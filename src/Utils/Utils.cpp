#include "Utils.h"

uintptr_t Utils::FindMultiLvlPtr(uintptr_t baseAddr, std::vector<unsigned int> offsets) {
	uintptr_t c;
	if (baseAddr != NULL) {
		c = baseAddr;
		for (unsigned int I = 0; I < offsets.size(); I++) {
			c = *(uintptr_t*)(c += offsets[I]);
			if (c == NULL) {
				break;
			}
		}
	}
	return c;
}

uintptr_t Utils::FindSig(const char* sig) {
	const char* pattern = sig;
	uintptr_t firstMatch = 0;
	static const uintptr_t rangeStart = (uintptr_t)GetModuleHandleA("Minecraft.Windows.exe");
	static MODULEINFO miModInfo;
	static bool init = false;
	if (!init) {
		init = true;
		GetModuleInformation(GetCurrentProcess(), (HMODULE)rangeStart, &miModInfo, sizeof(MODULEINFO));
	}
	static const uintptr_t rangeEnd = rangeStart + miModInfo.SizeOfImage;

	BYTE patByte = GET_BYTE(pattern);
	const char* oldPat = pattern;

	for (uintptr_t pCur = rangeStart; pCur < rangeEnd; pCur++)
	{
		if (!*pattern)
			return firstMatch;

		while (*(PBYTE)pattern == ' ')
			pattern++;

		if (!*pattern)
			return firstMatch;

		if (oldPat != pattern) {
			oldPat = pattern;
			if (*(PBYTE)pattern != '\?')
				patByte = GET_BYTE(pattern);
		}

		if (*(PBYTE)pattern == '\?' || *(BYTE*)pCur == patByte)
		{
			if (!firstMatch)
				firstMatch = pCur;

			if (!pattern[2])
				return firstMatch;

			pattern += 2;
		}
		else
		{
			pattern = sig;
			firstMatch = 0;
		}
	}
}

void Utils::DebugLogF(const char* output, const char* fPath, bool deleteIfFirstLaunch) {
	try {
		static std::string cachedPath;

		if (std::string(fPath).length() > 0) {
			cachedPath = std::string(fPath);
		}
		else fPath = cachedPath.c_str(); /* No Path Specified, use previous path instead..*/

		std::string dirP = getenv("APPDATA") + std::string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\" + std::string(fPath));

		if (deleteIfFirstLaunch) {
			static bool firstLaunch = true;

			if (firstLaunch) {
				firstLaunch = false;
				std::filesystem::remove_all(std::filesystem::path(dirP).parent_path());
			}
		}

		/* Check if path exists */

		struct stat buffer;

		if (!(stat(dirP.c_str(), &buffer) == 0)) {
			std::filesystem::create_directories(std::filesystem::path(dirP).parent_path());
		}

		CloseHandle(CreateFileA(dirP.c_str(), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));

		std::ofstream fileOutput;
		fileOutput.open(dirP.c_str(), std::ios_base::app);
		fileOutput << output << std::endl;
		fileOutput.close();

		return;
	} catch (...) {};
}
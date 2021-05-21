#include "TabGui.h"

void TabGui::onRender(class Renderer* renderer) {
	if (instance == nullptr || instance->guiData() == nullptr) return;

	size_t cIndex = 0;
	Vec2 res = instance->guiData()->res;
	float textSize = instance->guiData()->GuiScale() * 10;

	std::wstring logo = L"Echo's Client";

	renderer->drawString(logo, textSize, Vec2(res.x - ((logo.length() + 1) * (textSize / 2)), res.y - (textSize * 2)), RGBA_FW1(74, 152, 255).toUint32());

	for (auto C : client->categories) {
		Vec2 textPos = Vec2(15, (cIndex * (textSize + 5)) + 15);
		renderer->drawString(std::wstring(C->name.begin(), C->name.end()), textSize, (sCat ? sCIndex == cIndex ? Vec2(textPos.x + 10, textPos.y) : textPos : textPos), RGBA_FW1(74, 152, 255).toUint32());
		cIndex++;
	}
}

void TabGui::onKey(uint64_t key, bool isDown, bool* cancelOrigin) {
	if (isDown) {
		if (key == 0x27) { /* Right Arrow */
			if (!sCat) {
				sCat = true;
			}
			else {
				if (sMod) {
					auto cat = client->categories.at(sCIndex);
					if (cat != nullptr && cat->modules.size() > 0) {
						auto mod = cat->modules.at(sMIndex);
						mod->isEnabled = !mod->isEnabled;
					}
				}
				else {
					sMod = true;
				}
			}
		}
		if (key == 0x25) { /* Left Arrow */
			if (sCat) {
				sCat = false;
				sCIndex = 0;
			}
		}
		if (key == 0x26) { /* Up Arrow*/
			if (sCat && !sMod) {
				//
			}
			else if (sMod) {
				//
			}
		}
		if (key == 0x28) { /* Down Arrow */
			if (sCat && !sMod) {
				sCIndex++;
				if (sCIndex == client->categories.size()) {
					sCIndex = 0;
				}
			}
			else if (sMod) {
				sMIndex++;
				if (sMIndex == client->categories.size()) {
					sMIndex = 0;
				}
			}
		}
	}
}
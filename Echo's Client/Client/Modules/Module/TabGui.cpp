#include "TabGui.h"

class TC { /* Text Component */
public:
	int ID = 0;
	float cOffX = 0;
	float cOffY = 0;

	TC(int ID, Vec2 offPos) {
		this->ID = ID;
		this->cOffX = offPos.x;
		this->cOffY = offPos.y;
	}

	void shiftX(float newX, float multiplyr = 0.5f) {
		if (this->cOffX != newX) {
			if (this->cOffX < newX) {
				this->cOffX += multiplyr;
			}
			else if (this->cOffX > newX) {
				this->cOffX -= multiplyr;
			}
		}
	}
};

std::vector<TC*> textComponents = std::vector<TC*>();

void TabGui::onRender(class Renderer* renderer) {
	if (instance == nullptr || instance->guiData() == nullptr) return;

	int i = 0;
	float tSize = instance->guiData()->GuiScale() * 10;

	for (auto C : client->categories) {
		Vec2 tPos = Vec2(10, (i * (tSize + 5)) + 10);

		static bool reg = false;
		if (!reg) {
			textComponents.push_back(new TC(i, tPos));
			if(i == (client->categories.size() - 1)) reg = true;
		}

		auto cTC = textComponents.at(i);

		if (sCat && sCIndex == i) {
			cTC->shiftX(tPos.x + 10);
		}
		else {
			cTC->shiftX(tPos.x);
		}

		renderer->drawString(std::wstring(C->name.begin(), C->name.end()), tSize, Vec2(tPos.x + cTC->cOffX, tPos.y), _RGBA(52, 152, 219, 1));
		i++;
	}
}

void TabGui::onKey(uint64_t key, bool isDown, bool* cancelOrigin) {
	if (isDown) {
		if (key == 0x27) { /* Right Arrow */
			*cancelOrigin = true;
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
			*cancelOrigin = true;
			if (sMod) {
				sMod = false;
				sMIndex = 0;
			}
			else if (sCat) {
				sCat = false;
				sCIndex = 0;
			}
		}
		if (key == 0x26) { /* Up Arrow*/
			*cancelOrigin = true;
			if (sCat && !sMod) {
				if (sCIndex == 0) sCIndex = client->categories.size();
				sCIndex--;
			}
			else if (sMod) {
				if (client->categories.at(sCIndex)->modules.size()) {
					if (sMIndex == 0) sMIndex = client->categories.at(sCIndex)->modules.size();
					sMIndex--;
				}
			}
		}
		if (key == 0x28) { /* Down Arrow */
			*cancelOrigin = true;
			if (sCat && !sMod) {
				sCIndex++;
				if (sCIndex == client->categories.size()) {
					sCIndex = 0;
				}
			}
			else if (sMod) {
				if (client->categories.at(sCIndex)->modules.size()) {
					sMIndex++;
					if (sMIndex == client->categories.at(sCIndex)->modules.size()) {
						sMIndex = 0;
					}
				}
			}
		}
	}
}
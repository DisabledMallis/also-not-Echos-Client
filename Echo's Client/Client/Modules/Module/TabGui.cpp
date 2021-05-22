#include "TabGui.h"

void TabGui::onRender(class Renderer* renderer) {
	if (instance == nullptr || instance->guiData() == nullptr) return;

	size_t cIndex = 0;
	Vec2 res = instance->guiData()->res;
	float textSize = instance->guiData()->GuiScale() * 10;

	std::wstring logo = std::wstring(client->name.begin(), client->name.end());

	renderer->drawString(logo, textSize, Vec2(res.x - ((logo.length() + 1) * (textSize / 2)), res.y - (textSize * 2)), _RGBA(57, 126, 216));

	for (auto C : client->categories) {
		Vec2 textPos = Vec2(15, (cIndex * (textSize + 5)) + 15);
		renderer->drawString(std::wstring(C->name.begin(), C->name.end()), textSize, (sCat ? sCIndex == cIndex ? Vec2(textPos.x + 10, textPos.y) : textPos : textPos), _RGBA(57, 126, 216));
		cIndex++;
	}

	//renderer->fillRectangle(Vec2(50, 100), Vec2(300, 300), _RGBA(57, 126, 216, 0.6f));
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
			if (sCat) {
				sCat = false;
				sCIndex = 0;
			}
		}
		if (key == 0x26) { /* Up Arrow*/
			*cancelOrigin = true;
			if (sCat && !sMod) {
				//
			}
			else if (sMod) {
				//
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
				sMIndex++;
				if (sMIndex == client->categories.size()) {
					sMIndex = 0;
				}
			}
		}
	}
}
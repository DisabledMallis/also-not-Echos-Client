#include "TabGui.h"

void TabGui::onRender(class Renderer* renderer) {
	if (instance == nullptr || instance->guiData() == nullptr) return;

	//
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
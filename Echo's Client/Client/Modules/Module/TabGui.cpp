#include "TabGui.h"

class _OffXC {
public:
	int ID = 0;
	float offX;

	_OffXC(int ID, float offX) {
		this->ID = ID;
		this->offX = offX;
	}

	void shiftX(float newX, float mplyr = 0.5f) {
		if (offX < newX) {
			offX += mplyr;
		}
		else if (offX > newX) {
			offX -= mplyr;
		}
	}
};

bool once = false;
std::vector<class _OffXC*> Components;
std::vector<class _OffXC*> modComponents;

Vec2 start = Vec2(10, 10);

void TabGui::renderLogo(class Renderer* renderer) {
	//Do this later
}

void TabGui::updateAlpha() {
	float modifier = 0.03f;
	MinecraftGame* game = instance->minecraftGame();
	if (game->canUseKeys) {
		if (alpha < 1.0f) alpha += modifier;
	}
	else {
		if (alpha > 0) alpha -= modifier;
	}
}

float lastScale = -1;

void TabGui::onRender(class Renderer* renderer) {
	if (instance != nullptr && instance->guiData() != nullptr) {
		int ID = 0;
		if (!once) {
			for (auto C : client->categories) {
				Components.push_back(new _OffXC(ID, start.x));
				ID++;
			}
			once = true;
		}
		ID = 0;

		renderLogo(renderer);
		updateAlpha();
		
		_RGBA textColour = _RGBA(200, 200, 200, alpha);
		_RGBA greenColour = _RGBA(75, 155, 95, alpha);
		_RGBA backgroundColour = _RGBA(30, 70, 115, alpha);

		float tSize = instance->guiData()->GuiScale() * 10;
		float catLen = 0.f;

		for (auto C : client->categories) {
			auto currLen = renderer->textWidth(std::wstring(C->name.begin(), C->name.end()), tSize);
			if (currLen > catLen) catLen = currLen;
		}

		catLen += 10.0f; /* Stretch Width */
		float yStretch = 5.0f; /* Stretch Y */

		renderer->fillRectangle(Vec2(start.x - (start.x / 2), start.y), Vec2(start.x + catLen, start.y + (client->categories.size() * (tSize + yStretch))), backgroundColour);
		
		for (auto C : client->categories) {
			auto tComponent = ((Components.size() > ID) ? Components.at(ID) : nullptr);
			if (tComponent == nullptr) break;

			Vec2 tPos = Vec2(start.x, start.y + (ID * (tSize + yStretch)));
			tPos.x = (tPos.x + (this->sCat && !this->sMod && sCIndex == ID ? yStretch : 0));

			tComponent->shiftX(tPos.x);

			renderer->drawString(std::wstring(C->name.begin(), C->name.end()), tSize, Vec2(tComponent->offX, tPos.y), textColour);

			ID++;
		}
		if (sMod) {
			float rectLen = 0.f;
			auto modules = client->categories.at(sCIndex)->modules;

			for (auto M : modules) {
				auto currLen = renderer->textWidth(std::wstring(M->name.begin(), M->name.end()), tSize);
				if (currLen > rectLen) rectLen = currLen;
			}

			Vec2 startRect = Vec2(start.x + catLen, start.y + (sCIndex * (tSize + yStretch)));
			Vec2 endRect = Vec2((startRect.x + rectLen + 5), startRect.y + (modules.size() * (tSize + yStretch)));

			renderer->fillRectangle(startRect, endRect, backgroundColour);

			auto currScale = instance->guiData()->GuiScale();
			if (lastScale != currScale) {
				lastScale = currScale;
				modComponents.clear();
				int cID = 0;
				for (auto M : modules) {
					auto _this = new _OffXC(cID, startRect.x);
					_this->offX = (_this->offX + (this->sMod && sMIndex == cID ? yStretch : 0));
					modComponents.push_back(_this);
					Utils::DebugLogF(M->name.c_str());
					cID++;
				}
			}

			ID = 0;

			for (auto M : modules) {
				auto tComponent = ((modComponents.size() > ID) ? modComponents.at(ID) : nullptr);
				if (tComponent == nullptr) break;

				Vec2 tPos = Vec2(startRect.x, startRect.y + (ID * (tSize + yStretch)));
				tPos.x = (tPos.x + (this->sMod && sMIndex == ID ? yStretch : 0));

				tComponent->shiftX(tPos.x);

				renderer->drawString(std::wstring(M->name.begin(), M->name.end()), tSize, Vec2(tComponent->offX, tPos.y), M->isEnabled ? greenColour : textColour);
				ID++;
			}
		}
	}
}

void TabGui::onKey(uint64_t key, bool isDown, bool* cancelOrigin) {
	if (!isEnabled || instance == nullptr || instance->minecraftGame() == nullptr || !(instance->minecraftGame()->canUseKeys)) return;
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
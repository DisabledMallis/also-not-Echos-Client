#include "Coords.h"

void Coords::updateAlpha() {
	float modifier = 0.03f;
	MinecraftGame* game = instance->minecraftGame();
	if (game->canUseKeys) {
		if (textColour.a < 1.0f) textColour.a += modifier;
	}
	else {
		if (textColour.a > 0) textColour.a -= modifier;
	}
}

void Coords::onRender(class Renderer* renderer) {
	if (player == nullptr || instance == nullptr || instance->guiData() == nullptr)
		return;

	updateAlpha();
	
	auto pos = *player->getPos();
	auto size = instance->guiData()->GuiScale() * 10;

	std::string text(std::to_string((int)(pos.x)) + ", " + std::to_string((int)(pos.y)) + ", " + std::to_string((int)(pos.z)));
	std::wstring t(text.begin(), text.end());

	float len = renderer->textWidth(t, size);

	Vec2 res = instance->guiData()->res;
	Vec2 tPos = Vec2(4, res.y - (renderer->textHeight(t, size) + (instance->guiData()->GuiScale() * 6)));

	renderer->drawString(t, size, tPos, textColour);
}
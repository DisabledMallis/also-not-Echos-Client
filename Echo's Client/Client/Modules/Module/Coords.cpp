#include "Coords.h"

void Coords::onRender(class Renderer* renderer) {
	if (player == nullptr || instance == nullptr || instance->guiData() == nullptr)
		return;
	
	auto pos = *player->getPos();
	auto size = instance->guiData()->GuiScale() * 10;

	std::string text(std::to_string((int)(pos.x)) + ", " + std::to_string((int)(pos.y)) + ", " + std::to_string((int)(pos.z)));
	std::wstring t(text.begin(), text.end());

	float len = renderer->textWidth(t, size);

	Vec2 res = instance->guiData()->res;
	Vec2 tPos = Vec2(4, res.y - (renderer->textHeight(t, size) + (instance->guiData()->GuiScale() * 8)));

	renderer->drawString(t, size, tPos, _RGBA(255, 255, 255));
}
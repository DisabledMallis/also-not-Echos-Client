#include "Minecraft.h"

ClientInstance* Minecraft::ClientInstance(class ClientInstance* i) {
	static class ClientInstance* cache = nullptr;
	if (i != nullptr) cache = i;
	return cache;
}
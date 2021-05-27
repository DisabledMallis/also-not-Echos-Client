#include "Minecraft.h"

class ClientInstance* cache = nullptr;

ClientInstance* Minecraft::ClientInstance(class ClientInstance* i) {
	if (i != nullptr) cache = i;
	return cache;
}
#include "Category.h"
#include "../Client.h"

Category::Category(Client* client, std::string name) {
	this->client = client;
	this->name = name;

	client->categories.push_back(this);
}
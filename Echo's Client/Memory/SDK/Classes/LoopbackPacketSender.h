#pragma once

class LoopbackPacketSender {
public:
	virtual void send(class Packet* packet);
};
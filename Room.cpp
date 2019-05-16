#include "Room.h"

Room::Room(std::string description) {
	this->description = description;
}


Room::~Room() {

}

std::string Room::getDescription() {
	return this->description;
}

void Room::setRoomSetting(std::string setting) {
	roomSetting = setting;
}

std::string Room::getRoomSetting() {
	return this->roomSetting;
}

void Room::setRooms(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom) {
	this->northRoom = northRoom;
	this->southRoom = southRoom;
	this->eastRoom = eastRoom;
	this->westRoom = westRoom;
}

Room* Room::getRoom(std::string direction) {
	if (direction == "North" && this->northRoom != nullptr) {
		return this->northRoom;
	}
	else if (direction == "East" && this->eastRoom != nullptr) {
		return this->eastRoom;
	}
	else if (direction == "South" && this->southRoom != nullptr) {
		return this->southRoom;
	}
	else if (direction == "West" && this->westRoom != nullptr) {
		return this->westRoom;
	}
	else {
		std::cout << "You can't go that way." << std::endl;
		return this;
	}
};
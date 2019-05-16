#pragma once
#include <string>
#include <iostream>

class Room {
public:
	Room(std::string description);
	~Room();
	std::string getDescription();
	void setRoomSetting(std::string roomSetting);
	std::string getRoomSetting();
	void setRooms(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom);
	Room* getRoom(std::string direction);
protected:
	std::string description;
	std::string roomSetting;
	/************************************************************/
	/*     Naviagtion to room relative to a room labeled below  */
	/************************************************************/
	Room* northRoom;
	Room* eastRoom;
	Room* southRoom;
	Room* westRoom;
};
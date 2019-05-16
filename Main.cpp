#include <list>
#include <vector>
#include <iostream>
#include <string>
#include "Room.h"
#include "Enemy.h"
#include "Human.h"
#include "Animal.h"
#include "Hybrid.h"
#include "Flyer.h"
#include "Item.h"
#include "CombatItem.h"
#include "Weapon.h"
#include "MeleeWeapon.h"
#include "Firearm.h"
#include "Spells.h"
#include "NormalItem.h"
#include "Inventory.h"
#include "Player.h"
#include <algorithm>    // std::random_shuffle

//Item* dropItem(Inventory* enemyInventory, Inventory* playerInventory)
//{
//	int num = enemyInventory->size();
//	int randNum = rand() % num
//	for (int i = 0; i < inventory.size(); i++)
//	{
//		Item item = inventory.at(num);
//		return item;
//		
//	}
//}
int generateNum() {
	int randNum = rand() % 2; // Generate a random number between 0 and 1
	return randNum;
}

void combat(Enemy enemy, int something) {
	while (enemy.GetHealth() != 0 || something != 0) {
		int random = generateNum();
		if (random == 0) {
			std::string combat_to_use;
			std::cout << "It is your turn to fight. What form of combat do you want to use? You can use Melee, Firearms, or Spells." << std::endl;
			getline(std::cin, combat_to_use);
			int enemy_health = enemy.GetHealth();
			if (combat_to_use == "Melee") {
				std::string attack_kind;
				std::cout << "You have chosen to use Melee. What kind of attack do you want to use? Normal deals 2 HP, Strong deals 5 HP, and Special deals 8 HP. " << std::endl;
				getline(std::cin, attack_kind);
				if (attack_kind == "Normal") {
					enemy_health = enemy.TakeHit(2);
					std::cout << enemy.GetHealth() << std::endl;
					if (enemy_health <= 0) {
						std::cout << "You have killed " << enemy.GetName() << "!" << std::endl;
						break;
					}
				}
				else if (attack_kind == "Strong") {
					enemy_health = enemy.TakeHit(5);
					std::cout << enemy.GetHealth() << std::endl;
					if (enemy_health <= 0) {
						std::cout << "You have killed " << enemy.GetName() << "!" << std::endl;
						break;
					}
				}
				else if (attack_kind == "Special") {
					enemy_health = enemy.TakeHit(8);
					std::cout << enemy.GetHealth() << std::endl;
					if (enemy_health <= 0) {
						std::cout << "You have killed " << enemy.GetName() << "!" << std::endl;
						break;
					}
				}
			}
			else if (combat_to_use == "Firearms") {
				std::string attack_kind;
				std::cout << "You have chosen to use Firearms. What kind of attack do you want to use? Normal deals 5 HP, Strong deals 8 HP, and Rapid Fire deals 10 HP. " << std::endl;
				getline(std::cin, attack_kind);
				if (attack_kind == "Normal") {
					enemy_health = enemy.TakeHit(5);
					std::cout << enemy.GetHealth() << std::endl;
					if (enemy_health <= 0) {
						std::cout << "You have killed " << enemy.GetName() << "!" << std::endl;
						break;
					}
				}
				else if (attack_kind == "Strong") {
					enemy_health = enemy.TakeHit(8);
					std::cout << enemy.GetHealth() << std::endl;
					if (enemy_health <= 0) {
						std::cout << "You have killed " << enemy.GetName() << "!" << std::endl;
						break;
					}
				}
				else if (attack_kind == "Rapid Fire") {
					enemy_health = enemy.TakeHit(10);
					std::cout << enemy.GetHealth() << std::endl;
					if (enemy_health <= 0) {
						std::cout << "You have killed " << enemy.GetName() << "!" << std::endl;
						break;
					}
				}
			}
			else if (combat_to_use == "Spells") {
				std::string attack_kind;
				std::cout << "You have chosen to consult the Spell Book. Which spell do you want to use?" << std::endl;
				std::getline(std::cin, attack_kind);
				if (attack_kind == "Snow Spell") {
					enemy_health = enemy.TakeHit(10);
					std::cout << enemy.GetHealth() << std::endl;
					if (enemy_health <= 0) {
						std::cout << "You have killed " << enemy.GetName() << "!" << std::endl;
						break;
					}
				}
				else if (attack_kind == "Fire Spell") {
					enemy_health = enemy.TakeHit(12);
					std::cout << enemy.GetHealth() << std::endl;
					if (enemy_health <= 0) {
						std::cout << "You have killed " << enemy.GetName() << "!" << std::endl;
						break;
					}
				}
				else if (attack_kind == "Thunder Spell") {
					enemy_health = enemy.TakeHit(15);
					std::cout << enemy.GetHealth() << std::endl;
					if (enemy_health <= 0) {
						std::cout << "You have killed " << enemy.GetName() << "!" << std::endl;
						break;
					}
				}
			}
		}
		else {
			if (something <= 0) {
				std::cout << "You have been killed." << std::endl;
				break;
				exit(0);
			}
			else {
				std::cout << enemy.GetName() << "has attacked!" << std::endl;
			}
		}
	}
}

int main() {
	//initializing stuff
	int health = 50;
	std::vector<Room*> rooms;
	Inventory* invent = new Inventory();
	Inventory* enemyInvent = new Inventory();
	Player player = Player(health);


	//creating enemies
	Enemy mummy = Enemy("Mummy", 5, 1, 0, "A rotting skeleton covered in wraps. Beware his eyes, for if they shoot beams you will be stricken with his curse.");
	Enemy zombie = Enemy("Zombie", 5, 2, 0, "A rotting body of flesh covered in blood. If he bites you, you will be infected.");
	Enemy goblin = Enemy("Goblin", 5, 5, 0, "A small monstrous creature with big ears that attacks with a sword");
	Animal gorgon = Animal("Gorgon", 10, 10, 20, "A bull-like creature covered in scales. May either gore you or breathe a gas that turns you to stone.");
	Enemy elephant = Enemy("Elephant", 10, 15, 0, "A large animal with huge ears and long tusks. He will gore you, and the shield will not help.");
	Enemy fire_shark = Enemy("Fire Shark", 10, 20, 0, "A shark with fire emanating from its body and a strong bite. You can use the shield against his jaws.");
	Enemy minotaur = Hybrid("Minotaur", 15, 12, 0, "A muscular human with the head of a bull that uses his axe to kill anyone in his path");
	Enemy centaur = Hybrid("Centaur", 15, 10, 0, "A horse with the head of a person that kills using a spear");
	Enemy lizard_man = Hybrid("Lizard Man", 15, 15, 0, "A bipedal reptile that uses his club to destroy trespassers");
	Enemy manticore = Flyer("Manticore", 20, 12, 0, "A huge lion that uses dragon wings to fly. Breathes fire that can be deflected by shield, but not by armor alone.");
	Flyer hippogriff = Flyer("Hippogriff", 20, 15, 20, "A monstrous creature with wings, a horse's body, and an eagle's head. Can either attack with strong beak or sharp claws.");
	Enemy dragon = Flyer("Dragon", 20, 25, 0, "A giant red lizard-like creature with wings that breathes fire. Shield deflects attacks but armor alone does not.");

	//creating items
	Item sword = Item("Sword", "A sword that can slash enemies", 0);
	Item pistol = Item("Pistol", "A small gun that can be used to shoot at enemies", 0);
	Item spell_book = Item("Spell Book", "A book that you can use to activate snow, fire, or thunder spells on certain enemies (takes away a specific amount of damage)", 0);
	Item curse_breaker = Item("Curse Breaker", "This green potion makes you immune to the Mummy's Curse. Mummies do not attack if they see that you have it.", 0);
	Item antidote = Item("Antidote", "Use this syringe to make yourself immune to the infection. Zombies do not attack if they see that you have it.", 0);
	Item health_pack = Item("Health Pack", "Use this health pack to replenish your health", 0);
	Item snorkeling_mask = Item("Snorkeling Mask", "Use this mask to swim your way through areas of water", 0);
	Item key = Item("Key", "Can be used to unlock door leading into the shrine", 0);
	Item arena_key = Item("Arena Key", "This key will unlock the door to your final challenge!", 0);
	Item cross = Item("Cross", "Once you have overcome your final challenge, use this cross and God shall grant you freedom!", 0);
	Item holy_bread = Item("Holy Bread", "Consume the body of Christ and regain full health!", 0);
	Item poisonChemical = Item("Holy Bread", "Consume the body of Christ and regain full health!", 0);



	//adding to the enemy inventory
	enemyInvent->add(&health_pack);
	enemyInvent->add(&holy_bread);
	enemyInvent->add(&poisonChemical);
	enemyInvent->add(&health_pack);





	//setting up the rooms
	Room* currentRoom = nullptr;
	rooms.push_back(new Room("Entrance")); //0
	rooms.push_back(new Room("Crypt"));//1
	rooms.push_back(new Room("Library"));//2
	rooms.push_back(new Room("Observatory"));//3
	rooms.push_back(new Room("Labyrinth"));//4
	rooms.push_back(new Room("Infirmary"));//5
	rooms.push_back(new Room("Shark Pool"));//6
	rooms.push_back(new Room("Guardian's Lair"));//7
	rooms.push_back(new Room("Devil's Room"));//8
	rooms.push_back(new Room("Shrine"));//9
	rooms.push_back(new Room("Chapel"));//10
	rooms.push_back(new Room("Pantry"));//11
	rooms.push_back(new Room("Stairwell"));//12
	rooms.push_back(new Room("Sanctum 2nd Floor"));//13
	rooms.push_back(new Room("Vault 2nd Floor"));//14
	rooms.push_back(new Room("Necropolis 2nd Floor"));//15
	rooms.push_back(new Room("Battleground 2nd Floor"));//16
	rooms[0]->setRooms(nullptr, rooms[1], rooms[3], nullptr);
	rooms[1]->setRooms(nullptr, rooms[2], nullptr, rooms[0]);
	rooms[2]->setRooms(nullptr, nullptr, nullptr, rooms[1]);
	rooms[3]->setRooms(rooms[0], rooms[4], rooms[5], nullptr);
	rooms[4]->setRooms(nullptr, nullptr, rooms[6], rooms[3]);
	rooms[5]->setRooms(rooms[3], rooms[6], nullptr, nullptr);
	rooms[6]->setRooms(rooms[4], nullptr, rooms[7], rooms[5]);
	rooms[7]->setRooms(rooms[6], nullptr, rooms[9], nullptr);
	rooms[8]->setRooms(nullptr, rooms[9], nullptr, nullptr);
	rooms[9]->setRooms(rooms[7], rooms[10], rooms[11], rooms[8]);
	rooms[10]->setRooms(nullptr, nullptr, nullptr, rooms[9]);
	rooms[11]->setRooms(rooms[9], nullptr, rooms[12], nullptr);
	rooms[12]->setRooms(rooms[11], nullptr, rooms[13], nullptr);
	rooms[13]->setRooms(rooms[12], rooms[14], nullptr, nullptr);
	rooms[14]->setRooms(nullptr, nullptr, rooms[15], rooms[13]);
	rooms[15]->setRooms(rooms[14], nullptr, rooms[16], nullptr);
	rooms[16]->setRooms(rooms[15], nullptr, nullptr, nullptr);
	currentRoom = rooms[0];

	invent->add(&pistol);

	//Checks to see if item is picked up
	bool curseBreaker = false;
	bool isHealthLibrary = false;
	bool isSword = false;
	bool isantidote = false;
	bool hasSnorkelingMask = false;
	bool doorLocked = true;
	bool arenadoorLocked = true;
	bool isSharkDead = false;
	bool isArenaKeyTaken = false;
	bool hasSpellBook = false;

	std::string takeItem;
	bool engageCombat = false; // var input if user wants to fight enemy.
	std::string action; // Getting search, move, look, take etc, input from user

	//Adds items to enemy's inventory (when they are killed, player will be able to take these items)
	goblin.Add(&snorkeling_mask);
	goblin.Add(&spell_book);
	gorgon.Add(&health_pack);
	elephant.Add(&key);
	minotaur.Add(&health_pack);
	centaur.Add(&arena_key);
	lizard_man.Add(&health_pack);

	//start the game
	std::cout << "You have to try and find your way out of this Hellish nightmare. Armed with only a pistol, you are prepared for anything that comes in your path." << std::endl;
	while (action != "QUIT") {
		if (currentRoom->getDescription() == "Entrance") {
			std::cout << "You are currently in: " << currentRoom->getDescription() << "\n" << std::endl;
			std::cout << "What do you want to do? (type move to navigate, look to look, etc) ";
			std::getline(std::cin, action);
			if (action == "i") {
				invent->displayInventory();
			}if (action == "move") {
				std::string nav;
				std::cout << "Where do you want to move to: " << std::endl;
				getline(std::cin, nav);
				currentRoom = currentRoom->getRoom(nav);
			}if (currentRoom != nullptr) {
				std::cout << currentRoom->getDescription() << std::endl;
			}
		}
		/********************************************/
		/*    CRYPT LEVEL							*/
		/********************************************/
		while (currentRoom->getDescription() == "Crypt") {
			if (curseBreaker == false) {
				std::string fightOrRun;
				std::cout << "It's pretty dark in here. There are rows of caskets. Off in the distance, there seems to be a mummy walking towards me." <<
					"\n" << "I have a pistol in my back pocket, maybe a couple of shots will kill it.  Or I can try to sneak past it." << "\n" <<
					"What do you want to do? r to run or f to fight." << std::endl;
				std::getline(std::cin, fightOrRun);
				if (fightOrRun == "r") {
					currentRoom = currentRoom->getRoom("East");
				}

				else if (fightOrRun == "f") {
					std::cout << "You shoot a couple of bullets into the mummy, but unfortunately the gun jams and the mummy curses you, taking away 1 HP." << std::endl;
					mummy.Attack(health, mummy.GetHealthTaken());
				}
			}
			else {
				while (hasSpellBook == false) {
					std::cout << "The curse breaker makes you immune to the mummy's attacks. However, there is a strange book sitting on the casket. Want to take it?" << std::endl;
					std::string takeBook;
					std::getline(std::cin, takeBook);
					if (takeBook == "y") {
						std::cout << "You now have the spell book! This will allow you to perform spells on enemies, taking away certain amounts of health." << std::endl;
					}
					else {
						std::cout << "You won't get far without the book!" << std::endl;
					}hasSpellBook = true;
				}
				std::cout << "This area is pretty much all cleaned out." << std::endl;
				std::string nav;
				std::cout << "Where do you want to move to: " << std::endl;
				getline(std::cin, nav);
				currentRoom = currentRoom->getRoom(nav);
			}
		}
		/**********************************************/
		/*    LIBRARY LEVEL         */
		/**********************************************/
		while (currentRoom->getDescription() == "Library") {
			if (curseBreaker == false && isHealthLibrary == false) {
				std::cout << "There are piles upon piles of books with shelves reaching the ceiling. There is a shelf and a table to my left, with a cross ingrained in the center. " << std::endl;
				std::string action;
				std::cout << "What do you want to do? (type move to navigate, look to look, etc) ";
				std::getline(std::cin, action);
				if (action == "i") {
					invent->displayInventory();
				}
				else if (action == "look shelf" || action == "search shelf") {
					std::cout << "There is a glowing green potion and some ripped out peices of paper." << std::endl;
				}
				else if (action == "look table" || action == "search table") {
					if (isHealthLibrary = false) {
						std::cout << "You just found a health pack!" << std::endl;
						health = health + 10;
						std::cout << "Your health is at: " << health << std::endl;
						isHealthLibrary = true;
					}
					else {
						std::cout << "Nothing useful on the table." << std::endl;
					}
				}
				else if (action == "take green potion") {
					std::cout << "You've obtained the mummy curse breaker! This makes you immune to the mummy's attacks!" << std::endl;
					invent->add(&curse_breaker);
					curseBreaker = true;
				}
				else if (action == "move") {
					std::string nav;
					std::cout << "Where do you want to move to: " << std::endl;
					getline(std::cin, nav);
					currentRoom = currentRoom->getRoom(nav);
				}
			}
			else {
				std::cout << "There is no use being in this room. " << std::endl;
				std::string nav;
				std::cout << "Where do you want to move to: " << std::endl;
				getline(std::cin, nav);
				currentRoom = currentRoom->getRoom(nav);
			}
		}
		/*****************************************/
		/*   OBSERVATORY LEVEL       */
		/*****************************************/
		while (currentRoom->getDescription() == "Observatory") {
			int n = 2;
			while (n != 0) {
				std::cout << "This room is very dark but I can see a telescope and a couple of open cabinets." << std::endl;
				std::string action;
				std::cout << "What do you want to do? (type move to navigate, look to look, etc) ";
				std::getline(std::cin, action);
				if (action == "i") {
					invent->displayInventory();
				}
				else if (action == "look telescope" || action == "search telescope") {
					std::string takeSyringe;
					std::cout << "Appears to be an old telescope. Underneath it is a syringe which might be useful. Pick it up? y/n" << std::endl;
					std::getline(std::cin, takeSyringe);
					if (takeSyringe == "y") {
						std::cout << "You have obtained the Antidote! There will be a Zombie later, but he won't be able to hurt you with this!" << std::endl;
						invent->add(&antidote);
						isantidote = true;
					}
					else {
						std::cout << "Fine then. Your immune system won't help you later." << std::endl;
					}
				}
				else if (action == "look cabinet" || action == "search cabinet") {
					std::cout << "There is a small dueling sword, do you want to take it? y/n " << std::endl;
					std::getline(std::cin, takeItem);
					if (takeItem == "y") {
						std::cout << "You obtained a sword!" << std::endl;
						invent->add(&sword);
						isSword = true;
					}
					else {
						std::cout << "Okay then. Your loss." << std::endl;
					}
				}n--;
			}
			std::cout << "Nothing to be seen here in this room. " << std::endl;
			std::string nav;
			std::cout << "Where do you want to move to: " << std::endl;
			getline(std::cin, nav);
			currentRoom = currentRoom->getRoom(nav);
		}
		/***************************************/
		/*   LABYRINTH LEVEL      */
		/***************************************/
		bool isGoblinDead = false;

		while (currentRoom->getDescription() == "Labyrinth") {
			std::string want_to_fight;

			if (isGoblinDead == false)
			{


				std::cout << "Enemy Approaching!!! It is a Goblin. To proceed onward, you have to fight. Do you want to fight? y/n " << std::endl;
				std::getline(std::cin, want_to_fight);
				if (want_to_fight == "y") {
					engageCombat = true;
				}
				if (engageCombat == true) {
					combat(goblin, health);
					goblin.Loot(invent);
					std::cout << "You have obtained the items the Goblin was holding. He had a snorkeling mask, which you'll need later. He also had a Spell Book, which you can use to fight enemies using magic spells." << std::endl;
					//Item* randomItem = dropItem(enemyInvent, invent);
					//invent->add(randomItem);
					invent->add(&snorkeling_mask);
					invent->add(&spell_book);


					isGoblinDead = true;
					hasSnorkelingMask = true;
					std::cout << "No use standing around here." << std::endl;
					std::string nav;
					std::cout << "Where do you want to move to: " << std::endl;
					getline(std::cin, nav);
					currentRoom = currentRoom->getRoom(nav);
				}

				else if (engageCombat != true)
				{
					std::cout << "You can't move on until you defeat the goblin." << std::endl;
				}

			}





		}
		/***************************************/
		/*   INFIRMARY LEVEL      */
		/***************************************/
		while (currentRoom->getDescription() == "Infirmary") {
			if (isantidote == false) {
				std::string fightOrRun;
				std::cout << "There seems to be some kind of illness that has struck this place. One of the patients has turned into a Zombie." << std::endl;
				std::cout << "However, he moves slow enough that you can easily move past him. Press r to run or f to try and fight him." << std::endl;
				std::getline(std::cin, fightOrRun);
				if (fightOrRun == "r") {
					currentRoom = currentRoom->getRoom("East");
				}
				else if (fightOrRun == "f") {
					std::cout << "You try to shoot the zombie in one shot to the head, but you miss and he infects you, taking away 2 HP." << std::endl;
					zombie.Attack(health, zombie.GetHealthTaken());
				}
			}
			else {
				std::cout << "You have the antidote, so the zombie knows he cannot get you to become one of his own kind. Keep moving." << std::endl;
				std::string nav;
				std::cout << "Where do you want to move to: " << std::endl;
				getline(std::cin, nav);
				currentRoom = currentRoom->getRoom(nav);
			}
		}
		/***************************************/
		/*   SHARK POOL LEVEL      */
		/***************************************/

		while (currentRoom->getDescription() == "Shark Pool") {
			if (hasSnorkelingMask == false) {
				std::cout << "You need the snorkeling mask to get across this body of water." << std::endl;
				std::string nav;
				std::cout << "Where do you want to move to: " << std::endl;
				std::getline(std::cin, nav);
				currentRoom = currentRoom->getRoom(nav);
			}
			else if (hasSnorkelingMask == true)
			{
				if (isSharkDead == false)
				{


					std::string combat_or_swim;
					std::cout << "You'll need to swim across this large pool of water in order to get to the other side. However, there's a Shark with fire emanating from its body. A Fire Shark!" << std::endl;
					std::cout << "You can choose to enter combat with him (press c) or swim past him (press s)." << std::endl;
					std::getline(std::cin, combat_or_swim);
					if (combat_or_swim == "c")
					{
						combat(fire_shark, health);
						isSharkDead = true;
					}


					else if (combat_or_swim == "s") {
						std::cout << "As a fast swimmer by nature, you escape the shark before he has a chance to sink his jaws into your flesh." << std::endl;
						currentRoom = currentRoom->getRoom("South");
					}

				}

				else
				{
					std::cout << "There's no reason to be in this room any longer. " << std::endl;
					std::string nav;
					std::cout << "Where do you want to move to: " << std::endl;
					std::getline(std::cin, nav);
					currentRoom = currentRoom->getRoom(nav);
				}
			}
		}
		/***************************************/
		/*   GUARDIAN'S LAIR LEVEL      */
		/***************************************/
		while (currentRoom->getDescription() == "Guardian's Lair") {
			if (doorLocked == true)
			{
				std::cout << "The door leading into the next room is locked. The key is guarded by an Elephant. You must defeat the Elephant in order to obtain the key." << std::endl;
				std::string begin_elephant_fight;
				std::cout << "Begin Elephant Fight? Y/N" << std::endl;
				getline(std::cin, begin_elephant_fight);
				if (begin_elephant_fight == "y") {
					combat(elephant, health);
					elephant.Loot(invent);
					std::cout << "Now that you have killed the elephant, you can use this key to move to the next room." << std::endl;
					doorLocked = false;
				}
				else {
					std::cout << "You need to defeat this enemy in order to get the key" << std::endl;
				}
			}
			else
			{
				std::cout << "No use standing around here." << std::endl;
				std::string nav;
				std::cout << "Where do you want to move to: " << std::endl;
				getline(std::cin, nav);
				currentRoom = currentRoom->getRoom(nav);

			}
		}
		/***************************************/
		/*   DEVIL'S ROOM LEVEL      */
		/***************************************/
		while (currentRoom->getDescription() == "Devil's Room") {
			std::cout << "There is a minotaur in this room. He has the head of a bull and a strong muscular body. He deals damage with a huge axe." << std::endl;
			std::cout << "But you only get a health pack if you defeat him." << std::endl;
			std::string fight;
			std::cout << "Fight this enemy? y/n" << std::endl;
			std::getline(std::cin, fight);
			if (fight == "y") {
				combat(minotaur, health);
				minotaur.Loot(invent);
				std::cout << "You now have another health pack." << std::endl;
			}
		}
		/***************************************/
		/*   SHRINE LEVEL      */
		/***************************************/
		while (currentRoom->getDescription() == "Shrine") {
			if (arenadoorLocked == true) {
				std::cout << "There's a centaur here. This creature has the body of a horse and the head of a person. You must fight this enemy, for he has the key to your final challenge later on." << std::endl;
				std::string begin_battle;
				std::cout << "Begin Battle? y/n";
				std::getline(std::cin, begin_battle);
				if (begin_battle == "y")
				{
					combat(centaur, health);
					centaur.Loot(invent);
					std::cout << "You now have the final boss arena key!" << std::endl;
					invent->add(&arena_key);
					arenadoorLocked = false;
					isArenaKeyTaken = true;
				}
				else
				{
					std::cout << "You can't move on until you've defeated this enemy." << std::endl;
				}
			}

			else
			{
				std::cout << "No use standing around here." << std::endl;
				std::string nav;
				std::cout << "Where do you want to move to: " << std::endl;
				getline(std::cin, nav);
				currentRoom = currentRoom->getRoom(nav);
			}


		}
		/***************************************/
		/*   CHAPEL LEVEL					   */
		/***************************************/
		bool isGorgonDead = false;
		while (currentRoom->getDescription() == "Chapel")
		{

			if (isGorgonDead == false)
			{
				std::cout << "There's a Gorgon in this room. A Gorgon is a bull-like creature with scaly skin that breathes gas that can take 20 HP away from you." << std::endl;
				std::cout << "He only carries a health pack. Do you want to fight this enemy?" << std::endl;
				std::string fight;
				std::getline(std::cin, fight);
				if (fight == "y") {
					combat(gorgon, health);
					gorgon.Loot(invent);
					std::cout << "You have another health pack!" << std::endl;
					isGorgonDead = true;
				}
			}

			else
			{
				std::cout << "There's no use being in this damn place." << std::endl;
				std::string nav;
				std::cout << "Where do you want to move to: " << std::endl;
				getline(std::cin, nav);
				currentRoom = currentRoom->getRoom(nav);
			}

		}

		/******************************************/
		/*				PANTRY LEVEL			  */
		/******************************************/
		bool isBreadTaken = false;
		//std::string action;
		std::string takeBread;

		while (currentRoom->getDescription() == "Pantry")
		{
			std::cout << "There are counters with cleaning supplies and what seems to look like left-over bread" << std::endl;
			std::cout << "What do you want to do? " << std::endl;
			getline(std::cin, action);


			if (action == "look counter" || action == "look counters" || action == "search counter" || action == "search counters")
			{
				std::cout << "There is some bread on the counter, do you want to take it? " << std::endl;
				getline(std::cin, takeBread);
				if (takeBread == "y")
				{
					std::cout << "You acquired some Holy Bread! Consume the body of Christ and regain full health! " << std::endl;
					invent->add(&holy_bread);
					int health = player.restoreHealth();
					player = Player(health);	//restores health to player



				}

				else if (takeBread == "n")
				{
					std::cout << "So I guessed you don't want restored health then..." << std::endl;
				}
			}

			else if (action == "move") {
				std::string nav;
				std::cout << "Where do you want to move to: " << std::endl;
				getline(std::cin, nav);
				currentRoom = currentRoom->getRoom(nav);
			}

			else
			{
				std::cout << "There's nothing I can do with this. " << std::endl;

			}

		}

		while (currentRoom->getDescription() == "Stairwell")
		{
			std::cout << "As you climb a flight of staris, a mummy infects you and takes away 10 health!" << std::endl;
			int health = player.GetHealth() - 10;
			player = Player(health);
			std::cout << "Your health is now: " << player.GetHealth();
			currentRoom = currentRoom->getRoom("South");


		}

		/*******************************/
		/*			SANCTUM			   */
		/*******************************/
		while (currentRoom->getDescription() == "Sanctum 2nd Floor")
		{
			std::string action;
			std::string nav;

			std::cout << "This is an empty church area with an rows of benches and a table with glasses of wine and bread" << std::endl;
			std::cout << "There isn't really much to see here. " << std::endl;
			std::cout << "What do you want to do? " << std::endl;
			getline(std::cin, action);
			if (action == "move")
			{
				std::cout << "Where do you want to move to: " << std::endl;
				getline(std::cin, nav);
				currentRoom = currentRoom->getRoom(nav);

			}

			else if (action == "i")
			{
				invent->displayInventory();
			}

			else {
				std::cout << "That doesn't seem to work " << std::endl;
			}

		}

		/****************************/
		/*			VAULT			*/
		/****************************/
		std::string nav;
		bool isLizardDead = false;
		while (currentRoom->getDescription() == "Vault 2nd Floor")
		{
			if (isLizardDead == false)
			{
				std::cout << "I see stone walls and water dripping from ceiling, There is an unnerving atmosphere here " << std::endl;
				std::cout << "I hear a creaking noise as a large lizard creature reveals himself. Doesn't look like I can make an escape. " << std::endl <<
					"It looks like I have to take him on " << std::endl;
				combat(lizard_man, health);
				lizard_man.Loot(invent);
				isLizardDead = true;
			}

			else
			{
				std::cout << "There is use being in this room" << std::endl;
				std::cout << "Where do you want to move to: " << std::endl;
				getline(std::cin, nav);
				currentRoom = currentRoom->getRoom(nav);
			}

		}

		/****************************/
		/*		NECROPOLIS		    */
		/****************************/
		std::string takeCross;
		bool isCrossTaken = false;
		while (currentRoom->getDescription() == "Necropolis 2nd Floor")
		{
			std::string nav;
			std::string action;


			if (isCrossTaken == false)
			{
				std::cout << "This room is very eerire and large. I see what seems to be a large assortment of tombstones.  " << std::endl <<
					"There is a cross on one of the tombstones. What do you want to do? look, move, etc..." << std::endl;

				getline(std::cin, action);

				if (action == "look tombstone" || action == "search tombstone")
				{
					std::cout << "Do you want to take the cross? y/n " << std::endl;
					getline(std::cin, takeCross);
					if (takeCross == "y")
					{
						std::cout << "You obtained the cross! With this, you can drive all the possessed spirits away from this sacred dungeon." << std::endl <<
							"But first,you need to defeat all the enemies! " << std::endl;

						invent->add(&cross);
					}

					else
					{
						std::cout << "You need to take the cross, or else this place is damned to hell." << std::endl;
					}

				}

				else if (action == "move")
				{
					std::cout << "Where do you want to move to? : " << std::endl;
					getline(std::cin, nav);
					currentRoom = currentRoom->getRoom(nav);
				}

				else if (action == "i")
				{
					invent->displayInventory();
				}

				else
				{
					std::cout << "There's not much I can do with this. " << std::endl;
				}





			}

			else
			{
				std::cout << "You can't move on if you do not pick up the cross. " << std::endl;
			}
		}

		while (currentRoom->getDescription() == "Battleground 2nd Floor")
		{
			std::string useCross;
			bool isManticoreDead = false;
			bool isHippogriffDead = false;
			bool isDragonDead = false;

			if (isArenaKeyTaken == false)
			{
				std::cout << " You cannot enter the boss room, you need a key. " << std::endl;
				std::cout << "Where do you want to move to: " << std::endl;
				getline(std::cin, nav);
				currentRoom = currentRoom->getRoom(nav);
			}

			else
			{
				
				std::cout << " You step into a battleground arena with 3 possessed enemies: " << std::endl <<
					"1). Manticore: " << manticore.GetDescription() << std::endl <<
					"2). Hippogriff: " << hippogriff.GetDescription() << std::endl <<
					"3). Dragon: " << dragon.GetDescription() << std::endl;

				if (isManticoreDead == false)
				{
					std::cout << "You are figthing Manticore. " << std::endl;
					combat(manticore, health);
					isManticoreDead = true;

				}

				if (isManticoreDead == true)
				{
					std::cout << "You are figthing Hippogriff. " << std::endl;
					combat(hippogriff, health);
					isHippogriffDead = true;
				}

				if (isHippogriffDead == true)
				{
					std::cout << "You are figthing Dragon. " << std::endl;
					combat(dragon, health);
					isDragonDead = true;
				}

				if(isDragonDead == true)
				{
					std::cout << " You defeated all the enemies that possess this place. Now you can expell all the bad spirits " << std::endl
						<< " out of this place. Do you want to use the cross to perform an exorcism?" << std::endl;

					getline(std::cin, useCross);
					if (useCross == "y")
					{
						std::cout << "You won!" << std::endl;
						std::string hello;
						getline(std::cin, hello);
						exit(0);
					}

					else
					{
						std::cout << "Well you did all that for nothing. =( " << std::endl;
					}
				}


			}

		}






		/*std::string action(){
			std::string a;
			std::cout << "Do you want to: move, search, look, take, i for inventory." << std::endl;
			std::getline(std::cin, a);
			return a;
		}*/
	}
}
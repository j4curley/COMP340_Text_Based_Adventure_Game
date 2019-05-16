#include "NormalItem.h"

NormalItem::NormalItem(std::string name, std::string description) {
	this->name = name;
	this->description = description;
}

NormalItem::NormalItem() {

}

NormalItem::~NormalItem() {

}

std::string NormalItem::GetName() {
	return name;
}

std::string NormalItem::GetDescription() {
	return description;
}

int NormalItem::Heal(int something) {
	something = something + 10;
	return something;
}

void NormalItem::Use(NormalItem item) {
	//Put code here to use certain items
	std::cout << "This: " << std::endl;
}


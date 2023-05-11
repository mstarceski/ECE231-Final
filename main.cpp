//Max Starceski
//ECE 231L
//Final Project

#include <iostream>
#include <vector>
#include "Item.h"
#include "Critter.h"
#include <fstream>
//#include "functions.h"


int main(){
	Item i;
	std::cout << "test" << std::endl;

	std::cout << i.getPrice() << " " << i.getID() << " " << i.getName() << " " << i.getUID() << std::endl; 
	//std::vector<Item*> i2 = readData("art.csv");

	//std::cout << i2.size() << " " << i2[40]->getName() << " " << i2[40]->getPrice() << std::endl;
	

	std::ifstream itemfile;
	itemfile.open("art.csv", std::ios::in);
	std::vector<Item*> itemList;
	int comma;
	int nextComma;
	std::string line;
	std::getline(itemfile, line);
	if (itemfile.is_open()){
		while(std::getline(itemfile, line)){
			Item *i = new Item;
			i->readLine(line, 4); 
			itemList.push_back(i);
		}
	} else {std::cout << "File could not be opened" << std::endl;}
	itemfile.close();

	std::cout << *itemList[0] << std::endl;

	std::ifstream critterfile;
	critterfile.open("insects.csv", std::ios::in);
	std::vector<Critter*> critterList;
	std::getline(critterfile, line);
	if (critterfile.is_open()) {
		while (std::getline(critterfile, line)) {
			Critter* c = new Critter;
			c->readLine(line, 1, 6, 18);
			critterList.push_back(c);
			std::cout << *c << std::endl;
		}
	}
	else { std::cout << "File could not be opened" << std::endl; }
	critterfile.close();

//	std::cout << *critterList[18] << std::endl;



	return 0;
}





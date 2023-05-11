//Max Starceski
//ECE 231L
//Final Project

#ifndef _ITEM_H
#define _ITEM_H

#include <string>
#include <iostream>
#include <ostream>

class Item {
	private:
		int price; //No non integer prices, doesn't need to be double, units are "bells", this is sell price in all the csvs
		int ID;
		std::string UID;	//Weird unique ID
		std::string name;
	public:
		Item() {price = ID = -1; UID = "uninitialized"; name = "no name";}
		Item(int n_p, int n_ID, std::string n_UID, std::string n_n) {
		price = n_p; ID = n_ID; UID = n_UID; name = n_n;
		}
		
		int getPrice() {return price;} 
		int getID() {return ID;}
		std::string getUID() {return UID;}
		std::string getName() {return name;}
		
		void setPrice(int n_p) {price = n_p;}
		void setID(int n_ID) {ID = n_ID;}
		void setUID(std::string n_UID) {UID = n_UID;}
		void setName(std::string n_n) {name = n_n;}
		//read data for the Item from a csv styled string:
		//price_pos is whatever entry the price is located in
		//EX:	ham,...,...,...,20  => price_pos = 4 [ZERO INDEXED]
		virtual void readLine(std::string line, int price_pos);
		bool operator>(const Item &rhs){return price>rhs.price;}
		bool operator<(const Item &rhs){return price<rhs.price;}
		
		~Item(){}
};

void Item::readLine(std::string line, int price_pos) {

	int comma;
	int nextComma;
	
	nextComma = line.find(",");
	if(nextComma == std::string::npos) return;
	//std::cout<<line.substr(0, nextComma) << std::endl;
	name = line.substr(0, nextComma);
	//std::cout<<name<<std::endl;
	
	for(int i = 0; (++i < price_pos) && (nextComma != std::string::npos); nextComma = line.find(",", nextComma+1));
	if(nextComma == std::string::npos) return;

	comma = nextComma;
	nextComma = line.find(",", nextComma+1);

	//std::cout<<line.substr(comma, nextComma-comma) << "\n \n" <<comma <<std::endl;
	price = std::stoi(line.substr(comma+1, nextComma-comma));
	
	nextComma = line.rfind(",");
	comma = line.rfind(",", nextComma-1);

	ID = std::stoi(line.substr(comma+1, nextComma-comma));
	UID = line.substr(nextComma+1, std::string::npos);
}

std::ostream& operator<<(std::ostream& os, Item& rhs) {
	os << rhs.getName() << "\n";
	os << "\tSell price: " << rhs.getPrice() << " bells\n";
	os << "\tID number: " << rhs.getID() << "\n";
	os << "\tUnique ID code: " << rhs.getUID();

	return os;
}






#endif

//Max Starceski
//ECE231
//Final Project

#ifndef _CRITTER_H
#define _CRITTER_H

#include "Item.h"
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <ostream>

const std::string MONTHS[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

class Critter : public Item {

	private:
		std::vector<std::string> NHmonths_catchable;
		std::vector<std::string> SHmonths_catchable;
		std::string time_catchable;
	public:
		Critter() : Item() {time_catchable = "never";}
		Critter(std::string n_tc) {time_catchable = n_tc;}
		
		std::string getNHAvailability() {
			std::string out = "";
			for (int i = 0; i < NHmonths_catchable.size(); i++) {
				out = out + NHmonths_catchable[i] + " ";
			}
			return out;
		} 
		std::string getSHAvailability() {
			std::string out = "";
			for (int i = 0; i < SHmonths_catchable.size(); i++) {
				out = out + SHmonths_catchable[i] + " ";
			}
			return out;
		}
		std::string getTime() { return time_catchable; }
		
		void readLine(std::string line, int sell_price_pos, int NH_time_pos, int SH_time_pos);
		~Critter() {}
};

void Critter::readLine(std::string line, int sell_price_pos, int NH_time_pos, int SH_time_pos) {
	
//	std::cout << "Entered derived class function!" << std::endl;
	Item::readLine(line, sell_price_pos);

	//https://www.geeksforgeeks.org/cpp-string-to-vector-using-delimiter/:
	std::vector<std::string> line_vector;
	char *token = strtok(const_cast<char*>(line.c_str()), ",");
	while (token != nullptr){
		line_vector.push_back(std::string(token));
		token = strtok(nullptr, ",");
	}
	
//	std::cout << "Partitioning successful!" << std::endl;

	for(int i = 0; i < 12; i++){
		if(line_vector[NH_time_pos + i] != "NA"){
			NHmonths_catchable.push_back(MONTHS[i]);

				time_catchable = line_vector[NH_time_pos + i]; 
				//std::cout << time_catchable << std::endl;

		}
		if(line_vector[SH_time_pos + i] != "NA"){
			SHmonths_catchable.push_back(MONTHS[i]);

			time_catchable = line_vector[SH_time_pos + i];
		}		
	}
}

std::ostream& operator<<(std::ostream& os, Critter &rhs) {
	Item temp = rhs;
	os << temp;
	os << "\n\tCatchable in the Northern Hemisphere in " << rhs.getNHAvailability()
		<< "\n\tCatchable in the Southern Hemisphere in " << rhs.getSHAvailability()
		<< "\n\tCatchable between " << rhs.getTime();

	return os;
}



#endif

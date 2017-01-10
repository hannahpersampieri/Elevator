// elevator.cpp
#include <iostream>
#include "elevator.h"
using namespace std;

//default constructor
Elevator::Elevator(){
	floors = 0;
	direction = Elevator::IDLE;
	pushed_floors = new set<int>;
}
// overloaded constructor
Elevator::Elevator(int num_floors){
	floors = num_floors;
	direction = Elevator::IDLE;
	pushed_floors = new set<int>;
}
//destructor
Elevator::~Elevator(){
	delete pushed_floors;
}
// copy constructor 
Elevator::Elevator(const Elevator &other){
	copy(other);
}
//assignment operator
Elevator & Elevator::operator=(const Elevator & other){
	if (this != other){
		copy(other);
	}
	return *this;
}
void Elevator::copy(const Elevator &other){
	set_floors(other.get_floors());
	set_pushed_floors(other.get_pushed_floors());
	*this = other;
	return;
}
int Elevator::get_floors(){
	return floors;
}

set<int> Elevator::get_pushed_floors(){
	return pushed_floors;
}
void Elevator::set_floors(int new_num){
	floors = new_num;
	return;
}
string Elevator::get_direction(){
	if (direction == Elevator::UP){
		return "Up";
	}
	else if (direction == Elevator::DOWN){
		return "Down";
	}
	else{
		return "Idle";
	}
}

void Elevator::set_pushed_floors(set new_set){
	temp = pushed_floors;
	pushed_floors = new_set;
	delete temp;
	return;
}
string Elevator::get_id(){
	return id;
}

void Elevator::set_id(string name){
	id = name;
	return;
}
int Elevator::get_curr_floor(){
	return current_floor;
}
void Elevator::set_curr_floor(int f){
	current_floor = f;
	return;
}
void Elevator::ride(){
	int i;
	if(direction == Elevator::UP){
		i = 0;
	}
	else{
		i = pushed_floors.size();
	}
	while(!pushed_floors.empty() && direction != Elevator::IDLE){
		if (direction == Elevator::UP){
			cout <<"Elevator " << id << " going up!" << endl;
			set_curr_floor(pushed_floors[i]);
			cout << "Elevator" << id << " stopping at floor:" << pushed_floors[i] << endl;
			cout << "Press a button to go to a desired floor." << endl;
			int floor_request;
			cin >> floor_request;
			process_request(floor_request);
			i++;
		}
		else{
			cout <<"Elevator " << id << " going up!" << endl;
			set_curr_floor(pushed_floors[i]);
			cout << "Elevator" << id << " stopping at floor:" << pushed_floors[i] << endl;
			cout << "Press a button to go to a desired floor." << endl;
			int floor_request;
			cin >> floor_request;
			process_request(floor_request);
			i--;
		}
	}
	cout << "Elevator " << id << " is returning to idle service now." << endl;
	direction = Elevator::IDLE;
	return;
}

void Elevator::process_request(int floor_request){
	if (direction == Elevator::UP && floor_request < current_floor){
		cout << "Sorry, Elevator " << id << " is going up right now." << endl;
	}
	else if (direction == Elevator::DOWN && floor_request > current_floor){
		cout << "Sorry, Elevator " << id << " is going down right now." << endl;
	}
	else{
		pushed_floors.insert(floor_request);
		cout << "New request to go to floor " << floor_request << endl;
	}
	return;
}
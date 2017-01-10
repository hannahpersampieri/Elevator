// lobby.cpp
#include <iostream>
#include <queue> 
#include <vector>
#include "lobby.h"
#include "elevator.h"
using namespace std;
// default constructor
Lobby::Lobby(){
	elevators = new vector<Elevator>;
	requests = new queue<Request>;
}
// overloaded constructor
Lobby::Lobby(int num_elevators, int floors){
	elevators = new vector<Elevator>;
	for(int i = 0; i < num_elevators; i++){
		Elevator elev = new Elevator(floors);
		elev.set_id(to_string(i));
		elevators.push(elev);
	}
}
// destructor
Lobby::~Lobby(){
	for (int i = 0; i < elevators.size(); i++){
		delete elevators[i];
	}
	delete elevators;
	delete requests;
}
// Copy constructor
Lobby::Lobby(const Lobby & other){
	copy(other);
}
// Assign operator
Lobby & Lobby::operator=(const Lobby & other){
	if (this != other){
		copy(other);
	}
	return *this;
}
// getter/setter functions
vector<Elevator> Lobby::get_elevators(){
	return elevators;
}
queue<int> Lobby::get_requests(){
	return requests;
}
bool Lobby::no_requests(){
	if(requests.empty()){
		return true;
	}
	else{
		return false;
	}
}
void Lobby::copy(const Lobby & other){
	elevators = other.(get_elevators());
	requests = other.(get_requests());
}
// creating a new request and adding it to the queue 
void Lobby::generate_request(string direction_input, int floor){
	Request r = new Request;
	if (direction_input == "up" or direction_input == "Up" or direction_input =="UP"){
		r.direction = 1;
	}
	else{
		r.direction = 0;
	}
	r.floor = floor;
	requests.enqueue(r);
	delegate_requests();
	return;
}
// Take a request and find the best elevator to delegate it to 
void Lobby::delegate_requests(){
	while(!requests.empty()){
		Request next = requests.front();
		bool processed = false;
		int i = 0;
		while(not processed and i < elevators.size()){
			Elevator e = elevators[i];
			string direction = e.get_direction();
			if(direction == "Up" and e.get_curr_floor < next.floor and next.direction == 1){
				e.process_request(next.floor);
				requests.pop();
				e.ride();
				processed = true;
			}
			else if(direction == "Down" and e.get_curr_floor > next.floor and next.direction == 0){
				e.process_request(next.floor);
				requests.pop();
				e.ride();
				processed = true;
			}
			else if(direction == "Idle"){
				e.process_request(next.floor);
				requests.pop();
				e.ride();
				processed = true;
			}
			i++;
		}
		if (i >= elevators.size()){
			requests.pop();
			requests.enqueue(next);
		}
	}
	return;
}
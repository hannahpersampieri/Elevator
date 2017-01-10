// lobby.h
// Header file for the lobby class
// contains all of the elevators and manages requests (from any floor)

#ifndef LOBBY_H
#define LOBBY_H
#include <iostream>
#include <queue> 
#include <vector>
#include "elevator.h"
using namespace std;
struct Request {
	// 0 is down, 1 is up
	bool direction;
	int intial_floor;
};

class Lobby {
	public:
		// default constructor
		Lobby();
		// overloaded constructor
		Lobby(int num_elevators, int floors);
		// destructor
		~Lobby();
		// Copy constructor
	  	Lobby(const Lobby & other);
	  // Assign operator
	 	Lobby & operator=(const Lobby & other);
	 	void generate_request(string direction_input, int floor);
	 	queue<int> get_requests();
	 	bool no_requests();
	 	vector<Elevator> get_elevators();
	private:
		// array of all the elevators within the lobby
		vector<Elevator> elevators;
		// Queue for processing reuqests 
		queue<Request> requests;
		int num_elevators;
		int floors;
		void delegate_requests();
		void copy(const Lobby &other);

};
#endif 
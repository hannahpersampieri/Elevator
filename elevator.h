// elevator.h
// Header File for the elevator class
// Hannah Voelker 1/9/16
#ifndef ELEVATOR_H
#define ELEVATOR_H
#include <iostream>
#include <set>
using namespace std;

class Elevator {
	enum direction{
		UP,
		DOWN,
		IDLE
	};
	public:
		// default constructor
		Elevator();
		// overloaded constructor
		Elevator(int floors);
		// destructor
		~Elevator();
		// Copy constructor
	  	Elevator(const Elevator & other);
	  // Assign operator
	 	Elevator & operator=(const Elevator & other);
	 private:
	 	set<int> pushed_floors;
	 	int floors;

};

#endif
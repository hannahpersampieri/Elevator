// Main.cpp
// Tying it all together
#include <iostream>
#include "elevator.h"
#include "lobby.h"
#include <string> 

using namespace std;

int main(){
	cout << "Let's set up. How many elevators would you like?" << endl;
	int num_elev, num_floors;
	cin >> num_elev;
	cout << "How many floors are in this building?" << endl;
	cin >> num_floors;
	Lobby l = Lobby(num_elev, num_floors);
	cout << "Great, now we are up and running." << endl;
	bool done = false;
	while(not done){
				int floor;
		string direction;
		cout << "What floor are you on?" << endl;
		cin >> floor;
		cout << "What direction would you like to go?" << endl;
		cin >> direction;
		cout << "Processing your request now." << endl;
		l.generate_request(direction, floor);
		if(l.no_requests()){
			int input;
			cout << "All requests processed. To exit, type -1. Choose 1 for another request" << endl;
			if(input == -1){
				done = true;
			}
		}
	}
	return 0;
}


#include <iostream>
#include <iomanip>
using namespace std;
#include "Queue.h"
struct Teller_s {
	bool active;
	int time_At;
};
int main() {
	//Min/Max values for user input
	const int    MIN_SIM_TIME   = 0, MAX_SIM_TIME   = 10000,
	             MIN_TRANS_TIME = 0, MAX_TRANS_TIME = 100,
				 MIN_NUM_SERV   = 0, MAX_NUM_SERV   = 10,
				 MIN_ARRIV_TIME = 0, MAX_ARRIV_TIME = 100;
				 
	char runAgain = 'Y'; //Set runAgain so the program runs
	int sim_Time, trans_Time, num_Serv, arriv_Time; //User input variables
	int i, c_Time; //Counters
	int customers, wait_Time; //Total customers and integer for customer waiting time
	while (runAgain != 'N') {
		i = 0; c_Time = 0;
		customers = 0; wait_Time = 0;
		
		Queue bankQ; //Create queue object
		
		cout << "\n------------------------------------------"
			 << "\n- Welcome to the Bank Simulation Program -"
			 << "\n------------------------------------------";
		
		//Menu information
		cout << "\n\nPlease input the following data(Time in minutes):\n";
		cout << "\nLength of the Simulation: ";
		cin >> sim_Time;
		while (sim_Time <= MIN_SIM_TIME || sim_Time > MAX_SIM_TIME) {
			cout << "Invalid input. Please re-enter: ";
			cin >> sim_Time;
		}
		cout << "Average Transaction Time: ";
		cin >> trans_Time;
		while (trans_Time <= MIN_TRANS_TIME || trans_Time > MAX_TRANS_TIME) {
			cout << "Invalid input. Please re-enter: ";
			cin >> trans_Time;
		}
		cout << "Average Number of Servers: ";
		cin >> num_Serv;
		while (num_Serv <= MIN_NUM_SERV || num_Serv > MAX_NUM_SERV) {
			cout << "Invalid input. Please re-enter: ";
			cin >> num_Serv;
		}
		cout << "Average Time Between Arrivals: ";
		cin >> arriv_Time;
		while (arriv_Time <= MIN_ARRIV_TIME || arriv_Time > MAX_ARRIV_TIME) {
			cout << "Invalid input. Please re-enter: ";
			cin >> arriv_Time;
		}
		
		//Dynamically allocate an array for the teller structure
		Teller_s * tellArray = new Teller_s[num_Serv];
		
		//Set all tellers to empty
		for (i = 0; i < num_Serv; i++) {
			tellArray[i].active = false;
			tellArray[i].time_At = trans_Time;
		}
		
		while (c_Time < sim_Time) { //Run until simulation time is reached
			if (c_Time % arriv_Time == 0) { //Check if a customer should be enqueued
				bankQ.enqueue();
				customers++;
			}
			for (i = 0; i < num_Serv; i++) {
				if (tellArray[i].active == false && bankQ.getSize() != 0) { //Dequeue if a teller is open
					bankQ.dequeue();
					tellArray[i].active = true;
					tellArray[i].time_At = trans_Time;						
				}
			}
			
			
			
			for (i = 0; i < num_Serv; i++) {
				if (tellArray[i].active == true) {
					tellArray[i].time_At--;  //Decrement time spent at teller
				}
				if (tellArray[i].time_At == 0) {
					tellArray[i].active = false; //Set teller to open if time limit is reached
				}
			}
			
			wait_Time += bankQ.getSize(); //Set wait time to persons left in queue
			c_Time++;
		}
		//Output user input data
		cout << "\n---------------"
			 << "\n- Data Output -"
			 << "\n---------------\n";
			 
		cout << setw(31) << left << "Simulation Time: ";
		cout << sim_Time << endl;
		
		cout << setw(31) << left << "Average Transaction Time: ";
		cout << trans_Time << endl;
		
		cout << setw(31) << left << "Average Number of Servers: ";
		cout << num_Serv << endl;
		
		cout << setw(31) << left << "Average Time Between Arrivals: ";
		cout << arriv_Time << endl << endl;
		
		//Output calculated data
		cout << "Average Total Wait Time: ";
		cout << fixed << setprecision(2)
			 << (float)wait_Time/customers;
		cout << "\nCustomers in line at end of simulation: "
	         << bankQ.getSize() << endl;
		
		//Ask to run again
		cout << "\nRun the program again? (y/n): ";
		cin >> runAgain;
		runAgain = (char)toupper(runAgain);
		while (runAgain != 'Y' && runAgain != 'N') {
			cout << "Invalid Entry, please re-enter: ";
			cin >> runAgain;
			runAgain = (char)toupper(runAgain);
		}
		//Deallocate teller structure array
		delete [] tellArray;
	}	
	return 0;
}
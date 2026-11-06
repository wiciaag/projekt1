

#include <iostream>
#include<cmath>
using namespace std;
double infectionRate = 0.20;
double recoveryRate = 0.10;
int susceptible = 80;
int infected = 10;
int recovered = 10;
int day = 0;
void showPopulation();
void SimulateNextDay();
void ChangeModelParameters();
bool checkPopulation();
void ShowSimulationHistory();
int maxdays = 5;
int* limit = new int[maxdays];//limit dni epidemii-101 dni od 0 do dnia 100, ale zapisalam w postaci zmiennej zeby latwiej bylo to potem sprawdzic
int status[101][3] = {};//wiersze to kolejne dni, a kolumny to: 0-podatni,1-zainfekowani,2-wykurowani
int* dailynewinfections=new int[maxdays-1];
int* dailynewrecoveries=new int[maxdays-1];
int main()
{
	status[0][0] = 80;
	status[0][1] = 10;
	status[0][2] = 10;
	while (7) {
		showPopulation();
		int choice;
		cout << "== Epidemic Simulator ==\n1. Simulate next day\n2. Change model parameters\n3. Exit\n4. Show simulation history\nYour choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			if (day + 1 <= maxdays) {
				SimulateNextDay();
				break;
			}
			else {
				break;
			}
		case 2:
			ChangeModelParameters();
			break;
		case 3:
			break;
		case 4:
			ShowSimulationHistory();
			break;
		default:
			cout << "Your number is not correct. Try again:/\n";
			continue;

		}
		if (checkPopulation() == false) {
			cout << "\nYour population has no right to exist anymore, sorry:( \n";
			break;
		}
		if (choice == 3) {
			break;
		}
		if (day + 1 > maxdays) {
			cout << "Your epidemic is too long!";
			break;
		}
	}

	
}
void showPopulation() {
	cout << "Day: " << day<<"\n";
	cout << "Susceptible: " << susceptible << "\n";
	cout << "Infected: " << infected << "\n";
	cout << "Recovered: " << recovered << "\n";
	cout << "Total: " << susceptible + infected + recovered << "\n";
}
void SimulateNextDay(){
	day++;	
		limit[day] = day;
		int yesterdayinfected = infected;
		int newinfections = floor(yesterdayinfected * infectionRate);
		int newrecoveries = floor(yesterdayinfected * recoveryRate);
		susceptible = susceptible - newinfections;
		recovered = recovered + newrecoveries;

		infected = newinfections + yesterdayinfected;
		infected = infected - newrecoveries;
		dailynewinfections[day - 1] = newinfections;
		dailynewrecoveries[day - 1] = newrecoveries;
	status[day][0] = susceptible;
	status[day][1] = infected;
	status[day][2] = recovered;
	

	}
void ChangeModelParameters() {
	cout << "New value of infection rate(0-1): ";
	cin >> infectionRate;
	while (7) {
		if (infectionRate > 1.0 || infectionRate < 0.0) {
			cout << "That is not correct value, try again: ";
			cin >> infectionRate;
		}
		else {
			break;
		}
	}
	cout << "\n";
	cout << "New value of recovery rate(0-1): ";
	cin >> recoveryRate;
	while (7) {
		if (recoveryRate > 1.0 || recoveryRate < 0.0) {
			cout << "That is not correct value, try again: ";
			cin >> recoveryRate;
		}
		else {
			break;
		}
	}
	cout << "\n";
}
bool checkPopulation() {
	if (susceptible >= 0 && infected >= 0 && recovered >= 0 && susceptible + infected + recovered == 100) {
		return true;
	}
	else {
		return false;
	}

}
void ShowSimulationHistory() {
	cout << "Day:     Susceptible:     Infected:    Recovered:    New infections:    New recoveries: " << endl;
	for (int i = 0;i <= day;i++) {
		if (i!=0) {
			cout << i << "        " << status[i][0] << "               " << status[i][1] << "           " << status[i][2] << "             " << dailynewinfections[i-1] << "                  " << dailynewrecoveries[i-1] << endl;
		}
		else {
			cout<< i << "        " << status[i][0] << "               " << status[i][1] << "           " << status[i][2] << "             -                  - " << endl;
		}
	}
}
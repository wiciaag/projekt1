

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
int main()
{
	while (7) {
		showPopulation();
		int choice;
		cout << "== Epidemic Simulator ==\n1. Simulate next day\n2. Change model parameters\n3. Exit\nYour choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			SimulateNextDay();
			break;
		case 2:
			ChangeModelParameters();
			break;
		case 3:
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
	int yesterdayinfected=infected;
	int newinfections = floor(yesterdayinfected * infectionRate);
	int newrecoveries = floor(yesterdayinfected * recoveryRate);
	if (yesterdayinfected * infectionRate <= susceptible && yesterdayinfected * recoveryRate <= infected) {
		susceptible = susceptible - newinfections;
		recovered = recovered + newrecoveries;

		infected = newinfections + yesterdayinfected;
		infected = infected - newrecoveries;
	}
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


#include <iostream>
using namespace std;
double infectionRate = 0.20;
double recoveryRate = 0.10;
int susceptible = 80;
int infected = 10;
int recovered = 10;
int day = 0;
void showPopulation(int day, int susceptible, int infected, int recovered);
void SimulateNextDay(int day, int susceptible, int infected, int recovered);
void ChangeModelParameters(double recoveryRate,double infectedRate);
bool checkPopulation(int susceptible, int infected, int recovered);
int main()
{
	while (7) {
		showPopulation(day, susceptible, infected, recovered);
		int choice;
		cout << "== Epidemic Simulator ==\n1. Simulate next day\n2. Change model parameters\n3. Exit\nYour choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			SimulateNextDay(day, susceptible, infected, recovered);
			if (checkPopulation(susceptible,infected,recovered) == false) {
				cout << "\nYour population has no right to exist, sorry:( ";
				break;
			}
			break;
		case 2:
			ChangeModelParameters(recoveryRate,infectionRate);
			break;
		case 3:
			break;
		default:
			cout << "Your number is not correct. Try again:/\n";
			continue;

		}
		
	}

	
}
void showPopulation(int day, int susceptible, int infected, int recovered) {
	cout << "Day: " << day<<"\n";
	cout << "Susceptible: " << susceptible << "\n";
	cout << "Infected: " << infected << "\n";
	cout << "Recovered: " << recovered << "\n";
	cout << "Total: " << susceptible + infected + recovered << "\n";
}
void SimulateNextDay(int day, int susceptible, int infected, int recovered){
	day++;
	int yesterdayinfected=infected;
	if (yesterdayinfected * infectionRate >= susceptible && yesterdayinfected * recoveryRate >= infected) {
		susceptible = susceptible - (yesterdayinfected * infectionRate);
		recovered = recovered + (yesterdayinfected * recoveryRate);

		infected = (infected * infectionRate) + infected;
		infected = infected - (yesterdayinfected * recoveryRate);
	}
}
void ChangeModelParameters(double recoveryRate,double infectionRate) {
	cout << "New value of infection rate: ";
	cin >> infectionRate;
	cout << "\n";
	cout << "New value of recovery rate: ";
	cin >> recoveryRate;
	cout << "\n";
}
bool checkPopulation(int susceptible, int infected, int recovered) {
	if (susceptible >= 0 && infected >= 0 && recovered >= 0 && susceptible + infected + recovered == 100) {
		return true;
	}
	else {
		return false;
	}
}
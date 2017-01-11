#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	//ANSWER TO EXTRA CREDIT QUESTION: 166.66667 miles per gallon

	/*
	Test Case 1:
	10000
	2.50
	45000
	45
	5000
	30000
	22
	1000
	Gas

	Hybrid Gallons: 1111.11
	Hybrid Cost: 42777.8
	Non-Hybrid Gallons: 2272.7
	Non-Hybrid Cost: 34681.8

	Test Case 2:
	12000
	2.00
	40000
	50
	5000
	35000
	23
	2000
	Total

	Hybrid Gallons: 1200
	Hybrid Cost: 37400
	Non-Hybrid Gallons: 2608.7
	Non-Hybrid Cost: 38217.39

	Test Case 3:
	15000
	3.50
	35000
	55
	5000
	30000
	20
	10000
	Total

	Non-Hybrid Gallons: 3750
	Non-Hybrid Cost: 33125
	Hybrid Gallons: 1363.64
	Hybrid Cost: 34772.7

	*/

	//Part 1 - User Input

	double miles_driven_per_year;
	double price_gallon_gas;

	double hybrid_initialCost;
	double hybrid_milesPerGallon;
	double hybrid_resaleValue;

	double car_initialCost;
	double car_milesPerGallon;
	double car_resaleValue;

	string buying_criterion;

	// Miles Driven Per Year and Price of a Gallon of Gas
	cout << "\nEnter the estimated amount of miles the car will be driven per year: ";
	cin >> miles_driven_per_year;
	if (miles_driven_per_year <= 0) {
		cout << "\n\t\t\tMake sure your input is greater than zero!\n";
		cout << "\nEnter the estimated amount of miles the car will be driven per year: ";
		cin >> miles_driven_per_year;
	}

	cout << "Enter the estimated price of a gallon of gas during the 5 years of ownership: $";
	cin >> price_gallon_gas;
	if (price_gallon_gas <= 0) {
		cout << "\n\t\t\tMake sure your input is greater than zero!\n";
		cout << "\nEnter the estimated price of a gallon of gas during the 5 years of ownership: $";
		cin >> price_gallon_gas;
	}

	// Hybrid Car Inputs
	cout << "Enter the initial cost of the hybrid car: $";
	cin >> hybrid_initialCost;
	if (hybrid_initialCost <= 0) {
		cout << "\n\t\t\tMake sure your input is greater than zero!\n";
		cout << "\nEnter the initial cost of the hybrid car: $";
		cin >> hybrid_initialCost;
	}

	cout << "Enter the efficiency of the hybrid car in miles per gallon: ";
	cin >> hybrid_milesPerGallon;
	if (hybrid_milesPerGallon <= 0) {
		cout << "\n\t\t\tMake sure your input is greater than zero!\n";
		cout << "\nEnter the efficiency of the hybrid car in miles per gallon: ";
		cin >> hybrid_milesPerGallon;
	}

	cout << "Enter the estimated resale value for a hybrid after 5 years: $";
	cin >> hybrid_resaleValue;
	if (hybrid_resaleValue <= 0) {
		cout << "\n\t\t\tMake sure your input is greater than zero!\n";
		cout << "\nEnter the estimated resale value for a hybrid after 5 years: $";
		cin >> hybrid_resaleValue;
	}

	// Non-Hybrid Car Inputs
	cout << "Enter the initial cost of the non-hybrid car: $";
	cin >> car_initialCost;
	if (car_initialCost <= 0) {
		cout << "\n\t\t\tMake sure your input is greater than zero!\n";
		cout << "\nEnter the initial cost of the non-hybrid car: $";
		cin >> car_initialCost;
	}

	cout << "Enter the efficiency of the non-hybrid car in miles per gallon: ";
	cin >> car_milesPerGallon;
	if (car_milesPerGallon <= 0) {
		cout << "\n\t\t\tMake sure your input is greater than zero!\n";
		cout << "\nEnter the efficiency of the non-hybrid car in miles per gallon: ";
		cin >> car_milesPerGallon;
	}

	cout << "Enter the estimated resale value for a non-hybrid after 5 years: $";
	cin >> car_resaleValue;
	if (car_resaleValue <= 0) {
		cout << "\n\t\t\tMake sure your input is greater than zero!\n";
		cout << "\nEnter the estimated resale value for a non-hybrid after 5 years: $";
		cin >> car_resaleValue;
	}

	cout << "Enter your buying criterion (either 'Gas' for minimized gas or 'Total' for minimized total cost): ";
	cin >> buying_criterion;

	//Part 2 - Output Costs

	double hybrid_totalGallons = (miles_driven_per_year * 5) / hybrid_milesPerGallon;
	double car_totalGallons = (miles_driven_per_year * 5) / car_milesPerGallon;

	double hybrid_totalCost = (price_gallon_gas * hybrid_totalGallons) + (hybrid_initialCost - hybrid_resaleValue);
	double car_totalCost = (price_gallon_gas * car_totalGallons) + (car_initialCost - car_resaleValue);

	if (buying_criterion == "Gas" && hybrid_totalGallons < car_totalGallons) {
		cout << "\n\nHybrid Car\n";
		cout << "Total gallons of fuel consumed over 5 years: " << hybrid_totalGallons << "\n";
		cout << "The total cost of owning the car for 5 years: $" << hybrid_totalCost;

		cout << "\n\nNon-Hybrid Car\n";
		cout << "Total gallons of fuel consumed over 5 years: " << car_totalGallons << "\n";
		cout << "The total cost of owning the car for 5 years: $" << car_totalCost << "\n\n";
	}
	else if (buying_criterion == "Gas" && car_totalGallons < hybrid_totalGallons) {
		cout << "\n\nNon-Hybrid Car\n";
		cout << "Total gallons of fuel consumed over 5 years: " << car_totalGallons << "\n";
		cout << "The total cost of owning the car for 5 years: $" << car_totalCost;

		cout << "\n\nHybrid Car\n";
		cout << "Total gallons of fuel consumed over 5 years: " << hybrid_totalGallons << "\n";
		cout << "The total cost of owning the car for 5 years: $" << hybrid_totalCost << "\n\n";
	}
	else if (buying_criterion == "Total" && hybrid_totalCost < car_totalCost) {
		cout << "\n\nHybrid Car\n";
		cout << "Total gallons of fuel consumed over 5 years: " << hybrid_totalGallons << "\n";
		cout << "The total cost of owning the car for 5 years: $" << hybrid_totalCost;

		cout << "\n\nNon-Hybrid Car\n";
		cout << "Total gallons of fuel consumed over 5 years: " << car_totalGallons << "\n";
		cout << "The total cost of owning the car for 5 years: $" << car_totalCost << "\n\n";
	}
	else {
		cout << "\n\nNon-Hybrid Car\n";
		cout << "Total gallons of fuel consumed over 5 years: " << car_totalGallons << "\n";
		cout << "The total cost of owning the car for 5 years: $" << car_totalCost;

		cout << "\n\nHybrid Car\n";
		cout << "Total gallons of fuel consumed over 5 years: " << hybrid_totalGallons << "\n";
		cout << "The total cost of owning the car for 5 years: $" << hybrid_totalCost << "\n\n";
	};


	system("pause");

	return 0;
}
/* Car Rental Management System */

// ----------------- Include the libraries -----------------
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <direct.h>
#include <sstream>

// Use namespace
using namespace std;

// ----------------- Define Structurs -----------------
// Customer information struct
struct Customer
{
	string nationalID;
	string fullName;
	string phoneNumber;
	char gender;	
};

// Cars struct
struct Car
{
	string serialNumber;
	string carName;
	string carYear;
	double dailyPrice;
	string vehicleType;		
};
// Bills struct
struct Bill
{
	Customer renter;
	Car rentedCar;
	int numberOfDays;
	double totalPrice;
};

// ----------------- Global Variables Declaration -----------------
bool operationSuccess;
string textUpdate;


// ----------------- Prototypes -----------------
// Function to display the main menu
void displayMainMenu(int numberOfCustomers, int numberOfCars, int numberOfBills);
// Function to display customers menu
void displayCustomersMenu(Customer customer[], int &numOfCustomers);
// Function to display Cars menu.
void displayCarsMenu(Car cars[], int &numberOfCars);
// Function to add new customer.
void addCustomer(Customer customer[], int &numOfCustomers);
// Function to Update the phone number of a customer.
void updateCustomer(Customer customer[], int numOfCustomers);
// Function to search for a customer
int searchCustomer(int searchOption, Customer customer[], int numOfElements);
// Function to delete a customer
void deleteCustomer(Customer customer[], int &numOfCustomers);
// Function to display all customers
void displayCustomers(Customer customer[], int numOfCustomers);
// Function to add new car.
void addCar(Car cars[] , int &numberOfCars);
// Function to search for a car
int searchCar(string value,Car cars[], int numberOfCars);
// Function to update a car
void updateCar(Car cars[], int numberOfCars);
// Function to delete a car
void deleteCar(Car cars[] ,int &numberOfCars);
// Function to display all cars
void displayCars(Car car[], int numberOfCars);
// Function to display Rent a car menu
void billsMenu(Customer customer[], Car cars[], int &numberOfCustomers, Bill bills[], int &numberOfBills, int numberOfCars);
//function to rent a car for exist custumer
void existCustumer(int numberOfCustomers, int numberOfCars ,Customer customers[], Car cars[] , Bill bills[], int &numberOfBills );
//function to rent a car for new custumer
void newCustomerRent(int &numberOfCustomers, int numberOfCars ,Customer customers[], Car cars[] , Bill bills[], int &numberOfBills);
// Function to Create new bill
void createBill(Customer customer[], Car cars[], int &numberOfCustomers, Bill bills[], int &numberOfBills, int numberOfCars);
// Function to delete a bill
void deleteBill(Bill bills[] ,int &numberOfBills);
// Function to display all bills
void displayBills(Bill bills[], int numberOfBills);
// Function to sort the bills descending by the total price  
void sortBills(Bill bills[], int numberOfBills);
// Function to display generate reports menu.
void displayReportsMenu(Customer customer[], Car cars[], Bill bills[], int numberOfCustomers, int numberOfCars,  int numberOfBills);
// Function generate a report of customers to a file (Customers_Report.txt)
void customersReport(Customer customer[], int numberOfCustomers);
// Function generate a report of cars to a file (Cars_Report.txt)
void carsReport(Car car[], int numberOfCars);
// Function generate a report of bills to a file (Bills_Report.txt)
void billsReport(Bill bills[] ,int numberOfBills);
// Function to read Data (Customers, Cars, Bills)
void readData(Customer customer[], int &numberOfCustomers, Car cars[], int &numberOfCars, Bill bills[], int &numberOfBills);
// Function to write customers data to a file(CustomersData.txt)
void writeCustomersData(Customer customer[], int numberOfCustomers);
// Function to write cars data to a file(CarsData.txt)
void writeCarsData(Car cars[], int numberOfCars);
// Function to write bills data to a file(BillsData.txt)
void writeBillsData(Bill bills[], int numberOfBills);
// function to get the current local date and time 
string getDateAndTime();
//Function to check if the phone number of the new customer is new or not
bool isNew(string phoneNum, Customer customer[], int numOfCustomers);
//Function to check if the serialNumber of the new car is new or not
bool isNew(string serialNumber, Car cars[], int numOfCars);
//Function to check if the national ID of the new customer is new or not
bool isIDNew(string nationalID, Customer customer[], int numOfCustomers);
// Function to check if the input is number
bool isNumber(string value);
// Function to create the folders - Data and Reports -
void createFolders();
// Function to print the new bill
void printTheNewBill(Bill bills[], int numberOfBills);
// Function to rent a car for a customer
void rentTheCar(Car cars[], int numberOfCars, Bill bills[], int &numberOfBills);
// Function to write on the (Statistical Report.txt) file after any update
void statisticalReport (string text);
// Function to write the data of the new customer into "CustomersData.txt"
void writeNewCustomer(Customer customer);
// Function to write the data of the new car into "CarsData.txt"
void writeNewCar(Car cars);
// Function to convert double to string 
string numToString (double num);
// Function to convert integer to string 
string numToString (int num);
// Function to write the data of the new bill into "BillsData.txt"
void writeNewBills(Bill bill);
// Check if the input is number or not
void inputInt(int &num);
// Check if the input is number or not
void inputDouble(double &num);
// Function to calculate the age of the customer
int calculateAge();
// Function to check if the user is sure
bool sure();

// Main function
int main()
{
	// Create the Data folder and the Reports rolder
	createFolders();
	
	//Declare the array of the customers.
	Customer customers[1000];
	
	//Declare the array of the cars.
	Car cars[100];
	
	//Declare the array of the bills.
	Bill bills[1000];
	
	// Declare the number of customers and cars and bills.
	int numberOfCustomers = 0;
	int numberOfCars = 0;
	int numberOfBills = 0;
	
	//Read all data (Customers - Cars - Bills) from external files
	readData(customers, numberOfCustomers, cars, numberOfCars, bills, numberOfBills);
	
	// Store the user's choice  
	int mainOption;
	
	// Loop of the main program
	do{
		// Display the main menu and get the choice from the user
		displayMainMenu(numberOfCustomers, numberOfCars, numberOfBills);
		cin >> mainOption;
		
		// Check if the input is number or not
		while(cin.fail())
		{
			// Continue to get input until get an int
			cout << "Please select a valid option [From 1 to 5]" << endl;
			displayMainMenu(numberOfCustomers, numberOfCars, numberOfBills);
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> mainOption;
		}	
	
		// Switch statement for main menu
		switch(mainOption)
		{
			case 1:	
				billsMenu(customers, cars, numberOfCustomers, bills, numberOfBills, numberOfCars);
				break;
			case 2:
				displayCustomersMenu(customers, numberOfCustomers);
				break;
			case 3:
				displayCarsMenu(cars, numberOfCars);
				break;
			case 4:
				displayReportsMenu(customers, cars, bills, numberOfCustomers, numberOfCars, numberOfBills);
				break;
			case 5:
				cout << endl;
				cout << "------------------ GoodBye .. Have a nice day.------------------" << endl;
				break;
			default:
				cout << "Please select a valid option [From 1 to 5]. " << endl;				
		}
	} while (mainOption != 5); // Loop condition to exit the program

	return 0;
}


// ----------------- Define Functions -----------------
// Function to display the main menu.
void displayMainMenu(int numberOfCustomers, int numberOfCars, int numberOfBills)
{
	cout << "---------------------------- Car Rental Management ----------------------------" << endl;
	cout << "Number Of Customers [ " << numberOfCustomers << " ]" << "\tNumber Of Cars[ " << numberOfCars << " ]" << "\tNumber Of Bills[ " << numberOfBills << " ]" << endl << endl;
	cout << "1) Bills." << endl;
	cout << "2) Customers." << endl;
	cout << "3) Cars." << endl;
	cout << "4) Generate reports." << endl;
	cout << "5) Exit." << endl;
	cout << endl;
	
	cout << "Please enter your choice: ";
}

// Function to display customers menu.
void displayCustomersMenu(Customer customer[], int &numOfCustomers)
{	
	// Store the user's choice
	int customerOption;
	// Loop of the customers menu
	do
	{
		cout << endl;
		cout << "------------------ Customers Menu ------------------" << endl;
		cout << "1) Add customer." << endl;
		cout << "2) Update customer." << endl;
		cout << "3) Delete customer." << endl;
		cout << "4) Display customers." << endl;
		cout << "5) Back to main menu." << endl;
		cout << endl;
		
		// Get the user choice
		cout << "Please enter your choice: ";
		cin >> customerOption;
		
		// Check if the input is number or not
		while(cin.fail())
		{
			// Continue to get input until get an int
			cout << "Please select a valid option [From 1 to 5]\n" << endl;
			cout << "Please enter your choice: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> customerOption;
		}	
		
		// Switch statement for customers menu
		switch (customerOption)
		{
			case 1:
				addCustomer(customer, numOfCustomers);
				break;
			case 2:
				updateCustomer(customer, numOfCustomers);
				break;
			case 3:
				deleteCustomer(customer, numOfCustomers);
				break;
			case 4:
				displayCustomers(customer, numOfCustomers);	
				break;
			case 5:
				break;
			default:
				cout << "Please select a valid option [From 1 to 5]. " << endl; 
		}
	} while (customerOption != 5); // Loop condition to go back to the main menu

}

// Function to display Cars menu.
void displayCarsMenu(Car cars[], int &numberOfCars)
{	
	// Store the user's choice
	int carOption;

	// Loop of the cars menu
	do
	{
		cout << endl;
		cout << "------------------ Cars Menu ------------------" << endl;
		cout << "1) Add car." << endl;
		cout << "2) Update car." << endl;
		cout << "3) Delete car." << endl;
		cout << "4) Display cars." << endl;
		cout << "5) Back to main menu." << endl;
		cout << endl;
		
		// Get the user choice
		cout << "Please enter your choice: ";
		cin>>carOption;
		
		// Check if the input is number or not
		while(cin.fail())
		{
			// Continue to get input until get an int
			cout << "Please select a valid option [From 1 to 5]\n" << endl;
			cout << "Please enter your choice: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> carOption;
		}	
		
		// Switch statement for cars menu
		switch (carOption)
		{
			case 1: 
				addCar(cars, numberOfCars);
				break;
			case 2:
				updateCar(cars, numberOfCars);
				break;
			case 3:
				deleteCar(cars ,numberOfCars);
				break;
			case 4:
				displayCars(cars, numberOfCars);
				break;
			case 5:
				break;
			default:
				cout << "Please select a valid option [From 1 to 5]. " << endl;
		}
	} while (carOption != 5); // Loop condition to go back to the main menu
}

// Function to add new customer.
void addCustomer(Customer customer[], int &numOfCustomers)
{
	
	// To check if the adding done successfully or not
	operationSuccess = false;
	
	// Declare a variable to store the gender before check if it is true
	char gender;
	
	// Declare variable to store the phone number before check if it is true
	string phoneNum, nationalID;
	
	//Title of the menu
	cout << "------------------ Add Customer ------------------" << endl;
	
	// Get the age of the customer from the birth of date
	int age = calculateAge();
	if (age < 0)
	{
		return;
	}
	else
	{
		if (age < 18)
		{
			cout << "The customer should be more than 18." << endl << endl;
			return;
		}
	}
	
	// Get the national ID of the customer
	cout << "Enter the national ID: ";
	cin >> nationalID;

	// Check if the input is number
	if(isNumber(nationalID) == false)
	{
		// If it is not number end the function and go back to the previous menu
		cout << "\nSorry, please enter a valid national ID\n" << endl;
		
		// Clear the input buffer
		cin.ignore();
		
		return;
	}
	
	// Check if the national ID is already exists
	if(isIDNew(nationalID, customer, numOfCustomers) == false)
	{
		// If it is already exists end the function and go back to the previous menu
		cout << "\nSorry, the national number is already exists.\n" << endl;
		
		// Clear the input buffer
		cin.ignore();
		
		return;
	}
	
	// Get the phone number of the customer
	cout << "Enter the phone number: ";
	cin >> phoneNum;

	// Check if the input is number
	if(isNumber(phoneNum) == false)
	{
		// If it is not number end the function and go back to the previous menu
		cout << "\nSorry, please enter a valid phone number\n" << endl;
		
		// Clear the input buffer
		cin.ignore();
		
		return;
	}
	
	// Check if the phone number is already exists
	if(isNew(phoneNum, customer, numOfCustomers) == false)
	{
		// If it is already exists end the function and go back to the previous menu
		cout << "\nSorry, the customer already exists.\n" << endl;
		
		// Clear the input buffer
		cin.ignore();
		
		return;
	}
	
	//If the national ID and phone number are valid and new, complete the adding process
	customer[numOfCustomers].nationalID = nationalID;
	customer[numOfCustomers].phoneNumber = phoneNum;
	
	// Get the customer name
	cout <<"Enter the full Name: ";
	cin.ignore(); // To clear the input buffer.
	getline(cin, customer[numOfCustomers].fullName);
	
	// Loop to be sure the gender is correct
	while(gender != 'M' || gender != 'F')
	{
		// Get the gender
		cout << "Choose the gender (M: for male and F: for Female): ";
		cin >> gender;
		
		// if the input in lowercase
		if(gender == 'm' || gender == 'f')
		{
			// Convert lowercase to uppercase
			customer[numOfCustomers].gender = toupper(gender);
			break;
		}
		else if (gender == 'M' || gender == 'F')
		{
			customer[numOfCustomers].gender = gender;
			break;
		}
		
		// If it is neither M nor F
		else
		{
			cout << "Wrong choice Please Enter F or M.\n" << endl;
		}
	}
	
	// Increment the number of the customers by one
	numOfCustomers++;
	
	// If the customer added successfully set the variable to true
	operationSuccess = true;
	
	// Write the data, after add new customer, into a file(CustomersData.txt)	
	writeNewCustomer(customer[numOfCustomers-1]);
	
	// Write the update into statistcal report file
	textUpdate = string("Added a New Customer [ " )  + customer[numOfCustomers-1].nationalID + string(" ] - New number of customers: ") + numToString(numOfCustomers);
	statisticalReport (textUpdate);
	
	//Success message
	cout << "Customer added successfully!\n" << endl;
}

// Function to Update the phone number of a customer.
void updateCustomer(Customer customer[], int numOfCustomers)
{
	// Check if there are customers or not
	if (numOfCustomers == 0)
	{
		cout << "Sorry ... there are no customers to update." << endl;
	}
	else
	{
		// Display the customers to the user
		displayCustomers(customer, numOfCustomers);
		
		// Declare a variabl to get the choice from the user
		int searchOption;
		
		cout << "----------- Update customer information -----------" << endl;
		cout << "1- Search by national ID." << endl;
		cout << "2- Search by phone number." << endl << endl;
	
		// Get the choice from the user
		cout << "Please enter your choice: ";
		inputInt(searchOption);
		
		// Search for the index of the customer
		int found = searchCustomer(searchOption, customer, numOfCustomers);
		
		// If the customer is found
		if (found >= 0)
		{
			// Show the result of the search
			cout << "------------------ Search Result ------------------" << endl << endl;
			cout << left << setw(15) <<"National ID: "<<setw(30) <<"Full Name: " << setw(25) <<"Phone Number: " << setw(5) << "Gender: " << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			cout << left << setw(15) <<customer[found].nationalID<< setw(30) <<customer[found].fullName << setw(27) << customer[found].phoneNumber << setw(5) << customer[found].gender << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			
			int updateOption;
			cout << "1- Update the national ID." << endl;
			cout << "2- Update the full name." << endl;
			cout << "3- Update the phone number." << endl;
			cout << "4- Update the gender." << endl << endl;
			
			// Get the choice from the user
			cout << "Please enter your choice: ";
			inputInt(updateOption);
			
			// Update the national ID
			if (updateOption == 1)
			{
				// Get the new National ID and replace the old one
				string newNationalID;
				cout << "Enter the new national ID: ";
				cin >> newNationalID;
				
				// Check if the input is number
				if(isNumber(newNationalID) == false)
				{
					// If it is not number end the function and go back to the previous menu
					cout << "\nSorry, please enter a valid national ID\n" << endl;
					return;
				}
				
				// Check if the national ID is already exists
				if(isIDNew(newNationalID, customer, numOfCustomers) == false)
				{
					// If it is already exists end the function and go back to the previous menu
					cout << "\nSorry, enter another national ID, the national ID is already exists.\n" << endl;
					return;
				}
				
				// Check if the user want to continue
				if (!sure())
				{
					return;
				}
				
				// if all conditions are true set the new national ID
				customer[found].nationalID = newNationalID;	
				
				// Write the update into statistcal report file
				textUpdate = string("[Update] ") + customer[found].fullName + string(" National ID has been changed To: " ) + customer[found].nationalID;
				statisticalReport (textUpdate);
				
				//Success message
				cout << endl << endl <<"The national ID has successfully updated." << endl;
			}
			
			// Update the full name
			else if (updateOption == 2)
			{
				string newFullName;
				cout << "Enter the new full name: ";
				cin.ignore();
				getline(cin, newFullName);
				// Check if the user want to continue 
				if (!sure())
				{
					return;
				}
				customer[found].fullName = newFullName;
				
				// Write the update into statistcal report file
				textUpdate = string("[Update] ") + customer[found].nationalID + string(" Full name has been changed To: " ) + customer[found].fullName;
				statisticalReport (textUpdate);
				
				//Success message
				cout << endl << endl <<"The full name has successfully updated." << endl;
				
			}
			
			// Update the phone number
			else if (updateOption == 3)
			{
				// Get the new phone number and replace the old one
				string newPhoneNumber;
				cout << "Enter the new phone number: ";
				cin >> newPhoneNumber;
				
				// Check if the input is number
				if(isNumber(newPhoneNumber) == false)
				{
					// If it is not number end the function and go back to the previous menu
					cout << "\nSorry, please enter a valid phone number\n" << endl;
					return;
				}
				
				// Check if the phone number is already exists
				if(isNew(newPhoneNumber, customer, numOfCustomers) == false)
				{
					// If it is already exists end the function and go back to the previous menu
					cout << "\nSorry, enter another phone number, the number phone is already exists.\n" << endl;
					return;
				}
				
				// Check if the user want to continue
				if (!sure())
				{
					return;
				}
				
				// if all conditions are true set the new phone number
				customer[found].phoneNumber = newPhoneNumber;
				
				// Write the update into statistcal report file
				textUpdate = string("[Update] ") + customer[found].fullName + string(" Phone number has been changed To: " ) + customer[found].phoneNumber;
				statisticalReport (textUpdate);
			
				//Success message
				cout << endl << endl <<"The phone number has successfully updated." << endl;
			}
			
			// Update the gender (*In wrong input cases)
			else if (updateOption == 4)
			{
				char newGender;
				// Loop to be sure the gender is correct
				while(newGender != 'M' || newGender != 'F')
				{
					// Get the gender

					cout << "Enter the new gender (M: for male and F: for Female): ";
					cin >> newGender;
					
					// Check if the user want to continue
					if (!sure())
					{
						return;
					}
					
					// if the input in lowercase
					if(newGender == 'm' || newGender == 'f')
					{
						// Convert lowercase to uppercase
						customer[found].gender = toupper(newGender);
						break;
					}
					else if (newGender == 'M' || newGender == 'F')
					{
						customer[found].gender = newGender;
						break;
					}
					
					// If it is neither M nor F
					else
					{
						cout << "Wrong choice Please Enter F or M.\n" << endl;
					}
				}
				
				// Write the update into statistcal report file
				textUpdate = string("[Update] ") + customer[found].fullName + string(" Gender has been changed To: " ) + customer[found].gender;
				statisticalReport (textUpdate);
				
				//Success message
				cout << endl << endl <<"The gender has successfully updated." << endl;
			}
			
			// Show the result of the update
			cout << "------------------ After update ------------------" << endl << endl;
			cout << left << setw(15) <<"National ID: "<<setw(30) <<"Full Name: " << setw(25) <<"Phone Number: " << setw(5) << "Gender: " << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			cout << left << setw(15) <<customer[found].nationalID<< setw(30) <<customer[found].fullName << setw(27) << customer[found].phoneNumber << setw(5) << customer[found].gender << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			
			// Write the customers data, after the update, into a file(CustomersData.txt)
			writeCustomersData(customer, numOfCustomers);
			
		}
		
		// If the customer is not found
		else
		{
			cout << "The customer does not exist .. Please try again. " << endl;	
		}	
	}
}

// Function to search for a customer
int searchCustomer(int searchOption, Customer customer[], int numOfCustomers)
{
	// Declare a variable to store the search key
	string value;
	
	do
	{
		// Search by national ID
		if (searchOption == 1)
		{
			// Get the national ID from the user
			cout << "Enter the national ID of the customer: ";
			cin >> value;
			
			// Loop through the array of customers to check if the customer is exist
			for (int i =0; i<numOfCustomers; i++)
			{
				// If the customer is found
				if (value == customer[i].nationalID)
				{ 
					// return the index
					return i;
				}
			}
		}	
		
		// Search by phone number
		else if (searchOption == 2)
		{
			// Get the phone number from the user
			cout << "Enter the phone number of the customer: ";
			cin >> value;
			
			// Loop through the array of customers to check if the customer is exist
			for (int i =0; i<numOfCustomers; i++)
			{
				// If the customer is found
				if (value == customer[i].phoneNumber)
				{ 
					// return the index
					return i;
				}
			}
		}
		else
		{
			cout << "Please enter a valid number [1 or 2]: ";
			inputInt(searchOption);
		}	
	} while (searchOption != 1 || searchOption != 2);

	
	// If the customer is not found 
	return -1;
}

// Function to delete a customer
void deleteCustomer(Customer customer[], int &numOfCustomers)
{
	// Initialize index to -1
	int index = -1;
		
	//declare the phone number
	string phoneNumber;
	
	//Check if there are customers or not
	if (numOfCustomers == 0)
	{
		cout << "Sorry there are no customers to delete." << endl;
	}
	else 
	{
		
		// Display all customers to the user
		displayCustomers(customer, numOfCustomers);
		
		// Declare a variabl to get the choice from the user
		int searchOption;
			
		cout << "----------- Delete Customer -----------" << endl;
		cout << "1- Search by national ID." << endl;
		cout << "2- Search by phone number." << endl << endl;
		
		// Get the choice from the user
		cout << "Please enter your choice: ";
		inputInt(searchOption);
		
		// Search for the index of the customer
		index = searchCustomer(searchOption, customer, numOfCustomers);
		
		// If the customer is found
		if (index >= 0)
    	{
    		// Check if the user want to continue
			if (!sure())
			{
				return;
			}
			
			// Store the name of the deleted customer to display it
        	string deletedName = customer[index].fullName; 
        	
        	// Delete the customer
            for (int i = index; i < numOfCustomers-1; i++)
            {
            	customer[i]	= customer[i+1];
			}
			
			// Decrement the number of customers by one
			numOfCustomers--;
			
    		// Write the customers data, after the delete, into a file(CustomersData.txt)
    		writeCustomersData(customer, numOfCustomers);
    		
    		// Write the update into statistcal report file
			textUpdate = string("[Delete] ") + string("The customer [ " )  + deletedName + string(" ] has been deleted - ") + string("New number of customers: ")  + numToString(numOfCustomers);
			statisticalReport (textUpdate);
	
			// Success message
    		cout<< deletedName << " Has deleted successfully." << endl;
		}
		
		// If the customer is not found
		else
		{
			cout << "Wrong phone number, The customer does not exist .. Please try again. " << endl;
		}
	} 
}

// Function to display all customers
void displayCustomers(Customer customer[], int numOfCustomers)
{
	//Check if there are customers or not
	if (numOfCustomers == 0)
	{
		cout << "Sorry ... there are no customers to display." << endl;
	}
	else
	{
		// Print the labels 
		cout << endl;
		cout << left << setw(15) << "National ID: " << setw(30) <<"Full Name: " << setw(25) <<"Phone Number: " << setw(5) << "Gender: " << endl;
		cout << "--------------------------------------------------------------------------" << endl;
		
		// Loop through the array of customers and print them
		for (int i = 0; i < numOfCustomers; i++)
		{
			cout << left << setw(15) << customer[i].nationalID <<setw(30) <<customer[i].fullName << setw(27) << customer[i].phoneNumber << setw(5) << customer[i].gender << endl;
		}

		cout << "--------------------------------------------------------------------------" << endl << endl;
	}
}

// Function to add new car.
void addCar(Car cars[] , int &numberOfCars)
{
	// Declare variables
	int vehicleTypeOption;
	string serialNumber;
	
	//Title
	cout << "------------------ Add Car ------------------" << endl;
	
	//Get the serialNumber from the user 
	cout<<"Enter the car Serial Number: ";
	cin>>serialNumber;
	
	// Check if the input is a number
	if(isNumber(serialNumber) == false)
	{
		// If it is not number end the function and go back to the previous menu
		cout << "\nSorry, please enter a valid serialNumber (Only digits)\n" << endl;
		
		// Clear the input buffer
		cin.ignore();
		
		return;
	}
	
	// Check if the serialNumber is already exists
	if(isNew(serialNumber, cars, numberOfCars) == false)
	{
		// If it is already exists end the function and go back to the previous menu
		cout << "\nSorry, the car already exists.\n" << endl;
		
		// Clear the input buffer
		cin.ignore();
		
		return;
	}
	
	//If the serialNumber is valid and new, complete the adding process
	cars[numberOfCars].serialNumber = serialNumber;
	
	// Get the name of the car from the user
	cout<<"Enter the car name: "<<endl;
	cin.ignore();
	getline(cin, cars[numberOfCars].carName);
	
	// Get the year of the car from the user
	string carYear;
	cout << "Enter the year of the car: ";
	cin >> carYear;
	if (isNumber(carYear) == false)
	{
	    cout << "Please enter a valid car year" << endl << endl;
	    return;
	}
	cars[numberOfCars].carYear = carYear;
	
	// Get the daily price from the user
	cout<<"Enter the car daily price (SR): ";
	cin>>cars[numberOfCars].dailyPrice;
	
	// Check if the input is an integer
	while(cin.fail())
	{
		// Continue to get input until get a number
		cout << "Please enter a valid number" <<endl;
		cout << "Enter the car daily price (SR): ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> cars[numberOfCars].dailyPrice;
	}	
	
	// Loop to be sure the user choose a correct vehicle type 
	do
	{
		// Display the options 
		cout << "--------Vehicle Type:-------- " << endl;
		cout << "1) Sedan." << endl;
		cout << "2) SUV." << endl;
		cout << "3) Pickup." << endl;
		
		// Get the choice from the user 
		cout<<"Choose the car type [From 1 to 3]: ";
		cin>>vehicleTypeOption;
		
		// Check if the input is number or not
		while(cin.fail())
		{
			// Continue to get input until get an int
			cout << "Please select a valid option [From 1 to ]\n" << endl;
			cout << "Please enter your choice: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> vehicleTypeOption;
		}	
		
		// Check for the choice
		if(vehicleTypeOption == 1)
		{
			cars[numberOfCars].vehicleType = "Sedan"; 
		}
		else if (vehicleTypeOption == 2)
		{
			cars[numberOfCars].vehicleType = "SUV";
		}
		else if (vehicleTypeOption == 3)
		{
			cars[numberOfCars].vehicleType = "Pickup";
		}
		else
		{
			cout << endl << "Please Enter a valid option " << endl << endl;
		}
		
	} while (vehicleTypeOption <= 0 || vehicleTypeOption > 3 ); // Condition of the loop

	// Increment the number of cars by one
	numberOfCars++;
	
	// Write the cars data, after add new car, into a file(CarsData.txt)
	writeNewCar(cars[numberOfCars-1]);
	
	// Write the update into statistcal report file
	textUpdate = string("Added a New car [ " )  + cars[numberOfCars - 1].carName + string(" - ") + cars[numberOfCars - 1].carYear + string(" ] - New number of cars: ") + numToString(numberOfCars);
	statisticalReport (textUpdate);
				
	// Success message
	cout << "The Car has been added successfully!\n" << endl;
}

// Function to search for a car
int searchCar(string value,Car cars[], int numberOfCars)
{
	// Loop through the array of cars and search for the index
	for (int i =0; i<numberOfCars; i++)
	{
		if (value == cars[i].serialNumber)
		{ 
			// If the car is found return the index
			return i;
		}
	}
	
	// If the car is not found return -1 
	return -1;
}

// Function to update a car
void updateCar(Car cars[], int numberOfCars)
{
	// Check if there are no cars
	if (numberOfCars == 0)
	{
	cout << "Sorry there are no cars to update." << endl;
	}
	
	// If there are cars
	else 
	{
		// Display all cars to the user
		displayCars(cars, numberOfCars);
		
		// Get the serialNumber of the car
		string value;
		cout << "Enter the serialNumber of the car: ";
		cin >> value;
		
		// Search for the index of the car
		int found = searchCar(value, cars, numberOfCars);
		
		// If found >= 0 it means the car is found  
		if (found >= 0)
		{
			// Display the result of the search
			cout << "------------------ Search Result ------------------" << endl << endl;
			cout << left << setw(30) <<"Car Name:" << setw(15) << "Year:" << setw(20) <<"Vehicle Type:" << setw(20) << "Daily Price:" << setw(10) <<"SerialNumber: "<< endl;
			cout << "------------------------------------------------------------------------------------" << endl;
			cout << left << setw(30) <<cars[found].carName << setw(15) << cars[found].carYear << setw(20) << cars[found].vehicleType << setw(20) << cars[found].dailyPrice << setw(10) <<cars[found].serialNumber<< endl;
			cout << "------------------------------------------------------------------------------------" << endl;
			
			// Update options
			int updateOption;
			cout << "1- Update the car name." << endl;
			cout << "2- Update the car year." << endl;
			cout << "3- Update the vehicle type." << endl;
			cout << "4- Update the daily price." << endl;
			cout << "5- Update the serialNumber." << endl << endl;
			
			// Get the choice from the user
			cout << "Please enter your choice: ";
			inputInt(updateOption);
			
			// Update Car Name
			if(updateOption == 1)
			{
				string newCarName;
				cout << "Enter the new car name: ";
				cin.ignore();
				getline(cin, newCarName);
				// Check if the user want to continue
				if (!sure())
				{
					return;
				}
				
				cars[found].carName = newCarName;
				
				// Write the update into statistcal report file
				textUpdate = string("[Update] ") + cars[found].serialNumber + string(" car name has been changed To: " ) + cars[found].carName;
				statisticalReport (textUpdate);
				
				//Success message
				cout << endl << endl <<"The car name has successfully updated." << endl;
			}
			// Update the Car Year
			else if (updateOption == 2)
			{
				// Get the year of the car from the user
				string newCarYear;
				cout << "Enter the new year of the car: ";
				cin >> newCarYear;
				if (isNumber(newCarYear) == false)
				{
				    cout << "Please enter a valid car year" << endl << endl;
				    return;
				}
				// Check if the user want to continue
				if (!sure())
				{
					return;
				}
				
				cars[found].carYear = newCarYear;
				
				// Write the update into statistcal report file
				textUpdate = string("[Update] ") + cars[found].serialNumber + string(" car year has been changed To: " ) + cars[found].carYear;
				statisticalReport (textUpdate);
				
				//Success message
				cout << endl << endl <<"The car year has successfully updated." << endl;
			}
			// Update the vehicle type
			else if (updateOption == 3)
			{
				int vehicleTypeOption;
				// Loop to be sure the user choose a correct vehicle type 
				do
				{
					// Display the options 
					cout << "--------Vehicle Type:-------- " << endl;
					cout << "1) Sedan." << endl;
					cout << "2) SUV." << endl;
					cout << "3) Pickup." << endl;
					
					// Get the choice from the user 
					cout<<"Choose the car type [From 1 to 3]: ";
					inputInt(vehicleTypeOption);
					
					// Check if the user want to continue
					if (!sure())
					{
						return;
					}
				
					// Check for the choice
					if(vehicleTypeOption == 1)
					{
						cars[found].vehicleType = "Sedan"; 
					}
					else if (vehicleTypeOption == 2)
					{
						cars[found].vehicleType = "SUV";
					}
					else if (vehicleTypeOption == 3)
					{
						cars[found].vehicleType = "Pickup";
					}
					else
					{
						cout << endl << "Please Enter a valid option " << endl << endl;
					}
					
				} while (vehicleTypeOption <= 0 || vehicleTypeOption > 3 ); // Condition of the loop
				
				// Write the update into statistcal report file
				textUpdate = string("[Update] ") + cars[found].serialNumber + string(" vehicle type has been changed To: " ) + cars[found].vehicleType;
				statisticalReport (textUpdate);
				
				//Success message
				cout << endl << endl <<"The vehicle type has successfully updated." << endl;
			}
			
			else if (updateOption == 4)
			{
				// Get the daily price
				double newPrice;
				cout << "Enter the new daily price: ";
				inputDouble(newPrice);
				
				// Check if the user want to continue
				if (!sure())
				{
					return;
				}
				
				// if all conditions are true set the new phone number
				cars[found].dailyPrice = newPrice;
				
				// Write the update into statistcal report file
				textUpdate = string("[Update] ") + cars[found].serialNumber + string(" daily price has been changed To: " ) + numToString(cars[found].dailyPrice);
				statisticalReport (textUpdate);
				
				// Success message 
				cout << endl << endl <<"The daily price has successfully changed." << endl;
			}
			
			else if (updateOption == 5)
			{
				// Update the serial number
				string newSerialNumber;
				//Get the serialNumber from the user 
				cout << "Enter the new car serialNumber: ";
				cin >> newSerialNumber;
				
				// Check if the input is a number
				if(isNumber(newSerialNumber) == false)
				{
					// If it is not number end the function and go back to the previous menu
					cout << "\nSorry, please enter a valid serialNumber (Only digits)\n" << endl;
					
					// Clear the input buffer
					cin.ignore();
					
					return;
				}
				
				// Check if the serialNumber is already exists
				if(isNew(newSerialNumber, cars, numberOfCars) == false)
				{
					// If it is already exists end the function and go back to the previous menu
					cout << "\nSorry, the car already exists.\n" << endl;
					
					// Clear the input buffer
					cin.ignore();
					
					return;
				}
				
				// Check if the user want to continue
				if (!sure())
				{
					return;
				}
				
				//If the serialNumber is valid and new, complete the adding process
				cars[found].serialNumber = newSerialNumber;
				
				// Write the update into statistcal report file
				textUpdate = string("[Update] ") + cars[found].carName + string(" serial number has been changed To: " ) + cars[found].serialNumber;
				statisticalReport (textUpdate);
			}
		
			// Write the cars data, after update the car, into a file(CarsData.txt)
			writeCarsData(cars, numberOfCars);
			
			// Show the result of the update
			cout << "------------------ After update ------------------" << endl << endl;
			cout << left << setw(30) <<"Car Name:" << setw(15) << "Year:" << setw(20) <<"Vehicle Type:" << setw(20) << "Daily Price:" << setw(10) <<"serialNumber "<< endl;
			cout << "--------------------------------------------------------------------------------------------------------" << endl;
			cout << left << setw(30) <<cars[found].carName << setw(15) << cars[found].carYear << setw(20) << cars[found].vehicleType << setw(20) << cars[found].dailyPrice << setw(10) << cars[found].serialNumber<< endl;
			cout << "--------------------------------------------------------------------------------------------------------" << endl;
				
		}
		
		// If found is less than 0 it means the car is not found
		else
		{
			cout << "Wrong serialNumber number, The car does not exist. " << endl;	
		}
	}
}

// Function to delete a car
void deleteCar(Car cars[] ,int &numberOfCars)
{
	// Check if there are no cars
	if (numberOfCars == 0)
	{
	cout << "Sorry there are no cars to delete." << endl;
	}
	
	// If there are cars
	else 
	{
		// Declare variables
		int index = -1;
		string serialNumber;
	
		// Display all cars to the user
		displayCars(cars, numberOfCars);
		
		// Get the serialNumber of the car
		cout << "Enter the serialNumber of the car: ";
		cin >> serialNumber;
		
		// Search for the car by the serialNumber
		index = searchCar(serialNumber, cars, numberOfCars);
		
		// If found >= 0 it means the car is found  
		if (index >= 0)
	    {
	        // Check if the user want to continue
			if (!sure())
			{
				return;
			}
			// Store the deleted car name and serialNumber to print it to the user
			string deletedCar = cars[index].carName; 
	        string deletedserialNumber = cars[index].serialNumber;
			//  Delete the car
			for (int i = index; i < numberOfCars-1; i++)
	    	{
	            cars[i]	= cars[i+1];
			}
			
			// Decrement the number of cars by one
			numberOfCars--;
			
			// Write the cars data, after the delete, into a file(CarsData.txt)
			writeCarsData(cars, numberOfCars);
			
			// Write the update into statistcal report file
			textUpdate = string("The car [ " )  + deletedCar + string(" - serialNumber: ") + deletedserialNumber + string(" ] has been deleted - ") + string("New number of cars: ")  + numToString(numberOfCars);
			statisticalReport (textUpdate);
			
			// Success message
	       	cout<< deletedCar << " Has deleted successfully." << endl;  
		}
		
		// If the car is not found
		else
		{
			cout << "Wrong serialNumber number, The car does not exist .. Please try again. " << endl;
		}
	}
}

// Function to display all cars
void displayCars(Car car[], int numberOfCars)
{
	//Check if there are no cars
	if (numberOfCars == 0)
	{
		cout << "Sorry there are no cars to display." << endl;
	}
	
	// If there are cars
	else 
	{
		// Print the labels 
		cout << endl;
		cout << left << setw(30) <<"Car Name:" << setw(15) << "Year:" << setw(20) <<"Vehicle Type:" << setw(20) << "Daily Price:" << setw(10) <<"Serial Number: "<< endl;
		cout << "--------------------------------------------------------------------------------------------------------" << endl;
		
		// Loop through the array of cars and print them
		for (int i = 0; i < numberOfCars; i++)
		{
			cout << left << setw(30) <<car[i].carName << setw(15) << car[i].carYear << setw(20) << car[i].vehicleType << setw(20) << car[i].dailyPrice << setw(10) <<car[i].serialNumber<< endl;
		}
		cout << "--------------------------------------------------------------------------------------------------------" << endl;
	}
}

// Function to display Rent a car menu
void billsMenu(Customer customer[], Car cars[], int &numberOfCustomers, Bill bills[], int &numberOfBills, int numberOfCars)
{
	// Variable to store the user's choice
	int billOption;
	
	// Loop of the bills menu
	do
	{
		cout << endl;
		cout << "------------------ Bills menu ------------------" << endl;
		cout << "1) Create new bill." << endl;
		cout << "2) Remove bill." << endl;
		cout << "3) Sort the bills by price." << endl;
		cout << "4) Display bills." << endl;
		cout << "5) Back to main menu." << endl;
		cout << endl;
		
		// Get the user choice
		cout << "Please enter your choice: ";
		cin>>billOption;
		
		// Check if the input is number or not
		while(cin.fail())
		{
			// Continue to get input until get an int
			cout << "Please select a valid option [From 1 to 5]\n" << endl;
			cout << "Please enter your choice: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> billOption;
		}
		
		// Switch statement for bills menu
		switch (billOption)
		{
			case 1: 
				createBill(customer, cars, numberOfCustomers, bills, numberOfBills, numberOfCars);
				break;
			case 2:
				deleteBill(bills , numberOfBills);
				break;
			case 3:
				sortBills(bills , numberOfBills);
				break;
			case 4:
				displayBills(bills , numberOfBills);
				break;
			case 5:
				break;
			default:
				cout << "Please select a valid option [From 1 to 5]. " << endl;
		}
	} while (billOption != 5); // Loop condition to go back to the main menu
}

//function to rent a car for exist custumer
void existCustumer(int numberOfCustomers, int numberOfCars ,Customer customers[], Car cars[] , Bill bills[], int &numberOfBills )
{

	// Initialize the total price of the bill to 0
	bills[numberOfBills].totalPrice = 0;
	
	// Declare variables
	int days =0;
	string value, phoneNumber;
	
	// Display all customers to the user	
	displayCustomers(customers,numberOfCustomers);
	
	// Declare a variabl to get the choice from the user
	int searchOption;
	
	cout << "----------- Rent a car for an exist customer -----------" << endl;
	cout << "1- Search by national ID." << endl;
	cout << "2- Search by phone number." << endl << endl;

	// Get the choice from the user
	cout << "Please enter your choice: ";
	inputInt(searchOption);
	
	// Search for the index of the requested customer and store it
	int found = searchCustomer(searchOption, customers, numberOfCustomers);
	
	// If found >= that means the customers is exist 
	if (found >= 0)
	{
		// Set the requested customer as the renter in the bill 
		bills[numberOfBills].renter = customers[found];
		
		// Complete the rental proccess
		rentTheCar(cars, numberOfCars, bills, numberOfBills);
	}
	
	// If found less than 0 that means the customers is not exist 
	else
	{
		cout << "Wrong phone number, The customer does not exist .. Please try again. " << endl;
	}	
}

//function to rent a car for new custumer
void newCustomerRent(int &numberOfCustomers, int numberOfCars ,Customer customers[], Car cars[] , Bill bills[], int &numberOfBills)
{
	// Initialize the total price of the bill to 0
	bills[numberOfBills].totalPrice = 0;
	
	// Declare variables
	int days =0;
	int newCustomerIndex;
	string value, phoneNumber;
	
	// Add new customer
	addCustomer(customers, numberOfCustomers);

	// Check if the customer not added? end the function and go back to the main menu
	if (operationSuccess == false)
	{
		return;
	}
	
	// Initialize newCustomerIndex
	newCustomerIndex = numberOfCustomers - 1;
	
	// Set the new customer as the renter in the bill 
	bills[numberOfBills].renter = customers[newCustomerIndex]; 
	
	// Complete the rental proccess
	rentTheCar(cars, numberOfCars, bills, numberOfBills);
}

// Function to Create new bill
void createBill(Customer customer[], Car cars[], int &numberOfCustomers, Bill bills[], int &numberOfBills, int numberOfCars)
{
	// Check if there are no cars
	if (numberOfCars == 0)
	{
		cout << "\nSorry .. there are no cars\n" << "Please enter a car first" << endl;
	}
	
	// Check if there are cars
	else
	{
		// Declare a variable to store the user's choice
		int customerOption;
		
		// Display the options to the user
		do
		{
			cout << "------------------ Create new bill ------------------" << endl;
			cout << "1) New customer." << endl;
			cout << "2) Exist customer." << endl;
			cout << "3) Go back." << endl;
			cout << endl;
			
			// Get the user choice
			cout << "Please enter your choice: ";
			cin >> customerOption;
			
			// Check if the input is number or not
			while(cin.fail())
			{
				// Continue to get input until get an int
				cout << "Please select a valid option [From 1 to 3]\n" << endl;
				cout << "Please enter your choice: ";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin >> customerOption;
			}	
			
			// Switch statement for create bill menu
			switch (customerOption)
			{
				case 1:
					newCustomerRent(numberOfCustomers,  numberOfCars, customer, cars, bills, numberOfBills);
					break;
				case 2:
				{
					if (numberOfCustomers == 0)
					{
						cout << "\nSorry there are no customers." << endl;
						cout << "Please add a customer first to rent a car. \n" << endl;
					}
					else
					{
						existCustumer(numberOfCustomers, numberOfCars, customer, cars, bills, numberOfBills );	
					}
					break;	
				}
				case 3:
					break;
				default:
					cout << "Please select a valid option [From 1 to 3]."<< endl << endl;	
			}	
		} while(customerOption != 3); // Loop condition to go back to the bills menu

	}
}

//Function to delete a bill
void deleteBill(Bill bills[] ,int &numberOfBills)
{
	//Check if there are bills or not
	if (numberOfBills == 0)
	{
	cout << "Sorry there are no bills to delete." << endl;
	}
	
	else 
	{
		// Display all bills to the user
		displayBills(bills , numberOfBills);
		
		// Get the index of the bill - which is the ID -
		int index;
		cout << "\nEnter the ID of the bill: ";
		cin >> index;
		
		// Check if the ID is correct 
		if (index < numberOfBills && index >= 0)
	    {
	        // Store the data of the deleted bill to print it to the user
			string deletedBill = bills[index].renter.fullName; 
	        string deletedserialNumber = bills[index].rentedCar.serialNumber;
	        string deletedNumberPhone = bills[index].renter.phoneNumber;
	        
	        // Delete the bill
			for (int i = index; i < numberOfBills-1; i++)
	    	{
	            bills[i] = bills[i+1];
			}
			
			// Decrement the number of bills by one
			numberOfBills--;
			
			// Write the bills data, after the delete, into a file(BillsData.txt)   
			writeBillsData(bills, numberOfBills);
			
			// Write the update into statistcal report file
			textUpdate = string("Deleted the bill \nserialNumber Car: " )  + deletedserialNumber + string(" For customer: ") + deletedNumberPhone + string(" - New number of bills: ") + numToString(numberOfBills);
			statisticalReport (textUpdate);
			
			// Success message
	       	cout<< "The bill of the customer: " << deletedBill << " Has been deleted successfully." << endl;
		}
	
		// If the ID is not correct
		else
		{
			cout << "Sorry, please enter a valid ID" << endl;
		}
	}
}

// Function to display all bills
void displayBills(Bill bills[], int numberOfBills)
{
	// Check if there are no bills
	if (numberOfBills == 0)
	{
		cout << "Sorry there are no bills to display." << endl;
	}
	
	// If there are bills
	else 
	{
		// Print the labels
		cout << endl;
		cout << left << setw(12) <<"Bill ID:" << setw(30) <<"The renter:" << setw(30) << "The car:" << setw(17) <<"Daily Price: " << setw(12) << "Days:" << setw(15) <<"Total price: "<< endl;
		cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
		
		// Loop through the array of bills and print them
		for (int i = 0; i < numberOfBills; i++)
		{
			cout << left << setw(12) << i << setw(30) <<bills[i].renter.fullName << setw(30) << bills[i].rentedCar.carName + " - " + bills[i].rentedCar.carYear << setw(17) << bills[i].rentedCar.dailyPrice << setw(12) << bills[i].numberOfDays << setw(15) <<bills[i].totalPrice<< endl;
		}
		cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	}
}

// Function to sort the bills descending by the total price  
void sortBills(Bill bills[], int numberOfBills)
{
    // Check if the user want to continue or not
	char check;
	cout << "\nAre you sure you want to sort the bills descending by the total price?[Y/N]: ";
    cin >> check;
    
    // If the user choose to continue
    if (check == 'y' || check == 'Y')
    {
    	// initialize orderd to false
	    bool ordered=false;

		// Create a variable of struct Bill
	    Bill temp;
	    
	    // Check if the number of bills less than 2
	    if (numberOfBills < 2)
	    {
	    	cout<< "\nSorry there are no enough bills to sort." <<endl << endl;
		}
		
		// If the number of bills 2 or more
		else
	    {
	        // Loop through the array of bills to sort them
			for(int i = 0; i < numberOfBills-1 && ordered==false; i++) 
	     	{	    
				// Initialize ordered to true
				ordered=true;
				
	            for(int j = 0; j < numberOfBills-1; j++)
	            {
	            	// Sort the array if is is not sorted 
					if(bills[j+1].totalPrice > bills[j].totalPrice)
	        		{       
						// Initialize ordered to false
						ordered=false;
						temp = bills[j];
		            	bills[j] = bills[j+1];
		            	bills[j+1] = temp;
		      		}
				}
	      	}
	
			// Write the bills data, after the sorting, into the file (BillsData.txt)
			writeBillsData(bills, numberOfBills);
			
			// Write the update into statistcal report file
			textUpdate = "Bills has been sorted";
			statisticalReport (textUpdate);
			
			// Success message
	    	cout<<"\nBills have been successfully sorted" <<endl << endl;
	    	
	    }	
	}
	
	// If the user choose no, end the function
	else if (check == 'n' || check == 'N')
	{ 
		return;
	}
	
	// If the user enter anything else
	else
	{
		cout << "Please select a valid option [Y/N]."<< endl << endl;	
	}
}

// Function to display generate reports menu.
void displayReportsMenu(Customer customer[], Car cars[], Bill bills[], int numberOfCustomers, int numberOfCars,  int numberOfBills)
{	
	// Declare a variable to store the user's choice
	int reportsOption;
	
	// Loop of the reports menu
	do
	{
		cout << endl;
		cout << "------------------ Generate Reports ------------------" << endl;
		cout << "1) Generate bills report." << endl;
		cout << "2) Generate customers report." << endl;
		cout << "3) Generate cars report." << endl;
		cout << "4) Back to main menu." << endl;
		cout << endl;
		
		// Get the user choice
		cout << "Please enter your choice: ";
		cin >> reportsOption;
		
		// Check if the input is number or not
		while(cin.fail())
		{
			// Continue to get input until get an int
			cout << "Please select a valid option [From 1 to 4]\n" << endl;
			cout << "Please enter your choice: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> reportsOption;
		}
		
		// Switch statement for reports menu
		switch (reportsOption)
		{
			case 1: 
				billsReport(bills , numberOfBills);
				break;
			case 2:
				customersReport(customer, numberOfCustomers);
				break;
			case 3:
				carsReport(cars, numberOfCars);
				break;
			case 4:
				break;
			default:
				cout << "Please select a valid option [From 1 to 4]. " << endl;
		}
	} while (reportsOption != 4); // Loop condition to go back to the main menu
}


// Function generate a report of customers to the file (Customers_Report.txt)
void customersReport(Customer customer[], int numberOfCustomers)
{
	// If there are no customers
	if (numberOfCustomers == 0)
	{
		cout << "Sorry there are no customers." << endl;
	}
	
	// If there are customers
	else
	{
		// Declare stream variable
		ofstream outFile;
		
		// Declare variables to store the number of males and females
		double malesNum = 0;
		double femalesNum = 0;
		
		// Open the file 
		outFile.open("Reports/Customers_Report.txt", ios::out);
		
		// Check if the file is open
		if(outFile.is_open())
		{
			// Write into the file "Customers_Report.txt"	
			outFile << "---------------------------- Customers Report ----------------------------" << endl << endl;
			outFile << "Report generated in: " << getDateAndTime();
			outFile << "Number of customers: " << numberOfCustomers << endl;
			
			// Loop through the customers array to count the number of males and females	
			for (int i = 0; i < numberOfCustomers; i++)
			{
				if (customer[i].gender == 'M')
				{
					malesNum++;
				}
				else if (customer[i].gender == 'F')
				{
					femalesNum++;
				}
			}
			
			// Write the number of males and females to the file
			outFile << "Percent of males: " << setprecision(4) <<((malesNum/numberOfCustomers) * 100) << "%"<< endl;
			outFile << "Percent of females: " << setprecision(4) <<((femalesNum/numberOfCustomers) * 100) << "%" << endl << endl;

				
			// Write the labels	
			outFile << left << setw(17) <<"National ID: "<<setw(30) <<"Full Name: " << setw(25) <<"Phone Number: " << setw(5) << "Gender: " << endl;
			outFile << "------------------------------------------------------------------------------------" << endl;
			
			// Loop through the customers array and write them	
			for (int i = 0; i < numberOfCustomers; i++)
			{
				outFile << left << setw(17) << customer[i].nationalID << setw(30) <<customer[i].fullName << setw(27) << customer[i].phoneNumber << setw(5) << customer[i].gender << endl;
			}
			outFile << "------------------------------------------------------------------------------------" << endl << endl;
			
			// Success message
			cout << endl << endl;
			cout << "The report has saved successfully in Reports folder!\n" << endl;
		}
		
		// If the file is not opened
		else
		{
			cout << "Sorry File did not open.\n" << endl;
		}
		
		// Close the file
		outFile.close();
	}
}

// Function generate a report of cars to the file (Cars_Report.txt)
void carsReport(Car car[], int numberOfCars)
{
	// If there are no cars
	if (numberOfCars == 0)
	{
		cout << "Sorry there are no cars." << endl;
	}
	
	// If there are cars
	else
	{
		// Declare stream variable
		ofstream outFile;
		
		// Open the file
		outFile.open("Reports/Cars_Report.txt", ios::out);
		
		// Check if the file is open
		if(outFile.is_open())
		{
			// Write into the file "Cars_Report.txt"
			outFile << "---------------------------- Cars Report ----------------------------" << endl << endl;
			outFile << "Report generated in: " << getDateAndTime();
			outFile << "Number of cars: " << numberOfCars << endl << endl;
			
			// Write the labels 		
			outFile << left << setw(30) <<"Car Name:" << setw(15) << "Year:" << setw(20) <<"Vehicle Type:" << setw(20) << "Daily Price:" << setw(10) <<"serialNumber "<< endl;
			outFile << "------------------------------------------------------------------------------------------------------------------" << endl;
			
			// Loop through the cars array and write them	
			for (int i = 0; i < numberOfCars; i++)
			{
				outFile << left << setw(30) <<car[i].carName << setw(15) << car[i].carYear << setw(20) << car[i].vehicleType << setw(20) << car[i].dailyPrice << setw(10) <<car[i].serialNumber<< endl;
			}
			outFile << "------------------------------------------------------------------------------------------------------------------" << endl;
			
			// Success message
			cout << endl << endl;
			cout << "The report has saved successfully in Reports folder!\n" << endl;
		}
		
		// If the file is not opened
		else
		{
			cout << "Sorry File did not open.\n" << endl;
		}
		
		// Close the file
		outFile.close();
	}
}

// Function generate a report of bills to the file (Bills_Report.txt)
void billsReport(Bill bills[] ,int numberOfBills)
{
	// If there are no bills 
	if (numberOfBills == 0)
	{
		cout << "Sorry there are no bills." << endl;
	}
	
	// If there are bills
	else
	{
		// Declare stream variable
		ofstream outFile;
		
		// Declare a variable to calculate the total sales
		double totalSales = 0;
		
		// Open the file
		outFile.open("Reports/Bills_Report.txt", ios::out);
		
		// Check if the file is open
		if(outFile.is_open())
		{
			// Write into the file "Bills_Report.txt"
			outFile << "---------------------------- Bills Report ----------------------------" << endl << endl;
			outFile << "Report generated in: " << getDateAndTime();
			outFile << "Number of Bills: " << numberOfBills << endl;
			
			// Loop through the bills array to calculate the total sales
			for (int i = 0; i < numberOfBills; i++)
			{
				totalSales = totalSales + bills[i].totalPrice;
			}
			
			// Write the total sales after the calculations
			outFile << "Total sales: " << totalSales << endl << endl;
			
			// Write the labels
			outFile << left << setw(12) <<"Bill ID:" << setw(30) <<"The renter:" << setw(30) << "The car:" << setw(17) <<"Daily Price: " << setw(12) << "Days:" << setw(15) <<"Total price: "<< endl;
			outFile << "-------------------------------------------------------------------------------------------------------------------" << endl;
			
			// Loop through the bills array and write them	
			for (int i = 0; i < numberOfBills; i++)
			{
				outFile << left << setw(12) << i << setw(30) <<bills[i].renter.fullName << setw(30) << bills[i].rentedCar.carName + " - " + bills[i].rentedCar.carYear << setw(17) << bills[i].rentedCar.dailyPrice << setw(12) << bills[i].numberOfDays << setw(15) <<bills[i].totalPrice<< endl;
			}
			outFile << "-------------------------------------------------------------------------------------------------------------------" << endl;
			
			// Success message
			cout << endl << endl;
			cout << "The report has saved successfully in Reports folder!\n" << endl;
		}
		
		// If the file is not opened
		else
		{
			cout << "Sorry File did not open.\n" << endl;
		}
		
		// Close the file
		outFile.close();
	}
}


// Function to read Data (Customers, Cars, Bills)
void readData(Customer customer[], int &numberOfCustomers, Car cars[], int &numberOfCars, Bill bills[], int &numberOfBills)
{
	// Declare stream variables
	ifstream customersIn;
	ifstream carsIn;
	ifstream billsIn;
	cout << "\n";
	
	// --- Read customers data ---
	
	// open the file
	customersIn.open("Data/CustomersData.txt", ios::in);

	// Check if the file is open
	if (customersIn.is_open())
	{
		// Loop through the file until it reaches the end of the file
		while(!customersIn.eof())
		{
			// Read the data from the file "CustomersData.txt"
			customersIn.ignore(INT_MAX, ':');
			customersIn.ignore();
			customersIn >> customer[numberOfCustomers].nationalID;
			customersIn.ignore(12);
			getline(customersIn, customer[numberOfCustomers].fullName);
			customersIn.ignore(14);
			customersIn >> customer[numberOfCustomers].phoneNumber;
			customersIn.ignore(8);
			customersIn >> customer[numberOfCustomers].gender;
			
			numberOfCustomers++;
		}
		numberOfCustomers--;
		
		// Display the number of imported customers
		cout << "------- [ " << numberOfCustomers <<" ]"<< " Customers imported successfully! -------" << endl;
		
		// Close the file
		customersIn.close();
	}
	
	// If the file is not opened
	else
	{
		cout << "No customers imported, please add customers (from customers menu) to save them for the next time." << endl;
	}
	
	// --- Read cars data ---
	
	// Open the file
	carsIn.open("Data/CarsData.txt", ios::in);
	
	// Check if the file is open
	if (carsIn.is_open())
	{
		// Loop through the file until it reaches the end of the file
		while (!carsIn.eof())
		{
			// Read the data from the file "CarsData.txt"
			carsIn.ignore(100, ':');
			carsIn.ignore();
			getline(carsIn, cars[numberOfCars].carName);
			carsIn.ignore(10);
			carsIn >> cars[numberOfCars].carYear;
			carsIn.ignore(13);
			carsIn >> cars[numberOfCars].dailyPrice;
			carsIn.ignore(14);
			carsIn >> cars[numberOfCars].vehicleType;
			carsIn.ignore(14);
			carsIn >> cars[numberOfCars].serialNumber;

			numberOfCars++;
		}
		numberOfCars--;	
		
		// Display the number of imported cars
		cout << "------- [ " << numberOfCars <<" ]"<< " Cars imported successfully! ------------" << endl;
		
		// Close the file
		carsIn.close();
	}
	
	// If the file is not opened
	else
	{
		cout << "No cars imported, please add cars (from cars menu) to save them for the next time." << endl;
	}
	
	// --- Read bills data ---
	
	// Open the file
	billsIn.open("Data/BillsData.txt", ios::in);
	
	// Check if the file is open
	if (billsIn.is_open())
	{
		// Loop through the file until it reaches the end of the file
		while(!billsIn.eof())
		{
			// Read the data from the file "BillsData.txt"
			billsIn.ignore(100, ':');
			billsIn.ignore();
			billsIn >> bills[numberOfBills].renter.nationalID;
			billsIn.ignore(14);
			getline(billsIn, bills[numberOfBills].renter.fullName);
			billsIn.ignore(14);
			billsIn >> bills[numberOfBills].renter.phoneNumber;
			billsIn.ignore(9);
			billsIn >> bills[numberOfBills].renter.gender;
			billsIn.ignore(11);
			getline(billsIn, bills[numberOfBills].rentedCar.carName);
			billsIn.ignore(10);
			billsIn >> bills[numberOfBills].rentedCar.carYear;
			billsIn.ignore(13);
			billsIn >> bills[numberOfBills].rentedCar.dailyPrice;
			billsIn.ignore(14);
			billsIn >> bills[numberOfBills].rentedCar.vehicleType;
			billsIn.ignore(14);
			billsIn >> bills[numberOfBills].rentedCar.serialNumber;
			billsIn.ignore(16);
			billsIn >> bills[numberOfBills].numberOfDays;
			billsIn.ignore(13);
			billsIn >> bills[numberOfBills].totalPrice;
			
			numberOfBills++;
		}
		numberOfBills--;	
		
		// Display the number of imported customers
		cout << "------- [ " << numberOfBills <<" ]"<< " Bills imported successfully! -----------" << endl;
		
		// Close the file
		billsIn.close();
	}
	
	// If the file is not opened
	else
	{
		cout << "No bills imported, please add bills (from bills menu) to save them for the next time." << endl;
	}

	cout << "\n\n";
}

// Function to write customers data to a file(CustomersData.txt)
void writeCustomersData(Customer customer[], int numberOfCustomers)
{
	// Declare a stream variable
	ofstream outFile;
	
	// Open the file
	outFile.open("Data/CustomersData.txt", ios::out);
	
	// Check if the file is open or not
	if(outFile.is_open())
	{
		// Loop through customers array
		for (int i =0; i<numberOfCustomers; i++)
		{
			// Write the data to "CustomersData.txt"
			outFile << "=================================================================================\n";
			outFile << "National ID: " << customer[i].nationalID << endl;
			outFile << "Full name: " << customer[i].fullName << endl;
			outFile << "Phone number: " << customer[i].phoneNumber << endl;
			outFile << "Gender: " << customer[i].gender << endl;
			
		}
		
		// Close the file
		outFile.close();
	}
}


// Function to write cars data to a file(CarsData.txt)
void writeCarsData(Car cars[], int numberOfCars)
{
	// Declare a stream variable
	ofstream outFile;
	
	// Open the file
	outFile.open("Data/CarsData.txt", ios::out);
	
	// Check if the file is open or not
	if(outFile.is_open())
	{
		// Loop through cars array
		for (int i =0; i<numberOfCars; i++)
		{
			// Write the data to "CarsData.txt"
			outFile << "=================================================================================\n";
			outFile << "Car name: " << cars[i].carName << endl;
			outFile << "Car year: " << cars[i].carYear << endl;
			outFile << "Daily price: " << cars[i].dailyPrice << endl;
			outFile << "Vehicle type: " << cars[i].vehicleType << endl;
			outFile << "serialNumber: " << cars[i].serialNumber << endl;
		}
		
		// Close the file
		outFile.close();
	}
}

// Function to write bills data to a file(BillsData.txt)
void writeBillsData(Bill bills[], int numberOfBills)
{
	// Declare a stream variable
	ofstream outFile;
	
	// Open the file
	outFile.open("Data/BillsData.txt", ios::out);
	
	// Check if the file is open or not
	if(outFile.is_open())
	{
		// Loop through bills array
		for (int i =0; i<numberOfBills; i++)
		{
			// Write the data to "BillsData.txt"
			outFile << "=================================================================================\n";
			outFile << "National ID: " << bills[i].renter.nationalID << endl;
			outFile << "Renter name: " << bills[i].renter.fullName << endl;
			outFile << "Phone number: " << bills[i].renter.phoneNumber << endl;
			outFile << "Gender: " << bills[i].renter.gender << endl;	
			outFile << "Car name: " << bills[i].rentedCar.carName << endl;
			outFile << "Car year: " << bills[i].rentedCar.carYear << endl;
			outFile << "Daily price: " << bills[i].rentedCar.dailyPrice << endl;
			outFile << "Vehicle type: " << bills[i].rentedCar.vehicleType << endl;
			outFile << "serialNumber: " << bills[i].rentedCar.serialNumber << endl;
			outFile << "Number of days: " << bills[i].numberOfDays << endl;
			outFile << "Total price: " << bills[i].totalPrice << endl;
		}
		
		// Close the file
		outFile.close();
	}
}

// function to get the current local date and time 
string getDateAndTime()
{
	time_t currentTime = time(0);
	
	// Convert it to string
	char* dt = ctime(&currentTime);
	
	return dt;
}

//Function to check if the phone number of the new customer is new or not
bool isNew(string phoneNum, Customer customer[], int numOfCustomers)
{
	// Loop through customers array to check if the phone number already exists or not
	for (int i = 0; i < numOfCustomers; i++)
	{
		if (phoneNum == customer[i].phoneNumber)
		{
			// If it is already there return false
			return false;	
		}
	}
	
	// If it is not there return true
	return true;
}

//Function to check if the national ID of the new customer is new or not
bool isIDNew(string nationalID, Customer customer[], int numOfCustomers)
{
	// Loop through customers array to check if the phone number already exists or not
	for (int i = 0; i < numOfCustomers; i++)
	{
		if (nationalID == customer[i].nationalID)
		{
			// If it is already there return false
			return false;	
		}
	}
	
	// If it is not there return true
	return true;
}

//Function to check if the serialNumber of the new car is new or not
bool isNew(string serialNumber, Car cars[], int numOfCars)
{
	// Loop through cars array to check if the serialNumber already exists or not
	for (int i = 0; i < numOfCars; i++)
	{
		if (serialNumber == cars[i].serialNumber)
		{
			// If it is already there return false
			return false;	
		}
	}
	
	// If it is not there return true
	return true;
}

// Function to check if the input is number
bool isNumber(string value)
{
	// Declare a variable to store the length of the string
	int length = value.length();
	
	// Loop through each character on the string to check if it is digit 
	for (int i = 0; i < length; i++)
	{
		if (isdigit(value[i]) == false)
		{
			// If there is a non-digit character on string end the function and return false
			return false;
		}
	}
	
	// If all characters are digits return true 
	return true;
}
// Function to create the folders - Data and Reports -
void createFolders()
{

	// Create Data folder
	if(!_mkdir("Data"))
	{
		cout << "[ Data ]"<<" created, All data files will be saved in this folder." << endl << endl;
	}	
	
	// Create Reports folder
	if(!_mkdir("Reports"))
	{
		cout << "[ Reports ]"<<" created, All reports files will be saved in this folder." << endl << endl;
	}	
}


// Function to print the new bill
void printTheNewBill(Bill bills[], int numberOfBills)
{
	// Print the bill information
	cout << endl;
	cout << "------------------ The Bill ------------------" << endl;
	cout<<"Customer name:  "<<bills[numberOfBills].renter.fullName<<endl;
	cout<<"Customer phone: "<<bills[numberOfBills].renter.phoneNumber<<endl;
	cout<<"The rented car is: "<< bills[numberOfBills].rentedCar.carName << " - " << bills[numberOfBills].rentedCar.carYear <<endl;
	
	// Print how many days the car is rented
	if(bills[numberOfBills].numberOfDays>=2)
	{
		cout<<"The car is rented for "<<bills[numberOfBills].numberOfDays<<" days."<<endl;
	}
	if(bills[numberOfBills].numberOfDays == 1)
	{
		cout<<"The car is rented for 1 day."<<endl;
	}	
	
	// Print the total price	
	cout<<"\nTour total price is: "<< bills[numberOfBills].totalPrice <<endl;
	cout << "----------------------------------------------" << endl << endl;
}

// Function to rent a car for a customer
void rentTheCar(Car cars[], int numberOfCars, Bill bills[], int &numberOfBills)					
{
	// Declare variables
	string serialNumber;
	int days;
	
	// Display all cars to the user
	cout<<"Please select a car form the list by the serialNumber number:"<<endl;
	displayCars(cars, numberOfCars);
	
	while(true)
	{
		// Get the serialNumber of the requested car
		cout << "Enter the serialNumber of the car: " << endl;
		cin >> serialNumber;
		
		// Loop until the user enter a number
		while (isNumber(serialNumber) == false)
		{
			cout << "Sorry, please enter a valid serialNumber: "<<endl;
			cin >> serialNumber;
		}
	
		// Search for the index of the requested car
		int found = searchCar(serialNumber, cars, numberOfCars);
		
		// If found >= 0 it means the car is found  
		if (found >= 0)
		{
			// Loop if the user enter a 0 days
			do
			{
				// Get the number of days 
				cout<<"Enter the number of days: "<<endl;
				cin>>days;
			
				// Check if the input is an integer
				while(cin.fail())
				{
					// Continue to get input until get an int
					cout << "Please enter a valid number\n" <<endl;
					cout << "Enter the number of days: ";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin >> days;
					
				}
			}while (days == 0); 
			
			// Initialize the total price (Days * Daily price of the car)
			bills[numberOfBills].totalPrice = days * cars[found].dailyPrice;
			
			// After we check for the validation of the number of days, Initialize numberOfDays
			bills[numberOfBills].numberOfDays = days;
			
			// Set the selected car as the rented car
			bills[numberOfBills].rentedCar = cars[found];
			
			// Print the new bill to the user
			printTheNewBill(bills, numberOfBills);
			
			// Increment the number of bills by one
			numberOfBills++;
			
			// Write the new bill data into the file(BillsData.txt)					
			writeNewBills(bills[numberOfBills-1]);
			
			// Write the update into statistcal report file
			textUpdate = string("Added a New bill [ Car rented serialNumber:" )  + bills[numberOfBills-1].rentedCar.serialNumber + string(" For customer: ") + bills[numberOfBills-1].renter.phoneNumber + string(" ] - New number of bills: ") + numToString(numberOfBills);
			statisticalReport (textUpdate);
			
			// Success message
			cout << "The bill has been saved successfully!\n" << endl;
			
			// Break the loop if the the creating bill done
			break;
		}
		
		// If the serialNumber is incorrect
		else
		{
			cout<<"Sorry wrong serialNumber number, Please enter the correct serialNumber number"<<endl;
		}		
	}
}

// Function to write on the (Statistical Report.txt) file after any update
void statisticalReport (string text)
{
	// Declare stream variable
	ofstream outFile;
	
	// Open the file
	outFile.open("Statistical_Report.txt", ios::app);
	
	// Check if the file is open
	if (outFile.is_open())
	{
		// Write the date and time and the update text
		outFile << "-----------------------------------------------------------------------------" << endl;
		outFile << "Date and time: " << getDateAndTime() ;
		outFile << text << "." << endl << endl;
		
		// Close the file
		outFile.close();
	}
}

// Function to write the data of the new customer into "CustomersData.txt"
void writeNewCustomer(Customer customer)
{
	// Declare a stream variable
	ofstream outFile;
	
	// Open the file
	outFile.open("Data/CustomersData.txt", ios::app);
	
	// Check if the file is open or not
	if(outFile.is_open())
	{
		// Write the data of the new customer to "CustomersData.txt"
		outFile << "=================================================================================\n";
		outFile << "National ID: " << customer.nationalID << endl;
		outFile << "Full name: " << customer.fullName << endl;
		outFile << "Phone number: " << customer.phoneNumber << endl;
		outFile << "Gender: " << customer.gender << endl;	
		
		// Close the file
		outFile.close();
	}
}

// Function to write the data of the new car into "CarsData.txt"
void writeNewCar(Car cars)
{
	// Declare a stream variable
	ofstream outFile;
	
	// Open the file
	outFile.open("Data/CarsData.txt", ios::app);
	
	// Check if the file is open or not
	if(outFile.is_open())
	{
		// Write the data of the new car to "CarsData.txt"
		outFile << "=================================================================================\n";
		outFile << "Car name: " << cars.carName << endl;
		outFile << "Car year: " << cars.carYear << endl;
		outFile << "Daily price: " << cars.dailyPrice << endl;
		outFile << "Vehicle type: " << cars.vehicleType << endl;
		outFile << "serialNumber: " << cars.serialNumber << endl;
		
		// Close the file
		outFile.close();
	}
}

// Function to convert double to string 
string numToString (double num)
{
	// Declare a variable to store the number after convert it
	string converted;
	
	// Using the stringstream to convert from int to string 
	stringstream converter;
	converter << num;
	converted = converter.str();
	
	// Return the number after convert it
	return converted;
}

// Function to convert integer to string 
string numToString (int num)
{
	// Declare a variable to store the number after convert it
	string converted;
	
	// Using the stringstream to convert from int to string 
	stringstream converter;
	converter << num;
	converted = converter.str();
	
	// Return the number after convert it
	return converted;
}

// Function to write the data of the new bill into "BillsData.txt"
void writeNewBills(Bill bill)
{
	// Declare a stream variable
	ofstream outFile;
	
	// Open the file
	outFile.open("Data/BillsData.txt", ios::app);
	
	// Check if the file is open or not
	if(outFile.is_open())
	{
			// Write the data to "BillsData.txt"
			outFile << "=================================================================================\n";
			outFile << "National ID: " << bill.renter.nationalID << endl;
			outFile << "Renter name: " << bill.renter.fullName << endl;
			outFile << "Phone number: " << bill.renter.phoneNumber << endl;
			outFile << "Gender: " << bill.renter.gender << endl;	
			outFile << "Car name: " << bill.rentedCar.carName << endl;
			outFile << "Car year: " << bill.rentedCar.carYear << endl;
			outFile << "Daily price: " << bill.rentedCar.dailyPrice << endl;
			outFile << "Vehicle type: " << bill.rentedCar.vehicleType << endl;
			outFile << "serialNumber: " << bill.rentedCar.serialNumber << endl;
			outFile << "Number of days: " << bill.numberOfDays << endl;
			outFile << "Total price: " << bill.totalPrice << endl;
		
		// Close the file
		outFile.close();
	}
}

// Check if the input is number or not
void inputInt(int &num)
{
    cin >> num;
    while(cin.fail())
    {
    // Continue to get input until get an int
	cout << "Please enter a number: ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	cin >> num;
    }
}

// Check if the input is number or not
void inputDouble(double &num)
{
    cin >> num;
    while(cin.fail())
    {
    // Continue to get input until get an int
	cout << "Please enter a number: ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	cin >> num;
    }
}

// Function to calculate the age of the customer
int calculateAge()
{
    // Declare Variables
	int day, month, year;
    struct tm date = {0};
    
    // Get the date of birth from 
    cout<<"Enter The Date of Birth" << endl;
    cout << "  > Year: ";
    inputInt(year);
    
	// Get the month from the user
	cout << "  > Month: ";
    inputInt(month);
    
    // Check if the month is correct
	while (month > 12 || month <= 0)
	{
		cout << "Please enter a valid month" << endl << endl;
		cout << "  > Month: ";
    	inputInt(month);
	}
	
	// Get the day from the user
	cout << "  > Day: ";
	inputInt(day);	
	
	// Check if the day is correct
	bool correctDay = false;	
	while (correctDay = false || day>31 || day<=0)
	{
		if((month==1 || month==3 || month==5|| month==7|| month==8||month==10||month==12) && day>0 && day<=31)
		{
			correctDay = true ;
		}
		else if (month==4 || month==6 || month==9|| month==11 && day>0 && day<=30)
		{
			correctDay = true ;
		}
		else if (month==2)
		{
			
			// Check if it is Leap year
			if((year%400==0 || (year%100!=0 && year%4==0)) && day>0 && day<=29)
                 correctDay = true ;
               else if(day>0 && day<=28)
                  correctDay = true ;
		}
		cout<<"Please enter a valid day"<< endl << endl;
		cout << "  > day: ";
    	inputInt(day);
	}

    // Calculate the age
    date.tm_year = year-1900;
    date.tm_mon  = month-1;
    date.tm_mday = day;
    time_t normal = mktime(&date);
    time_t current;
    time(&current);
    int age = ((difftime(current, normal) + 86400L/2) / 86400L)/365;
	
	//Check if the age is correct
	if (age > 100 || age <=0)
	{
		cout<<"Sorry the age is not correct, Please Check the information and try again."<<endl;
		return -1 ;
	}
	
	// Return the age in years
	return age;
}

// Function to check if the user is sure
bool sure()
{
	while (true)
	{
		char check;
		cout << "\nAre you sure you want to continue ?[Y/N]: ";
	    cin >> check;
	    
	    // If the user choose to continue
	    if (check == 'y' || check == 'Y')
	    {
	    	return true;
	    }
	    
	    // If the user choose no, end the function
		else if (check == 'n' || check == 'N')
		{ 
			return false;
		}
		
		// If the user enter anything else
		else
		{
			cout << "Please select a valid option."<< endl << endl;	
		}
	}
}


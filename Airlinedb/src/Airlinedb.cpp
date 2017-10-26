//============================================================================
// Name        : Airlinedb.cpp
// Author      :ferdinandTembo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Passenger.h"
#include "LinkedList.h"
#include "OrderedLinkedList.h"
using namespace std;


string getFlightNumber();
string getFirstname();
string getLastname();
string getAdress();
string getNumber();
void listPassenger(Passenger Passengers[], int listSize);
void search(string firstname,string lastname);
void deletePassenger(Passenger passenger,string flightnumber);
void displayPassengerDetails(Passenger p, string flightNumber);


Passenger* pPassengers;
int capacity = 0;
int size = 0;
OrderedLinkedList<Passenger> list100;
OrderedLinkedList<Passenger> list200;
OrderedLinkedList<Passenger> list300;
OrderedLinkedList<Passenger> list400;

int main() {

	char answer;

	cout<<"******DELTA AITLINES ***\nPlease choose an operation: \n";

	do{
		cout<<"A(Add) | S (Search) | D(Delete) |L(List) |Q(Quit): ";
		cin >> answer;
		cout<<endl;
		answer = tolower(answer);

		switch(answer){
		case 'a': {
			string flight = getFlightNumber();
			while(flight !="100" && flight !="200" && flight !="300" && flight !="400"){
				cout<<"This flight does not exist"<<endl;
				flight = getFlightNumber();

			}
			string firstname = getFirstname();
			string lastname = getLastname();
			string adress = getAdress();
			string phoneNumber = getNumber();
			Passenger newPassenger(firstname, lastname, adress,phoneNumber);

			if (flight =="100" ){
				list100.insert(newPassenger);
			}else if (flight =="200"){
				list200.insert(newPassenger);
			}else if (flight =="300"){
				list300.insert(newPassenger);
			}else if (flight =="400"){
				list400.insert(newPassenger);
			}
			else { cout<<" "<<endl;

			}break;

		}
		case 's': {
			string firstname = getFirstname();
			string lastname = getLastname();
			search(firstname,lastname);
			break;
		}
		case 'l': {
			string flight = getFlightNumber();
			while(flight !="100" && flight !="200" && flight !="300" && flight !="400"){
				cout<<"This flight does not exist"<<endl;
				flight = getFlightNumber();

			}
			if (flight=="100"){
				list100.display();
			}
			else if (flight=="200"){
				list200.display();
			}
			else if (flight=="300"){
				list300.display();
			}
			else if (flight=="400"){
				list400.display();
			}
			break;

		}
		case 'd':{
			string flight = getFlightNumber();
			string firstname = getFirstname();
			string lastname = getLastname();

			Passenger passengerTodelete(firstname,lastname);
			deletePassenger(passengerTodelete, flight);
			cout<<"Passenger deleted"<<endl;
			break;
		}


		}

	}while (answer!='q');

	cout<<"Thank you for using the software!"<< endl;

	return 0;
}

// just deliting the passenger in the appropriate fight
void deletePassenger(Passenger p,string flightnumber){

	if(flightnumber == "100"){
		list100.deletePassenger(p);
	}
	else if(flightnumber == "200"){
		list200.deletePassenger(p);
	}
	else if(flightnumber == "300"){
		list300.deletePassenger(p);
	}
	else if(flightnumber == "400"){
		list400.deletePassenger(p);
	}



}
// just searching the passenger in their appropriate flight
void search(string firstname,string lastname){

	Passenger pas(firstname, lastname);
	Passenger *p1 = list100.search(pas);
	Passenger *p2 = list200.search(pas);
	Passenger *p3 = list300.search(pas);
	Passenger *p4 = list400.search(pas);
	if(list100.search(pas)!=NULL){
		displayPassengerDetails(*p1,"100");
	}
	else if(p2!=NULL){
		displayPassengerDetails(*p2,"200");
	}
	else if(p3!=NULL){
		displayPassengerDetails(*p3,"300");
	}
	else if(p3!=NULL){
		displayPassengerDetails(*p4,"400");
	}
	else{
		cout<<"Passenger does not exist"<<endl;
	}
}
// This is just the way I want to display my Passenger's details
void displayPassengerDetails(Passenger p, string flightNumber){

	cout<<"Flight Number: "<<flightNumber<<endl;
	cout<<"Firstname: "<<p.getFirstname()<<endl;
	cout<<"Lastname: "<<p.getLastname()<<endl;
	cout<<"Adress: "<<p.getAdress()<<endl;
	cout<<"Phone:"<<p.getPhoneNumber()<<endl;

}



// This function ask the user to enter the fight number
string getFlightNumber(){
	string fight;
	cout<<"Please enter the fight number :"<<endl;
	cin>>fight;
	return fight;
}
/* in this function , I just define 0123456789 as my valid number ,
it will help me in the getFirname and getLastname to check if the user type the appropriate format I want
*/
bool validateString(string stringdata){
	string numberValidation = "0123456789";
	for(int i = 0; i < stringdata.size(); i++){
		if(numberValidation.find(stringdata[i]) != -1){
			return false;
		}
	}
	return true;
}
// this function just ask for the firtname , and if the user type in the wrong format like numbers, it will keeps asking
string getFirstname(){

	string firstname;
	cout<<"Please enter firstname :"<<endl;
	cin>> firstname;

	while(!validateString(firstname)){
		cout<<"This is not correct"<<endl;
		cout<<"Please enter firstname :"<<endl;
		cin>> firstname;
	}
	return firstname;

}

// this function just ask for the lastname , and if the user type in the wrong format like numbers, it will keeps asking
string getLastname(){
	string lastname;
	cout<<"Please enter lastname :"<<endl;
	cin>> lastname;
	while(!validateString(lastname)){
		cout<<"This is not correct"<<endl;
		cout<<"Please enter lastname :"<<endl;
		cin>> lastname;
	}
	return lastname;

}
// This function get the adress from the user
string getAdress(){
	string adress;
	cout <<"Please enter the adress :"<<endl;
	cin.ignore();
	getline(cin,adress);

	return adress;
}


// This function get the number from the user
string getNumber(){
	string phoneNumber;
	cout<<"Please enter the number :"<<endl;
	cin>>phoneNumber;
	return phoneNumber;
}



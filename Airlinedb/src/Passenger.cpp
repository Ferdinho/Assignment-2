/*
 * Passengers.cpp
 *
 *  Created on: Oct 16, 2017
 *      Author: ferdinandtembo
 */

#include "Passenger.h"

Passenger::Passenger() {
	firstname ="";
	lastname = "";
	adress = "";
	phoneNumber = "";

	// TODO Auto-generated constructor stub

}

Passenger::Passenger (string firstname ,string lastname, string adress , string phoneNumber){
	this->firstname = firstname;
	this->lastname = lastname;
	this->adress = adress;
	this->phoneNumber = phoneNumber;


}

string Passenger::getFirstname(){
	return firstname;
}

string Passenger::getLastname(){
	return lastname;
}

string Passenger::getAdress(){
	return adress;

}

string Passenger::getPhoneNumber(){
	return phoneNumber;
}

bool Passenger::operator > (const Passenger &passenger)
{
  return (lastname > passenger.lastname);
}

bool Passenger::operator < (const Passenger &passenger)
{
	return (lastname < passenger.lastname);
}

void Passenger::displayContactDetail(Passenger Passenger){
	cout<<"Firstname :"<<Passenger.firstname<<" Lastname: "<<Passenger.lastname <<" Adress : "<<Passenger.adress <<" Phone: "<<Passenger.phoneNumber<<endl;;
}

Passenger::~Passenger() {
	// TODO Auto-generated destructor stub
}




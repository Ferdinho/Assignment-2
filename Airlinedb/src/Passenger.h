/*
 * Passengers.h
 *
 *  Created on: Oct 16, 2017
 *      Author: ferdinandtembo
 */


#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <iostream>
using namespace std;

class Passenger {
private :
	string firstname;
	string lastname;
	string adress;
	string phoneNumber;

public:
	Passenger();
	Passenger(const Passenger& other){
		firstname = other.firstname;
		lastname = other.lastname;
		adress = other.adress;
		phoneNumber = other.phoneNumber;
	}
	Passenger(string firstname, string lastname):firstname(firstname),lastname(lastname){};

	Passenger(string firstname ,string lastname, string adress , string phoneNumber);
	string getFirstname();
	string getLastname();
	string getAdress();
	string getPhoneNumber();
    void displayContactDetail(Passenger Passenger);
    friend ostream& operator<<(ostream &out, const Passenger &passenger){
    			out<<passenger.firstname<<" "<<passenger.lastname<<" ["<<passenger.adress<<"] ["<<passenger.phoneNumber<<"]";
    				return out;
    		}
    bool operator == (const Passenger &other)
    	{
    	  return (firstname == other.firstname && lastname == other.lastname)
    	                ? true : false;
    	}
    bool operator != (const Passenger &other)
        	{
        	  return (firstname != other.firstname || lastname != other.lastname)
        	                ? true : false;
        	}

    bool operator < (const Passenger &passenger);
    bool operator > (const Passenger &passenger);

	virtual ~Passenger();
};

#endif /* PASSENGER_H_ */

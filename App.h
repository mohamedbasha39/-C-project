#pragma once
#include <iostream>
#include<string>
using namespace std;

struct Account {

	string Username, Fulladress, Password;
	string Status = "active";
	int Age;
	unsigned long long int ID;
	double Balance;

};




class Createaccountforadmin {

public:

	void getfullname(string Fullname, int Size) ;

	void getfulladress(string Fulladress);

	void ID(unsigned long long int ID) ;


	void Password(string Password);

	void Age(int Age);

	void Balance(double Balance);

	void Increase();

};

class Implmented 
{
	public:

		Createaccountforadmin create;


		void Fullname();

		void Fulladress();

		void ID();

		void Password();
		void Age();

		void Balance();

		void plus();
};


class OpenAccount 
{

public:


	void checkforadmin();

	void checkforclient();

	void transaction();


	void changeaccountstatus();


	void getcash();


	void addcash();


	void changeaccountpassword();

	void openaccount(int Switch);


};


void Makeaccount();
void openaccountforadminandclient(int Switch);
void AppStart();





#include "App.h"

int k = 0;
int i = 0;
Account account[50];
int l = 0;

void Createaccountforadmin :: getfullname(string Fullname, int Size) {

	account[i].Username = Fullname;
	if (Size > 21) {
		throw exception("Invalid ");
	}
}

void Createaccountforadmin:: getfulladress(string Fulladress) {

	account[i].Fulladress = Fulladress;
}

void Createaccountforadmin::ID(unsigned long long int ID) {
	int Size = 0;
	account[i].ID = ID;
	do {
		ID /= 10;
		Size++;
	} while (ID != 0);



	if (Size != 14) {
		throw exception("Invalid ");
	}
}

void Createaccountforadmin::Password(string Password)
{
	account[i].Password = Password;
}

void Createaccountforadmin::Age(int Age)
{
	account[i].Age = Age;

	if (account[i].Age < 21) {
		throw exception("Invalid");
	}
}

void Createaccountforadmin::Balance(double Balance)
{
	account[i].Balance = Balance;

	if (account[i].Balance < 0) {
		throw exception("Invalid");
	}
}

void Createaccountforadmin::Increase()
{
	k = ++i;
}

void Implmented::Fullname()
{
	string Fullname;
	int Size;
	cout << "Enter Your Fullname At Least Four Names:  ";
	cin.ignore();
	getline(cin, Fullname);
	cout << endl;
	Size = Fullname.length();
	create.getfullname(Fullname, Size);
}

void Implmented::Fulladress()
{
	string Fulladress;
	cout << "Enter Your Fulladress:  ";
	cin.ignore();
	getline(cin, Fulladress);
	cout << endl;
	create.getfulladress(Fulladress);
}

void Implmented::ID()
{
	unsigned long long int ID;
	cout << "Enter Your ID Without Spaces consist Of 14 Number:  ";
	cin >> ID;
	cout << endl;
	create.ID(ID);
}

void Implmented::Password()
{
	string Password;
	cout << "Enter Your password Without Spaces:  ";
	cin >> Password;
	cout << endl;
	create.Password(Password);
}

void Implmented::Age()
{
	int Age;
	cout << "Enter Your Age:  ";
	cin >> Age;
	cout << endl;
	create.Age(Age);
}

void Implmented::Balance()
{
	double Balance;
	cout << "Enter Your Balance:  ";
	cin >> Balance;
	cout << endl;
	create.Balance(Balance);
}

void Implmented::plus()
{
	create.Increase();
}

void OpenAccount::checkforadmin()
{
	int Choice;

	do {

		cout << "Press 1 To Make Transaction" << endl << "Press 2 To Change Account Status" <<
			endl << "Press 3 To Get Cash" << endl << "Press 4 To Deposit in Account" << endl <<
			"Press 5 To Return To Main Menu" << endl << endl;
		cin >> Choice;

		if (Choice == 1) {
			transaction();
		}

		else if (Choice == 2) {
			changeaccountstatus();
		}

		else if (Choice == 3) {
			getcash();
		}

		else if (Choice == 4) {
			addcash();
		}

		else if (Choice == 5) {
			cout << "You Return To Main Menu " << endl << endl;
		}

		else {
			throw exception("Invalid");
		}

	} while (Choice <= 4);
}

void OpenAccount::checkforclient()
{
	int Choice;

	do {

		cout << "Press 1 To Make Transaction" << endl << "Press 2 To Change Account Password" <<
			endl << "Press 3 To Get Cash" << endl << "Press 4 To Deposit in Account" << endl <<
			"Press 5 To Return To Main Menu" << endl << endl;
		cin >> Choice;

		if (Choice == 1) {
			transaction();
		}

		else if (Choice == 2) {
			changeaccountpassword();
		}

		else if (Choice == 3) {
			getcash();
		}

		else if (Choice == 4) {
			addcash();
		}

		else if (Choice == 5) {
			cout << "You Return To Main Menu " << endl << endl;
		}

		else {
			throw exception("Invalid");
		}

	} while (Choice <= 4);
}

void OpenAccount::transaction()
{
	unsigned long long int ID;
	int Index = 0;
	double Balance;

	cout << "Enter Clint ID To Transfer Money:   ";
	cin >> ID;
	cout << endl;

	for (int i = 0; i < k; i++) {

		if (account[i].ID == ID) {

			Index = i;

			if (account[l].Status == account[Index].Status) {

				cout << "Enter The Money To Transfer It:  ";
				cin >> Balance;
				cout << endl;

				if (Balance > account[l].Balance) {
					throw exception("Invalid");
				}

				account[Index].Balance = account[Index].Balance + Balance;
				account[l].Balance = account[l].Balance - Balance;
				cout << "Now Your Money In Your Account Become:  " << account[l].Balance;

			}

			else {
				throw exception("Invalid ");
			}

		}

	}

	if (Index == 0) {
		throw exception("Invalid");
	}
}

void OpenAccount::changeaccountstatus()
{
	int Status;

	cout << "Press 1 To Change Statue To Active" << endl << "Press 2 To Change Statue To  Restricted"
		<< endl << "Press 3 To Change Statue To  Closed" << endl;
	cin >> Status;

	if (Status == 1) {
		account[l].Status = "active";
		cout << "it is now " << account[l].Status << endl;
	}

	else if (Status == 2) {
		account[l].Status = "Restricted";
		cout << "it is now " << account[l].Status << endl;
	}

	else if (Status == 3) {
		account[l].Status = "Closed";
		cout << "it is now " << account[l].Status << endl;
	}

	else {
		throw exception("Invalid");
	}
}

void OpenAccount::getcash()
{
	double Balance;
	cout << "Enter The Money You Want From This Account:  ";
	cin >> Balance;
	cout << endl;
	if (Balance > account[l].Balance) {
		throw exception("Invalid");
	}

	else {
		account[l].Balance = account[l].Balance - Balance;
		cout << "You Got " << Balance << " From Your Account " << account[l].Username << endl
			<< "Now Your Money In Your Account Become: " << account[l].Balance << endl << endl;
	}
}

void OpenAccount::addcash()
{
	double Balance;
	cout << "Enter The Money That You Add To This Account:  ";
	cin >> Balance;
	cout << endl;
	if (Balance < 0) {
		throw exception("Invalid");
	}

	else {
		account[l].Balance = account[l].Balance + Balance;
		cout << "You Added " << Balance << " To Your Account " << account[l].Username << endl
			<< "Now Your Money In Your Account Become: " << account[l].Balance << endl << endl;
	}
}

void OpenAccount::changeaccountpassword()
{
	string Oldpassword, Newpassord;
	int flag = 0;
	cout << "Enter Clint Old Password:  ";
	cin >> Oldpassword;

	for (int i = 0; i < k; i++) {

		if (account[i].Password == Oldpassword) {

			l = i;
			flag = 1;
			cout << "Enter Clint New Password:  ";
			cin >> Newpassord;
			cout << endl;
			account[i].Password = Newpassord;

		}

	}

	if (flag == 0) {
		throw exception("Invalid");
	}
}

void OpenAccount::openaccount(int Switch)
{

	unsigned long long int ID;
	int flag = 0;
	string Password;
	cout << "Enter Clint ID:  ";
	cin >> ID;
	cout << endl;

	if (Switch == 1) {

		for (int i = 0; i < k; i++) {

			if (account[i].ID == ID) {
				l = i;
				flag = 1;
				checkforadmin();
			}

		}
	}

	else if (Switch == 2) {
		cout << "Enter Clint Password:  ";
		cin >> Password;
		cout << endl;

		for (int i = 0; i < k; i++) {

			if (account[i].ID == ID && account[i].Password == Password) {
				l = i;
				flag = 1;
				checkforclient();
			}

		}

	}

	if (flag == 0) {
		throw exception("Invalid");
	}
}

void Makeaccount() {
	Implmented implemented;
	implemented.Fullname();
	implemented.Fulladress();
	implemented.ID();
	implemented.Password();
	implemented.Age();
	implemented.Balance();
	implemented.plus();
}
void openaccountforadminandclient(int Switch) {
	OpenAccount openAccount;
	openAccount.openaccount(Switch);
}

void AppStart()
{
	int Choice, flag = 0, Switch, Answer;

	do {

		cout << "Hi,This Application For The Bank " << endl << endl;
		cout << "Press 1 For Admin Account " << endl << "Press 2 For Client Account " << endl << endl;
		cin >> Switch;

		if (Switch == 1) {

			cout << "Press 1 Create Account Number 1 " << endl << "Press 2 Open Existing Account Number 2 " << endl
				<< "Press 3 Exit System Number 3 " << endl << endl;
			cin >> Choice;

			if (Choice == 1) {
				Makeaccount();
				flag = 1;
			}

			else if (Choice == 2 && flag == 1) {
				openaccountforadminandclient(Switch);
			}

			else if (Choice == 3) {
				system("CLS");
			}

			else {
				throw exception("Invalid ");
			}


		}

		else if (Switch == 2) {
			openaccountforadminandclient(Switch);
		}

		else {
			throw exception("Invalid ");
		}


	} while (Switch < 3);
}
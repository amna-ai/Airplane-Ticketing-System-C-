#include<iostream>
#include<fstream>
#include<windows.h>
#include<iomanip>
#include<conio.h>
#include <string>
using namespace std;

string M = "Manager.txt";
string D = "Domestic.txt";
string I = "International.txt";
string C = "Customer.txt";
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
fstream d;
fstream s;
void errordisplay(string);
void passdisplay(string);
bool checkid(string);
void mngfile();
void readdomestic();
void readinternational();
void editdata();
void intro();
void mainmenu();

class start {

protected:

	string name;
	string password;

public:
	virtual void login() = 0;
	virtual void signup() = 0;
};

class customer : public start {

protected:
	string fname, lname, prof, ufile;
public:
	void signup() {
		string n, p;
		cout << "To Sign you up,Enter the asked Credentials: \n\n";
		cout << "First name: ";
		cin >> fname;
		cout << "Last name: ";
		cin >> lname;
		cout << "Profession: ";
		cin >> prof;
		cout << "Username: ";
	m:	cin >> name;
		cout << endl;
		cout << "Password: ";
		cin >> password;
		s.open(C.c_str(), ios::in);
		while (s >> n >> p) {

			if (n == name) {

				//	cout << n << p;
				cout << endl;
				errordisplay("This username already exist.");
				cout << "\nChoose another please: ";
				s.close();
				goto m;
			}


		}
		cout << endl;
		passdisplay("Account Created Successfully.");
		SetConsoleTextAttribute(color, 13);
		cout << "\n\t" <<"Welcome " <<name<< endl;
		SetConsoleTextAttribute(color, 7);
		Sleep(750);
		d.open(C.c_str(), ios::out | ios::app);
		d << name << " " << password << endl;
		d.close();
		s.close();
		ufile = filename(name);
		d.open(ufile.c_str(), ios::out);
		d.close();
	}

	string filename(string a) {
		fname = a + ".txt";
		return fname;
	}




	void login() {
		string u, p;
		cout << "\tLOGIN:\n";
		cout << "       --------\n";
		cout << "Username: ";
		cin >> name;
		cout << "Password: ";
	m:	cin >> password;
		ifstream read(C.c_str());
		
		while (read >> u >> p) {
			if (name == u) {
				//	d >> p;
				break;
			}
			
		}
		read.close();
	//	cout << u << " " << p;
		if (password == p) {
			cout << endl;
			passdisplay("Login Successful.");
			SetConsoleTextAttribute(color, 13);
			cout << endl;
			cout << "\t" <<"Welcome back " << name << endl;
			SetConsoleTextAttribute(color, 7);
			Sleep(750);
			system("cls");
		}

		if (password != p) {
			errordisplay("Wrong Password.");
			cout << endl;
			cout << "Enter Again: ";
			goto m;
		}
		
	}



	void newbooking() {
		int z;
		system("cls");
		cout << "New Booking for\n";
		cout << endl;
		cout << "1.International Flight\n";
		cout << "2.Domestic Flight\n";
		cout << endl;
		cout << "\tEnter your choice: ";
	m:	cin >> z;
		switch (z) {
		case 01: {
			intb();
			break;
		}
		case 02: {
			domb();
			break;
		}
		default:
			cout << "Wrong Input.Select Again: ";
			goto m;
		}
	}

	void intb() {
		int count, ch;
		int k, n, seat;
		string from, to, time, code, level;
		string ufile = filename(name);
		//	cout << ufile;
		system("cls");
		cout << "\t\tAvailable Flights\n\n";
		cout << "\t\t******************\n";
		readinternational();
		count = noofline(I);
		cout << "\n Choose from the available Flight List: ";
	m:	cin >> ch;
		if (ch > count) {
			cout << endl;
			errordisplay("Wrong Input");
			cout << "Enter Again: ";
			goto m;
		}
		s.open(I.c_str(), ios::in);
		while (s >> k >> from >> to >> time >> code) {
			if (ch == k) {
				break;
			}
		}
		s.close();
		 cout << k << from << to << time << code;
		ifstream f(ufile.c_str());
		f.seekg(0, std::ios::end);
		unsigned int size = f.tellg();
		if (!size) {
			n = 0;
			// cout << "Empty File\n";
		}
		else {
			n = noofline(ufile);
		}
		f.close();

		cout << "Choose a Class:" << endl;
		cout << "1.Business \t2.Economy ";
		int x;
		cin >> x;
		switch (x) {
		case 01: {
			level = "Business";
			break;
		}
		case 02: {
			level = "Economy";
			break;
		}

		}

		cout << "Number of seats:";
	ss:	cin >> seat;
		if (seat > 30) {
			cout << endl;
			errordisplay("Sorry.Limited seats available");
			cout << "Enter again: ";
			goto ss;
		}

		d.open(ufile.c_str(), ios::out | ios::app);
		d << n + 1 << "    " << from << "    " << to << "    " << time << "    " << level << "    " << seat << "    " << code << endl;
		d.close();
		passdisplay("Flight Booked");
		cout << endl;
		passdisplay("Payment: Rs.25000");
		Sleep(1050);
	}





	void domb() {
		int count, ch;
		int k, n, seat;
		string from, to, time, code, level;
		string ufile = filename(name);
		cout << "\t\tAvailable Flights\n\n";
		cout << "\t\t*****************" << endl;
		readdomestic();
		count = noofline(D);
		cout << "\n Choose from the available Flight List: ";
	m:	cin >> ch;
		if (ch > count) {
			cout << endl;
			errordisplay("Wrong Input");
			cout << "Enter Again: ";
			goto m;
		}

		s.open(D.c_str(), ios::in);
		while (s >> k >> from >> to >> time >> code) {
			if (ch == k) {
				break;
			}
		}
		s.close();
		cout << k << from << to << time << code;
		ifstream f(ufile.c_str());
		f.seekg(0, std::ios::end);
		unsigned int size = f.tellg();
		if (!size) {
			n = 0;
			// cout << "Empty File\n";
		}
		else {
			n = noofline(ufile);
		}
		f.close();

		cout << "Choose a Class:" << endl;
		cout << "1.Business\t2.Economy ";
		int x;
		cin >> x;
		switch (x) {
		case 01: {
			level = "Business";
			break;
		}
		case 02: {
			level = "Economy";
			break;
		}

		}

		cout << "Number of seats:";
	ss:	cin >> seat;
		if (seat > 30) {
			cout << endl;
			errordisplay("Sorry.Limited seats available");
			cout << "Enter again: ";
			goto ss;
		}

		d.open(ufile.c_str(), ios::out | ios::app);
		d << n + 1 << "    " << from << "    " << to << "    " << time << "    " << level << "    " << seat << "    " << code << endl;
		d.close();
		passdisplay("Flight Booked");
		cout << endl;
		passdisplay("PAyment: Rs.10,000");
		Sleep(1050);
	}


	int noofline(string a) {
		int count = 0;
		string line;

		ifstream file(a.c_str());
		while (getline(file, line)) {
			count++;
		}
		file.close();
		return count;
	}

	void showbooking() {
		system("cls");
		char temp;
		string ufile = filename(name);
		ifstream f(ufile.c_str());
		f.seekg(0, std::ios::end);
		unsigned int size = f.tellg();
		if (!size) {
			cout << endl;
			errordisplay("No Bookings yet.");
			f.close();
			Sleep(750);
		}
		else {
        d.open(ufile.c_str(), ios::in);
		cout << "\n\t\t   Your Bookings  \n";
		cout << "\t\t*******************\n";
		cout << "|S.no|  |From|  |To|  |Time|  |Class|  |Seats|  |Flight no.|\n\n";
		while (!d.eof()) {
			d >> noskipws >> temp;
			cout << temp;
		}
        
		d.close();
		}
	}



	void cancelbooking() {

		system("cls");
		
		int x;
		int k, seat;
		string from, to, time, code, level, xyz;
		string ufile = filename(name);
		
	/*
		char temp;
		ifstream f(ufile.c_str());
		f.seekg(0, std::ios::end);
		unsigned int size = f.tellg();
		if (!size) {
			cout << endl;
			errordisplay("No Bookings yet.");
			f.close();
			Sleep(750);
			
		}
		else {

		*/
            char temp;
			d.open(ufile.c_str(), ios::in);
			cout << "\n\t\t      Your Bookings \n";
			cout << "\t\t-------------------\n";
			while (!d.eof()) {
				d >> noskipws >> temp;
				cout << temp;
	}
			d.close();
			int nll = noofline(ufile);

			cout << "Select the booking you want to cancel: ";
		ghq:	cin >> x;
			
			int y = 1;

			if (x > nll) {
				cout << endl;
				errordisplay("Invalid Selection");
				cout << "Select again: ";
				goto ghq;
			}
			
            
			fstream write;
			write.open("temp.txt",ios::out);
			
			s.open(ufile.c_str(), ios::in);
			
			while (s >> k >> from >> to >> time >> level >> seat >> code) {
				if (x != k) {
				
					write << y << "    " << from << "    " << to << "    " << time << "    " << level << "    " << seat << "    " << code << endl;
					y++;		
			}
			s.close();
			write.close();
			remove(ufile.c_str());
			rename("(temp.txt)", ufile.c_str());

			errordisplay("Booking Cancelled.");
			Sleep(650);
		}		
	}



	void custmenu() {
		int x;
		cout << "\n1.New Member\n";
		cout << "2.Login\n";
		cout << "\tChoose your option: ";
	m:	cin >> x;
		switch (x) {
		case 01: {
			system("cls");
			signup();
			break;
		}

		case 02: {
			system("cls");
			login();
			break;
		}

		default: {
			cout << "Wrong Choice.Enter again: ";
			goto m;
		}


		}
		system("cls");
	m1:	cout << "\n\t Customer Mode\n";
		cout << "\t***************\n\n";
		cout << "1.New Booking\n";
		cout << "2.Show Booking\n";
		cout << "3.Cancel Booking\n";
		cout << "4.Logout\n";
		cout << "\tEnter your choice: ";
		cin >> x;
		switch (x) {
		case 01:
		{
			newbooking();
			system("cls");
			goto m1;
			break;
		}
		case 02: {
			showbooking();
			cout << "\tPress enter to continue ";
			_getch();
			system("cls");
			goto m1;
			break;
		}
		case 03:
		{
			cancelbooking();
			system("cls");
			goto m1;
			break;
		}
		case 04: {
			system("cls");
			mainmenu();
			break;
		}
		default:
			cout << "Wrong Input.Enter Again: ";
			goto m1;
			break;
		}
	}




};







void passdisplay(string message) {

	SetConsoleTextAttribute(color, 10);
	cout << "\t\t" << message << endl;
	SetConsoleTextAttribute(color, 7);
}

void errordisplay(string message) {

	SetConsoleTextAttribute(color, 4);
	cout << "\t\t" << message << endl;
	SetConsoleTextAttribute(color, 7);
}


void mngfile() {

	d.open(M.c_str(), ios::out);
	d << "321" << " " << "amna";
	d.close();
}


void datafile() {

	d.open(I.c_str(), ios::out);
	d << "1\t" << "ISL\t" << "DXB\t" << "Day\t" << "IP232" << endl;
	d << "2\t" << "LHR\t" << "GLA\t" << "Day\t" << "IP233" << endl;
	d << "3\t" << "KHI\t" << "JED\t" << "Day\t" << "IP234" << endl;
	d.close();

	d.open(D.c_str(), ios::out);
	d << "1\t" << "ISL\t" << "LHR\t" << "Day\t" << "D544" << endl;
	d << "2\t" << "OPQT\t" << "MUX\t" << "Day\t" << "D545" << endl;
	d << "3\t" << "LHR\t" << "KHI\t" << "Day\t" << "D56" << endl;
	d << "4\t" << "KHI\t" << "GIL\t" << "Day\t" << "D547" << endl;
	d.close();
}


void readdomestic() {

	char temp;

	d.open(D.c_str(), ios::in);
	cout << "\n\t\t  DOMESTIC FLIGHTS\n\n";
	cout << "|S.NO|\t" << "|FROM|\t" << "|TO|\t" << "|TIME|\t" << "|CODE|" << endl;
	while (!d.eof()) {
		d >> noskipws >> temp;
		cout << temp;
	}
	d.close();
}


void readinternational() {

	char temp;

	d.open(I.c_str(), ios::in);
	cout << "\n\t\t      INTERNAIONAL FLIGHTS\n\n";
	cout << "|S.NO|\t" << "|FROM|\t" << "|TO|\t" << "|TIME|\t" << "|CODE|" << endl;
	while (!d.eof()) {
		d >> noskipws >> temp;
		cout << temp;
	}
	d.close();

}



void editdata() {

	int x;
	string line;
	int count = 0;
	string from, to, time, code;
	cout << "\tADD UP IN: \n" << endl;
	cout << "1.International Flights" << endl;
	cout << "2.Domestic Flights" << endl;
	cout << "\tEnter your choice ";
	cin >> x;
	cout << "\nFROM: ";	cin >> from; cout << "\nTO: "; cin >> to;
	cout << "\nTIME: "; cin >> time; cout << "\nCODE: ";	cin >> code;

	if (x == 1) {

		s.open(I.c_str(), ios::in);
		while (getline(s, line)) {
			count++;
		}
		d.open(I.c_str(), ios::out | ios::app);
		d << count + 1 << "\t" << from << "\t" << to << "\t" << time << "\t" << code << endl;
		s.close();
	}
	if (x == 2) {
		s.open(D.c_str(), ios::in);
		while (getline(s, line)) {
			count++;
		}
		d.open(D.c_str(), ios::out | ios::app);
		d << count + 1 << "\t" << from << "\t" << to << "\t" << time << "\t" << code << endl;
		s.close();
	}
	d.close();
	passdisplay("UPDATED SUCCESSFULLY");

}


void intro() {

	cout << "\n\n\n\t\t   ************************" << endl;
	cout << "\t\t      WELCOME TO FLYLINE" << endl;
	cout << "\t\t   ************************" << endl;
	Sleep(1500);
	cout << "\n\n\t\t    CODE BY:" << endl;
	Sleep(220);
	cout << "\n\t\t         Amna Sohail" << endl;
	Sleep(220);
	cout << "\n\t\t         -----------" << endl;
	Sleep(220);
	cout << "\n\t\t         -----------" << endl;
	Sleep(1600);
	system("cls");
}


class manager : public start {

public:
	manager() {
		mngfile();
	}
	void signup() {}
	void login() {
		cin.ignore();
		cin.clear();
		cout << "\n\tLOGIN PLEASE: \n\n";
		cout << "USERNAME: ";
		getline(cin, name);
		cout << "PASSWORD: ";
	m:	getline(cin, password);

		ifstream mng(M.c_str());
		string temp;
		while (mng >> temp) {
			if (temp == password) {
				passdisplay("LOGIN SUCCESSFUL");
				Sleep(600);
				system("cls");
				break;

			}
			else if (temp != password) {
				errordisplay("WRONG PASSWORD");
				cout << "Enter Again: ";
				goto m;
				break;

			}
			mng.close();

		}
	}


	void mngmenu() {
		int x;

	n:
	m:
		cout << "\n\t\t\MANAGER MODE" << endl;
		cout << "\t     ******************" << endl;
		cout << "1.Add New Flights to the Schedule" << endl;
		cout << "2.View the Schedule" << endl;
		cout << "3.LOG OUT " << endl;
		cout << "\t ENTER YOUR CHOICE: ";
		cin >> x;
		system("cls");
		switch (x) {
		case 01: {
			editdata();
			Sleep(600);
			system("cls");
			goto m;
			break;
		}

		case 02: {
			readdomestic();
			readinternational();
			cout << "\t\t PRESS ENTER TO CONTINUE";
			_getch();
			system("cls");
			goto n;
			break;
		}

		case 03: {
			mainmenu();
			break;
		}
		}
	}

};

void mainmenu() {

	int x, y;
f:	
	cout << "\n\n";
	cout << setw(50) << "*************************************" << endl;
	cout << setw(50) << "*        FLYLINE RESERVATION        *" << endl;
	cout << setw(50) << "*             MAIN MENU             *" << endl;
	cout << setw(50) << "*    PRESS 1 FOR MANAGER MODE       *" << endl;
	cout << setw(50) << "*    PRESS 2 FOR CUSTOMER MODE      *" << endl;
	cout << setw(50) << "*    PRESS 3 to EXIT                *" << endl;
	cout << setw(50) << "*        ENTER YOUR CHOICE:         *" << endl;
	cout << setw(50) << "*************************************" << endl;

	cin >> x;
	
	switch (x) {

	case 01: {
		system("cls");
		manager m;
		m.login();
		m.mngmenu();
		break;
	}

	case 02: {
		system("cls");
		customer c1;
		c1.custmenu();
		break;
	}
	case 03: {
		system("cls");
		SetConsoleTextAttribute(color, 11);
		cout << "\n\t\t" << "Thankyou for choosing FLYLINE.\n\n\n";
		SetConsoleTextAttribute(color, 7);
		Sleep(1000);
		break;
	}
	default: {
		errordisplay("Wrong input");
		Sleep(500);
		system("cls");
		goto f;
	}
	}
}

int main() {
	intro();
	// system("color A0");
	mainmenu();
}

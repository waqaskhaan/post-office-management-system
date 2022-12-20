#include <iostream>
#include <fstream>

using namespace std;

class Postoffice {
public:


};

class customer :public Postoffice {
public:
	string firstname;
	string lastname;
	string customerID;
	string senderaddress;
	string recieveraddress;
	string sendernumber;
	string recievernumber;
public:
	customer() {
		
	}



	void setfirstname(string fn)
	{
		firstname = fn;
	}

	string getfirstname() {
		return firstname;
	}

	void setlastname(string ln)
	{
		lastname = ln;
	}

	string getlastname() { 
	 return lastname; 
	 }

	void setcustomerID(string cid) {
		customerID = cid;
	}

	string getcustomerID() { return customerID; }


	void setsenderaddress(string sa) {
		senderaddress = sa;
	}
	string getsenderaddress() { return senderaddress; }

	void setrecieveraddress(string ra) {
		recieveraddress = ra;
	}
	string getrecieveraddress() { return recieveraddress; }

	void setsendernumber(string sn)
	{
		senderaddress = sn;
	}
	string getsendernumber() { return sendernumber; }

	void setrecievernumber(string rn)
	{
		senderaddress = rn;
	}
	string getrecievernumber() { return recievernumber; }

	customer Customerlogin(customer cl) {
		cout << "-------//WELCOME TO THE POST OFFICE\\-------" << endl;
		cout << "       LOGGING IN TO CUSTOMER ACCOUNT     " << endl;
		cout << "Enter Firstname :" << endl;
		cin >> firstname;
		cout << "Enter Lastname :" << endl;
		cin >> lastname;
		cout << "Enter Customer ID :" << endl;
		cin >> customerID;
		cout << "Enter SenderAddress :" << endl;
		cin >> senderaddress;
		cout << "Enter Reciever Address :" << endl;
		cin >> recieveraddress;
		cout << "Enter Sender Number :" << endl;
		cin >> sendernumber;
		cout << "Enter Reciever Number :" << endl;
		cin >> recievernumber;
		cout << endl;
		fstream file;
		file.open("details.txt", ios::out | ios::app);
		file<<"First Name: " << firstname << " \n  Last Name: " << lastname << "  \n Customer Id:  " << customerID << "  \n  Sender Address: " << senderaddress << "   \n  Reciever Address:  " << recieveraddress << "   \n  SenderNumber: " << sendernumber << "    \n  RecieverNumber: " << recievernumber << "\n";
		file.close();
		return *this;

	}

	virtual void showdetails()
	{
		cout << "First Name :" << this->firstname << endl;
		cout << "Last Name :" << this->lastname << endl;
		cout << "Customer ID :" << this->customerID << endl;
		cout << "Sender Address :" << this->senderaddress << endl;
		cout << "Reciever Address :" << this->recieveraddress << endl;
		cout << "Sender Number :" << this->sendernumber << endl;
		cout << "Reciever Number :" << this->recievernumber << endl;


	}

};



class Invoice :public customer
{
public:

	int weight;
	string dimension;
	int shipmenttime;

	Invoice() {

		weight = 0;
		dimension = "2D";
		shipmenttime = 2;

	}

	Invoice(int w, string d, int st)
	{
		weight = w;

		dimension = d;
		shipmenttime = st;

	}

	void setweight() {
		cin >> weight;
	}
	int getweight() { return weight; }

	void setdimension(string d) {
		dimension = d;
	}
	string getdimension() { return dimension; }

	void setshipmenttime(int st) {
		shipmenttime = st;
	}
	int getshipmenttime() { return shipmenttime; }

	Invoice getinvoicedetails(customer inv) {

		int newweight;

		cout << endl;
		cout << "------//KINDLY FILL THE FOLLOWING INVOICE DETAILS//------" << endl << endl;
		cout << "Enter Weight :" << endl;
		setweight();
		newweight = getweight();
		cout << "Enter Dimensions :" << endl;
		cin >> dimension;
		cout << "Enter Shipment time :" << endl;
		cin >> shipmenttime;
		return *this;
		fstream file;
		file.open("details.txt", ios::out | ios::app);
		file << newweight << " " << dimension << " " << shipmenttime << "\n";
	}

	void showdetails()
	{
		cout << endl;
		cout << "Weight :" << this->weight << endl;
		cout << "Dimensions :" << this->dimension << endl;
		cout << "Shipment time :" << this->shipmenttime << endl;

	}

	void allshowdetails(customer c1)
	{
		cout << endl << endl;
		cout << "***ALL DETAILS REGARDING CUSTOMER AND INVOICE*** " << endl << endl;;
		cout << "First Name :" << c1.firstname << endl;
		cout << "Last Name :" << c1.lastname << endl;
		cout << "Customer ID :" << c1.customerID << endl;
		cout << "Sender Address :" << c1.senderaddress << endl;
		cout << "Reciever Address :" << c1.recieveraddress << endl;
		cout << "Sender Number :" << c1.sendernumber << endl;
		cout << "Reciever Number :" << c1.recievernumber << endl;
		cout << "Weight :" << weight << endl;
		cout << "Dimensions :" << dimension << endl;
		cout << "Shipment time :" << shipmenttime << endl;
	}

};


class Mail {
protected:
	string type;
	string servicetype;
public:
	void setmailtype() { cin >> type; }
	string getmailtype() { return type; }
	void setservicetype() { cin >> servicetype; }
	string getservicetype() { return servicetype; }
};


//PRICING USED FOR CALCULATING PRICE OF ORDER
class pricing
{
	Mail m1;
	Invoice inv;
	int price;
public:
	void pricecalculation(Invoice i1) {
		cout << "Enter Mail Type between Urgent and Regular:" << endl;
		m1.setmailtype();
		cout << "Enter Service type Between Local or City" << endl;
		m1.setservicetype();



		cout << endl;
		inv = i1;
		cout << endl;
		if (m1.getmailtype() == "Urgent" && m1.getservicetype() == "City" && inv.weight >= 30) {
			price = 875 + 86 + 75;
			cout << "Price :" << price;
		}
		else if (m1.getmailtype() == "Urgent" && m1.getservicetype() == "Local" && inv.weight >= 30) {
			price = 875 + 51 + 75;
			cout << "Price :" << price;
		}
		else if (m1.getmailtype() == "Regular" && m1.getservicetype() == "Local" && inv.weight >= 30) {
			price = 875 + 51;
			cout << "Price :" << price;
		}
		else if (m1.getmailtype() == "Regular" && m1.getservicetype() == "City" && inv.weight >= 30) {
			price = 875 + 86;
			cout << "Price :" << price;
		}

		else if (m1.getmailtype() == "Urgent" && m1.getservicetype() == "City" && inv.weight >= 15 && inv.weight < 30) {
			price = 500 + 86 + 75;
			cout << "Price :" << price;
		}
		else if (m1.getmailtype() == "Urgent" && m1.getservicetype() == "Local" && inv.weight >= 15 && inv.weight < 30) {
			price = 500 + 61 + 75;
			cout << "Price :" << price;
		}
		else if (m1.getmailtype() == "Regular" && m1.getservicetype() == "Local" && inv.weight >= 15 && inv.weight < 30) {
			price = 500 + 61;
			cout << "Price :" << price;
		}
		else if (m1.getmailtype() == "Regular" && m1.getservicetype() == "City" && inv.weight >= 15 && inv.weight < 30) {
			price = 500 + 85;
			cout << "Price :" << price;
		}
		else if (m1.getmailtype() == "Urgent" && m1.getservicetype() == "City" && inv.weight >= 0 && inv.weight <= 15) {
			price = 250 + 86 + 75;
			cout << "Price :" << price;
		}
		else if (m1.getmailtype() == "Urgent" && m1.getservicetype() == "Local" && inv.weight >= 0 && inv.weight <= 15) {
			price = 250 + 61 + 75;
			cout << "Price :" << price;
		}
		else if (m1.getmailtype() == "Regular" && m1.getservicetype() == "Local" && inv.weight >= 0 && inv.weight <= 15) {
			price = 250 + 61;
			cout << "Price :" << price;
		}
		else if (m1.getmailtype() == "Regular" && m1.getservicetype() == "City" && inv.weight >= 0 && inv.weight <= 15) {
			price = 250 + 85;
			cout << "Price :" << price;
		}

	}

};

class Employee :public Postoffice {
protected:
	string employeename;
	string employeeID;
	string employeepassword;
	string employeephonenumber;
	int employeeage;
public:

	void setemployeename(string en) {
		cout << "Enter Name" << endl;
		employeename = en;
	}
	string getemployeename() { return employeename; }
	void setemployeeID(string eid) {
		cout << "Enter Employee ID :" << endl;
		employeeID = eid;
	}
	string getemployeeID() { return employeeID; }
	void setemployeepassword(string ep) {
		cout << "Enter Employee Password :" << endl;
		employeepassword = ep;
	}
	string getemployeepassword() { return employeepassword; }
	void setemployeephonenumber(string epn) {
		cout << "Enter Employee Phone Number :" << endl;
		employeephonenumber = epn;
	}
	string getemployeephonenumber() { return employeephonenumber; }
	void setemployeeage(int a) {
		cout << "Enter Employee Phone Number :" << endl;
		employeeage = a;
	}
	int getemployeeage() { return employeeage; }
	Employee() {
		
	}
	Employee(string en, string eid, string epa, string epn, int ea)
	{
		employeename = en;
		employeeID = eid;
		employeepassword = epa;
		employeephonenumber = epn;
		employeeage = ea;

	}
	Employee getemployeedetails(Employee E) {
		cout << endl << "****WELCOME TO THE POST OFFICE DATABASE*****" << endl << "TAP TO LOGIN" << endl;
		cout << "Enter Your name" << endl;
		cin >> employeename;
		cout << "Enter Your ID" << endl;
		cin >> employeeID;
		cout << "Enter Your Password" << endl;
		cin >> employeepassword;
		cout << endl << "***LOGGED IN SUCCESSFULLYY***" << "TAP TO VERIFY YOUR PHONE NUMBER" << endl << endl;
		cout << "Enter Your updated PhoneNumber" << endl;
		cin >> employeephonenumber;
		cout << "Last but not the least!" << endl << "Your age please" << endl;
		cin >> employeeage;
		return *this;
	}
	Employee createemployee(Employee CE) {
		cout << endl << "****WELCOME TO THE POST OFFICE SIGN UP*****" << endl << "TAP TO CREATE AN ACCOUNT" << endl;
		cout << "Enter Your name" << endl;
		cin >> employeename;
		cout << "Make Your ID" << endl;
		cin >> employeeID;
		cout << "Create Your Password" << endl;
		cin >> employeepassword;
		cout << endl << "***ACCOUNT CREATED SUCCESSFULLY***" << "TAP TO VERIFY YOUR PHONE NUMBER" << endl << endl;
		cout << "Enter Your PhoneNumber" << endl;
		cin >> employeephonenumber;
		cout << "Last but not the least!" << endl << "Your age please" << endl;
		cin >> employeeage;
		return *this;
	}



	void showdemployeedetails()
	{
		cout << endl;
		cout << "Name :" << this->employeename << endl;
		cout << "ID :" << this->employeeID << endl;
		cout << "Password :" << "*********" << endl;
		cout << "PhoneNumber :" << this->employeephonenumber << endl;
		cout << "Age :" << this->employeeage << endl;

	}

	Employee UpdateEmployee(Employee E) {
		cout << "****UPDATING EMPLOYEE DETAILS****" << endl;
		cout << "ReEnter Your New name" << endl;
		cin >> employeename;
		cout << "Make Your New ID" << endl;
		cin >> employeeID;
		cout << "Create Your New Password" << endl;
		cin >> employeepassword;
		cout << endl << "***ACCOUNT CREATED SUCCESSFULLY***" << "TAP TO VERIFY YOUR PHONE NUMBER" << endl << endl;
		cout << "Enter Your New PhoneNumber" << endl;
		cin >> employeephonenumber;
		cout << "Last but not the least!" << endl << "Your age please" << endl;
		cin >> employeeage;
		return *this;
	}
};

class Head {
protected:
	Employee emp;
	string decision;
public:
	void makeemployee(string decision) {
		cout << "***RESPECTABLE HEAD DO YOU WANT TO HIRE AN EMPLOYEE?***" << endl << "Please answer with a Yes or a No" << endl;
		cin >> decision;
		if (decision == "Yes") {
			emp.createemployee(emp);
			cout << endl;
			emp.showdemployeedetails();
		}
		else if (decision == "No") {
		cout << "Acknowledged Sir" << endl;
		}

	}

	void HeadUpdateemployee(string decision) {
		cout << " ***RESPECTABLE HEAD DO YOU WANT TO UPDATE AN EMPLOYEE ? ***" << endl << "Please answer with a Yes or a No" << endl;
		cin >> decision;
		if (decision == "Yes") {
			emp.UpdateEmployee(emp);
			cout << endl;
			emp.showdemployeedetails();
		}
		else if (decision == "No")
			cout << "Acknowledged Sir" << endl;
	}

	void showdheademployeedetails()
	{
		cout << endl;
		emp.showdemployeedetails();

	}

};

class clerk :public Employee {
public:
	clerk();
	clerk(string en, string eid, string ep, string epn, int ea) :Employee(en, eid, epn, epn, ea) {

	}


};


class accountofficer :public Employee
{
public:
	accountofficer();
	accountofficer(string en, string eid, string ep, string epn, int ea) :Employee(en, eid, epn, epn, ea) {
	}

};

class postman :public Employee
{
public:
	postman();
	postman(string en, string eid, string ep, string epn, int ea) :Employee(en, eid, epn, epn, ea) {
	}

};

int main() {
	string choice;
	cout << "WELCOME TO THE POST OFFICE" << endl;
	cout << "Are you a customer or an Employee?" << endl << "Choose 1 for Customer and 2 for Employee" << endl;
	cin >> choice;
	if (choice == "1")
	{
		customer c1;
		c1.Customerlogin(c1);
		c1.showdetails();
		cout << endl;
		Invoice i1;
		i1.getinvoicedetails(c1);
		i1.allshowdetails(c1);
		pricing p1;
		p1.pricecalculation(i1);
	}
	else if (choice == "2") {
		Employee E1;
		E1.getemployeedetails(E1);
		E1.showdemployeedetails();
		Head H1;
		H1.makeemployee("Yes");
		H1.HeadUpdateemployee("Yes");
		H1.showdheademployeedetails();


	}

}





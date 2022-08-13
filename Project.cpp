#include<iostream>
#include<conio.h>
#include<fstream> // for file handling
#include<stdio.h>
#include<stdlib.h>// for getch() function standard library function
#include<string> // for string data members
//#include<dos.h>


using namespace std;
class Customer
{
public:
string name,address;
char phone[12];
char from_date[20];
char to_date[20];
float payment_advance;
int booking_id;
Customer(){//default constructor
string name="Mishal,Mahnoor";
string address="Lahore";
}

//Setters and Getters 
string getName()    {
return name;
}
        string getAddress() {
		return address;
		}
		char getPhone()
		{
			return phone[12];
		}
		int getBookingId()
		{
			return booking_id;
		}
		float getPaymentadvance()
		{
			return payment_advance;
		}
		
		void setName(string name)       { 
		this -> name = name;
		}
        void setAddress(string address) {
		 this -> address = address;
		 }  
		 void setBookingid(int ID)
		 {
		 	ID=booking_id;
		  } 
		  void setPaymentadvance(float p)
		  {
		  	p=payment_advance;
		  }
		  void setPhone(char p)
		  {
		  	p=phone[12];
		  }

		

};

class Room
{
   public:
   char type;//single or non-single
char size_type;//size of room big/small
char ac;//ac room or non_ac
int roomNumber;
int rent;
int status; // to check that customer is 0 or 1
Room() //default constructor
{
}
Room(char t,char size,char ac,int rno,int r,int s) // parametrized constructor
{
	t=type;
	size=size_type;
	rno=roomNumber;
	r=rent;
	s=status;	
}
class Customer cust;//object of customer class(containership)
void addRoom();
void Roomsalotted(); //function of all rooms occupied
void DisplayRoom();
int check(int);// function to check Room status 
	
};
//class Room rooms[max];// allocating 100 rooms 
void Room::addRoom()//adding room
{
	int r;
	cout<<"\n Total no. of Rooms - 50";
cout<<"\n Ordinary Rooms from 1 - 30";
cout<<"\n Luxuary Rooms from 31 - 45";
cout<<"\n Royal Rooms from 46 - 50";
cout <<"\n Enter The Room no. you want to stay in :- "<<endl;
cin>>r;
	
}
void Room::Roomsalotted() // display data of room occupied
{
	system("cls");

ifstream fin("Record.dat",ios::in);
cout<<"\n\t\t\t    List Of Rooms Allotted";
cout<<"\n\t\t\t    ----------------------";
cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\n";

while(!fin.eof())
{

fin.read((char*)this,sizeof(Room));
cout<<"\n\n "<<roomNumber<<"\t\t"<<cust.name;
cout<<"\t\t"<<cust.address<<"\t\t"<<cust.phone;

}

cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
getch();
fin.close();

}

void Room::DisplayRoom() //display particular customer details
{

  system("cls");

ifstream fin("Record.dat",ios::in);
int r,flag;

cout<<"\n Enter room no. for a particular customer`s details :- "<<endl;
cin>>roomNumber;

while(!fin.eof())
{

fin.read((char*)this,sizeof(Room));
if(roomNumber==r)
{

  system("cls");
cout<<"\n Cusromer Details";
cout<<"\n ----------------";
cout<<"\n\n Room no: "<<roomNumber;
cout<<"\n Name: "<<cust.name;
cout<<"\n Address: "<<cust.address;
cout<<"\n Phone no: "<<cust.phone;
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant....!!";
cout<<"\n\n Press any key to continue....!!";

getch();
fin.close();
}


int Room::check(int r)//Function to check status of Room that guest is in room or not
{

int flag=0;

ifstream fin("Record.dat",ios::in);

while(!fin.eof())
{

fin.read((char*)this,sizeof(Room));
if(roomNumber==r)
{

flag=1;
break;

}

}

fin.close();
return(flag);

}

class HotelManagement:protected Room //child class
{
	public:
	void checkIn();
    void editrecord();
    void modifyRecord(int);		//to modify the record
void delete_rec(int);
    void checkOut(int);
    
};
void HotelManagement::checkIn() // Function to check-in room
{

system("cls");
int r,flag;
ofstream fout("Record.dat",ios::app);

cout<<"\n Enter room no. for check-in:- "<<endl;
cin>>r;

flag=check(r);//calling function of check roomstatus to check room is available or not     

if(flag)
cout<<"\n Sorry..!!!Room is already booked";

else
{

roomNumber=r;
cout<<"\nEnter booking id: ";
cin>>cust.booking_id;

cout<<"\nEnter Customer Name (First Name): ";
cin>>cust.name;

cout<<"\nEnter Address (only city): ";
cin>>cust.address;

cout<<"\nEnter Phone: ";
cin>>cust.phone;

cout<<"\nEnter From Date: ";
cin>>cust.from_date;

cout<<"\nEnter to  Date: ";
cin>>cust.to_date;


cout<<"\nEnter Advance Payment: ";
cin>>cust.payment_advance;


fout.write((char*)this,sizeof(HotelManagement));
cout<<"\n Room is booked...!!!";

}

cout<<"\n Press any key to continue.....!!";

getch();
fout.close();

}

void HotelManagement::editrecord()
{

  system("cls");

int choice,r;
cout<<"\n EDIT MENU";
cout<<"\n ---------";
cout<<"\n\n 1.Modify Customer Record";
cout<<"\n 2.Delete Customer Record";
cout<<"\n 3. Check-Out";
cout<<"\n Enter your choice: ";

cin>>choice;
  system("cls");

cout<<"\n Enter room no: " ;
cin>>r;

switch(choice)
{

case 1:	modifyRecord(r);
break;

case 2:	delete_rec(r);
break;

case 3: checkOut(r);
break;

default: cout<<"\n Wrong Choice.....!!";

}
cout<<"\n Press any key to continue....!!!";

getch();
}

//FUNCTION TO MODIFY CUSTOMERS RECORD


void HotelManagement::modifyRecord(int r)
{

long pos,flag=0;

fstream file("Record.dat",ios::in|ios::out|ios::binary);

while(!file.eof())
{

pos=file.tellg();
file.read((char*)this,sizeof(HotelManagement));

if(roomNumber==r)
{

cout<<"\n Enter New Details";
cout<<"\n -----------------";
cout<<"\n Name: ";
cin>>cust.name;
cout<<" Address: ";
cin>>cust.address;
cout<<" Phone no: ";
cin>>cust.phone;
file.seekg(pos);
file.write((char*)this,sizeof(HotelManagement));
cout<<"\n Record is modified....!!";
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant...!!";
file.close();

}

void HotelManagement::delete_rec(int r) //Delete customer record
{

int flag=0;
char ch;
ifstream fin("Record.dat",ios::in);
ofstream fout("temp.dat",ios::out);

while(!fin.eof())
{

fin.read((char*)this,sizeof(HotelManagement));
if(roomNumber==r)

{

cout<<"\n Name: "<<cust.name;
cout<<"\n Address: "<<cust.address;
cout<<"\n Pone No: "<<cust.phone;
cout<<"\n\n Do you want to delete this record(y/n): ";
cin>>ch;

if(ch=='n')
fout.write((char*)this,sizeof(HotelManagement));
flag=1;

}

else
fout.write((char*)this,sizeof(HotelManagement));

}

fin.close();
fout.close();

if(flag==0)
cout<<"\n Sorry room no. not found or vacant...!!";

else
{

remove("Record.dat");
rename("temp.dat","Record.dat");

}

}
//hotel managemt generates the bill of the expenses
void HotelManagement::checkOut(int Roomnum)
{
int i,found=0,days,rno;
float billAmount=0;

cout<<"\nEnter Number of Days:\t";
cin>>days;
billAmount=days*rent; //formula for calculating bill amount

cout<<"\n\t######## CheckOut Details ########\n";
cout<<"\nCustomer Name : "<<cust.name;
cout<<"\nRoom Number : "<<roomNumber;
cout<<"\nAddress : "<<cust.address;
cout<<"\nPhone : "<<cust.phone;
cout<<"\nTotal Amount Due : "<<billAmount<<" /";
cout<<"\nAdvance Paid: "<<cust.payment_advance<<" /";
cout<<"\n*** Total Payable: "<<billAmount<<cust.payment_advance<<"/ only";


getch();
}

int main()
{
	system("cls");
	Room r;
	HotelManagement hm;
	

cout<<"\n\t\t\t****************************";
cout<<"\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
cout<<"\n\t\t\t****************************";
cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
int choice;
while(choice!=5)
{

  system("cls");
cout<<"\n\t\t\t\t*************************";
cout<<"\n\t\t\t\t HOTEL MANAGEMENT SYSTEM!!! ";
cout<<"\n\t\t\t\t      * MAIN MENU *";
cout<<"\n\t\t\t\t*************************";
cout<<"\n\n\n\t\t\t1.Add Rooms";
cout<<"\n\t\t\t2.Check-In Room";
cout<<"\n\t\t\t3.Rooms Allotted";
cout<<"\n\t\t\t4.Search Customer Record";
cout<<"\n\t\t\t5.Edit Record";
cout<<"\n\n\t\t\tEnter Your Choice: ";
cin>>choice;

switch(choice)
{

case 1:
 r.addRoom();
break;

case 2:
 hm.checkIn();
break;

case 3: 
r.Roomsalotted();
break;

case 4:	
r.DisplayRoom();
break;

case 5: 
hm.editrecord();
break;
case 6:
	getch();
	

default:
{

cout<<"\n\n\t\t\tWrong choice.....!!!";
cout<<"\n\t\t\tPress any key to   continue....!!";
getch();

}

}

}

}

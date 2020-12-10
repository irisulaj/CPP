#include<iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>

using namespace std;
class trip
{
int trip_no;
char name[30];
char address[50];
char phone[10];
char trip_date_hour[30];
public:
void main_menu(); //show main menu
void add(); // add a trip
void display(); //display traveler's data
void booked_trips(); //display booked trips
void edit(); //update traveler's data
int check(int); //check trip's status
void modify(int); //modify the data
void delete_rec(int); //delete the data
};
void trip::main_menu()
{
int choice;
while(choice!=5)
{
cout<<"\n\t-----------------------";
cout<<"\n\t MAIN MENU ";
cout<<"\n\t------------------------";
cout<<"\n\t1.Book a trip";
cout<<"\n\t2.Traveler's Data";
cout<<"\n\t3.Booked Trips";cout<<"\n\t4.Update the data";
cout<<"\n\t5.Exit Menu";
cout<<"\n\t Press your option: ";
cin>>choice;
switch(choice)
{
case 1: add();
break;
case 2: display();
break;
case 3: booked_trips();
break;
case 4: edit();
break;
case 5: break;
default:
{
cout<<"\n Invalid option!";
cout<<"\n Press any key to continue...!";
getch();
}}
}}

void trip::add()
{
    
int r,flag;
ofstream fout("Savedata.txt",ios::app);
cout<<"\n ";
cout<<"\n ----------------------";
cout<<"\n\n Trip Number: ";
cin>>r;
flag=check(r);
if(flag)
cout<<"\n Sorry! There are no remaining seats for this trip";
else
{
trip_no=r;
cout<<" Name: ";
gets(name);
cout<<" Adress: ";
gets(address);
cout<<" \n Phone_no: ";
gets(phone);
cout<<"\n Date and Hour of the trip: ";
gets(trip_date_hour);
fout.write((char*)this,sizeof(trip));
cout<<"\n Trip booked...!";
}
cout<<"\n Press any key to continue...!";
getch();
fout.close();
}void trip::display()
{ifstream fin("Savedata.txt",ios::in);
int r,flag;
cout<<"\n Press trip no : ";
cin>>r;
while(!fin.eof())
{
fin.read((char*)this,sizeof(trip));
if(trip_no==r)
{
cout<<"\n Traveler's data'";
cout<<"\n ----------------";
cout<<"\n\n Trip No: "<<trip_no;
cout<<"\n\n Name: "<<name;
cout<<"\n \n Adress: "<<address;
cout<<"\n \n Phone_no: "<<phone;
cout<<"\n\nDate and hour of the trip: "<<trip_date_hour;
flag=1;
break;
}
}
if(flag==0)
cout<<"\n Sorry, trip number was not found, or there are no bookings for this trip...!";
cout<<"\n\n Press any key to continue...!";
getch();
fin.close();
}
void trip::booked_trips()
{
ifstream fin("Savedata.txt",ios::in);
cout<<"\n\t\t\t List of booked trips";
cout<<"\n\t\t\t ----------------------";
cout<<"\n\n Trip_no\tName\t\tAdress\t\t\t\tPhone_no\n \t\t\tDate and hour of the trip:";
while(!fin.eof())
{
fin.read((char*)this,sizeof(trip));
cout<<"\n\n "<<trip_no<<"\t\t"<<name;
cout<<"\t\t"<<address<<"\t\t"<<phone<<"\n\n"<<trip_date_hour;
}
cout<<"\n\n\n\t\t\tPress any key to continue...!";
getch();
fin.close();
}
void trip::edit()
{
int choice,r;
cout<<"\n MODIFY MENU";
cout<<"\n ---------";
cout<<"\n\n 1.Modify traveler's data";
cout<<"\n 2.Delete traveler's data'";
cout<<"\n Choose your option: ";
cin>>choice;
cout<<"\n Enter trip no: " ;
cin>>r;
switch(choice)
{
case 1: modify(r);
break;
case 2: delete_rec(r);
break;
default: cout<<"\n Unknown option...!";
}
cout<<"\n Press any key to continue...!";
getch();
}
int trip::check(int r)
{
int flag=0;
ifstream fin("Savedata.txt",ios::in);
while(!fin.eof())
{
fin.read((char*)this,sizeof(trip));
if(trip_no==r)
{
flag=1;
break;
}
}fin.close();
return(flag);
}
void trip::modify(int r)
{
long pos,flag=0;
fstream file("Savedata.txt",ios::in|ios::out|ios::binary);
while(!file.eof())
{
pos=file.tellg();
file.read((char*)this,sizeof(trip));
if(trip_no==r)
{
cout<<"\n Add the new data";
cout<<"\n -----------------";
cout<<"\n Name: ";
gets(name);
cout<<" \n Adress: ";
gets(address);
cout<<" \n Phone_no: ";
gets(phone);
cout<<"\n Date and hour of the trip: ";
gets(trip_date_hour);
file.seekg(pos);
file.write((char*)this,sizeof(trip));
cout<<"\n The data are now modified....!";
flag=1;
break;
}}
if(flag==0)
cout<<"\n Sorry, trip number was not found, or there are no bookings for this trip...!";
file.close();
}
void trip::delete_rec(int r)
{
int flag=0;
char ch;
ifstream fin("Savedata.txt",ios::in);
ofstream fout("temp.txt",ios::out);
while(!fin.eof())
{
fin.read((char*)this,sizeof(trip));
if(trip_no==r)
{
cout<<"\n Name: "<<name;
cout<<"\n Adress: "<<address;
cout<<"\n Phone_no: "<<phone;
cout<<"\n Data and hour of the trip: "<<trip_date_hour;
cout<<"\n\n Do you want to delete the data?(y/n): ";
cin>>ch;
if(ch=='n')
fout.write((char*)this,sizeof(trip));
flag=1;
}
else
fout.write((char*)this,sizeof(trip));
}
fin.close();
fout.close();
if(flag==0)
cout<<"\n Sorry, trip number was not found, or there are no bookings for this trip...!";
else
{
remove("Savedata.txt");
rename("temp.txt","Savedata.txt");
}
}
main()
{
trip t;
system("color Af");
cout<<"\n\t----------------------------------------------------";
cout<<"\n\t* TRAVEL AGENCY MANAGEMENT SYSTEM *";
cout<<"\n\t----------------------------------------------------";
cout<<"\n\n\t *DEVELOPED BY: Shaqir Sulaj";

cout<<"\n\n\t *Press any key to continue...!";
getch();
t.main_menu();
}

/*This is a program based on Airline Ticket booking in Kempegowda international airport*/

//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<iomanip.h>
#include<process.h>
#include<stdio.h>
#include<dos.h>

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class Airport
{
 char fno[10];           // Flight number
 char airline[40];       // Name of Airline
 char destination[50];  //  Destination
 int hr,min;            //  Departure Time in hours and min
 public:
  void read();         // Function prototype to read data members of class Airport
  void display();      // Function prototype to print data members of class Airport
  char* rair()         // Function that returns Airline
  {
   return airline;
  }
  char* rdest()        // Function that returns Destination
  {
   return destination;
  }
  char* rfno()         // Function that returns Flight Number
  {
   return fno;
  }
};

void Airport::read()  // Function Definition to read data members of class Airport
{
 cout<<"\nEnter the Flight No:";
 cin>>fno;
 cout<<"\nEnter the Name of the Airline:";
 gets(airline);
 cout<<"\nEnter the Airline's Destination:";
 gets(destination);
 cout<<"\nEnter the Time of Departure";
 cout<<"\n\nHours:";cin>>hr;
 cout<<"\nMinutes:";cin>>min;
}

void Airport::display()     // Function Definition to print data members of class Airport
{
 cout<<"\n\nFlight No: "<<fno;
 cout<<"\nFlight Name: "<<airline;
 cout<<"\nDestination: "<<destination;
 cout<<"\nTime of Departure: "<<hr<<":"<<min;
}

void writetofile()     // Function that writes data of class Airport to file
{
 clrscr();
 char ch;
 Airport a;
 ofstream fout;
 fout.open("airsystem.dat",ios::binary|ios::app);
 if(!fout)
  cout<<"\nError in opening";
 else
 {
  do
  {
   a.read();
   fout.write((char*)&a,sizeof(a));
   cout<<"\nDo you want to Add more(Y/N):";
   cin>>ch;
  }while(ch=='y'||ch=='Y');
  fout.close();
 }
 getch();
}

void readfromfile()   // Function that reads data of class Airport from file
{
 clrscr();
 Airport a;
 ifstream fin;
 fin.open("airsystem.dat",ios::binary);
 if(!fin)
  cout<<"\nError in opening";
 else
 {
  while(fin.read((char*)&a,sizeof(a)))
  {
  a.display();
  }
	fin.close();
 }
 getch();
}

void searchfromfile()  // Function that searches data of class Airport from file
{
 clrscr();
 Airport a;
 ifstream fin;
 fin.open("airsystem.dat",ios::binary);
 int found=0;
 char code[40];
 cout<<"\nEnter the Flight No. you want to search:";
 gets(code);
  if(!fin)
  cout<<"\nError in opening";
 else
 {
  while(fin.read((char*)&a,sizeof(a)))
  {
   if(strcmpi(a.rfno(),code)==0)
   {
    a.display();
    found=1;
   }
  }
  if(found==0)
   cout<<"\n!!!No Record Found!!!";
 }
 fin.close();
 getch();
}

void modifyfile()   // Function that modifies data of class Airport in the file
{
 clrscr();
 Airport a;
 ifstream fin("airsystem.dat",ios::binary);
 ofstream fout("Temp.dat",ios::binary);
 int found=0;
 char code[40];
 cout<<"\nEnter the Flight No. you want to modify:";
 gets(code);
 if(!fin)
  cout<<"\nError in opening";
 else
 {
  while(fin.read((char*)&a,sizeof(a)))
  {
   if(strcmpi(a.rfno(),code)==0)
   {
    a.display();
    found=1;
    cout<<"\nEnter New Data:";
    a.read();
    fout.write((char*)&a,sizeof(a));
   }
   else
   {
    fout.write((char*)&a,sizeof(a));
   }
  }
  if(found==0)
   cout<<"\n!!!No Record Found!!!";
 }
 fin.close();
 fout.close();
 remove("airsystem.dat");
 rename("Temp.dat","airsystem.dat");
 getch();
}

void deletefromfile()  // Function that deletes data of class Airport from file
{
 clrscr();
 Airport a;
 ifstream fin("airsystem.dat",ios::binary);
 ofstream fout("Temp.dat",ios::binary);
 int found=0;
 char code[40];
 cout<<"\nEnter the Flight No. you want to delete:";
 gets(code);
 if(!fin)
  cout<<"\nError in opening";
 else
 {
  while(fin.read((char*)&a,sizeof(a)))
  {
   if(strcmpi(a.rfno(),code)==0)
   {
    a.display();
    found=1;
   }
   else
   {
    fout.write((char*)&a,sizeof(a));
   }
  }
  if(found==0)
   cout<<"\n!!!No Record Found!!!";
 }
 fin.close();
 fout.close();
 remove("airsystem.dat");
 rename("Temp.dat","airsystem.dat");
 getch();
}

void maindesign()  // Function for Displaying Main Design of the project
{
 clrscr();
 cout<<"\n\n\n\n\n    *** *** *   * *** * * *** *** ***    *** *** *** *** *   * *** ***";
 cout<<"\n    *   * * ** ** * * * *  *  *   * *    *   *    *  *   **  * *   *";
 cout<<"\n    *   * * * * * *** * *  *  *** ***    *** *    *  *** * * * *   ***";
 cout<<"\n    *   * * *   * *   * *  *  *   **       * *    *  *   *  ** *   *";
 cout<<"\n    *** *** *   * *   ***  *  *** * *    *** *** *** *** *   * *** ***";
 cout<<"\n\n\t\t\t*** *** *** *** *** *** ***";
 cout<<"\n\t\t\t* * * * * *  *  *   *    * ";
 cout<<"\n\t\t\t*** *** * *  *  *** *    * ";
 cout<<"\n\t\t\t*   **  * *  *  *   *    * ";
 cout<<"\n\t\t\t*   * * *** **  *** ***  * ";
 sleep(2);
 cout<<"\n\n\n\t\t\t\tB Y :- L Akash.";
 cout<<"\n\n\t\t\tPress any key to continue... ";
 getch();
}

void thanks()   // Function for Displaying Thanks in the project
{
 clrscr();
 cout<<"\n\n\n\n\t\tHHHHH H   H   H   H   H H  H   H   H HHHHH H   H    ";
 cout<<"\n\t\t  H   H   H H   H HH  H H H    H   H H   H H   H    ";
 cout<<"\n\t\t  H   HHHHH HHHHH H H H HH      H H  H   H H   H    ";
 cout<<"\n\t\t  H   H   H H   H H  HH H H      H   H   H H   H    ";
 cout<<"\n\t\t  H   H   H H   H H   H H  H     H   HHHHH  HHH   HH";
 getch();
}

int k=1;

void search(char* code)    // Function for searching user destinaiton with program
{
 clrscr();
 Airport a;
 ifstream fin;
 fin.open("airsystem.dat",ios::binary);
 int found=0;

  if(!fin)
  cout<<"\nError in opening";
 else
 {
  while(fin.read((char*)&a,sizeof(a)))
  {
   if(strcmpi(a.rdest(),code)==0)
   {
    cout<<"\n\n"<<k<<".";
    a.display();
    k=k++;
    found=1;
   }
  }
  if(found==0)
   cout<<"\n!!!No Such Destination FOUND!!!";
 }
 fin.close();
 getch();
}

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class booking
{
 protected:
  char firstname[60];      // First Name of the Ticket Purchaser
  char lastname[60];       // Last Name of the Ticket Purchaser
  char address[60];        // Address of the Ticket Purchaser
  char c_loc[30];          // Current location of the Ticket Purchaser
  char dest[30];           // Destination of the Ticket Purchaser
  char reservation_no[60]; // Passport Number of the Ticket Purchaser
 public:
  int t;                   // Ticket number
  int r;                   //Refernce number
  char Date[20];           // Date of Journey
  char flight[40];         // Flight Name

  char* rname()            //Function to return First name of class booking
  {
   return firstname;
  }

  booking()                //Constructor to initialize values of Data members of class booking
  {
   strcpy(c_loc,"Bangalore");
   t=1;
   r=001;
  }

 void searchdest(char* code,char* opd);  // Function Prototype for Matching Destination fo user and program

 void getdata()             // Function to read Data members of class booking
 {
  char op[10];
  cout<<"\n\n\t\t@@ENTER PASSENGERS DETAILS@@";
  cout<<"\n\n\n\nEnter Date of Journey:";
  cin>>Date;
  cout<<"\n\nEnter the First Name of passenger:";
  cin.getline(firstname,60);
  cin.getline(firstname,60);
  cout<<"\n\nEnter the Last Name of passenger: ";
  cin.getline(lastname,60);
  cout<<endl;
  cout<<"\nEnter address of passenger:  ";
  cin.getline(address,60);
  cout<<endl;
  cout<<"\nEnter Your Passport No.:";
  cin.getline(reservation_no,60);
  cout<<endl;
  cout<<"\nEnter the destination of passenger(IN CAPITAL LETTERS ONLY):  ";
  cin.getline(dest,60);
  cout<<endl<<endl;
  search(dest);
  cout<<"\n\nEnter the Flight no. which you want to go:";
  cin>>op;
  searchdest(dest,op);
  system("CLS");
  }

 void show()         //Function to print Data members of class booking
 {
  cout<<"\n### Your E-Ticket ###:"<<endl;
  cout<<"                          *****AIR  TICKET*****                                 "<<endl;
  cout<<"|Ticket No."<<t<<"                                Reference No."<<r<<"\t  "<<endl;
  cout<<"|_________________________________________________________________________"<<endl;
  cout<<"|Passport No. :"<<reservation_no<<"                                     "<<endl;
  cout<<"|__________________________________________________________________________"<<endl;
  cout<<"|Passenger Information :                                                  "<<endl;
  cout<<"|Name :"<<firstname<<"/"<<lastname<<"                                     "<<endl;
  cout<<"|                                                                         "<<endl;
  cout<<"|Address :"<<address<<"                                                   "<<endl;
  cout<<"|_________________________________________________________________________"<<endl;
  cout<<"|flight Information :                                                     "<<endl;
  cout<<"|Date:"<<Date<<"                                                              "<<endl;
  cout<<"|Airline:"<<flight<<"                                                                "<<endl;
  cout<<"|_________________________________________________________________________"<<endl;
  cout<<"|Depart :"<<c_loc<<"                                                      "<<endl;
  cout<<"|Arrive :"<<dest<<"                                                       "<<endl;
  cout<<"|*BAGGAGE allowed 40 Kilos                                                "<<endl;
  cout<<"|*contact Airline to Confirm baggage allowance                            "<<endl;
  cout<<"|_________________________________________________________________________"<<endl;
  cout<<"\n!!!!Have a safe journey !!!!";
 t++;
 r++;
 }
};

void booking::searchdest(char* code,char* opd)    // Function Definition for Matching Destination fo user and program
{
 clrscr();
 Airport a;
 ifstream fin;
 fin.open("airsystem.dat",ios::binary);
   if(!fin)
  cout<<"\nError in opening";
 else
 {
  while(fin.read((char*)&a,sizeof(a)))
  {
   if(strcmpi(a.rdest(),code)==0)
   {
   if(strcmpi(opd,a.rfno())==0)
   {
   strcpy(flight,a.rair());
   }
   }
  }
 }
 fin.close();
 getch();
}

void writefile()    // Function that writes data of class booking to file
{
 clrscr();
 char ch;
 booking b;
 ofstream fout;
 fout.open("booksystem.dat",ios::binary|ios::app);
 if(!fout)
  cout<<"\nError in opening";
 else
 {
  do
  {
   cout<<"\nInseting the New Record...";
   b.getdata();
   fout.write((char*)&b,sizeof(b));
   cout<<"\nDo you Book more Ticket(Y/N):";
   cin>>ch;
  }while(ch=='y'||ch=='Y');
  fout.close();
 }
 getch();
}

void readfile()   // Function that reads data of class Airport from file
{
 clrscr();
 booking b;
 ifstream fin;
 fin.open("booksystem.dat",ios::binary);
 if(!fin)
  cout<<"\nError in opening";
 else
 {
  cout<<"\nList of Record...";
  while(fin.read((char*)&b,sizeof(b)))
  {
  b.show();
  }
  fin.close();
 }
 getch();
}

void searchfile()   // Function that searches data of class booking from file
{
 clrscr();
 booking b;
 ifstream fin;
 fin.open("booksystem.dat",ios::binary);
  int found=0;
 char code[40];
 cout<<"\nEnter Person's Name whose Ticket is to be Printed:";
 gets(code);
  if(!fin)
  cout<<"\nError in opening";
 else
 {
  cout<<"\nSearching for Record...";
  while(fin.read((char*)&b,sizeof(b)))
  {
   if(strcmpi(b.rname(),code)==0)
   {
    b.show();
    found=1;
   }
  }
  if(found==0)
   cout<<"\n!!!No Record Found!!!";
 }
 fin.close();
 getch();
}

void modifyingfile()  // Function that modifies data of class booking in the file
{
 clrscr();
 booking b;
 ifstream fin("booksystem.dat",ios::binary);
 ofstream fout("Temp.dat",ios::binary);
 int found=0;
 char code[40];
 cout<<"\nEnter Person's Name whose Detail is to be modified:";
 gets(code);
 if(!fin)
  cout<<"\nError in opening";
 else
 {
  while(fin.read((char*)&b,sizeof(b)))
  {
   if(strcmpi(b.rname(),code)==0)
   {
    cout<<"\nUpdating the Record...";
    b.show();
    found=1;
    cout<<"\nEnter New Data:";
    b.getdata();
    fout.write((char*)&b,sizeof(b));
   }
   else
   {
    fout.write((char*)&b,sizeof(b));
   }
  }
  if(found==0)
   cout<<"\n!!!No Record Found!!!";
 }
 fin.close();
 fout.close();
 remove("booksystem.dat");
 rename("Temp.dat","booksystem.dat");
 getch();
}

void deletefile()    // Function that Deletes data of class booking in the file
{
 clrscr();
 booking b;
 ifstream fin("booksystem.dat",ios::binary);
 ofstream fout("Temp.dat",ios::binary);
 int found=0;
 char code[40];
 cout<<"\nEnter Person's Name whose Ticket is to be Cancelled:";
 gets(code);
 if(!fin)
  cout<<"\nError in opening";
 else
 {
  while(fin.read((char*)&b,sizeof(b)))
  {
   if(strcmpi(b.rname(),code)==0)
   {
    cout<<"\nDeleting the Record...";
    b.show();
    found=1;
   }
   else
   {
    fout.write((char*)&b,sizeof(b));
   }
  }
  if(found==0)
   cout<<"\n!!!No Record Found!!!";
 }
 fin.close();
 fout.close();
 remove("booksystem.dat");
 rename("Temp.dat","booksystem.dat");
 getch();
}

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

void main()
{
 window(1,1,80,50);    //functions for:
 textbackground(4);    // Background Color
 textcolor(9);         // Text Color
 gotoxy(1,1);
 maindesign();        // Calling of Function maindesign()
 clrscr();
 char username[50];
 int password;
 int opt;
 int pass;
 booking b;
 window(1,1,80,50);    //functions for:
 textbackground(4);    // Background Color
 textcolor(14);         // Text Color
 gotoxy(1,1);
 cout<<"\n\n\n\n\t\t**************************************";
 cout<<"\n\t\t   KEMPEGOWDA INTERNATIONAL AIRPORT";
 cout<<"\n\t\t**************************************";
 cout<<"\n\n\t\t  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
 cout<<"\n\t\t         ADMINISTATOR LOGIN         ";
 cout<<"\n\t\t  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
 cout<<"\n\n\t\tUSERNAME:";
 gets(username);
 cout<<"\n\n\t\tPASSWORD:";
 cin>>password;
 cout<<"\n\t\t\t---------";
 cout<<"\n\t\t\t| LOGIN |";
 cout<<"\n\t\t\t---------";
 cout<<"\n\t\tPress ENTER key to Continue...";
 getch();
 if(strcmpi(username,"Staff 1")==0 || strcmpi(username,"staff")==0 || strcmpi(username,"akash")==0)
 {
  if((password==12345))
  {
   clrscr();
   while(1)
   {
   clrscr();
   cout<<"\n\n\n\n\t\t**************************************";
   cout<<"\n\t\t   KEMPEGOWDA INTERNATIONAL AIRPORT";
   cout<<"\n\t\t**************************************";
   cout<<"\n\n\t\t1.Ticket Booking";
   cout<<"\n\t\t2.Ticket Printing";
   cout<<"\n\t\t3.Update Ticket Details";
   cout<<"\n\t\t4.Ticket Cancellation";
   cout<<"\n\t\t5.Check Flight Details";
   cout<<"\n\t\t6.Administration Login";
   cout<<"\n\t\t7.Exit";
   cout<<"\n\t\t**************************************";
   cout<<"\n\t\tEnter your Option:";
   cin>>opt;
   window(1,1,80,50);    //functions for:
   textbackground(5);    // Background Color
   textcolor(14);         // Text Color
   gotoxy(1,1);
   switch(opt)     //Switch case for Main program
   {
    case 1: clrscr();
	    writefile();    // Calling of Function writefile()
	    break;
    case 2: clrscr();
	    int s;
	    window(1,1,80,50);    //functions for:
	    textbackground(5);    // Background Color
	    textcolor(14);         // Text Color
	    gotoxy(1,1);
	    cout<<"\n******************";
	    cout<<"\n TICKET PRINTING";
	    cout<<"\n******************";
	    cout<<"\n1.Print All Tickets";
	    cout<<"\n2.Print Tickets by Name";
	    cout<<"\n******************";
	    cout<<"\nEnter your option:";
	    cin>>s;
	   if(s==1)
	   {
	    readfile();       // Calling of Function readfile()
	   }
	   else if(s==2)
	   {
	    searchfile();     // Calling of Function searchfile()
	   }
	   else
	    cout<<"\n!!!Invalid Option!!!";
	   break;
    case 3: clrscr();
	    modifyingfile();   // Calling of Function modifyingfile()
	    break;
    case 4: clrscr();
	    deletefile();     // Calling of Function deletefile()
	    break;
    case 5: clrscr();
	    cout<<"\nFlight Details......";
	    readfromfile();    // Calling of Function readfromfile()
	    break;
    case 6:
    {
     clrscr();
     cout<<"\nEnter Admin Password:";
     cin>>pass;
     if(pass==12345)
     {
      char ch;
      cout<<"\nAirline Details";
      cout<<"\n==============";
      cout<<"\nA.Add Data";
      cout<<"\nB.Display Data";
      cout<<"\nC.Search Data";
      cout<<"\nD.Update Data";
      cout<<"\nE.Delete Data";
      cout<<"\nF.Exit";
      cout<<"\n===============";
      cout<<"\nEnter your choice:";
      cin>>ch;
      switch(ch)
      {

       case 'A':
       case 'a':
	writetofile();        // Calling of Function writefile()
	break;
       case 'B':
       case 'b':
	readfromfile();       // Calling of Function readfromfile()
	break;
       case 'C':
       case 'c':
	searchfromfile();      // Calling of Function searchfromfile()
	break;
       case 'D':
       case 'd':
	modifyfile();          // Calling of Function modifyfile()
	break;
       case 'E':
       case 'e':
	deletefromfile();       // Calling of Function deletefromfile()
	break;
       case 'F':
       case 'f':
	thanks();               // Calling of Function thanks()
	getch();
	exit(0);                //Function that helps us to come out the program
       default: cout<<"\nInvalid Choice!!!";
      }
     }
     else
      cout<<"\n!!!Wrong Password!!!";
    }
     break;
    case 7: thanks();    // Calling of Function thanks()
	    getch();
	    exit(0);      //Function that helps us to come out the program
     default: cout<<"\n!!!Invalid Choice!!!";
    }
    cout<<"\n\n\nPress any key to continue...";
    getch();
   }
  }
  else
   cout<<"\n!!!Wrong Password!!!";
 }
 else
  cout<<"\n!!!Wrong Username!!!";
getch();
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
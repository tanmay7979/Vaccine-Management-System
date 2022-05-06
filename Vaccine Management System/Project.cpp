//#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<time.h>														//VACCINE MANAGEMENT SYSTEM
using namespace std;													//Made By-Partha Sakha Paul 
#define Covaxin 250
#define Covishield 500
#define SputnikV 150

class Vaccination
{
	public:
		string name,username,state,gender,city,password,vaccine; 
		int adhaar,dose,age;	
		
		void Start();
		void Register();
		void Login();
		void Display_Menu();
		void Book_Vaccine();
		void Display_Details();
	private:
		int Covaxin_available=Covaxin;
		int Covishield_available=Covishield;
		int SputnikV_available=SputnikV;
		
};
void Vaccination::Start()
{
	int ch;
	//system("cls");
	cout<<"\n \t\t\t\t\t\t\t ||||   REGISTER/LOGIN ||||\n\n";
	cout<<"\n \t\t\t\t  1)  Register ";
	cout<<"\t\t\t  2) LogIn ";
	cout<<" \t\t\t 3) EXIT \n";
	cout<<"\n\n \t\t\t\t\t Enter 1 for Register \n";
	cout<<"\n \t\t\t\t\t Enter 2 for LogIn \n";
	cout<<"\n \t\t\t\t\t Enter 3 for EXIT \n";
	cout<<"\n \t\t\t\t\t Enter Your Choice :";
	cin>>ch;
	switch(ch)
	{
		case 1:
			Register();
			break;
		case 2:
			Login();
			break;
		case 3:
			exit(0);
			break;
		default:
			cout<<"\n \t\t\t\t\t Wrong Choice \n";
			Start();
	}
}

void Vaccination::Register()
{
	system("cls");
	cout<<"\n \t\t\t\t\t\t\t || Welcome to REGISTRATION ||\n";
	ofstream file1("register.txt");
	cout<<"\n\t\t\t\t\t Enter First Name Only:";
	cin>>name;
	file1<<name<<endl;
	cout<<"\n \t\t\t\t\t Enter UserName(without Spaces):";
	cin>>username;
	file1<<username<<endl;
	cout<<"\n \t\t\t\t\t Enter Gender (Male as M/Female as F /Other as O):";
	cin>>gender;
	file1<<gender<<endl;
	cout<<"\n \t\t\t\t\t Enter State:";
	cin>>state;
	file1<<state<<endl;
	cout<<"\n \t\t\t\t\t Enter City:";
	cin>>city;
	file1<<city<<endl;
	cout<<"\n \t\t\t\t\t Enter Adhaar Number:";
	cin>>adhaar;
	file1<<adhaar<<endl;
	age_go:
	cout<<"\n \t\t\t\t\t Enter Age:";
	cin>>age;
	if(age<18)
	{
		cout<<"\n \t\t\t\t\t Enter above 18 Age:";
		goto age_go;
	}	
	file1<<age<<endl;
	//cout<<"\n \t\t\t\t\t Enter Vaccine Book Or Not:";
	vaccine="Not_Booked";
	file1<<vaccine<<endl;
	int attempt=2;
	repass:
	cout<<"\n \t\t\t\t\t Enter Password: ";
	//printf("\b \b");
	cin>>password;
	cout<<"\n \t\t\t\t\t Re-Enter Password :";
	{
		string password1;
		cin>>password1;
		if(password!=password1)
		{
			cout<<"\n \t\t\t\t\t---->>> Password Doesn't Match ";
			while(attempt>=0)
			{
				if(attempt==0)
				{
					system("cls");
					Start();
				}
			cout<<"\n \t\t\t\t\t You have "<<attempt<<" Attempts Left";
			attempt--;
			goto repass;
			}
		}
		file1<<password<<endl;
		cout<<"\n \t\t\t\t\t Password Set";
		cout<<"\n\n \t\t\t\t\t --------------------------REGISTRATION SUCCSESSFUL--------------------------";
	}
	
	//file1<<" "<<name<<" "<<username<<" "<<gender<<" "<<state<<" "<<city<<" "<<adhaar<<" "<<age<<" "<<vaccine<<" "<<password<<" ";
	//Registration Part Ends
	cout<<"\n \t\t\t\t\t Do You Want To LogIn???";
		cout<<"\n \t\t\t\t\t If Yes Press Y Or If No Press N:";
		char t;
		cin>>t;
		if(t=='Y')
		{
			system("cls");
			Start();
		}
		else
		{
		system("cls");
		Start();	
		}	
file1.close();
}
//---------------------------------------------------------------
void Vaccination::Login()
{
	system("cls");
	ifstream file1("register.txt");
	
	file1>> name>> username>>gender>>state>>city>>adhaar>>age>>vaccine>>password;
	cout<<"\n \t\t\t\t\t\t\t|| Welcome to LogIn || \n";
	string username_trial,password_trial;
	int attempt0=2;
	user:
	cout<<"\n \t\t\t\t\t Enter Your Username: ";
	cin>>username_trial;
	if(username==username_trial)
		goto pass;
	else
	{
		cout<<"\n \t\t\t\t\t---->>> Username Wrong ";
		while(attempt0>=0)
	 	{
	 		if(attempt0==0)
	 			{
					system("cls");
					Start();
				}
			cout<<"\n \t\t\t\t\t You have "<<attempt0<<" Attempts Left";
			attempt0--;
			goto user;
		}
			
	}
	pass:
	int attempt1=2;
	pas:
	cout<<"\n \t\t\t\t\t Enter Your Password: ";
	cin>>password_trial;
	if(password!=password_trial)
		{
			cout<<"\n \t\t\t\t\t---->>> Password Doesn't Match ";
			while(attempt1>=0)
			{
				if(attempt1==0)
				{
					system("cls");
					Start();
				}
	 				
				cout<<"\n \t\t\t\t\t You have "<<attempt1<<" Attempts Left";
				attempt1--;
				goto pas;
			}
		}
	int attempt2=2;
	cap:
	srand(time(0));
	int t=rand(),f=0;
	cout<<"\n \t\t\t\t\t Captcha:"<<t;
	cout<<"\n\n \t\t\t\t\t Enter the Captcha:";
	cin>>f;
	if(f!=t)
		{
			while(attempt2>=0)
			{
				if(attempt2==0)
	 				{
					system("cls");
					Start();
					}
				cout<<"\n \t\t\t\t\t You have "<<attempt2<<"Attempts Left";
				attempt2--;
				goto cap;	
			}
		cout<<"\n \t\t\t\t\t Please Try Again:";
		cout<<"\n \t\t\t\t\t Do You Want To TRY AGAIN to LogIn Or Want to EXIT???";
		cout<<"\n \t\t\t\t\t If TRY AGAIN Press Y Or If EXIT Press N:";
		char t;
		cin>>t;
		if(t=='Y')
			Login();
		else
			exit(0);	
		}
	else
	{
	
		cout<<"\n \t\t\t\t\t Logged In ";
		Display_Menu();
	}	
	file1.close();
	//LogIn Part Ends	
}

//---------------------------------------------------
void Vaccination::Display_Menu()
{
	int ch;
	system("cls");
	cout<<"\n \t\t\t\t\t\t\t || VACCINATION ||\n";
	cout<<"\n \n 1)BOOK VACCINE ";
	cout<<" \t\t 2)AVAILABLE VACCINE STATUS";
	cout<<" \t\t 3)TYPE OF VACCINES AVAILABLE ";
	cout<<" \t\t 4)DISPLAY YOUR DETAILS ";
	cout<<" \t\t 5)EXIT \n";
	cout<<"\n \t\t\t\t\t Enter Your Choice :";
	cin>>ch;
	switch(ch)
	{
		case 1:
			Book_Vaccine();
			break;
		case 2:
			cout<<"\n \t\t\t\t\t Covaxin:"<<Covaxin_available;
			cout<<"\n \t\t\t\t\t Covishield:"<<Covishield_available;
			cout<<"\n \t\t\t\t\t SputnikV:"<<SputnikV_available;
			break;
		case 3:
			cout<<"\n \t\t\t\t\t Covaxin- MADE IN INDIAN BY Bharat Biotech";
			cout<<"\n\n \t\t\t\t\t Covishield- MADE IN INDIA BY  AstraZeneca & Serum Institute of India ";
			cout<<"\n\n \t\t\t\t\t SputnikV: MADE IN RUSSIA BY Gamaleya Research Institute \n";
			break;
		case 4:
			Display_Details();
		case 5:
			exit(0);
			
		default:
			cout<<"\n \t\t\t\t\t Wrong Choice \n";
			Display_Menu();
			
	}
	cout<<"\n \t\t\t\t\t Do You Want To GO TO PREVIOUS MENU???";
		cout<<"\n \t\t\t\t\t If Yes Press Y Or If No Press N:";
		char t;
		cin>>t;
		if(t=='Y')
		{
			system("cls");
			Display_Menu();
		}
		else
		{
		exit(0);	
		}	
}

void Vaccination::Book_Vaccine()
{
	system("cls");
	int ch;
	char t;
	cout<<"\n \t\t\t\t\t Enter Vaccine you want to book:";
	cout<<"\n\n  1)Covishield ";
	cout<<" \t\t\t 2)Covaxin";
	cout<<" \t\t\t 3)SputnikV ";
	cout<<"\n\n \t\t\t\t\t Enter 1 for Covishield \n";
	cout<<"\n \t\t\t\t\t Enter 2 for Covaxin \n";
	cout<<"\n \t\t\t\t\t Enter 3 for SputnikV \n";
	cout<<"\n \t\t\t\t\t Enter Your Choice :";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"\n \t\t\t\t\t DO YOU WANT TO CONFIRM BOOK COVISHIELD FOR TOMMORROW ???? :";
			cout<<"\n \t\t\t\t\t If Yes Press Y Or If No Press N:";
			cin>>t;
			if(t=='Y')
			{
				Covishield_available-=1;
				cout<<"\n \t\t\t\t\t BOOKED COVISHIELD VACCINE FOR TOMORROW :";
				vaccine="Booked";
				}
			else
				Display_Menu();
			break;
			
		case 2:
			cout<<"\n \t\t\t\t\t DO YOU WANT TO CONFIRM BOOK COVAXIN FOR TOMMORROW ???? :";
			cout<<"\n \t\t\t\t\t If Yes Press Y Or If No Press N:";
			cin>>t;
			if(t=='Y')
			{
				Covaxin_available-=1;
				cout<<"\n \t\t\t\t\t BOOKED COVAXIN VACCINE FOR TOMORROW :";
				vaccine="Booked";
			}
			else
				Display_Menu();
			break;
			
		case 3:
			cout<<"\n \t\t\t\t\t DO YOU WANT TO CONFIRM BOOK SPUTNIKV FOR TOMMORROW ???? :";
			cout<<"\n \t\t\t\t\t If Yes Press Y Or If No Press N:";
			cin>>t;
			if(t=='Y')
			{
				SputnikV_available-=1;
				cout<<"\n \t\t\t\t\t BOOKED SPUTNIKV VACCINE FOR TOMORROW :";
				vaccine="Booked";
			}
			else
				Display_Menu();
			break;
			
		default:
			cout<<"\n \t\t\t\t\t Wrong Choice \n";	
			Display_Menu();	
	}
	ofstream file1("register.txt");
	//file1>> name>> username>>gender>>state>>city>>adhaar>>age>>vaccine>>password;
	file1<<" "<<name<<" "<<username<<" "<<gender<<" "<<state<<" "<<city<<" "<<adhaar<<" "<<age<<" "<<vaccine<<" "<<password<<" ";
	cout<<"\n\n \t\t\t\t\t Do You Want To Previous Menu???";
				cout<<"\n \t\t\t\t\t If Yes Press Y Or If No Press N:";
				char t1;
				cin>>t1;
				if(t1=='Y')
				{
					system("cls");
					Display_Menu();
				}
				else
				{
				exit(0);	
				}	
	file1.close();
}
//-----------------------------------------------------------------------
void Vaccination::Display_Details()
{
	ifstream file1("register.txt");
	file1>> name>> username>>gender>>state>>city>>adhaar>>age>>vaccine>>password;
	
	cout<<"Name: "<<name<<"\nUsername: "<<username<<"\nGender: "<<gender<<"\nState: "<<state<<"\nCity: "<<city<<"\nAdhaar No: "<<adhaar<<"\nAge:"<<age<<"\nVaccine Book or Not: "<<vaccine<<"\n ";
	cout<<"\n \t\t\t\t\t Do You Want To LogIn???";
		cout<<"\n \t\t\t\t\t If Yes Press Y Or If No Press N:";
		char t;
		cin>>t;
		if(t=='Y')
		{
			system("cls");
			Display_Menu();
		}
		else
		{
		exit(0);	
		}	
	file1.close();
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
	Vaccination V;
	
	cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	cout<< "\t\t\t\t\t\t\t|||| VACCINATION MANAGEMENT SYSTEM  ||||\n";
	cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	cout<< "\n \t\t\t\t\t\t\t\t\t\t\t\t\t\t Made By-Partha Sakha Paul \n\n";
	
	V.Start();
}

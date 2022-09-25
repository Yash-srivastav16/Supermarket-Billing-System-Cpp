#include<iostream>
#include<fstream>
using namespace std;

class shopping
{
	private: 
		//P for product
		int pcode;
		float price;
		float discount;
		string pname;
		
	public:
		void menu();
		void administration();
		void buyer();
		void add();
		void edit();
		void remove();
		void list();
		void receipt();
};

void shopping :: menu()
{
	m:
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t_________________________________________\n";
	cout<<"\t\t\t\t                                         \n";
	cout<<"\t\t\t\t            Supermarket Main Menu        \n";
	cout<<"\t\t\t\t                                         \n";
	cout<<"\t\t\t\t_________________________________________\n";
	cout<<"\t\t\t\t                                         \n";
	cout<<"\t\t\t\t|  1) Administrator     |\n";
	cout<<"\t\t\t\t|                       |\n";
	cout<<"\t\t\t\t|  2) Buyer             |\n";
	cout<<"\t\t\t\t|                       |\n";
	cout<<"\t\t\t\t|  3) Exit              |\n";
	cout<<"\t\t\t\t|                       |\n";
	cout<<"\n\t\t\t Please Select!";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\t\t\t Please Login \n";
			cout<<"\t\t\t Enter Email  \n";
			cin>>email;
			cout<<"\t\t\t Enter Password  \n";
			cin>>password;
			
			if(email=="yash@gmail.com" && password=="yash@123"){
				administration();
			}
			else{
				cout<<"Invalid Email or Password";
			}
			break;
			
		case 2:
			buyer();
			break;
			
		case 3:
			exit(0);
			break;
			
		default:
			cout<<"Please Select from the given options";
	}
	
	goto m;
}

void shopping :: administration()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t Administration menu";
	cout<<"\n\t\t\t|_____1) Add the product____|";
	cout<<"\n\t\t\t|                           |";
	cout<<"\n\t\t\t|_____2) Modify the product_|";
	cout<<"\n\t\t\t|                           |";
	cout<<"\n\t\t\t|_____3) Delete the product_|";
	cout<<"\n\t\t\t|                           |";
	cout<<"\n\t\t\t|_____4) Back to main menu__|";
	cout<<"\n\t\t\t|                           |";
	cout<<"\n\n\t Please enter your choice ";
	
	cin>>choice;
	switch(choice){
		case 1:
			add();
			break;
			
		case 2:
			edit();
			break;
		
		case 3:
			remove();
			break;
			
		case 4:
			menu();
			break;
			
		default:
			cout<<"Invalid Choice";
	}
	goto m;
}

void shopping :: buyer()
{
	m:
	int choice;
	cout<<"\t\t\t    Buyer \n";
	cout<<"\t\t\t______________ \n";
	cout<<"\t\t\t1) Buy Product \n";
	cout<<"                     \n";
	cout<<"\t\t\t2) Go Back     \n";
	cout<<"\t\t\t Enter your choice : ";
	
	cin>>choice;
	
	switch(choice){
		
		case 1:
			receipt();
			break;
			
		case 2:
			menu();
			break;
		default:
			cout<<"Invalid Choice";	
	}
	goto m;
}

void shopping :: add()
{
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\t Add new product ";
	cout<<"\n\n\t Product code of the product ";
	cin>>pcode;
	cout<<"\n\n\t Name of the product ";
	cin>>pname;
	cout<<"\n\n\t Price of the product ";
	cin>>price;
	cout<<"\n\n\t Enter the discount ";
	cin>>discount;
	
	data.open("Database.txt",ios::in); //ios::in will open the file in reading mode and ios::out will open the file in writting mode
	if(!data){ //if nothing is in database
		data.open("Database.txt",ios::app|ios::out); //ios::app means append mode
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
		data.close();
	}
	else{
		data>>c>>n>>p>>d;
		while(!data.eof()){ //eof = end of file
			if(c==pcode){
				token++;    //each content check wether already product is present or not
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	}
	
	if(token==1)
		goto m;
 	else{
 		data.open("Database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
		data.close();
	}
	cout<<"\n\n\t\t Record inserted !";
	 
}


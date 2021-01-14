#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
char passphrase[]="8385";

void gotoxy(int i,int j)
 { int o=0,p=0;
    for(;p<=j;p++)
      { cout<<"\n";
      }
    for(;o<=i;o++)
      {cout<<" ";
      }

  }
int productCount=0;
int userCount=0;
int cart[10];
int currId;
int items=0;

class product
{
	char name[50];
	char category;
	int id;
	float price;
public:
	product()
		{ category='A'; id=0;}
	char retcateg()
		{ return category; }
	int retid()
		  {
		  	return id; }
	 float retp()
		  { return price; }
	void input()
	{
	system("cls");
	char temp;
	 gotoxy(53,5);
     cout<<"************";
     gotoxy(53,1);
	 cout<<"Categories:";
	 gotoxy(53,1);
     cout<<"************";
	 			gotoxy(53,1);
				cout<<"A. Clothing and Fashion";
				gotoxy(53,1);
				cout<<"B. Electronics";
				gotoxy(53,1);
				cout<<"C. Furniture & Home Decor";
				gotoxy(53,1);
				cout<<"D. Books & Stationery";
				gotoxy(53,1);
				cout<<"E. Games, Music & Entertainment.";
	gotoxy(53,1);
	cout<<"Select category: ";
	cin>>temp;
	category = toupper(temp);
	gotoxy(53,3);
	cout<<"Enter name of the product: ";
	char abc[2];
	gets(abc);
	gets(name);
	gotoxy(53,1);
	cout<<"Enter price: ";
	cin>>price;
	productCount++;
	id=productCount;
	gotoxy(53,3);
	cout<<"Product Added. ";
	gotoxy(53,3);
	cout<<"Press any Key to continue....";
	getch();
  }

  void display()
  {
	gotoxy(53,1);
	cout<<id<<") ";
    puts(name);
    gotoxy(53,1);
    cout<<"Rs."<<price;

  }

};

class buyer
{
	char name[20];
	char address[30];
	int id;
	char pass[6];
public:

	int retid(){
		return id;
	}
	char *retpass(){
		return (char *)pass;
	}
	void input()
	{
		system("cls");
		gotoxy(53,5);
		cout<<"*******";
		gotoxy(53,1);
		cout<<"New User";
		gotoxy(53,1);
		cout<<"*******";
		gotoxy(53,3);
		cout<<"Enter name: ";
		char abc[2];
		int i;
		gets(abc);
		gets(name);
		gotoxy(53,1);
		cout<<"Enter Shipping Address: ";
		gets(address);
		gotoxy(53,1);
		cout<<"Enter a passcode: ";
        for(i=0; i<4; i++)
            {pass[i]=getch();
            cout<<pass[i];}
        pass[i]='\0';
     	userCount++;
		id=userCount;
		gotoxy(53,1);
		cout<<"Profile added successfully.";
		gotoxy(53,3);
	    cout<<"Press Any key to continue...";
		getch();

	}

	void display()
	{
		gotoxy(53,1);
		cout<<id<<") ";
		cout<<"Name: ";
		puts(name);

	}

	void checkout(){
		gotoxy(53,2);
		cout<<"Thank you for your purchase : ";
		puts(name);
		gotoxy(53,1);
		cout<<"Your order will be delivered in 3-5 bussiness days to : ";
		puts(address);
	}



};

void input_b()
{

	ofstream f1("Buyer.dat", ios::binary | ios::app);
	buyer s;
	s.input();
	f1.write( (char*)&s, sizeof(s) );
	f1.close();

}


void display_b()
{   system("cls");
	ifstream f1("Buyer.dat", ios::binary);
	buyer s;
	f1.read( (char*)&s, sizeof(s) );

		gotoxy(53,5);
		cout<<"************";
		gotoxy(53,1);
		cout<<"Profile : ";
		gotoxy(53,1);
		cout<<"************";
	do{
		s.display();
		f1.read( (char*)&s, sizeof(s) );
	  }while(f1);
		f1.close();

}

int password2(int b)
{
	char pass[50];
	ifstream f1("Buyer.dat", ios::binary);
	buyer s;
	f1.read( (char*)&s, sizeof(s) );
		do{
		if(s.retid()==b)
		{
			strcpy(pass,s.retpass());
			break;
		}
		cout<<endl;
		f1.read( (char*)&s, sizeof(s) );
	  }while(f1);
		f1.close();
     char ch[10];
     char a;
     int i;
     again:
     system("cls");
     gotoxy(53,10);
     cout<<"Authentication required to proceed!!!!!";
     gotoxy(53,3);
     cout<<"Enter The Pin : ";
     for(i=0;i<4;i++)
     {
       ch[i]=getch();
       cout<<'*';
     }
     ch[i]='\0';
     if(strcmp(ch,pass)==0)
     {
    gotoxy(53,5);
	cout<<"Authentication Completed Successfully....";
	getch();
	return 1;
     }
     else
     {
     	gotoxy(53,4);
	cout<<"Wrong Password Entered,Try Again...";
	gotoxy(53,2);
	cout<<"If you want to try again,press 0..";
	cin>>a;
	if(a=='0')
	goto again;

	else
	{
	  gotoxy(53,2);
	  cout<<"Authentication Failed....";
	  return -1;
	}
      }
}

void checkdisplay(int b)
{
	ifstream f1("Buyer.dat", ios::binary);
	buyer s;
	f1.read( (char*)&s, sizeof(s) );
	while(f1){
		if(s.retid()==b)
		s.checkout();
		cout<<endl;
		f1.read( (char*)&s, sizeof(s) );
	  }
		f1.close();

}

void add_p()
{
	ofstream f1("Product.dat", ios::binary | ios::app);
	product s;
	s.input();
	f1.write( (char*)&s, sizeof(s) );
	f1.close();

}

void categoryMenu();
void mainMenu();


void search_p(char cat)
{   system("cls");
    int a[10];
	cout<<endl;
	int flag=0;
	ifstream f1("Product.dat", ios::binary);
	product s;
	f1.read( (char*)&s, sizeof(s) );
	do{
		if(s.retcateg()==cat)
		 { a[flag]=s.retid();
           flag++; }
		f1.read( (char*)&s, sizeof(s) );
	  }while(f1);
	  f1.close();
	  if (flag==0)
        {
         cout<<"No products in this category yet!\n\n";
         cout<<"Press Any Key to go back.";
         getch();
         return categoryMenu();
        }
      else
      {
        gotoxy(53,1);
        cout<<"*******";
        gotoxy(53,1);
        cout<<"PRODUCT : ";
        gotoxy(53,1);
        cout<<"*******";

        switch(cat)
        {
            case 'A':  gotoxy(53,1);
                        cout<<"Category : Clothing and Fashion\n";
                            break;

            case 'B': gotoxy(53,1);
                        cout<<"Category : Electronics\n";
                            break;

            case 'C': gotoxy(53,1);
                        cout<<"Category : Furniture & Home Decor\n";
                            break;

            case 'D': gotoxy(53,1);
                        cout<<"Category : Books & Stationery\n";
                            break;

            case 'E': gotoxy(53,1);
                        cout<<"Category : Games, Music & Entertainment\n";
                            break;
            default:    gotoxy(53,3);
                        cout<<"Wrong Choice";
                            break;
        }
         int z;
         ifstream f1("Product.dat", ios::binary);
         for (int j=0;j<flag;j++)
         {
            z=a[j];
            f1.seekg(0);
            f1.read( (char*)&s, sizeof(s) );
            do{
                if(s.retid()== z)
                {
                    s.display();
                    cout<<endl;
                }
                f1.read( (char*)&s, sizeof(s) );
                }while(f1);
            }
         f1.close();
      }
}

float disp(int items)
{    system("cls");
	gotoxy(53,5);
	cout<<"*******";
	gotoxy(49,1);
	cout<<"Your purchase:";
	gotoxy(53,1);
	cout<<"*******";
	 gotoxy(53,2);
	 if (items==0)
     {
         cout<<"Your Cart is empty!\n\n";
         cout<<" Press Any Key to go back.";
         getch();
         return -1;
     }

     else
     {
         cout<<"Number of products bought = "<<items<<endl;
         gotoxy(80,3);
         cout<<"PRODUCT LIST : ";
         gotoxy(79,1);
         cout<<"----------------\n\n";
         float sum=0;
         int a;
         product x;
         ifstream f1("Product.dat", ios::binary);
         for (int j=0;j<items;j++)
         {
            a=cart[j];
            f1.seekg(0);
            f1.read( (char*)&x, sizeof(x) );
            do{
                if(x.retid()== a)
                {
                    x.display();
                    sum+=x.retp();
                    cout<<endl;
                    break;
                }
                f1.read( (char*)&x, sizeof(x) );
                }while(f1);
            }
         f1.close();
         return sum;
     }
}

void intro()
{
 system("cls");
 gotoxy(57,10);
 cout<<"**********************";
 gotoxy(50,1);
 cout<<"WELCOME TO OUR E-COMMERCE PLATFORM";
 gotoxy(54,1);
 cout<<"**********************";
 cout<<"\n\n\n";
 gotoxy(66,1);
 cout<<"==============================";
 gotoxy(72,1);
 cout<<"PROJECT MADE BY ::";
 cout<<"\n";
 gotoxy(75,1);
 cout<<"SAFDAR AHMED";
 cout<<"\n";
 gotoxy(69,1);
 cout<<"PRABHSIMAR SINGH TANEJA ";
 gotoxy(66,1);
 cout<<"==============================";
 cout<<"\n\n\n";
 gotoxy(67,3);
 cout<<"DELHI PUBLIC SCHOOL ";
 gotoxy(51,1);
 cout<<"==========================================================";
 gotoxy(81,3);
 cout<<" Press Any Key to continue...";
 getch();
}

int password()
{
     char ch[10];
     char a;
     int i;
     again:
     system("cls");
     gotoxy(53,10);
     cout<<"Authentication required to proceed!!!!";
     gotoxy(53,3);
     cout<<"Enter The Password : ";
     for(i=0;i<4;i++)
     {
       ch[i]=getch();
       cout<<'*';
     }
     ch[i]='\0';
     if(strcmp(ch,passphrase)==0)
     {
    gotoxy(53,5);
	cout<<"Authentication Completed Successfully....";
	getch();
	return 1;
     }
     else
     {
     	gotoxy(53,4);
	cout<<"Wrong Password Entered,Try Again...";
	gotoxy(53,2);
	cout<<"If you want to try again,press 0.. ";
	cin>>a;
	if(a=='0')
	goto again;

	else
	{
	  cout<<"\n\tAuthentication Failed....";
	  return -1;
    }
  }
}

void productCountInit()
{

	ifstream f1("Product.dat", ios::binary);
	product s;
	f1.read( (char*)&s, sizeof(s) );
	do{
		productCount++;
		f1.read( (char*)&s, sizeof(s) );
	  }while(f1);
	  f1.close();
}

void userCountInit()
{
	ifstream f1("Buyer.dat", ios::binary);
	buyer s;
	f1.read( (char*)&s, sizeof(s) );
    do{
		userCount++;
		f1.read( (char*)&s, sizeof(s) );
	  }while(f1);
	  f1.close();
}

void categoryMenu()
{
    char choice,temp;
    do{
        system("cls");
		  gotoxy(53,10);
       	cout<<"*******";
       	  gotoxy(51,1);
		cout<<"Categories:";
		  gotoxy(53,1);
	    cout<<"*******";
	      gotoxy(53,2);
        cout<<"A. Clothing and Fashion\n";
		  gotoxy(53,1);
        cout<<"B. Electronics\n";
		  gotoxy(53,1);
        cout<<"C. Furniture & Home Decor\n";
		  gotoxy(53,1);
        cout<<"D. Books & Stationery\n";
		  gotoxy(53,1);
        cout<<"E. Games, Music & Entertainment\n\n";
          gotoxy(53,1);
        cout<<"F. Back to menu\n\n";
        char ch;
          gotoxy(53,3);
        cout<<"Enter Your Choice : ";
        cin>>temp;
        ch = toupper(temp);
        if (ch=='F')
            return mainMenu();
        search_p(ch);
        int x;
          gotoxy(53,1);
        cout<<"Select the product you want to buy: ";
        cin>>x;
        cart[items]=x;
        items++;
		  gotoxy(53,1);
		cout<<"Do you want to buy more (y/n) : ";
		choice=getch();
      }while(choice=='y'||choice=='Y');
}

void mainMenu()
{
	system("cls");
	int c;
	float p;
	do{
        system("cls");
          gotoxy(53,10);
        cout<<"**************";
          gotoxy(58,1);
        cout<<"MENU";
          gotoxy(53,1);
        cout<<"**************";
          gotoxy(53,2);
        cout<<"1. BUY ";
          gotoxy(53,1);
        cout<<"2. SELL ";
          gotoxy(53,1);
        cout<<"3. Exit";
          gotoxy(53,3);
        cout<<"Enter your choice : ";
        cin>>c;
        if(c==2)
            add_p();
        else if(c==1)
        {categoryMenu();
        system("cls");
        p=disp(items);
        if (p == -1)
            {return mainMenu();
            break;}
        else
            {
            gotoxy(53,1);
            cout<<"Your total amount is Rs."<<p;
              gotoxy(53,1);
            checkdisplay(currId);
              gotoxy(53,1);
            cout<<"Press any key to continue....";
            getch();
            }}
    }while (c!=3);
}

int main()
{
	productCountInit();
	userCountInit();
	intro();
	int pin;
	system("cls");
	pin=password();
	if(pin==1){

	int c,b;
	do{
	system("cls");
	gotoxy(53,10);
	cout<<"************";
	gotoxy(56,1);
	cout<<"LOGIN";
	gotoxy(53,1);
	cout<<"************";
	gotoxy(53,2);
	cout<<"1) Create New Profile";
    gotoxy(53,1);
	cout<<"2) Select Existing Profile";
	gotoxy(53,1);
	cout<<"3) EXIT";
	gotoxy(53,2);
	cout<<"************";
	gotoxy(53,5);
	cout<<"Enter your choice : ";
	cin>>c;
	if(c==1)
		input_b();
	else if(c==2)
		display_b();
	else if(c==3)
	{
	  exit(0);
    }
	else cout<<"Wrong input!";
	} while (c!=2);
	gotoxy(53,2);
	cout<<"Choose profile: ";
	cin>>b;
	currId=b;
	int pin2=password2(b);
	if(pin2==1)
        mainMenu();
}
	system("cls");
	gotoxy(53,5);
	cout<<"**************";
	gotoxy(54,1);
	cout<<"THANK YOU!!";
	gotoxy(53,1);
	cout<<"**************";
}


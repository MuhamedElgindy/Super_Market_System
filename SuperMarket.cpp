#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<iomanip>
#include<process.h>
using namespace std;

class Item
{
	char Iname[50][50];

public:
	int totalitems;
	float Qty[3];
	float price[3];
	int vatprice[3];
	int tprice[3];
	//void input();
	void output();
void input()
{
	
	cout<<"\nEnter number of items= ";
	cin>>totalitems;

	for(int i=0; i<totalitems; i++)
	{
		cout<<"\nEnter name of item "<<i+1<<": ";
		cin>>Iname[i];
		cout<<"Enter quantity: ";
		cin>>Qty[i];
		cout<<"Enter price of item "<<i+1<<": ";
		cin>>price[i];
		tprice[i]=Qty[i]*price[i];
	}
}
void output()
{
	int a;

	ifstream infile("COUNT.TXT");
	infile>>a;

	ofstream outfile("COUNT.TXT");
	a+=1;
	outfile<<a;
	outfile.close();

	
	{
	ofstream outfile("HIS.TXT", ios::app);
	outfile<<endl<<"Bill No.: "<<a<<endl;
	outfile<<"------------------------------------------------------------------------"<<endl;
cout<<"\n";
	cout<<"Name of Item\tQuantity   Price  Total Price\n";
	for(int i=0;i<totalitems;i++)
	{
		outfile<<"Name: "<<Iname[i]<<" Qty: "<<Qty[i]<<" Price: "<<tprice[i]<<endl;
		cout<<Iname[i]<<"\t\t"<<Qty[i]<<"\t   "<<price[i]<<"\t   "<<tprice[i]<<'\n';
	}

	outfile<<"------------------------------------------------------------------------"<<endl;
	outfile.close();
}
}

};
class vat:public head
{
	float vats;
public:
	void vatcal();
	void outputs();
	void sum();
};
//******************************************************************
//	    INPUT FUNCTION
//******************************************************************


//******************************************************************
//	   OUTPUT FUNCTION
//******************************************************************



void head::


//******************************************************************
//	   VAT CALCULATION
//******************************************************************

void vat::vatcal()
{
	input();
	for(int i=0;i<totalitems;i++)
	{
		if(price[i]<=100.00)
		{
			vatprice[i]=tprice[i]+(0.03*tprice[i]);
		}
		else
		{
			vatprice[i]=tprice[i]+(0.1*tprice[i]);
		}
	}
}
//******************************************************************
//	    VAT OUTPUTS
//******************************************************************

void vat::outputs()
{
	output();

	float cash=0,sum=0,qty=0,sumt=0;

	for(int i=0;i<totalitems;i++)
	{
	       sumt+=tprice[i];
		   sum+=vatprice[i];
		   qty+=Qty[i];
	}
	cout<<"\nTotal:";
	cout<<"\n------------------------------------------------------------------------------";
	cout<<"\n\tQuantity= "<<qty<<"\t\t Sum= "<<sumt<<"\tWith Vat:"<<sum;
	cout<<"\n------------------------------------------------------------------------------";

pay:

	cout<<"\n\n\t\t\t****PAYMENT SUMMARY****\n";
	cout<<"\n\t\t\tTotal cash given: ";
	cin>>cash;

	if(cash>=sum)
		cout<<"\n\t\t\tTotal cash repaid: "<<cash-sum<<'\n';
		
	else
	{	cout<<"\n\t\t\tCash given is less than total amount!!!";

	goto pay;
	}
}


int main(){
	item itm;
	char opt , ch;
	ifstream fin;
	
	cout<<"\t\t\t\t  _______________________________"<<"\n";
	cout<<"\t\t\t\t | Welcome in SuperMarket System |"<<"\n";
	cout<<"\t\t\t\t |_______________________________|"<<"\n";
	cout<<"\n\n";
	
	do{
		start:
			cout<<"Enter OK to Start \n";
			system("pause");
			cout<<"\n \t\t\t\tWhat do you want to do : "<<"\n";
			cout<< "\t\t\t\t ___________________________\n";
			cout<<" \t\t\t\t| 1  |Enter 1 to new item   |\n";
			cout<<" \t\t\t\t|____|______________________|\n";
			cout<<" \t\t\t\t| 2  |Enter 2 to view Cart  |\n";
			cout<<" \t\t\t\t|____|______________________|\n";
			cout<<" \t\t\t\t| 3  |Enter 3 To Exite      |\n";
			cout<<" \t\t\t\t|____|______________________|\n";
			cout<<"\n";
			cout<<"\t\t\t\t _____________________________\n";
			cout<<"\t\t\t\t| Please Enter Your Cohice :  \n";
			cout<<"\t\t\t\t|_____________________________ ";
			cin>>opt;
			
			
			switch(opt){
				case '1':
					itm.output();
					goto start;
					
				case '2':
					fin.open("Super_Market",ios::in);
					while(fin.get(ch)){
						cout<<ch;
					}
					fin.close();
					goto start;
				
				case '3':
					exit(0);
				default:
					cout<<"\a";
				}
				}while(opt!=3);
			return 0;
		}
		
	
//	int option = 0 , id=0 , quantity = 0;
//	double price = 0;
//	string name="";
//	
//	
//	
//	cout<<"\t\t\t  _______________________________"<<"\n";
//	cout<<"\t\t\t | Welcome in SuperMarket System |"<<"\n";
//	cout<<"\t\t\t |_______________________________|"<<"\n";
//	cout<<"\n\n";
//	
//	cout<<" What do you want to do ! .\n\n\n";
//	cout<<"Enter 1 to create a new Product : \n";
//	cout<<"Enter 2 to show product : \n";
//	cout<<"Enter 3 to Delete Product :\n";
//	cout<<"Enter 4 to add product : \n";
//	cout<<"Enter 5 to Exit";
//	
//	switch(option){
//		case 1:
//			cout<<"Hello Now You Can Create Product :\n";
////			new_product();
//			break;
//		case 2:
//			cout<<"The Product List : \n";
////			ct.show_product();
//			break;
//		case 3:
//			break;	
//	}
//	ofstream myfile;
//	myfile.open("Super_Market.txt");
//	myfile<<"\t\t\t _____________________________"<<"\n\n";
//	myfile<<"\t\t\t| Welcome in SuperMarket System|"<<"\n";
//	myfile<<"\t\t\t _____________________________"<<"\n";
//	
//	myfile.close();
//}


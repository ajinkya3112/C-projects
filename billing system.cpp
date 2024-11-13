#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class Bill{
private:
	string Item;
	int Rate, Quantity;
public:
	Bill():Item(""), Rate(0), Quantity(0){}
	
void setItem(string item){
	Item = item;
}

void setRate(int rate){
	Rate = rate;
}

void setQuant(int quant){
	Quantity = quant;
}

string getItem(){
	return Item;
}

int getRate(){
	return Rate;
}

int getQuant(){
	return Quantity;
}

};

addItem(Bill b){
bool close = false;
while(!close){
	int choice;
cout<<"\t1.Add."<<endl;
cout<<"\t2.close."<<endl;
cout<<"\tEnter Choise: ";
cin>>choice;

if(choice==1){
	system("cls");
string item;
int rate, quant;

cout<<"\tEnter Item Name: ";
cin>>item;
b.setItem(item);

cout<<"\tEnter Rate of Item: ";
cin>>rate;
b.setRate(rate);

cout<<"\tEnter Quantity of Iteam: ";
cin>>quant;
b.setQuant(quant);

std::ofstream out("C:\\Users\\admin\\Documents\\cpp\\C++ Projects\\bill.txt", std::ios::app);
if(!out){
	cout<<"\tError: File Can't Open!"<<endl;
}
else{
out<<"\t"<<b.getItem()<<" : "<<b.getRate()<<" : "<<b.getQuant()<<endl<<endl;
cout<<"\tItem Added Successfuly"<<endl;
}
out.close();
Sleep(3000);
}

else if(choice == 2){
	system("cls");
close = true;
cout<<"\tBack To Main Menu!";
Sleep(3000);
}
}
}

printBill(){
	system("cls");
int count = 0;
bool close = false;
while(!close){
system("cls");
int choice;
cout<<"\t1.Add Bill."<<endl;
cout<<"\t2.Close Session."<<endl;
cout<<"\tEnter Choice : ";
cin>>choice;

if(choice==1){
string item;
int quant;
cout<<"\Enter Item : ";
cin>>item;
cout<<"\tEnter Quantity : ";
cin>>quant;

ifstream in("C:\\Users\\admin\\Documents\\cpp\\C++ Projects\\bill.txt");
ofstream out("C:\\Users\\admin\\Documents\\cpp\\C++ Projects\\bill_Temp.txt");

string line;
bool found = false;

while(getline(in, line)){
stringstream ss;
ss<<line;
string itemName;
int itemRate, itemQuant;
char delimiter;
ss>>itemName>>delimiter>>itemRate>>delimiter>>itemQuant;

if(item ==itemName){
found = true;
if(quant <= itemQuant){
int amount = itemRate * quant;
cout<<"\t Item | Rate | Quantity | Amount"<<endl;
cout<<"\t"<<itemName<<"\t"<<itemRate<<"\t"<<quant<<"\t"<<amount<<endl;	
int newQuant = itemQuant - quant;
itemQuant = newQuant;
count +=amount;

out<<"\t"<<itemName<<" : "<<itemRate<<" : "<<itemQuant<<endl<<endl;
}
else{
cout<<"\tSorry, "<<item<<"End"<<endl;
}
}
else{
out<<line;
}
}
if(!found){
cout<<"\tItem Not Available!"<<endl;
}
out.close();
in.close();
remove("C:\\Users\\admin\\Documents\\cpp\\C++ Projects\\bill.txt");
rename("C:\\Users\\admin\\Documents\\cpp\\C++ Projects\\bill_Temp.text", "C:\\Users\\admin\\Documents\\cpp\\C++ Projects\\bill.txt");
}
else if(choice ==2){
close = true;
cout<<"\tCounting Total Bill"<<endl;
}
Sleep(3000);
}
system("cls");
cout<<endl<<endl;
cout<<"\t Total Bill ------------------------- : "<< count <<endl<<endl; 
cout<<"\tThanks for Shoppint"<<endl;
Sleep(5000);
}

int main(){
Bill b;

bool exit = false;
while(!exit){
system("cls");
int val;

cout<<"\tWelcome to Super Market Billing System"<<endl;
cout<<"\t***********************************"<<endl;
cout<<"\t\t1.Add Item."<<endl;
cout<<"\t\t2.Print Bill."<<endl;
cout<<"\t\t3.Exit."<<endl;
cout<<"\t\tEnter Choice: ";
cin>>val;

if(val==1){
system("cls");
addItem(b);
Sleep(3000);	
}

else if(val==2){
printBill();
}

else if(val==3){
	system("cls");
exit = true;
cout<<"\tGood Luck!"<<endl;
Sleep(3000);
}
}
} 

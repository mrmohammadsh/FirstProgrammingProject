//-------------------------------------------Librarys---------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

//--------------------------------------------Define&typedefs------------------------------------
typedef long long int lint;
typedef unsigned long long int ulint;
//------------------------------------------NameSpace--------------------------------------------
using namespace std;
//-----------------------------------------GlobalVariables&Classes---------------------------------------
fstream Cities,Accounts,Customers,Tickets;    //Class for reading file
struct City{
    int X,Y;
};//CountryCitys[300];
struct Account{
    lint ID,Password,Mony;
};
struct Customer{
    string username,Password,Firstname,Lastname,Mobile,Friend,BId,Bpassword;
};
struct Ticket{
    string Vehicle,Origin,Destination,Date,Driver;
};
vector<struct Customer> CustomerList;
vector<struct City> CountryCitys;
vector<struct Account> CountryAccount;
#include "File.h"
//CountryCitys.resize(300,0);
//-----------------------------------------Function----------------------------------------------
/*
void OpenFile(){
    cout<<"Reading Cities....";
    Cities.open("cities.txt",ios::in|ios::app);
    if(Cities.is_open()){
        cout<<"Reading Accounts";
        Accounts.open("accounts.txt",ios::in|ios::app);
        if(Accounts.is_open()){
            Customers.open("Customers.txt",ios::in|ios::app);
            if(Customers.is_open()){
            cout<<"Reading File was Succesful :)";
            return;
            }
            
        }
        
    }
        cout<<"Error :(";
        exit(0);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertData(){
    int temp,index;
    string tmp;
    while(Cities>>index){
        CountryCitys.push_back(City());
        Cities>>temp;
        CountryCitys[CountryCitys.size()-1].X=temp;
        Cities>>temp;
        CountryCitys[CountryCitys.size()-1].Y=temp;
    }
    while(Accounts>>index){
        CountryAccount.push_back(Account());
        CountryAccount[CountryAccount.size()-1].ID=index;
        Cities>>temp;
        CountryAccount[CountryAccount.size()-1].Password=temp;
        Cities>>temp;
        CountryAccount[CountryAccount.size()-1].Mony=temp;
         
    }
    while(Customers>>tmp){
        CustomerList.push_back(Customer());
        CustomerList[CustomerList.size()-1].BId=tmp;
        Customers>>tmp;
        CustomerList[CustomerList.size()-1].Bpassword=tmp;
        Customers>>tmp;
        CustomerList[CustomerList.size()-1].Firstname=tmp;
        Customers>>tmp;
        CustomerList[CustomerList.size()-1].Lastname=tmp;
        Customers>>tmp;
        CustomerList[CustomerList.size()-1].username=tmp;
        Customers>>tmp;
        CustomerList[CustomerList.size()-1].Password=tmp;
        Customers>>tmp;
        CustomerList[CustomerList.size()-1].Mobile=tmp;
        Customers>>tmp;
        CustomerList[CustomerList.size()-1].Friend=tmp;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void CloseFiles(){
    Cities.close();
    Accounts.close();
    Customers.close();

}
////////////////////////////////////////////////////////////////////////////////////////////////
*/
void ShowTicket(string Viechel,string Origin,string Destination,string date){

}


//------------------------------------------Main-------------------------------------------------
int main(){
    
    OpenFile("All");
    InsertData();
    CloseFiles();
    for (int i=0;i<9;i++){
        cout<<CountryCitys[i].X<<endl;
        cout<<CountryCitys[i].Y<<endl;
        //cout<<CountryAccount[i].Mony<<endl;
    }
    
    return 0;
}
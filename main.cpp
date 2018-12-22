//-------------------------------------------Librarys---------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//--------------------------------------------Define&typedefs------------------------------------
typedef long long int lint;
typedef unsigned long long int ulint;
//------------------------------------------NameSpace--------------------------------------------
using namespace std;
//-----------------------------------------GlobalVariables&Classes---------------------------------------
fstream Cities,Accounts;    //Class for reading file
struct City{
    int X,Y;
};//CountryCitys[300];
struct Account{
    lint ID,Password,Mony;
};
vector<struct City> CountryCitys;
vector<struct Account> CountryAccount;
//CountryCitys.resize(300,0);
//-----------------------------------------Function----------------------------------------------

void OpenFile(){
    cout<<"Reading Cities....";
    Cities.open("cities.txt");
    if(Cities.is_open()){
        cout<<"Reading Accounts";
        Accounts.open("accounts.txt");
        if(Accounts.is_open()){
            cout<<"Reading File was Succesful :)";
            return;
        }
        
    }
        cout<<"Error :(";
        exit(0);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertData(){
    int temp,index;
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
}
////////////////////////////////////////////////////////////////////////////////////////////////

//------------------------------------------Main-------------------------------------------------
int main(){
    
    OpenFile();
    InsertData();
    return 0;
}
//-------------------------------------------Librarys---------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#define CAPACITY 10
#define PENALTY 10
#define COST 10
#include "includeF.h"


//--------------------------------------------Define&typedefs------------------------------------
typedef long long int lint;
typedef unsigned long long int ulint;
//------------------------------------------NameSpace--------------------------------------------
using namespace std;
//-----------------------------------------GlobalVariables&Classes---------------------------------------

//------------------------------------------Main-------------------------------------------------
int main(){
    OpenFile("All");
    InsertData();
    CloseFiles();
    cout<<endl<<endl;
    cout<<TripCost("1","2")<<endl;
    //WriteData("Tickets");
    //AddTrip("1","3","1397/1/1","200015","hava","12");
    //DriverReg("sahand","1234","sahand","zoufan","09351618663","200014","7535","hava");
    //AddTrip("salam","salam","salam","salam","salam","salam");
    ShowTrip("1","2","1397/1/1","hava");
    DeletTrip("1","3","1397/1/1", "200015","hava","12");
    //BuyTicket(1,"9698","200004","dada","1","2","1397/1/1","hava");
    cout<<CustomerTicket.size()<<endl;
    /*cout<<CustomerTicket[2].Origin<<endl;
    cout<<CustomerTicket[2].Destination<<endl;
    cout<<CustomerTicket[2].Date<<endl;
    cout<<CustomerTicket[2].Vehicle<<endl;
    cout<<CustomerTicket[2].Id<<endl;
    cout<<CustomerTicket[2].Time<<endl;*/
    //DeleteTicket("hava","1","2","1397/1/1","12","200004");
    //200004	9698
    /*for (int i=0;i<9;i++){
        cout<<CountryCitys[i].X<<endl;
        cout<<CountryCitys[i].Y<<endl;
        //cout<<CountryAccount[i].Mony<<endl;
    }*/
    
    return 0;
}
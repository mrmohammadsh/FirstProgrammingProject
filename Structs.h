#ifndef StructFile
#define StructFile
//--------------------------------------------Define&typedefs------------------------------------
typedef long long int lint;
typedef unsigned long long int ulint;
//------------------------------------------NameSpace--------------------------------------------
using namespace std;
//-----------------------------------------GlobalVariables&Classes---------------------------------------
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
        string Vehicle,Origin,Destination,Date,Driver,Id,Time,Seat;
    };
    struct ATicket{
        string Vehicle,Origin,Destination,Date,Driver,Id,Time;
    };
    struct Driver{
        string username,Password,Firstname,Lastname,Mobile,Vehicle,BId,Bpassword;
    };
    struct Trip{
        string Vehicle,Origin,Destination,Date,Id,Time;
        //int capacity;

    };
    vector<struct Customer> CustomerList;
    vector<struct City> CountryCitys;
    vector<struct Account> CountryAccount;
    vector<struct Ticket> CustomerTicket;
    vector<struct ATicket> CustomerATicket;
    vector<struct Driver> DriverInf;
     vector<struct Trip> TripInf;

#endif
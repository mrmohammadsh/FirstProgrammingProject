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
#define TIME "13"
#include "includeF.h"


//--------------------------------------------Define&typedefs------------------------------------
typedef long long int lint;
typedef unsigned long long int ulint;
//------------------------------------------NameSpace--------------------------------------------
using namespace std;
//-----------------------------------------GlobalVariables&Classes---------------------------------------
string ADMINPASS="11";
void ProgramMenu(){
    OpenFile("All");
    InsertData();
    CloseFiles();
    cout<<"1-Admin\n2-User\n3-Guest\n4-Register New User\n";
    int temp;
    cin>>temp;
    switch(temp){
        case 1:{
            cout<<"Welcome Dear Admin"<<endl;
            cout<<"Enter Password"<<endl;
            string pass;
            cin>>pass;
            if(pass==ADMINPASS){
                bool AdminFlag=true;
                while(AdminFlag){
                    cout<<"Hello Rich Boy :)"<<endl;
                    cout<<"1-Change PassWord\n2-ADD Driver\n3-See Tickets History\n4-Show Customer\n5-Change Driver Info\n6-Change Trip Info\n";
                    int temp;
                    cin>>temp;
                    switch(temp){
                        case 1:{
                            bool ChangePasswordFlag=true;
                            while(ChangePasswordFlag){
                                cout<<"Enter New Password:"<<endl;
                                string temp;
                                cin>>temp;
                                cout<<"Enter New Password Again:"<<endl;
                                string temp1;
                                cin>>temp1;
                                if(temp==temp1){
                                    ADMINPASS=temp1;
                                    ChangePasswordFlag=false;
                                }
                                else{
                                    cout<<"Wrong"<<endl;

                                }
                            }
                        AdminFlag=true;
                        break;
                        }
                        case 2:{
                            cout<<"Do you Want Add Driver So Let's Go"<<endl;
                            cout<<"Enter Driver First name:\n ";
                            string firstname,lastname,username,password,mobile,vehicle,Bid,Bpassword;
                            cout<<"Enter firstname:\n";
                            cin>>firstname;
                            cout<<"Enter lastname:\n";
                            cin>>lastname;
                            cout<<"Enter username:\n";
                            cin>>username;
                            cout<<"Enter password:\n";
                            cin>>password;
                            cout<<"Enter mobile:\n";
                            cin>>mobile;
                            cout<<"Enter vehicle:\n";
                            cin>>vehicle;
                            cout<<"Enter bank id:\n";
                            cin>>Bid;
                            cout<<"Enter bank password:\n";
                            cin>>Bpassword;
                            if(IsCorrent(Bid,Bpassword)){
                                DriverReg(username,password,firstname,lastname,mobile,Bid,Bpassword,vehicle);
                            }
                            else{
                                cout<<"is not correct\n";
                            }

                            
                        break;
                        }
                        case 3:{
                            cout<<"Ticket History\n";
                            ShowATicket();
                            cout<<"Press Enter to Exit"<<endl;
                            cin.ignore();
                            cin.ignore();
                            break;
                        }
                        case 4:{
                            cout<<"Show All Customer\n";
                            ShowACustomer();
                            cout<<"Press Enter to Exit"<<endl;
                            cin.ignore();
                            cin.ignore();

                            break;
                        }
                        case 5:{
                            bool ChangeDriverInfFlag=1;
                            while(ChangeDriverInfFlag){
                                cout<<"Change Driver info";
                                cout<<endl;
                                cout<<"First Enter Username of Customer\n";
                                string username;
                                cin>>username;
                                if(IsDriverExist(username)){
                                    cout<<"What Do You want to Change"<<endl;
                                    cout<<"1-Mobile\n2-Vehicle\n";
                                    int temp;
                                    cin>>temp;
                                    switch(temp){
                                        case 1:{
                                            cout<<"Enter New Mobile Number\n";
                                            string mobile;
                                            cin>>mobile;
                                            
                                            long long int index=IsDriverExist(username);
                                            index-=1;
                                            AChangeAcInfo(username,DriverInf[index].Firstname,DriverInf[index].Lastname,mobile,DriverInf[index].Vehicle);
                                            break;
                                        }
                                        case 2:{
                                            cout<<"Enter Driver New Vehicle\n";
                                            string vehicle;
                                            cin>>vehicle;
                                            
                                            long long int index=IsDriverExist(username);
                                            index-=1;
                                            AChangeAcInfo(username,DriverInf[index].Firstname,DriverInf[index].Lastname,DriverInf[index].Mobile,vehicle);
                                            break;
                                        }
                                    }
                                }
                                else{
                                    cout<<"Driver Is not exist";
                                }
                                
                                break;
                            }
                        }
                        case 6:{
                                bool ChangeTripInfFlag=1;
                            while(ChangeTripInfFlag){
                                cout<<"Change Trip info";
                                cout<<endl;
                                cout<<"Enter Destination:\n";
                                string Destination,Origin,Id;
                                cin>>Destination;
                                cout<<"Enter Origin:\n";
                                cin>>Origin;
                                cout<<"Enter Driver Id:\n";
                                cin>>Id;
                                if(IsTripExist(Destination,Origin,Id)){
                                    cout<<"What Do You want to Change"<<endl;
                                    cout<<"1-Date\n2-Time\n";
                                    int temp;
                                    cin>>temp;
                                    switch(temp){
                                        case 2:{
                                            cout<<"Enter New Time \n";
                                            string Time;
                                            cin>>Time;
                                            
                                            long long int index=IsTripExist(Destination,Origin,Id);
                                            index-=1;
                                            AChangeTripInfo(TripInf[index].Date,Time,index);
                                            break;
                                        }
                                        case 1:{
                                            cout<<"Enter  New Date\n";
                                            string Date;
                                            cin>>Date;
                                            long long int index=IsTripExist(Destination,Origin,Id);
                                            index-=1;
                                            AChangeTripInfo(Date,TripInf[index].Time,index);
                                            break;
                                        }
                                    }
                                }
                                else{
                                    cout<<"Trip Is not exist";
                                }
                                
                                break;
                            }


                        }
                    }
                }
            }
            else{
                cout<<"Wrong Password";
            }
            break;
        }
        case 2:{
            cout<<"Enter Your UserName:";
            string username,Password;
            cin>>username;
            cout<<"Enter Your Password:";
            cin>>Password;
            long long int index=IsCustomerExist(username,Password);
            
            if(index){
                index-=1;
                cout<<"You Logged IN"<<endl;
                cout<<"1-Buy Ticket\n2-Delete Ticket\n3-Change Information\n";
                int temp;
                cin>>temp;
                switch(temp){
                    case 1:{
                        string Origin,Destination,Date,Vehicle;
                        cout<<"Enter Origin\n";
                        cin>>Origin;
                        cout<<"Enter Destination\n";
                        cin>>Destination;
                        cout<<"Enter Date\n";
                        cin>>Date;
                        cout<<"Enter Vehicle\n";
                        cin>>Vehicle;
                        if(ShowTrip(Origin,Destination,Date,Vehicle)){
                            cout<<"Enter Number Of row:";
                            int number;
                            cin>>number;
                            string Bpassword,Bid,Seat;
                            long long int index=TripIndex(number,Origin,Destination,Date,Vehicle);
                            cout<<"This Is The Full Seats\n";
                            if(ShowSeat(Origin,Destination,Date,Vehicle,DriverInf[DriverId(TripInf[index].Id)].Firstname,TripInf[index].Time))
                            {
                                int kkk;
                            }
                            else{
                                cout<<"Vehicle is empty";
                            }
                            cout<<"Enter Seat:";
                            cin>>Seat;
                            if(SeatExist(Seat,Origin,Destination,Date,Vehicle,DriverInf[DriverId(TripInf[index].Id)].Firstname,TripInf[index].Time)){
                                cout<<"Enter Bank Id\n";
                                cin>>Bid;
                                cout<<"Enter Bank Password";
                                cin>>Bpassword;
                                if(IsCorrent(Bid,Bpassword)){
                                BuyTicket(number,Bpassword,Bid,username,Origin,Destination,Date,Vehicle,Seat);
                                }
                                else{
                                    cout<<"Bank Account is Incorrect";
                                }
                            }
                            else{
                                cout<<"Seat You Chose Is Full";
                            }

        
                            
                        }
                        break;
                    }
                    case 2:{
                        cout<<"Delete Ticket\n";
                        string Vehicle,Origin,Destination,Date,Time,Id,Seat;
                        cout<<"Enter Origin\n";
                        cin>>Origin;
                        cout<<"Enter Destination\n";
                        cin>>Destination;
                        cout<<"Enter Vehicle\n";
                        cin>>Vehicle;
                        cout<<"Enter Date\n";
                        cin>>Date;
                        cout<<"Enter Time\n";
                        cin>>Time;
                        cout<<"Enter Seat\n";
                        cin>>Seat;
                        cout<<"Enter ID\n";
                        cin>>Id;
                        DeleteTicket(Vehicle,Origin,Destination,Date,Time,Id,Seat);
                    }
                    case 3:{
                        cout<<"What Do You Want To Change\n";
                        cout<<"1-password\n2-Mobile\n";
                        int num;
                        cin>>num;
                        switch(num){
                            case 1:{
                                cout<<"Enter New password:\n";
                                string password1,password2;
                                cin>>password1;
                                cout<<"Enter New password Again:\n";
                                cin>>password2;
                                if(password1==password2){
                                    CustomerList[UserNameToIndex(username)].Password=password1;
                                    WriteData("Customer");
                                    cout<<"Password Changed\n";
                                }
                                else{
                                    cout<<"Wrong Password";
                                }
                                break;
                            }
                            case 2:{
                                cout<<"Enter New Phone Number\n";
                                string Mobile;
                                cin>>Mobile;
                                CustomerList[UserNameToIndex(username)].Mobile=Mobile;
                                WriteData("Customer");
                                cout<<"Mobile Changed\n";
                                break;
                            }
                        }
                    }
                }
            }
            else{
                cout<<"Wrong Answear";

            }
        }
        case 4:{
            string username,Password,Firstname,Lastname,Mobile,BId,Bpassword,Friend;
            cout<<"Enter Username:\n";
            cin>>username;
            cout<<"Enter Password:\n";
            cin>>Password;
            cout<<"Enter Firstname:\n";
            cin>>Firstname;
            cout<<"Enter Lastname:\n";
            cin>>Lastname;
            cout<<"Enter Mobile:\n";
            cin>>Mobile;
            cout<<"Enter Bank Id:\n";
            cin>>BId;
            cout<<"Enter Bpassword:\n";
            cin>>Bpassword;
            cout<<"Enter Friend Else Enter Null:\n";
            cin>>Friend;
            if(IsCorrent(BId,Bpassword)){
                 CustomerReg(username,Password,Firstname,Lastname,Mobile,BId,Bpassword,Friend);
                 cout<<"You Are Register Succsefully";
            }
            else{
                cout<<"SomeThing Went Wrong";
            }
            
        }
    }
}
//------------------------------------------Main-------------------------------------------------
int main(){

    cout<<endl<<endl;
    //CustomerReg("sdf","sdf","gooz","khar","3423","200004","323","");
    //cout<<TripCost("1","2")<<endl;
    //WriteData("Tickets");
    cout<<"salam"<<endl;
    //cout<<AddTrip("1","3","1397/1/1","200014","hava","12");
    //DriverReg("sahand","1234","sahand","zoufan","09351618663","200014","7535","hava");
    //AddTrip("salam","salam","salam","salam","salam","salam");
    //ShowTrip("1","3","1397/1/1","hava");
    //DeletTrip("1","3","1397/1/1", "200015","hava","12");
    //BuyTicket(1,"9698","200004","dada","1","3","1397/1/1","hava","13");
    //BuyTicket(1,"9698","200004","dada","1","3","1397/1/1","hava");
    //WriteData("ATickets");
    //ShowATicket();
    //TripCustomer("1","3","1397/1/1","hava","12");
    //CustomerHistory("200004");
    //DeletTrip("1","3","1397/1/1", "200015","hava","12");
    //cout<<CustomerTicket.size()<<endl;
    /*cout<<CustomerTicket[2].Origin<<endl;
    cout<<CustomerTicket[2].Destination<<endl;
    cout<<CustomerTicket[2].Date<<endl;
    cout<<CustomerTicket[2].Vehicle<<endl;
    cout<<CustomerTicket[2].Id<<endl;
    cout<<CustomerTicket[2].Time<<endl;*/
    //DeleteTicket("hava","1","2","1397/1/1","12","200004");
    //CustomerReg("sahand","1234","sahand","dada","09351618663","200013","4302","");
    //200004	9698
    /*for (int i=0;i<9;i++){
        cout<<CountryCitys[i].X<<endl;
        cout<<CountryCitys[i].Y<<endl;
        //cout<<CountryAccount[i].Mony<<endl;
    }*/
    //cout<<"ddddddddddddddddddddddddd"<<endl;
    //Time("1:44");
    //cout<<UHour<<"    "<<UMin;
    ProgramMenu();
    return 0;
}
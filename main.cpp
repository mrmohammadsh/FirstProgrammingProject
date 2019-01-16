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
    cout<<"1-Admin\n2-User\n3-Guest\n";
    int temp;
    cin>>temp;
    switch(temp){
        case 1:
        cout<<"Welcome Dear Admin"<<endl;
        cout<<"Enter Password"<<endl;
        string pass;
        cin>>pass;
        if(pass==ADMINPASS){
            bool AdminFlag=true;
            while(AdminFlag){
                cout<<"Hello Rich Boy :)"<<endl;
                cout<<"1-Change PassWord\n2-ADD Driver\n3-See Tickets History\n";
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
                }
            }
        }
        else{
            cout<<"Wrong Password";
        }
        break;
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
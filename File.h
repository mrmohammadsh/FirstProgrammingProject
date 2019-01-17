#ifndef FileFunctions
#define FileFunctions
//--------------------------------------------Define&typedefs------------------------------------
typedef long long int lint;
typedef unsigned long long int ulint;
//------------------------------------------NameSpace--------------------------------------------
using namespace std;
//-----------------------------------------GlobalVariables&Classes---------------------------------------
//-----------------------------------------Function----------------------------------------------
fstream Cities,Accounts,Customers,Tickets,Drivers,Trips,ATickets; 
string Coding(string pass){
    string Salt="ThisIsSalt";
    pass=pass+Salt;
    for(int i=0;i<pass.length();i++){
        pass[i]=(char)((int)pass[i]-1);
    }
    return pass;
}
string DeCoding(string pass){

    for(int i=0;i<pass.length();i++){
        pass[i]=(char)((int)pass[i]+1);
    }
    string Salt="ThisIsSalt";
    pass.erase(pass.find(Salt),pass.length());
    //pass=pass-Salt;
    return pass;
}
void OpenFile(const char *name){
    
        if(strcmp("Cities",name)==0){
            cout<<"Reading Cities...."<<endl;
            Cities.open("cities.txt",ios::in|ios::app);
            if(Cities.is_open())    cout<<"Rading Cities Was Sucsseful"<<endl;
            else exit(0);
            }
        else if(strcmp("Accounts",name)==0){
            cout<<"Reading Accounts...."<<endl;
            Accounts.open("accounts.txt",ios::in|ios::out);
            if(Accounts.is_open())    cout<<"Rading Accounts Was Sucsseful"<<endl;
            else exit(0);
        }
        else if(strcmp("Customers",name)==0){
            cout<<"Reading Customers...."<<endl;
            Customers.open("Customers.txt",ios::in|ios::out);
            if(Customers.is_open())    cout<<"Rading Customers Was Sucsseful"<<endl;
            else exit(0);
        }
        else if(strcmp("Tickets",name)==0){
            cout<<"Reading Tickets...."<<endl;
            Tickets.open("Tickets.txt",ios::in|ios::out);
            if(Tickets.is_open())    cout<<"Rading Tickets Was Sucsseful"<<endl;
            else exit(0);
        }
        else if(strcmp("Drivers",name)==0){
            cout<<"Drivers ...."<<endl;
            Drivers.open("Drivers.txt",ios::in|ios::out);
            if(Drivers.is_open())    cout<<"Rading Drivers Was Sucsseful"<<endl;
            else exit(0);
        }
        else if(strcmp("Trips",name)==0){
            cout<<"Trips ...."<<endl;
            Trips.open("Trips.txt",ios::in|ios::out);
            if(Trips.is_open())    cout<<"Rading Trips Was Sucsseful"<<endl;
            else exit(0);
        }
        else if(strcmp("ATickets",name)==0){
            cout<<"Aticket ...."<<endl;
            ATickets.open("ATicket.txt",ios::in|ios::out);
            if(ATickets.is_open())    cout<<"Rading ATicket Was Sucsseful"<<endl;
            else exit(0);
        }
        else if("All"){
            OpenFile("Cities");
            OpenFile("Accounts");
            OpenFile("Customers");
            OpenFile("Tickets");
            OpenFile("Drivers");
            OpenFile("Trips");
            OpenFile("ATickets");

        }
        

}
void CloseFiles(){
    Cities.close();
    Accounts.close();
    Customers.close();
    Tickets.close();
    Drivers.close();
    Trips.close();
    ATickets.close();


}
void EmptyFile(string name){
    if(name=="Tickets"){
        Tickets.open("Tickets.txt",ios::out|ios::trunc);
    }
    else if(name=="Drivers"){
        Drivers.open("Drivers.txt",ios::out|ios::trunc);
    }
    else if(name=="Accounts"){
        Accounts.open("Accounts.txt",ios::out|ios::trunc);
    }
    else if(name=="Customers"){
        Customers.open("Customers.txt",ios::out|ios::trunc);
    }
    else if(name=="Trips"){
        Trips.open("Trips.txt",ios::out|ios::trunc);
    }
    else if(name=="ATickets"){
        ATickets.open("ATickets.txt",ios::out|ios::trunc);
    }
    CloseFiles();
        
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertData(){
    long long int temp,index;
    string tmp;
    //cout<<"helloooooooooooooooooooooooooooooooooooooo";
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
        Accounts>>tmp;
        CountryAccount[CountryAccount.size()-1].Password=stoll(DeCoding(tmp));
        Accounts>>temp;
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
    
    while(Drivers>>tmp){
        DriverInf.push_back(Driver());
        DriverInf[DriverInf.size()-1].BId=tmp;
        Drivers>>tmp;
        DriverInf[DriverInf.size()-1].Bpassword=tmp;
        Drivers>>tmp;
        DriverInf[DriverInf.size()-1].Firstname=tmp;
        Drivers>>tmp;
        DriverInf[DriverInf.size()-1].Lastname=tmp;
        Drivers>>tmp;
        DriverInf[DriverInf.size()-1].username=tmp;
        Drivers>>tmp;
        DriverInf[DriverInf.size()-1].Password=tmp;
        Drivers>>tmp;
        DriverInf[DriverInf.size()-1].Mobile=tmp;
        Drivers>>tmp;
        DriverInf[DriverInf.size()-1].Vehicle=tmp;
    }
    while(Trips>>tmp){
        //string Vehicle,Origin,Destination,Date,Id;
        TripInf.push_back(Trip());
        TripInf[TripInf.size()-1].Vehicle=tmp;
        Trips>>tmp;
        TripInf[TripInf.size()-1].Origin=tmp;
        Trips>>tmp;
        TripInf[TripInf.size()-1].Destination=tmp;
        Trips>>tmp;
        TripInf[TripInf.size()-1].Date=tmp;
        Trips>>tmp;
        TripInf[TripInf.size()-1].Id=tmp;
        Trips>>tmp;
        TripInf[TripInf.size()-1].Time=tmp;
    }
    
    while(Tickets>>tmp){
        CustomerTicket.push_back(Ticket());
        CustomerTicket[CustomerTicket.size()-1].Vehicle=tmp;
        Tickets>>tmp;
        CustomerTicket[CustomerTicket.size()-1].Origin=tmp;
        Tickets>>tmp;
        CustomerTicket[CustomerTicket.size()-1].Destination=tmp;
        Tickets>>tmp;
        CustomerTicket[CustomerTicket.size()-1].Date=tmp;
        Tickets>>tmp;
        CustomerTicket[CustomerTicket.size()-1].Driver=tmp;
        Tickets>>tmp;
        CustomerTicket[CustomerTicket.size()-1].Id=tmp;
        Tickets>>tmp;
        CustomerTicket[CustomerTicket.size()-1].Time=tmp;
        Tickets>>tmp;
        CustomerTicket[CustomerTicket.size()-1].Seat=tmp;
        Tickets>>tmp;
        CustomerTicket[CustomerTicket.size()-1].Code=tmp;

    }
while(ATickets>>tmp){
        CustomerATicket.push_back(ATicket());
        CustomerATicket[CustomerATicket.size()-1].Vehicle=tmp;
        ATickets>>tmp;
        CustomerATicket[CustomerATicket.size()-1].Origin=tmp;
        ATickets>>tmp;
        CustomerATicket[CustomerATicket.size()-1].Destination=tmp;
        ATickets>>tmp;
        CustomerATicket[CustomerATicket.size()-1].Date=tmp;
        ATickets>>tmp;
        CustomerATicket[CustomerATicket.size()-1].Driver=tmp;
        ATickets>>tmp;
        CustomerATicket[CustomerATicket.size()-1].Id=tmp;
        ATickets>>tmp;
        CustomerATicket[CustomerATicket.size()-1].Time=tmp;

    }

}
void WriteData(string name){
    if(name=="Customer"){
        EmptyFile("Customers");
        OpenFile("Customers");
        
        //string Vehicle,Origin,Destination,Date,Driver;
        for(lint i=0;i<CustomerList.size();i++){
                Customers<<CustomerList[i].BId;
                Customers<<'\t';
                Customers<<CustomerList[i].Bpassword;
                Customers<<'\t';
                Customers<<CustomerList[i].Firstname;
                Customers<<'\t';
                Customers<<CustomerList[i].Lastname;
                Customers<<'\t';
                Customers<<CustomerList[i].username;
                Customers<<'\t';
                Customers<<CustomerList[i].Password;
                Customers<<'\t';
                Customers<<CustomerList[i].Mobile;
                Customers<<'\t';
                Customers<<CustomerList[i].Friend;
                Customers<<'\n';
            
        }
        CloseFiles();

    }
    else if(name=="Drivers"){
        OpenFile("Drivers");
        //string Vehicle,Origin,Destination,Date,Driver;
        for(lint i=0;i<DriverInf.size();i++){
                Drivers<<DriverInf[i].BId;
                Drivers<<'\t';
                Drivers<<DriverInf[i].Bpassword;
                Drivers<<'\t';
                Drivers<<DriverInf[i].Firstname;
                Drivers<<'\t';
                Drivers<<DriverInf[i].Lastname;
                Drivers<<'\t';
                Drivers<<DriverInf[i].username;
                Drivers<<'\t';
                Drivers<<DriverInf[i].Password;
                Drivers<<'\t';
                Drivers<<DriverInf[i].Mobile;
                Drivers<<'\t';
                Drivers<<DriverInf[i].Vehicle;
                Drivers<<'\n';
            
        }
        CloseFiles();

    }
    else if(name=="Trips"){
        EmptyFile("Trips");
        OpenFile("Trips");
        //string Vehicle,Origin,Destination,Date,Driver;
        for(lint i=0;i<TripInf.size();i++){
            Trips<<TripInf[i].Vehicle;
            Trips<<'\t';
            Trips<<TripInf[i].Origin;
            Trips<<'\t';
            Trips<<TripInf[i].Destination;
            Trips<<'\t';
            Trips<<TripInf[i].Date;
            Trips<<'\t';
            Trips<<TripInf[i].Id;
            Trips<<'\t';
            Trips<<TripInf[i].Time;
            Trips<<'\n';
            
        }
        CloseFiles();


    }
    else if(name=="Tickets"){
        //OpenFile("Tickets");
        //string Vehicle,Origin,Destination,Date,Driver;
        //Tickets.open("Tickets.txt",ios::out|ios::trunc);
        EmptyFile("Tickets");
        OpenFile("Tickets");
        cout<<CustomerTicket.size()<<"oooooo"<<endl;
        for(lint i=0;i<CustomerTicket.size();i++){
            Tickets<<CustomerTicket[i].Vehicle;
            Tickets<<'\t';
            Tickets<<CustomerTicket[i].Origin;
            Tickets<<'\t';
            Tickets<<CustomerTicket[i].Destination;
            Tickets<<'\t';
            Tickets<<CustomerTicket[i].Date;
            Tickets<<'\t';
            Tickets<<CustomerTicket[i].Driver;
            Tickets<<'\t';
            Tickets<<CustomerTicket[i].Id;
            Tickets<<'\t';
            Tickets<<CustomerTicket[i].Time;
            Tickets<<'\t';
            Tickets<<CustomerTicket[i].Seat;
            Tickets<<'\t';
            Tickets<<CustomerTicket[i].Code;
            Tickets<<'\n';
            
        }
        CloseFiles();


    }
    else if(name=="ATickets"){
        //OpenFile("Tickets");
        //string Vehicle,Origin,Destination,Date,Driver;
        //Tickets.open("Tickets.txt",ios::out|ios::trunc);
        //EmptyFile("Tickets");
        EmptyFile("ATickets");
        OpenFile("ATickets");
        //cout<<CustomerATicket.size()<<"oooooo"<<endl;
        for(lint i=0;i<CustomerATicket.size();i++){
            ATickets<<CustomerATicket[i].Vehicle;
            ATickets<<'\t';
            ATickets<<CustomerATicket[i].Origin;
            ATickets<<'\t';
            ATickets<<CustomerATicket[i].Destination;
            ATickets<<'\t';
            ATickets<<CustomerATicket[i].Date;
            ATickets<<'\t';
            ATickets<<CustomerATicket[i].Driver;
            ATickets<<'\t';
            ATickets<<CustomerATicket[i].Id;
            ATickets<<'\t';
            ATickets<<CustomerATicket[i].Time;
            ATickets<<'\n';
            
        }
        CloseFiles();


    }
    else if(name=="Accounts"){
        OpenFile("Accounts");
         
        for(lint i=0;i<CountryAccount.size();i++){
            Accounts<<CountryAccount[i].ID;
            Accounts<<'\t';
            Accounts<<Coding(to_string(CountryAccount[i].Password));
            Accounts<<'\t';
            Accounts<<CountryAccount[i].Mony;
            Accounts<<'\n';
            
        }
        CloseFiles();
        

    }
    
}
void CodingAccounts(){
long long int temp,index;
string tmp;
OpenFile("Accounts");
while(Accounts>>index){

        CountryAccount.push_back(Account());
        CountryAccount[CountryAccount.size()-1].ID=index;
        Accounts>>temp;
        CountryAccount[CountryAccount.size()-1].Password=temp;
        Accounts>>temp;
        CountryAccount[CountryAccount.size()-1].Mony=temp;

         
    }
    CloseFiles();
    WriteData("Accounts");

}
/////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
#endif
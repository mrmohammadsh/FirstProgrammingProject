#ifndef FileFunctions
#define FileFunctions
//-----------------------------------------Function----------------------------------------------

void OpenFile(const char *name){
    
        if(strcmp("Cities",name)==0){
            cout<<"Reading Cities....";
            Cities.open("cities.txt",ios::in|ios::app);
            if(Cities.is_open())    cout<<"Rading Cities Was Sucsseful";
            else exit(0);
            }
        else if(strcmp("Accounts",name)==0){
            cout<<"Reading Accounts....";
            Accounts.open("accounts.txt",ios::in|ios::app);
            if(Accounts.is_open())    cout<<"Rading Accounts Was Sucsseful";
            else exit(0);
        }
        else if(strcmp("Customers",name)==0){
            cout<<"Reading Customers....";
            Customers.open("Customers.txt",ios::in|ios::app);
            if(Customers.is_open())    cout<<"Rading Customers Was Sucsseful";
            else exit(0);
        }
        else if(strcmp("Tickets",name)==0){
            cout<<"Reading Tickets....";
            Tickets.open("Tickets.txt",ios::in|ios::app);
            if(Tickets.is_open())    cout<<"Rading Tickets Was Sucsseful";
            else exit(0);
        }
        else{
            OpenFile("Cities");
            OpenFile("Accounts");
            OpenFile("Customers");
            OpenFile("Tickets");

        }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertData(){
    lint temp,index;
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
        Accounts>>temp;
        CountryAccount[CountryAccount.size()-1].Password=temp;
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
    /*while(Customers>>tmp){
        Ticket.push_back(Customer());
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
    }*/
}
void WriteData(string name){
    if(name=="Tickets"){

    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void CloseFiles(){
    Cities.close();
    Accounts.close();
    Customers.close();

}
////////////////////////////////////////////////////////////////////////////////////////////////
#endif
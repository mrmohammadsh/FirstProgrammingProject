#ifndef FileFunctions
#define FileFunctions
//-----------------------------------------Function----------------------------------------------

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
#endif
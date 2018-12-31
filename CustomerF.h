#ifndef CustomerF
#define CustomerF
    long long int CustomerId(string BId){
        for(long long int i=0;i<CustomerList.size();i++){
            if(CustomerList[i].BId==BId){
                return i;
            }
        }
        return -1;
    }
    void CustomerReg(string username,string Password,string Firstname,string Lastname,string Mobile,string BId,string Bpassword,string Friend){
        //cout<<endl<<CustomerList.size()<<"kwejrklwj";
        //string username,Password,Firstname,Lastname,Mobile,Friend,BId,Bpassword;
        CustomerList.push_back(Customer());
        CustomerList[CustomerList.size()-1].username=username;
        CustomerList[CustomerList.size()-1].Password=Password;
        CustomerList[CustomerList.size()-1].Firstname=Firstname;
        CustomerList[CustomerList.size()-1].Lastname=Lastname;
        CustomerList[CustomerList.size()-1].Mobile=Mobile;
        CustomerList[CustomerList.size()-1].Friend=Friend;
        CustomerList[CustomerList.size()-1].BId=BId;
        CustomerList[CustomerList.size()-1].Bpassword=Bpassword;
        WriteData("Customer");
    }
    void ShowTrip(string Origin,string Destination,string Date,string Vehicle){
        int counter=1;
        for(int i=0;i<TripInf.size();i++){
            
            if(
            TripInf[i].Origin==Origin&&
            TripInf[i].Destination==Destination&&
            TripInf[i].Date==Date&&
            TripInf[i].Vehicle==Vehicle
            ){          //If
                cout<<counter++<<'\t'<<TripInf[i].Time<<endl;
                
            }

        }
    }
    long long int TripCost(string Origin,string Destination){
        long long int temp;
        temp=pow(abs(CountryCitys[stoi(Origin)-1].X-CountryCitys[stoi(Destination)-1].X),2)+pow(abs(CountryCitys[stoi(Origin)-1].Y-CountryCitys[stoi(Destination)-1].Y),2);
        temp=int(sqrt(temp));
    }
    long long int CustomerMony(string BId){
        for(long long int i=0;i<CountryAccount.size();i++){
            if(CountryAccount[i].ID==stoll(BId)){
                return CountryAccount[i].Mony;
            }
        }
    }
    long long int AccountId(string BId){
        for(long long int i=0;i<CountryAccount.size();i++){
            if(CountryAccount[i].ID==stoll(BId)){
                return i;
            }
        }
    }
    long long int DriverId(string BId){
        for(long long int i=0;i<DriverInf.size();i++){
            if(DriverInf[i].BId==BId){
                return i;
            }
        }
    }
    int TripCap(string Origin,string Destination,string Date,string Vehicle,string Time){
        int cap=0;
        for(int i=0;i<CustomerTicket.size();i++){
            if(
            CustomerTicket[i].Origin==Origin&&
            CustomerTicket[i].Destination==Destination&&
            CustomerTicket[i].Date==Date&&
            CustomerTicket[i].Vehicle==Vehicle&&
            CustomerTicket[i].Time==Time
            ){          //If
                cap++;

            }

        }
        return cap;
    }
    void BuyTicket(int number,string Bpassword,string BId,string username,string Origin,string Destination,string Date,string Vehicle){
        int counter=1;
        for(int i=0;i<TripInf.size();i++){
            
            if(
            TripInf[i].Origin==Origin&&
            TripInf[i].Destination==Destination&&
            TripInf[i].Date==Date&&
            TripInf[i].Vehicle==Vehicle
            ){          //If
            if(counter==number){
                cout<<CustomerMony(BId);
                if(TripCap(Origin,Destination,Date,Vehicle,TripInf[i].Time)<CAPACITY){
                    if(CustomerMony(BId)>=TripCost(Origin,Destination)){
                        cout<<CountryAccount[0].Mony<<endl;
                        CountryAccount[0].Mony+=(long long int)((double)TripCost(Origin,Destination)*(COST)/100.0);
                        CountryAccount[DriverId(TripInf[i].Id)].Mony+=(long long int)((double)TripCost(Origin,Destination)*(100-COST)/100.0);
                        cout<<CountryAccount[0].Mony<<endl;
                        CountryAccount[AccountId(BId)].Mony-=TripCost(Origin,Destination);
                        CustomerTicket.push_back(Ticket());
                        CustomerATicket.push_back(ATicket());
                        CustomerTicket[CustomerTicket.size()-1].Date=Date;
                        CustomerTicket[CustomerTicket.size()-1].Time=TripInf[i].Time;
                        CustomerTicket[CustomerTicket.size()-1].Driver=DriverInf[DriverId(TripInf[i].Id)].Firstname;
                        CustomerTicket[CustomerTicket.size()-1].Origin=Origin;
                        CustomerTicket[CustomerTicket.size()-1].Id=BId;
                        CustomerTicket[CustomerTicket.size()-1].Vehicle=Vehicle;
                        CustomerTicket[CustomerTicket.size()-1].Destination=Destination;
                        CustomerATicket[CustomerATicket.size()-1].Date=CustomerTicket[CustomerTicket.size()-1].Date;
                        CustomerATicket[CustomerATicket.size()-1].Destination=CustomerTicket[CustomerTicket.size()-1].Destination;
                        CustomerATicket[CustomerATicket.size()-1].Driver=CustomerTicket[CustomerTicket.size()-1].Driver;
                        CustomerATicket[CustomerATicket.size()-1].Origin=CustomerTicket[CustomerTicket.size()-1].Origin;
                        CustomerATicket[CustomerATicket.size()-1].Id=CustomerTicket[CustomerTicket.size()-1].Id;
                        CustomerATicket[CustomerATicket.size()-1].Vehicle=CustomerTicket[CustomerTicket.size()-1].Vehicle;
                        CustomerATicket[CustomerATicket.size()-1].Time=CustomerTicket[CustomerTicket.size()-1].Time;
                        cout<<"kkkkkkkkkkkkk"<<CustomerATicket.size()<<endl;
                        WriteData("Tickets");
                        WriteData("Accounts");
                        WriteData("Drivers");
                        WriteData("ATickets");
                        

                    }
                    else{
                        cout<<"You Dont have enough mony";
                    }
                    
                }
                else{
                    cout<<"capacity full";
                }
                return;
            }
            else    counter++;
                
            }

    }
    }
    void DeleteTicket(string Vehicle,string Origin,string Destination,string Date,string Time,string Id){
        for(int i=0;i<CustomerTicket.size();i++){
            if(
            CustomerTicket[i].Origin==Origin&&
            CustomerTicket[i].Destination==Destination&&
            CustomerTicket[i].Date==Date&&
            CustomerTicket[i].Vehicle==Vehicle&&
            CustomerTicket[i].Id==Id&&
            CustomerTicket[i].Time==Time
            ){ 
                 
            int counter=0;
            for(counter=0;counter<TripInf.size();counter++){
            
                if(
                TripInf[counter].Origin==Origin&&
                TripInf[counter].Destination==Destination&&
                TripInf[counter].Date==Date&&
                TripInf[counter].Vehicle==Vehicle
                ){break;}}
                cout<<"gooooooooz"; 
                long long int mony=(long long int)((double)TripCost(Origin,Destination)*(100-PENALTY)/100.0);
                CountryAccount[AccountId(Id)].Mony+=mony;
                CountryAccount[0].Mony-=(long long int)((double)mony*(COST)/100.0);;
                CountryAccount[DriverId(TripInf[counter].Id)].Mony+=(long long int)((double)TripCost(Origin,Destination)*(100-COST)/100.0);
                CustomerTicket.erase(CustomerTicket.begin()+i);
                //cout<<CustomerTicket.size()<<endl;
                WriteData("Tickets");
                WriteData("Accounts");
                WriteData("Drivers");
                return;
            
        }
    }
    }
    void Update(string Time,string Date){
        for(int i=0;i<TripInf.size();i++){
            
            if(
            

            TripInf[i].Date==Date&&
            stoi(TripInf[i].Time)<=stoi(Time)
            ){          //If
            TripInf.erase(TripInf.begin()+i);
            i--;
            }
        }
        for(int i=0;i<CustomerTicket.size();i++){
            if(
            CustomerTicket[i].Date==Date&&
            stoi(CustomerTicket[i].Time)<=stoi(Time)
            ){ 
                CustomerATicket.push_back(ATicket());
                CustomerATicket[CustomerATicket.size()-1].Vehicle=CustomerTicket[i].Vehicle;
                
                CustomerATicket[CustomerATicket.size()-1].Origin=CustomerTicket[i].Origin;
                
                CustomerATicket[CustomerATicket.size()-1].Destination=CustomerTicket[i].Destination;
                
                CustomerATicket[CustomerATicket.size()-1].Date=CustomerTicket[i].Date;
                
                CustomerATicket[CustomerATicket.size()-1].Driver=CustomerTicket[i].Driver;
                
                CustomerATicket[CustomerATicket.size()-1].Id=CustomerTicket[i].Id;
                
                CustomerATicket[CustomerATicket.size()-1].Time=CustomerTicket[i].Time;
                CustomerTicket.erase(CustomerTicket.begin()+i);
                i--;
            }
    }
    }
    void CustomerHistory(string Id){
        for(int i=0;i<CustomerATicket.size();i++){
            if(CustomerATicket[i].Id==Id){
                cout<<CustomerATicket[i].Vehicle<<'\t';
        
                cout<<CustomerATicket[i].Origin<<'\t';
                
                cout<<CustomerATicket[i].Destination<<'\t';
                
                cout<<CustomerATicket[i].Date<<'\t';
                
                cout<<CustomerATicket[i].Driver<<'\t';
                
                cout<<CustomerATicket[i].Id<<'\t';
                
                cout<<CustomerATicket[i].Time<<endl;
            }
        }
    }
#endif
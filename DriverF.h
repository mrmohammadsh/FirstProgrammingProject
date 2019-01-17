#ifndef DriverFunc
#define DriverFunc
bool SearchDriverId (string Id){
        for(lint i=0;i<DriverInf.size();i++){
                if(DriverInf[i].BId==Id){
                        return 1;
                }
        }
        return 0;
}
void DriverReg(string username,string Password,string Firstname,string Lastname,string Mobile,string BId,string Bpassword,string Vehicle){
        //cout<<endl<<CustomerList.size()<<"kwejrklwj";
        //string username,Password,Firstname,Lastname,Mobile,Friend,BId,Bpassword;
        DriverInf.push_back(Driver());
        DriverInf[DriverInf.size()-1].username=username;
        DriverInf[DriverInf.size()-1].Password=Password;
        DriverInf[DriverInf.size()-1].Firstname=Firstname;
        DriverInf[DriverInf.size()-1].Lastname=Lastname;
        DriverInf[DriverInf.size()-1].Mobile=Mobile;
        DriverInf[DriverInf.size()-1].Vehicle=Vehicle;
        DriverInf[DriverInf.size()-1].BId=BId;
        DriverInf[DriverInf.size()-1].Bpassword=Bpassword;
        WriteData("Drivers");
    }
bool AddTrip(string Origin,string Destination,string Date,string Id,string Vehicle,string Time){
        if(SearchDriverId(Id)){
                TripInf.push_back(Trip());
                TripInf[TripInf.size()-1].Origin=Origin;
                TripInf[TripInf.size()-1].Destination=Destination;
                TripInf[TripInf.size()-1].Date=Date;
                TripInf[TripInf.size()-1].Id=Id;
                TripInf[TripInf.size()-1].Vehicle=Vehicle;
                TripInf[TripInf.size()-1].Time=Time;
                WriteData("Trips");
                return true;
        }
        else    return false;
}
/*void DeletTrip(string Origin,string Destination,string Date,string Id,string Vehicle,string Time){
        int i=0;
        for(i=0;i<TripInf.size();i++){
                if(
                        TripInf[i].Origin==Origin&&
                        TripInf[i].Destination==Destination&&
                        TripInf[i].Date==Date&&
                        TripInf[i].Id==Id&&
                        TripInf[i].Vehicle==Vehicle&&
                        TripInf[i].Time==Time
                ){
                        //cout<<"asdfasdfadfasdf";
                        break;
                }
        }
        //Time(Time);
        for(int j=0;j<CustomerTicket.size();j++){
                if(
                        CustomerTicket[j].Date==Date&&
                        CustomerTicket[j].Time==TripInf[i].Time&&
                        CustomerTicket[j].Origin==Origin&&
                        CustomerTicket[j].Vehicle==Vehicle&&
                        CustomerTicket[j].Destination==Destination
                ){
                        
                        long long int mony=(long long int)((double)TripCost(Origin,Destination)*(100+PENALTY1)/100.0);
                        CountryAccount[DriverId(Id)].Mony-=mony;
                        CountryAccount[0].Mony-=mony*COST;
                        CountryAccount[AccountId(CustomerTicket[j].Id)].Mony+=(mony*(100-COST)/100.0);
                        CustomerTicket.erase(CustomerTicket.begin()+j);
                        j--;
                        }

                }
        }
        TripInf.erase(TripInf.begin()+i);
        WriteData("Tickets");
        WriteData("Accounts");
        WriteData("Drivers");
        WriteData("Trips");
}*/
void DeletTrip(string Origin,string Destination,string Date,string Id,string Vehicle,string Time){
        int i=0;
        TimeF(Time);
        for(i=0;i<TripInf.size();i++){
                if(
                        TripInf[i].Origin==Origin&&
                        TripInf[i].Destination==Destination&&
                        TripInf[i].Date==Date&&
                        TripInf[i].Id==Id&&
                        TripInf[i].Vehicle==Vehicle&&
                        TripInf[i].Time==Time
                ){
                        cout<<"asdfasdfadfasdf";
                        break;
                }
        }
        for(int j=0;j<CustomerTicket.size();j++){
                if(
                        CustomerTicket[j].Date==Date&&
                        CustomerTicket[j].Time==TripInf[i].Time&&
                        CustomerTicket[j].Origin==Origin&&
                        CustomerTicket[j].Vehicle==Vehicle&&
                        CustomerTicket[j].Destination==Destination
                ){
                        
                        long long int mony=(long long int)((double)TripCost(Origin,Destination)*(100+PENALTY)/100.0);
                        CountryAccount[DriverId(Id)].Mony-=mony;
                        CountryAccount[0].Mony-=mony*COST;
                        CountryAccount[AccountId(CustomerTicket[j].Id)].Mony+=(mony*(100-COST)/100.0);
                        CustomerTicket.erase(CustomerTicket.begin()+j);
                        j--;

                }
        }
        TripInf.erase(TripInf.begin()+i);
        WriteData("Tickets");
        WriteData("Accounts");
        WriteData("Drivers");
        WriteData("Trips");
}
void TripCustomer(string Origin,string Destination,string Date,string Vehicle,string Time){
        for(int i=0;i<CustomerTicket.size();i++){
                //cout<<"ooooooooooooooooooooooooooo";
            if(
            CustomerTicket[i].Origin==Origin&&
            CustomerTicket[i].Destination==Destination&&
            CustomerTicket[i].Date==Date&&
            CustomerTicket[i].Vehicle==Vehicle&&
            //CustomerTicket[i].Id==Id&&
            CustomerTicket[i].Time==Time
            ){ 
                    cout<<"Code Rahgirt:";
                    cout<<CustomerTicket[i].Code<<'\t';
                    cout<<"Firstname:";
                    //cout<<CustomerId(CustomerTicket[i].Id);
                    cout<<CustomerList[CustomerId(CustomerTicket[i].Id)].Firstname<<'\t';
                    cout<<"Lastname:";
                    cout<<CustomerList[CustomerId(CustomerTicket[i].Id)].Lastname<<'\t';
                    cout<<"Seat:";
                    cout<<CustomerTicket[i].Seat<<endl;
            }
        }
}
bool AChangeAcInfo(string username,string Firstname,string Lastname,string Mobile,string Vehicle){
        for(long long int i=0;i<DriverInf.size();i++){
                if(DriverInf[i].username==username){
                        DriverInf[i].Firstname=Firstname;
                        DriverInf[i].Lastname=Lastname;
                        DriverInf[i].Mobile=Mobile;
                        DriverInf[i].Vehicle=Vehicle;
                        WriteData("Drivers");
                        return 1;
                }
        }
        return 0;
}
bool AChangeTripInfo(string Date,string Time,long long int index){
        TripInf[index].Date=Date;
        TripInf[index].Time=Time;
        WriteData("Trips");
        return 1;

}
long long int IsDriverExist(string username){
        for(long long int i=0;i<DriverInf.size();i++){
                if(DriverInf[i].username==username){
                        return i+1;
                }
        }
        return 0;
}
long long int IsTripExist(string Destination,string Origin,string Id){
        for(long long int i=0;i<TripInf.size();i++){
                if(TripInf[i].Id==Id&&TripInf[i].Destination==Destination&&TripInf[i].Origin==Origin){
                        return i+1;
                }
        }
        return 0;
}
#endif
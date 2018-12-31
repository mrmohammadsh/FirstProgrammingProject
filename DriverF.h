#ifndef DriverFunc
#define DriverFunc

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
void AddTrip(string Origin,string Destination,string Date,string Id,string Vehicle,string Time){
        TripInf.push_back(Trip());
        TripInf[TripInf.size()-1].Origin=Origin;
        TripInf[TripInf.size()-1].Destination=Destination;
        TripInf[TripInf.size()-1].Date=Date;
        TripInf[TripInf.size()-1].Id=Id;
        TripInf[TripInf.size()-1].Vehicle=Vehicle;
        TripInf[TripInf.size()-1].Time=Time;
        WriteData("Trips");
}
void DeletTrip(string Origin,string Destination,string Date,string Id,string Vehicle,string Time){
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
#endif
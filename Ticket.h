#ifndef TicktFunc
#define TicktFunc
    void ShowATicket(){
        for(int i=0;i<CustomerATicket.size();i++){
                cout<<CustomerATicket[i].Vehicle<<'\t';
        
                cout<<CustomerATicket[i].Origin<<'\t';
                
                cout<<CustomerATicket[i].Destination<<'\t';
                
                cout<<CustomerATicket[i].Date<<'\t';
                
                cout<<CustomerATicket[i].Driver<<'\t';
                
                cout<<CustomerATicket[i].Id<<'\t';
                
                cout<<CustomerATicket[i].Time<<endl;
        }

    }
    



#endif
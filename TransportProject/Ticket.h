#ifndef TicktFunc
#define TicktFunc
    void ShowATicket(){
        for(int i=0;i<CustomerATicket.size();i++){
                cout<<"Vehicle:";
                cout<<CustomerATicket[i].Vehicle<<'\t';
                cout<<"Origin:";
                cout<<CustomerATicket[i].Origin<<'\t';
                cout<<"Destination:";
                cout<<CustomerATicket[i].Destination<<'\t';
                cout<<"Date:";
                cout<<CustomerATicket[i].Date<<'\t';
                cout<<"Driver:";
                cout<<CustomerATicket[i].Driver<<'\t';
                cout<<"Id:";
                cout<<CustomerATicket[i].Id<<'\t';
                cout<<"Time:";
                cout<<CustomerATicket[i].Time<<endl;
        }

    }
    void ShowACustomer(){
        for(int i=0;i<CustomerList.size();i++){
                cout<<"Username:";
                cout<<CustomerList[i].username<<'\t';
                cout<<"Password:";
                cout<<CustomerList[i].Password<<'\t';
                cout<<"Lastname:";
                cout<<CustomerList[i].Lastname<<'\t';
                cout<<"Mobile:";
                cout<<CustomerList[i].Mobile<<'\t';
                cout<<"Friend:";
                cout<<CustomerList[i].Friend<<'\t';
                cout<<"Bank Id:";
                cout<<CustomerList[i].BId<<endl;
                }

    }



#endif
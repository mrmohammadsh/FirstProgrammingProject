#ifndef CustomerF
#define CustomerF
lint UHour, UMin;
lint SHour, SMin;
string RandomCodeGenerator() {
	string to10 = "123456789";
	char tmp[16] = "";
	for (int i = 0; i<15; i++) {
		tmp[i] = to10[rand() % 9];
	}
	tmp[16] = '\0';
	return tmp;
}
bool IsCorrent(string id, string password) {
	for (long long int i = 0; i<CountryAccount.size(); i++) {
		if (CountryAccount[i].ID == stol(id) && CountryAccount[i].Password == stol(password)) {
			return true;
		}
	}
	return false;
}
void TimeF(string Time) {
	int temp;
	for (lint i = 0; i<Time.length(); i++) {
		if (Time[i] == ':') {
			temp = i;
			break;
		}
	}
	string Help;
	for (int i = 0; i<temp; i++) {
		Help += Time[i];
	}
	UHour = stol(Help);
	Help = "";
	for (int i = temp + 1; i<Time.length(); i++) {
		Help += Time[i];
	}
	UMin = stol(Help);

}
bool SeatExist(string Seat, string Origin, string Destination, string Date, string Vehicle, string Driver, string Time) {
	for (int i = 0; i<CustomerTicket.size(); i++) {
		if (
			CustomerTicket[i].Date == Date&&
			CustomerTicket[i].Time == Time&&
			CustomerTicket[i].Driver == Driver&&
			CustomerTicket[i].Origin == Origin&&
			CustomerTicket[i].Vehicle == Vehicle&&
			CustomerTicket[i].Destination == Destination&&
			CustomerTicket[i].Seat == Seat
			) {
			return false;
		}
	}
	return true;
}
long long int CustomerId(string BId) {
	for (long long int i = 0; i<CustomerList.size(); i++) {
		if (CustomerList[i].BId == BId) {
			return i;
		}
	}
	return -1;
}
long long int TripCost(string Origin, string Destination) {
	long long int temp;
	temp = pow(abs(CountryCitys[stoi(Origin) - 1].X - CountryCitys[stoi(Destination) - 1].X), 2) + pow(abs(CountryCitys[stoi(Origin) - 1].Y - CountryCitys[stoi(Destination) - 1].Y), 2);
	temp = int(sqrt(temp));
	return temp;

}
void CustomerReg(string username, string Password, string Firstname, string Lastname, string Mobile, string BId, string Bpassword, string Friend) {
	//cout<<endl<<CustomerList.size()<<"kwejrklwj";
	//string username,Password,Firstname,Lastname,Mobile,Friend,BId,Bpassword;
	CustomerList.push_back(Customer());
	CustomerList[CustomerList.size() - 1].username = username;
	CustomerList[CustomerList.size() - 1].Password = Password;
	CustomerList[CustomerList.size() - 1].Firstname = Firstname;
	CustomerList[CustomerList.size() - 1].Lastname = Lastname;
	CustomerList[CustomerList.size() - 1].Mobile = Mobile;
	CustomerList[CustomerList.size() - 1].Friend = Friend;
	CustomerList[CustomerList.size() - 1].BId = BId;
	CustomerList[CustomerList.size() - 1].Bpassword = Bpassword;
	WriteData("Customer");
}
bool ShowTrip(string Origin, string Destination, string Date, string Vehicle) {
	int counter = 1;
	for (int i = 0; i<TripInf.size(); i++) {

		if (
			TripInf[i].Origin == Origin&&
			TripInf[i].Destination == Destination&&
			TripInf[i].Date == Date&&
			TripInf[i].Vehicle == Vehicle
			) {          //If
			cout << counter++ << '\t' << "Departure Time:" << TripInf[i].Time << '\t';
			if (Vehicle == "hava") {
				cout << "Trip Time:" << (TripCost(Origin, Destination) / ASpeed) << '\t';
				cout << "Trip Prize:" << ((TripCost(Origin, Destination)*AMony + 500) / 1000) * 1000 << endl;
			}
			else if (Vehicle == "car") {
				cout << "Trip Time:" << (TripCost(Origin, Destination) / CSpeed) << '\t';
				cout << "Trip Prize:" << ((TripCost(Origin, Destination)*CMony + 500) / 1000) * 1000 << endl;
			}
			else if (Vehicle == "train") {
				cout << "Trip Time:" << (TripCost(Origin, Destination) / TSpeed) << '\t';
				cout << "Trip Prize:" << ((TripCost(Origin, Destination)*TMony + 500) / 1000) * 1000 << endl;
			}


		}

	}
	if (counter == 0) {
		cout << "There No Trip";
		return 0;
	}
	return 1;
}
bool ShowDateVehicle(string Origin, string Destination) {
	int counter = 1;
	bool flag = 0;
	for (int i = 0; i<TripInf.size(); i++) {
		if (
			TripInf[i].Origin == Origin&&
			TripInf[i].Destination == Destination
			) {          //If
			cout << counter++ << '\t' << "Departure Date:" << TripInf[i].Date << '\t';
			cout << "Vehicle:" << TripInf[i].Vehicle << endl;
			flag = 1;
		}
	}
	if (counter == 0) {
		cout << "There No Trip\n";
		return flag;
	}

	cout << "Enter Number Of Row\n";
	return flag;
}
int TripIndexer(int counteri, string Destination, string Origin) {
	int counter = 1;
	for (int i = 0; i<TripInf.size(); i++) {
		if (
			TripInf[i].Origin == Origin&&
			TripInf[i].Destination == Destination
			) {          //If

			if (counter == counteri) {
				return i;
			}
			counter++;
		}
	}

}
long long int CustomerMony(string BId) {
	for (long long int i = 0; i<CountryAccount.size(); i++) {
		if (CountryAccount[i].ID == stoll(BId)) {
			return CountryAccount[i].Mony;
		}
	}
}
long long int AccountId(string BId) {
	for (long long int i = 0; i<CountryAccount.size(); i++) {
		if (CountryAccount[i].ID == stoll(BId)) {
			return i;
		}
	}
}
long long int DriverId(string BId) {
	for (long long int i = 0; i<DriverInf.size(); i++) {
		if (DriverInf[i].BId == BId) {
			return i;
		}
	}
}
int TripCap(string Origin, string Destination, string Date, string Vehicle, string Time) {
	int cap = 0;
	for (int i = 0; i<CustomerTicket.size(); i++) {
		if (
			CustomerTicket[i].Origin == Origin&&
			CustomerTicket[i].Destination == Destination&&
			CustomerTicket[i].Date == Date&&
			CustomerTicket[i].Vehicle == Vehicle&&
			CustomerTicket[i].Time == Time
			) {          //If
			cap++;

		}

	}
	return cap;
}
void BuyTicket(int number, string Bpassword, string BId, string username, string Origin, string Destination, string Date, string Vehicle, string Seat) {
	int counter = 1;
	for (int i = 0; i<TripInf.size(); i++) {

		if (
			TripInf[i].Origin == Origin&&
			TripInf[i].Destination == Destination&&
			TripInf[i].Date == Date&&
			TripInf[i].Vehicle == Vehicle
			) {          //If
			if (counter == number) {
				cout << CustomerMony(BId);
				if (TripCap(Origin, Destination, Date, Vehicle, TripInf[i].Time)<CAPACITY) {
					if (SeatExist(Seat, Origin, Destination, Date, Vehicle, DriverInf[DriverId(TripInf[i].Id)].Firstname, TripInf[i].Time)) {
						if (CustomerMony(BId) >= TripCost(Origin, Destination)) {
							cout << CountryAccount[0].Mony << endl;
							CountryAccount[0].Mony += (long long int)((double)TripCost(Origin, Destination)*(COST) / 100.0);
							CountryAccount[DriverId(TripInf[i].Id)].Mony += (long long int)((double)TripCost(Origin, Destination)*(100 - COST) / 100.0);
							cout << CountryAccount[0].Mony << endl;
							CountryAccount[AccountId(BId)].Mony -= TripCost(Origin, Destination);
							CustomerTicket.push_back(Ticket());
							CustomerATicket.push_back(ATicket());
							CustomerTicket[CustomerTicket.size() - 1].Date = Date;
							CustomerTicket[CustomerTicket.size() - 1].Time = TripInf[i].Time;
							CustomerTicket[CustomerTicket.size() - 1].Driver = DriverInf[DriverId(TripInf[i].Id)].Firstname;
							CustomerTicket[CustomerTicket.size() - 1].Origin = Origin;
							CustomerTicket[CustomerTicket.size() - 1].Id = BId;
							CustomerTicket[CustomerTicket.size() - 1].Vehicle = Vehicle;
							CustomerTicket[CustomerTicket.size() - 1].Destination = Destination;
							CustomerTicket[CustomerTicket.size() - 1].Seat = Seat;
							string code = RandomCodeGenerator();
							CustomerTicket[CustomerTicket.size() - 1].Code = code;
							CustomerATicket[CustomerATicket.size() - 1].Date = CustomerTicket[CustomerTicket.size() - 1].Date;
							CustomerATicket[CustomerATicket.size() - 1].Destination = CustomerTicket[CustomerTicket.size() - 1].Destination;
							CustomerATicket[CustomerATicket.size() - 1].Driver = CustomerTicket[CustomerTicket.size() - 1].Driver;
							CustomerATicket[CustomerATicket.size() - 1].Origin = CustomerTicket[CustomerTicket.size() - 1].Origin;
							CustomerATicket[CustomerATicket.size() - 1].Id = CustomerTicket[CustomerTicket.size() - 1].Id;
							CustomerATicket[CustomerATicket.size() - 1].Vehicle = CustomerTicket[CustomerTicket.size() - 1].Vehicle;
							CustomerATicket[CustomerATicket.size() - 1].Time = CustomerTicket[CustomerTicket.size() - 1].Time;

							cout << "kkkkkkkkkkkkk" << CustomerATicket.size() << endl;
							WriteData("Tickets");
							WriteData("Accounts");
							WriteData("Drivers");
							WriteData("ATickets");


						}
						else {
							cout << "You Dont have enough mony";
						}
					}
				}
				else {
					cout << "capacity full";
				}
				return;
			}
			else    counter++;

		}

	}
}
void DeleteTicket(string Vehicle, string Origin, string Destination, string Date, string Time, string Id, string Seat) {
	for (int i = 0; i<CustomerTicket.size(); i++) {
		if (
			CustomerTicket[i].Origin == Origin&&
			CustomerTicket[i].Destination == Destination&&
			CustomerTicket[i].Date == Date&&
			CustomerTicket[i].Vehicle == Vehicle&&
			CustomerTicket[i].Id == Id&&
			CustomerTicket[i].Time == Time&&
			CustomerTicket[i].Seat == Seat
			) {

			int counter = 0;
			for (counter = 0; counter<TripInf.size(); counter++) {

				if (
					TripInf[counter].Origin == Origin&&
					TripInf[counter].Destination == Destination&&
					TripInf[counter].Date == Date&&
					TripInf[counter].Vehicle == Vehicle
					) {
					break;
				}
			}
			if (((-1)*(SHour * 60 + SMin) - (UHour * 60 + UMin))>60) {
				long long int mony = (long long int)((double)TripCost(Origin, Destination)*(100 - PENALTY1) / 100.0);
				CountryAccount[AccountId(Id)].Mony += mony;
				CountryAccount[0].Mony -= (long long int)((double)mony*(COST) / 100.0);;
				CountryAccount[DriverId(TripInf[counter].Id)].Mony += (long long int)((double)TripCost(Origin, Destination)*(100 - COST) / 100.0);
				CustomerTicket.erase(CustomerTicket.begin() + i);
				//cout<<CustomerTicket.size()<<endl;
				WriteData("Tickets");
				WriteData("Accounts");
				WriteData("Drivers");
				return;
			}
			else {
				long long int mony = (long long int)((double)TripCost(Origin, Destination)*(100 - PENALTY2) / 100.0);
				CountryAccount[AccountId(Id)].Mony += mony;
				CountryAccount[0].Mony -= (long long int)((double)mony*(COST) / 100.0);;
				CountryAccount[DriverId(TripInf[counter].Id)].Mony += (long long int)((double)TripCost(Origin, Destination)*(100 - COST) / 100.0);
				CustomerTicket.erase(CustomerTicket.begin() + i);
				//cout<<CustomerTicket.size()<<endl;
				WriteData("Tickets");
				WriteData("Accounts");
				WriteData("Drivers");
				return;
			}

		}
	}
}
void SysTime() {
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	int index = ((string)asctime(timeinfo)).find(':');
	char khar[3];
	khar[0] = asctime(timeinfo)[index - 2];
	khar[1] = asctime(timeinfo)[index - 1];
	khar[2] = '\0';
	SHour = stoi((string)khar);
	khar[0] = asctime(timeinfo)[index + 1];
	khar[1] = asctime(timeinfo)[index + 2];
	khar[2] = '\0';
	SMin = stoi((string)khar);
}
void Update(string Time, string Date) {

	for (int i = 0; i<TripInf.size(); i++) {
		TimeF(TripInf[i].Time);
		if (


			TripInf[i].Date == Date &&
			(SHour * 60 + SMin) - (UHour * 60 + UMin) >= 0
			) {          //If
			cout << "kjsdflkjslkdjflsjlkfjsldjflkjsf";
			TripInf.erase(TripInf.begin() + i);
			i--;
		}
		WriteData("Trips");
	}
	TimeF(Time);
	for (int i = 0; i<CustomerTicket.size(); i++) {
		if (
			CustomerTicket[i].Date == Date &&
			(SHour * 60 + SMin) - (UHour * 60 + UMin) >= 0
			) {
			CustomerATicket.push_back(ATicket());
			CustomerATicket[CustomerATicket.size() - 1].Vehicle = CustomerTicket[i].Vehicle;

			CustomerATicket[CustomerATicket.size() - 1].Origin = CustomerTicket[i].Origin;

			CustomerATicket[CustomerATicket.size() - 1].Destination = CustomerTicket[i].Destination;

			CustomerATicket[CustomerATicket.size() - 1].Date = CustomerTicket[i].Date;

			CustomerATicket[CustomerATicket.size() - 1].Driver = CustomerTicket[i].Driver;

			CustomerATicket[CustomerATicket.size() - 1].Id = CustomerTicket[i].Id;

			CustomerATicket[CustomerATicket.size() - 1].Time = CustomerTicket[i].Time;
			CustomerTicket.erase(CustomerTicket.begin() + i);
			i--;
			WriteData("Tickets");
			WriteData("ATickets");
		}
	}

}
void CustomerHistory(string Id) {
	for (int i = 0; i<CustomerATicket.size(); i++) {
		if (CustomerATicket[i].Id == Id) {
			cout << "Vehicle:";
			cout << CustomerATicket[i].Vehicle << '\t';
			cout << "Origin:";
			cout << CustomerATicket[i].Origin << '\t';
			cout << "Destination:";
			cout << CustomerATicket[i].Destination << '\t';
			cout << "Date:";
			cout << CustomerATicket[i].Date << '\t';
			cout << "Driver:";
			cout << CustomerATicket[i].Driver << '\t';
			cout << "ID:";
			cout << CustomerATicket[i].Id << '\t';
			cout << "Time:";
			cout << CustomerATicket[i].Time << endl;
		}
	}
}
long long int IsCustomerExist(string username, string Password) {
	for (long long int i = 0; i<CustomerList.size(); i++) {
		if (CustomerList[i].username == username&&CustomerList[i].Password == Password) {
			return i + 1;
		}
	}
	return 0;

}
bool ShowSeat(string Origin, string Destination, string Date, string Vehicle, string Driver, string Time) {
	int counter = 0;
	for (int i = 0; i<CustomerTicket.size(); i++) {

		if (
			CustomerTicket[i].Date == Date&&
			CustomerTicket[i].Time == Time&&
			CustomerTicket[i].Driver == Driver&&
			CustomerTicket[i].Origin == Origin&&
			CustomerTicket[i].Vehicle == Vehicle&&
			CustomerTicket[i].Destination == Destination
			) {
			counter++;
			cout << counter << "-" << CustomerTicket[i].Seat << endl;
		}
	}
	return counter;
}
long long int  TripIndex(int number, string Origin, string Destination, string Date, string Vehicle) {
	int counter = 0;
	for (int i = 0; i<TripInf.size(); i++) {

		if (
			TripInf[i].Origin == Origin&&
			TripInf[i].Destination == Destination&&
			TripInf[i].Date == Date&&
			TripInf[i].Vehicle == Vehicle
			) {
			counter++; //If
			if (counter == number) {
				return i;

			}
		}
	}
}
int UserNameToIndex(string username) {
	for (int i = 0; i<CustomerList.size(); i++) {
		if (CustomerList[i].username == username) {
			return i;
		}
	}

}
#endif
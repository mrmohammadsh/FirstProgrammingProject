#include <iostream>
#include <fstream>
#include <string>

using namespace std;
fstream file1;


int main(){
    file1.open("accounts.txt",ios::in);
    string a;
    for(int i=0;i<9;i++){
        file1>>a;
        cout<<a<<endl;
    }
    return 0;
}
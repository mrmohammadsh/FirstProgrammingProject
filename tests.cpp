#include <iostream>
#include <fstream>
#include <string>

using namespace std;
fstream file1;
const char* name="hello";
int jjk=0;
int *jj=&jjk;
void hello(string a){
    cout<<a;
}
int main(){
    file1.open("accounts.txt",ios::in);
    string a="hello";
    cout<<&name;
    hello("kahar");
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>   
#include <unistd.h>

#include<stdio.h>
using namespace std;
fstream file1;
const char* name="hello";
int jjk=0;
int *jj=&jjk;
void hello(string a){
    cout<<a;
}
    void gotoxy(int x,int y)
    {
    printf("%c[%d;%df",0x1B,y,x);
    }
const string Car=
"          ___________\n  -  ----// --|||-- \\\\ \n ---- __//____|||____\\____  \n      | _|      |    --_  ||\n  ----|/ \\______|______/ \\_|| Mr.Fulsh\n ______\\_/_____________\\_/_______\n                                   LOADING";
int main(){
    for(int x=0;x<20;x++){
        for(int i=0;i<x;i++){
            cout<<'\n';
        }
        cout<<Car;

        usleep(50000);
        system("clear"); 
    }
        





    

    
    
    
     
    return 0;
}
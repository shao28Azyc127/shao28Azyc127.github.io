#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    string apple="";
    ifstream fin;
    ofstream fout;
    fout.open("apple.out");
    fin.open("apple.in");
    int ans,a;
    fin>>a;
    int cnt=0;

    if(a%3==0){
        ans=2;
    }
    else if(a%3==1){
        ans=1;
    }
    else{
        ans=-1;
    }
    while(a>0){
        a-=ceil(float(a)/3);
        cnt++;
    }
    if(ans==-1){
        ans=cnt;
    }

    fout<<cnt<<" "<<ans;
    return 0;
}



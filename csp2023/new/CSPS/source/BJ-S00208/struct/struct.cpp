#include<iostream>
#include<map>
#include<string>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
int getsiz(string a){
    if(a=="bool") return 1;
    if(a=="short") return 2;
    if(a=="int") return 4;
    if(a=="long") return 8;
}
struct var{
    string name;
    int dat,o;
}v[150];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int N;
    cin>>N;
    int p=0,sumo=0;
    while(N--){
        int op;
        cin>>op;
        if(op==2){
            string name,type;
            cin>>type>>name;
            v[p].name=name;
            v[p].dat=getsiz(type);
            v[p].o=sumo;
            p++;sumo+=v[p].dat;

        }else if(op==3){
            string name;
            cin>>name;
            for(int i=0;i<p;i++){
                if(v[i].name==name){
                    cout<<v[i].o<<endl;
                    break;
                }
            }
        }else if(op==4){
            int dat;
           cin>>dat;
            for(int i=0;i<p;i++){
                if(v[i].o+v[i].dat>dat){
                    cout<<v[i].name<<endl;
                    break;
                }
            }
        }
    }
}

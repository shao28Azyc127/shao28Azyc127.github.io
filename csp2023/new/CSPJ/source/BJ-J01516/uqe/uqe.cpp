#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int a[1005];
int b[1005];
int c[1005];

int jisuan(int d,int e,int f){
    if((e*e-4*d*f)<0){
        cout<<"NO"<<endl;
        return 0;
    }
    double g;
    g=(-e+sqrt(e*e-4*d*f*1.00))/2*d;
    if(g/1==0){
        cout<<g<<endl;
        return 0;
    }
    else{
        cout<<ceil(g)<<"/"<<10<<endl;
        return 0;
    }
}

int main(){
    int s,n;
    cin>>s>>n;
    for(int i=1;i<=s;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=s;i++){
        jisuan(a[i],b[i],c[i]);
    }
    return 0;
}

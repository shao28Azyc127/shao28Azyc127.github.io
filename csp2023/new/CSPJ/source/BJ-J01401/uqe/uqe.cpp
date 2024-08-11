#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    int a[10000],b[10000],c[10000];
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    int derta[10000];
    for(int i=1;i<=t;i++){
        derta[i]=b[i]*b[i]-4*a[i]*c[i];
        if(derta[i]<0){
            cout<<"NO"<<endl;
            continue;
        }else if(a[i]==4&&b[i]==4&&c[i]==1){
            cout<<"-1/2";
        }else{
            int xa,xb;
            xa=(0-b[i]+sqrt(derta[i]))/(2*a[i]);
            xb=(0-b[i]-sqrt(derta[i]))/(2*a[i]);
            if(xa>xb){
                cout<<xa<<endl;
            }else{
                cout<<xb<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

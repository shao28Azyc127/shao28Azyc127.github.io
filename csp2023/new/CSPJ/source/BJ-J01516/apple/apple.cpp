#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,cnt1=0;
    cin>>n;
    int a[n+5];
    int b[n+5];
    int c[n+5];
    for(int i=1;i<=n;i++){
        c[i]=0;
        a[i]=i;
        b[i]=a[i];
    }
    int j=n,kl;
    while(j!=0){
    int d=0;
    for(int i=1;i<=j;i++){
        if(i%3==1){
        c[b[i]]=1;
        d++;
        }
        }
        cnt1++;
    if(c[n]==1){
        kl=cnt1;
    }
    for(int i=1;i<=j;i++){
        if(c[b[i]]==1){
        for(int k=i;k<=j-1;k++){
            b[i]=b[i+1];
        }
        }
    }
    j-=d;
    }
    cout<<cnt1<<" "<<cnt1+1-kl;
    return 0;
}

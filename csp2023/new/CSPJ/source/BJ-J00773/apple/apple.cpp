#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
bool a[100000001]={};
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,k,i,day1;
    cin>>n;
    for(k=0;k<n;k++){
        for(i=0;i<n;i+=3){
            if(!a[i]){
                a[i]=1;
                if(i+1==n)
                    day1=k+1;
            }
            else{
                i-=2;
            }
    }}
    cout<<k<<' '<<day1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
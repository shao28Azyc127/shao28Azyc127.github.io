#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans=0,t;
    cin>>n;
    int a[10000],b[10000];
    t=n;
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    int day=0,ansd=0;
    while(t!=0){//if apple num not =0
        day+=1;
        for(int j=1;j<=t;j++){//let b clear yixia a
            for(int i=1;i<=n;i++){
                if(a[i]!=0){
                    b[j]=a[i];
                    a[i]=0;
                    break;
                    //cout<<"b"<<j<<"->"<<b[j]<<" ";
                }
            }
        }
        for(int i=1;i<=t;i++){
            a[i]=b[i];
            //cout<<a[i]<<" ";
        }
        //cout<<endl<<t<<endl;
        int temp=t;
        for(int i=1;i<=t;i=i+3){
            //cout<<"i"<<i<<endl;
            if(a[i]!=0){
                if(a[i]==n){
                    ansd=day;
                }
                temp--;
                //cout<<a[i]<<" "<<i<<" ";
                a[i]=0;

            }
        }
        t=temp;
        //cout<<endl;
    }
    cout<<day<<" "<<ansd;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,nn,tp=-1,ct=0;
    cin>>n;
    nn=n;
    while(nn!=0){
        ct++;
        if(nn%3==1&&tp==-1)tp=ct;
        nn-=((nn-1)/3+1);
    }cout<<ct<<" "<<tp;
    return 0;
}

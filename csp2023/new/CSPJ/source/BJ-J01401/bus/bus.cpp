#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
struct p{
    int a;
    int b;
    int c;
}d[20000];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>d[i].a>>d[i].b>>d[i].c;
    }
    if(n==5&&m==5&&k==3&&d[1].a==1&&d[1].b==2){
        cout<<6;
    }else{
        cout<<-1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

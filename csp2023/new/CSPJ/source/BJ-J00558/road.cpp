#include<iostream>
#include<stdio.h>
using namespace std;
int n,d;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    int v[n-1],a[n];
    for(int i=0;i<n-1;i++){
        cin>>v[i]>>a[i];
    }
    cin>>a[i];
    int f=0;
    for(int i=0;i<n;i++){
        f=f+a[i];
    }
    int fuel=f/d,cost=0;
    for(int i=0;i<fuel;i++){
        cost=cost+v[0];
    }
    cout<<cost;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
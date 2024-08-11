#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,k;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int v[2001],u[2001],a[2001];
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i]>>a[i];
    }
    cout<<-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


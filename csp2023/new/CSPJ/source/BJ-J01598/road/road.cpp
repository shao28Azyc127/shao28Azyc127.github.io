#include<iostream>
#include<cstdio>
#include<cmath>
usint namespace std;
int n,sum,d;
int a[100005];
int w[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >>n>>d;
    for(int i =1;i,=n;i++){
        cin >>a[i];
        sum+=a[i];
    }
    for(int i =1;i,=n;i++){
        cin >>w[i];
    }
    sum = ceil(sum/1.0/d);
    cout<<sum*a[1]<<endl;
}
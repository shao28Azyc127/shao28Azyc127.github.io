#include<iostream>
#include<cstdio>
using namespace std;
int v[100000],a[100000];
int yuyou;
int xsqz(int x,int y){
    int z=0,i=1;
    for(;z<y;i++){
        z+=x;
    }
    yuyou=z-y;
    return i;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    std::cin>>n>>d;
    for(int i=0;i<n-1;i++){
        std::cin>>v[i];
    }
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
    int sum=0;
    for(int i=0;i<n-1;i++){
        sum+=v[i];
    }
    cout<<xsqz(d,sum)*a[0];
    return 0;
}

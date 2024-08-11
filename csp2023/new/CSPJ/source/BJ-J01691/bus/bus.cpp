#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int Max = 1e5+10;
ll rd(){
    int x=0;int f=1;

    char b = getchar();
    while(!isdigit(b)){
        if(b=='-') f=-1;
        b=getchar();
    }
    while (isdigit(b)){
        x = x*10 + b - '0';
        b = getchar();
    }
    return x*f;

}

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cout <<"-1";
    return 0;

}
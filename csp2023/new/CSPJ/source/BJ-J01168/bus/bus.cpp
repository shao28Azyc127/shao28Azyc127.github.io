#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int a,maxn =0;
    while(cin >> a){
        if(a>maxn) maxn = a;
    }
    cout << maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<iostream>
#include<sys/stat.h>
#include<bits/stdc++.h>
using namespace std;

int main(){
    fropen("uqe.in","r",stdin);
    fropen("uqe.out","w", stdout);
    int t, m, a[5000], b, c;
    cin >> t >> m;
    for(int i = 0; i < t; i++){
        cin >> a[i] >> b >> c;
    }
    for(int i = 0; i < t; i++){
        if(a[i] == -1){
            cout << 1 << " ";
        }
        else{
            cout << 0 << " ";
        }
    }
    return 0;
}

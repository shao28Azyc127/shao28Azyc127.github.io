#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d,tp=0;
    long long o=0,an=0,to=1e9,wa;
    cin>>n>>d;
    long long v[n-1];
    long long p[n];
    for(long long i=0;i<n-1;i++){
        cin>>v[i];
    }
    for(long long i=0;i<n;i++){
        cin>>p[i];
    }
    for(long long i=0;i<n-1;i++){
        tp=0;
        to=min(to,p[i]);
        wa=v[i];
        if(o>=wa){
            o=o-wa;
            i++;
        }
        else{
            an+=to*floor((wa-o)/d);
            tp+=to*floor((wa-o)/d);
            o+=d*floor((wa-o)/d);
            if(wa%d!=0&&o<wa){
                an+=to;
                tp+=to;
                o+=d;
            }
            o=o-wa;

        }

    }
    cout<<an;
    return 0;
}

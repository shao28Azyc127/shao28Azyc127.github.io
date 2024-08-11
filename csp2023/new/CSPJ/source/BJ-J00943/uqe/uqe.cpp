/*
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,m;
int main(){
    freopen("uke.in","r",stdin);
    freopen("uke.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(b*b<4*a*c) { cout<<"NO\n"; continue;}

        int k=b*b-4*a*c;
        int k2=(sqrt(k)-b)/(2*a);
        cout<<k2<<"\n";
    }
    return 0;
}

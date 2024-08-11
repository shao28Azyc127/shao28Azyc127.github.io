#include<iostream>
#include<cstdio>
using namespace std;
int t,m,a,b,c;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        if(b*b-4*a*c<0){
            cout<<"No\n";
            continue;
        }
        cout<<"1\n";
    }
}

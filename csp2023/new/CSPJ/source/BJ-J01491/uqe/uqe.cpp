#include<bits/stdc++.h>
using namespace std;
int t,m;
int gcd(int x,int y){
    if(y==0)return x;
    else return gcd(y,x%y);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(b*b-4*a*c<0){
            cout<<"NO"<<endl;
        }else{
            if(c==0){
                int fu=1;
                int all=gcd(b,a);
                if(b/all<0)fu++;
                if(a/all<0)fu++;
                if(fu%2)cout<<"-";
                cout<<abs(b/all);
                if(a!=all)cout<<"/"<<abs(a/all);
                cout<<endl;
            }else{
                int fu=0;
                int d=sqrt(b*b-4*a*c)-b;
                int all=gcd(d,2*a);
                if(d/all<0)fu++;
                if(2*a/all<0)fu++;
                if(fu%2)cout<<"-";
                cout<<abs(d/all);
                if(2*a!=all)cout<<"/"<<abs(2*a/all);
                cout<<endl;
            }
        }
    }
    return 0;
}
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int gcd(int x,int y){
    x=abs(x);
    y=abs(y);
    if(y==0)return x;
    return gcd(y,x%y);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int der=b*b-4*a*c;
        if(der<0){
            cout<<"NO"<<endl;
            continue;
        }
        int ans=-1;
        for(int i=0;i<=der;i++){
            if(i*i==der){
                ans=i;
                break;
            }
        }
        if(ans>=0){
            if((-b+ans)/(2*a)>(-b-ans)/(2*a)){
                int x=-b+ans,y=2*a;
                if(x%y!=0){
                    int z=gcd(x,y);
                    cout<<x/z<<"/"<<y/z<<endl;
                }
                else cout<<x/y<<endl;
            }
            else{
                int x=-b-ans,y=2*a;
                if(x%y!=0){
                    int z=gcd(x,y);
                    cout<<x/z<<"/"<<y/z<<endl;
                }
                else cout<<x/y<<endl;
            }
            continue;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a,b,c;
    int x,y,z;
    int delta=0;
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        delta=pow(b,2)-4*a*c;
        if(delta<0){
            cout<<"NO"<<endl;
        }else if(delta==0){
            cout<<((-1)*b+sqrt(delta))/2*a<<endl;
        }else{
            x=((-1)*b+sqrt(delta))/2*a;y=((-1)*b-sqrt(delta))/2*a;
            z=max(x,y);cout<<z<<endl;
        }
    }

    return 0;
}

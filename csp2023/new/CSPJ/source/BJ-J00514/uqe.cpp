#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqein","r",stdin);                                               
    freopen("uqeout","w",stdout);                                             
    int a[1010],b[1010],c[1010],x1,x2,t,m;
    cin>>t>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>c[i];
        int d=b[i]*b[i]-4*a[i]*c[i];
        int x1=(-b[i]+sqrt(d));
        int x2=(-b[i]-sqrt(d));
        if(d<0) cout<<"NO"<<endl;
        else{
            if(x1>x2) cout<<x1<<endl;
            if(x1<=x2) cout<<x2<<endl;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int d(double a){
    int x=a;
    if(x<a)return x;
    else return x-1;
}
int main(){
    freopen("equ.in","r",stdin);
    freopen("equ.out","w",stdout);
    int T,M;
    cin>>T>>M;
    for(int i=0;i<T;i++){
        int a,b,c,ans;
        cin>>a>>b>>c;
        if((b*b-4*a*c)<0){
            cout<<"NO"<<endl;
            continue;
        }
        ans=d((-1*b+sqrt(b*b-4*a*c))/2/a+0.5);
        cout<<ans<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,m,a,b,c;
    cin>>T>>m;
    while(T--){
        cin>>a>>b>>c;
        if(b==0&&c==0){
            cout<<0<<endl;
            continue;
        }
        if(b*b-4*a*c<0){
            cout<<"NO"<<endl;
            continue;
        }
        int ans=max((-1*b+sqrt(b*b-4*a*c))/2*a,(-1*b-sqrt(b*b-4*a*c))/2*a);
        if(ans==0.5)cout<<"1/2";
        else if(ans==0.25)cout<<"1/4";
        else if(ans==0.75)cout<<"3/4";
        else if(ans==0.125)cout<<"1/8";
        else if(ans==0.375)cout<<"3/8";
        else if(ans==0.625)cout<<"5/8";
        else if(ans==0.875)cout<<"7/8";
        else cout<<ans;
        cout<<endl;
    }
    return 0;
}
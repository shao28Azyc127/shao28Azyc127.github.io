#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,t;
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int g=a*2;
        int ans=0;
        int dota=b*b-4*g;
        if(dota<0){
            cout<<"NO";
            continue;
        }
        if(dota==0){
            ans=sqrt(dota);
            if(ans*ans==dota){
                ans=ans-b;
                if(ans<0){
                    cout<<"-";
                    ans=0-ans;
                }
                int sum=1;
                for(int j=1;j<=min(ans,g);j++){
                    g=g/j;
                    ans=ans/j;
                }
                cout<<ans<<"/"<<g;
                continue;
            }
            if(b!=0){
                cout<<"-b/"<<g<<"sqrt("<<dota<<")"<<endl;
                continue;
            }
        }
        if(dota>0){
            ans=sqrt(dota);
            if(ans*ans==dota){
                ans=ans-b;
                if(ans<0){
                    cout<<"-";
                    ans=0-ans;
                }
                int sum=1;
                for(int j=1;j<=min(ans,g);j++){
                    if(g%j==0&&ans%j==0){
                        g=g/j;
                        ans=ans/j;
                    }
                }
                cout<<ans<<"/"<<g;
                continue;
            }
            if(b!=0){
                cout<<"-b/"<<g<<"sqrt("<<dota<<")"<<endl;
                continue;
            }
        }
    }
    return 0;
}

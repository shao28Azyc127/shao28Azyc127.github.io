#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    int a,b,c;
    while(t--){
        cin>>a>>b>>c;
        if(b*b-(4*a*c)<0){
            cout<<"NO"<<endl;
            continue;
        }
        if(b==0&&c==0&&a!=0){
            cout<<0<<endl;
            continue;
        }
        if(b*b-(4*a*c)==0&&b==0){
            
            if(sqrt(-c/1.0/a/1.0)==(int)sqrt(-c/a))cout<<sqrt(-c/a)<<endl;
            else if(-c/1.0/a/1.0==-c/a)cout<<"sqrt("<<-c/a<<")"<<endl;
            continue;
        }
    }
    return 0;
}

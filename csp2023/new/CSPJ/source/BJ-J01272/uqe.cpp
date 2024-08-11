#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int v=0;v<t;v++){
        int a,b,c;
        cin>>a>>b>>c;
        int cnt=b*b-4*a*c;
        if(cnt<0){
            cout<<"NO"<<endl;
            continue;
        }
        if(c==0){
            if(b>=0){
                cout<<0<<endl;
                continue;
            }
        int m=gcd(b,a);
        a/=m;
        b/=m;
        if(a==1){
            cout<<-b<<endl;
            continue;
        }
        else if(a>0){
            cout<<-b<<"/"<<a<<endl;
            continue;
        }
        cout<<b<<"/"<<-a<<endl;
        continue;
    }
    int ans;
    for(int i=sqrt(cnt);i>=1;i--){
            int s=i*i;
            if(cnt%s==0){
                ans=i;
                cnt/=s;
                break;
            }
        }
    if(cnt==1){
        int f=2*a;
        int x=gcd(f,ans);
        ans/=x;
        f/=x;
        if(f>0){
            if(f==1){
                cout<<ans<<endl;
                continue;
            }
            cout<<ans<<"/"<<f<<endl;
            continue;
        }
        if(f==-1){
            cout<<-ans<<endl;
            continue;
        }
        cout<<-ans<<"/"<<-f<<endl;
        continue;
    }
    int f=2*a;
        int x=gcd(f,ans);
        ans/=x;
        f/=x;
        if(f>0){
            if(f==1){
                cout<<ans;
            }
            else{
            cout<<ans<<"/"<<f;
            }
        }
        if(f==-1){
            cout<<-ans;
        }
        else if(f<0){
                cout<<-ans<<"/"<<-f;
        }
        cout<<"*sqrt("<<cnt<<")"<<endl;
}
}

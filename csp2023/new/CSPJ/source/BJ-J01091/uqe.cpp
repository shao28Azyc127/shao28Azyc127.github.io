#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p[1005];
ll vis[1005];
ll cnt=0;
ll pow1(ll x,ll y){
    ll ans=1;
    while(y>0){
        if(y&1){
            ans*=x;
        }
        x*=x;
        y/=2;
    }
    return ans;
}
ll solve(ll x){
    ll ans=1;
    for(ll i=1;i<=cnt;i++){
        ll temp=0;
        ll temp1=x;
        while(temp1%p[i]==0){
            temp1/=p[i];
            temp++;
        }
        ans*=pow1(p[i],(temp/2)*2);
    }
    return ans;
}
ll gcd(ll x,ll y){
    if(y==0)return x;
    return gcd(y,x%y);
}
bool check(double x){
    ll y=x;
    if(x==y)return 0;
    return 1;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    for(ll i=2;i<=1000;i++){
        if(vis[i]==0)p[++cnt]=i;
        for(ll j=1;p[j]*i<=1000&&j<=cnt;j++){
            vis[p[j]*i]=1;
            if(i%p[j]==0)continue;
        }
    }
    ll n,m;
    cin>>n>>m;
    while(n--){
        ll a,b,c;
        cin>>a>>b>>c;
        if(pow1(b,2)<4*a*c){
            cout<<"NO\n";
            continue;
        }
        if(pow1(b,2)==4*a*c){
            if((-b)%(2*a)==0){
                if(b!=0){
                    cout<<(-b)/(2*a);
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<-b/gcd(b,2*a)<<"/"<<2*a/gcd(b,2*a);
            }
        }
        else if(check(sqrt(pow1(b,2)-4*a*c))){
            if((-b)%(2*a)==0){
                if(b!=0){
                    cout<<(-b)/(2*a)<<"+";
                }
            }
            else{
                if(-b/gcd(b,2*a)<0&&2*a/gcd(b,2*a)<0){
                    cout<<b/gcd(b,2*a)<<"/"<<-2*a/gcd(b,2*a)<<"+";
                }
                else if(-b/gcd(b,2*a)>0&&2*a/gcd(b,2*a)<0)cout<<b/gcd(b,2*a)<<"/"<<-2*a/gcd(b,2*a)<<"+";
                else cout<<-b/gcd(b,2*a)<<"/"<<2*a/gcd(b,2*a)<<"+";
            }
            ll temp=solve(pow1(b,2)-4*a*c);
            temp=sqrt(temp);
            if(temp==1){
                    if(2*a>0)cout<<"sqrt("<<(pow1(b,2)-4*a*c)<<")/"<<2*a;
                    else cout<<"sqrt("<<-(pow1(b,2)-4*a*c)<<")/"<<-2*a;
            }
            else{
                if(temp%(2*a)==0){
                    if(temp!=2*a)cout<<temp/2/a<<"*sqrt("<<(pow1(b,2)-4*a*c)/temp/temp<<")";
                    else cout<<"sqrt("<<(pow1(b,2)-4*a*c)/temp/temp<<")";
                }
                else{
                    if(2*a>0)cout<<temp/gcd(temp,2*a)<<"*sqrt("<<(pow1(b,2)-4*a*c)/temp/temp<<")/"<<2*a/gcd(temp,2*a);
                    else cout<<-temp/gcd(temp,2*a)<<"*sqrt("<<(pow1(b,2)-4*a*c)/temp/temp<<")/"<<-2*a/gcd(temp,2*a);
                }
            }
        }
        else{
            ll temp=sqrt(pow1(b,2)-4*a*c);
            temp=temp-b;
            if(temp%(2*a)==0){
                cout<<temp/(2*a);
            }
            else{
                if(2*a>0)cout<<temp/gcd(temp,2*a)<<"/"<<2*a/gcd(temp,2*a);
                else cout<<-temp/gcd(temp,2*a)<<"/"<<-2*a/gcd(temp,2*a);
            }
        }
        cout<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int t,m;
int a,b,c;
typedef long long ll;

ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
void print(int flag){
    if(flag==-1) cout<<"-";
    return ;
}
ll qp(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        ll delta=b*b-4*a*c;
        if(delta<0) cout<<"NO"<<endl;
        else if(delta==0){
            int flag=(b>=0?-1:1)*(a>=0?1:-1);
            int x=abs(b),y=abs(2*a);
            if(x==0){
                cout<<0<<endl;
                continue;
            }
            int z=gcd(x,y);
            if(z!=0) x/=z,y/=z;
            if(y==1){
                print(flag),cout<<x<<endl;
            }
            else print(flag),cout<<x<<'/'<<y<<endl;
        }
        else{
            ll x=1,y=1;
            for(ll i=2;i*i<=delta;i++){
                int sum=0;
                while(delta%i==0){
                    delta/=i;
                    sum++;
                }
                x*=qp(i,sum/2);
                if(sum%2==1) y*=i;
            }
            if(delta!=1) y*=delta;
            if(y==1){
                if(a>0) x-=b;
                else x=-x-b;
                y=2*a;
                int flag=(x>=0?1:-1)*(y>=0?1:-1);
                x=abs(x),y=abs(y);
                if(x==0){
                    cout<<0<<endl;
                    continue;
                }
                ll z=gcd(x,y);
                x/=z,y/=z;
                print(flag);
                if(y==1) cout<<x<<endl;
                else cout<<x<<'/'<<y<<endl;
                continue;
            }
            ll X=x,Y=y;
            int flag=(b>=0?-1:1)*(a>=0?1:-1);
            x=abs(b),y=abs(2*a);
            ll z=gcd(x,y);
            x/=z,y/=z;
            if(x!=0){
                if(y==1){
                    print(flag),cout<<x;
                }
                else print(flag),cout<<x<<'/'<<y;
                cout<<'+';
            }
            x=X,y=abs(2*a);
            z=gcd(x,y);
            x/=z,y/=z;
            if(x==1){
                cout<<"sqrt("<<Y<<')';
                if(y!=1) cout<<"/"<<y;
                cout<<endl;
                continue;
            }
            cout<<x;
            if(Y!=1){
                cout<<'*'<<"sqrt("<<Y<<')';
                if(y!=1) cout<<"/"<<y;
            }
            cout<<endl;
        }
    }
}
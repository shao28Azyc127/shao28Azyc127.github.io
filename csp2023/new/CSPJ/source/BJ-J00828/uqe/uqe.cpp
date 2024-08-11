#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ll t,m;
    cin>>t>>m;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        ll d=b*b-4*a*c;
        //cout<<sqrt(d)<<endl;48
        if(d<0){
            cout<<"NO"<<endl;
            continue;
        }
        if(a<0){
            a=-a;
            b=-b;
        }
        ll r=sqrt(d);
        if(r*r==d){
            ll sq=(sqrt(d)+b)/2/a;
            if(sq*2*a==sqrt(d)+b){
                cout<<sq<<endl;
            }else{
                ll m=gcd(sqrt(d)+b,2*a);
                ll x=(sqrt(d)+b)/m,y=2*a/m;
                if(y<0&&x>0){
                    y=-y;
                    x=-x;
                }
                if(y<0&&x<0){
                    y=-y;
                    x=-x;
                }
                cout<<x<<"/"<<y<<endl;
            }
        }else{
            if(b==0){
                ll x=d;
                ll id=sqrt(x);
                while(true){
                    ll tr=id*id;
                    if(x%tr==0){
                        d/=tr;
                        break;
                    }
                    id--;
                }
                if(id%(2*a)==0){
                    id=id/2/a;
                    if(id==1){
                        cout<<"sqrt("<<d<<")"<<endl;
                        continue;
                    }
                    cout<<id<<"*sqrt("<<d<<")"<<endl;
                }else{
                    ll m=gcd(id,2*a);
                    ll x=id/m,y=2*a/m;
                    if(y<0){
                        y=-y;
                    }
                    if(x==1){
                        cout<<"sqrt("<<d<<")/"<<y<<endl;
                        continue;
                    }
                    if(x<0){
                        x=-x;
                    }
                    cout<<x<<"*sqrt("<<d<<")/"<<y<<endl;
                }
            }else{
                if(b%(2*a)==0){
                    cout<<-b/2/a;
                }else{
                    ll gc=gcd(b,2*a);
                    ll g=b/gc,c=2*a/gc;
                    g=-g;
                    if(g<0&&c<0){
                        g=-g;
                        c=-c;
                    }
                    cout<<g<<"/"<<c;
                }
                cout<<"+";
                ll x=d;
                ll id=sqrt(x);
                ll tr=id*id;
                while(id){
                    tr=id*id;
                    if(x%tr==0){
                        d/=tr;
                        break;
                    }
                    id--;
                }
                //cout<<tr<<endl;
                if(id%(2*a)==0){
                    id=id/2/a;
                    if(id<0){
                        id=-id;
                    }
                    if(id==1){
                        cout<<"sqrt("<<d<<")"<<endl;
                        continue;
                    }
                    cout<<id<<"*sqrt("<<d<<")"<<endl;
                }else{
                    ll m=gcd(id,2*a);
                    ll x=id/m,y=2*a/m;
                    //cout<<x<<" "<<y<<endl;
                    if(y<0){
                        y=-y;
                    }
                    if(x<0){
                        x=-x;
                    }
                    if(x==1){
                        cout<<"sqrt("<<d<<")/"<<y<<endl;
                        continue;
                    }
                    cout<<x<<"*sqrt("<<d<<")/"<<y<<endl;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

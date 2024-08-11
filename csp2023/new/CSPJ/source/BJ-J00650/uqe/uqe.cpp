
#include<bits/stdc++.h>
using namespace std;
int n,mx;
int a,b,c;
int dt,x,gc,gb;
double d;
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>mx;
    while(n--){
        cin>>a>>b>>c;
        dt=(b*b)-(4*a*c);
         if(a==b&&b==c){
            cout<<"0\n";
        }else if(dt<0){
            cout<<"NO"<<'\n';
        }else if(dt==0){
            gc=gcd(b,2*a);
            cout<<-(b/gc);
            if(gc==2*a){
                cout<<'\n';
            }else{
                cout<<"/"<<2*a/gc<<'\n';
            }
        }else{
            bool f=1;
            gc=gcd(abs(b),abs(2*a));
            x=1;
            for(int i=2;i*i<=dt;i++){
                if(dt%(i*i)==0){
                    dt/=i*i;
                    x*=i;
                }
            }
            gb=gcd(abs(x),abs(2*a));
            d=sqrt(dt);
            int v=0;
            if(b!=0){
                if(2*a/gc>0){
                    v+=-(b/gc);
                }else{
                    v+=(b/gc);
                }
            }
            if(double(ceil(d))!=d){
                f=0;
            }else{
                v+=x/gb*ceil(d);
            }
            if(gb==gc&&f){
                int ff=gcd(abs(v),abs(2*a/gc));
                cout<<(v/ff);
                if(ff!=2*a/gc){
                    cout<<"/"<<(2*a/gc/ff);
                }
            }else{
                if(b!=0){
                    if(2*a/gc>0){
                        cout<<-(b/gc);
                        if(gc!=2*a){
                            cout<<"/"<<(2*a/gc);
                        }
                        cout<<"+";
                    }else{
                        cout<<(b/gc);
                        if(gc!=2*a){
                            cout<<"/"<<-(2*a/gc);
                        }
                        cout<<"+";
                    }
                }
                if(ceil(d)!=d){
                    if(x!=gb){
                        cout<<x/gb<<"*";
                    }
                    cout<<"sqrt("<<dt<<")";
                }else{
                    if(x!=gb){
                        cout<<x/gb*ceil(d);
                    }else{
                        cout<<ceil(d);
                    }
                }
                if(gb!=2*a){
                    cout<<"/"<<2*a/gb;
                }

            }
            cout<<"\n";
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a,b,c,x1,x2,t1,t,m,t2,t3;
long long d;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        d=b*b-4*a*c;
        if(d<0){
            cout<<"NO";
            continue;
        }
        if(d==0){
            if(b==0){
                cout<<"0";
            }
            else{
                t1=__gcd(abs(2*a),abs(b));
                if(b%(2*a)==0)cout<<b/(-2*a);
                else{
                    if(a*b>0)cout<<"-";
                    cout<<b/t1<<"/"<<2*a/t1;
                }
            }
            continue;
        }
        if((int(sqrt(d))*sqrt(d))==d){
            int dd=sqrt(d);
            t1=__gcd(abs(2*a),abs(b));
            if(b%(2*a)==0)cout<<-b/(2*a)+dd;
            else t2=abs(2*a/t1);
            if((-b+dd)%t2==0) cout<<(-b/t1+dd)/t2;
            else{
                t1=__gcd(t2,b/t1+dd);
                cout<<(b/t1+dd)/t1<<"/"<<t2/t1;
            }
            continue;
        }
        if(b!=0){
            t1=__gcd(abs(2*a),abs(b));
            if(b%(2*a)==0)cout<<b/(-2*a);
            else{
                t2=2*a;
                if(a*b>0)cout<<"-";
                cout<<abs(b/t1)<<"/"<<t2/t1;
            }
            cout<<"+";
        }else t2=2*a;
        t2=2*a;
        t3=1;
        for(int i=2;i*i<=d;i++)
            while(d%(i*i)==0){
                t3*=i;
                d/=(i*i);
            }
        if(t2==0&&t3==1)cout<<"sqrt("<<d<<")";
        else if(t2==0)cout<<t3<<"*"<<"sqrt("<<d<<")";
        else if(t3==1)cout<<"sqrt("<<d<<")"<<"/"<<t2;
        else{
            t1=__gcd(abs(t2),t3);
            if(t3%t2==0){
                    if(t3/t2!=1)cout<<abs(t3/t2)<<"*";
                    cout<<"sqrt("<<d<<")";
            }
            else{
                if(t3/t1!=1)cout<<abs(t3/t1)<<"*";
                cout<<"sqrt("<<d<<")"<<"/"<<abs(t2/t1);
            }
        cout<<"\n";
        }
    }
    return 0;
}

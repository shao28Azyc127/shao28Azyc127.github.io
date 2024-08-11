#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,m,a,b,c;
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        int d=b*b-4*a*c,g,g_2,e,f,dc,x;
        if(d<0){
            cout<<"NO"<<endl;
            continue;
        }
        dc=sqrt(d);
        if(dc*dc==d){
            int y=-b+dc,p=a*2;
            if(y<=0&&p<0){
                y=-y;
                p=-p;
                int z=__gcd(y,p);
                y=y/z;
                p=p/z;
            }
            else if(y>=0&&p<0){
                p=-p;
                int z=__gcd(y,p);
                y=-y/z;
                p=p/z;
            }
            else if(y<=0&&p>0){
                y=-y;
                int z=__gcd(y,p);
                y=-y/z;
                p=p/z;
            }
            else if(y>=0&&p>0){
                int z=__gcd(y,p);
                y=y/z;
                p=p/z;
            }
            if(y==0) cout<<0<<endl;
            else if(p==1) cout<<y<<endl;
            else cout<<y<<"/"<<p<<endl;
            continue;
        }
        else{
            int qwq=a;
            if(b>=0&&qwq>0){
                g=__gcd(b,qwq*2);
                b=b/g;
                e=qwq*2/g;
            }
            else if(b<=0&&qwq>0){
                b=-b;
                g=__gcd(b,qwq*2);
                b=-b/g;
                e=qwq*2/g;
            }
            else if(b>=0&&qwq<0){
                qwq=-qwq;
                g=__gcd(b,qwq*2);
                b=-b/g;
                e=qwq*2/g;
            }
            else if(b<=0&&qwq<0){
                b=-b;
                qwq=-qwq;
                g=__gcd(b,qwq*2);
                b=b/g;
                e=qwq*2/g;
            }
            if(a<0){
                a=-a;
                g_2=__gcd(d,a*2);
                x=d/g_2/g_2;
                if(x*g_2*g_2==d){
                    d=-d/g_2/g_2;
                    f=a*2/g_2;
                }
            }
            else if(a>0){
                g_2=__gcd(d,a*2);
                x=d/g_2/g_2;
                if(x*g_2*g_2==d){
                    d=d/g_2/g_2;
                    f=a*2/g_2;
                }
            }
            if(b!=0){
                if(e!=1) cout<<-b<<"/"<<e<<"+";
                else cout<<-b<<"+";
            }
            int ans=0;
            for(int i=1;i*i<=d;i++){
                if(d%(i*i)==0){
                    ans=i;
                }
            }
            d=d/(ans*ans);
            if(f==1&&ans==1) cout<<"sqrt("<<d<<")"<<endl;
            if(f==1&&ans!=1){
                cout<<ans<<"*"<<"sqrt("<<d<<")"<<endl;
            }
            if(f!=1&&ans==1){
                cout<<"sqrt("<<d<<")"<<"/"<<f<<endl;
            }
            if(f!=1&&ans!=1){
                cout<<ans<<"*"<<"sqrt("<<d<<")"<<"/"<<f<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
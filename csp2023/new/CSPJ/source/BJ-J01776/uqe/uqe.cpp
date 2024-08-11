#include <bits/stdc++.h>
using namespace std;
int solve2(int a,int b){//最大公约数
    int m;
    a=abs(a),b=abs(b);
    for(int i=1;i<=min(a,b);i++)
        if(a%i==0&&b%i==0)
            m=i;
    return m;
}
int main(){
    freopen("uqe.in","r",stdin);
   freopen("uqe.out","w",stdout);
    int T,M,n,a,b,c,derta;
    cin>>T>>M;
    while(T--){
        cin>>a>>b>>c;
        derta=b*b-4*a*c;
        if(c==0){
            if(b>=0)
                cout<<0<<endl;
            else if(b<0){
                b=abs(b);
                int y=solve2(a,b);
                a/=y;
                b/=y;
                if(a==1)
                    cout<<b<<endl;
                else
                    cout<<b<<"/"<<a<<endl;
            }
            continue;
        }
        if(b==0){
            if(derta<0){
                cout<<"NO\n";
                continue;
            }
            a=abs(a);
            c=abs(c);
            int x=c*a,y=1;
            for(int i=sqrt(double(c*a))+2;i>1;i--){
                if(x%(i*i)==0){
                    x/=i*i;
                    y*=i;
                }
            }
            int m=solve2(a,y);
            y/=m;
            a/=m;
            if(x==1){
                if(y==1){
                    if(a==1){
                        cout<<1<<endl;
                    }
                    else
                        cout<<1<<"/"<<a<<endl;
                }
                else{
                    if(a==1)
                        cout<<y<<endl;
                    else
                        cout<<y<<"/"<<a<<endl;
                }
            }
            else{
                if(y==1){
                    if(a==1)
                        cout<<"sqrt("<<x<<")"<<endl;
                    else
                        cout<<"sqrt("<<x<<")/"<<a<<endl;
                }
                else{
                    if(a==1)
                        cout<<y<<"*"<<"sqrt("<<x<<")"<<endl;
                    else
                        cout<<y<<"*"<<"sqrt("<<x<<")/"<<a<<endl;
                }
            }
        }
    }
    return 0;
}

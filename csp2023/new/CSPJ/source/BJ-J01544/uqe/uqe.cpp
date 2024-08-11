#include <bits/stdc++.h>
using namespace std;
int findnum(int w){
    int ans=1,a=w;
    for(int i=2;i*i<=a;i++){
        if(a%i==0&&(a/i)%i==0){
            int x=i*i;
            while(a%x==0){
                a/=x;ans*=i;
            }
        }
    }return ans;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;cin>>t>>m;
    while(t){
        t--;
        long long a,b,c;cin>>a>>b>>c;
        int up,down,delta;
        up=b*(-1);down=a*2;
        delta=b*b-(4*a*c);
        if(delta<0){cout<<"NO"<<endl;continue;}
        int x=sqrt(delta);
        if(x*x==delta){
            up+=x;
            x=__gcd(up,down);
            up/=x;down/=x;
            if(down==1)cout<<up<<endl;
            else {
                if(up<0||down<0)cout<<'-';
                cout<<abs(up)<<'/'<<abs(down)<<endl;
            }
        }else{
            int s=__gcd(up,down);
            up/=s;down/=s;
            if(down==1&&up!=0)cout<<up;
            else if(up!=0){
                if(up<0||down<0)cout<<'-';
                cout<<abs(up)<<'/'<<abs(down);
            }down*=s;
            int xishu=findnum(delta);
            delta/=(xishu*xishu);
            x=__gcd(xishu,down);
            xishu/=x;down/=x;
            cout<<'+';
            if(xishu!=1)cout<<abs(xishu)<<'*';
            cout<<"sqrt("<<delta<<')';
            if(down!=1)cout<<'/'<<abs(down)<<endl;
            else cout<<endl;
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
const int N=2500+10;
int prnum,prlist[N],vis[N];

void buildpr(){
    for(int i=2;i<=1000;i++){
        if(!vis[i]){
            prlist[++prnum]=i;
            for(int j=i;j<=2500;j+=i)vis[j]=1;
        }
    }
    for(int i=1001;i<=2500;i++)if(!vis[i])prlist[++prnum]=i;
}
int gtmy(int x){
    if(x==0)return 0;
    int res=1;
    //cout<<"\t\t"<<x<<endl;
    for(int i=1;i<=prnum&&prlist[i]*prlist[i]<=x;i++){
        //cout<<"\t\t\t"<<prlist[i]<<endl;
        while(x%(prlist[i]*prlist[i])==0)x/=prlist[i]*prlist[i],res*=prlist[i];
    }return res;
}

void test(){
    int t,m;cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int dlt=b*b-4*a*c;
        //cout<<a<<','<<b<<','<<c<<": "<<dlt<<endl;
        if(dlt<0){
            cout<<"NO\n";continue;
        }
        int t=gtmy(dlt);
        //cout<<"\t"<<t<<endl;
        if(t*t==dlt){
            int p1,p2;
            p1=-b+t,p2=2*a;
            if(p2<0){
                p1=-b-t;
            }
            int gd=__gcd(p1,p2);p1/=gd,p2/=gd;
            if(p2<0)p1=-p1,p2=-p2;
            cout<<p1;
            if(p2!=1)cout<<"/"<<p2;
            cout<<endl;
        }else{
            dlt/=t*t;
            //cout<<"\t"<<t<<","<<dlt<<endl;
            if(b!=0){
                int p1,p2;
                p1=-b,p2=2*a;
                int gd=__gcd(p1,p2);p1/=gd,p2/=gd;
                if(p2<0)p1=-p1,p2=-p2;
                cout<<p1;
                if(p2!=1)cout<<"/"<<p2;
                cout<<"+";
            }
            int q1=t,q2=2*a;
            int gd=__gcd(q1,q2);q1/=gd,q2/=gd;
            q1=abs(q1),q2=abs(q2);
            if(q1>1)cout<<q1<<"*";
            cout<<"sqrt("<<dlt<<")";
            if(q2>1)cout<<"/"<<q2;
            cout<<endl;
        }
    }
}

signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    buildpr();
    test();
    return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a,int b){
    if(a<b){
        swap(a,b);
    }
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int lsq(int dlt){
    int res=1;
    int s=sqrt(dlt);
    if(s*s==dlt){
        return s;
    }
    for(int i=2;i<=s+1;i++){
        int cnt=0;
        while(dlt%i==0){
            cnt++;
            dlt/=i;
        }
        cnt/=2;
        res*=pow(i,cnt);
    }
    return res;
}

void yf(int& nb,int& na){
    bool f=false;
    if(nb<0&&na>0){
        f=true;
        nb=-nb;
    }
    else if(nb>0&&na<0){
        f=true;
        na=-na;
    }
    else{
        nb=abs(nb);
        na=abs(na);
    }
    int g=gcd(na,nb);
    nb/=g;
    na/=g;
    if(f){
        nb=-nb;
    }
}

int t,m,a,b,c,dlt;

signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        dlt=b*b-4*a*c;
        if(dlt<0){
            cout<<"NO"<<endl;
            continue;
        }
        int s=lsq(dlt);
        if(a<0){
            s=-s;
        }
        if(s*s==dlt){
            dlt=0;
            b-=s;
        }
        else{
            dlt/=(s*s);
        }
        if(dlt==0){
            int nb=-b,na=2*a;
            if(nb==0){
                cout<<0<<endl;
                continue;
            }
            yf(nb,na);
            if(na==1){
                cout<<nb<<endl;
            }
            else{
                cout<<nb<<"/"<<na<<endl;
            }
        }
        else{
            int nb=-b,na=2*a;
            if(nb!=0){
                yf(nb,na);
                if(na==1){
                    cout<<nb<<"+";
                }
                else{
                    cout<<nb<<"/"<<na<<"+";
                }
            }
            nb=s;
            na=2*a;
            yf(nb,na);
            if(nb!=1){
                cout<<nb<<"*";
            }
            cout<<"sqrt("<<dlt<<")";
            if(na!=1){
                cout<<"/"<<na;
            }
            cout<<endl;
        }
    }

    return 0;
}

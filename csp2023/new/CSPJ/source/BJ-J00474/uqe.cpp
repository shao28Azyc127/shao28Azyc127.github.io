#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<fstream>
#define int long long
/*
qwq awa QWQ QAQ ccf csp noip noi iakioi
never gonna give you up
freopen("uqe.in",'w',"ios::stdin")
freopen("upe.out,'r',"ios::stdout")
retrun 0;
int mian()
using namespace tsd;
*/
using namespace std;
void pfrac(int a,int b,string ws=""){
    if((a<0||b<0)&&!(a<0&&b<0)){
        cout<<"-";
    }
    if(a==0){
        return;
    }
    a=abs(a);
    b=abs(b);
    int gcd=__gcd(a,b);
    if(gcd==a){
        cout<<"1/"<<b/gcd;
    }
    else if(gcd==b){
        cout<<a;
    }
    else{
        cout<<a/gcd<<"/"<<b/gcd;
    }
    cout<<ws;
}
void pdelt(int a,int b){
    //  sqrt(a)/b
    if(b<0){
        cout<<"NO";
        return;
    }
    else if(b==0){cout<<0;return;}
    if((a<0||b<0)&&!(a<0&&b<0)){
        cout<<"-";
    }
    if(a==0){
        return;
    }
    a=abs(a);
    b=abs(b);
    int gcd=__gcd(a,b);
    if(gcd==a){
        cout<<"1/"<<b/gcd;
    }
    else if(gcd==b){
        cout<<a;
    }
    else{
        cout<<a/gcd<<"/"<<b/gcd;
    }
}
void solve(){
    int a,b,c;cin>>a>>b>>c;
    long long delta=(b*b)-4*a*c;
    if(delta<0){
        cout<<"NO";
        return;
    }
    //T1,5,6
    else if(c==0){
        if(b<0){
            pfrac(a,b);
        }
        else if(b==0){
            cout<<0;
            return;
        }
        else{
            cout<<0;
            return;
        }
    }
    //T1,3,4
    else if(b==0){
        if(a*c>0){
            cout<<"NO";
        }
        else{
            int u=-1*a*c;int d=a;int ut=1;
            if(d<0){
                cout<<"-";
            }
            for(int i=2;i*i<=u;i++){
                if(__gcd(u,i*i)!=1){
                    u=u/(i*i);ut*=i;
                }
            }
            if(u==1){
                if(d==1){
                    cout<<ut;
                }
                else{
                    ut=ut/__gcd(ut,d);
                    d=d/__gcd(ut,d);
                    cout<<ut<<"/"<<d;
                }
            }
            else if(ut==1){
                printf("sqrt(%d)/%d",u,d);
            }
            else{
                ut=ut/__gcd(ut,d);
                d=d/__gcd(ut,d);
                printf("%d*sqrt(%d)/%d",ut,u,d);
            }
        }
    }
    else if(delta==0){
        pfrac(-b,2*a);
    }
    else{
        pfrac(-b,2*a,"+");
        pdelt(delta,2*a);
    }
}
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;cin>>T>>M;
    for(int i=0;i<T;i++){
        solve();
        cout<<endl;
    }
    return 0;
}

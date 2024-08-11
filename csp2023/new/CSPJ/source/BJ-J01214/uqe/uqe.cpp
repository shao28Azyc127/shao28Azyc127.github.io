#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,m;
int gcd(int a,int b){
    return (b==0?a:gcd(b,a%b));
}
void yf(int &x,int &y){
    int dd;
    dd=gcd(x,y);
    x/=dd;
    y/=dd;
    if(y<0){
        y=-y;
        x=-x;
    }
}
void ot(int u,int v){
    if(v==1){
        cout<<""<<u<<"";
    }else{
        cout<<""<<u<<"/"<<v<<"";
    }
}
void _main(){
    int a,b,c;
    cin>>a>>b>>c;
    int d;
    d=b*b-4*a*c;
    int e;
    e=sqrt(d);
    if(d<0){
        cout<<"NO"<<endl;
        return;
    }
    //(-b+-sqrt(d))/2*a
    if(e*e==d){
            int z1,z2;
            z1=(sqrt(d));
            if(a<0){
                z1*=-1;
            }
            z1-=b;
            z2=2*a;
            yf(z1,z2);
            ot(z1,z2);
            cout<<endl;
            return;
    }
    int q11,q12;
    q11=-b;
    q12=2*a;
    if(q11){
        yf(q11,q12);
        ot(q11,q12);
        cout<<'+';
    }
    int q2;
    if(a<0){
        q2=-1;
    }else{
        q2=1;
    }
    for(int i=sqrt(d);i>=1;i--){
        if(d%(i*i)==0){
            q2*=i;
            d/=(i*i);
            break;
        }
    }
    q11=q2;
    q12=2*a;
    yf(q11,q12);
    if(q11!=1||q12!=1){
        if(q12==1){
            printf("%lld*sqrt(%lld)",q11,d);
        }else if(q11==1){
            printf("sqrt(%lld)/%lld",d,q12);
        }else{
            printf("%lld*sqrt(%lld)/%lld",q11,d,q12);
        }
    }else{
        cout<<"sqrt("<<d<<")";
    }
    cout<<endl;
}
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        _main();
    }
    return 0;
}

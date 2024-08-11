#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int t,m;
int zs[120];
int asb(int x){
    if(x<0) return -x;
    return x;
}
int gcd(int a,int b){//a>b
    a=asb(a);
    b=asb(b);
    int ans=1;
    int c,d=1;
    while(d){
        c=a/b;
        d=a%b;
        a=b;
        b=d;
    }

    return a;
}
int zhshu(int m){
    int cnt=0;
    for(int i=2;i<=m;i++){
        int ok=1;
        for(int j=0;j<cnt;j++){
            if(i%zs[j]){
                ok=0;
                continue;
            }
        }
        if(ok){
            zs[cnt]=i;
            cnt++;
        }
    }
    cnt--;
    return cnt;
}
//(-b +- s(b*b-4ac) )/2a
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    cin>>t>>m;
    int zl=zhshu(m);
    while(t--){
        cin>>a>>b>>c;
        if(b*b<4*a*c){//wugen
            cout<<"NO"<<endl;
            continue;
        }else if(b*b==4*a*c){//deng gen

            if(b==0)cout<<0<<endl;
            else if(b*a<0){
                cout<<asb(b)/gcd(2*a,b);
                a=asb(a)/gcd(2*a,b);
                if(a!=1) cout<<"/"<<a;
                cout<<endl;
            }else{
                cout<<-asb(b)/gcd(2*a,b);
                a=asb(a)/gcd(2*a,b);
                if(a!=1) cout<<"/"<<a;
                cout<<endl;
            }
            continue;
        }


        if(c==0){
            int x,y;
            if(a*b>=0) cout<<0<<endl;
            else{
                cout<<asb(b)/gcd(a,b);
                a=abs(a)/gcd(a,b);
                if(a!=1) cout<<"/"<<a;
                cout<<endl;
            }
            continue;
        }
        if(a*b>0)cout<<"-";
        int f;
        cout<<asb(b)/gcd(2*a,b);
        f=abs(2*a)/gcd(2*a,b);
        if(f!=1) cout<<"/"<<f;
        cout<<"+";

        int n=b*b-4*a*c;
        int m=1;
        for(int i=0;zs[i]*zs[i]<=n;i++){
            if(n%(zs[i]*zs[i])==0){
                m*=zs[i];
                n/=zs[i]*zs[i];
            }
        }
        int mb=m/gcd(m,2*a);
        if(mb!=1) cout<<mb;
        if(n!=1) cout<<"*sqrt("<<n<<")";
        if(asb(a)/gcd(2*a,m) != 1) cout<<"/"<<asb(a)/gcd(2*a,m);

        cout<<endl;
    }

    return 0;
}

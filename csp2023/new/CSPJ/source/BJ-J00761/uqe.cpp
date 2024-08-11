#include <bits/stdc++.h>
using namespace std;
int a1,b1,c1;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
int qpow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)  ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
struct num1{
    int p,q;
    void yf(){
        int ngcd=gcd(p,q);
        p/=ngcd;
        q/=ngcd;
        if(q<0)  p=-p,q=-q;
    }
}c;
struct num2{
    int sq,p,q;
    void sqyf(){
        int t=sq;
        for(int i=2;i*i<=t;i++){
            if(t%i==0){
                int cnt=0;
                while(t%i==0){
                    t/=i;
                    cnt++;
                }
                if(cnt>=2){
                    int pp=cnt/2;
                    //cout<<i<<"^"<<pp<<"="<<qpow(i,pp)<<endl;
                    p*=qpow(i,pp);
                    sq/=qpow(i,pp*2);
                }
            }
        }
    }
    void yf(){
        int ngcd=gcd(p,q);
        p/=ngcd;
        q/=ngcd;
        if(q<0)  p=-p,q=-q;
    }
}c2;
void tf(){
    int nlcm=lcm(c.q,c2.q);
    c.p*=nlcm/c.q;
    c2.p*=nlcm/c2.q;
    c.q=nlcm,c2.q=nlcm;
}
void plus1(){
    if(c2.sq==1){
        tf();
        c.p+=c2.p;
        c2.sq=0;
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin>>T>>M;
    while(T--){
        cin>>a1>>b1>>c1;
        c.p=-b1,c.q=2*a1,c.yf();
        int delta=b1*b1-4*a1*c1;
        if(delta<0){
            cout<<"NO\n";
            continue;
        }
        c2.sq=delta,c2.q=2*a1,c2.p=1;
        if(c2.q<0)  c2.q=-c2.q;
        c2.sqyf(),c2.yf(),plus1();
        c.yf();
        if(c.p!=0){
            if(c.q==1)  cout<<c.p;
            else  cout<<c.p<<"/"<<c.q;
        }
        if(c2.sq!=0){
            if(c.p!=0)  cout<<"+";
            if(c2.p==1||c2.p==-1){
                if(c2.sq==1)  cout<<"1";
                else  cout<<"sqrt("<<c2.sq<<")";
                if(c2.q!=1)  cout<<"/"<<c2.q;
            }else{
                cout<<abs(c2.p);
                if(c2.sq!=1) cout<<"*sqrt("<<c2.sq<<")";
                if(c2.q!=1)  cout<<"/"<<c2.q;
            }
        }
        if(c.p==0&&c2.sq==0)  cout<<0;
        cout<<'\n';
    }
    //cout<<c.p<<"/"<<c.q<<"+"<<c2.p<<"*sqrt("<<c2.sq<<")/"<<c2.q;
    //x=-b/2a+sqrt(b^2-4ac)/2a
    return 0;
}
//t3 moni
//long long!!!!
//long long!!!!
//long long!!!!
//long long!!!!
//long long!!!!
//long long!!!!
//long long!!!!
//long long!!!!
//long long!!!!
//long long!!!!
//long long!!!!
//long long!!!!

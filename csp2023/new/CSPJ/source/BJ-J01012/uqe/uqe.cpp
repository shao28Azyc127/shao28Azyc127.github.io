#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define ull unsigned long long
using namespace std;
int t,m,a,b,c,aa;
double a1,b1,c1,bb,x1,x2;
int sq(int x){
    for(int i=0;i*i<=x;i++)if(i*i==x)return 1;
    return 0;
}
int bsq(int x){
    for(int i=sqrt(x);i>=1;i--)if(x%(i*i)==0)return i;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        a1=a,b1=b,c1=c;
        aa=b*b-4*a*c;
        bb=aa;
        if(aa<0)cout<<"NO\n";
        else{
            a1=a,b1=b,c1=c;
            x1=(sqrt(bb)-b)/2/a;
            x2=(-sqrt(bb)-b)/2/a;
            if(max(x1,x2)==x1){
                if(sq(aa)==1){
                    int q1=sqrt(aa)-b,q2=2*a;//q1=2,q2=2
                    //cout<<q1<<"  |  "<<q2<<"\n";
                    int nq1=q1/__gcd(abs(q1),abs(q2)),nq2=q2/__gcd(abs(q1),abs(q2));
                    if(nq2<0)nq1=-nq1,nq2=-nq2;
                    if(nq2!=1)cout<<nq1<<"/"<<nq2<<"\n";
                    else cout<<nq1<<"\n";
                }
                else{
                    int sqrt1=bsq(aa),sqrt2=aa/sqrt1/sqrt1;//\sqrt aa=sqrt2 * \sqrt{sqrt1}
                    int q1=-b,q2=2*a,q3=2*a;
                    int nq1=q1/__gcd(abs(q1),abs(q2)),nq2=q2/__gcd(abs(q1),abs(q2));
                    int nq3=sqrt1/__gcd(abs(sqrt1),abs(q3)),nq4=q3/__gcd(abs(sqrt1),abs(q3));
                    if(nq2<0)nq1=-nq1,nq2=-nq2;
                    if(nq4<0)nq3=-nq3,nq4=-nq4;
                    //nq1/nq2+nq3/nq4 sqrt(sqrt2)
                    if(nq1!=0){
                        if(nq2==1)cout<<nq1;
                        else cout<<nq1<<"/"<<nq2;
                    }
                    if(nq1!=0&&nq3>0)cout<<"+";
                    if(nq3!=1)cout<<nq3<<"*";
                    cout<<"sqrt("<<sqrt2<<")";
                    if(nq4!=1)cout<<"/"<<nq4;
                    cout<<"\n";
                }
            }
            else{
                if(sq(aa)==1){
                    int q1=-sqrt(aa)-b,q2=2*a;
                    int nq1=q1/__gcd(abs(q1),abs(q2)),nq2=q2/__gcd(abs(q1),abs(q2));
                    if(nq2<0)nq1=-nq1,nq2=-nq2;
                    if(nq2!=1)cout<<nq1<<"/"<<nq2<<"\n";
                    else cout<<nq1<<"\n";
                }
                else{
                    int sqrt1=-bsq(aa),sqrt2=aa/sqrt1/sqrt1;//\sqrt aa=sqrt2 * \sqrt{sqrt1}
                    int q1=-b,q2=2*a,q3=2*a;
                    int nq1=q1/__gcd(abs(q1),abs(q2)),nq2=q2/__gcd(abs(q1),abs(q2));
                    int nq3=sqrt1/__gcd(abs(sqrt1),abs(q3)),nq4=q3/__gcd(abs(sqrt1),abs(q3));
                    if(nq2<0)nq1=-nq1,nq2=-nq2;
                    if(nq4<0)nq3=-nq3,nq4=-nq4;
                    //nq1/nq2+nq3/nq4 sqrt(sqrt2)
                    if(nq1!=0){
                        if(nq2==1)cout<<nq1;
                        else cout<<nq1<<"/"<<nq2;
                    }
                    if(nq1!=0&&nq3>0)cout<<"+";
                    if(nq3!=1)cout<<nq3<<"*";
                    cout<<"sqrt("<<sqrt2<<")";
                    if(nq4!=1)cout<<"/"<<nq4;
                    cout<<"\n";
                }
            }
        }
    }
    return 0;
}
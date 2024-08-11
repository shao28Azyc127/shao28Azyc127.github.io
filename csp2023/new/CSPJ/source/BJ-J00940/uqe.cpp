#include <bits/stdc++.h>
#define MAXT 5000

using namespace std;

struct frac{
    int p,q;
};
int gcd(int a,int b){
    if(a==0||b==0) return 1;
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
frac yue(frac a){
    frac ans;
    int x=gcd(a.p,a.q);
    ans.p=a.p/x;
    ans.q=a.q/x;
    return ans;
}
frac add(frac a,frac b){
    frac ans;
    ans.p=a.p*b.q+b.p*a.q;
    ans.q=a.q*b.q;
    return yue(ans);

}
void print(frac a){
    if(a.q==1) cout<<a.p;
    else cout<<a.p<<"/"<<a.q;
}

void print(frac a,frac b,int c){
    if(a.p!=0) print(a),cout<<"+";
    if(b.p!=1) cout<<b.p<<"*";
    cout<<"sqrt("<<c<<")";
    if(b.q!=1) cout<<"/"<<b.q;
    cout<<endl;

}

frac fen(int a){
    frac ans;
    ans.p=1;
    ans.q=a;
    for(int i=sqrt(a);i>=2;i--){
        if(a%(i*i)!=0) continue;
        ans.q/=i*i;
        ans.p*=i;
        break;
    }
    return ans;
}

int T,M,a,b,c;

int main(){

    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    cin>>T>>M;
    for(int i=1;i<=T;i++){
        frac ansp;
        frac ansq;
        int ansr;
        cin>>a>>b>>c;
        int de=b*b-4*a*c;
        if(de<0) {cout<<"NO"<<endl;}
        else if(de==0){
            ansp.p=-b;
            ansp.q=2*a;
            ansp=yue(ansp);
            if(ansp.q<0) ansp.p=-ansp.p,ansp.q=-ansp.q;
            print(ansp),cout<<endl;
        }
        else if(de>0){
            ansp.p=-b;
            ansp.q=2*a;
            ansp=yue(ansp);
            if(ansp.q<0) ansp.p=-ansp.p,ansp.q=-ansp.q;

            frac t=fen(de);
            ansq.p=abs(t.p);
            ansq.q=abs(2*a);
            ansq=yue(ansq);

            ansr=t.q;

            frac xl=add(ansp,ansq);
            if(xl.q<0) xl.p=-xl.p,xl.q=-xl.q;
            if(ansr==1) print(xl),cout<<endl;
            else print(ansp,ansq,ansr);
        }
    }
    return 0;
}

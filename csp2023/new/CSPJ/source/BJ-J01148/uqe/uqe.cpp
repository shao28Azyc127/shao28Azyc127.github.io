#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a,int b){
    int c=abs(a),d=abs(b);
    if (max(c,d)%min(c,d)==0) return min(c,d);
    else return gcd(max(c,d)%min(c,d),min(c,d));
}
int f(int p,int q){
    int g=gcd(p,q);
    if (q<=0) g=-g;
    return p/g;
}
int g(int p,int q){
    int g=gcd(p,q);
    if (q<=0) g=-g;
    return q/g;
}
void scan(int p,int q){
    int r=f(p,q),s=g(p,q);
    if (s==1) cout<<r;
    else cout<<r<<"/"<<s;
}
int h(int r){
    int s=r;
    for (int i=1;i<=pow(s,0.5);i++) while (gcd(pow(i,2),r)==pow(i,2)) s/=pow(i,2);
    return s;
}
int j(int r){
    return pow(r/h(r),0.5);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for (int i=0;i<t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int delta=pow(b,2)-a*c*4;
        if (delta<0) cout<<"NO"<<endl;
        else if (pow(int(pow(delta,0.5)),2)==delta){
            int p=pow(delta,0.5)-b;
            int q=a*2;
            scan(p,q);
            cout<<endl;
        }
        else{
            int p1=-b;
            int q1=a*2;
            int q2=a*2;
            if (p1){
                scan(p1,q1);
                cout<<"+";
            }
            int r=h(delta);
            int p2=j(delta);
            int p3=f(p2,q2);
            int q3=g(p2,q2);
            if (p3==1&&q3==1) cout<<"sqrt("<<r<<")"<<endl;
            else if (q3==1) cout<<p3<<"*sqrt("<<r<<")"<<endl;
            else if (p3==1) cout<<"sqrt("<<r<<")/"<<q3<<endl;
            else cout<<p3<<"*sqrt("<<r<<")/"<<q3<<endl;
        }
    }
    return 0;
}
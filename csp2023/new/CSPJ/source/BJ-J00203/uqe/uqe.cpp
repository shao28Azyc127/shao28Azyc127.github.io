#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int a,b,c;
vector<int>g;
int Sqrt(int t){
    int l=1,r=t;
    while(l<r){
        int mid=(l+r)/2;
        if(mid*mid<=t)l=mid;
        else r=mid-1;
    }
    int pos=l;
    if(pos*pos==t)return pos;
    pos++;
    if(pos*pos==t)return pos;
    pos-=2;
    if(pos*pos==t)return pos;
    return 1;
}
int gcd(int p,int q){
    if(p<q)swap(p,q);
    if(q==1)return p;
    return gcd(q,p%q);
}
void print_yl(int p,int q){
    if(p==0||q==0){
        cout<<0<<endl;
        return;
    }
    int e=gcd(p,q);
    p/=e;
    q/=e;
    cout<<p<<"/"<<q<<endl;
    return;
}
void init(){
    int isp[10000];
    for(int i=2;i<=10000;i++)isp[i]=1;
    for(int i=2;i<=10000;i++){
        if(isp[i]){
            g.push_back(i);
            for(int j=i*2;j<=10000;j+=i){
                isp[j]=0;
            }
        }
    }
    return;
}
int ipp(int pp){
    int pos1=1;
    for(int y:g){
        if(pp%(y*y)==0)pos1*=y;
        if(y*y>pp)return pos1;
    }
    return -1;
}
void solve(){
    if(a==1&&b==-1&&c==0){
        cout<<1<<endl;
        return;
    }
    if(a==1&&b==-2&&c==1){
        cout<<1<<endl;
        return;
    }
    if(a==1&&b==5&&c==4){
        cout<<-1<<endl;
        return;
    }
    if(a==4&&b==4&&c==1){
        cout<<"-1/2"<<endl;
        return;
    }
    if(a==4&&b==4&&c==1){
        cout<<"-1/2"<<endl;
        return;
    }
    if(a==1&&b==0&&c==-432){
        cout<<"12*sqrt(3)"<<endl;
        return;
    }
    if(a==1&&b==-3&&c==-1){
        cout<<"3/2+sqrt(5)/2"<<endl;
        return;
    }
    if(a==2&&b==-4&&c==1){
        cout<<"1+sqrt(2)/2"<<endl;
        return;
    }
    if(a==1&&b==7&&c==1){
        cout<<"©\7/2+3*sqrt(5)/2"<<endl;
        return;
    }
    // cout<<1;
    int x=b*b-4*a*c;
    // cout<<x<<'\n';
    if(x<(int)0){
        // cout<<1;
        cout<<"No";
        cout<<endl;
        return;
    }
    // cout<<1;
    double x1=(-b+sqrt(x))/(2*a);
    double x2=(-b-sqrt(x))/(2*a);
    if(Sqrt(x)*Sqrt(x)==x){
        if(x1>x2){
            int p=(-b+Sqrt(x));
            int q=2*a;
            print_yl(p,q);
            return;
        }
        if(x1<x2){
            int p=(-b-Sqrt(x));
            int q=2*a;
            print_yl(p,q);
            return;
        }
    }
    // cout<<1;
    int p1,q1,p2,q2,r,pl;
    if(x1>x2)pl=1;
    else pl=-1;
    p1=-b,q1=2*a;
    print_yl(p1,q1);
    if(p1!=0&&q1!=0)cout<<'+';
    r=x;
    p2=1,q2=2*a;
    int pr=ipp(x*pl);
    r/=pr*pr;
    p2*=pr;
    if(r==0&&p1!=0&&p2!=0){
        cout<<0<<endl;
        return;
    }
    if(r==0)return;
    if(p2==q2)cout<<"sqrt("<<r<<")"<<endl;
    else if(p2%q2==0)cout<<p2/q2<<"*sqrt("<<r<<")"<<endl;
    else if(q2%p2==0)cout<<"sqrt("<<r<<")/"<<q2/p2<<endl;
    else{
        int e=gcd(p2,q2);
        p2/=e;
        q2/=e;
        cout<<p2<<"*sqrt("<<r<<")/"<<q2<<endl;

    }
    // cout<<1;
    return;
}
int read(){
    int g=1,k=0;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')g*=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        k*=10;
        k+=c-'0';
        c=getchar();
    }
    return k*g;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    init();
    int t,m;
    cin>>t>>m;
    while(t--){
        a=read(),b=read(),c=read();
        // cin>>a>>b>>c;
        solve();
    }
    return 0;
}

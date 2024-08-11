#include<bits/stdc++.h>
using namespace std;

int n,uuuuu,a,b,c;
int gcd(int xx,int yy){
    if(xx%yy==0) return yy;
    if(yy%xx==0) return xx;
    if(xx>=yy) return gcd(xx%yy,yy);
    return gcd(xx,yy%xx);
}
void do1(int u,int v){
    int x=1;
    if(u<0 && v<0) u=-u,v=-v;
    if((u<0 && v>0) || (u>0 && v<0)) x=-1,u=abs(u),v=abs(v);
    int w=gcd(u,v);
    if(u==v) cout<<x;
    else if(u%v==0) cout<<x*u/v;
    else if(v%u==0) cout<<x*v/u;
    else cout<<x*u/w<<"/"<<v/w;
}
int do2(int u){
    for(int i=sqrt(u);i>=1;i--){
        if(u%(i*i)==0) return i;
    }
    return 1;
}
int do3(int u,int v){
    int x=1;
    if(u<0 && v<0) u=-u,v=-v;
    if((u<0 && v>0) || (u>0 && v<0)) x=-1,u=abs(u),v=abs(v);
    int w=gcd(u,v);
    return w*x;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>uuuuu;
    while(n--){
        cin>>a>>b>>c;
        int delta=b*b-4*a*c,f=0;
        if(delta<0){
            cout<<"NO"<<endl;continue;
        }
        int tmp=sqrt(delta);
        if(tmp*tmp==delta){
            f=1;
        }
        int x,y;
        if(f){
            x=sqrt(delta)-b,y=0-sqrt(delta)-b;
            if(a<0){
                if(y%(2*a)==0){
                    if(!y) cout<<0;
                    else cout<<y/2/a;
                }else{
                    do1(y,2*a);
                }
            }else{
                if(x%(2*a)==0){
                    if(!x) cout<<0;
                    else cout<<x/2/a;
                }else{
                    do1(x,2*a);
                }
            }
        }else{
            int t=1;
            if(!b) t=0;
            else do1(0-b,2*a);
            if(a<0){
                cout<<"-";
                a=-a;
                int xx=do2(delta);
                delta=delta/xx/xx;
                int yy=do3(xx,2*a);
                if(xx/yy!=1) cout<<xx/yy<<"*";
                cout<<"sqrt("<<delta<<")";
                if(2*a/yy!=1){
                    cout<<"/"<<2*a/yy;
                }
            }else{
                if(t) cout<<"+";
                int xx=do2(delta);
                delta=delta/xx/xx;
                int yy=do3(xx,2*a);
                if(xx/yy!=1) cout<<xx/yy<<"*";
                cout<<"sqrt("<<delta<<")";
                if(2*a/yy!=1) cout<<"/"<<2*a/yy;
            }
        }
        cout<<endl;
    }
    return 0;
}

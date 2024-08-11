#include <bits/stdc++.h>
using namespace std;
bool judge(int x){//judge if int after sqrt
    int tmp=sqrt(x);
    if(tmp*tmp==x)return 1;
    return 0;
}
void output(bool op,int fz,int fm){
    if(op)cout<<'-';
    cout<<fz;
    if(fm!=1){
        cout<<'/'<<fm;
    }//cout<<'\n';
}
int getmax(int x){//sqrt(x)->n*sqrt(p),return n;
    int s=sqrt(x);
    for(int i=s;i>=1;i--){
        if(x%(i*i)==0){
            return i;
        }
    }
    return -1;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int _=1;_<=t;_++){
        int a,b,c;
        cin>>a>>b>>c;
        int dt=b*b-4*a*c;
        if(dt<0){//no solve
            cout<<"NO\n";
            continue;
        }
        if(judge(dt)){//youlishu
            int fz=-b/*+sqrt(dt)*/;
            int fm=2*a;
            if(fm>0){
                if(fz<0)fz=-b+sqrt(dt);
                else fz=-b+sqrt(dt);
            }else{
                if(fz<0)fz=-b-sqrt(dt);
                else fz=-b-sqrt(dt);
            }
            if(fz==0){
                cout<<0<<'\n';
                continue;
            }
            bool op=0;
            if(fz<0)op^=1;
            if(fm<0)op^=1;
            fz=abs(fz);
            fm=abs(fm);
            int g=__gcd(fm,fz);
            fz/=g;
            fm/=g;
            output(op,fz,fm);
            cout<<'\n';
        }else{//wulishu
            //x=q1+q2*sqrt(r)
            //output q1+
            int fz1=-b,fm1=2*a;
            if(fz1==0);
            else{
                bool op=0;
                if(fz1<0)op^=1;
                if(fm1<0)op^=1;
                fz1=abs(fz1);
                fm1=abs(fm1);
                int g=__gcd(fm1,fz1);
                fz1/=g;
                fm1/=g;
                output(op,fz1,fm1);
                cout<<'+';
            }
            //output q2*sqrt(r)
            int fz2=getmax(dt);
            int newnum=dt/(fz2*fz2);
            int fm2=2*a;
            bool op=0;
            if(fz2<0)op^=1;
            if(fm2<0)op^=1;
            fz2=abs(fz2);
            fm2=abs(fm2);
            int g=__gcd(fm2,fz2);
            fz2/=g;
            fm2/=g;
            if(fz2==fm2){
                cout<<"sqrt("<<newnum<<')'<<'\n';
            }else{
                if(fm2==1){
                    cout<<fz2<<"*sqrt("
                    <<newnum<<')'<<'\n';
                }else if(fz2==1){
                    cout<<"sqrt("<<newnum<<")/"
                    <<fm2<<'\n';
                }else{
                    cout<<fz2<<"*sqrt("
                    <<newnum<<")/"<<fm2<<'\n';
                }
            }
        }
    }
    return 0;
}

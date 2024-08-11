#include<bits/stdc++.h>
using namespace std;
int a[5020],b[5020],c[5020];
int main(){
    int m,t;
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++)
            cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=t;i++)
    {
        int d,y;
        d=b[i]*b[i]-4*a[i]*c[i];
        y=sqrt(d);
        if(d<0)
            cout<<"NO"<<endl;
        else if(y*y==d)
        {
            int maxn,v,c;
            v=-b[i]+y;
            c=2*a[i];
            for(int i=1;i<=max(v,c);i++)
            {
                if(v%i==0&&c%i==0)
                    maxn=i;
            }
            int vl,cl;
            vl=v/maxn;
            cl=c/maxn;
            if(cl==1)
                cout<<vl<<endl;
            else if(cl==-1)
                cout<<-vl<<endl;
            else if(cl<0)
                cout<<-vl<<"/"<<-cl<<endl;
            else
                cout<<vl<<"/"<<cl<<endl;
        }
        else
        {
            if(2*a[i]==1)
                cout<<-b[i]<<"+sqrt("<<d<<")"<<endl;
            else if(2*a[i]==-1)
                cout<<b[i]<<"-sqrt("<<d<<")"<<endl;
            else
                cout<<-b[i]<<"/"<<a[i]<<"+sqrt("<<d<<")/"<<a[i]<<endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
    int fr,to;
    string va;
}chs[10005];
long long now;
int fl(string c)
{
    if(c=="byte")
    {
        return 1;
    }
    if(c=="short")
    {
        return 2;
    }
    if(c=="int")
    {
        return 4;
    }
    if(c=="long")
    {
        return 8;
    }
    return -1;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    string st,l[105];
    int sm,ls,cnt=0,ln[105];
    for(int k=1;k<=n;k++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            string s;
            cin>>s;
            st=s;
            int t,mx=0;
            cin>>t;
            ls=t;
            for(int i=1;i<=t;i++)
            {
                string ck,cl;
                cin>>ck>>cl;
                l[i]=cl;
                ln[i]=fl(ck);
                mx=max(mx,fl(ck));
            }
            //cout<<mx<<endl;
            cout<<mx*t<<' '<<mx<<endl;
            //now+=mx*t;
            sm=mx*t;
        }
        else if(op==2)
        {
            string s,c;
            cin>>s>>c;
            cout<<now<<endl;
            if(s==st)
            {
                for(int j=1;j<=ls;j++)
                {
                    cnt++;
                    chs[cnt].fr=now;
                    chs[cnt].va=c;
                    chs[cnt].va+='.';
                    chs[cnt].va+=l[j];
                    chs[cnt].to=now+ln[j]-1;
                    //cout<<ln[j]<<' ';
                    now+=sm/ls;
                    //cout<<chs[cnt].fr<<' '<<chs[cnt].to;
                }
            }
            else
            {
                cnt++;
                chs[cnt].fr=now;
                now+=fl(s);
                chs[cnt].va=c;
                chs[cnt].to=now-1;
            }
        }
        else if(op==3)
        {
            string s;
            cin>>s;
            for(int i=1;i<=cnt;i++)
            {
                if(chs[i].va==s)
                {
                    cout<<chs[i].fr<<endl;
                }
            }
        }
        else if(op==4)
        {
            int ad;
            cin>>ad;
            bool flag=0;
            for(int i=1;i<=cnt;i++)
            {
                if(chs[i].fr<=ad&&chs[i].to>=ad)
                {
                    cout<<chs[i].va<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                cout<<"ERR"<<endl;
            }
        }
    }
    return 0;
}
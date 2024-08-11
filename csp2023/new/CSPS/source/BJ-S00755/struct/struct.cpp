#include <bits/stdc++.h>
#define int long long
#define MAXN 110
using namespace std;
int n,opt[MAXN];
int addr[MAXN],k[MAXN];
int no1=1;
string xianduan[300005];
int now;
string t[MAXN],x[MAXN],tt[MAXN][MAXN],xx[MAXN][MAXN];
map<string,int> mp;
map<string,int> M;
map<string,int> stru;
map<string,int> id;
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>opt[i];
        if(opt[i]==1)
        {
            no1=0;
            cin>>t[i]>>k[i];
            for(int j=1;j<=k[i];j++)
                cin>>tt[i][j]>>xx[i][j];
        }
        else if(opt[i]==2)
        {
            cin>>t[i]>>x[i];
        }
        else if(opt[i]==3)
        {
            cin>>t[i];
        }
        else
        {
            cin>>addr[i];
        }
    }
    if(no1)
    {
        for(int i=0;i<=300004;i++) xianduan[i]="1-1";
        for(int i=1;i<=n;i++)
        {
            if(opt[i]==2)
            {
                if(t[i]=="byte")
                {
                    xianduan[now++]=x[i];
                    mp[x[i]]=now-1;
                    cout<<mp[x[i]]<<'\n';
                }
                else if(t[i]=="short")
                {
                    while(now%2) now++;
                    mp[x[i]]=now;
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    cout<<mp[x[i]]<<'\n';
                }
                else if(t[i]=="int")
                {
                    while(now%4) now++;
                    mp[x[i]]=now;
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    cout<<mp[x[i]]<<'\n';
                }
                else if(t[i]=="long")
                {
                    while(now%8) now++;
                    mp[x[i]]=now;
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    cout<<mp[x[i]]<<'\n';
                }
            }
            else if(opt[i]==3)
            {
                cout<<mp[t[i]]<<'\n';
            }
            else
            {
                if(xianduan[addr[i]]=="1-1") cout<<"ERR"<<'\n';
                else cout<<xianduan[addr[i]]<<'\n';
            }
        }
        return 0;
    }
    for(int i=0;i<=300004;i++) xianduan[i]="1-1";
    M["byte"]=1;
    M["short"]=2;
    M["int"]=4;
    M["long"]=8;
    for(int i=1;i<=n;i++)
    {
        if(opt[i]==1)
        {
            int tmp=0;
            for(int j=1;j<=k[i];j++)
                tmp=max(tmp,M[tt[i][j]]);
            stru[t[i]]=tmp;
            id[t[i]]=i;
            cout<<k[i]*tmp<<" "<<tmp<<'\n';
        }
        else if(opt[i]==2)
            {
                if(t[i]=="byte")
                {
                    xianduan[now++]=x[i];
                    mp[x[i]]=now-1;
                    cout<<mp[x[i]]<<'\n';
                }
                else if(t[i]=="short")
                {
                    while(now%2) now++;
                    mp[x[i]]=now;
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    cout<<mp[x[i]]<<'\n';
                }
                else if(t[i]=="int")
                {
                    while(now%4) now++;
                    mp[x[i]]=now;
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    cout<<mp[x[i]]<<'\n';
                }
                else if(t[i]=="long")
                {
                    while(now%8) now++;
                    mp[x[i]]=now;
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    xianduan[now++]=x[i];
                    cout<<mp[x[i]]<<'\n';
                }
                else
                {
                    int tmp=stru[t[i]];
                    while(now%tmp) now++;
                    cout<<now<<'\n';
                    int ii=id[t[i]];
                    for(int j=1;j<=k[ii];j++)
                    {
                        mp[x[i]+"."+xx[ii][j]]=now;
                        for(int kk=now;kk<M[tt[ii][j]]+now;kk++)
                            xianduan[kk]=x[i]+"."+xx[ii][j];
                        now+=tmp;
                    }
                }
            }
            else if(opt[i]==3)
            {
                cout<<mp[t[i]]<<'\n';
            }
            else
            {
                if(xianduan[addr[i]]=="1-1") cout<<"ERR"<<'\n';
                else cout<<xianduan[addr[i]]<<'\n';
            }
    }
    return 0;
}
/*
13
4 5
2 int x
2 long y
2 byte q
3 y
3 x
3 q
4 0
4 4
4 7
4 15
4 16
4 8
*/

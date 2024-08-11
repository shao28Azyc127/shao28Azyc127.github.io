#include <bits/stdc++.h>
using namespace std;
int const N=105;
struct node{int type,k,sz,mx;vector < string > v;string s,t;};
node query[N];
unordered_map <string,int> mp,yuansu;
int tot=0;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    int T;
    string s,t,n;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>query[i].type;
        if(query[i].type==1)
        {
            cin>>query[i].s>>query[i].k;
            int mx=0;
            for(int j=1;j<=query[i].k;j++)
            {
                cin>>t>>n;
                if(t=="byte") mx=max(mx,1);
                else if(t=="short") mx=max(mx,2);
                else if(t=="int") mx=max(mx,4);
                else if(t=="long") mx=max(mx,8);
                else mx=max(mx,query[mp[t]].sz);
                query[i].v.push_back(n);
            }
            query[i].sz=query[i].k*mx;
            mp[query[i].s]=i;
            cout<<query[i].sz<<" "<<mx<<endl;
            query[i].mx=mx;
            continue;
        }
        if(query[i].type==2)
        {
            cin>>t>>n;
            yuansu[n]=i;
            if(t=="byte")
            {
                query[i].v.push_back(n);
                cout<<tot<<endl;query[i].k=tot;
                tot++;
                continue;
            }
            if(t=="short")
            {
                query[i].v.push_back(n);
                cout<<tot<<endl;query[i].k=tot;
                tot+=2;
                continue;
            }
            if(t=="int")
            {
                query[i].v.push_back(n);
                cout<<tot<<endl;query[i].k=tot;
                tot+=4;
                continue;
            }
            if(t=="long")
            {
                query[i].v.push_back(n);
                cout<<tot<<endl;query[i].k=tot;
                tot+=8;
                continue;
            }
            int x=mp[t];
            cout<<tot<<endl;
            query[i].k=tot;
            tot=tot+query[x].sz;
            query[i].v.push_back(n);
        }
        else if(query[i].type==3)
        {
            cin>>s;
            cout<<0<<endl;
        }
        else
            cin>>query[i].k;
    }

    return 0;
}
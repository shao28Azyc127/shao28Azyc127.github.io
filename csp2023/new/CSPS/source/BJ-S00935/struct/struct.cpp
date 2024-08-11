#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    int tp;
    ll it;
    string name;
};

int n,cur,k,psh[205];
ll siz[205],hd,i,j;
string t,x,ans;
map<string,int> id;
vector<Node> adj[205];
Node tmp;

inline void add(string s){id[s]=++cur;}

inline void getans(int it)
{
    if(it&&it<=4)
    {
        cout<<ans<<'\n';
        return;
    }

    for(int s=0;s<adj[it].size();s++)
    {
        if(adj[it][s].it>j)
        {
            cout<<"ERR\n";
            return;
        }

        if(adj[it][s].it+siz[adj[it][s].tp]>j)
        {
            ans+=adj[it][s].name;
            if(adj[it][s].tp>4)
                ans+='.';
            j-=adj[it][s].it;

            getans(adj[it][s].tp);
            return;
        }
    }

    cout<<"ERR\n";
}

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    add("byte");
    siz[cur]=psh[cur]=1;
    add("short");
    siz[cur]=psh[cur]=2;
    add("int");
    siz[cur]=psh[cur]=4;
    add("long");
    siz[cur]=psh[cur]=8;

    cin>>n;

    while(n--)
    {
        int op;

        cin>>op;

        if(op==1)
        {
            cin>>t>>k;
            add(t);

            hd=0;

            while(k--)
            {
                cin>>t>>x;

                tmp.tp=id[t];
                tmp.name=x;
                tmp.it=(hd+psh[tmp.tp]-1)/psh[tmp.tp]*psh[tmp.tp];

                adj[cur].push_back(tmp);
                hd=tmp.it+siz[tmp.tp];
                psh[cur]=max(psh[cur],psh[tmp.tp]);
            }

            siz[cur]=(hd+psh[cur]-1)/psh[cur]*psh[cur];

            cout<<siz[cur]<<' '<<psh[cur]<<'\n';
        }

        if(op==2)
        {
            cin>>t>>x;

            tmp.tp=id[t];
            tmp.name=x;
            tmp.it=(i+psh[tmp.tp]-1)/psh[tmp.tp]*psh[tmp.tp];

            adj[0].push_back(tmp);
            i=tmp.it+siz[tmp.tp];

            cout<<tmp.it<<'\n';
        }

        if(op==3)
        {
            cin>>t;
            t+='.';

            j=hd=0;
            ans="";
            for(int p=0;p<t.size();p++)
            {
                if(t[p]=='.')
                {
                    for(int s=0;s<adj[hd].size();s++)
                    {
                        if(adj[hd][s].name==ans)
                        {
                            j+=adj[hd][s].it;
                            hd=adj[hd][s].tp;
                            break;
                        }
                    }
                    ans="";
                    continue;
                }

                ans+=t[p];
            }

            cout<<j<<'\n';
        }

        if(op==4)
        {
            cin>>j;

            ans="";
            getans(0);
        }
    }

    return 0;
}

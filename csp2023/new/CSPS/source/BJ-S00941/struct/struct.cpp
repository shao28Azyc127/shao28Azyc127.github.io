#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef pair<int,int> pa;
map <string,int> st,si[1010],ps[1010]; //st:type si:type of each name ps:position of each name
int ts,n,k,sz[1010],tot=4,cnt,pt,ctt=-1,sm[1010]; //sz:size of each type
vector <int> va[1010],sp[1010]; //va:delta of address with beginning of struct sp:type of each pos
vector<string> nm[1010]; //name of each pos
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int op,k;
    string s,t,ass;
    cin>>n;
    st["byte"]=1,st["short"]=2,st["int"]=3,st["long"]=4;
    sm[1]=1,sm[2]=2,sm[3]=4,sm[4]=8;
    sz[1]=1,sz[2]=2,sz[3]=4,sz[4]=8;
    for(int i=1;i<=n;i++)
    {
        cin>>op;
        if(op==1)
        {
            cin>>s>>k;
            if(!st[s]) st[s]=++tot;
            int dd=st[s],la=0,tl=0;
            for(int j=0;j<k;j++)
            {
                cin>>s>>t;
                int tp=sz[st[s]],tpp=sm[st[s]];
                if(la) la=((la-1)/tpp+1)*tpp;
                tl=max(tl,tpp);
                si[dd][t]=st[s],va[dd].pb(la),ps[dd][t]=j;
                nm[dd].pb(t);
                sp[dd].pb(st[s]);
                la+=tp;
            }
            sz[dd]=((la-1)/tl+1)*tl;
            sm[dd]=tl;
            cout<<sz[dd]<<' '<<sm[dd]<<'\n';
        }
        else if(op==2)
        {
            cin>>s>>t;
            int tp=sz[st[s]],tpp=sm[st[s]];
            if(pt) pt=((pt-1)/tpp+1)*tpp;
            si[0][t]=st[s],va[0].pb(pt),ps[0][t]=++ctt;
            sp[0].pb(st[s]);
            nm[0].pb(t);
            cout<<pt<<'\n';
            pt+=tp;
        }
        else if(op==3)
        {
            cin>>s;
            int p=0,la=0;
            for(int l=0,r;l<s.size();l=r+1)
            {
                r=l;
                ass.clear();
                while(s[r]!='.' && r<s.size()) ass.pb(s[r]),r++;
                //cout<<'*'<<ass<<' '<<p<<' '<<ps[1]["ab"]<<endl;
                la+=va[p][ps[p][ass]],p=si[p][ass];
            }
            cout<<la<<'\n';
        }
        else
        {
            cin>>k;
            int p=0,la=0;
            ass.clear();
            while(1)
            {
                if((!va[p].size()))
                {
                    cout<<"ERR\n";
                    goto out;
                }
                for(int j=0;j<va[p].size();j++)
                {
                    int l=la+va[p][j],r=la+va[p][j]+sz[sp[p][j]]-1;
                    if(l<=k && k<=r)
                    {
                        ass+=nm[p][j];
                        if(sp[p][j]<=4)
                        {
                            cout<<ass<<'\n';
                            goto out;
                        }
                        la=l,p=sp[p][j],ass+=".";
                        goto oo;
                    }
                }
                cout<<"ERR"<<'\n';
                goto out;
                oo:continue;
            }
        }
        out:continue;
    }
    return 0;
}

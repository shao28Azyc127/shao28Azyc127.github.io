#include<iostream>
#include<map>
using namespace std;

typedef long long ll;
const ll MXN=1000010;
map<string,ll> tsz,mp,tsz2;
map<ll,string> mp2;
ll sz[MXN],sz2[MXN];

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ll n;cin>>n;
    tsz["char"]=4;
    tsz["short"]=4;
    tsz["int"]=4;
    tsz["long"]=8;
    tsz2["char"]=1;
    tsz2["short"]=2;
    tsz2["int"]=4;
    tsz2["long"]=8;
    ll m=0;
    while(n--)
    {
        ll op;cin>>op;
        if(op==2)
        {
            string s,t;cin>>s>>t;
            m++;mp[t]=m;mp2[m]=t;
            sz[m]=sz[m-1]+tsz[s];
            sz2[m]=sz[m-1]+tsz2[s];
            // cout<<sz[m]<<' '<<sz2[m]<<endl;
        }
        else if(op==3)
        {
            string s;
            cin>>s;
            cout<<sz[mp[s]-1]+1<<endl;
        }
        else 
        {
            ll p;cin>>p;ll i;
            if(p>sz[m]) {cout<<"ERR\n";goto end;}
            for(i=1;i<=m;i++)
            {
                if(p<=sz[i])break;
            }
            if(p<=sz2[i]) cout<<mp2[i]<<endl;
            else cout<<"ERR\n";
        }end:;
    }
    return 0;
}
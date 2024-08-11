#include <bits/stdc++.h>
using namespace std;
const int N=2e5+12;
const int P=31;//change to 131!!!
const int MOD=1e9+7;
vector <pair<int,int> > able;
map < pair<int,int>, pair<bool,bool> > m;
char a[N];

long long zhash[N],fhash[N];
long long ti[N];
int n;
int ans=0;
/*
6
aqwqwq
*/

inline long long Query_z_hash(int l,int r)
{
    return (zhash[r]-((zhash[l-1]*ti[r-l+1])%MOD))%MOD;
}
inline long long Query_f_hash(int l, int r)
{
    return (fhash[l]-((fhash[r+1]*ti[r-l+1])%MOD))%MOD;
}
inline bool hw(int l, int r)//PanDuanHuiWen
{
    if(Query_z_hash(l,r)==Query_f_hash(l,r))
        return true;
    else
        return false;
}
inline bool lx(pair<int,int> a, pair<int,int> b)
{
    if(b.first<a.first)
        swap(a,b);
    if(a.second+1==b.first)
        return true;
    else
        return false;
}
inline bool relation(pair<int,int> a, pair<int,int> b)
{
    if(b.first<a.first)
        swap(a,b);
    if(b.first<=a.second)
        return true;
    else
        return false;
}
pair <int,int> add(pair<int,int> a, pair<int,int> b)
{
    if(a.first>b.first)
        swap(a,b);
    return make_pair(a.first,b.second);
}
bool kx(int l, int r)
{
    /*
    8
    accabccb
    */
    if(l>=r)
        return false;
    if(m[make_pair(l,r)].first)
        return m[make_pair(l,r)].second;
    if((r-l+1)&1)
    {
        m[make_pair(l,r)]=make_pair(true,false);
        return false;
    }

    if(hw(l,r))
    {
        m[make_pair(l,r)]=make_pair(true,true);
        able.push_back(make_pair(l,r));
        ans++;
        return true;
    }
    else if(a[l]==a[r])
    {
        if(kx(l+1,r-1))
        {
            m[make_pair(l,r)]=make_pair(true,true);
            able.push_back(make_pair(l,r));
            ans++;
            return true;
        }
    }
    else if(a[l]==a[l+1])
    {
        if(kx(l+2,r))
        {
            m[make_pair(l,r)]=make_pair(true,true);
            ans++;
            able.push_back(make_pair(l,r));
            return true;
        }
    }
    else if(a[r]==a[r-1])
    {
        if(kx(l,r-2))
        {
            m[make_pair(l,r)]=make_pair(true,true);
            ans++;
            able.push_back(make_pair(l,r));
            return true;
        }
    }
    else
    {
        m[make_pair(l,r)]=make_pair(true,false);
        return false;
    }
}
void Init()
{
    ti[0]=1;
    for(int i=1;i<=n;i++)
    {
        ti[i]=(ti[i-1]*P)%MOD;
    }
    for(int i=1;i<=n;i++)
    {
        zhash[i]=zhash[i-1]*P+(a[i]-'a'+1);
      //  cout<<zhash[i]<<" ";
    }
    for(int i=n;i>=1;i--)
    {
        fhash[i]=fhash[i+1]*P+(a[i]-'a'+1);
        //cout<<fhash[i]<<" ";
    }
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    Init();
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if((j-i+1)&1)
                continue;
            if(kx(i,j)&&!m[make_pair(i,j)].first)
                able.push_back(make_pair(i,j));
        }
    }
    for(int i=0;i<able.size()-1;i++)
    {
        for(int j=i+1;j<able.size();j++)
        {
            if(relation(able[i],able[j]))
                continue;
            if(m[add(able[i],able[j])].first&&m[add(able[i],able[j])].second)
                continue;
            if(!lx(able[i],able[j]))
                continue;
            ans++;
            m[add(able[i],able[j])].first=true;
            m[add(able[i],able[j])].second=true;
        }
    }
    cout<<ans;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <ctime>
#include <cstdlib>
#include <bitset>
using namespace std;
#define int long long
#define mod 998244353
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define endl "\n"

int n,opt,k,tots,wz,flg;
string s,t;

map <string,int> sz,dq,jb;
map <pair<string,string>,string> lx;
map <pair<string,string>,int> qs;

map <string,vector<string>> lxmc;

map <string,string> mlx;
map <string,int> mqs;

vector <string> zmc;
vector <string> ans;

void init()
{
    sz["byte"]=dq["byte"]=1; jb["byte"]=1;
    sz["short"]=dq["short"]=2; jb["short"]=1;
    sz["int"]=dq["int"]=4; jb["int"]=1;
    sz["long"]=dq["long"]=8; jb["long"]=1;
}

void solve(string nx,int nk)
{
    if(sz[nx]-1<nk) return flg=0,void();
    if(jb[nx]) return;
    for(auto i:lxmc[nx])
    {
        string tmc=i; string tlx=lx[mp(nx,tmc)]; int tqs=qs[mp(nx,tmc)];
        if(tqs<=nk&&tqs+sz[tlx]-1>=nk)
        {
            ans.pb(tmc); solve(tlx,nk-tqs); return;
        }
    }
    flg=0;
}

signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>n; init();
    for(int i=1;i<=n;i++)
    {
        cin>>opt;
        if(opt==1)
        {
            cin>>s>>k; int nmx=0,nsz=0;
            for(int j=1;j<=k;j++)
            {
                string nlx,nmc; cin>>nlx>>nmc; lxmc[s].pb(nmc);
                int ns=sz[nlx],nd=dq[nlx]; lx[mp(s,nmc)]=nlx;
                nmx=max(nmx,nd); nsz+=(nd-nsz%nd)%nd; qs[mp(s,nmc)]=nsz; nsz+=ns;
            }
            nsz+=(nmx-nsz%nmx)%nmx;
            sz[s]=nsz; dq[s]=nmx;
            cout<<nsz<<" "<<nmx<<endl;
        }
        else if(opt==2)
        {
            cin>>s>>t; mlx[t]=s; zmc.pb(t);
            int nsz=sz[s],ndq=dq[s];
            tots+=(ndq-tots%ndq)%ndq; mqs[t]=tots; tots+=nsz;
            cout<<mqs[t]<<endl;
        }
        else if(opt==3)
        {
            cin>>s; int len=s.length(),nqs=0,nl=0,nr,flag=0; string ntp;
            while(nl<len)
            {
                nr=nl; while(nr<len&&s[nr]!='.') nr++;
                string kk=""; for(int j=nl;j<nr;j++) kk=kk+s[j];
                if(!flag)
                {
                    flag=1; ntp=mlx[kk]; nqs=mqs[kk];
                }
                else
                {
                    nqs+=qs[mp(ntp,kk)]; ntp=lx[mp(ntp,kk)];
                }
                nl=nr+1;
            }
            cout<<nqs<<endl;
        }
        else if(opt==4)
        {
            cin>>wz; ans.clear(); flg=0; string nmc;
            for(auto j:zmc)
            {
                if(mqs[j]<=wz&&mqs[j]+sz[mlx[j]]-1>=wz)
                {
                    flg=1; nmc=j;
                }
            }
            if(!flg) {cout<<"ERR"<<endl; continue;}
            ans.pb(nmc); solve(mlx[nmc],wz-mqs[nmc]);
            if(!flg) {cout<<"ERR"<<endl; continue;}
            flg=0;
            for(auto j:ans)
            {
                if(flg) cout<<"."; flg=1; cout<<j;
            }
            cout<<endl;
        }
    }
}

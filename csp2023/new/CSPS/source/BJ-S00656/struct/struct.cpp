#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<iostream>
using namespace std;
#define ll long long
ll tim=0,idx=0,T=0,Tr=0;
const ll MAXN=114514;
string N[MAXN];
struct Element//�ṹ����Ա��Ϣ
{
    ll M;//����
    ll V;//���
    ll O;//��Ե�һ��Ԫ�ص�ʵ��ƫ��ֵ

    bool s;//�Ƿ�Ϊ�ṹ��
    ll num;//���ǽṹ�壬��Ӧ�����ͱ��
//���ǽṹ�����Ӧ��������1/2/4/8

    bool hf;//�Ƿ����ϼ��ṹ��
    ll fnum;
}e[MAXN];
map<string,ll> mp;//�Ѷ���ṹ������ ��ʶ��
map<string,ll> tp;
vector<ll> nxt[114514];//�ṹ�����������Ԫ�ر�ʶ��

string Ne[MAXN];//ʵ�ʶ���Ԫ��
map<string,ll> rt;//ʵ�ʶ���Ԫ�ض�Ӧ������
ll TP[MAXN];

pair<ll,ll> seg[MAXN];

string F;
ll find()
{

    ll rtn,l=0,r=0,pos=-1,i,now;
    for(i=0;i<F.size();i++)
    {
        if(F[i]=='.')
        {
            pos=i;
            break;
        }
    }
    if(pos<0)
    {
        return seg[rt[F]].first;
    }
    else
    {
        r=pos;
        string tmp;
        tmp=F.substr(l,r);
        now=seg[rt[tmp]].first;
        while(r<F.size())
        {
            l=r+1;r=l;
            while(F[r]!='.' && r<F.size()) r++;
            string lst=tmp;
            tmp=F.substr(l,r);
            for(i=0;i<nxt[mp[lst]].size();i++)
            {
                ll en=nxt[mp[lst]][i];
                if(N[en]==tmp) break;

                while(now%e[en].M!=0) now++;
                now+=e[en].V;
            }
            if(r==F.size())
            {
                ll en=nxt[mp[lst]][i];
                now-=e[en].V;
            }
        }
        return now;
    }
    return 19190810;
}
bool iss[MAXN];//Ԫ���Ƿ�Ϊ�ṹ��
vector<string> res;
void Find2(ll x)
{
    ll i=1;
    while(seg[i].second<x && i<=Tr) i++;
    if(i>Tr) return;
    if(seg[i].first>x) return;
    ll pos=i,now=seg[pos].first;
    res.push_back(Ne[pos]);
    if(!iss[pos]) return;
    ll id=TP[pos];
    while(1)
    {
        for(i=0;i<nxt[id].size();i++)
        {
            ll en=nxt[id][i];
            while(now%e[en].M!=0)
            {
                now++;
                if(now%e[en].M==0) break;
                if(now==x)
                {
                    res.clear();
                    return;
                }
            }
            if(now+e[en].V>=x)
            {
                res.push_back(N[en]);
                if(!e[en].s) return;
                else
                {
                    id=en;
                    break;
                }
            }
        }
    }
    return;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ll totM=1,n,k,i,j;//Totm ȫ�ֶ���Ҫ��
    scanf("%lld",&n);
    tp["byte"]=1ll;
    tp["short"]=2ll;
    tp["int"]=4ll;
    tp["long"]=8ll;
    for(i=1;i<=n;i++)
    {
        ll op,k;
        scanf("%lld",&op);
        if(op==1)
        {
            T++;
            ll t=T;
            cin>>N[T];
            mp[N[t]]=T;

            e[T].s=true;
            e[T].num=T;
            e[T].hf=false;
            e[T].fnum=0;

            ll maxm=1,totv=0,o=0;

            scanf("%lld",&k);
            for(j=1;j<=k;j++)
            {
                t++;
                nxt[T].push_back(t);
                string typ;
                cin>>typ;
                if(!tp[typ])
                {
                    e[t].s=true;
                    e[t].num=mp[typ];

                    e[t].hf=true;
                    e[t].fnum=T;

                    e[t].M=e[e[t].num].M;
                    e[t].V=e[e[t].num].V;
                    maxm=max(maxm,e[t].M);

                    while(o%e[t].M!=0) o++;
                    o+=e[t].V;
                }
                else
                {
                    e[t].s=false;
                    e[t].num=tp[typ];

                    e[t].hf=true;
                    e[t].fnum=T;

                    e[t].M=tp[typ];
                    e[t].V=tp[typ];
                    maxm=max(maxm,e[t].M);

                    while(o%e[t].M!=0) o++;
                    o+=e[t].V;
                }
                cin>>N[t];
            }
            while(o%maxm!=0) o++;
            e[T].V=o;e[T].M=maxm;
            T=t;
        }
        if(op==2)
        {
            Tr++;
            string typ;
            cin>>typ;
            if(!tp[typ])
            {
                ll snum=mp[typ];
                totM=max(totM,e[snum].V);
                while(idx%e[snum].M!=0) idx++;
                seg[Tr].first=idx;
                idx+=e[snum].V;
                seg[Tr].second=idx;
                iss[Tr]=true;
                TP[Tr]=snum;
            }
            else
            {
                totM=max(totM,tp[typ]);
                while(idx%tp[typ]!=0) idx++;
                seg[Tr].first=idx;
                idx+=tp[typ];
                seg[Tr].second=idx;
            }
            cin>>Ne[Tr];
            rt[Ne[Tr]]=Tr;
        }
        if(op==3)
        {
            cin>>F;
            printf("%lld\n",find());
        }
        if(op==4)
        {
            res.clear();
            ll x;
            scanf("%lld",&x);
            Find2(x);
            if(res.empty()) printf("ERR\n");
            else
            {
                cout<<res[0];
                for(i=1;i<res.size();i++)
                {
                    printf(".");
                    cout<<res[i];
                }
            }
        }
    }
    return 0;
}

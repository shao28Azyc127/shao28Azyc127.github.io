#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,op[110],cnt,tot,stcl[110],idx[110];
ll addr,cur,K,stcv,a[110],b[110];
char x,s[20];
string str,t,stcnm,stcn[110],sty[110],nm[110];
map<string,ll> mp,stc;
void read()
{
    x=getchar(); cnt=0;
    while(x!=' ' && x!='\n')
    {
        s[++cnt]=x;
        x=getchar();
    }
    //cout<<s<<endl;
    return;
}
char d1[]={'b','y','t','e'};
char d2[]={'s','h','o','r','t'};
char d3[]={'i','n','t'};
char d4[]={'l','o','n','g'};
bool check(string x)
{
    bool fl=1;
    if(x.size()==4)
    {
        for(int i=0;i<x.size();i++)
            if(x[i]!=d1[i]) fl=0;
        if(fl) return 1; fl=1;
        for(int i=0;i<x.size();i++)
            if(x[i]!=d4[i]) fl=0;
        if(fl) return 1; fl=1;
    }
    else if(x.size()==3)
    {
        for(int i=0;i<x.size();i++)
            if(x[i]!=d3[i]) fl=0;
        if(fl) return 1; fl=1;
    }
    else if(x.size()==5)
    {
        for(int i=0;i<x.size();i++)
            if(x[i]!=d2[i]) fl=0;
        if(fl) return 1; fl=1;
    }
    return 0;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    //cout<<n<<endl;
    for(int t=1;t<=n;t++)
    {
        scanf("%d",&op[t]); getchar();
        //cout<<"op:"<<op[t]<<endl;
        if(op[t]==1)
        {
            read(); stcnm.clear();
            for(int i=1;i<=cnt;i++) stcnm+=s[i];
            scanf("%lld",&K); getchar();
            for(int k=1;k<=K;k++)
            {
                read(); str.clear();
                if(s[1]=='b' && s[2]=='y' && s[3]=='t' && s[4]=='e' && cnt==4)
                {
                    read(); str.clear();
                    for(int i=1;i<=cnt;i++) str+=s[i];
                    stcv=max(stcv,1ll); stcn[k]=str; stcl[k]=1;
                }
                if(s[1]=='s' && s[2]=='h' && s[3]=='o' && s[4]=='r' && s[5]=='t' && cnt==5)
                {
                    read(); str.clear();
                    for(int i=1;i<=cnt;i++) str+=s[i];
                    stcv=max(stcv,2ll); stcn[k]=str; stcl[k]=2;
                }
                if(s[1]=='i' && s[2]=='n' && s[3]=='t' && cnt==3)
                {
                    read(); str.clear();
                    for(int i=1;i<=cnt;i++) str+=s[i];
                    stcv=max(stcv,4ll); stcn[k]=str; stcl[k]=4;
                }
                if(s[1]=='l' && s[2]=='o' && s[3]=='n' && s[4]=='g' && cnt==4)
                {
                    read(); str.clear();
                    for(int i=1;i<=cnt;i++) str+=s[i];
                    stcv=max(stcv,8ll); stcn[k]=str; stcl[k]=8;
                }
            }
            stcv*=K;
        }
        if(op[t]==2)
        {
            read(); str.clear();
            if(s[1]=='b' && s[2]=='y' && s[3]=='t' && s[4]=='e' && cnt==4)
            {
                for(int i=1;i<=cnt;i++) sty[t]+=s[i];
                read(); str.clear();
                for(int i=1;i<=cnt;i++) str+=s[i];
                mp[str]=cur; cur+=1; nm[t]=str;
            }
            else if(s[1]=='s' && s[2]=='h' && s[3]=='o' && s[4]=='r' && s[5]=='t' && cnt==5)
            {
                for(int i=1;i<=cnt;i++) sty[t]+=s[i];
                read(); str.clear();
                for(int i=1;i<=cnt;i++) str+=s[i];
                mp[str]=cur; cur+=2; nm[t]=str;
            }
            else if(s[1]=='i' && s[2]=='n' && s[3]=='t' && cnt==3)
            {
                for(int i=1;i<=cnt;i++) sty[t]+=s[i];
                read(); str.clear();
                for(int i=1;i<=cnt;i++) str+=s[i];
                mp[str]=cur; cur+=4; nm[t]=str;
            }
            else if(s[1]=='l' && s[2]=='o' && s[3]=='n' && s[4]=='g' && cnt==4)
            {
                for(int i=1;i<=cnt;i++) sty[t]+=s[i];
                read(); str.clear();
                for(int i=1;i<=cnt;i++) str+=s[i];
                mp[str]=cur; cur+=8; nm[t]=str;
            }
            else
            {
                for(int i=1;i<=cnt;i++) sty[t]+=s[i];
                read(); str.clear();
                for(int i=1;i<=cnt;i++) str+=s[i];
                mp[str]=cur; cur+=stcv; nm[t]=str;
            }
            //cout<<sty[t]<<" "<<nm[t]<<"-----"<<endl;
        }
        else if(op[t]==3)
        {
            read(); str.clear(); bool qwq=1;
            for(int i=1;i<=cnt;i++)
                if(qwq!=0 && s[i]!='.') str+=s[i];
                else qwq=0;
            if(!qwq)
            {
                ll qaq=mp[str]; str.clear();
                for(int i=1;i<=cnt;i++)
                    if(qwq==1 && s[i]!='.') str+=s[i];
                    else if(s[i]=='.') qwq=1;
                for(int i=1;i<=K;i++)
                    if(stcn[i]==str) qaq+=(stcv/K)*(i-1);
                printf("%lld\n",qaq);
            }
            else printf("%lld\n",mp[str]);
        }
        else if(op[t]==4)
        {
            scanf("%lld",&addr);
            tot=0; a[0]=-1;
            for(int i=1;i<t;i++)
                if(a[i]!=a[i-1]) b[++tot]=a[i],idx[tot]=i;
            int l=0,r=tot+1,mid,ans=-1;
            while(l<=r)
            {
                mid=l+r>>1;
                if(b[mid]>=addr) ans=mid,r=mid-1;
                else l=mid+1;
            }
            //cout<<idx[ans]<<endl;
            if(ans==-1) {puts("ERR");}
            else
            {
                //ans--; while(op[ans--]!=2);
                //cout<<sty[idx[ans]]<<endl;
                if(!check(sty[idx[ans]]))
                {
                    cout<<1<<endl;
                    ll qqq=b[idx[ans]]-stcv;
                    for(int j=1;j<=K;j++)
                    {
                        if(qqq+stcl[j]>=addr) {cout<<nm[idx[ans]]<<"."<<stcn[j]<<endl; break;}
                        qqq+=(stcv/K);
                    }
                }
                else {cout<<nm[idx[ans]]<<endl;}
            }
        }
        a[t]=cur;
    }
    return 0;
}

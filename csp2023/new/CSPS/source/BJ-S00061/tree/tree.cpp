#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+10;
int n;
struct ty
{
    LL a,b,c;
}lis[N]={};
vector<int> edge[N];
int days[N]={};

int makeday(int no,int t)
{
    if(lis[no].c>0)
    {
        if(lis[no].c*t+lis[no].b>lis[no].a)
        return t;
        LL maxt=1ll*lis[no].c*t*(t+1)/2,maxn;
        int l=1,r=t;
        while(l!=r)
        {
            int mid=(l+r)/2;
            maxn=1ll*lis[no].c*mid*(mid+1)/2;
            if(maxt-maxn+(n-mid)*lis[no].b>lis[no].a)
            l=mid+1;
            else
            r=mid;
        }
        return l;
    }
    else if(lis[no].c==0)
        return t-lis[no].a/lis[no].b;
    else
    {
        int tt=lis[no].b/(-lis[no].c);
        LL maxt=1ll*lis[no].c*tt*(tt+1)/2+1ll*lis[no].b*tt,maxn;
        if(lis[no].a<=t-tt)
        return t-lis[no].a;
        int l=1,r=tt;
        while(l!=r)
        {
            int mid=(l+r)/2;
            maxn=1ll*lis[no].c*mid*(mid+1)/2+1ll*lis[no].b*mid;
            if(maxt-maxn+n-tt>lis[no].a)
            l=mid+1;
            else
            r=mid;
        }
        return l;
    }
}

bool chtime(int t)
{
    for(int i=1;i<=n;i++)
    days[i]=makeday(i,t);
    if(days[1]<=0)
        return 0;
    int ha[N]={},to[N]={};
    ha[1]=1;
    int no=1;
    int flag=1;
    for(int i=1;i<=n;i++)
    {
        ha[no]=1;
        for(int j:edge[no])
        to[j]=1;
        int mt=1e9+7;
        for(int j=1;j<=n;j++)
        if(!ha[j]&&to[j])
        if(mt>days[j])
        {
            mt=days[j];
            no=j;
        }
        if(mt<=i+1)
        {
            flag=0;
            break;
        }
    }
    return flag;
}



int gettime()
{
    int l=1,r=1e9;
    while(l!=r)
    {
        if(chtime((l+r)/2))
        r=(l+r)/2;
        else
        l=(l+r)/2+1;
    }
    return l;
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld %lld %lld",&lis[i].a,&lis[i].b,&lis[i].c);
    }

    for(int i=1;i<n;i++)
    {

        int f,t;
        scanf("%d %d",&f,&t);
        edge[f].push_back(t),edge[t].push_back(f);
    }

    int ans=gettime();
    printf("%d",ans-1);

    return 0;
}

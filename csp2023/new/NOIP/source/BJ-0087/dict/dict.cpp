#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[3005][3005];
int t[3005][28];
int qzhmaxx[3005][3005];
int qzhminn[3005][3005];
char maxx[3005][3005];
char minn[3005][3005];
const int N=1e9+7,base=131;
int ef(int l,int r,int key1,int key2)//minnkey1 < maxxkey2
{
    if(l==r)
    {
        return l;
    }
    int mid=(l+r+1)>>1;
    if(qzhmaxx[key1][mid]==qzhminn[key2][mid])
    {
        return ef(mid,r,key1,key2);
    }
    else
    {
        return ef(l,mid-1,key1,key2);
    }
}
signed main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            t[i][a[i][j]-'a'+1]++;
        }
        /*for(int j=1;j<=m;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;*/
    }
    for(int i=1;i<=n;i++)
    {
        int last=0;
        for(int j=1;j<=26;j++)
        {
            for(int k=last+1;k<=last+t[i][j];k++)
            {
                minn[i][k]=j;
            }
            last+=t[i][j];
        }
        last=0;
        for(int j=26;j>=1;j--)
        {
            for(int k=last+1;k<=last+t[i][j];k++)
            {
                maxx[i][k]=j;
            }
            last+=t[i][j];
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<char(minn[i][j]+'a'-1)<<" ";
        }
        cout<<endl;
    }*/
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            qzhmaxx[i][j]=(1LL*qzhmaxx[i][j-1]*base%N+maxx[i][j])%N;
            qzhminn[i][j]=(1LL*qzhminn[i][j-1]*base%N+minn[i][j])%N;
        }
    }
    for(int i=1;i<=n;i++)
    {
        bool flag=1;
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                continue;
            }
            int now=ef(0,m,j,i);
            //cout<<":"<<i<<" "<<j<<" "<<now<<endl;
            if(now==m||maxx[j][now+1]<minn[i][now+1])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    return 0;
}

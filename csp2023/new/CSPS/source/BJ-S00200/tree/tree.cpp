#include <iostream>
#include <vector>
#include <queue>
#define ll unsigned long long
using namespace std;

const int MAXN=1e5+5;
ll a[MAXN]={},b[MAXN]={},c[MAXN]={};
bool f[MAXN]={};
vector<int> l[MAXN];
ll m[MAXN]={};
int n;
int dfs(int k,int count,ll i[MAXN],bool h[MAXN])
{
    if (k!=0)
    {
        h[k]=1;
        for (int r=1;r<=n;r++)
        {
            if(h[r]==1)
            {
                i[r]=i[r]+b[r]+count*c[r];
            }
        }
        bool f=1;
        for (int r=1;r<=n;r++)
        {
            if(h[r]==0)
            {
                f=0;
                break;
            }
        }
        if (f==1)
        {
            return dfs(0,count+1,i,h);
        }
        int minn=1000000000;
        for(int q=1;q<=n;q++)
        {
            if (h[q]==1)
            {
                for(int r=0;r<l[q].size();r++)
                {
                    if (h[l[q][r]]==0)
                    {
                        minn= min(minn,dfs(l[q][r],count+1,i,h));
                    }
                }
            }
        }
        return minn;
    }
    else
    {
        for (int r=1;r<=n;r++)
        {

            i[r]=i[r]+b[r]+count*c[r];
        }
        bool f=1;
        for (int r=1;r<=n;r++)
        {
            if (i[r]<a[r])
            {
                f=0;
                break;
            }
        }
        if (f==1)
        {
            return count;
        }
        else{
            return  dfs(0,count+1,i,h);
        }
    }

}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >>  n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i]>> b[i] >> c[i];
    }
    for (int i=0;i<n-1;i++)
    {
        int x,y;
        cin >>  x  >> y;
        l[x].push_back(y);
        l[y].push_back(x);
    }
    cout << dfs(1,1,m,f);

    return 0;
}

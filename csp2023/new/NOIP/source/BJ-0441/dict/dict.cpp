#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,a[N][30];
int maxx[N],minn[N];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        minn[i]=27;
        for(int j=1;j<=m;j++)
        {
            char c;
            cin>>c;
            a[i][(int)(c-'a'+1)]++;
            maxx[i]=max(maxx[i],(int)(c-'a'+1));
            minn[i]=min(minn[i],(int)(c-'a'+1));
        }
    }
    for(int i=1;i<=n;i++)
    {
        int flg=1;
        for(int j=1;j<=n;j++)
        {
            if(j==i)
                continue;
            if(minn[i]<maxx[j])
                continue;
            else
            {
                flg=0;
                break;
            }
        }
        cout<<flg;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n,m,cnt[3010][30],num1[3010],num2[3010];
string s[3010];

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >> n >> m ;
    for(int i=1;i<=n;i++)
        cin >> s[i] ;
    if(n==1)
    {
        cout << 1 << endl ;
        return 0 ;
    }
    if(m==1)
    {
        int minn=(int)'z';
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if((int)s[i][0]<minn)
            {
                minn=(int)s[i][0];
                ans=i;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(i!=ans)
                cout << 0 ;
            else
                cout << 1 ;
        }
        return 0 ;
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++)
            cnt[i][(int)s[i][j]-'a'+1]++;
    //for(int i=1;i<=n;i++)
    //{
    //    for(int j=1;j<=26;j++)
    //        cout << cnt[i][j] << " " ;
    //    cout << endl ;
    //}
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=26;j++)
        {
            if(cnt[i][j]!=0)
            {
                num1[i]=j;
                break;
            }
        }
        for(int j=1;j<=26;j++)
            if(cnt[i][j]!=0)
                num2[i]=j;
    }
    for(int i=1;i<=n;i++)
    {
        int ans;
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            if(num2[j]>num1[i])ans=1;
            if(num2[j]<=num1[i])
            {
                ans=0;
                break;
            }
        }
        cout << ans ;
    }
    return 0 ;
}
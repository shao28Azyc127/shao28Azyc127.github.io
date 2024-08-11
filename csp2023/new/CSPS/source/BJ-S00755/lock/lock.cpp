#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[20][10],mp[100010],ans,pw[10];
vector<int> num;
signed main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin>>a[i][j];
    if(n==1) cout<<9*5+9*(5-1);
    else
    {
        pw[0]=1;
        pw[1]=10;
        for(int i=2;i<=6;i++) pw[i]=pw[i-1]*10;
        for(int i=1;i<=n;i++)
        {
            int s=0;
            for(int j=1;j<=5;j++)
                s=s*10+a[i][j];
            for(int j=1;j<=5;j++)
            {
                int tmp=s-a[i][j]*pw[5-j];
                for(int k=1;k<=9;k++)
                {
                    int x=tmp+((a[i][j]+k)%10)*pw[5-j];
                    num.push_back(x);
                    mp[x]++;
                    if(mp[x]==n) ans++;
                }
            }
            for(int j=1;j<5;j++)
            {
                int tmp=s-a[i][j]*pw[5-j]-a[i][j+1]*pw[5-j-1];
                for(int k=1;k<=9;k++)
                {
                    int x=tmp+((a[i][j]+k)%10)*pw[5-j]+((a[i][j+1]+k)%10)*pw[5-j-1];
                    num.push_back(x);
                    mp[x]++;
                    if(mp[x]==n) ans++;
                }
            }
        }
        //for(int i=0;i<num.size();i++) cout<<num[i]<<" ";
        //cout<<endl;
        cout<<ans;
    }
    return 0;
}
/*
2
2 8 3 5 5
2 8 3 5 1
*/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int flag[100005] = {}, x[7] = {};

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    for(int j = 1;j <= n;j++)
    {
        cin>>x[1]>>x[2]>>x[3]>>x[4]>>x[5];
        for(int i = 1;i <= 4;i++)
        {
            for(int k = 1;k<=10;k++)
            {
                x[i]-= k;
                x[i] = (x[i]+10)%10;
                flag[x[1]*10000+x[2]*1000+x[3]*100+x[4]*10+x[5]]++;
                x[i+1]-=k;
                x[i+1] = (x[i+1]+10)%10;
                flag[x[1]*10000+x[2]*1000+x[3]*100+x[4]*10+x[5]]++;
                x[i+1]+=k;
                x[i+1] = (x[i+1]+10)%10;
                x[i] += 2*k;
                x[i] = (x[i]+10)%10;
                flag[x[1]*10000+x[2]*1000+x[3]*100+x[4]*10+x[5]]++;
                x[i+1]+=k;
                x[i+1] = (x[i+1]+10)%10;
                flag[x[1]*10000+x[2]*1000+x[3]*100+x[4]*10+x[5]]++;
                x[i+1]-=k;
                x[i+1] = (x[i+1]+10)%10;
                x[i]-=k;
                x[i] = (x[i]+10)%10;
            }
        }
        for(int k = 1;k <=10;k++)
        {
            int i = 5;
            x[i] -= k;
            x[i] = (x[i]+10)%10;
            flag[x[1]*10000+x[2]*1000+x[3]*100+x[4]*10+x[5]]++;
            x[i] += 2*k;
            x[i] = (x[i]+10)%10;
            flag[x[1]*10000+x[2]*1000+x[3]*100+x[4]*10+x[5]]++;
            x[i]-=k;
            x[i] = (x[i]+10)%10;
        }
    }
    int ans = 0;
    for(int i = 1;i <= 99999;i++)
    {
        if(flag[i] == 2*n)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}

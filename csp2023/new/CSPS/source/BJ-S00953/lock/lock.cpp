// Let LRH bless me, I love LRH forever !!!

#include<bits/stdc++.h>
using namespace std;
map<vector<int>,int> mp;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        vector<int> now;
        for(int j=1;j<=5;j++)
        {
            int x;
            scanf("%d",&x);
            now.push_back(x);
        }
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<=9;k++)
            {
                int Gen=now[j];
                now[j]=k;
                mp[now]++;
                now[j]=Gen;
            }
        }

        for(int j=0;j<4;j++)
        {
            for(int k=0;k<=9;k++)
            {
                int Gen1=now[j],Gen2=now[j+1];
                now[j]=(now[j]+k)%10,now[j+1]=(now[j+1]+k)%10;
                mp[now]++;
                now[j]=Gen1,now[j+1]=Gen2;
            }
        }


    }

    int cnt=0;
    for(auto i:mp)
    {
        if(i.second==m) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}

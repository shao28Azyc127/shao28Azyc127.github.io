#include<bits/stdc++.h>
using namespace std;
string dict[4000];
struct ch{
    char a;
    long long num=0;
};
ch table[4000][30];
ch turbo[4000][30];
char t[4000][30];
int main()
{
    ios::sync_with_stdio(0);
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    long long n, m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    for(long long i=1;i<=n;i++)
    {
        cin>>dict[i];
    }
    for(long long i=1;i<=n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            table[i][dict[i][j]-'a'].num++;
            turbo[i][dict[i][j]-'a'].num++;
        }
    }
    for(long long i=0;i<26;i++)
    {
        long long cnt=99999999;
        for(long long j=1;j<=n;j++)
        {
            if(cnt>table[j][i].num)
            {
                cnt=table[j][i].num;
            }
        }
        for(long long j=1;j<=n;j++)
        {
            table[j][i].num=cnt;
        }
    }

    for(long long i=0;i<26;i++)
    {
        for(long long k=1;k<=table[1][i].num;k++)
        {
            for(long long j=1;j<=n;j++)
            {
                turbo[j][i].num--;
            }
        }
    }
    long long in[4000];
    for(long long i=1;i<=n;i++)
    {
        in[i]=0;
        for(long long j=0;j<26;j++)
        {
            if(turbo[i][j].num!=0)
            {
                t[i][in[i]]=j+'a';
                in[i]++;
            }
        }
    }
    for(long long i=1;i<=n;i++)
    {
        long long cnt=0;
        for(long long k=1;k<=n;k++)
        {
            bool flag=false;
            if(k==i) continue;
            for(long long j=0;j<in[i];j++)
            {
                for(long long z=0;z<in[k];z++)
                {
                    if(t[i][j]<t[k][z])
                    {
                        flag=true;
                        break;
                    }
                }
                if(flag)
                {
                    break;
                }
            }
            if(flag)
            {
                cnt++;
            }
        }
        if(cnt!=n-1)
        {
            cout<<0;
        }
        else{
            cout<<1;
        }
    }
    return 0;
}

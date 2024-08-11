#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 3005;

int n,m;
string s[N];
string smin[N],smax[N];
void sort(int num)
{
    for(int i = 0;i < m;++i)
        smin[num][i] = s[num][i];
    for(int i = 0;i < m;++i)
    {
        int tmp = i;
        while(1)
        {
            if(tmp == 0) break;
            if(smin[num][tmp]-'a' < smin[num][tmp-1]-'a')
            {
                char tmpchar = smin[num][tmp-1];
                smin[num][tmp-1] = smin[num][tmp];
                smin[num][tmp] = tmpchar;
                --tmp;
            }
            else if(smin[num][tmp]-'a' >= smin[num][tmp-1]-'a') break;
        }
    }
    for(int i = 0;i < m;++i)
        smax[num][i] = s[num][i];
    for(int i = 0;i < m;++i)
    {
        int tmp = i;
        while(1)
        {
            if(tmp == 0) break;
            if(smax[num][tmp]-'a' > smax[num][tmp-1]-'a')
            {
                char tmpchar = smin[num][tmp-1];
                smin[num][tmp-1] = smin[num][tmp];
                smin[num][tmp] = tmpchar;
                --tmp;
            }
            else if(smax[num][tmp]-'a' <= smax[num][tmp-1]-'a') break;
        }
    }
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;++i)
    {
        cin>>s[i];
        sort(i);
    }
    int fl;
    for(int i = 1;i <= n;++i)
    {
        fl = 1;
        for(int j = 1;j <= n;++j)
        {
            if(i == j) continue;
            if(fl == 0) break;
            for(int k = 0;k < m;++k)
            {
                if(smin[i][k]-'a' != smax[j][k]-'a')
                {
                    if(smin[i][k]-'a' < smax[j][k]-'a') break;
                    else {fl = 0;break;}
                }
            }
        }
        if(fl == 1) cout<<1;
        else cout<<0;
    }
    return 0;
}

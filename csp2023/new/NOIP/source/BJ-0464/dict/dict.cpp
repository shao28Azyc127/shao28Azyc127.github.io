#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<iomanip>
#include<cstdlib>

using namespace std;

typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mkp make_pair

int n,m;

string s[3010];
string smax[3010],smin[3010];

int box1[3010][27],box2[3010][27];

bool check(int j)
{
    for(int i = 1;i;i++)
    {
        if(i == j)i++;
        if(i > n)break;
        if(smax[i] < smin[j])
            return 0;
    }
    return 1;
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i];
        for(int j = 0;j < m;j++)
            box1[i][ s[i][j] - 'a' ]++,box2[i][ s[i][j] - 'a' ]++;
        for(int j = 0;j < m;j++)
        {
            int mx = 25,mi = 0;
            while(!box1[i][mx])mx--;
            while(!box2[i][mi])mi++;
            smax[i] += char(mx + 'a');
            smin[i] += char(mi + 'a');
            --box1[i][mx],--box2[i][mi];
        }
        // cout << smax[i] << ' ' << smin[i] << endl;
    }
    for(int i = 1;i <= n;i++)
    {
        if(check(i))
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define int long long
using namespace std;
int n,m;
string s[3010],s2[3010];
bool cmp(char a,char b)
{
    return a > b;
}
void rev(int x)
{
    for(int i = 0; i <= (s[x].size() - 1) / 2; i++)
    {
        swap(s[x][i],s[x][m - i - 1]);
    }
}
signed main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >> n >> m;//nmlogm,9e7,o2
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        sort(s[i].begin(),s[i].end());
        rev(i);
        s2[i] = s[i];
    }
    for(int i = 1; i <= n; i++)
    {
        rev(i);
        sort(s + 1,s + n + 1);
        rev(1);
        if(s2[i] == s[1]) cout << 1;
        else cout << 0;
        for(int j = 1; j <= n; j++)
        {
            s[j] = s2[j];
        }
        //print();
    }
    return 0;
}

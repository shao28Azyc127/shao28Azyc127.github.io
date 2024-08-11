#include <bits/stdc++.h>
using namespace std;
const int N= 1e4+10;
int n, ans;
char s[N];
bool is(string t)
{
    int len = t.size();
    char tmp[N]={};
    int l=0;
    for (int i=0;i<len;i++)
    {
        if (t[i]==t[i+1])
        {
            i+=1;
        }
        else
            tmp[l++] = t[i];
    }
    if (l<=0)
    {
        ans++;
       return true;
    }

    if (l>=len-1)
        return false;
    is(tmp);
}
int main (){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    for (int i=0;i<n-1;i++)
    {
        char tmp[N] = {};
        int l=0;
        for (int j=0;j<n-i;j++)
        {
            tmp[l++] = s[i+j];
            bool tr=is(tmp);
        }
    }
    cout << ans <<endl;
    return 0;
}

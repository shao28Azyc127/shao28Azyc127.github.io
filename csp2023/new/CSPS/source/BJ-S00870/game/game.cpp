#include <bits/stdc++.h>
using namespace std;

string s;
struct Node
{
    int l,r;
    int num;
};
Node tree[1000005];
int ans;
int n,m;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n >>  s;
    for(int i = 0;i < n-1;i++)
    {
        if(s[i] != s[i+1])continue;
        ans++;
        int t = 1;
        while(i-t >=0 && i+1+t < n)
        {
            if(s[i-t] == s[i+1+t]) ans++;
            t++;
        }
        t--;
        Node a;
        a.l = i-t;
        a.r = i+1+t;
        a.num = 1;
        bool situation = 0;
        for(int j = m;j > 0;j--)
        {
            Node b = tree[j];
            if(b.l <= a.l && a.r <= b.r)
            {
                situation = 1;
                break;
            }
            else if(a.l <= b.l && b.r <= a.r)
            {
                tree[j].l = 1;
                tree[j].r = tree[j].num = 0;
            }
        }
        if(situation) continue;
        bool situation2 = 0;
        for(int j = m;j > 0;j--)
            if(tree[j].r + 1 == a.l)
            {
                tree[j].r = a.r;
                ans += tree[j].num;
                tree[j].num++;
                situation2 = 1;
                break;
            }
        if(!situation)
        {
            m++;
            tree[m] = a;
        }
    }
    cout << ans << endl;


    return 0;
}
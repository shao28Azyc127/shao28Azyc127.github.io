#include<bits/stdc++.h>
using namespace std;
int n;
char s[2000005];
map<char,int> m;
int dp[2000005],tree[2000005],root[2000005];
int lowbit(int x)
{
    return x &= -x;
}
int find(int l,int r)
{
    int ans = 0;
    while(l<=r)
    {
        if(r - lowbit(r) + 1 < l)
        {
            if(root[r] == 0) r--;
            else return 0;
        }
        else
        {
            if(tree[r] == 0) r -= lowbit(r);
            else return 0;
        }
    }
    return 1;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        int flag = find(m[s[i]]+1,i-1);
        if(m[s[i]] == 0 || flag == 0)
        {
            int t = i;
            root[i] = 1;
            while(t <= n)
            {
                tree[t] += 1;
                t = t + lowbit(t);
            }
            m[s[i]] = i;
        }
        else
        {
            dp[i] = dp[m[s[i]]-1] + 1;
            if(root[m[s[i]]] != 0)
            {
                //cout<<m[s[i]]<<endl;
                root[m[s[i]]] = 0;
                int t = m[s[i]];
                while(t <= n)
                {
                    tree[t] -= 1;
                    t = t + lowbit(t);
                }
            }
            m[s[i]] = i;
        }
        /*
        for(int i=1;i<=n;i++)
        {
            cout<<tree[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<root[i]<<" ";
        }
        cout<<endl;
        */
    }
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        sum += dp[i];
        //cout<<dp[i]<<" ";
    }
    /*
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<root[i]<<" ";
    }*/
    cout<<sum;
    return 0;
}
/*8
a b b a c b b c
*/

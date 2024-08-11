#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,cnt;vector<int> a;bool vis[N];
int main()
{
    freopen("apple.in","r",stdin);freopen("apple.out","w",stdout);
    cin>>n;
    int tmpn=n;
    while(n!=0)
    {
        n-=ceil(n/3.0);
        cnt++;
    }
    cout<<cnt<<" ";
    if(n>1e3) cout<<1;
    else
    {
        for(int i=1;i<=tmpn;i++) a.push_back(i);
        for(int i=1;i<=cnt;i++)
        {
            int x=0;
            for(int j=0;j<tmpn;j++)
            {
                if(!vis[a[j]]) x++;
                if(x%3==1)
                {
                    vis[a[j]]=true;
                    if(a[j]==tmpn)
                    {
                        cout<<i;return 0;
                    }
                }
            }
        }
    }
    return 0;
}

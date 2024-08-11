#include <bits/stdc++.h>
using namespace std;
char a[5000010];
stack<char> st;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            for(int k=j;k<=j+i-1;k++)
            {
                if(st.top()==a[k]) st.pop();
                else st.push(a[k]);
            }
            if(st.size()==0) ans++;
            while(st.size()!=0) st.pop();
        }
    }
    cout<<ans;
    return 0
}
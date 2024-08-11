#include<bits/stdc++.h>
using namespace std;
char t[8005];
int cv(int l,int r)
{
    stack<char> st;
    for(int i=l;i<=r;i++)
    {
        if(st.empty())
        {
            st.push(t[i]);
        }
        else if(st.top()==t[i])
        {
            st.pop();
        }
        else
        {
            st.push(t[i]);
        }
    }
    return st.empty();
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int i,j,n,s=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",&t[i-1]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j+=2)
        {
            s+=cv(i,j);
        }
    }
    printf("%d",s);
    return 0;
}
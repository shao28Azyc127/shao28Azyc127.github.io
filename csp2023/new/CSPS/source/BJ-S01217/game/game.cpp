#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
char s[N];
stack<int> st;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)a[i]=s[i]-'a';
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        while(!st.empty())st.pop();
        for(int j=i;j<=n;j++)
        {
            if(st.empty())st.push(a[j]);
            else
            {
                if(st.top()==a[j])st.pop();
                else st.push(a[j]);
            }
            if(st.empty())ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

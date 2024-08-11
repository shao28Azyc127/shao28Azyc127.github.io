#include<bits/stdc++.h>
using namespace std;
const int N=2000001;
int n;
string s;
int p[N],q[N];
int cnt;
int cntp;
set<pair<int,int> > st;
void Check(int c)
{
    int k=0;
    while (s[c-k]==s[c+k+1])
    {
        p[++cnt]=c-k;
        q[cnt]=c+k+1;
        ++k;
    }
    return ;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>s;
    for (int i=0;i<s.size();++i)
    {
        if (s[i]==s[i+1])
        {
            Check(i);
        }
    }
    for (int i=1;i<=cnt;++i)
    {
        for (int j=i+1;j<=cnt;++j)
        {
            if (p[i]<p[j] && p[j]==q[i]+1)
            {
                st.insert(make_pair(p[i],q[j]));
            }
            if (p[i]>p[j] && p[i]==q[j]+1)
            {
                st.insert(make_pair(p[j],q[i]));
            }
        }
    }
    cout<<cnt+st.size();
    return 0;
}

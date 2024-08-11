#include<bits/stdc++.h>

using namespace std;

int n,ans;
string s;
int vis[30];
stack<char> st;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    for(int i=2;i<=n;i+=2)
    {
        for(int j=0;j<n-i+1;j++)
        {
            while(!st.empty())
                st.pop();
            bool flag=true;
            memset(vis,0,sizeof(vis));
            string ss=s.substr(j,i);

            for(int k=0;k<ss.size();k++)
            {
                vis[ss[k]-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                if(vis[i]%2!=0)
                {
                    flag=false;
                    break;
                }
            }
            if(flag==false)
                continue;

            for(int k=0;k<ss.size();k++)
            {
               if(st.empty())
               {
                   st.push(ss[k]);
                   continue;
               }
               char x=st.top();
               if(x==ss[k])st.pop();
               else st.push(ss[k]);
            }
            if(st.empty())
            {
                ans++;
                //cout<<ss<<endl;
                continue;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}

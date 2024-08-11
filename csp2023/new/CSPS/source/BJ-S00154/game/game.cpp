#include<bits/stdc++.h>
using namespace std;
string s;
stack<int> st;
int ans;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        while(!st.empty()) st.pop();
        st.push(s[i]);
        //cout<<s[i]<<' ';
        for(int j=i+1;j<n;j++)
        {
            //cout<<s[j]<<' ';
            if(!st.empty()&&s[j]==st.top())
            {
                st.pop();
            }
            else
            {
                st.push(s[j]);
            }
            if(st.empty())
            {
                //cout<<1<<' ';
                ans++;
            }
        }
        /*if(st.empty())
        {
            ans++;
        }*/
        //cout<<endl;
    }
    cout<<ans;
    return 0;
}

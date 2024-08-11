#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
using namespace std;
int dp[2000005]={};
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int l,c=0;
    string s;
    cin>>l>>s;
    for(int i=1;i<s.length();i++)
    {
        stack<char> st;
        int x;
        for(int j=i;j>=0;j--)
        {
            if(st.size()&&st.top()==s[j]) st.pop();
            else st.push(s[j]);
            if(st.empty())
            {
                dp[i]+=1+(j==0?0:dp[j-1]);
                c+=dp[i];
                break;
            }
        }
    }
    cout<<c;
    return 0;
}

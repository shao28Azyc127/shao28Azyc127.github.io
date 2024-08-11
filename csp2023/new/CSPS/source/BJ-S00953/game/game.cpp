// Let LRH bless me, I love LRH forever !!!

#include<bits/stdc++.h>
using namespace std;
int n;
string str;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    cin>>str;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        stack<int> st;
        st.push(i);
        for(int j=i+1;j<n;j++)
        {
            if(!st.empty() && str[j]==str[st.top()])
            {
                st.pop();
                if(st.empty()) cnt++;
            }else{
                st.push(j);
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}

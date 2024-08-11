//I'm a share bee, so what should I do?
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int n,ans;
char c[2000005];
stack<char> st;

void check(int l,int r)
{
    while(!st.empty()) st.pop();
    for(int i=l;i<=r;i++)
    {
        if(!st.empty() && st.top() == c[i]) st.pop();
        else st.push(c[i]);
    }
    if(st.empty()) ans++;
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> c[i];
    for(int len=2;len<=n;len+=2)
        for(int i=1;i+len-1<=n;i++)
        {
            int j = i+len-1;
            check(i,j);
        }
    cout << ans << endl;
    return 0;
}

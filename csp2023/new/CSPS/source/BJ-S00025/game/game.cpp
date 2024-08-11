#include <bits/stdc++.h>
#include <stack>
using namespace std;
int n;
char s[21000000];
stack<char> st;
int ans;
int main()
{
    st.push('*');
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    for (int i = 0;i <= n - 1;i++)
    {
        cin >> s[i];
        //cout << "1";
    }
    for(int i = n - 1;i >= 0;i--)
    {
        for (int j = 0;j <= i;j++)
        {
            for (int k = j;k <= i;k++)
            {
                if (s[k] == st.top())
                {
                    st.pop();
                }
                else st.push(s[k]);
            }
            if (st.top() == '*')
            {
                ans++;
                //cout << i +1 << " " << j + 1 <<endl;
            }
            else
            {
                while(!st.empty()) st.pop();
                st.push('*');
            }
        }
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

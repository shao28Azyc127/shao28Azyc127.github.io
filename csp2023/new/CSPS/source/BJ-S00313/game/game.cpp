#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
char ch;
int f[200005];
int lst[30];
stack<int> st[30];
void show_stack(stack<int> st)
{
    vector<int> tmp;
    while (!st.empty())
    {
        printf("%c ", st.top());
        tmp.push_back(st.top());
        st.pop();
    }
    for (int i = tmp.size() - 1; i >= 0; i--)
        st.push(tmp[i]);
    printf("\n");
}
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    memset(lst, 0x80, sizeof(lst));
    scanf("%d", &n);
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int cop_fr = -1, tmp;
        scanf("\n%c", &ch);
        if (st[ch - 'a'].empty() && lst[ch - 'a'] != 0x80808080)
        {
            f[i] = f[lst[ch - 'a'] - 1] + 1;
            cnt += f[i];

            cop_fr = lst[ch - 'a'] - 1;
        }
        for (int j = 0; j < 26; j++)
        {
            if (!st[j].empty() && st[j].top() == ch) st[j].pop();
            else st[j].push(ch);
        }
        tmp = lst[ch - 'a'];
        lst[ch - 'a'] = i;
        while (!st[ch - 'a'].empty())
            st[ch - 'a'].pop();
        //printf("%c: %d(last:%d)  fi = %d(copy:%d)  cnt = %d\n", ch, lst[ch - 'a'], tmp, f[i], cop_fr, cnt);
        //for (int i = 0; i < 26; i++) show_stack(st[i]);
    }
    printf("%d\n", cnt);
    return 0;
}

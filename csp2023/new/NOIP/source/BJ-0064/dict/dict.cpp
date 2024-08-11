#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int read()
{
    int n = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') n = n*10+(ch^48), ch = getchar();
    return n*f;
}
vector<string> s, s2;
char str[3005];
int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    int n = read(), m = read();
    if(n == 1) { printf("1\n"); return 0; }
    for(int i = 0; i < n; i++)
    {
        scanf("%s", str);
        sort(str, str+m, greater<char>());
        s.emplace_back(str);
    }
    s2 = s;
    sort(s.begin(), s.end());
    for(int i = 0; i < n; i++)
    {
        int flag = 0;
        if(s2[i] == s[0]) flag = 1;
        reverse(s2[i].begin(), s2[i].end());
        if(s2[i] < s[flag]) putchar('1');
        else putchar('0');
    }
    putchar('\n');
    return 0;
}
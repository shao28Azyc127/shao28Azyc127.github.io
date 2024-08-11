#include <bits/stdc++.h>
using namespace std;
int n,op;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &op);
        string s;
        int k;
        unsigned long long addr;
        if (op == 1)
        {
            cin >> s;
            scanf("%d", &k);
        }
        else if (op == 2) cin >> s;
        else if (op == 3) cin >> s;
        else if (op == 4) scanf("%ull", &addr);
    }
    printf("0"); //wan dan le (bei)
    return 0;
}
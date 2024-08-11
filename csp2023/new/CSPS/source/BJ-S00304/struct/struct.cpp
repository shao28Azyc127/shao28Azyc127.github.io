#include <bits/stdc++.h>
using namespace std;
map<string, int> type = {{"byte", 1}, {"short", 2}, {"int", 4}, {"long", 8}};
vector<pair<string, string>> things;
vector<int> addr;
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n, curaddr = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            string newtype;
            int members;
            cin >> newtype >> members;
        }
        else if (op == 2)
        {
            string curtype;
            string name;
            cin >> curtype >> name;
            things.emplace_back(pair<string, string>(curtype, name));
            int x = (curaddr + type[curtype] - 1) / type[curtype] * type[curtype];
            addr.emplace_back(x);
            curaddr = x + type[curtype];
        }
        else if (op == 3)
        {
            string name;
            cin >> name;
            for (int i = 0; i < things.size(); i++)
            {
                if (things[i].second == name)
                {
                    printf("%d\n", addr[i]);
                    break;
                }
            }
        }
        else if (op == 4)
        {
            int inaddr;
            bool flag = false;
            scanf("%d", &inaddr);
            for (int i = 0; i < addr.size(); i++)
            {
                if (addr[i] <= inaddr && inaddr <= addr[i] + type[things[i].first] - 1)
                {
                    cout << things[i].second << "\n";
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                printf("ERR\n");
            }
        }
    }
    return 0;
}

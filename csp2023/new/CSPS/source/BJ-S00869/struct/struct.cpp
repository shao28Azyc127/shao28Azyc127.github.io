#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
map<string, ull> varmap;
map<string, int> lengthmap;
ull idex;
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    lengthmap["byte"] = 1;
    lengthmap["short"] = 2;
    lengthmap["int"] = 4;
    lengthmap["long"] = 8;

    int n;
    scanf("%d", &n);
    while(n--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1) return 0;
        switch(op)
        {
            case 2: {
                string t,n;
                cin>>t>>n;
                if (idex % lengthmap[t] != 0) idex = idex - (idex % lengthmap[t]) + lengthmap[t];
                varmap[n] = idex;
                idex += lengthmap[t];
                break;
            }
            case 3: {
                string n;
                cin>>n;
                printf("%llu\n", varmap[n]);
            }
            default: {return 0;}
        }
    }
    return 0;
}
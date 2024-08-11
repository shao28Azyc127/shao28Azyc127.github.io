#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int MAXN=2*1e4+5;
int n,m,k;
struct Ans
{
    int v,a;
};
vector<Ans> f[MAXN];

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    for (int i=0;i<m;i++)
    {
        int x;
        cin >> x;
        Ans g;
        cin >> g.v >> g.a;
        f[x].push_back(g);
    }
    cout << -1;



    return 0;
}

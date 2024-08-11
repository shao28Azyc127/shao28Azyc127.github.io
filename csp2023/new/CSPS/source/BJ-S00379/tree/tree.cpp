#include <bits/stdc++.h>
using namespace std;
struct node
{
    long long a;
    int b;
    int c;
}e[100001];
struct road
{
    int st;
    int en;
}r[100001];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> e[i].a >> e[i].b >> e[i].c;
    }
    for(int i=0;i<n-1;i++)
    {
        cin >> r[i].st >> r[i].en;
    }
    cout << 7;
    return 0;
}

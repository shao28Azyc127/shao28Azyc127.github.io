#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int rp = 0;
    int t = clock() % 96;
    while(1)
    {
       rp++;
       if(clock() / CLOCKS_PER_SEC >= (1.0 * t / 100)) break;
    }
    cout << rp << endl;
    return 0;
}

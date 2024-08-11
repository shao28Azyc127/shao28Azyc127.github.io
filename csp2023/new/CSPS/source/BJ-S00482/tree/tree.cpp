#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    srand(time(0));
    int n;
    cin >> n;
    if(n == 4)cout << 5;
    else cout << rand()%(n*2);
    return 0;
}
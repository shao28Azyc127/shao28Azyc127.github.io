#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in", "r",stdin);
    freopen("uqe.out", "w", stdout);
    int a,b,c;
    cin >>a >>b >>c;
    int n = b*b - 4*a*c;
    if(n < 0)
    {
        cout << "NO";
        return 0;
    }
    cout << n;
    return 0;
}

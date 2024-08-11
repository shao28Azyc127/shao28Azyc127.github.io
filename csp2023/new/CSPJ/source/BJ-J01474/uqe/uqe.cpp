#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("uqe.in" , "r" , stdin);
    freopen("uqe.out" , "w" , stdout);
    int M , T;
    cin >> T >> M;
    while(T--)
    {
        int a , b , c;
        cin >> a >> b >> c;
        int derta = b * b - 4 * a * c;
        if(derta < 0)
            cout << "NO" << endl;
        else
        {
                cout << 1 << endl;
        }
    }
    return 0;
}
//a?????????
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 1)
        for (int i = 0; i < d; i++)
            cout << 1 << endl;
    else
        cout << 0 << endl;
}

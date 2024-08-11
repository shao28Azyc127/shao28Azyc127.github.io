#include <iostream>

int n, Mis;
int ds, dt; //days, date;

using namespace std;

int main(void)
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;

    int l = n;
    while(l > 0)
    {
        Mis = l / 3;
        if(l % 3 != 0) Mis++;
        l -= Mis;
        ds++;
    }

    if(n % 3 == 0) dt = 2;
    if(n % 3 == 1) dt = 1;
    if(n % 3 == 2) dt = ds;
    cout << ds << " " << dt;
    return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int temp = n;
    int days = 0;
    while (temp > 0)
    {
        days++;
        temp -= (temp - 1) / 3 + 1;
    }
    cout << days << " ";
    int x = n, ans = 1; //x stands for number
    while (x % 3 != 1)
    {
        ans++;
        x -= (x - 1) / 3 + 1;
    }
    cout << ans << endl;
    return 0;
}

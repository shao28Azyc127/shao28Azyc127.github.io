#include <iostream>
using namespace std;

int d[100005], y[100005];

int main()
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> d[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> y[i];
    }
    int money = 0, y = 0;
    for (int i = 1; i <= n; ++i)
    {
        int distance = 0;
        for (int j = i + 1; j <= n; ++i)
        {
            distance += d[j - 1];
            if (y[j] < y[i])
            {
                i = j;
                if (distance % d == 0)
                {
                    money += (distance / d - y) * y[i];
                    y = (distance / d) % d;
                }
                else
                {
                    money += (distance / d + 1 - y) * y[i];
                    y = (distance / d + 1) % d;
                }
            }
        }
    }
    cout << money << endl;
    return 0;
}
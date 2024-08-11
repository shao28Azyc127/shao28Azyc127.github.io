#include <iostream>

using namespace std;
int n, d, a[100005], b[100005], price, sum, least, now;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i <= n - 1; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    if(sum % d == 0)
    {
        least = sum / d;
    }
    else
    {
        least = sum / d + 1;
    }
    cout << b[1] * least << endl;

    return 0;
}

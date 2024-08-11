#include <iostream>
using namespace std;

int v[200005], pr[200005];
int s[200005]{0};

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.ans", "w", stdout);
    int n, d;
    cin >> n >> d;
    int sum = 0, bc = 0;
    int mubd = 1, chace = 0;
    for(int i = 1; i <= n - 1; i++)
    {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> pr[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(pr[mubd] <= pr[i])
        {
            chace++;
        }
        if(pr[mubd] > pr[i] || i == n)
        {
            sum += ((s[i - 1] - s[mubd - 1] - bc - 1) / d + 1) * pr[mubd];
            bc = (s[i - 1] - s[mubd - 1] - bc) % d;
            mubd = i;
            chace = 1;
        }
    }
    cout << sum << endl;
    return 0;
}

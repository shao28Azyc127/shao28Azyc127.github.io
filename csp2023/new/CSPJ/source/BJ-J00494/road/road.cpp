#include <iostream>
#include <cstdio>
using namespace std;


const int MAX = 100005;

int V[MAX], A[MAX];


int Ceil(double x)
{
    int res = (int)x;
    if(x - (int)x > 0) res++;

    return res;
}


int F(double x)
{
    return x - (int)x;
}


int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);


    int n, d;
    cin >> n >> d;
    for(int i = 1; i <= n - 1; ++i)
        cin >> V[i];
    for(int i = 1; i <= n; ++i)
        cin >> A[i];


    int MinCost = MAX;
    int ans = 0;
    double left = 0;
    for(int i = 1; i <= n - 1; ++i)
    {
        if(A[i] < MinCost) MinCost = A[i];

        double need = (double)V[i] / d - left;
        ans += Ceil(need) * MinCost;
        left = Ceil(need) - need;
    }
    cout << ans << endl;


    return 0;
}

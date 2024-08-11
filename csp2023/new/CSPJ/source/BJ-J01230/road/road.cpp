#include <fstream>
using namespace std;

int v[10001];
int a[10001];

int main()
{
    ifstream fin("road.in");
    ofstream fout("road.out");

    int n, d;
    fin >> n >> d;
    for (int i = 0; i < n - 1; i++)
    {
        fin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        fin >> a[i];
    }

    long long sta = 0, power = 0;
    long long ans = 0;
    while (sta < n - 1)
    {
        long long dis = 0;
        for (int i = sta + 1; i < n; i++)
        {
            dis += v[i - 1];
            if (a[i] < a[sta] || i == n - 1)
            {
                if (i == n - 1)
                {
                    dis += v[n - 1];
                }
                int npower = dis - power;
                int nofo = npower / d + (npower % d == 0 ? 0 : 1);
                ans += nofo * a[sta];
                power = nofo * d - npower;
                sta = i;
                break;
            }
        }
    }

    fout << ans << endl;
}
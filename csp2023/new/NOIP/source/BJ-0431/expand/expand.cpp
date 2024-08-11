#include <fstream>
using namespace std;

ifstream fin("expand.in");
ofstream fout("expand.out");

int x[1001];
int y[1001];

int xx[1001];
int yy[1001];

int main()
{
    int c, n, m, q;
    fin >> c >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        fin >> x[i];
    }
    for (int i = 1; i <= m; i++)
    {
        fin >> y[i];
    }

    if (c == 1)
    {
        fout << (x[1] != y[1]);
        while (q--)
        {
            for (int i = 1; i <= n; i++)
            {
                xx[i] = x[i];
            }
            for (int i = 1; i <= m; i++)
            {
                yy[i] = y[i];
            }

            int kx, ky;
            fin >> kx >> ky;
            while (kx--)
            {
                int p, v;
                fin >> p >> v;
                xx[p] = v;
            }
            while (ky--)
            {
                int p, v;
                fin >> p >> v;
                yy[p] = v;
            }
            fout << (xx[1] != y[1]);
        }
    }

    if (c == 2)
    {
        fout << ((x[1] < y[1]) && (x[2] < y[2]));
        while (q--)
        {
            for (int i = 1; i <= n; i++)
            {
                xx[i] = x[i];
            }
            for (int i = 1; i <= m; i++)
            {
                yy[i] = y[i];
            }

            int kx, ky;
            fin >> kx >> ky;
            while (kx--)
            {
                int p, v;
                fin >> p >> v;
                xx[p] = v;
            }
            while (ky--)
            {
                int p, v;
                fin >> p >> v;
                yy[p] = v;
            }
            fout << ((x[1] < y[1]) && (x[2] < y[2]));
        }
    }
}
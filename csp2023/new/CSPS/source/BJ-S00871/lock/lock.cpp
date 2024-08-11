#include <fstream>
using namespace std;

int lock[10][5];
int riht[5];

bool check(int l)
{
    int d1 = -1, d2 = -1, dn = 0;
    for (int i = 0; i < 5; i++)
    {
        if (lock[l][i] != riht[i])
        {
            if (d1 == -1)
            {
                d1 = i;
            }
            else if (d2 == -1)
            {
                d2 = i;
            }
            dn++;
        }
    }

    if (dn >= 3 || dn == 0)
    {
        return false;
    }

    if (dn == 1)
    {
        return true;
    }
    else
    {
        if ((lock[l][d1] - riht[d1] + 10) % 10 == (lock[l][d2] - riht[d2] + 10) % 10 && d2 - d1 == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    ifstream fin("lock.in");
    ofstream fout("lock.out");

    int n;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            fin >> lock[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        riht[i] = lock[0][i];
    }

    if (n == 1)
    {
        fout << 81 << endl;
    }
    else
    {
        int ans = 0;
        for (int set = 0; set < 5; set++)
        {
            for (int num = 0; num <= 9; num++)
            {
                if (lock[0][set] == num)
                {
                    continue;
                }
                riht[set] = num;
                bool yes = true;
                for (int i = 1; i < n; i++)
                {
                    if (!check(i))
                    {
                        yes = false;
                        break;
                    }
                }
                if (yes)
                {
                    ans++;
                }
            }
            riht[set] = lock[0][set];
        }

        for (int set = 0; set < 4; set++)
        {
            for (int add = 1; add <= 9; add++)
            {
                riht[set] = (riht[set] + add) % 10;
                riht[set + 1] = (riht[set + 1] + add) % 10;

                bool yes = true;
                for (int i = 1; i < n; i++)
                {
                    if (!check(i))
                    {
                        yes = false;
                        break;
                    }
                }
                if (yes)
                {
                    ans++;
                }

                riht[set] = lock[0][set];
                riht[set + 1] = lock[0][set + 1];
            }
        }
        fout << ans << endl;
    }
}
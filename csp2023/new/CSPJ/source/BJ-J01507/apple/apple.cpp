#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple2.in", "r", stdin);
    freopen("apple2.out", "w", stdout);
    long long n;
    cin >> n;
    long long day = 0;
    long long day1;
    for (long long i = 1; i <= n; i++)
    {
        if(b[i] == 0)
        {
            for (int j = i; j <= n; j+= 3)
            {
                if(b[j] == 0)
                {
                    b[j] = 1;
                }

            }
        }
        else
        {
            day++;
        }
        if(b[n] == 1)
        {
            day1 = day;
        }
    }
    cout << day  << " " << day1 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

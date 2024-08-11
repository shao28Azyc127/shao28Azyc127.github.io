#include <fstream>
using namespace std;

int main()
{
    ifstream fin("apple.in");
    ofstream fout("apple.out");

    int n;
    fin >> n;

    int m = n;
    int ans1 = 0;
    int ans2 = -1;

    while (m != 1)
    {
        if (m % 3 == 1 && ans2 == -1)
        {
            ans2 = ans1;
        }

        if (m % 3 == 0)
        {
            m /= 3;
            m *= 2;
        }
        else if (m % 3 == 1)
        {
            m--;
            m /= 3;
            m *= 2;
        }
        else
        {
            m -= 2;
            m /= 3;
            m *= 2;
            m++;
        }
        ans1++;
    }
    if (ans2 == -1)
    {
        ans2 = ans1;
    }

    fout << ans1 + 1 << ' ' << ans2 + 1 << endl;
}
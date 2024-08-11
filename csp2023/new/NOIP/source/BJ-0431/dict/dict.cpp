#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

ifstream fin("dict.in");
ofstream fout("dict.out");

char dict[3001][3001];

int main()
{
    int n, m;
    fin >> n >> m;

    string mins = "";
    int s = -1, cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        mins += "z";
    }

    for (int i = 0; i < n; i++)
    {
        fin >> dict[i];
        if (dict[i] < mins)
        {
            cnt = 0;
            s = i;
            mins = dict[i];
        }
        if (dict[i] == mins)
        {
            cnt++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        sort(dict[i], dict[i] + m);
        if (dict[i] < mins)
        {
            fout << 1;
        }
        else if (cnt == 1 && s == i)
        {
            fout << 1;
        }
        else
        {
            fout << 0;
        }
    }
    return 0;
}
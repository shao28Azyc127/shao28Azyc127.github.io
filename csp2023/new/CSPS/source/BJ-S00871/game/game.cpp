#include <fstream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

ifstream fin("game.in");
ofstream fout("game.out");

char str[2000001];
vector<int> ennd[20001];
int n;

int bfs(int l, int r)
{
    int ans = 0;

    queue<int> ql;
    queue<int> qr;
    ql.push(l);
    qr.push(r);

    while (!ql.empty())
    {
        int nl = ql.front();
        int nr = qr.front();
        ql.pop();
        qr.pop();

        bool has = false;
        for (int i = 0; i < ennd[nr].size(); i++)
        {
            if (ennd[nr][i] == nl)
            {
                has = true;
                break;
            }
        }
        if (has)
        {
            continue;
        }
        
        ans++;
        ennd[nr].push_back(nl);

        if (nl > 0 && nr < n - 1 && str[nl - 1] == str[nr + 1])
        {
            ql.push(nl - 1);
            qr.push(nr + 1);
        }

        if (nl > 0)
        {
            for (int i = 0; i < ennd[nl - 1].size(); i++)
            {
                ql.push(ennd[nl - 1][i]);
                qr.push(nr);
            }
        }
    }
    return ans;
}

int main()
{

    int ans = 0;

    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> str[i];
    }

    for (int i = 1; i < n; i++)
    {
        if (str[i] == str[i - 1])
        {
            ans += bfs(i - 1, i);
        }
    }

    fout << ans << endl;
}
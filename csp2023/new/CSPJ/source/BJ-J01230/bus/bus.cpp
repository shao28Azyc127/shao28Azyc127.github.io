#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
    int to, open;
    Edge(int v, int a)
    {
        to = v;
        open = a;
    }
};

vector<Edge> e[10001];
int n, k;

int bfs()
{
    queue<int> q;
    queue<int> t;
    q.push(1);
    t.push(0);

    while (!q.empty())
    {
        int now = q.front();
        int nt = t.front();
        q.pop();
        t.pop();

        if (now == n && nt % k == 0)
        {
            return nt;
        }
        for (int i = 0; i < e[now].size(); i++)
        {
            q.push(e[now][i].to);
            t.push(nt + 1);
        }
    }
    return -1;
}

int main()
{
    ifstream fin("bus.in");
    ofstream fout("bus.out");

    int m;
    bool spe = true;
    fin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int u, v, a;
        fin >> u >> v >> a;
        if (a != 0)
        {
            spe = false;
        }
        e[u].push_back(Edge(v, a));
    }

    if (spe)
    {
        fout << bfs() << endl;
    }
    else
    {
        fout << -1 << endl;
    }
    return 0;
}
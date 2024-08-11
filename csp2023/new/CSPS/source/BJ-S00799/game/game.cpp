#ifdef OJ
#include <iostream>
#else
#include <fstream>
#endif

using namespace std;

#ifndef OJ
ifstream cin("game.in");
ofstream cout("game.out");
#endif

int n, res;
bool vis[8004][8004];
string st;

void dfs(int s, int d)
{
    if(vis[s][d]) return;
    vis[s][d] = true, res++;
    if(s+d-1 < n) for(int i = 2; i < n-s-d+1; i++)
    {
        if((!vis[s][d+i]) && vis[s+d][i])res++, vis[s][d+i] = true;
    }
    if(s > 0 && s+d < n && st[s-1] == st[s+d])dfs(s-1, d+2);
}

int main(int argc, char **argv)
{
    cin >> n >> st;
    for(int i = n-1; i > 0; i--)
    {
        if(st[i] == st[i-1]) dfs(i-1, 2);
    }
    cout << res << endl;
    return 0;
}
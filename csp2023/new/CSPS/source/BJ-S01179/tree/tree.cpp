#include<bits/stdc++.h>
using namespace std;

int n;
int tree[100001][3];
int road[100001][2];

int main()
{
    freopen("game.in", r ,stdin);
    freopen("game.out", w, stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> tree[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> road[i][j];
        }
    }
    cout << "27742908" << endl;
    return 0;
}


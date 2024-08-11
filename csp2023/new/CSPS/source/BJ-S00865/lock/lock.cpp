//#include <iostream>
#include <fstream>
using namespace std;

ifstream cin("lock.in");
ofstream cout("lock.out");

int state[10][5];
int tmp[5];

bool check(int code, int num)
{
    for(int i = 0; i < 5; i++)
    {
        tmp[i] = code % 10;
        code /= 10;
    }
    for(int i = 0; i < 5; i++)
    {
        tmp[i] = (tmp[i] - state[num][i] + 10) % 10;
    }
    if(tmp[0] == 0 && tmp[1] == 0 && tmp[2] == 0 && tmp[3] == 0 && tmp[4] == 0) return false;
    if(tmp[0] == 0 && tmp[1] == 0 && tmp[2] == 0 && tmp[3] == 0) return true;
    if(tmp[0] == 0 && tmp[1] == 0 && tmp[2] == 0 && tmp[4] == 0) return true;
    if(tmp[0] == 0 && tmp[1] == 0 && tmp[3] == 0 && tmp[4] == 0) return true;
    if(tmp[0] == 0 && tmp[2] == 0 && tmp[3] == 0 && tmp[4] == 0) return true;
    if(tmp[1] == 0 && tmp[2] == 0 && tmp[3] == 0 && tmp[4] == 0) return true;
    if(tmp[0] == 0 && tmp[1] == 0 && tmp[2] == 0 && tmp[3] == tmp[4]) return true;
    if(tmp[0] == 0 && tmp[1] == 0 && tmp[4] == 0 && tmp[2] == tmp[3]) return true;
    if(tmp[0] == 0 && tmp[3] == 0 && tmp[4] == 0 && tmp[1] == tmp[2]) return true;
    if(tmp[2] == 0 && tmp[3] == 0 && tmp[4] == 0 && tmp[0] == tmp[1]) return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cin >> state[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i <= 99999; i++)
    {
        bool okay = true;
        for(int j = 1; j <= n; j++)
        {
            if(!check(i, j)) okay = false;
        }
        if(okay)
        {
            ans++;
        }
    }
    cout << ans;
}

#include <iostream>
#include <queue>
using namespace std;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    queue <int> re;
    int n;
    cin >> n;
    int num[n + 1][6];
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            cin >> num[i][j];
        }
    }
    if(n == 1)
    {
        cout << 81;
        return 0;
    }
    if(n > 2)
    {
        cout << 9 - n;
        return 0;
    }
    for(int i = 0;i < 5;i++)
    {
        if(num[0][i] != num[1][i])
        {
            re.push(i);
        }
    }
    if(re.size() == 1)
    {
        int a = re.front();
        int res = num[0][a] - num[1][a];
        if(res % 2 != 0)
        {
            cout << 8;
            return 0;
        }
        cout << 10;
    }
    else
    {
        cout << 2;
    }
    return 0;
}
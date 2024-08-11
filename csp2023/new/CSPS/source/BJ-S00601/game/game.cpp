#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;
string a,c;
int b[2000010];
struct iNode
{
    char bb;
    int pp;
};
bool pd(int s,int e)
{
    for(int i = s; i <= e; i++)
    {
        c += a[i];
    }
    int len = e - s + 1;
    bool f = 0;
    while(c.size() != 0)
    {
        for(int i = 0; i < c.size() - 1; i++)
        {
            if(c.size() == 0) break;
            if(c[i] == c[i + 1])
            {
                c.erase(i,2);
                f = 1;
                i--;

            }
        }
        if(!f) return 0;
        f = 0;
    }
    return 1;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin >> n;
    cin >> a;
    int cnt = 0;
    for(int i = 2; i <= n; i += 2)
    {
        for(int j = 0; j < n - i + 1; j++)
        {
            if(pd(j,j + i - 1)) cnt++;
            c = "";
        }
    }
    cout << cnt;
    return 0;
}

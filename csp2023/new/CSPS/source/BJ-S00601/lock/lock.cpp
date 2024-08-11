#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int a[10][10],b[10],c[10];
map<int,int> mp;
int tonum()
{
    return b[1] * 10000 + b[2] * 1000 + b[3] *100 + b[4] * 10 + b[5];
}
void mj(int t)
{
    for(int i = 1; i <= 5; i++)
    {
        b[1] = a[t][1];
        b[2] = a[t][2];
        b[3] = a[t][3];
        b[4] = a[t][4];
        b[5] = a[t][5];
        for(int j = 0; j <= 9; j++)
        {
            if(b[i] == j) continue;
            int t = b[i];
            b[i] = j;
            mp[tonum()]++;
            //cerr << tonum() << endl;
            b[i] = t;
        }
    }
    for(int i = 1; i < 5; i++)
    {
        b[1] = a[t][1];
        b[2] = a[t][2];
        b[3] = a[t][3];
        b[4] = a[t][4];
        b[5] = a[t][5];
        for(int j = 1; j <= 9; j++)
        {
            int t1 = b[i],t2 = b[i + 1];
            b[i] = (b[i] + j) % 10;
            b[i + 1] = (b[i + 1] + j) % 10;
            mp[tonum()]++;
            //cerr << tonum() << endl;
            b[i] = t1;
            b[i + 1] = t2;
        }
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin  >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        mj(i);
    }
    int cnt = 0;
    for(int i = 0; i <= 99999; i++)
    {
        if(mp[i] >= n) cnt++;

    }
    cout << cnt;
    return 0;
}

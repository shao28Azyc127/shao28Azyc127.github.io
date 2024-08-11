#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[10][10];
int f[100000];

int num(int n,int x,int y)
{
    int d[10];
    for(int i = 1; i <= 5; i++)
        d[i] = a[n][i];
    d[x] = y;
    return d[1] * 10000 + d[2] * 1000 + d[3] * 100 + d[4] * 10 + d[5];
}

bool check2(int n,int x)
{
    for(int i = 1; i <= n; i++)
    {
        if(num(i,0,0) == x) return true;
    }
    return false;
}

bool check1(int x,int i)
{
    int a1 = x % 10;
    int b1 = x / 10 % 10;
    int c1 = x / 100 % 10;
    int d1 = x / 1000 % 10;
    int e1 = x / 10000 % 10;
    int a2 = i % 10;
    int b2 = i / 10 % 10;
    int c2 = i / 100 % 10;
    int d2 = i / 1000 % 10;
    int e2 = i / 10000 % 10;
    if(a1 != a2 && b1 == b2 && c1 == c2 && d1 == d2 && e1 == e2) return true;
    if(a1 == a2 && b1 != b2 && c1 == c2 && d1 == d2 && e1 == e2) return true;
    if(a1 == a2 && b1 == b2 && c1 != c2 && d1 == d2 && e1 == e2) return true;
    if(a1 == a2 && b1 == b2 && c1 == c2 && d1 != d2 && e1 == e2) return true;
    if(a1 == a2 && b1 == b2 && c1 == c2 && d1 == d2 && e1 != e2) return true;

    if(a1 != a2 && b1 != b2 && c1 == c2 && d1 == d2 && e1 == e2 && (a1 + 10 - a2) % 10 == (b1 + 10 - b2) % 10) return true;
    if(a1 == a2 && b1 != b2 && c1 != c2 && d1 == d2 && e1 == e2 && (b1 + 10 - b2) % 10 == (c1 + 10 - c2) % 10) return true;
    if(a1 == a2 && b1 == b2 && c1 != c2 && d1 != d2 && e1 == e2 && (c1 + 10 - c2) % 10 == (d1 + 10 - d2) % 10) return true;
    if(a1 == a2 && b1 == b2 && c1 == c2 && d1 != d2 && e1 != e2 && (d1 + 10 - d2) % 10 == (e1 + 10 - e2) % 10) return true;

    return false;
}

bool check(int x,int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(check1(x,num(i,0,0)) == false) return false;
    }
    return true;
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int cnt = 0;
    for(int i = 0; i <= 99999; i++)
    {
        if(check2(n,i)) continue;
        if(check(i,n)) cnt++;
    }
    cout << cnt;
    return 0;
}

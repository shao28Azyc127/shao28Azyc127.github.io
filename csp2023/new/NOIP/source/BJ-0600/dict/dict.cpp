#include <bits/stdc++.h>
using namespace std;
const int N=3010;
string s[N];
int n, st[N][N], k, st2[N][N], st1[N][N];
int cmp(int a, int b)
{
    return a>b;
}
bool smaller(int a[], int b[])
{
    for (int i=1;i<=k;i++)
    {
        if(a[i]>b[i])
            return 0;
        if (a[i]<b[i])
            return 1;
    }
    return 0;
}
void out()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=k;j++)
        {
            cout<< st[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
int main ()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> k;
    if (n==1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        cin >>s[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<k;j++)
        {
            st[i][j+1] = s[i][j]-'a';
            st1[i][j+1] = s[i][j]-'a';
            st2[i][j+1] = s[i][j]-'a';
        }
    }
    for (int i=1;i<=n;i++)
    {
        sort(st2[i]+1, st2[i]+k+1, cmp);
        sort(st1[i]+1, st1[i]+k+1);
    }
    for (int i=1;i<=n;i++)
    {
        bool flag = 0;
        for (int j=1;j<=n;j++)
        {
            if (i==j)
                    continue;
            if (!smaller(st1[i], st2[j]))
                flag++;
        }
        if (!flag)
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
    return 0;
}

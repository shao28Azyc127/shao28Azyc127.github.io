#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;

const int maxN = 100000010;
int n, a[maxN];

int main()
{
    memset(a, -1, sizeof(a));
    ios::sync_with_stdio(false);
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;/*
    for(int i = 1; i <= n; i++)
        if((i + 2) % 3 == 0)
            a[i] = 1;*/
    int cnt = 1;
    int ansr = 1;
    while(1)
    {
        bool done = false;
        int k = 1;
        for(int i = 1; i <= n; i++)
        {
            if (a[i] != -1) continue;
            if(k == 4) k = 1;
            if(k == 1) a[i] = cnt;
            k++;
            done = true;
        }
        if(!done) break;
        ansr = max(ansr, cnt);
        cnt++;
    }
    cout << ansr << " " << a[n] << endl;
    return 0;
}

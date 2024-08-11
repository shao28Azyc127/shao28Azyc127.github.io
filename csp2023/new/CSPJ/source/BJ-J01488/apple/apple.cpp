#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <list>
using namespace std;

int main()
{
        freopen("apple.in", "r", stdin);
        freopen("apple.out", "w", stdout);
        long long n, daynum = 1, eatn;
        cin >> n;
        bool apple[1000000010];
        for(int i = 0;i < n;i++)
        {
                apple[i] = 1;
        }
        for(int i = n;i > 0;daynum++)
        {
                int applec = 0, eata;
                for(int j = 0;j < n;j++, applec = (applec + 1) % 3)
                {
                        if(apple[i] && !applec)
                        {
                                eata++;
                                if(j == n)
                                {
                                        eatn = daynum;
                                }
                        }
                }
                i = i - eata;
        }
        printf("%lld %lld",daynum, eatn);
        return 0;
}

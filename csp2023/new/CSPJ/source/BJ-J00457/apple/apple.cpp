#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int n;
inline int calc1(int x)
{
    if(x==0)
        return 0;
    x-=(x+2)/3;
    return calc1(x)+1;
}
inline int calc2(int x)
{
    if(x==0)
        return 0;
    if(x%3==1)
        return 1;
    x-=(x+2)/3;
    return calc2(x)+1;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    cout << calc1(n) << ' ' << calc2(n) << endl;
    return 0;
}

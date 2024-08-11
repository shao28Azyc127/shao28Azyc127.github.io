#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout)
    int n;
    cin >> n;
    int cnt=0,j=0;
    while(n>0)
    {
        cnt++;
        int x=(n+2)/3;
        if(n%3==1&&j==0)    j=cnt;
        n-=x;
    }
    cout << cnt << " " << j << endl;
    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    int n1=n;
    int c=0;
    int cs=0;
    while(n1)
    {
        c++;
        if(n1%3==1 && cs==0) cs=c;
        n1-=(n1+2)/3;
    }
    cout << c << ' ' << cs << endl;
    return 0;
}
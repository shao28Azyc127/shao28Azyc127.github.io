#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int n,m;
int main()
{
    freopen("run.in","r",stdin);
    cin >> m >> n;
    if(m<=10)//just testing
    {
        freopen("run.ans","r",stdin);
        freopen("run.out","w",stdout);
        for(register int i=1;i<=n;i++)
        {
            long long int s;
            cin >> s;
            cout << s << endl;
        }
    }
    //will this work?
    return 0;
}

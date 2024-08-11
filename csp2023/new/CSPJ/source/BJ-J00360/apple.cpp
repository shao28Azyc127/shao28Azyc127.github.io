#include <bits/stdc++.h>
using namespace std;
int n,day,ntime;
int main()
{
    freopen(stdin,"w",apple.in);
    freopen(stdout,"r",apple.out);
    cin>>n;
    while(n>=0)
    {
        day++;
        if(n%3==1)
        {
            ntime=day;
            n=2*(n/3);
        }
        else if(n%3==2) n=2*(n/3)+1;
        else n=2*(n/3);
    }
    cout<<day<<" "<<ntime;
    return 0;
}

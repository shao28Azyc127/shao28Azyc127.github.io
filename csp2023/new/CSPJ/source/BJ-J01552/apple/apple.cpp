#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=0,d;
    bool i=true;
    cin>>n;
    while(n)
    {
        cnt++;
        if(n%3==1&&i)
        {
            d=cnt;
            i=false;
        }
        if(n%3==0)
            n-=n/3;
        else
            n-=n/3+1;
    }
    cout<<cnt<<' '<<d;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
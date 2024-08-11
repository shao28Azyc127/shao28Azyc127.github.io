#include<bits/stdc++.h>
using namespace std;
int n,d=0,b,x,flag=0;
int main()
{
    freopen("apple.in","r",stdin);
    cin>>n;
    x=n;
    while(x>0)
    {
        d++;
        for(int i=1;i<=n;i+=3)
        {
            x--;
            if(n%3==1&&!flag)
            {
                b=d;
                flag=1;
            }
        }
        n=x;
    }
    freopen("apple.out","w",stdout);
    cout<<d<<" "<<b<<endl;
    return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;
int all,out;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,sum,n1;
    cin>>n;
    n1=n;
    if(n<=3)
    {
        cout<<n<<" "<<n;
        return 0;
    }
    for(int i=1;i<=n+10;i++)
    {
        int f = n/3;
        if(n%3!=0)
            f++;
        n-=f;
        if(n%3==1)
            out=i+1;
        if(n<=3)
        {
            i+=n;
            n=0;
        }

        if(n==0)
        {
            all=i;
            out=i;
            break;
        }
    }
    if(n1%3==1)
    {
        out=1;
    }
    cout<<all<<" "<<out;
    fclose(stdin);
    fclose(stdout);
}

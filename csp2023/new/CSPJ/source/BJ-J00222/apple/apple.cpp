#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N=1e9+1;
int nans,anas;
bool bb[N];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >>n;

    if(n<=3)
    {
        nans=n;
    }
    else if(n%3==1){
        nans=1;
    }
    else if((n-2)%9==0||(n-2)%9==4)
    {
        nans=2;
    }
    else
    {
        int p=1;
        for(int i=1;i<=n;i++)
        {
            int a,b;
            p*=3;
            a=(n-i)% p==0;
            b=(n-i)% p==p/i;
            if(n==a||n==b){nans=i;break;}
        }
    }
    while(1)
    {
        if(n>1){
            int j=(n-1)/3+1;
            n=n-j;

        }
        else{
            n-=1;
        }
       // cout <<n<<"\n";
        anas++;
        if(n==0)
        {
            break;
        }

    }
    cout <<anas<<" "<<nans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

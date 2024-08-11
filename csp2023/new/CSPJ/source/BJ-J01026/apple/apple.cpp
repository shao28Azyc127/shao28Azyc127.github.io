#include <iostream>

using namespace std;
int n,a,cnt,ans2,cur=3;
bool f=0;
int xs(double x)
{
    int k=x;
    if(x>1.0*k) return k+1;
    else return k;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;

    a=n;
    while(a!=0)
    {
        a-=xs(1.0*a/3);
        cnt++;
    }
    if(n%3==1) ans2=1;
    else
    {
        while(true)
        {
            if(cur*(cur+1)/2-4==n)
            {
                f=1;
                break;
            }
            else if(cur*(cur+1)/2-4>n)
            {
                break;
            }
            cur++;
        }
        if(f==1) ans2=2;
        else ans2=cnt;
    }
    cout<<cnt<<" "<<ans2;
    return 0;
}
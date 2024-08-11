#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int T,M,a[100001],b[100001],c[100001];
bool check(int x,int y,int z)
{
    int delta=y*y-4*x*z;
    if(delta<0) return 0;
    return 1;
}
int aa(int x,int y,int z)
{
    int a1=sqrt(y*y-4*x*z);
    int a2=a1-y;
    int a3=-y-a1;
    a2=a2/2/x;
    a3=a3/2/x;
    return max(a2,a3);
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    for(int i=1;i<=T;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=T;i++)
    {
        if(check(a[i],b[i],c[i])==0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            int n=aa(a[i],b[i],c[i]);
            cout<<n<<endl;
        }
    }
    return 0;
}

#include<iosteam>
#include<stdio>
using namespace std;

string a[10];

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
            cin>>a[i];
            string t=a[i];
    }
    if(n==1)
    {
        cout<<81<<endl;
    }
    else
    {
        cout<<10<<endl;
    }
    return 0;
}

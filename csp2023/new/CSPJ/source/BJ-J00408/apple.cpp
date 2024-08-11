#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

long long n,tn,day=1,ans1,ans2;;
bool a[1000000005],flag;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    cin>>n;
    tn=n;
    while(tn>0)
    {
        flag=false;
        for(int i=1;i<=n;i+=3)
        {
            while(a[i]==true)
            {
                i++;
            }
            tn--;
            a[i]=true;
            ans2=day;
            flag=true;
        }
        if(flag==false)
        {
            ans1=day-1;
            break;
        }
        day++;

    }

    cout<<ans1<<' '<<ans2<<endl;

    return 0;
}

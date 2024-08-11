#include<iostream>
using namespace std;
const long long N=100000005;
int a[N];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) a[i]=1;
    int num=0,day1=0,day2=0;
    num=n;
    while(num>0)
    {
        int m=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0) continue;
            if(m==4) m=1;
            if(m==1)
            {
                a[i]--;
                num--;
                if(i==n-1) day2=day1+1;
            }
            if(m<=3) m++;
        }
        day1++;
    }
    cout<<day1<<" "<<day2;
}

#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],flag,tou=1,na,num,tian,z;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    num=n;
    while(num!=0)
    {
        tian++;
        z=0;
        for(int i=tou;i<=n;i+=3)
        {
            a[i]=1;
            z++;
            if(a[n]==1&&flag==0)
            {
                na=tian;
                flag=1;
            }
            while(a[i]>a[i-1])
            {
                swap(a[i],a[i-1]);
            }
            num--;
        }
        tou+=z;
    }
    cout<<tian<<" "<<na;
    return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;
int de(int a,int b)
{
    if(a<b)
        return 0;
    if(a%b==0)
        return a/b;
    return a/b+1;
}
int main()
{
    freopen("road1.in","r",stdin);
    freopen("road.out","w",stdout);
    int v[10005]={};
    int a[10005]={};
    int n,d,sum=0,m,l=0;
    cin>>n>>d;
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i==0)
        {
            sum+=de(v[i],d)*a[i];
            l+=de(v[i],d)*d;
            m=a[i];
        }
        else
        {
            l-=v[i];
            if(a[i]>m)
            {
                sum+=de(v[i]-l,d)*m;
                l+=de(v[i]-l,d)*d;
            }

            else
            {
                sum+=de(v[i]-l,d)*a[i];
                l+=de(v[i]-l,d)*d;
                m=a[i];
            }
        }


    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;


}

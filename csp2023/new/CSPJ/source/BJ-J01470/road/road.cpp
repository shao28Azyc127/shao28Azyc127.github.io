#include <bits/stdc++.h>
using namespace std;
int n,d,a[100000],b[100000],c[100000],num=0,money=0,oil=0,h=0;
int bijiao(int x,int y)
{
    if(x>=y)
        return 0;
    if(x<y)
        return 1;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(int i=0;i<=n;i+=h+1)
    {
        for(int j=i;j<n;j++)
        {
            if(bijiao(b[i],b[j+1]))
                num+=a[j],h++;
            else
            {
                if(bijiao(b[i],b[j+1])&&j==i)
                {
                    num+=a[i];
                    break;
                }
                num+=a[j+1];
                break;
            }
        }
        if(num%d==0)
            oil+=num/d;
        else
            oil+=num/d+1;
        money+=oil*b[i];
        num=0;
        oil=0;
    }
    cout<<money;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n,i,j,d,sum,y;

struct node
{
    int v,a;
}a[100010];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(i=0;i<n-1;i++)
    {
        cin>>a[i].v;
    }
    for(i=0;i<n;i++)
    {
        cin>>a[i].a;
    }
    for(i=0;i<n-1;i++)
    {
        if(y<a[i].v)
        {
            while(y<a[i].v)
            {
                y=y+d;
                sum=sum+a[i].a;
            }
            if(a[i].a<a[i+1].a)
            {
                while(y<a[i].v+a[i+1].v)
                {
                    y=y+d;
                    sum=sum+a[i].a;
                }
            }
        }
        y=y-a[i].v;
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
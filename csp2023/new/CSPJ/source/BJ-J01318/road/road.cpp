#include <iostream>
#include <cstdio>
using namespace std;
struct lm
{
    int v;
    int m;
};
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    lm a[100000];
    for(int i=0;i<n-1;i++)
    {
        cin>>a[i].v;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i].m;
    }
    int b=0;
    int c=0;
    int i=0;
    while(i<n-1)
    {
        int h=i+1;
        int f;
        while(a[h].m>=a[i].m)
        {
            a[i].v+=a[h].v;
            h++;
        }
        if(b<a[i].v)
        {
            f=(a[i].v-b)/d;
            if((a[i].v-b)%d)
            {
                f++;
            }
            b+=f*d;
            c+=f*a[i].m;
        }
        b-=a[i].v;
        i=h;
    }
    cout<<c;
    return 0;
}

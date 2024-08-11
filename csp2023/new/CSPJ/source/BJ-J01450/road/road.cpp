#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int s,b;
    cin>>s>>b;
    int x[s-1],a[s];
    for(int i=0;i<s-1;i++)
    {
        cin>>x[i];
    }
    for(int i=0;i<s;i++)
        cin>>a[i];
    int oil=0,point=0,km=0;
    while(point<s)
    {
        for(int i=point+1;i<s;i++)
        {
            if(a[i]<a[point])
            {
                for(int j=point;j<i;j++)
                {
                    km+=x[j];
                    point=j+1;
                }
            }
            else
            {
                for(int i=point;i<min_element(x+point,x+s-2)-x-1;i++)
                {
                    km+=x[i];
                    point=i+1;
                }
            }
        }
    }
    if(km%b==0)
    {
        oil=km/b;
    }
    else
        oil=km/b+1;
    cout<<oil;
    return 0;
}

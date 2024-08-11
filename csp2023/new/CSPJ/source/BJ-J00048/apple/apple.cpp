#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int dn=0,d=n;
    int day=0;
    bool en=0;
    for(int i=1;i<=n;i++)
    {
        day++;
        if(d%3==1&&en==0)
        {
            dn=i;
            en=1;
        }
        d-=(d-1)/3+1;
        if(d==1)
        {
            day++;
            if(en==0)
            {
                dn=day;
            }
            break;
        }
    }
    cout<<day<<" "<<dn<<endl;
    return 0;
}

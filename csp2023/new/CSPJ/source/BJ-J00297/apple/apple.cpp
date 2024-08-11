#include<iostream>
using namespace std;
bool flag[1000000000];
int main()
{
    int n,day=1,ans=0;
    cin>>n;
    int id =0;
    for(int j = 1; j<=n; j++)
    {
        while(flag[id]) id++;
        if(id=n-1) ans=day;
        flag[id]=1;
        for(int i = 1; i<=3; i++)
        {
            id++;
            if(id>=n)
            {
                id=0;
                day++;
                break;
            }
            while(flag[id]) id++;
        }

    }
    cout<<day<<" "<<ans<<endl;
    return 0;
}
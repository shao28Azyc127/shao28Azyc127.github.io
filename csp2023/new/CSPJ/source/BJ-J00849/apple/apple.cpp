#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    long long a[n+5];
    for (int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    int num=0,i=n,cnt=1,ans=0,sum=0,b=1;
    while (i>0)
    {
        num++;
        while (a[cnt]==-1)
        {
            cnt++;
        }
        if (cnt==n)
        {
            ans=num;
        }
        a[cnt]=-1;
        //cout<<cnt<<" ";
        i--;
        //cnt++;
        sum=1;
        while (i>0)
        {
            if (a[cnt]==-1)
            {
                cnt++;
            }
            else       //(a[cnt]!=-1)
            {

                if (sum==3)
                {
                    if (cnt==n)
                    {
                        ans=num;
                    }
                    a[cnt]=-1;
                    i--;
                    sum=0;
                    //cout<<cnt<<" ";
                }
                cnt++;
                sum++;
            }
            if (cnt>n)
            {
                //cnt%=n;
                b++;
                cnt=b;
                //cout<<cnt<<endl;
                break;
            }
        }
        //cout<<endl;
    }
    cout<<num<<" "<<ans;
    return 0;
}

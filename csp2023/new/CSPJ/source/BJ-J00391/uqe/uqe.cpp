#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n;
    cin>>n;
    while(n--)
    {
        int m,n,k;
        cin>>m>>n>>k;
        if(n==0&&m==0)
        {
            cout<<0<<endl;
        }else{
            if(n==0)
            {
                cout<<sqrt(k)<<endl;
            }
            if(k==0)
            {
                if(n>0&&m>0)
                {
                    cout<<0-n/m;
                }
                if(n>0&&m<0)
                {
                    cout<<n/(0-m);
                }
                if(m>0&&n<0)
                {
                    cout<<(0-n)/m;
                }
                  
                if(n<0&&m<0)
                {
                    cout<<0-n/m;
                }  
            }
        }
    }

    return 0;
}

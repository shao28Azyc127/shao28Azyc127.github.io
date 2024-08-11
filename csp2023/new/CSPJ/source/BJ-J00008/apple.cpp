#include <bits/stdc++.h>

using namespace std;

int n,sum,num,i,j,k,k1,m;

bool a[1000000010]={1};

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    m=n;
    while(1)
    {
        k1=0;
        for(i=0;i<m;)
        {
            if(a[i])
            {
                if(i==n-1) num=k;
                a[i]=0;
                k1++;
                for(j=0;j<=2;)
                {
                    if(a[i]) j++;
                    i++;
                    if(i>=m) break;
                }
            }
            else i++;
        }
        n=n-k1;
        if(n<=0)
        {
            sum=k;
            break;
        }
        k++;
    }
    cout<<sum<<" "<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
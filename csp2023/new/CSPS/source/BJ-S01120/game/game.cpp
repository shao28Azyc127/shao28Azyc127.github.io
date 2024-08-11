#include<iostream>
#include<stdio.h>
char a[2000005];
long long n,ans;
using namespace std;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=' ')
        {
            char y;
            y=a[i];
            for(int j=i+1;j<n-1;j++)
            {
                if(a[j]!='')
                {
                ans+1;
                }
            }
        }

    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

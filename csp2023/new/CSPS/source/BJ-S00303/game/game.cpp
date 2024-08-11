#include<bits/stdc++.h>
using namespace std;
int n,cnt,flag=0;
char a[200050],b[200050];
bool Check(int s,int f)
{
    int sum=0;
    for(int i=s,j=1;i<=f;i++,j++)
    {
        b[j]=a[i];
        sum=j;
    }
    for(int i=1;i<sum;i++)
    {
        if(b[i]==b[i+1])
        {
            for(int j=i;j<=sum-2;j++)
            {
                b[j]=b[j+2];
            }
            sum-=2;
            i=0;
        }
    }
    if(sum==0)
        return true;
    return false;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;i+j<=n;j+=2)
        {
            if(Check(i,i+j)==true)
                cnt++;
        }
    }
    fclose(stdin);
    fclose(stdout);
    cout<<cnt;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;
int sum,ans;
bool flag;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(n!=0)
    {
        sum++;
        if(n%3==1&&flag==0)
        {
            flag=1;
            ans=sum;
        }
        n=n*2/3;
    }
    printf("%d %d",sum,ans);
    return 0;
}

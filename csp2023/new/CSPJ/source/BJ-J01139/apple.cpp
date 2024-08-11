#include <bits/stdc++.h>
using namespace std;
int n,sum,i,j,ans,f;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    sum = n;
    j = n;
    if(j%3 == 1) {ans = 1;f = 1;}
    while(sum>=0)
    {
        i++;
        int arr = sum/3+1;
        int arr2;
        if(sum%3 == 0)
        {
            arr2 = sum/3;
        }
        else arr2 = sum/3+1;
        sum-=arr;
        j-=arr2;
        if(j%3 == 1&&f == 0) {ans = i+1;f = 1;}
    }
    printf("%d %d",i,ans);
    return 0;
}

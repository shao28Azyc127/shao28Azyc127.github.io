#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);
    int m = n;
    int z = 0,a = 0,flag = 0;
    while(true)
    {
        if(n == 1)
        {
            break;
        }
        if(flag == 0)
        {
            a++;
            if((n - 1) % 3 == 0)
            {
                flag = 1;
                a--;
            }
        }
        n = n - ((n - 1) / 3 + 1);
        z++;
    }
    printf("%d %d",z + 1,a + 1);
    return 0;
}

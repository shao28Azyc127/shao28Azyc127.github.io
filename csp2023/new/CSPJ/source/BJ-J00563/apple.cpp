#include <bits/stdc++.h>

using namespace std;

int a[100];

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int day1 = 0;
    int day2 = 0;
    for(int i = 1;i<=n;i++)
    {
        a[i] = 1;
    }
    for(int i = 1;;i++)
    {
        int t = 2;
        for(int j = 1;j<=n;j++)
        {
            if(a[j]!=0)
            {
                t++;
                if(t == 3)
                {
                    t = 0;
                    a[j] = 0;
                    if(j == n)
                    {
                        day2 = i;
                    }
                }
            }
        }
        int c = 0;
        for(int j = 1;j<=n;j++)
        {
            c = a[j];
        }
        if(c == 0)
        {
            day1 = i;
            break;
        }
    }
    cout<<day1<<" "<<day2;
    return 0;
}

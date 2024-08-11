#include <bits/stdc++.h>
using namespace std;
int n;

struct numbers
{
    int num;
    bool rolled;
};

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    numbers a[n+5];
    for (int i = 1;i<=n;i++)
    {
        a[i].num = i;
    }
    int f,s,t;
    int days = 0,ans = 0;
    for (int i = 1;i<=n;i+=3)
    {
        for (f = 1; f<= n;f+=3)
        {
            for (s = f+1;s<=n;s+=3)
            {
                for(t = f+2;t<=n;t+=3)
                {
                    while (!a[f].rolled)
                    {
                        if (a[f].rolled){
                            if (f == n)
                            {
                                ans = days;
                            }
                            a[f].rolled = true;
                            break;
                        } else {
                            if(f <= n){
                                f++;
                                s++;
                                t++;
                            } else {
                                f = n;
                            }
                        }
                    }
                    while (!a[s].rolled)
                    {
                        if (a[s].rolled){
                            break;
                        } else {
                            if(s <= n){
                                s++;
                            } else {
                                s = n;
                            }
                        }
                    }
                    while (!a[t].rolled)
                    {
                        if (a[t].rolled){
                            break;
                        } else {
                            if(t <= n){
                                t++;
                            } else {
                                s=t = n;
                            }
                        }
                    }
                }
            }
        }
        if (a[f].rolled == true&&a[s].rolled == true&&a[t].rolled == true) break;
        days ++;
        f = 1;s = 1;t = 1;
    }
    printf("%d %d",days,ans);
    return 0;
}
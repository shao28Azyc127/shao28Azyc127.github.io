#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int T, M;
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin>>T>>M;
    while(T--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(((b * b) - (4 * a * c)) < 0)
        {
            printf("NO\n");
            continue;
        }
        int derta = (b * b) - (4 * a * c);
        double ans1 = (-b + sqrt(derta)) / (2 * a);
        double ans2 = (-b - sqrt(derta)) / (2 * a);
        double anss = max(ans1, ans2);
        for(int i = 0; i <= M; i++)
        {
            int t2 = anss * i;
            if(__gcd(t2, i) == 1)
            {
                if(i == 1)
                {
                    cout<<t2<<endl;
                    break;
                }
                else
                {
                    cout<<t2<<"/"<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}

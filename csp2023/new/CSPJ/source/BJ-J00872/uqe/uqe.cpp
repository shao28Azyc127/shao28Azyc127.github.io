#include<bits/stdc++.h>

using namespace std;
int T, M;
#define debug(x) cout << #x << '=' << x << endl
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d %d", &T, &M);
    while(T--)
    {
        int a, b, c, ans = 0;
        scanf("%d %d %d", &a, &b, &c);
        if(b != 0)
        {
            int derta = b * b - 4 * a * c;
            if(derta < 0) printf("NO\n");
            else
            {
                int x1 = (-b + sqrt(derta)) / 2 / a;
                int x2 = (-b - sqrt(derta)) / 2 / a;
                printf("%d\n", max(x1, x2));
            }

            continue;
        }
        ans -= c;
        if(ans < 0)
        {
            printf("NO\n");
            continue;
        }
        int q = 1, v = ans / a;
        if(floor(sqrt(v)) * floor(sqrt(v)) == v)
        {
            printf("%d\n", sqrt(v));
            continue;
        }
//        debug(v);
        for(int i = 2; i * i <= v; i++)
        {
            while(v % (i * i) == 0)
                v /= (i * i), q *= i;
  //          debug(q);
 //           debug(v);;
        }
        if(q != 1) printf("%d*", q);
        printf("sqrt(%d)\n", v);
    }
    return 0;
}

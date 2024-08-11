#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int t, m, a, b, c;

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &t, &m);
    for(int i = 1; i <= t; i++){
        scanf("%d%d%d", &a, &b, &c);
        int ge=b*b-4*a*c;
        if(ge < 0){
            printf("NO\n");
            continue;
        }
        int ans=0;
        if((int)(sqrt(ge))==sqrt(ge)){
                ans = ((0-b)+sqrt(ge));
            if(ans%(2*a)==0){
                printf("%d\n", ans/2/a);
                continue;
            }
            if(ans%2==0){
                printf("%d/%d\n", ans/2, a);
                continue;
            }
            if(ans%a==0){
                printf("%d/2\n", ans/a);
                continue;
            }
        }
        else{
            if(b%(2*a)==0){
                printf("%d+sqrt(%d)/%d\n", b/2/a, ge, 2*a);
                continue;
            }
            if(b&1)
                printf("%d/%d+sqrt(%d)/%d\n", (0-b), (2*a), ge, (2*a));
            else if(b==0)
                printf("sqrt(%d)/%d\n", ge, (2*a));
            else if(b%a==0)
                printf("%d/%d+sqrt(%d)/%d\n", (0-b)/a, 2, ge, (2*a));
            else
                printf("%d/%d+sqrt(%d)/%d\n", (0-b)/2, a, ge, (2*a));
            continue;
        }

        if(ans&1){
            printf("%d/%d+%d\n", (0-b), 2*a, ans);
            continue;
        }
        printf("%d/%d\n", ans/2, a);
    }


    return 0;
}

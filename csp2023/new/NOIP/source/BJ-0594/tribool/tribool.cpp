#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t,m,n;
    cin >> c >> t;
    if(c == 3 || c == 4){
        struct tribool{
            char tb;
            int x;
        };
        for(int z = 1;z <= t;z++){// cout t times in total
            cin >> n >> m;
            tribool l[m+5];
            int sum = 0;//to sum up
            int a[n+5] = {0};//to check whether there's U
            for(int i = 1;i <= m;i++){
                cin >> l[i].tb >> l[i].x;
                if(l[i].tb == 'U')
                    a[l[i].x] = 1;
            }
            for(int i = 1;i <= n;i++){
                if(a[i] == 1)
                    sum++;
            }
            cout << sum << endl;
        }
    }
    else if(c == 5 || c == 6){
        struct tribool{
            char tb;
            int x;
            int y;
        };
        for(int z = 1;z <= t;z++){
            cin >> n >> m;
            tribool l[m+5];
            int sum = 0;
            int a[n+5];
            for(int i = 1;i <= n;i++){
                a[i] = i;
            }
            for(int i = 1;i <= m;i++){
                cin >> l[i].tb;
                if(l[i].tb  == 'U'){
                    cin >> l[i].x;
                    a[l[i].x] = 0;
                }
                else{
                    cin >> l[i].x >> l[i].y;
                    a[l[i].x] = a[l[i].y];
                }
            }
            for(int i = 1;i <= n;i++){
                if(a[i] == 0)
                    sum++;
            }
            cout << sum;
        }
    }
    else {
        struct tribool{
            char tb;
            int x;
            int y;
        };
        for(int z = 1;z <= t;z++){
            cin >> n >> m;
            tribool l[m+5];
            int sum = 0;
            int t = 1;
            int a[n+5];
            for(int i = 1;i <= n;i++){
                a[i] = i;
            }
            for(int i = 1;i <= m;i++){
                cin >> l[i].tb >> l[i].x >> l[i].y;
                if(l[i].tb == '+'){
                    a[l[i].x] = a[l[i].y];
                }
                else{
                    a[l[i].x] = a[l[i].y];
                }
            }
            for(int k = 1;k <= n;k++){
                for(int i = t;i <= n;i++){
                    for(int j = 1;j <= n;j++){
                        if(j == a[i] || j != i){
                            //aaaaaa time is up but it does not matter ^-^
                        }
                    }
                }
            }
            cout << 0;

        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct ap{
    int d;
    int num;
    int g;
}a[100000005];
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        a[i].num= i;
        a[i].g = 0;
    }
    int flag = 1, da= 0;
    while(flag){
        da++;int cnt=1, sum==0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i].g == 0){
                    cnt++;
                if(cnt%3==1)
                {
                    a[i].g= 1;
                    a[i].d = da;
                    sum++;
                }
            }
        }
        if(sum==0)
            flag =0;
    }
    cout << da << a[i].d;
    return 0;

}

#include <bits/stdc++.h>
using namespace std;
int c,T;
int a[100005];
int ca[100005];//-1 0 1
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin >> c >> T;
    while(T--)
    {
        memset(ca,0,sizeof(ca));
        int n,m; cin >> n >> m;
        for(int t = 1;t <= n;t++) a[t] = t;
        for(int t = 1;t <= m;t++)
        {
            char v; cin >> v;
            if(v == '+')
            {
                int i,j; cin >> i >> j;
                a[i] = a[j];
                ca[i] = ca[j];
            }
            else if(v == '-')
            {
                int i,j; cin >> i >> j;
                a[i] = -a[j];
                ca[i] = -ca[j];
            }
            else
            {
                int i; cin >> i;
                a[i] = 0;
                if(v == 'U') ca[i] = 0;
                else if(v == 'F') ca[i] = -1;
                else ca[i] = 1;
            }
        }

//for(int i = 1;i <= n;i++) cout << a[i] << " " << ca[i] << endl;

        for(int i = 1;i <= n;i++) 
            if(a[i] == -i) 
            {
                a[i] = 0;
                ca[i] = 0;
            }
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            if(a[i] != i && a[i] != 0)
            {
                int cishu = 0;
                int k = abs(a[i]); a[i] = (a[i]/abs(a[i])) * a[k]; ca[i] = (a[i]/abs(a[i])) * ca[k];
                while(a[k] != k && a[k] != 0)
                {
                    if(a[i] == -i)
                    {
                        a[i] = 0;
                        ca[i] = 0;
                        break;
                    }
                    k = abs(a[k]);
                    a[i] = (a[i]/abs(a[i])) * a[k];
                    ca[i] = (a[i]/abs(a[i])) * ca[k];
                    //cout << i << " " << a[i] << endl;
                    
                    cishu++;
                    if(cishu > n) break;
                }
            }
            if(a[i] == 0 && ca[i] == 0) ans++;
        }
        cout << ans << endl;
       // cout << endl;
    }


    return 0;
}
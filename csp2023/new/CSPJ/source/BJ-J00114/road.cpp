#include <iostream>
#include <time.h>
using namespace std;
long long len[100010];
long long v[100010];
int main()
{
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    long long n , d;
    cin >> n >> d;
    for(long long i = 1 ; i <= n - 1 ; i ++)
    {
        cin >> len[i];
    }
    for(long long i = 1 ; i <= n ; i ++)
    {
        cin >> v[i];
    }
    long long ol = 0;
    long long ans = 0;
    for(long long i = 1 ; i < n ; i ++)
    {
        if(v[i + 1] < v[i])
        {
            //cout<< 1 << " " << ol ;
            long long lon = len[i] - ol;
            long long mu;
            if(lon % d == 0)
            {
                mu = lon / d;
            }
            else{
                mu = lon / d + 1;
            }
            ans += v[i] * mu;
            ol = mu * d - len[i];
            //cout <<" "<< mu << " " << v[i] * mu << endl;

        }
        else if(v[i + 1] > v[i])
        {
            //cout << 2 << " " << ol ;
            long long lon = 0;
            long long j;
            for(j = i ; j < n; j ++)
            {
                if(v[j + 1] > v[i])
                {
                    lon += len[j];
                }
                else{
                    lon += len[j];
                    break;
                }
            }
            long long s = lon;
            lon -= ol;
            long long mu;
            if(lon % d == 0)
            {
                mu = lon / d;
            }
            else{
                mu = lon / d + 1;
            }
            ans += v[i] * mu;
            ol = ol + mu*d - s;
            //cout << " " << s << " " << mu << " " << v[i] * mu << endl;
            i = j;
        }
    }
    cout << ans << endl;
    return 0;
}

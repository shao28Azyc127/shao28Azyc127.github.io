#include<iostream>
using namespace std;
int n;
int c[100005];
int sum[100005];
int a[100005];
int d;
int answ[100005];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin >> n >> d;
    c[1] = 0;
    for(int i = 2;i <= n;i++)
    {
        cin >>c[i];
        sum[i] = sum[i - 1] + c[i];
    }
    for(int i = 1;i <= n;i++)
    {

        cin >> a[i];
    }
    int now = n;
    int ans = 0;
    int tot = 0;
    answ[0] = n;
    while(now > 1)
    {
        int minn = 1e8;
        int pos = -1;

        for(int i = 1;i < now;i++)
        {
            if(a[i] < minn)
            {
                minn = a[i];
                pos = i;
            }

        }
        now = pos;
        answ[++tot] = now;
    }
    int more = 0;
    for(int i = tot;i >= 1;i--)
    {
        int next = answ[i - 1];
        int xian = answ[i];
        int val = (sum[next] - sum[xian] - more) / d;
        if((sum[next] - sum[xian] - more) % d != 0)
        {

            val++;
        }
        more = val * d - (sum[next] - sum[xian] - more);
        ans += val * a[xian];
    }
    cout << ans << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N = 8003;
typedef long long ll;

char a[N];
bool flag[N][N];

int main()
{
    ios::sync_with_stdio(false);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    cin >> a+1;
    ll cnt = 0;
    for(int i = n-1; i >= 1; i--)
    {
        for(int j = i+1; j <= n; j+=2)
        {
            if(a[i] == a[j] && (i+1 == j || flag[i+1][j-1]))
            {
                flag[i][j] = true;
                cnt++;
                continue;
            }
            for(int k = i+1; k < j; k+=2)
            {
                flag[i][j] = flag[i][k] && flag[k+1][j];
                if(flag[i][j])
                    break;
            }
            cnt += flag[i][j];
            //cout << i << " " << j << " " << flag[i][j] << endl;
        }
    }
    cout << cnt << endl;
    return 0;
}

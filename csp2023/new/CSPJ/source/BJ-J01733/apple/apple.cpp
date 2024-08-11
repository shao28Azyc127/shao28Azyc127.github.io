#include <iostream> 
#include <cstdio>
using namespace std;

const int N = 1e6 + 5;
int n, tmp = 0, tn, cnt = 0, ans;
bool flag = 0;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    tn = n;
    while(tn > 0)
    {
        cnt++;
        if(tn % 3 == 1 && !flag)
        {
            flag = 1;
            ans = cnt;
        }
        tn = tn - ((tn - 1) / 3 + 1);
    }
    
    cout << cnt << " " << ans << endl;
    return 0;
}
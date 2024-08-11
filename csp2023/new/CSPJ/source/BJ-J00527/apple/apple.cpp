#include <iostream>
#include <cmath>
using namespace std;

bool l[1000010];
int ans1,ans2;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    int x = n;
    while (x){
        x -= ceil(x/3.0);
        ans1++;
    }
    cout << ans1 << " ";
    int len = n;
    while (len){
        ans2++;
        int v = 2;
        for (int i = 1;i <= n;i++){
            if (l[i] == 0) v++;
            if (v == 3){
                l[i] = 1;
                len--;
                v = 0;
                if (i == n){
                    cout << ans2;
                    return 0;
                }
            }
        }
    }
    return 0;
}

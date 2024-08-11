#include <bits/stdc++.h>
using namespace std;
int ans1,ans2,n;
bool f1 = false,f2 = false,f3 = false;
const int N = 1e6 + 10;
int a[N];
bool r[N] = {false};
int main() {

    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    int k = 1;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++,k++) {
        for(int j = i;j <= n;j += 3) {
            for(int x = j;x <= j + 3;x++) {
                if(r[x] == true) {
                    f3 = true;
                    break;
                }
            }
            if(f3 == true) j++;
            if(j == n && f1 == false) {
                cout << i << " ";
                f1 = true;
            }
            r[j] = true;
        }
        n -= (n / 3 + 1);
        if(n <= 3 && f2 == false) {
            f2 = true;
            break;
        }
    }
    if(f2 && f1 == false) {
        k += n;
        cout << k << " " << k;
    } else if(f2 && f1 == true) {
        cout << k + n;
    }
    else {
        cout << k + n;
    }

    return 0;
}

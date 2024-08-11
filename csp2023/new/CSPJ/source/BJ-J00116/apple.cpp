#include <bits/stdc++.h>
using namespace std;
const int N = 10e9 + 1;
int n,sum, x = 2, ans, xn;
bool q[1000000000];
bool b = 0;
int main() {
    freopen("apple.in", "r", stdin);
    
    freopen("apple.out", "w", stdout);
    
    cin >> n;
    memset(q, 0, sizeof(q));
    while(ans != n)///第一个代表取走了多少个苹果，当取走的苹果与一共的苹果相等的时候，代表循环结束
    {///此处代表每一天
       x = 2;
        sum ++ ;///直接将天数多少次循环加加
        for(int i = 1; i <= n ;i ++) {

            if(q[i] == 0 && x == 2) {
				q[i] = 1;//取走苹果
				//cout << i << " ";
				ans ++ ;
				x = 0;
            }
            if(q[i] == 0)
                x ++ ;
        }
        //cout << endl;
        if(q[n] == 1 && b == 0) {
                xn = sum;
                b = 1;
        }
    }
    cout << sum << " " << xn;
    return 0;
}

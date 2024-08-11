#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> v;
bool check(int tmp){
    for (int i = 0; i < v.size(); i ++)
        if (tmp == v[i]) return 0;
    return 1;
}
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n, a[10], cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i ++){
        int tmp = 0;
        for (int j = 0; j < 5; j ++){
            cin >> a[j];
            tmp = tmp * 10 + a[j];
        }
        for (int j = 0; j < 5; j ++){
            int tmpi = (int)(tmp / pow(10, 4 - j)) % 10;
            for (int k = 1; k < 10; k ++){
                int kk = (((tmpi + k) % 10 < tmpi) ? -1 * (tmpi - (tmpi + k) % 10) : ((tmpi + k) % 10 - tmpi)) * pow(10, 4 - j);
                tmp += kk;
                if (check(tmp)) cnt ++;
                tmp -= kk;
            }
        }
        for (int j = 0; j < 4; j ++){
            int tmpi1 = (int)(tmp / pow(10, 4 - j)) % 10;
            int tmpi2 = (int)(tmp / pow(10, 4 - j + 1)) % 10;
            for (int k = 1; k < 10; k ++){
                int kk1 = (((tmpi1 + k) % 10 < tmpi1) ? -1 * (tmpi1 - (tmpi1 + k) % 10) : ((tmpi1 + k) % 10 - tmpi1)) * pow(10, 4 - j);
                int kk2 = (((tmpi2 + k) % 10 < tmpi2) ? -1 * (tmpi2 - (tmpi2 + k) % 10) : ((tmpi2 + k) % 10 - tmpi2)) * pow(10, 4 - j + 1);
                tmp += kk1 + kk2;
                if (check(tmp)) cnt ++;
                tmp -= kk1 + kk2;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

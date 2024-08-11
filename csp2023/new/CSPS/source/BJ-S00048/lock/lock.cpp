#include<iostream>
#include<cstring>
typedef long long ll;
using namespace std;
const int N = 10;
const int M = 20;

int f(int a[5]){
    int res = 0;
    for(int i = 0; i < 5; i++){
        res = res * 10 + a[i];
    }
    return res;
}

int n, ans;
int a[N][N], cnt[(int)1E6 + 10];
int p[] = {1, 10, 100, 1000, 10000};

int main(){

    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 5; j++){
            cin >> a[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++){
        int x[5];
        memcpy(x, a[i], sizeof(x));
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 10; k++){
                x[j]++;
                x[j] %= 10;
                cnt[f(x)]++;
            }
        }
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 10; k++){
                x[j]++;
                x[j + 1]++;
                x[j] %= 10;
                x[j + 1] %= 10;
                cnt[f(x)]++;
            }
        }
    }

    for(int i = 0; i < 1E5; i++){
        if(cnt[i] == n) ans++;
    }
    cout << ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
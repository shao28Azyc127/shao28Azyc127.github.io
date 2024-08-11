#include<iostream>
#include<string.h>

using namespace std;

const int N = 1e5 + 5;

int arr[6], res, st[N], last[N];

int n, times;


void dfs(int cur){
    int ans = 0;
    for(int i = 1; i <= 5; i++){
        ans *= 10;
        ans += arr[i];
    }
    if(cur == 1){
        if(!last[ans]){
            st[ans] ++;
            last[ans] = 1;
        }
        return ;
    }
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 2; j++){
            if(i == 5 && j == 2) continue;
            for(int q = 1; q <= 9; q++){
                for(int k = 1, now = i; k <= j; k++, now++){
                    arr[now] += q;
                    arr[now] %= 10;
                }
                dfs(cur + 1);
                for(int k = 1, now = i; k <= j; k++, now++){
                    arr[now] -= q;
                    if(arr[now] < 0) arr[now] += 10;
                }
            }
        }
    }
}

int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 5; j++){
            cin >> arr[j];
        }
        dfs(0);
        memset(last, 0, sizeof last);
    }
    for(int i = 0; i < N; i++){
        if(st[i] == n) res ++;
    }
    cout << res;
    return 0;
}

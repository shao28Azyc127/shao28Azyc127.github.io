#include<bits/stdc++.h>
using namespace std;
int a[10][6], check1[100000] = {0};

int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5; j++)
            cin >> a[i][j];
    if (n == 1){
        cout << 81;
        return 0;
    }

    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= 5; i++)
            for (int j = 1; j <= 9; j++)
                check1[(a[k][i] + j) % 9]++;
    }

    int num = 0;
    for (int i = 0; i <= 99999; i++)
        if (check1[i] == n)
            num++;

    cout << num;

    return 0;
}
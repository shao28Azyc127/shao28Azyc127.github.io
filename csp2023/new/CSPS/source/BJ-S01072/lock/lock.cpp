#include <bits/stdc++.h>
/*
    long long
    freopen
*/
using namespace std;

int const N = 10;

int a[N][10], n, ans;

int dis[10][10] = {
{0, 1, 2, 3, 4, 5, -4, -3, -2, -1},
{-1, 0, 1, 2, 3, 4, 5, -4, -3, -2},
{-2, -1, 0, 1, 2, 3, 4, 5, -4, -3},
{-3, -2, -1, 0, 1, 2, 3, 4, 5, -4},
{-4, 3, 2, 1, 0, 1, 2, 3, 4, 5},
{5, -4, -3, -2, -1, 0, 1, 2, 3, 4},
{4, 5, -4, -3, -2, -1, 0, 1, 2, 3},
{3, 4, 5, -4, -3, -2, -1, 0, 1, 2},
{2, 3, 4, 5, -4, -3, -2, -1, 0, 1},
{1, 2, 3, 4, 5, -4, -3, -2, -1, 0}};

bool g(int a1[], int a2[]){
    vector <int> diff;
    for (int j = 1;j <= 5;++j){
        if (a1[j] != a2[j]){
            diff.push_back(j);
        }
    }
    if (diff.size() == 2){
        if (abs(diff[0] - diff[1]) == 1){
            if (dis[a2[diff[0]]][a1[diff[0]]] == dis[a2[diff[1]]][a1[diff[1]]])
                return 1;
        }
    }
    else if (diff.size() == 1) return 1;

    return 0;
}

void f(int x[]){
    for (int i = 1;i <= n;++i){
        if (g(a[i], x) == 0)
            return;
    }
    ans ++;
}

int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n;++i)
        cin >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >> a[i][5];
    if (n == 1){
        cout << 81 << endl;
        return 0;
    }
    else{
        for (int i = 0;i <= 9;++i)
            for (int j = 0;j <= 9;++j)
                for (int k = 0;k <= 9;++k)
                    for (int l = 0;l <= 9;++l)
                        for (int o = 0;o <= 9;++o){
                            int x[] = {0, i, j, k, l, o};
                            f(x);
                        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

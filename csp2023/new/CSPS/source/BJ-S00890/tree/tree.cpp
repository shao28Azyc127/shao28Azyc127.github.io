#include<bits/stdc++.h>
using namespace std;
int day = 0;
int c[100001][100001];
int a[100001] = {0};
bool check[100001];

struct node{
    long long a;
    long long b, c;
}dk[100001];

bool sort1(node x, node y){
    return x.a > y.a;
}

void check1(int n){
    while(true){
        bool flag = true;
        for (int i = 1; i <= n; i++)
            if (a[i] < dk[i].a)
                flag = false;
        if (!flag)
            break;
        day++;
        for (int i = 1; i <= n; i++)
            if (check[i])
                a[i] += max(int(dk[i].b + day * dk[i].c), 1);
        for (int i = 1; i < n; i++)
            if (c[n][i] == 1){
                check1(i);
                c[n][i] = 0;
                c[i][n] = 0;
            }
    }
}

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    memset(c, 0, sizeof(c));
    memset(check, false, sizeof(check));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> dk[i].a >> dk[i].b >> dk[i].c;
    sort(dk + 1, dk + n, sort1);
    for (int i = 1; i <= n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        c[tmp1][tmp2] = 1;
        c[tmp2][tmp1] = 1;
    }

    check[1] = true;
    check1(n);

    cout << day;

    return 0;
}

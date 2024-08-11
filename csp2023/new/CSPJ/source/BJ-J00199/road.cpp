#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int v[MAXN], a[MAXN], f[MAXN], sv[MAXN];
int n, d;
int mn = 0x1f1f1f1f, mnidx, s = 0;
int tot = 0, remain = 0;

#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))

void solve()
{
    int curidx = 1, i = 0;
    for (int useless = 1; useless < n; useless++) {
        if (curidx == n - 1|| i == n - 1) break;
        for (i = curidx; i < n; i++) {
            if (a[i] < a[curidx]) break;
        }
        // ÿ�μ��ͼӵ����ܵ���һ���ȵ�ǰվ����˵�վ��
        int litter = DIV_ROUND_UP(sv[i] - sv[curidx] - remain, d);
        tot += litter * a[curidx];
        remain += litter * d - (sv[i] - sv[curidx]);
        curidx = i;
    }
    int litter = DIV_ROUND_UP(v[n - 1] - remain, d);
    tot += litter * a[curidx];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> d;
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        sv[i] = sv[i - 1] + v[i];
        s += v[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (mn > a[i]) {
            mn = a[i];
            mnidx = i;
        }
    }
    // ��վ��1�ͼ���ͣ���ֱ����վ��1������ȫ�̵���
    if (mnidx == 1) {
        // �����͹�����ȫ�̣�
        cout << a[1] * DIV_ROUND_UP(s, d) << endl;
    }
    // ̰�� �ò��˶��ٷ֣����������ò����������ö����Ƕ���
    solve();
    cout << tot << endl;
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n, d;
int v[100005]; // v[i] 代表第 i 个站点到第 i+1 个站点的距离
int a[100005]; // a[i] 代表第 i 个站点的油价
int s[100005]; // v 数组的前缀和, s[i] 代表从 1 到 i 的路程 

void init_and_read(int &sum_of_v, int &min_among_a, int &mini) {
    scanf("%d%d", &n, &d);
    sum_of_v = 0;
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d", &v[i]);
        sum_of_v += v[i];
        s[i] = s[i - 1] + v[i - 1];
    }
    s[n] = s[n - 1] + v[n - 1];
    min_among_a = 1000005;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < min_among_a) {
            min_among_a = a[i];
            mini = i;
        }
    }
    a[n] = 1000005;
}

void display() {
    for (int i = 1; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int min_among_a, sum_of_v, mini;
    init_and_read(sum_of_v, min_among_a, mini);
    // display();
    if (mini == 1) { // case 11~13
        int ans = ceil(double(min_among_a * sum_of_v) / double(d));
        printf("%d\n", ans);

        return 0;
    }
    int cnt = 0;
    int tpos = 1;
    for (int i = 1; i <= n; i++) {
        // printf("%d:  %d %d %d\n", i, a[i - 1], a[i], a[i + 1]);
        if (i == 1 || (a[i + 1] > a[i] && a[i - 1] > a[i]) && tpos == i) {
            tpos = n - 1;
            for (int j = i + 1; j <= n; j++)  {
                // printf("%d\n", j);
                if (a[j + 1] > a[j] && a[j - 1] > a[j]) {
                    tpos = j;
                    break;
                }
            }
            // printf("%d %d\n", s[tpos], s[i - 1]);
            int ts = ceil(double(s[tpos] - s[i - 1]) * double(a[i]) / double(d));
            // printf("%d %d\n", i, tpos);
            cnt += ts;
        }
    }
    printf("%d\n", cnt);

    return 0;
}
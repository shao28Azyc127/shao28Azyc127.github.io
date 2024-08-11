#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 10;
const int INF = 0x3f3f3f3f;

int ai[8], ina[10][8], n;
int dist(int a, int b)
{
    return (b - a + 10) % 10;
}
bool check()
{
    int ans1 = 0;
    int flag = -1, pos;
    for(int i = 1; i <= n; i++){
        int flg = 1, ps;
        for(int j = 1; j <= 5; j++){
            if(ina[i][j] == ai[j]) continue;
            if(j > 1 && dist(ina[i][j], ai[j]) == dist(ina[i][j - 1], ai[j - 1])){
                if(flg == 2 && ps == j - 1) flg = 3;
                else {flg = 0; break;}
                continue;
            }
            if(flg == 2 || flg == 3){
                flg = 0;
                break;
            }
            flg = 2;
            ps = j;
        }   
        if(flg == 0) return false;
        if(flg == 1) {
            ans1++;
            continue;
        }
        if(flag == -1){
            flag = flg;
            pos = ps;
        }
        else if(flg != flag || pos != ps) 
            return false;
    }
    if(ans1 == n) return false;
    return true;
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 5; j++) 
            scanf("%d", &ina[i][j]);
    int cnt = 0;
    for(int a = 0; a <= 9; a++){ ai[1] = a;
    for(int b = 0; b <= 9; b++){ ai[2] = b;
    for(int c = 0; c <= 9; c++){ ai[3] = c;
    for(int d = 0; d <= 9; d++){ ai[4] = d;
    for(int e = 0; e <= 9; e++){ ai[5] = e;
        if(check()) {
            cnt++;
            //printf("%d %d %d %d %d\n", ai[1], ai[2], ai[3], ai[4], ai[5]);
        }
    }}}}}
    printf("%d", cnt);
    return 0;
}
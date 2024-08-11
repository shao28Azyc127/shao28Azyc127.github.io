#include<bits/stdc++.h>
using namespace std;
int read(){
    char ch = getchar();
    int pn = 1, k = 0;
    while(ch > '9' || ch < '0'){
        if(ch == '-') pn = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        k *= 10;
        k += ch - '0';
        ch = getchar();
    }
    return pn*k;
}
int n, ans;
int x1, x2, x3, x4, x5;
bool sth[10][10][10][10][10];
bool cur[10][10][10][10][10];
void az(){
    memset(cur, false, sizeof(cur));
    for(int i = 1; i < 10; i ++){
        cur[(x1 + i)%10][x2][x3][x4][x5] = true;
        cur[x1][(x2 + i)%10][x3][x4][x5] = true;
        cur[x1][x2][(x3 + i)%10][x4][x5] = true;
        cur[x1][x2][x3][(x4 + i)%10][x5] = true;
        cur[x1][x2][x3][x4][(x5 + i)%10] = true;
        cur[(x1 + i)%10][(x2 + i)%10][x3][x4][x5] = true;
        cur[x1][(x2 + i)%10][(x3 + i)%10][x4][x5] = true;
        cur[x1][x2][(x3 + i)%10][(x4 + i)%10][x5] = true;
        cur[x1][x2][x3][(x4 + i)%10][(x5 + i)%10] = true;
    }
    for(int e1 = 0; e1 < 10; e1 ++){
        for(int e2 = 0; e2 < 10; e2 ++){
            for(int e3 = 0; e3 < 10; e3 ++){
                for(int e4 = 0; e4 < 10; e4 ++){
                    for(int e5 = 0; e5 < 10; e5 ++){
                        if(sth[e1][e2][e3][e4][e5] == true && cur[e1][e2][e3][e4][e5] == false){
                            sth[e1][e2][e3][e4][e5] = false;
                        }
                    }
                }
            }
        }
    }
}
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    n = read();
    memset(sth, true, sizeof(cur));
    for(int i = 0; i < n; i ++){
        x1 = read();
        x2 = read();
        x3 = read();
        x4 = read();
        x5 = read();
        az();
    }
    for(int e1 = 0; e1 < 10; e1 ++){
        for(int e2 = 0; e2 < 10; e2 ++){
            for(int e3 = 0; e3 < 10; e3 ++){
                for(int e4 = 0; e4 < 10; e4 ++){
                    for(int e5 = 0; e5 < 10; e5 ++){
                        if(sth[e1][e2][e3][e4][e5] == true){
                            ans ++;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    fcloseall();
    return 0;
}

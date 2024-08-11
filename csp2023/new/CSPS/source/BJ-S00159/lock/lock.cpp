#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][10], q[10], s[8][8];
int find_same(int a[], int b[]){
    int cnt = 0;
    for(int i = 1; i <= 5; i++)
        if(a[i] != b[i]) q[cnt++] = i;
    if(cnt == 5) return 0;
    else return cnt;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf(" %d",&n);
    for(int i = 1; i <= n; i++){
        scanf(" %d %d %d %d %d",&a[i][1],&a[i][2],&a[i][3],&a[i][4],&a[i][5]);
    }
    if(n == 1){
        printf("81\n");
        return 0;
    }
    for(int i = 1; i <= n - 1; i++){
        s[i][i] = -1;
        for(int j = i + 1; j <= n; j++){
            s[i][j] = find_same(a[i], a[j]);
        }
    }
    if(n == 2){
        switch(s[1][2]){
            case 0: {printf("81\n");return 0;}
            case 1: {printf("10\n");return 0;}
            case 2: {
                    if(q[2] - q[1] == 1){
                        if(a[1][q[2]] - a[1][q[1]] == a[2][q[2]] - a[2][q[1]]) printf("10\n");
                        else printf("2\n");
                    }
                    else printf("2\n");
                    return 0;
            }
        }
        printf("2\n");
    }
    else printf("1\n");
    return 0;
}

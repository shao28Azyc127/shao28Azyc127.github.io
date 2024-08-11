#include<iostream>
#include<vector>
using namespace std;
int n, cnt, a[10], f[15][15][15][15][15];
vector <int> pos, diff;
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    while(n--){
        scanf("%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5]);
        for(int I = 0; I <= 9; ++I)
            for(int J = 0; J <= 9; ++J)
                for(int K = 0; K <= 9; ++K)
                    for(int L = 0; L <= 9; ++L)
                        for(int M = 0; M <= 9; ++M){
                            pos.clear();
                            diff.clear();
                            if(I != a[1]) pos.push_back(1), diff.push_back(I - a[1]);
                            if(J != a[2]) pos.push_back(2), diff.push_back(J - a[2]);
                            if(K != a[3]) pos.push_back(3), diff.push_back(K - a[3]);
                            if(L != a[4]) pos.push_back(4), diff.push_back(L - a[4]);
                            if(M != a[5]) pos.push_back(5), diff.push_back(M - a[5]);
                            if((pos.size() > 2 || (pos.size() == 2 && (pos[1] - pos[0] > 1 || diff[0] != diff[1])) || !pos.size()) && !(pos.size() == 2 && pos[1] - pos[0] == 1 && ((diff[0] + 10 == diff[1]) || (diff[0] == diff[1] + 10)))) f[I][J][K][L][M] = 1;
                        }
    }
    for(int I = 0; I <= 9; ++I)
            for(int J = 0; J <= 9; ++J)
                for(int K = 0; K <= 9; ++K)
                    for(int L = 0; L <= 9; ++L)
                        for(int M = 0; M <= 9; ++M)
                            if(!f[I][J][K][L][M]) cnt++;
    printf("%d", cnt);
    return 0;
}

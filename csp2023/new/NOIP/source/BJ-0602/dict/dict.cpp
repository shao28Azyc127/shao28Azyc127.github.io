#include<bits/stdc++.h>

using namespace std;

char w[3010][3010];
int n, m;
int num[3010][3010];
int suan[3010];    //计算第m列的最值
int mina[3010], minb[3010];
int judge[3010];

void sin() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    sin();
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> w[i][j];
            num[i][j] = w[i][j];
        }
        sort(num[i], num[i] + m + 1);
    }
    for(int i = 1; i <= m; i++) {   //计算每列的最小值和次小值
        //priority_queue<int> q;
        for(int j = 1; j <= n; j++) {
            suan[j] = num[j][m - i + 1];
            //q.push(num[j][m - i + 1]);
        }
        sort(suan, suan + n + 1);
        mina[i] = suan[1];
        minb[i] = suan[2];
    }
    if(n == 1) {
        cout << "1";
        return 0;
    }
    
    for(int i = 1; i <= n; i++) {
        judge[i] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {   //比i个单词的每个字母
            if(num[i][j] != mina[j]) {
                if(num[i][j] > mina[j]) {
                    cout << "0";
                    judge[i] = 0;
                    break;
                }
                if(num[i][j] < mina[j]) {
                    cout << "1";
                    judge[i] = 0;
                    break;
                }
                if(num[i][j] == mina[j]) {
                    continue;
                }
            }
            if(num[i][j] == mina[j]) {
                if(num[i][j] > minb[j]) {
                    cout << "0";
                    judge[i] = 0;
                    break;
                }
                if(num[i][j] < minb[j]) {
                    cout << "1";
                    judge[i] = 0;
                    break;
                }
                if(num[i][j] == minb[j]) {
                    continue;
                }
            }
        }
        if(judge[i] == 1) {
            cout << "1";
        }
    }
    return 0;
}
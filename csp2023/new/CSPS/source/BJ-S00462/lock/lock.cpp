#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

int a[9][5];
int num[10];

int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 5; j++){
            cin >> a[i][j];
        }
    }
    if (n == 1){
        cout << 81;
        return 0;
    } else if (n == 2){
        int difcnt = 0;
        int mark = 0;
        vector <int> v;
        for (int i = 1; i <= 5; i++){
            if (a[1][i] != a[2][i]){
                difcnt++;
                mark = i;
                v.push_back(i);
            }
        }
        if (difcnt == 1){
            if (mark == 1 || mark == 5){
                cout << 10;
            } else{
                cout << 12;
            }
        }
        if (difcnt == 2){
            if (a[1][v[0]]-a[2][v[0]] == a[1][v[1]]-a[2][v[1]]){
                cout << 10;
            } else{
                cout << 2;
            }
        }
        if (difcnt == 3){
            cout << 2;
        }
        if (difcnt == 4){
            cout << 2;
        }
        if (difcnt > 4){
            cout << 0;
        }
    } else{
        int ans = 0;
        int dif = 0;

        for (int i = 1; i <= 5; i++){
            int flag = 0;
            for (int j = 2; j <= n; j++){
                if (a[i][j] != a[i][j-1]){
                    flag = 1;
                    break;
                }
            }
            if (flag == 1){
                dif++;
            }
        }
        if (dif == 1){
            for (int i = 1; i <= 5; i++){
                set <int> s;
                for (int j = 1; j <= n; j++){
                    s.insert(a[i][j]);
                }
                if (s.size() > 1){
                    cout << 10 - s.size();
                    break;
                }
            }
        } else if (dif == 2){
            cout << 10 - n;
        } else if (dif == 3){
            cout << 1;
        }
        if (dif > 3){
            cout << 0;
        }
    }

    return 0;
}

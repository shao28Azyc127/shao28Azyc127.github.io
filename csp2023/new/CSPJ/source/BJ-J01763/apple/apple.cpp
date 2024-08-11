#include <bits/stdc++.h>

using namespace std;

int n, sum, id;
bool flag;

int main(){
        freopen("apple.in", "r", stdin);
        freopen("apple.out", "w", stdout);

        scanf("%d", &n);

        while((n - 1) / 3){
                int x = 1 + (n - 1) / 3;
                sum ++;
//              cout << (n - 1) % 3 << endl;
                if((n - 1) % 3 == 0 && !flag){
                        flag = true;
                        //cout << 's';
                        id = sum;
                }
                n -= x;
        }

        sum += n;
        if(!flag) id = sum;
        cout << sum << ' ' << id << endl;
        return 0; 
}

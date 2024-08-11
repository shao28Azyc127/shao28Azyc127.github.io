#include<bits/stdc++.h>
using namespace std;

long long n, day = 0, last = 0;
bool seq[1000000005];
bool flag = 1;

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    scanf("%d", &n);

    while(flag == 1){
        int cnt = 3;
        flag = 0;
        day++;
        for(int i=1; i<=n; i++){
            if(cnt == 3 && seq[i] == 0){
                if(i == n){
                    last = day;
                }
                seq[i] = 1;
                cnt = 1;
            }
            if(seq[i] == 0){
                cnt++;
                flag = 1;
            }
        }
    }
    printf("%d %d", day, last);

    return 0;
}

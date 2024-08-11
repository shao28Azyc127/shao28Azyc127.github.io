#include<bits/stdc++.h>
using namespace std;
const long long N = 1e9+5;

long long n, take_num, recent_num, ans1=0, ans2=0;
int break_num;
bool fetch[N]={false};

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    scanf("%lld", &n);
    take_num = 0;
    recent_num = 1;

    while (take_num <= n-1){

    break_num = 2;
    while (recent_num <= n){
        if (break_num == 2){
            while (fetch[recent_num] == true){
                recent_num++;
            }
            if (recent_num <= n){
                fetch[recent_num] = true;
                // printf("%lld ", recent_num);
                if (recent_num == n){
                    ans2 = ans1+1;
                }

                take_num++;
                recent_num++;
                break_num = 0;
            }
            else{
                break;
            }
        }

        if (recent_num <= n){
            if (fetch[recent_num] == true){
                recent_num++;
            }
            else{
                break_num++;
                recent_num++;
            }
        }
    }
    ans1++;

    recent_num = 1;
    while (fetch[recent_num] == true){
        recent_num++;
    }

    // printf("\n");

    }

    printf("%lld %lld", ans1, ans2);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool list1[10000];
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, list1_i, n_at;
    scanf("%d", &n);
    for (int day_=1; day_<=n; ++day_){
        list1_i=0;
        for (int i=0; i<n; ++i)
            if (list1[i]==0){
                if (list1_i%3==0){
                    list1[i]=1;
                    if (i==n-1) n_at=day_;
                }++list1_i;
            }
        if (list1_i==0){
            printf("%d %d", day_-1, n_at);
            break;
        }
    }
    return 0;
}

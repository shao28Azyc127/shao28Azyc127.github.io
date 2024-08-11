#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans,count1 = 0;
    cin >> n;
    int a[n+5],book[n+5],numbers[n+5],n1 = n;
    for(int i = 1;i<=n;i++){
        a[i] = i;
        book[i] = 0;
        numbers[i] = 0;
    }
    while(n){
        for(int i = 1;i <= n;i++){
            if(a[i] == 0){
                continue;
            }
            else{
                if(count1 == 3){
                    count1 = 0;
                }
                if(count1 == 0);
                    a[i] = 0;
                    book[i] = 0;
                    numbers[i] += 1;
                    ans += 1;
                }
            count1 += 1;
        }
        n -= 1;
        if(n == 0){
            break;
        }
    }
    cout << ans << " " << numbers[ans];
    return 0;
}
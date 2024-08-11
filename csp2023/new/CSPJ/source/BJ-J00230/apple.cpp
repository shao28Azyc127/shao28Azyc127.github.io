#include<bits/stdc++.h>
using namespace std;
int n, ans1, ans2;
bool ok;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf(" %d",&n);
    int k = n, i = 0;
    while(k != 0){
        if(k % 3 == 0) k = k - k / 3;
        else if(k % 3 == 2) k = k - k / 3 - 1;
        else{
            if(ok) k = k - k / 3 - 1;
            else{
                ok = true;
                ans2 = i + 1;
                k = k - k / 3 - 1;
            }
        }
        i++;
    }
    ans1 = i;
    printf("%d %d",ans1, ans2);
    return 0;
}

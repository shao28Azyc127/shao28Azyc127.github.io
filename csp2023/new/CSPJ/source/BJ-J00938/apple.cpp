#include<bits/stdc++.h>
using namespace std;

int n, x;
int ans = 0;
int main(){
        freopen("apple.in","r", stdin);
        freopen("apple.out", "w", stdout);

        cin >> n;
        x = n;
        bool flag = true;
        for(int i = 1; n > 0; i++){
                int y = n / 3, cnt = 0;
                if(n % 3 != 0) y += 1;

                for(int j = 0; j < y && flag; j++){
                        if(j == 0 && x % 3 == 1){
                                ans = i;
                                flag = false;
                        }
                        else if(x >( j * 3 + 1)){ 
                                cnt ++;
                        }
                        if(j == y - 1) x -= cnt;
                }
                n -= y;
                if(n == 0) cout << i << ' '<< ans << '\n';
        }
        return 0;
}
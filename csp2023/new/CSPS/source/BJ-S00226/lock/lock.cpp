#include <iostream>
#include <cstdio>
using namespace std;
struct locknode {
    int lock[5];
};

int main() {
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    locknode locks[n];
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<5;j++) {
            cin>>locks[i].lock[j];
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++) {
        for(int j = i + 1;j<n;j++) {
            bool flag = false,flag2 = true;
            for(int x = 0;x<5;x++) {
                if(locks[i].lock[x] == locks[j].lock[x]) {
                    if(flag) {
                        flag = false;
                        flag2 = false;
                    }
                    else if(flag2){
                        flag = true;
                    }
                    ans -= 9;
                }
            }
            if(flag) {
                ans-=10;
            }
            for(int x = 0;x<4;x+=2) {
                if(abs(locks[i].lock[x] - locks[i].lock[x+1]) == abs(locks[j].lock[x] - locks[j].lock[x+1])) {
                    ans -= 9;
                }
            }
        }
    }
    cout << ans << endl;
    ans+=81*n;
    cout << ans;
    return 0;
}
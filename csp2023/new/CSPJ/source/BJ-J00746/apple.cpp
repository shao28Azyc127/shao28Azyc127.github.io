#include<iostream>
#include<cstdio>
using namespace std;

bool vis[2000005];

int main (){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt = 0,round = 0,ans1 = 0,ans2 = 0;
    cin >> n;
    int a = n;
    while(a > 0){
        round++;
        cnt = 1;
        for (int i = 1;i <= n;i++){
            if (!vis[i]){
                if(cnt == 4) cnt = 1;
                if (cnt == 1){
                    if (i == n){
                        ans2 = round;
                    }
                    if (a == 1){
                        ans1 = round;
                    }
                    //cout << i << " ";
                    vis[i] = true;
                    a--;
                }

                cnt++;
            }
        }
        //cout <<endl;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}

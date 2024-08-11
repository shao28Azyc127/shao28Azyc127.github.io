#include <iostream>
#include <queue>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    queue <int> q;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    int ans1 = 0,ans2 = 1;
    while(!q.empty()){
        int x = q.size(),cnt = 2;
        for(int i = 1; i <= x; i++){
            if(cnt == 2){
                if(q.front() == n){
                    cout << ans1 << ' ';
               }
                q.pop();
                cnt = 0;
            }else{
                q.push(q.front());
                q.pop();
                cnt++;
            }
        }
        ans1++;
        ans2++;
    }
    cout << ans2;
    return 0;
}

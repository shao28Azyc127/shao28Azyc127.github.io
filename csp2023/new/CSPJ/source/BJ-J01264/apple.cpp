#include<bits/stdc++.h>
using namespace std;
int n;
queue<int> se;
int ans1,ans2;
int y;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    y = n;
    for(int i = 1;i <= n;i++){
        se.push(i);
    }
    while(y){
        while(!se.empty()){
            ans1++;
            queue<int> tex;
            queue<int> nz;
            int p = 1;
            while(se.size()){
                if(p % 3 == 1){
                    if(se.front() == n){
                        ans2 = ans1;
                    }
                    se.pop();
                    y--;
                }else{
                    tex.push(se.front());
                    se.pop();
                }
                p++;
            }
            while(tex.size()){
                se.push(tex.front());
                tex.pop();
            }
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}

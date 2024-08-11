#include <bits/stdc++.h>

using namespace std;
string a;int n;
struct item{
    int cs;
    char nr;
};
stack<item> h;
void print(){
}
int main()
{
     freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin >> n;
    cin >> a;
    item kkk;
    kkk.nr = NULL;
    kkk.cs = 0;
    h.push(kkk);
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(h.top().nr != NULL){
            kkk = h.top();
            if(kkk.nr == a[i]){
                h.pop();
                ans += 1 + h.top().cs;
                kkk = h.top();
                kkk.cs++;
                h.pop();
                h.push(kkk);
            }
            else{
                kkk.nr = a[i];
                kkk.cs = 0;
                h.push(kkk);
            }
        }
        else{
            kkk.nr = a[i];
            kkk.cs = 0;
            h.push(kkk);
        }
    }
    cout << ans;
    return 0;
}

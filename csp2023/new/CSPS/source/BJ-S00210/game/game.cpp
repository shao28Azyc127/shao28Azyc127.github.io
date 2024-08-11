#include <bits/stdc++.h>
using namespace std;
struct node{
    char c;
    int id;
};
stack<node> s;
int n,ans;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    char tmp;
    cin>>tmp;
    int p=1;
    node tm;
    tm.c=tmp;
    tm.id=p;
    s.push(tm);
    for (int i=2;i<=n;i++){

        cin>>tmp;
        tm.id=i;
        tm.c=tmp;
        node t;
        if (!s.empty()){
            t=s.top();
        }else{
            s.push(tm);
            continue;
        }

        if (tmp==t.c){
            s.pop();
            if (tm.id==t.id+1){
                ans++;
            }else{
                if (s.empty()){
                    ans++;
                }
            }

        }else{
            s.push(tm);
        }
    }
    if (s.empty()){
        ans++;
    }
    cout<<ans;
    return 0;
}

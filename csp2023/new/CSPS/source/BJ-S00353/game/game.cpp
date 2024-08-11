#include<bits/stdc++.h>
using namespace std;
char a[200005];
int ans;

bool check(int beg,int lg){
    stack<int> s;
    for(int i=beg;i<=beg+lg-1;i++){
        if(s.empty()) s.push(i);
        else if(a[s.top()]==a[i]) s.pop();
        else s.push(i);
    }
    if(s.empty()) return 1;
    else return 0;
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i+=2){
        for(int j=1;j<=n-i+1;j++){
            if(check(j,i)){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

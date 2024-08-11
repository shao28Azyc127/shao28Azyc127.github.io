#include<bits/stdc++.h>
using namespace std;
stack<int> s;
char a[200005];
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    long long ans=0;
    cin>>n;
    cin>>a;
    //if(n<=8000){
        for(int i=0;i<n;i++){
            while(!s.empty()) s.pop();
            for(int j=i;j<n;j++){
                if(!s.empty()&&a[j]==s.top()) s.pop();
                else s.push(a[j]);
                if(s.empty()) ans++;
            }
        }
        cout<<ans;
    //}
    
    return 0;
}

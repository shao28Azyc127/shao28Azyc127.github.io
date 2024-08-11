#include<bits/stdc++.h>
using namespace std;
int n;
int tmp;
stack<char> s;
string zhan_wei;
char a[2000005];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    int ans=0;
    getline(cin,zhan_wei);
    for(int i=1;i<=n;i++){
        scanf("%c",&a[i]);
    }
    s.push(a[1]);
    for(int i=2;i<=n;i++){
        if(!s.empty()&&a[i]==s.top()){
            ans++;
            s.pop();
            //cout<<i<<"->"<<a[i]<<endl;
        }
        else{
            s.push(a[i]);
        }

    }
    if(s.empty())ans++;
    cout<<ans;
    return 0;
}

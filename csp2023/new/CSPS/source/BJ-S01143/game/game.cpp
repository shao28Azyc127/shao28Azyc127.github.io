#include<iostream>//50pts
#include<cstdio>
#include<stack>
using namespace std;
char c[2000006];
stack<char>s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        while(!s.empty())s.pop();
        for(int j=i;j<=n;j++){
            if(!s.empty()&&s.top()==c[j])s.pop();
            else s.push(c[j]);
            if(s.empty())++ans;
        }
    }
    cout<<ans;
    return 0;
}

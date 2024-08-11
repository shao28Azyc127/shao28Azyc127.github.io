#include<bits/stdc++.h>
using namespace std;
struct node{
    int val,cnt;
};
stack<node> s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,tmp=0,ans=0;
    string str;
    scanf("%d",&n);
    cin>>str;
    for(int i=0;i<n;i++){
        if(s.size() && s.top().val==str[i]){
            ans+=s.top().cnt+1;
            tmp=s.top().cnt+1;
            s.pop();
        } else {
            s.push(node{str[i],tmp});
            tmp=0;
        }
    }
    printf("%d",ans);
    return 0;
}

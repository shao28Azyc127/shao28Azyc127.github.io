#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,ans;
char s[N];
char st[N];
int top=0;
bool check(int l,int r){
    top=0;
    for(int i=l;i<=r;i++){
        if(top&&st[top]==s[i]) top--;
        else st[++top]=s[i];
    }
    return top==0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    scanf("%s",&s);
    for(int l=0;l<n;l++) for(int r=l+1;r<n;r++) if(check(l,r)) ans++;
    cout<<ans<<endl;
    return 0;
}

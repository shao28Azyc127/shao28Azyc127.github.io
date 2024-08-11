#include<bits/stdc++.h>
using namespace std;
int n,cnt,book[2000010],cnt1;
struct node{
    int l,r;
}match1[1000010];
long long ans;
string s;
void match(int x,int y){
    cnt++;
    int tx=x,ty=y;
    while(x>=1&&y<=n){
        if(s[x]==s[y]){
            x--;
            y++;
            ans++;
        }
        else{
            if(s[x]==s[x-1]) x-=2,ans++;
            if(s[y]==s[y+1]) y+=2,ans++;
            else break;
        }
    }
    match1[++cnt1].l=x+1,match1[cnt1].r=y-1;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        if(s[i]==s[i+1]) match(i,i+1);
    }
    int x=1;
    for(int i=1;i<=cnt1;i++){
        if(match1[i].r+1==match1[i+1].l) x++;
        else{
            ans+=x*(x-1)/2;
            x=1;
        }
    }
    cout<<ans;
    return 0;
}

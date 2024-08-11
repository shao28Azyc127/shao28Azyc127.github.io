#include<bits/stdc++.h>
using namespace std;
char s[2000005];
long long ans,n,cnt,x;
struct node{
    int last;
    int next;
    char a;
}t[2000005];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            t[i-1].last=i-1;
            t[i-1].a='0';
            t[i-1].next=i;
            for(int k=i;k<=j+1;k++){
                t[k].a=s[k];
                t[k].last=k-1;
                t[k].next=k+1;
            }
            x=i;
            while(t[x].next!=j+1){
                if(t[x].a==t[t[x].next].a){
                   x=t[x].last;
                   t[x].next=t[t[t[x].next].next].next;
                   x=t[x].next;
                   t[x].last=t[t[t[x].last].last].last;
                   x=t[t[t[x].last].last].last;
                }
                else{
                    x=t[x].next;
                }
            }
            if(t[i-1].next==j+1){
                ans++;
            }
        }
    }
    cout<<ans;
}

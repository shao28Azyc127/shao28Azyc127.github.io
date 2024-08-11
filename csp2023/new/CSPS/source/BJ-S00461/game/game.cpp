#include<bits/stdc++.h>
#define maxn 8005
using namespace std;
int n;
string s;
struct Node{
    int u,v;
}nd[maxn];
int a[maxn];
int cnt;
int ans;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    cin>>s;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            int l=i,r=i+1,f=0;
            cnt++;
            while(s[l]==s[r]&&l>=0&&r<n){
                ans++;
                l--;
                r++;
            }
            nd[cnt].u=l+1;
            nd[cnt].v=r-1;
        }
    }
    for(int i=1;i<=cnt;i++){
        for(int j=i+1;j<=cnt;j++){
            if(nd[i].v+1==nd[j].u){
                a[j]=a[i]+1;
                ans+=a[j];
            }
        }
    }
    printf("%d",ans);
}

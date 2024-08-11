#include <bits/stdc++.h>
using namespace std;
int n,a[200010],ans;
bool book[200010];
void solve(){
    for(int i=2;i<=n;i+=2){
        for(int j=1;j+i-1<=n;j++){
            for(int k=1;k<=10;k++) book[k]=0;
            int sum=0;
            while(1){
                bool fff=0;
                int last=-1,lasti=-1;
                for(int k=j;k<=j+i-1;k++){
                    if(book[k]) continue;
                    if(a[k]!=last){
                        last=a[k];
                        lasti=k;
                        continue;
                    }
                    if(a[k]==last){
                        book[k]=book[lasti]=1;
                        sum++;
                        fff=1;
                    }
                }
                if(!fff) break;
            }
            if(sum==i/2) ans++;
        }
    }
    printf("%d",ans);
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    char c=getchar();int i=0;
    c=getchar();
    while(c>='a'&&c<='z'){
        a[++i]=c-'a'+1;
        c=getchar();
    }
    if(n<=10){
        solve();
        return 0;
    }
    while(1){
        bool fff=0;
        int last=-1,lasti=-1;
        for(int i=1;i<=n;i++){
            if(book[i]) continue;
            if(a[i]!=last){
                last=a[i];
                lasti=i;
                continue;
            }
            if(a[i]==last){
                book[i]=book[lasti]=1;
                ans++;
                fff=1;
            }
        }
        if(!fff) break;
    }
    printf("%d",ans);
    return 0;
}

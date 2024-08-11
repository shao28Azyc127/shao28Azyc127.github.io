#include<bits/stdc++.h>
using namespace std;
int n,ans;
const int M=2e6+7;
bool a[M];
char c[M];
bool work(int x,int y){
    memset(a,1,sizeof(a));
    int cnt=0,p=-1;
    while(p!=cnt){
        p=cnt;
        for(int i=x;i<=y;){
            if(a[i]){
                int j;
                for(j=i+1;j<=y;j++){
                    if(a[j]){
                        if(c[i]==c[j]){
                            a[i]=0;
                            a[j]=0;
                            cnt+=2;
                            break;
                        }
                        else break;
                    }
                }
                i=j;
            }
            else i++;
        }
    }
    if(cnt==y-x+1) return true;
    else return false;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if((j-i)%2==0) continue;
            if(work(i,j)) ans++;
        }
    }
    printf("%d",ans);
    return 0;
}

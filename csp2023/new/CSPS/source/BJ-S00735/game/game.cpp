#include<cstdio>
using namespace std;
const int N=2e6+5,L=8005;
int n,ans;
char str[N],lfull[N],rfull[N];
bool mp[L][L];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d%s",&n,str+1);
    for(int i=2;i<=n;i++){
        if(str[i]==str[i-1]){
            mp[i-1][i]=true;
            int l=i-1,r=i;
            ans++;
            while(true){
                l--;
                r++;
                if(str[l]!=str[r])break;
                mp[l][r]=true;
                ans++;
            }
            lfull[i]=l+1;
            rfull[i]=r-1;
        }
    }
    if(n>=10000){
        printf("%d\n",ans);
        return 0;
    }
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++){
            if(rfull[i]==0||lfull[j]==0)continue;
            if(rfull[i]+1==lfull[j]&&!mp[lfull[i]][rfull[j]]){
                mp[lfull[i]][rfull[j]]=true;
                ans++;
            }
        }

    printf("%d\n",ans);
    return 0;
}
//Workingmen of all countries, unite!

#include<bits/stdc++.h>
using namespace std;
char s[2000010];
int n, ans;
int cnt[30];
bool check(int x,int y){
    int cnt2=0, cnt4=0;
    for(int i=x;i<=y;i++){
        if(s[i]=='A') cnt4++;
    }
    if(cnt4==y-x+1) return true;
    for(int i=x;i<=y;i++){
        while(s[i]=='A'){
            i++;
        }
        int j=i;
        i++;
        while(s[i]=='A'){
            i++;
        }
        if(s[i]==s[j]&&s[i]!='A'){
            cnt2++;
            s[i]='A';
            s[j]='A';
        }
    }
    if(cnt2==0) return false;
    return check(x,y);
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d", &n);
    scanf("%s", s+1);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            bool flag=true;
            for(int k=i;k<=j;k++){
                cnt[s[k]-'a'+1]++;
            }
            for(int k=1;k<=30;k++){
                if(cnt[k]%2!=0) {
                    flag=false;
                }
            }
            if(flag==false) continue;
            if(check(i,j)){
                /*for(int k=i;k<=j;k++){
                    printf("%c", s[k]);
                }*/
                ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}

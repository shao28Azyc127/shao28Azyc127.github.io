#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
void read(int &number){
    number=0;
    bool fuhao=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')fuhao=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        number*=10;
        number+=ch-'0';
        ch=getchar();
    }
    if(fuhao)number=-number;
    return;
}
void lread(long long &number){
    number=0;
    bool fuhao=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')fuhao=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        number*=10;
        number+=ch-'0';
        ch=getchar();
    }
    if(fuhao)number=-number;
    return;
}
void print(LL number){
    if(number<0){
        putchar('-');
        number=-number;
    }
    if(number>9){
        print(number/10);
    }
    putchar((number%10)^48);
}
const int N=2e6+9;
string ss;
int s[N];
int f[N][26];
LL dp[N];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,res;
    scanf("%d",&n);
    cin>>ss;
    LL ans=0;
    for(int i=0;i<n;i++)s[i+1]=ss[i]-'a';
    f[n][s[n]]=n;
    for(int i=n-1;i;i--){
        res=f[i+1][s[i]];
        f[i][s[i]]=i;
        if(res>0){
            dp[i]=dp[res+1]+1;
            for(int j=0;j<=25;j++){
                if(j!=s[i])f[i][j]=f[res+1][j];
            }
        }
    }
    for(int i=1;i<n;i++)ans+=dp[i];
    print(ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int NR=3e3+10;
int n,m,ans[NR],minp,minp2,buc[200];
char str[NR][NR],s1[NR][NR],s2[NR][NR];

signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf(" %s",str[i]+1);
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=m;j++)
            
    for(int i=1;i<=n;i++){
        memset(buc,0,sizeof(buc));
        for(int j=1;j<=m;j++)buc[(int)str[i][j]-'a'+1]++;
        int len=0;
        for(int j=26;j>=1;j--)
            for(int x=1;x<=buc[j];x++)s1[i][++len]='a'-1+j;
    }
    for(int i=1;i<=n;i++){
        memset(buc,0,sizeof(buc));
        for(int j=1;j<=m;j++)buc[(int)str[i][j]-'a'+1]++;
        int len=0;
        for(int j=1;j<=26;j++)
            for(int x=1;x<=buc[j];x++)s2[i][++len]='a'-1+j;
    }
    minp=1;
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;j<=m;j++){
            if(s1[i][j]>s1[minp][j]){
                flag=0;
                break;
            }
            if(s1[i][j]<s1[minp][j])break;
        }
        if(flag)minp=i;
    }
    for(int i=1;i<=n;i++)
        if(i!=minp){
            if(!minp2){
                minp2=i;
                continue;
            }
            bool flag=1;
            for(int j=1;j<=m;j++){
                if(s1[i][j]>s1[minp2][j]){
                    flag=0;
                    break;
                }
                if(s1[i][j]<s1[minp2][j])break;
            }
            if(flag)minp2=i;
        }
    for(int i=1;i<=n;i++){
        bool flag=0;
        if(i!=minp){
            for(int j=1;j<=m;j++){
                if(s2[i][j]>s1[minp][j])break;
                if(s2[i][j]<s1[minp][j]){
                    flag=1;
                    break;
                }
            }
        }
        else{
            for(int j=1;j<=m;j++){
                if(s2[i][j]>s1[minp2][j])break;
                if(s2[i][j]<s1[minp2][j]){
                    flag=1;
                    break;
                }
            }
        }
        // for(int j=1;j<=m;j++)printf("%c",s2[i][j]);puts("");
        if(flag)putchar('1');
        else putchar('0');
    }
    puts("");
    return 0;
}
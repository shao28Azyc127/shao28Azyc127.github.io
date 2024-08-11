#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n;
char s[N];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d%s",&n,s+1);
    int ans=0;
    for(int i=1;i<=n-2+1;i++){
        for(int j=i+2-1;j<=n;j+=2){
            string prt="",tmp="";
            for(int id=i;id<=j;id++){tmp=tmp+s[id];}
            int ok=0;prt=tmp;
            while(1){
                string pro="";
                int flag=0,len=tmp.size();
                for(int id=0;id<len;id++){
                    if(tmp[id]==tmp[id+1]) id+=1,flag=1;
                    else pro=pro+tmp[id];
                }
                if(pro==""){ok=1;break;}
                if(flag==0){break;}
                tmp=pro;
            }
            if(ok==1) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
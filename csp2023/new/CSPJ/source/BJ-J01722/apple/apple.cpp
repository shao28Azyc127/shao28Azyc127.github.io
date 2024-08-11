#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000000005;
int n,sum=0,now=3,temp=0,ans=-1;
bool flag[MAXN];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    memset(flag,true,sizeof(flag));
    while(sum<n){
        temp++;
        now=3;
        for(int i=1;i<=n;i++){
            if(flag[i]){
                if(now==3){
                    flag[i]=false;
                    sum++;
                    now=1;
                }else now++;
            }
        }if(!flag[n]&&ans==-1)ans=temp;
    }printf("%d %d\n",temp,ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
map<int,int> pp;
int main(){
    int n;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    double n1=n;
    int ans1=0;
    while(n1>=3){
        n1-=ceil(n1/3);
        ans1++;
    }
    ans1+=n1;
    int les=n,ans2=0,sta=1;
    while(les>0){
        ans2++;
        for(int i=1;i<=n;i++){
            if(pp[i]==0){
                 sta=i;
                 break;
            }
        }
        if(sta==n){
            printf("%d %d",ans1,ans2);
            return 0;
        }
        for(int i=sta;i<=n;){
            int cnt=0;
            if(i==sta) pp[i]=1;
            while(cnt<3){
                i++;
                if(pp[i]==0) cnt++;
            }
            pp[i]=1;
            les--;
            if(i==n){
                printf("%d %d",ans1,ans2);
                return 0;
            }
        }
    }
    return 0;
}
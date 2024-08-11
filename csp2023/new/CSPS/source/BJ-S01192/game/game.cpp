#include<bits/stdc++.h>
using namespace std;
int t[1000005];
char s[100005];
int numc[1000005];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    scanf("%d",&n);
    cin>>s;
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            memset(numc,0,sizeof(numc));
            for(int k=i;k<=j;k++){
                numc[int(s[k]-'a')]++;
            }
            int flag=0;
            for(int k=0;k<=25;k++){
                if(numc[k]%2!=0){
                   flag=1;
                }
            }
            if(flag==1){
                continue;
            }
            int l=j-i+1;
            int tof=1;
            while(l){
                int next=i+1;
                int flag=0;
                memset(t,0,sizeof(t));
                for(int k=i;k<j;k++){
                    while(t[next]){
                        next++;
                    }
                    if(s[i]==s[next]){
                        t[i]=1;
                        t[next]=1;
                        flag=1;
                        continue;
                    }
                    next++;
                }
                if(flag==0){
                    tof=0;
                    break;
                }
                l--;
            }
            sum+=tof;
        }
    }
    cout<<sum;
    return 0;
}

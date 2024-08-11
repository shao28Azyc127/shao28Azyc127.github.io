#include<bits/stdc++.h>
using namespace std;
int arr[15][15],brr[15],cnt[100005],ans;
bool vis[100005];
int hs(){
    int res=0;
    for(int i=1;i<=5;i++){
        res=res*10+brr[i];
    }
    return res;
}
void add(){
    int has=hs();
    if(!vis[has]){
        vis[has]=1;
        cnt[has]++;
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int T,c1=0,c2=0;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        for(int j=0;j<=100000;j++){
            vis[j]=0;
        }
        for(int j=1;j<=5;j++){
            scanf("%d",&arr[i][j]);
            brr[j]=arr[i][j];
        }
        for(int j=1;j<=5;j++){
            int t=brr[j];
            for(int k=0;k<=9;k++){
                if(k==t) continue;
                brr[j]=k;
                add();
                c1++;
            }
            brr[j]=t;
        }
        for(int j=1;j<=4;j++){
            int t1=brr[j],t2=brr[j+1];
            for(int k=1;k<=9;k++){
                brr[j]=(t1+k)%10;
                brr[j+1]=(t2+k)%10;
                add();
                c2++;
            }
            brr[j]=t1;
            brr[j+1]=t2;
        }
    }
    for(int i=0;i<100000;i++){
        if(cnt[i]==T){
            ans++;
        }
    }
    //cout<<c1<<" "<<c2<<endl;
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

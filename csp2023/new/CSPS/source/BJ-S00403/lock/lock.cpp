#include<iostream>
#include<cstdio>
using namespace std;
int n;
struct lnum{
    int cnt=0;
    int lastest=0;
}vis[100001];
int next(int s){
    if(s==9)return 0;
    return s+1;
}
int last(int s){
    if(s==0)return 9;
    return s-1;
}
int lock[10][6];
void save(int l[],int i){
    int r=0,coun=10000;
    for(int i=1;i<=5;i++){
        r=r+coun*l[i];
        coun/=10;
    }
    //printf("%d\n",r);
    if(vis[r].lastest!=i){
        vis[r].cnt++;
        vis[r].lastest=i;
    }
    return;
}
bool check(int i){
    if(vis[i].cnt==n){
        return 1;
    }
    return 0;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&lock[i][j]);
        }
        for(int j=1;j<=5;j++){
            lock[i][j]=next(lock[i][j]);
            for(int k=1;k<=9;k++){
                save(lock[i],i);
                lock[i][j]=next(lock[i][j]);
            }
        }
        for(int j=1;j<=4;j++){
            lock[i][j]=next(lock[i][j]);
            lock[i][j+1]=next(lock[i][j+1]);
            for(int k=1;k<=9;k++){
                save(lock[i],i);
                lock[i][j]=next(lock[i][j]);
                lock[i][j+1]=next(lock[i][j+1]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<100000;i++){
        if(check(i)){
            //printf("%d\n",i);
            ans++;
        }
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

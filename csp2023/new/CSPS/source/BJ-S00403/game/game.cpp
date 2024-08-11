#include<iostream>
#include<cstdio>
#include<stack>
#define maxn 100002
using namespace std;
struct str{
    int fa;
    int len=0;
}vis[maxn<<2];
long long ans;
struct node{
    char c;
    int addr;
};
stack<node>st;
int n;
void add(int l,int r){
    for(int i=l;i<=r;i++){
        if(vis[i].fa==i){
            vis[i].fa=l;
            i=i+vis[i].len;
        }
    }
    vis[l].len=r-l;
    return;
}
int find_fa(int i){
    if(vis[i].fa==i)return i;
    else return vis[i].fa=find_fa(vis[i].fa);
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        vis[i]={i,0};
    }
    for(int i=0;i<=n;i++){
        char in;
        scanf("%c",&in);
        if(st.empty()){
            st.push({in,i});
        }
        else{
            node head=st.top();
            if(head.c!=in){
                st.push({in,i});
            }else{
                st.pop();
                add(head.addr,i);
                //printf("@");
                //printf("%c\n",in);
                ans++;
            }
        }
    }
    long long cnt=0;
    for(int i=0;i<=n;i++){
        if(vis[i].fa==i)continue;
        vis[i].fa=find_fa(i);
    }
    for(int i=0;i<=n;i++){
        if(vis[i].fa==i&&vis[i].len>0){
            //printf("$");
            ans+=cnt;
            cnt++;
            i=i+vis[i].len;
        }else{
            cnt=0;
        }
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
const int M = 2e4+10,N = 1e4+10;
int n,m,v;
struct node{
    int to,next,len;
}a[M];
int pre[N],k;
int q[N][2];
void add(int u,int v,int len){
    k++;
    a[k].to = v;
    a[k].len = len;
    a[k].next = pre[u];
    pre[u] = k;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&v);
    int x,y,len;
    int ss = 0;
    int maxn = 0;
    for(int i = 1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&len);
        add(x,y,len);
        if(len==0)ss++;
        maxn = max(maxn,len);
    }
    if(ss==m){
        int h = 1,t = 1;
        q[1][0] = 1;
        q[1][1] = 0;
        while(h<=t){
            int p = q[h][0];
            for(int i = pre[p];i;i = a[i].next){
                int to = a[i].to;
                t++;
                q[t][0] = to;
                q[t][1] = q[h][1]+1;
                if(q[t][0]==n){
                    int res = q[t][1]/v;
                    if(q[t][1]%v!=0)res++;
                    printf("%d",res*v);
                    return 0;
                }
            }
            h++;
        }
        printf("-1");
        return 0;
    }else if(v==1){
        for(int i = 1;i<=maxn;i++){
            int h = 1,t = 1;
            q[1][0] = 1;
            q[1][1] = i;
            while(h<=t){
                int p = q[h][0];
                for(int i = pre[p];i;i = a[i].next){
                    int to = a[i].to;
                    if(a[i].len<q[h][1]){
                        t++;
                        q[t][0] = to;
                        q[t][1] = q[h][1]+1;
                        //cout<<to<<endl;
                        if(q[t][0]==n){
                            printf("%d",q[t][1]);
                            return 0;
                        }
                    }
                }
                h++;
            }
        }
        printf("-1");
        return 0;
    }else{
        for(int i = 1;i<=maxn;i++){
            int h = 1,t = 1;
            q[1][0] = 1;
            q[1][1] = i;
            while(h<=t){
                int p = q[h][0];
                for(int i = pre[p];i;i = a[i].next){
                    int to = a[i].to;
                    if(a[i].len<q[h][1]){
                        t++;
                        q[t][0] = to;
                        q[t][1] = q[h][1]+1;
                        //cout<<to<<endl;
                        if(q[t][0]==n){
                            int res = q[t][1]/v;
                            if(q[t][1]%v!=0)res++;
                            printf("%d",res*v);
                            return 0;
                        }
                    }
                }
                h++;
            }
        }
        printf("-1");
        return 0;
    }
    printf("-1");

    return 0;
}

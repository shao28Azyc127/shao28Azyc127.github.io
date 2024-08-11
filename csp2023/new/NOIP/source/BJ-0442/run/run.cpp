#include<bits/stdc++.h>
using namespace std;

int c,t,n,m,k,d,p,ans;
bool rd[1010],trd[1010];
struct node{
    int x,y,v;
}arr[110];

bool cmp(node a,node b){
    if(a.v==b.v){
        if(a.y==b.y){
            if(a.x==b.x){
                return true;
            }
            return a.x<b.x;
        }
        return a.y<b.y;
    }
    return a.v>b.v;
}

void qread(int& in){
    in=0;
    char ch=getchar();
    while(!isdigit(ch)){
        ch=getchar();
    }
    do{
        in=in*10+(ch-'0');
        ch=getchar();
    }while(isdigit(ch));
}

signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(false);
    qread(c);
    qread(t);
    if(c<=9){
        for(int i=1;i<=t;i=-(~i)){
            qread(n);
            qread(m);
            qread(k);
            qread(d);
            p=1;
            for(int j=1;j<=m;j=-(~j),p=-(~p)){
                qread(arr[p].x);
                qread(arr[p].y);
                qread(arr[p].v);
                if(arr[p].y>k||arr[p].y*d>=arr[p].v){
                    p--;
                }
            }
            sort(arr+1,arr+p+1,cmp);
            for(int j=1;j<=p;j=-(~j)){
                memcpy(rd,trd,sizeof(rd));
                int ydis=0;
                for(int k=arr[j].x;k>=arr[j].x-arr[j].y+1;k--){
                    if(!trd[k]){
                        trd[k]=1;
                        ydis++;
                    }
                }
                int cnt=0,pos=arr[j].x;
                while(trd[pos]&&pos>=1){
                    cnt=-(~cnt);
                    pos--;
                }
                if(cnt>k){
                    continue;
                }
                else{
                    memcpy(trd,rd,sizeof(rd));
                    ans+=(arr[j].v-ydis*d);
                }
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}

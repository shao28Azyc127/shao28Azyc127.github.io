#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int M=31;
const int N=3005;
char c[N][N];
int a[N],aa[N],a1[N][N],k[N],a0[N][N],n,m;
ull b[N],s[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>c[i][j];
            k[j]=c[i][j]-'a'+1;
        }
        sort(k+1,k+1+m);
        for(int j = 1;j<=m;j++) a1[i][j]=k[j],a0[i][j]=k[m-j+1];
    }
    if(n==1){
        printf("1");
        return 0;
    }
    if(n<=15&&m<=2){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            aa[j]=a[j]=c[i][j]-'a'+1;
        }
        sort(a+1,a+1+m);
        sort(aa+1,aa+1+m,cmp);
        for(int j = 1;j<=m;j++){
            s[i]=s[i]*M+a[j];
            b[i]=b[i]*M+aa[j];
        }
    }
    for(int i = 1;i<=n;i++){
        int flag=1;
        for(int j = 1;j<=n;j++){
            if(i==j) continue;
            if(s[i]>=b[j]){
                flag=0;
                break;
            }
        }
        if(flag) printf("1");
        else printf("0");
    }return 0;}
    if(n<=300&&m<=300){
        for(int i = 1;i<=n;i++){
            int flag=0;
            for(int j = 1;j<=n;j++){
                if(i==j) continue;
                int q=0;
                for(int kk = 1;kk<=m;kk++){
                    if(a1[i][kk]>a0[j][kk]) break;
                    if(a1[i][kk]<a0[j][kk]){
                        q=1;
                        break;
                    }
                }
                if(!q){
                    flag=1;
                    break;
                }
            }
            if(!flag) printf("1");
            else printf("0");
        }
        return 0;
    }
    int id=1;
    for(int i = 2;i<=n;i++){
        int q=0;
        for(int kk = 1;kk<=m;kk++){
            if(a0[i][kk]>a0[id][kk]) break;
            if(a0[i][kk]<a0[id][kk]){
                q=1;
                break;
            }
        }
        if(q) id=i;
    }
    for(int i = 1;i<=n;i++){
        if(id!=i){
            int q=0;
            for(int kk = 1;kk<=m;kk++){
                if(a1[i][kk]>a0[id][kk]) break;
                if(a1[i][kk]<a0[id][kk]){
                    q=1;
                    break;
                }
            }
            if(q) printf("1");
            else printf("0");
        }
        else{
            int flag=0;
            for(int j = 1;j<=n;j++){
                if(i==j) continue;
                int q=0;
                for(int kk = 1;kk<=m;kk++){
                    if(a1[i][kk]>a0[j][kk]) break;
                    if(a1[i][kk]<a0[j][kk]){
                        q=1;
                        break;
                    }
                }
                if(!q){
                    flag=1;
                    break;
                }
            }
            if(flag) printf("0");
            else printf("1");
        }
    }
    return 0;
}

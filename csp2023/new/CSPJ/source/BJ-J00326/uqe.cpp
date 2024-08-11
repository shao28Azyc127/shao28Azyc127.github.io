#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c,s[2010],len;
bool f[2010];
void yue(int x,int y){
    if(x==0){
        printf("0\n");
        return;
    }
    if(y==0){
        printf("NO\n");
        return;
    }
    if(x<0&&y>=0||x>=0&&y<0){
        printf("-");
        x=abs(x);
        y=abs(y);
    }
    for(int i = 1;i <= len;i++){
        while(x%s[i]==0&&y%s[i]==0){
            x/=s[i];
            y/=s[i];
        }
    }
    if(y==1){
        printf("%d\n",x);
        return;
    }
    printf("%d/%d",x,y);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    f[1]=true;
    for(int i = 1;i <= 2000;i++){
        if(!f[i]){
            s[++len]=i;
            for(int j = 1;j <= 2000/i;j++){
                f[i*j]=true;
            }
        }
    }
    scanf("%d%d",&t,&m);
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        int k=b*b-4*a*c;
        if(k<0) printf("NO\n");
        else{
            int x=sqrt(k);
            if(x*x==k){
                int y=-b+x;
                yue(y,2*a);
            }
        }
    }
}

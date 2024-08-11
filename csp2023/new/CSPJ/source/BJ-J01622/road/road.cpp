#include<iostream>
using namespace std;
int i,j,n,d,s[1000001],p[1000001],lo=0,m=0,c[1000001],cn,cp,t=0;
void fi(int k){
    cn=1000001;
    t++;
    for(int i=1;i<=k;i++){
        if(p[i]<cn) {
            cn=p[i];
            cp=i;
        }
    }
    c[t]=cp;
    if(cp==1){
        return ;
    }else{
        fi(cp-1);
    }
}
int se(int q){
    for(int i=q-1;i>=1;i--){
            m+=((s[c[i]]-s[c[i+1]]-lo*d)/d+1)*p[c[i+1]];
            lo+=(s[c[i]]-s[c[i+1]]-lo*d)/d+1-(s[c[i]]-s[c[i+1]])/4;
    }
    return m;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    s[1]=0;
    for(i=2;i<=n;i++){
        scanf("%d",&s[i]);
        s[i]+=s[i-1];
    }
    for(i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    fi(n);
    if(c[t]!=n) c[t+1]=n;
    printf("%d",se(t));
    return 0;
}
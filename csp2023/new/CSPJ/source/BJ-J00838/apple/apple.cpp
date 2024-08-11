#include<cstdio>
using namespace std;
int min(int a,int b){return a<b?a:b;}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,i=0,ans=0x7fffffff;
    scanf("%d",&n);
    while(n!=0){
        i++;
        if(n%3==1)ans=min(ans,i);
        if(n%3==0)n=n/3*2;
        else n=n-(n/3+1);

    }
    printf("%d %d",i,ans);
    return 0;
}

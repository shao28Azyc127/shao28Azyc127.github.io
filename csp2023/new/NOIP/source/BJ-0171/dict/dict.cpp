#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3e3+5;
int n,m;
char a[N],mx[N],mn[N];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",a+1);
        mn[i]='z'+1;
        for(int j=1;j<=m;j++)mx[i]=max(mx[i],a[j]),mn[i]=min(mn[i],a[j]);
    }
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(mn[i]>=mx[j]){
                flag=false;
                break;
            }
        }
        if(!flag)printf("0");
        else printf("1");
    }
    puts("");
    return 0;
}
//Workingmen of all countries, unite!
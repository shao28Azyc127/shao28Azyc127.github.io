#include<bits/stdc++.h>
using namespace std;
struct station{
    int dis,price;
};
station s[100001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,sum=0,past=1,ans=0;
    double d,left=0.0;
    s[1].dis=0;
    scanf("%d %lf",&n,&d);
    for(int i=2;i<=n;i++){
        scanf("%d",&s[i].dis);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i].price);
        sum+=s[i].dis;
        if(s[i].price<s[past].price||i==n){
            ans+=int(ceil(double(sum)/d-left))*s[past].price;//支付上一段路的费用
            left=ceil(double(sum)/d-left)-(double(sum)/d-left);
            //printf("Chtholly %d %d %d %d %lf %lf %lf\n",ans,past,sum,int(ceil(double(sum)/d-left)),double(sum)/d-left,d,left);
            sum=0;
            past=i;
        }
    }
    printf("%d",ans);
    return 0;
}

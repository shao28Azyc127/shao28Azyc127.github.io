#include<cstdio>
#include<iostream>
using namespace std;
int day[100001],y[100001],bao[100001],a,b,d,cnt,i;

using namespace std;
int main(){
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
scanf("%d",&a);
b=a;
for(i=1;i<=a;i++){
    y[i]++;
}
while(a>=0){
    i=1;
    d=1;
    while(y[i]==0){
        i++;
    }

    bao[i]=d;
    y[i]=0;
    a--;

    cnt=0;
    while(cnt<=2&&i<=b){
            i++;
        if(y[i]>0){
            cnt++;
        }
        if(cnt==2){
            bao[i]=d;
            y[i]=0;
            a--;
        }
        cnt=0;
    }
    d++;



}
printf("%d %d",d,bao[d]);


return 0;


}

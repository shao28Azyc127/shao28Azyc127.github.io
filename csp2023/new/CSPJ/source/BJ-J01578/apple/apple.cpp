#include<bits/stdc++.h>
using namespace std;
bool app[100010];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    memset(app,1,sizeof(app));
    int num,day=1,nday,i=1;
    scanf("%d",&num);
    int n=num;
    while(n!=0)
    {
        if(app[i])
        {
            app[i]=0;
            n--;
        }
        else{
            continue;
            i++;
        }
        if(i==num)nday=day;
        i+=3;
        if(i>n){
            i=1;
             day++;
        }
    }
    printf("%d %d",day,nday);
    return 0;
}

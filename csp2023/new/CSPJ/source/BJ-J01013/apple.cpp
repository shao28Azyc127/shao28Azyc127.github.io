//apple.cpp
#include <iostream>

using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int all,cnt=0,ans=0;
    bool flag=false;
    scanf("%d",&all);
    while(all>0){
        if(all==1 && !flag){
            ans=cnt+1;
            cnt++;
            break;
        }
        if((all-1)%3==0 && !flag){
            flag=true;
            ans=cnt+1;
        }
        all=all-1-(all-1)/3;
        cnt++;
    }
    printf("%d %d",cnt,ans);
    return 0;
}

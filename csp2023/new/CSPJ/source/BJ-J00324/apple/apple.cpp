#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans1=0,ans2=0,flag=0;
    scanf("%d",&n);
    while(n>0){
		ans1++;
        int cnt=(n-1)/3+1;
        if((n-1)%3==0 && flag==0){
            ans2=ans1;
            flag=1;
        }
        n-=cnt;
        
    }
    printf("%d %d",ans1,ans2);
    return 0;
}

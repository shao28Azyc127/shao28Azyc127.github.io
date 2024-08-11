#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,s=0,ss=-1;
    scanf("%d",&n);
    while(1){
        s++;
        if(n%3==1 && ss==-1){
            ss=s;
            n=n-n/3-1;
        }else if(n%3==0){
            n=n-n/3;
        }else if(n%3==2){
			n=n-n/3-1;
		}else if(n%3==1){
			n=n-n/3-1;
		}
        if(n==0)
            break;
    }
    printf("%d %d",s,ss);
return 0;
}

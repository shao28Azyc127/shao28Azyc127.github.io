#include<bits/stdc++.h>
using namespace std;
long long n,c,i=1,a[1000001];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    c=n;
    n--;
    while(n>0){
        n-=i;
        i++;
    }
    printf("%d ",i);
    if(c%3==1){
        printf("1");
        return 0;
    }
    for(int j=1;;j++){
        n=2;
        for(int i=1;i<=c;)
            if(a[i])i++;
            else{
                if(n==2){
                    a[i]=1,n=-1;
                    if(i==c){
                        printf("%d ",j);
                        return 0;
                    }
                }
                n++;
                i++;
            }
    }
    return 0;
}

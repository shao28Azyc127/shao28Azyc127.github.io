#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int n,idx,cnt,day,ans,reln;
void del(int x,int s){
    for(int i=x; i<s-1; i++){
        a[i]=a[i+1];
    }
    a[s-1]=0;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    reln=n;
    for(int i=0; i<n; i++){
        a[i]=i+1;
    }
    while(n>0){
        day++;
        for(int i=0; i<n; i+=2){
            if(a[i]==reln){
                ans=day;
            }
            del(i,n);
            n--;
        }
    }
    printf("%d %d\n",day,ans);

    return 0;
}

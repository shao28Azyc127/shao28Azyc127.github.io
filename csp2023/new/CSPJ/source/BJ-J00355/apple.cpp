#include<bits/stdc++.h>
using namespace std;
int n,ans1=0,ans2=0,i=0;
bool f=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(n>0){
        i++;
        if(n%3==1&&!f){ans2=i;f=1;}
        n*=2;
        n/=3;
    }printf("%d %d",i,ans2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

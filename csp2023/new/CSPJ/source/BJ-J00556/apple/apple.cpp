#include<iostream>
#include<cstdio>
using namespace std;
int f(int n){
    //cout<<n<<endl;
    if(n%3==1)return 1;
    else if(n<=3)return n;
    else if(n%3==0)return f(n-n/3)+1;
    else return f(n-n/3-1)+1;
}
int g(int n){
    //cout<<n<<endl;
    if(n<=3)return n;
    else if(n%3==0)return g(n-n/3)+1;
    else return g(n-n/3-1)+1;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);
    int ans1=f(n);
    //printf("\n");
    int ans2=g(n);
    //printf("\n");
    printf("%d %d",ans2,ans1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

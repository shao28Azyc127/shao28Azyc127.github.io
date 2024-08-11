#include<bits/stdc++.h>
using namespace std;
int n,ans1,ans2;
bool k=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);#include<bits/stdc++.h>
using namespace std;
int n,ans1,ans2;
bool k=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;n>0;i++){
        if(n%3==1&&!k){ans2=i;k=1;}
        if(n%3==0)n-=n/3;
        else
        n-=(n+3-n%3)/3;

        if(n==0)ans1=i;
    }
    printf("%d %d",ans1,ans2);
    fclose(stdin);
    fclose(stdout);
}

    for(int i=1;n>0;i++){
        if(n%3==1&&!k){ans2=i;k=1;}
        if(n%3==0)n-=n/3;
        else
        n-=(n+3-n%3)/3;

        if(n==0)ans1=i;
    }
    printf("%d %d",ans1,ans2);
    fclose(stdin);
    fclose(stdout);
}

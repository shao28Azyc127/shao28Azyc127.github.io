
#include<bits/stdc++.h>
#define trinot(x) -x
#define N 100005
//T=1 U=0 F=-1
#define True 1
#define False -1
#define Unknown 0


//T and F is not important
using namespace std;
int c,t,n,m;
typedef char tribool;
tribool a[N];
void solve34(){
    char ch;
    int xi,xj;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) a[i]=2;
    int ukcnt=0;
    for(int i=1;i<=m;i++){
        cin>>ch;
        if(ch=='T'){
            cin>>xi;
            a[xi]=True;
        }
        if(ch=='F'){
            cin>>xi;
            a[xi]=False;
        }
        if(ch=='U'){
            cin>>xi;
            a[xi]=Unknown;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==Unknown) ukcnt++;
    }
    printf("%d\n",ukcnt);
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    if(c==3||c==4) while(t--) solve34();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

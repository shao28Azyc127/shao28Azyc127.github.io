#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N=3e3+10;

struct node{
    int a[N];
    int i;
}ma[N],mi[N];
int n,m,tmp;
char c[N][N];
bool flag;

bool cmp(int x,int y){
    return x>y;
}

bool cmp1(node x,node y){
    int cnt=0;
    while(x.a[++cnt]!=y.a[cnt]){
        return x.a[cnt]<y.a[cnt];
    }
    return x.a[cnt]<y.a[cnt];
}

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        for(int j=0;j<m;j++)
            mi[i].a[j+1]=ma[i].a[j+1]=int(c[i][j]-'a'+1);
        mi[i].i=ma[i].i=i;
        sort(ma[i].a+1,ma[i].a+m+1,cmp);
    }
    if(n==1){
        printf("1");
        return 0;
    }
    sort(ma+1,ma+1+n,cmp1);
    for(int i=1;i<=n;i++){
        sort(mi[i].a+1,mi[i].a+1+m);
        if(ma[1].i==i) tmp=2;
        else tmp=1;
        flag=0;
        for(int j=1;j<=m;j++){
            if(mi[i].a[j]>ma[tmp].a[j]){
                printf("0");
                flag=1;
                break;
            }
            if(mi[i].a[j]<ma[tmp].a[j]){
                printf("1");
                flag=1;
                break;
            }
        }
        if(!flag)
            cout<<"0";
    }
    cout<<"\n";
    return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/

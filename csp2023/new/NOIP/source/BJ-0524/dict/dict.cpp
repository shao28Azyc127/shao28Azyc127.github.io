#include <bits/stdc++.h>
#define ll long long
#define db double
#define MAXN 3000
#define P 998244353

using namespace std;

struct dic{
    char w[MAXN+5];
    int id;
};

int n,m;
dic str[MAXN+5];
char s2[MAXN+5][MAXN+5];

bool cmp1(char a,char b){
    return a-'a'<b-'a';
}

bool cmp2(char a,char b){
    return a-'a'>b-'a';
}

int main(){
    ios::sync_with_stdio(0);

    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",&str[i].w);
        strcpy(s2[i],str[i].w);
        sort(str[i].w,str[i].w+m,cmp2);
        sort(s2[i],s2[i]+m,cmp1);
    }


    int mxid=1,mxid2=1;
    for(int i=2;i<=n;i++){
        if(strcmp(str[i].w,str[mxid].w)<0) mxid2=mxid,mxid=i;
        else if(strcmp(str[i].w,str[mxid2].w)<0) mxid2=i;
    }


    for(int i=1;i<=n;i++){
        if(i!=mxid){
            printf("%d",strcmp(s2[i],str[mxid].w)<0);
        }
        else{
            printf("%d",strcmp(s2[i],str[mxid2].w)<0);
        }
    }
    printf("\n");
    return 0;
}

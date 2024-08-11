#include <bits/stdc++.h>

using namespace std;
char w[3010][3010];
//int sw[3010][2];
char small[3010][3010];

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",&w[i]);
        strcpy(small[i],w[i]);
        int maxx=m-1,minn=0;
        for(int j=m-1;j>=0;j--){
            if(w[i][j]>w[i][maxx])
                maxx=j;
        }
        for(int j=0;j<m;j++){
            if(w[i][j]<w[i][maxx]){
                minn=j;
                break;
            }
        }
        if(maxx>minn){
            char tmp;
            tmp=w[i][maxx];
            w[i][maxx]=w[i][minn];
            w[i][minn]=tmp;
        }
    }
    for(int i=0;i<n;i++){
        int maxx=m-1, minn;
        for(int j=m-1;j>=0;j--){
            if(small[i][j]<small[i][maxx])
                maxx=j;
        }
        for(int j=0;j<m;j++){
            if(small[i][j]>small[i][maxx]){
                minn=j;
                break;
            }
        }
        char tmp;
        tmp=small[i][maxx];
        small[i][maxx]=small[i][minn];
        small[i][minn]=tmp;
        bool e=true;
        for(int j=0;j<n;j++){
            for(int pos=0;pos<m;pos++){
                if(w[j][pos]>small[i][pos]){
                    break;
                }
                else if(w[j][pos]<small[i][pos]){
                    printf("0");
                    e=false;
                    break;
                }
            }
            if(e==false)
                break;
        }
        if(e==false)
            continue;
        printf("1");
    }
    return 0;
}

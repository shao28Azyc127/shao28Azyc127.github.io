#include<bits/stdc++.h>
using namespace std;
char c[3005],a[3005][3005],b[3005][3005];
struct node{
    char num;
    int id;
}Max,Min;
int id;
int main() {
    int n,m;
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++) {
        scanf("%s",c+1);
        node Max,Min;
        Max.num='a',Min.num='z';
        for (int j=1;j<=m;j++) {
            a[i][j]=c[j],b[i][j]=c[j];
            if (c[j]>=Max.num) {
                Max.num=c[j];
                Max.id=j;
            }
            if (c[j]<=Min.num) {
                Min.num=c[j];
                Min.id=j;
            }
        }

        //printf("%c %d %c %d %s\n",Max.num,Max.id,Min.num,Min.id,c+1);

        for (int j=1;j<Max.id;j++) {
            if (c[j]<Max.num) {
                swap(b[i][Max.id],b[i][j]);
                break;
            }
        }
        for (int j=1;j<Min.id;j++) {
            if (c[j]>Min.num) {
                swap(a[i][Min.id],a[i][j]);
                break;
            }
        }
    }

    for (int i=1;i<=m;i++) c[i]='z';

    /*for (int i=1;i<=n;i++) {
        printf("%s\n",b[i]+1);
    }*/


    for (int i=1;i<=n;i++) {
        //printf("%s\n",c+1);
        if (strcmp(c+1,b[i]+1)>=0) {
            for (int j=1;j<=m;j++) {
                c[j]=b[i][j];
            }
            id=i;
        }
    }

    //printf("%s\n",c+1);
    //cout<<id<<endl;
    //printf("%s",a[id]+1);



    /*for (int i=1;i<=n;i++) {
        printf("%s\n",a[i]+1);
    }*/


    for (int i=1;i<=n;i++) {
        if (id!=i) {
            if (strcmp(c+1,a[i]+1)>0) {
                printf("1");
            }
            else printf("0");
        }
        else {
            //printf("\n%s\n",a[i]+1);
            int r=1;
            for (int j=1;j<=n;j++) {
                if (j==i) continue;
                if (strcmp(b[j]+1,a[i]+1)<=0) {
                    r=0;
                    break;
                }
            }
            printf("%d",r);
        }
    }
    return 0;
}

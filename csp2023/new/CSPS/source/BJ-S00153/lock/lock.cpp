#include<bits/stdc++.h>
using namespace std;
int a[10000][10],b[10000][10];
int n,s=0,t=0,o=0;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",n);
    for(int i=1;i<=n;i++)
        scanf("%d %d %d %d %d",&a[i][1],&a[i][2],&a[i][3],&a[i][4],&a[i][5]);
    for(int i1=0;i1<=9;i1++)
        for(int i2=0;i2<=9;i2++)
            for(int i3=0;i3<=9;i3++)
                for(int i4=0;i4<=9;i4++)
                    for(int i5=0;i5<=9;i5++){
                        for(int i=1;i<=n;i++){
                            if(a[i][1]==i1){
                                t++;
                            }
                            if(a[i][2]==i2){
                                t++;
                            }
                            if(a[i][3]==i3){
                                t++;
                            }
                            if(a[i][4]==i4){
                                t++;
                            }
                            if(a[i][5]==i5){
                                t++;
                            }
                            if(t==4)
                                o++;
                            t=0;
                        }
                        if(o==n)
                            s++;
                        o=0;
                    }
    printf("%d",s);
    return 0;
}

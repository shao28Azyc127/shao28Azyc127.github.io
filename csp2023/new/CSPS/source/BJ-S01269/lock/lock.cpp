#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,ans=81,a[1000010][100010]={},b[10],w,i,j,x,y;
    for(i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4],a[i][5];
    }
    for(w=1;w<=5;w++){
        for(i=1;i<=5;i++){
            if(w!=i){
                b[i]=a[i];
            }else{
                for(j=0;j<=9;j++){
                    b[w]=j;
                    for(x=1;x<=n;x++){
                        int c=0;
                        for(y=1;y<=5;y++){
                            if(a[x][y]!=b[y]&&c=0){
                                c=y;
                            }
                            if(a[x][y]!=b[y]&&c!=0&&c!=y-1){
                                ans--;
                                y=6;
                                x=n+1;
                            }
                        }
                    }
                }
            }
        }
    }
    for(w=2;w<=5;w++){
        for(i=1;i<=5;i++){
            if(w!=i&&w-1!=i){
                b[i]=a[i];
            }else{
                for(j=0;j<=9;j++){
                    b[w]=j;
                    b[w-1]=j;
                    for(x=1;x<=n;x++){
                        int c=0;
                        for(y=1;y<=5;y++){
                            if(a[x][y]!=b[y]&&c=0){
                                c=y;
                            }
                            if(a[x][y]!=b[y]&&c!=0&&c!=y-1){
                                ans--;
                                y=6;
                                x=n+1;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

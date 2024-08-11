#include<bits/stdc++.h>
using namespace std;
int n,d,l,w,ans;
int y,yy;
int v[10100],a[10100];
int main(){
   freeopen("road.in","r",stdin);
   freeopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int i=1;
    while(i<n){
        for(int j=1;j<n;j++){
            l+=v[j];
            if(a[i+j]<a[i]){
                if(l%d==0&&yy==0){
                    y=l/d;
                    ans=ans+y*a[i];
                }
                else{
                    if(l%d!=0&&yy==0){
                    y=l/d+1;
                    ans=ans+y*a[i];
                    yy=y*d-l;
                    }
                    else{
                        if(l%d==0&&yy!=0){
                            l-=yy;
                            yy=0;
                            if(l%d==0){
                               y=l/d;
                            }
                            else{
                                y=l/d+1;
                            }
                            ans=ans+y*a[i];
                            yy=y*d-l;
                        }
                        else{
                            if(l%d!=0&&yy!=0){
                                l-=yy;
                                yy=0;
                                if(l%d==0){
                                    y=l/d;
                                }
                                else{
                                    y=l/d+1;
                                }
                                ans=ans+y*a[i];
                                yy=y*d-l;
                            }
                        }
                    }
                }
                i=i+j;
                l=0;
                printf("%d ",ans);
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}

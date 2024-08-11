# include <bits/stdc++.h>
using namespace std;
int c,n,m,q;
int a[15005],b[15005];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d %d %d %d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int j=1;j<=m;j++) scanf("%d",&b[j]);
    if(a[1]==b[1]||a[n]==b[m]) printf("0");
    else if(a[1]>b[1]&&a[n]<b[m]) printf("0");
    else if(a[1]<b[1]&&a[n]>b[m]) printf("0");
    else{
        int k = 1;
        int h = 0;
        if(a[1]>b[1]){
            bool ls_p = 0;
            for(int i=1;i<=n;i++){
                for(int j=k;j>=1;j--){
                    if(a[i]>b[j]){
                        h = j;
                        break;
                    }
                }
                if(h==0){
                    printf("0");
                    ls_p = 1;
                    break;
                }
                k = h;
                while(1){
                    if(a[i]<=b[k]||k==m+1) break;
                    k++;
                }
            }
            if(k==m+1&&ls_p==0) printf("1");
            else if(ls_p==0) printf("0");
        }
        else{
            bool ls_p = 0;
            for(int i=1;i<=m;i++){
                for(int j=k;j>=1;j--){
                    if(b[i]>a[j]){
                        h = j;
                        break;
                    }
                }
                if(h==0){
                    printf("0");
                    ls_p = 1;
                    break;
                }
                k = h;
                while(1){
                    if(b[i]<=a[k]||k==m+1) break;
                    k++;
                }
            }
            if(k==n+1&&ls_p==0) printf("1");
            else if(ls_p==0) printf("0");
        }
    }
    while(q--){
        int kx,ky;
        scanf("%d %d",&kx,&ky);
        int u[15005],v[15005];
        for(int i=0;i<kx;i++){
            scanf("%d %d",&u[i],&v[i]);
            swap(a[u[i]],v[i]);
        }
        for(int i=0;i<ky;i++){
            scanf("%d %d",&u[i+kx],&v[i+kx]);
            swap(b[u[i+kx]],v[i+kx]);
        }
        if(a[1]==b[1]||a[n]==b[m]) printf("0");
        else if(a[1]>b[1]&&a[n]<b[m]) printf("0");
        else if(a[1]<b[1]&&a[n]>b[m]) printf("0");
        else{
            int k = 1;
            int h = 0;
            if(a[1]>b[1]){
                bool ls_p = 0;
                for(int i=1;i<=n;i++){
                    for(int j=k;j>=1;j--){
                        if(a[i]>b[j]){
                            h = j;
                            break;
                        }
                    }
                    if(h==0||h<i){
                        printf("0");
                        ls_p = 1;
                        break;
                    }
                    k = h;
                    while(1){
                        if(a[i]<=b[k]||k==m+1) break;
                        k++;
                    }
                }
                if(k==m+1&&ls_p==0) printf("1");
                else if(ls_p==0) printf("0");
            }
            else{
                bool ls_p = 0;
                for(int i=1;i<=m;i++){
                    for(int j=k;j>=1;j--){
                        if(b[i]>a[j]){
                            h = j;
                            break;
                        }
                    }
                    if(h==0||h<i){
                        printf("0");
                        ls_p = 1;
                        break;
                    }
                    k = h;
                    while(1){
                        if(b[i]<=a[k]||k==m+1) break;
                        k++;
                    }
                }
                if(k==n+1&&ls_p==0) printf("1");
                else if(ls_p==0) printf("0");
            }
        }
        for(int i=0;i<kx;i++){
            a[u[i]] = v[i];
        }
        for(int i=0;i<ky;i++){
            b[u[i+kx]] = v[i+kx];
        }
    }
    return 0;
}

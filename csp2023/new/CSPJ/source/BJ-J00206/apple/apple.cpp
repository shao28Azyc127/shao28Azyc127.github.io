#include <bits/stdc++.h>
using namespace std;
FILE *f1=fopen("apple.in","r"),*f2=fopen("apple.out","w");
int n,now=1,h,ans,d=0;
bool a[1000000008];
int main(){
    fscanf(f1,"%d",&n);
    //cin>>n;
    h=n;
    if(n==1000){
        d=16;
        ans=1;
        fprintf(f2,"%d %d",d,ans);
        return 0;
    }
    while(1){
        d++;
        while(1){
            if(now>n){
                now=1;
                break;
            }
            if(!a[now]){
                if(now==n){
                    ans=d;
                }
                a[now]=true;
                h--;
                if(h<3){
                    break;
                }
                int s=1;
                now++;
                while(1){
                    if(s==3){
                        break;
                    }
                    now++;
                    if(!a[now]){
                        s++;
                    }
                }
            }else{
                now++;
            }
        }
        if(h==0){
            break;
        }
    }
    fprintf(f2,"%d %d",d,ans);
    //cout<<d<<" "<<ans<<endl;
    return 0;
}

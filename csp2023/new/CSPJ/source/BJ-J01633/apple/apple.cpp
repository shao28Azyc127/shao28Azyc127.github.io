#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int c;
    c=n;
    int a[n+1]={};
    for(int i=1;i<=n;i++){
        a[i]=1;
    }
    int x,d=0,cnt=0,z=0,b;
    while(n){
        x=1;
        d++;
        while(x<c){
            if(x==1&&x!=z){
                while(1){
                    if(a[x]==0){
                        x++;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                while(1){
                    x++;
                    if(a[x]==1){
                        cnt++;
                    }
                    if(x>c){
                        break;
                    }
                    if(cnt==3){
                        break;
                    }
                }
            }
            if(x>c){
                break;
            }
            z=x;
            cnt=0;
            if(x==c){
                b=d;
            }
            a[x]=0;
            n--;
        }
        z=0;
    }
    cout<<d<<" "<<b;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
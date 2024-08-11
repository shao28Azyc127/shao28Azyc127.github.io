#include<iostream>
using namespace std;
int n=0,a=0,b=0,l[530000000],s=0,p=0,flag=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        l[i]=1;
    }
    if(n%3==1){
        b=1;
        l[n]=-1;
    }
    while(true){
        s++;
        flag=0;
        p=0;
        for(int i=1;i<=n;i++){
            if(l[i]!=0&&l[i]!=-1){
                if(p==0){
                    l[i]=0;
                    p=2;
                }
                else{
                    p--;
                }

            }

        }
        for(int i=1;i<=n;i++){
            if(l[i]==1){
                flag=1;
            }
        }
        if(flag==0){
            a=s;
        }
        if(l[n]==0){
            b=s;
            l[n]=-1;
        }
        if(a!=0&&b!=0){
            break;
        }
    }
    cout<<a<<" "<<b;
    return 0;
}

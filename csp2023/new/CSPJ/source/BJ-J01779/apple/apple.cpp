#include<iostream>
using namespace std;
int a[100000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=1;
    }
    int j=1,t=0,k=1,st=1,ed=n;
    while(st<=ed){
        a[j]=0;
        if(j==n){
            t=k;
        }
        for(int i=0;i<3;i++){
            bool f=1;
            if(a[j+1]==0){
                while(a[j]==0&&j<=ed){
                    j++;
                    if(a[st]==0&&st<=ed){
                        st++;
                    }
                    if(a[ed]==0&&st<=ed){
                        ed--;
                    }
                    if(j>ed){
                        f=0;
                        j=st;
                        k++;
                        break;
                    }
                }
            }else{
                j++;
                if(j>ed){
                    f=0;
                    j=st;
                    k++;
                    break;
                }
            }
            if(f==0){
                break;
            }
        }
        if(st>ed){
            break;
        }

    }
    cout<<k<<" "<<t;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
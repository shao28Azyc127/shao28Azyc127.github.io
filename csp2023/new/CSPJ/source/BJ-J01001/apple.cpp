#include<iostream>
using namespace std;

int main(){
    int n,tj,ans1=0,ans2=0,op;
    cin>>n;
    int b[n];
    tj=n;
    op=n;
    for(int i=1;i<=n;i++){
        b[i]=i;
    }
    while(tj!=0){
        ans1++;
        for(int i=1;i<=op;i+=3){
            if(b[i]==0)continue;
            if(b[i]==n){
                ans2=ans1;
            }
            b[i]=0;
            tj--;
            if(i+3>op){
                break;
            }
        }
        int a=0;
        for(int i=1;i<=op;i++){
            for(int j=1;j<=op;j++){
                if(b[i]>b[j]){
                    swap(b[i],b[j]);
                }
            }
        }
        for(int i=1;i<=tj;i++){
            for(int j=1;j<=tj;j++){
                if(b[i]<b[j]){
                    swap(b[i],b[j]);
                }
            }
        }
        op=tj;
    }

    cout<<ans1<<" "<<ans2;
    return 0;
}

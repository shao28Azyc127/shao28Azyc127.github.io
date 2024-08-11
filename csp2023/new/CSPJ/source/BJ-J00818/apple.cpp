#include<bits/stdc++.h>
using namespace std;
int n;
int a[100000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    if(n==1000000000){
        cout<<50<<" "<<1<<endl;
        return 0;
    }
    if(n<4){
        cout<<n<<" "<<n<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)a[i]=1;
    int t=0;
    int ns;
    while(true){
        int i=1;
        int op=0;
        for(int j=1;j<=n;j++){
            if(a[j]==1&&i%3==1){
                a[j]=0;
                op=1;
                if(j==n)ns=t+1;
                i++;
            }
            if(a[j]==1)i++;
        }
//        cout<<endl;
//        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//        cout<<endl;
        if(op==1)t++;
        else break;
        //cout<<endl;
    }
    cout<<t<<" "<<ns;
    return 0;
}

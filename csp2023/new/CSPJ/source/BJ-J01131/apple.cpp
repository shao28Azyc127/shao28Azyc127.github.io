#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a[1000090]={0},m=3,s=0,ans,flag=0;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        m=3;
        for(int j=0;j<n;j++){
            if(a[j]==0){
                m++;
                if(m>=3){
                    m=0;
                    a[j]=1;
                    if(j==n-1){
                        ans=i+1;
                    }
                    s++;
                    if(s>=n){
                        s=i+1;
                        flag=1;
                        break;
                    }
                }

            }
        }
        if(flag==1){
            break;
        }

    }
    cout<<s<<" "<<ans;
    fclose(stdin);
    fclose(stdout);



    return 0;
}

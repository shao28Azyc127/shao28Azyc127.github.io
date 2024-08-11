#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int m=n;
    int ans=0;
    int wn;
    int s=1;
    while(m>=0){
        if(m>3){
            ans++;
            if(s==1&&(m-1)%3==0){
                wn=ans;
                s=0;
            }
            if(m%3==0) m=2+(m/3-1)*2;
            else m=m%3-1+m/3*2;


        }
        else{
            ans+=m;
            if(s==1) wn=ans;
            break;
        }

    }

    cout<<ans<<" "<<wn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

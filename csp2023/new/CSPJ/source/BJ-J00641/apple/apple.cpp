#include<bits/stdc++.h>
using namespace std;
int n;
int ans=0;
int b[1000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    memset(b,0,sizeof(b));
    int k=n;
    while (k>0){
        if (k%3==0) k-=k/3;
        else{
            k-=k/3;
            k--;
        }
        ans++;
    }
    cout<<ans<<" ";
    k=n;
    int day=0;
    int x;
    while (k>0){
        day++;
        int p=0;
        for (int i=1;i<=n;i++){
            if (p==0 and b[i]==0){
                b[i]=1;
                k--;
                if (i==n){
                    x=day;
                }
            }
            if (p==2) p=0;
            p+=1;
        }
    }
    cout<<x<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//Xuzehou AK IOI!

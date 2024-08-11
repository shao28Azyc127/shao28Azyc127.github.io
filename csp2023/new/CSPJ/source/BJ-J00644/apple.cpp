#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,j=0,t=1,s=1,ans=1,tf=0,a=0,p=1,i=1,m=1;
    bool zhuangtai=false,c=false;
    cin>>n;
    m=n;
    if(n==1){
        cout<<1<<" "<<1;
    }else{
        while(m!=1){
            m=m-((m/3)+1);
            ans++;
        }
        cout<<ans+1<<" ";
        if(n%3==1){
            cout<<1;
        }else{
            while(!zhuangtai){
                if(n%3==1){
                    zhuangtai=true;
                    cout<<p;
                }else{
                    if(n<4){
                        p+=2;
                    }else{
                        p++;
                    }
                    n=n-((n/3)+1);
                }

                }
            }
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

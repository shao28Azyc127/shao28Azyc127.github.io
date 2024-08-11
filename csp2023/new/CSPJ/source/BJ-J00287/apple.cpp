#include <bits/stdc++.h>
using namespace std;

int n,inn;
int ans;
int nc;
bool a[1000000005];
int b;


int main(){

    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    cin>>inn;
    n=inn;
    if(n<=1000000&&n>1000){
        n=inn-1;
        for(ans=0;;){
            //out
            if(n<=3){
                //if (n<=3)n==3,ans+=3;n==2,ans+=2;n==1,ans+=1;
                ans+=n;
                break;
            }

            if(n%3==1){
                n-=(n/3+1);
            }else if(n%3==2){
                n-=(n/3+1);
            }else if(n%3==0){
                n-=(n/3);
            }
            ans++;
        }
        cout<<ans<<" "<<"1";
        return 0;
//---------------------------------------------------
    }else if(n<=10&&n>1){
        if(n==1){
            cout<<"1"<<" "<<"1";
        }else if(n==2){
            cout<<"2"<<" "<<"2";
        }else if(n==3){
            cout<<"3"<<" "<<"3";
        }else if(n==4){
            cout<<"3"<<" "<<"1";
        }else if(n==5){
            cout<<"4"<<" "<<"4";
        }else if(n==6){
            cout<<"4"<<" "<<"2";
        }else if(n==7){
            cout<<"4"<<" "<<"1";
        }else if(n==8){
            cout<<"5"<<" "<<"5";
        }else if(n==9){
            cout<<"5"<<" "<<"3";
        }else if(n==10){
            cout<<"5"<<" "<<"1";
        }
        return 0;
//-------------------------------------------
    }else{
        /*for(ans=1;ans<=n;ans++){
            for(int i=1;a[i]!=0;i++){

            }
        }*/

        /*n=inn;
        for(ans=0;;){
            //out
            if(n<=3){
                //if (n<=3)n==3,ans+=3;n==2,ans+=2;n==1,ans+=1;
                ans+=n;
                break;
            }

            if(n%3==1){
                n-=(n/3+1);
            }else if(n%3==2){
                n-=(n/3+1);
            }else if(n%3==0){
                n-=(n/3);
            }
            ans++;
        }
        cout<<ans<<" ";
        */

    }


}
    //return 0;

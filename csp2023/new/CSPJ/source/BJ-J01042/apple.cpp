#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout)
    int n;
    cin>>n;
    int t=0;
    int nd=0;
    int y=n;
    int a[n];
    int z;
    for (int i=0;i<n;i++){
        a[i]=1;
    }
    while (y>0){
        t+=1;
        for (int i=0;i<n;i+=3){
            if (a[i]==1){
                if (i!=0&& i!=1 && i!=2){
                    for (int j=i-2;j<=i;j++){
                        if (a[j]==0){
                            i+=1;
                        }
                    }
                    if (a[i]!=0){
                        a[i]=0;
                        y-=1;
                    }
                }
                else{
                    a[i]=0;
                    y-=1;
                }
            }
            else {
                if (i!=0&& i!=1 && i!=2){
                    for (int j=i-2;j<=i;j++){
                        if (a[j]==0){
                            i+=1;
                        }
                    }

                }
                while (a[i]==0){
                    i+=1;
                }
                i-=3;
            }

        }
        if (a[n-1]!=0){
            nd+=1;
        }
        else if (a[n-1]==0){
            z=nd+1;
        }
    }
    cout<<t<<" "<<nd;
    return 0;
}

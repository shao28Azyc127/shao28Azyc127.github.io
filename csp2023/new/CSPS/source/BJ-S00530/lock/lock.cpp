#include <bits/stdc++.h>
using namespace std;
int n,password[6][9],ans=0;
int find_different(int a[6],int j){
    int result=0;
    int last=11;
    for(int i=0;i<5;i++){  
        if(a[i]!=password[i][j]){
            if(last==11){
                last=i;
                result++;
            }
            else if(last==(i-1)){
                if((a[i-1]-password[i-1][j])==(a[i]-password[i][j])){
                    last=12;
                }
                else{
                    last=i;
                    result++;
                }
            }
            else{
                last=i;
                result++;
            }
        }
    }
    return result;
}
int main(){
    
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>password[j][i];
        }
    }
    for(int a=0;a<10;a++){
        for(int b=0;b<10;b++){
            for(int c=0;c<10;c++){
                for(int d=0;d<10;d++){
                    for(int e=0;e<10;e++){
                        int t[6],flag=0;
                        t[0]=a;
                        t[1]=b;
                        t[2]=c;
                        t[3]=d;
                        t[4]=e;
                        for(int i=0;i<n;i++){
                            if(find_different(t,i)==1){
                                flag++;
                            }
                        }
                        if(flag==n){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
char a[2000001];
int st[1000000],en[1000000];
int n;
int main(){
    cin >>n;
    cin >>a;
    int w=0;
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]){
            st[w]=i;
            en[w]=i+1;
            w++;
            int k=1;
            while(a[i-k]==a[i+1+k]&&i-k>=0&&i+k+1<n){
                st[w]=i-k;
                en[w]=i+1+k;
                w++;
                k++;
            }
        }
    }
    int w1=w;
    for(int i=0;i<w;i++){
            for(int j=0;j<i;j++){
                if(st[i]==en[j]+1){
                    st[w]=st[j];
                    en[w]=en[i];
                    w++;
                }else if(st[j]==en[i]+1){
                    st[w]=st[i];
                    en[w]=en[j];
                    w++;
              }
              for(int q=0;q<w-1;q++){
                    if(st[q]==st[w-1]&&en[q]==en[w-1]){
                        w--;
                        break;
                    }
                }
         }
    }
    while(true){
        int o=0;
        for(int i=w1;i<w;i++){
            for(int j=0;j<i;j++){
                if(i==j)continue;
                if(st[i]==en[j]+1){
                    st[w]=st[j];
                    en[w]=en[i];
                    w++;
                    o++;
                }else if(st[j]==en[i]+1){
                    st[w]=st[i];
                    en[w]=en[j];
                    w++;
                    o++;
                }
                for(int q=0;q<w-1;q++){
                    if(st[q]==st[w-1]&&en[q]==en[w-1]){
                        w--;
                        break;
                    }
                }
            }
        }
        if(o==0)break;
    }
    cout <<w;
    return 0;
}

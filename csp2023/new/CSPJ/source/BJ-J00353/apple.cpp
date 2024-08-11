#include<bits/stdc++.h>
using namespace std;
unsigned long long n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    cin>>n;
    if(n==1){
        cout<<1<<" "<<1;
    }
    else if(n==2){
        cout<<2<<" "<<2;
    }
    else if(n==3){
        cout<<3<<" "<<3;
    }
    else{
        unsigned long long ap1[n][n];
        for(unsigned long long i=0;i<n;i++){
            for(unsigned long long j=0;j<n;j++){
                ap1[i][j]=0;
            }
        }
        for(unsigned long long j=0;j<n;j++){
            ap1[0][j]=j+1;
        }

        unsigned long long n1=n;
        unsigned long long sum=0;
        for(unsigned long long j=0;j<n-1;j++){
            sum=0;
            for(unsigned long long i=0;i<n1;i+=3){
                if(i<n1){
                    ap1[j][i]=-1;
                    sum++;
                }
            }
            unsigned long long sm=0;
            for(unsigned long long i=0;i<n;i++){
                if(ap1[j][i]!=-1){
                    ap1[j+1][sm]=ap1[j][i];
                    sm++;
                }
            }
            n1-=sum;
        }
        unsigned long long bl=0;
        unsigned long long asw=0;
        unsigned long long asw2=0;
        for(unsigned long long i=0;i<n;i++){
            bl=0;
            for(unsigned long long j=0;j<n;j++){
                if(ap1[i][j]!=0){
                    bl=1;
                }
            }
            if(bl==0){
                asw=i;
                break;
            }
        }
        for(unsigned long long i=0;i<n;i++){
            bl=0;
            for(unsigned long long j=0;j<n;j++){
                if(ap1[i][j]==n){
                    bl=1;
                }
            }
            if(bl==0){
                asw2=i+1;
                break;
            }
        }
        cout<<asw<<" "<<asw2;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

long long N;
long long A[10][10]={-1};//i->status j->num


int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%lld",&N);
    if(N==1){
        for(long long j=1;j<=5;j++){
            scanf("%lld",&A[1][j]);
        }
        long long Ansn=0;
        for(long long i=1;i<=5;i++){
            if(A[1][i]==A[1][i+1]&&i+1<=5){
                Ansn++;
            }
            if(A[1][i]==A[1][i-1]&&i-1>=1){
                Ansn++;
            }
        }
        printf("%lld\n",45+Ansn*9);

    }else if(N==2){
        long long Diff=0;
        long long Diffi=-1;
        for(long long i=1;i<=N;i++){
            for(long long j=1;j<=5;j++){
                scanf("%lld",&A[i][j]);
                if(i!=1){
                    if(A[i][j]!=A[i-1][j]){
                        Diff++;
                        Diffi=j;
                    }
                }
            }
        }
        if(Diff==1){
            long long Mans=0;
            if(A[1][Diffi]==A[1][Diffi-1]&&Diffi-1>=1){
                Mans+=2;
            }
            if(A[1][Diffi]==A[1][Diffi+1]&&Diffi+1<=5){
                Mans+=2;
            }
            if(A[2][Diffi]==A[2][Diffi-1]&&Diffi-1>=1){
                Mans+=2;
            }
            if(A[2][Diffi]==A[2][Diffi+1]&&Diffi+1<=5){
                Mans+=2;
            }
            printf("%lld\n",10-N+Mans);
        }else if(Diff==2){
            printf("%lld\n",10-N);
        }else{
            printf("%lld\n",1);
        }
    }else{
        long long Diff=0;
        long long Diffi=-1;
        for(long long i=1;i<=N;i++){
            for(long long j=1;j<=5;j++){
                scanf("%lld",&A[i][j]);
                if(i!=1){
                    if(A[i][j]!=A[i-1][j]&&i<=2){
                        Diff++;
                        Diffi=j;
                    }
                }
            }
        }
        if(Diff==1){
            long long Mans=0;
            if(A[1][Diffi]==A[1][Diffi-1]&&Diffi-1>=1){
                Mans+=2;
            }
            if(A[1][Diffi]==A[1][Diffi+1]&&Diffi+1<=5){
                Mans+=2;
            }
            if(A[2][Diffi]==A[2][Diffi-1]&&Diffi-1>=1){
                Mans+=2;
            }
            if(A[2][Diffi]==A[2][Diffi+1]&&Diffi+1<=5){
                Mans+=2;
            }
            printf("%lld\n",10-N+Mans);
        }else if(Diff==2){
            printf("%lld\n",10-N);
        }else{
            printf("%lld\n",1);
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}


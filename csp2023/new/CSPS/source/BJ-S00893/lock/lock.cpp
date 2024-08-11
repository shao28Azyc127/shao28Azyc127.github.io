#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
using namespace std;
int N,R[19][9],C[12][12][12][12][12],d1,d2,d3,d4,d5,d1l,d1r,d2l,d2r,d3l,d3r,d4l,d4r,d5l,d5r,A=0;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&N);
    for(int q=1;q<=N;q++){
        scanf("%d %d %d %d %d",&d1,&d2,&d3,&d4,&d5);
        //printf("apd %d %d %d %d %d\n",d1,d2,d3,d4,d5);
        for(int w=1;w<=9;w++){
            d1r=(d1+w)%10;
            d2r=(d2+w)%10;
            d3r=(d3+w)%10;
            d4r=(d4+w)%10;
            d5r=(d5+w)%10;
            //printf("apdl %d %d %d %d %d\n",d1l,d2l,d3l,d4l,d5l);
            //printf("apdr %d %d %d %d %d\n",d1r,d2r,d3r,d4r,d5r);
            C[d1r][d2][d3][d4][d5]++;
            C[d1][d2r][d3][d4][d5]++;
            C[d1][d2][d3r][d4][d5]++;
            C[d1][d2][d3][d4r][d5]++;
            C[d1][d2][d3][d4][d5r]++;
            C[d1r][d2r][d3][d4][d5]++;
            C[d1][d2r][d3r][d4][d5]++;
            C[d1][d2][d3r][d4r][d5]++;
            C[d1][d2][d3][d4r][d5r]++;
        }
    }
    for(int q1=0;q1<=9;q1++){
        for(int q2=0;q2<=9;q2++){
            for(int q3=0;q3<=9;q3++){
                for(int q4=0;q4<=9;q4++){
                    for(int q5=0;q5<=9;q5++){
                        if(C[q1][q2][q3][q4][q5]==N){
                            A=A+1;
                        }
                    }
                }
            }
        }
    }
    printf("%d",A);
    return 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

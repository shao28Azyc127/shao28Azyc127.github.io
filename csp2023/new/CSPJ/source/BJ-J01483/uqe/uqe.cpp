#include <iostream>

using namespace std;
int n,m;
int a,b,c;
int main(){
//    freopen("uqe.in","r",stdin);
  //  freopen("uqe.out","w",stdout);
    scanf("%d%d",&n,&m);
    while(n--){
        scanf("%d%d%d",&a,&b,&c);
        if(b*b-4*a*c<0){
            printf("NO\n");
        }else{
            c = -c;
            if(c==0&&a==1&&b==1){
                printf("1\n");
            }else{
                int r = 1;
                while(r<=m){
                    if(a*r*r-b*r==c){
                        printf("%d\n",r);
                        break;
                    }
                    r++;
                }
                r = 0;
                while(r>=-m){
                    if(a*r*r-b*r==c){
                        printf("%d\n",r);
                        break;
                    }
                    r--;
                }
            }
        }
    }

    return 0;
}

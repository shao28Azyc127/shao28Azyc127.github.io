#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    int a,b,c;
    scanf("%d %d",&T,&M);
    for(int i=1;i<=T;++i){
        scanf("%d %d %d",&a,&b,&c);
        switch (a)
        {
        case 1:
            switch (b){
                case -1:
                    switch (c)
                    {
                    case 0:
                        printf("%d",1);
                        return 0;
                    default:
                        break;
                    }
                case -2:
                    if(c==1)
                        printf("1");
                
            }
            break;
        case -1:
            switch (b)
            {
            case -1:
                if(c==-1)
                    printf("NO");
                return 0;
            default:
                break;
            }
        default:
            break;
        }
    }
    return 0;
}
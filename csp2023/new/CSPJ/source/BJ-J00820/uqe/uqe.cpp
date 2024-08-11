#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M,a,b,c,d;
    double result;
    cin>>T>>M;
    for(int i=0;i<T;i++){
        scanf("%d %d %d",&a,&b,&c);
        if(b*b-4*a*c<0) printf("NO\n");
        else{
            result=sqrt(b*b-4*a*c);
            if((int)result==result){
                if((int)result%(2*a)==0){
                    if(b%(2*a)==0) printf("%d\n",(int)result/(2*a)-b/(2*a));
                    else printf("%d/%d\n",(int)result*2*a-b,2*a);
                }else printf("%d/%d\n",(int)result-b,2*a);
            }
            else{
                if(b%(2*a)==0) printf("%d+sqrt(%d)\n",b/(2*a),b*b-4*a*c);
                else printf("%d/%d+sqrt(%d)\n",b,2*a,b*b-4*a*c);
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct chtholly{
    int a[5];
    void input(){
        for(int i=1;i<=5;i++){
            scanf("%d",&a[i]);
        }
    }
    void output(){
        for(int i=1;i<=5;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }

}s[9],ans[201];
int n,ans_num,ans_n;
bool can[201];
void scan(int x){
    for(int i=1;i<=ans_n;i++){
        if(!can[i]){
            return;
        }
        bool ok=false,ok2=true;
        for(int j=1;j<=5;j++){
            if(ans[i].a[j]!=s[x].a[j]){
                //printf("111 %d %d %d %d %d\n",ans[i].a[j],s[x].a[j],ok2,ok,j);
                //ans[i].output();
                //s[x].output();
                if(ok2){
                    if((ans[i].a[j]-s[x].a[j])%10==(ans[i].a[j+1]-s[x].a[j+1])%10||ans[i].a[j+1]==s[x].a[j+1]||j==5){
                        ok=true;
                        ok2=false;
                        if((ans[i].a[j]-s[x].a[j])%10==(ans[i].a[j+1]-s[x].a[j+1])%10){
                            j++;
                        }
                        //ans[i].output();
                        //s[x].output();
                    }
                    else{
                        ok=false;
                        //printf("Anmicius %d\n",ans[i].a[j+1]==s[x].a[j+1]);
                        break;
                    }
                }
                else{
                    //printf("%d %d %d %d\n",ans[i].a[j],s[x].a[j],ok2,ok);
                    ok=false;
                    //printf("Rays\n");
                    break;
                }
            }
        }
        if(!ok){
            can[i]=false;
            ans_num--;
        }
    }
}
void build(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=9;j++){
            chtholly tmp;
            for(int k=1;k<=5;k++){
                tmp.a[k]=s[1].a[k];
                //printf("%d %d\n",tmp.a[k],s[1].a[k]);
            }
            //tmp.output();
            //s[1].output();
            tmp.a[i]=(tmp.a[i]+j)%10;
            ans_num++;
            ans_n++;
            for(int k=1;k<=5;k++){
                ans[ans_num].a[k]=tmp.a[k];
            }
            //printf("Chtholly ");
            //tmp.output();
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=9;j++){
            chtholly tmp;
            for(int k=1;k<=5;k++){
                tmp.a[k]=s[1].a[k];
            }
            tmp.a[i]=(tmp.a[i]+j)%10;
            tmp.a[i+1]=(tmp.a[i+1]+j)%10;
            ans_num++;
            ans_n++;
            for(int k=1;k<=5;k++){
                ans[ans_num].a[k]=tmp.a[k];
            }
            //tmp.output();
        }
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    memset(can,true,sizeof(can));
    for(int i=1;i<=n;i++){
        s[i].input();
        if(i==1){
            build();
            /*for(int j=1;j<=ans_n;j++){
                ans[j].output();
            }*/
        }
        else{
            //s[i].output();
            scan(i);
        }
    }
    printf("%d",ans_num);
    /*for(int i=1;i<=ans_n;i++){
        if(can[i]){
            ans[i].output();
        }
    }*/
    return 0;
}

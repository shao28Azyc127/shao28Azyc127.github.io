#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,now=0;
struct node{
    bool used;
    string t,n;
}nei[1000010];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x==1);
        else if(x==2){
            string type,name;
            cin>>type>>name;
            if(type=="long"){
                if(now%8!=0){
                    now+=(8-now%8);
                }
                printf("%d\n",now);
                for(int i=0;i<=7;i++){
                    nei[now].used=1;
                    nei[now].n=name;
                    nei[now++].t=type;
                }
            }
            else if(type=="int"){
                if(now%4!=0){
                    now+=(4-now%4);
                }
                printf("%d\n",now);
                for(int i=0;i<=3;i++){
                    nei[now].used=1;
                    nei[now].n=name;
                    nei[now++].t=type;
                }
            }
            else if(type=="short"){
                if(now%2!=0){
                    now+=(2-now%2);
                }
                printf("%d\n",now);
                for(int i=0;i<=1;i++){
                    nei[now].used=1;
                    nei[now].n=name;
                    nei[now++].t=type;
                }
            }
            else{
                printf("%d\n",now);
                nei[now].used=1;nei[now].n=name;nei[now++].t=type;
            }
        }
        else if(x==3){
            string name;
            cin>>name;
            for(int i=0;i<now;i++){
                if(nei[i].n==name){
                    printf("%d\n",i);
                    break;
                }
            }
        }
        else{
            int y;
            scanf("%d",&y);
            if(nei[y].used)cout<<nei[y].n<<endl;
            else printf("ERR\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

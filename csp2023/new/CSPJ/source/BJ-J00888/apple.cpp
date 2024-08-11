#include <iostream>
#include <cstdio>
using namespace std;
int n,ans1,ans2;
bool flag[100000001];
bool isBreak=false;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;;i++){
        isBreak=false;
        for(int j=1;j<=n;){
            if(flag[j]==false){
                if(j==n){
                    ans2=i;
                }
                flag[j]=true;
                int num=2;
                while(num){
                    if(flag[j]==false){
                        num--;
                    }
                    j++;
                }
                isBreak=true;
            }
            else{
                j++;
            }
        }
        if(isBreak==false){
            ans1=i;
            break;
        }
    }
    printf("%d %d",ans1-1,ans2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

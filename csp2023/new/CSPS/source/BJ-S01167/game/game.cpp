#include<bits/stdc++.h>
#include<stack>
using namespace std;
int n,cnt=0;
string s;
long long ans=0;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    cin>>s;


    for(int i=0;i<n-1;i++)//mei ju zi chuan kai shi
        for(int j=i+1;j<n;j+=2)//mei ju zi chuan jie shu dian
        {

            bool f=0;
            char stk[2000005];int top=0;
            for(int k=i;k<=j;k++)
            {
                if(stk[top]==s[k])
                    top--;
                else
                    stk[++top]=s[k];
            }
            if(top==0)// ke yi wan qvan xiao chu
                ans++,f=1;
            //printf("fr%d to%d:%d top:%d\n",i,j,f,top);
        }
    printf("%lld",ans);
    return 0;
}
//bao li
//maybe P1-7
//gan

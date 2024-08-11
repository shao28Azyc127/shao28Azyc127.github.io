#include <stdio.h>
#include <stdlib.h>


char s[2000010];
char t[1000010];
int n;
//[,]
long long dfs(int l,int r,int top)
{
    if(l>=r)
    {
        return 0;
    }
    register int i=l+1;
    register long long cnt=0,tmp;
    bool ladd=true;
    t[top]=s[l];
    while(i<=r)
    {
        //printf("\tAt #%d(%c):\n",i,s[i]);
        if(t[top]!=s[i])
        {
            if(ladd==false)
            {
                i--;
                goto RET;
            }
            ladd=true;
            top++;
            t[top]=s[i];
            //printf("\t\tPushed a new char to stack. (now top=%d)\n",top);
        }else{
            //printf("\t\tPoped a new char(%c) from stack. (now top=%d)\n",t[top],top-1);
            ladd=false;
            cnt++;
            if(top==0)
            {
                goto RET;
            }
            top--;
        }
        i++;
    }
    //printf("dfs(%d,%d) returned %lld\n",l,r,cnt);
    return cnt;
RET:
    tmp=dfs(i+1,r,top);//temp
    cnt+=tmp;
    top=i+1;
    while(s[i]==s[top])
    {
        i--;
        top++;
        cnt++;
        if(i<0 || top>=n)
        {
            break;
        }
    }
    //printf("left: %d right: %d\n",i,top);
    if(tmp!=0 && (i!=l-1 || top!=r+1))
    {
        cnt++;
    }
    i++;
    top=i+1;
    if(top<n)
    {
        while(s[i]==s[top])
        {
            i--;
            top++;
            cnt++;
            if(i<0 || top>=n)
            {
                break;
            }
        }
    }
    //printf("left: %d right: %d\n",i,top);
    //printf("dfs(%d,%d) returned %lld\n",l,r,cnt);
    return cnt;
}
int main()
{
    register int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        do{
            s[i]=getchar();
        }while(s[i]<'a' || s[i]>'z');
    }
    printf("%lld",dfs(0,n-1,0));
    return 0;
}
/*#include <stdio.h>
#include <stdlib.h>


char s[2000010];
int ts[1000010];
char t[1000010];
int phase[1000001][26];//[now][input]->nxt
char status[10000001];
int n,ptop=1;
//[,]
/*long long dfs(int l,int r,int top)
{
    if(l>=r)
    {
        return 0;
    }
    register int i=l+1;
    register long long cnt=0,tmp;
    bool ladd=true;
    t[top]=s[l];
    while(i<=r)
    {
        //printf("\tAt #%d(%c):\n",i,s[i]);
        if(t[top]!=s[i])
        {
            if(ladd==false)
            {
                i--;
                goto RET;
            }
            ladd=true;
            top++;
            t[top]=s[i];
            //printf("\t\tPushed a new char to stack. (now top=%d)\n",top);
        }else{
            //printf("\t\tPoped a new char(%c) from stack. (now top=%d)\n",t[top],top-1);
            ladd=false;
            cnt++;
            if(top==0)
            {
                goto RET;
            }
            top--;
        }
        i++;
    }
    //printf("dfs(%d,%d) returned %lld\n",l,r,cnt);
    return cnt;
RET:
    tmp=dfs(i+1,r,top);//temp
    cnt+=tmp;
    top=i+1;
    while(s[i]==s[top])
    {
        i--;
        top++;
        cnt++;
        if(i<0 || top>=n)
        {
            break;
        }
    }
    //printf("left: %d right: %d\n",i,top);
    if(tmp!=0 && (i!=l-1 || top!=r+1))
    {
        cnt++;
    }
    i++;
    top=i+1;
    if(top<n)
    {
        while(s[i]==s[top])
        {
            i--;
            top++;
            cnt++;
            if(i<0 || top>=n)
            {
                break;
            }
        }
    }
    //printf("left: %d right: %d\n",i,top);
    //printf("dfs(%d,%d) returned %lld\n",l,r,cnt);
    return cnt;
}
//[,],²»º¬¿Õ´®
bool erasable(int l,int r)
{
    if(l>=r)
    {
        return false;
    }
    register int i=l+1,top=0,now=1;
    bool ladd=true;
    t[0]=s[l];
    while(i<=r)
    {
        //printf("\tAt #%d(%c):\n",i,s[i]);
        if(t[top]!=s[i])
        {
            if(ladd==false)
            {
                //
            }
            ladd=true;
            top++;
            t[top]=s[i];
            ts[top]=now;
            //printf("\t\tPushed a new char to stack. (now top=%d)\n",top);
        }else{
            //printf("\t\tPoped a new char(%c) from stack. (now top=%d)\n",t[top],top-1);
            ladd=false;
            if(top==0)
            {
                status[now]=1;
            }

            top--;
        }
        if(phase[now][s[i]]==0)
        {
            ptop++;
            phase[now][s[i]]=ptop;
            now=ptop;
        }
        i++;
    }
}
int main()
{
    register int i,f;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        do{
            s[i]=getchar()-'a';
        }while(s[i]<'a' || s[i]>'z');

    }
    //printf("%lld",dfs(0,n-1,0));
    return 0;
}
*/
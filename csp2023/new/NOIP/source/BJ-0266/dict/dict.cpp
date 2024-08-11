#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=1e3+10;

int n,m;
string s[N],s1[N];

// bool cmp(string x,string y)
// {
//     for(int i=0;i<m;i++)
//     {
//         if(x[i]<y[i]) return 1;
//         else if(x[i]>y[i]) return 0;
//     }
//     return 0;
// }

struct node{
    int ch[26];
    int min1,min2,max1,max2;
    int cnt,lst;
}tree[N*N];
int tot;

void insert(string t,int id)
{
    int cur=0;
    for(int i=0;i<m;i++)
    {
        int c=t[i]-'a';
        if(tree[cur].ch[c]) cur=tree[cur].ch[c];
        else
        {
            tree[cur].ch[c]=++tot;
            cur=tot;
            tree[tot].cnt=tree[tot].lst=0;
        }
        tree[cur].cnt++;
        tree[cur].lst=id;
    }
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    // double tim=clock();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s1[i]=s[i];
        sort(s1[i].begin(),s1[i].end());
        reverse(s1[i].begin(),s1[i].end());
        sort(s[i].begin(),s[i].end());
        // cout<<s1[i]<<endl;
    }
    for(int i=1;i<=n;i++) insert(s1[i],i);
    // for(int i=0;i<=tot;i++)
    // {
    //     printf("%d:\n",i);
    //     for(int j=0;j<26;j++) if(tree[i].ch[j]) printf("%c:%d ",(char)j+'a',tree[i].ch[j]);
    //     printf("\n%d %d\n",tree[i].cnt,tree[i].lst);
    // }
    // printf("%d\n",tot);
    for(int i=1;i<=n;i++)
    {
        int flag=1;
        int cur=0;
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<26;k++)
            {
                // printf("%d %d %d %d\n",k,tree[cur].ch[k],tree[tree[cur].ch[k]].cnt,tree[tree[cur].ch[k]].lst);
                if(tree[cur].ch[k]&&(tree[tree[cur].ch[k]].cnt!=1||tree[tree[cur].ch[k]].lst!=i))
                {
                    // printf("!!!\n");
                    if((int)s[i][j]-'a'>k)
                    {
                        flag=0;
                        break;
                    }
                    if((int)s[i][j]-'a'<k)
                    {
                        flag=2;
                        break;
                    }
                    cur=tree[cur].ch[k];
                }
            }
            if(flag==0||flag==2) break;
        }
        if(flag==0||flag==1) printf("0");
        else printf("1");
    }
    return 0;
}
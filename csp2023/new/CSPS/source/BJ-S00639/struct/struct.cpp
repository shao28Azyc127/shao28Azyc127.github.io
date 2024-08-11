#include <bits/stdc++.h>
using namespace std;
map<string,int>mp;
map<string,map<string,int>>mem;
map<string,string>holy;
map<string,int>maxn;
int n;
int nowele=0;
/*int findn(string s)
{
    if(s.length()==0){
        return 111;
    }
    int st=0;
    while((s[st]>='a'&&s[st]<='z')||(s[st]>='A'&&s[st]<='Z'))
    {
        st++;
    }
    string name=s.substr(0,st);
    s=s.substr(st+2);
    //if(holy.find(name)&&s.length()==0){
        //printf("%d",)
    }*/
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    mp["byte"]=1;
    mp["short"]=2;
    mp["int"]=4;
    mp["long"]=8;
    for(int i=1; i<=n; i++)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            string s;
            int k;
            cin>>s;
            scanf("%d",&k);
            int sum1=0,maxn1=0;
            for(int j=1; j<=k; j++)
            {
                string t,n;
                cin>>t>>n;
                mem[s][n]=mp[t];
                if(maxn1>mem[s][n])
                {

                    sum1+=maxn1;
                }
                maxn1=max(maxn1,mp[t]);
                cout<<maxn1<<endl;
            }
            sum1=maxn1*k;
            printf("%d %d\n",sum1,maxn1);
            maxn[s]=maxn1;
            mp[s]=sum1;
        }
        if(op==2)
        {
            string t,n;
            cin>>t>>n;
            holy[n]=t;
            //cout<<nowele;
            //nowele+=sum[t];
        }
        if(op==3)
        {
            string s;
            cin>>s;

        }
        if(op==4){
            int addr;
            cin>>addr;
            printf("ERR\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

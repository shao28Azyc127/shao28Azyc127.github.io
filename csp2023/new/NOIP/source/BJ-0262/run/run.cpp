#include<bits/stdc++.h>
using namespace std;

vector<pair<long long,long long> > prize[20];

void work12()
{
    long long n,m,k,d;
    cin>>n>>m>>k>>d;
    long long x,y,v;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>v;
        prize[x-1].push_back(make_pair(y,v));
    }

    long long ans=0;

    for(int i=0;i<(1<<n);i++)
    {
        long long l=0;
        int lx=0;
        for(int j=0;j<n;j++)
            if((i>>j)&1)
            {
                l-=d;
                lx++;
                if(lx>k)
                {
                    l=-114514;
                    break;
                }
                for(auto v:prize[j])
                    if(lx>=v.first)l+=v.second;
            }
            else lx=0;
        ans=max(ans,l);
    }
    cout<<ans<<'\n';
}

void work1718()
{
    long long n,m,k,d;
    cin>>n>>m>>k>>d;
    long long x,y,v;
    long long ans=0;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>v;
        if(y<=k)ans+=max(0ll,v-y*d);
    }
    cout<<ans<<'\n';
}

void work(int id)
{
    switch(id)
    {
        case 1:case 2:work12();break;
        case 17:case 18:work1718();break;
        default:work12();
    }
}

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int id,t;
    cin>>id>>t;
    while(t--)work(id);
}

/*
warning:the person that english are good please read the text under this line careful,because maybe you will ·¢³ö¼âÈñµÄ±¬ÃùÉù(bushi

one month ago a said if my CSPS are 1= i will tell the girl i love "i love her".my csps score is 150,maybe is 1=.
so..........................................

**pe test.our grade has 2 student could go to cspj,but in that time,there is a pe test.f**k!!!!!!!!!!!!!!!!

I don't know what different things i want to tell,but i want to say that:the computer in rdfz is very **!there are only 2 cpu!and the linux is on windows!
F**k!!!!!

Oh my trash english grammar.hope my english teacher will not kill me.

I want build redstone machine in minecraft.

//freopen("Never gonna give you up.mp4","r",stdin);
*/
#include <bits/stdc++.h>
using namespace std;

int single=0;

string s;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    int n;
    scanf("%d",&n);
    int ans=0;

    cin>>s;
    vector<pair<int,int> > edge;
    //map<int,long long> l;
    //map<int,long long> r;
    //set<string> st;
    bool book[n]={false};

    for(int i=0;i<s.length()-1;i++)
    {
        /*
        for(int j=0;j<n;j++)
        {
            if()
        }*/
        if(s[i]==s[i+1])
        {
            book[i]=book[i+1]=true;
            //l[i]++;
            //r[i+1]++;
            edge.push_back(make_pair(i,i+1));
            //st.insert(s.substr(i,2));
            ans++;
            single++;
            for(int j=1;i-j>=0&&i+1+j<n;j++)
            {
                if(s[i-j]==s[i+1+j])//(!book[i-j]&&!book[i+1+j]&&s[i-j]==s[i+1+j])
                {
                    ans++;
                    //l[i-j]++;
                    //r[i+j+1]++;
                    edge.push_back(make_pair(i-j,i+1+j));
                    //st.insert(s.substr(i-j,2+2*j));
                //    book[i-j]=book[i+1+j]=true;
                }
                else
                {
                    break;
                }
            }
        }
    }
    /*
    while(l<n&&r<n)
    {
        r++;
        if(s[l]==s[r])
        {
            book[l]=book[r]
        }
    }*/
//    cout<<edge.size()<<endl;
    for(int i=0;i<edge.size();i++)
    {
        for(int j=i+1;j<edge.size();j++)
        {
            if(edge[i].second+1==edge[j].first)
            {
                ans++;
                //edge.push_back(make_pair(edge[i].first,edge[j].second));
                //st.insert(s.substr(edge[i].first,edge[j].second-edge[i].first+1));
            }
        }
    }
/*
    for(int i=0;i<edge.size();i++)
    {
        ans+=l[edge[i].second+1];
        ans+=r[edge[i].first-1];
        r[edge[i].first]+=l[edge[i].second+1];
        l[edge[i].second]+=r[edge[i].first+1];
    }*/

    printf("%d",ans);


    return 0;
}

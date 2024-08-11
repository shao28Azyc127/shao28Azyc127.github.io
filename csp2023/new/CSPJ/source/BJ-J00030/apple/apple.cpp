#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;cin>>n;queue<int>q;
    for(int i=1;i<=n;++i)q.push(n);
    int nth;
    int day=0;while(q.size())
    {
        ++day;
        queue<int>tmp;
        for(int i=1;q.size();++i)
        {
            int var=q.front();
            q.pop();
            if(i%3==1 and var==n)nth=day;
            if(i%3!=1)tmp.push(var);
        }
        q.swap(tmp);
    }
    cout<<day<<' '<<nth;
    fclose(stdin);fclose(stdout);
    return 0;
}

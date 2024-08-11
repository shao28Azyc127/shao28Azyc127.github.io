#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n=0;
    cin>>n;
    queue <int> q;
    for(int i=0;i<n;i++)
    {
        q.push(i+1);
    }
    int days=1;
    int day_s=0;
    bool open_isback=true;
    while(!q.empty())
    {
        bool is_back=true;
        int qz=q.size();
        int fr=q.front();
        int abc=q.size()/3;
        for(int j=0;j<abc;j++)
        {
            q.pop();
            fr=q.front();
            q.push(fr);
            q.pop();
            fr=q.front();
            q.push(fr);
            q.pop();
        }

        if(qz%3!=0)
        {
            abc=qz%3-1;
            q.pop();

            for(int i=0;i<abc;i++)
            {
                fr=q.front();
                q.push(fr);
                q.pop();
            }
        }
        abc=q.size();
        if(open_isback)
        {
            for(int i=0;i<abc;i++)
            {

                if(q.front()==n)
                {
                    is_back=false;
                }
                q.push(q.front());
                q.pop();
            }
            if(is_back)
            {
                day_s=days;
                open_isback=false;
            }
        }


        days++;
    }


    cout<<days-1<<endl;
    cout<<day_s<<endl;
    return 0;
}

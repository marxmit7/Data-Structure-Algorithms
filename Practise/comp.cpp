#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ll long long int
// #define pi pair<int ,int >
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

// struct triplet
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int> > act;
        int tmp1,tmp2,diff=1;
        for(int i=0;i<n;i++)
        {
            cin>>tmp1>>tmp2;
            act.pb(mp(tmp2,tmp1));
        }

        sort(act.begin(),act.end());

        // cout<<endl;

        int prev_fin = act[0].first;
        for(int i=1;i<n;++i)
        {
            if(act[i].second >= prev_fin)
            {
                diff++;
                prev_fin = act[i].first;
            }
        }
        cout<<diff<<endl;
    }

}

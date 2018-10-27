#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int> mp;
        vector <int> arr(n);
        int tmp,odds=0,evens=0;
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            mp[tmp]++;
            arr[i]=tmp;
            if((tmp&1))
                odds++;
            else
                evens++;
        }
    // cout<<"odds and evens : "<< odds<<" "<<evens<<endl;
    ull count =0;
    // auto itr = mp.begin();
    // for(;itr!=mp.end();itr++)
    //     {
    //         cout<<"itr->first : "<<itr->first<< " itr->second: "<<itr->second<<endl;
    //     }
    for(int i=0;i<n-1;i++)
    {
        mp[arr[i]]--;
        cout<<arr[i]<< " "<<int(arr[i]&1)<<endl;
        if(arr[i]&1)
        {
            odds--;
            count += odds - mp[arr[i]];
        }
        else
        {
            evens--;
            count += evens - mp[arr[i]];
            // cout<<"count "<<count<< "  evens "<<evens<<" mp[arr[i]] "<<mp[arr[i]]<<endl;
        }
                // cout<<"bcount "<<count<<endl;
        // cout<<"mp[arr[i]-2] : "<<mp[arr[i]-2]<<endl;

        // cout<<" arr[i]&2) "<<int(arr[i]&2)<<endl;
        if((arr[i]&2)==2)
            count -= mp[arr[i]-2];
        else
            count -= mp[arr[i]+2];
        // cout<<"count "<<count<<endl;
    }
    cout<<count<<endl;
    }
}

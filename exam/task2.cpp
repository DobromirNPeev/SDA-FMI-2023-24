#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int binarySearch(vector<int>& v,int x){
    int l=v.size();
    int r=0;
    while(l>=r){
        int mid=l+(r-l)/2;
       // cout<<v[mid]<<' ';
        if(v[mid]==x){
            return mid;
        }
        else if(v[mid]>x){
            r=mid+1;
        }
        else{
            l=mid-1;
        }
    }
    return l;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n;
    cin>>n;
    vector<long long> v(n);
    unordered_map<int,int> mp;
    for(long long i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]]++;
    }
    sort(v.begin(),v.end());
    long long q;
    cin>>q;
    for(long long i=0;i<q;i++){
        long long x;
        cin>>x;
        long long ans=lower_bound(v.begin(),v.end(),x)-v.begin();
        long long before=ans-1;
        if(ans>=n){
            cout<<-1<<'\n';
            continue;
        }
        if(before<0){
            cout<<v[ans+1]<<'\n';
            continue;
        }
        if(v[ans]==x){
            cout<<v[ans+1]<<'\n';
        }
        else if(abs(x-v[before]) > abs(x-v[ans])){
            cout<<v[ans+1]<<'\n';
        }
        else if(abs(x-v[before]) < abs(x-v[ans])){
            cout<<v[ans]<<'\n';
        }
        else {
            cout<<v[ans+1]<<'\n';
        }
        
    }
    return 0;
}
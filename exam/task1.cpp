#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        unordered_map<char,int> mp;
        for(int j=0;j<str.length();j++){
            mp[str[j]]++;
        }
        bool isvalid=true;
        for(auto iter:mp){
            unordered_map<char,int> copy(mp);
            copy[iter.first]--;
            if(copy[iter.first]==0){
                copy.erase(iter.first);
            }
            isvalid=true;
            for(auto iter1:copy){
            //    cout<<iter1.first<<" "<<iter1.second<<'\n';
            }
            //cout<<iter.first<<" ";
            for(auto iter1:copy){
              //  cout<<iter1.first<<" "<<iter1.second<<'\n';
                for(auto iter2:copy){
                    if(iter1.first==iter2.first || iter2.second==0){
                        continue;
                    }
                    if(iter2.second!=iter1.second){
                      //  cout<<iter1.second<<" "<<iter2.second<<'\n';
                        isvalid=false;
                        break;
                    }
                }
                if(!isvalid)
                    break;
            }
            if(isvalid)
                break;
            copy[iter.first]++;
          //  cout<<isvalid<<" ";
        }
        if(isvalid){
            cout<<1<<"\n";
        }
        else{
            cout<<0<<'\n';
        }
    }
    return 0;
}
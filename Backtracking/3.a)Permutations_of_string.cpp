#include <bits/stdc++.h>
using namespace std;

void permute(int start, int len, string &currstr, set<string> &permutations){
    if(start == len-1){
        permutations.insert(currstr);
        return;
    }
    for(int i=start;i<len;i++){
        swap(currstr[start],currstr[i]);
        permute(start+1,len,currstr,permutations);
        swap(currstr[start],currstr[i]);
    }
}

void print(set<string> &permutations){
    for(auto str:permutations){
        cout<<str<<" ";
    }
    cout<<endl;
}

int main() {
    int t;
    string s;
    cin>>t;
    while(t--){
        string currstr;
        set<string> permutations;
        cin>>s;
        currstr = s;
        int len = s.length();
        permute(0,len,currstr,permutations);
        print(permutations);
    }
	return 0;
}
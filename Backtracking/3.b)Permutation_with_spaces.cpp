//PROBLEM LINK
//https://practice.geeksforgeeks.org/problems/permutation-with-spaces/0

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

#include<bits/stdc++.h>
using namespace std;

void permutations(int start,int len, string &str, set<string> &strings){
    if(start == len-1){
        strings.insert(str);
        return;
    }
    permutations(start+1,len,str,strings);
    str.insert(start+1," ");
    permutations(start+2,len+1,str,strings);
    str.erase(start+1,1);
}

void print(set<string> &strings){
    for(auto str:strings){
        cout<<"("<<str<<")";
    }
    cout<<endl;
}

int main(){
    int t;
    string s;
    cin>>t;
    while(t--){
        set<string> strings;
        cin>>s;
        permutations(0,s.length(),s,strings);
        print(strings);
    }
}
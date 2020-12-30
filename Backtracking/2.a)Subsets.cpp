//PROBLEM LINK
//https://practice.geeksforgeeks.org/problems/subsets/0

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

#include <bits/stdc++.h>
using namespace std;

//Pass by value
// void subsets(int i,int arr[],int n,set<vector<int>> &s, vector<int> currset){
//     if(i == n){
//         s.insert(currset);
//         return;
//     } 
//     subsets(i+1,arr,n,s,currset);
//     currset.push_back(arr[i]);
//     subsets(i+1,arr,n,s,currset);
// }


//Pass by reference
void subsets(int i,int arr[],int n,set<vector<int>> &s, vector<int> &currset){
    if(i == n){
        s.insert(currset);
        return;
    } 
    subsets(i+1,arr,n,s,currset);
    currset.push_back(arr[i]);
    subsets(i+1,arr,n,s,currset);
    currset.pop_back();
}

void print(set<vector<int> > &s){
    for(auto x:s){
        cout<<"(";
        for(int i = 0;i<x.size();i++){
            if(i == x.size()-1){
                cout<<x[i];
            }
            else{
                cout<<x[i]<<" ";
            }
        }
        cout<<")";
    }
    cout<<endl;
}
int main() {
	int t,i,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int arr[n];
	    
	    for(i=0;i<n;i++)
	        cin>>arr[i];
	   
	    sort(arr,arr+n);
	    set<vector<int> > s;
	    vector<int> currset;
	    subsets(0,arr,n,s,currset);
	    print(s);
	        
	}
	return 0;
}
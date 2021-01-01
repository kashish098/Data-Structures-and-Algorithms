//PROBLEM LINK: https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE
#include <bits/stdc++.h>
using namespace std;

bool isSubset(int i, int arr[], int n,bool vis[],int sum, int target){
    
    if(sum == target)
        return true;
        
    if(i == n){
        return false;
    }
    
    if(vis[i]){
        return isSubset(i+1,arr,n,vis,sum,target);
    }
    
    if(isSubset(i+1,arr,n,vis,sum,target)){
        return true;
    }
    sum += arr[i];
    
    if(isSubset(i+1,arr,n,vis,sum,target)){
        vis[i] = true;
        return true;
    }
    
    return false;
}

bool isKPartitionPossible(int A[], int N, int K)
{
    bool vis[N];
    for(int i=0;i<N;i++) vis[i] = false;
    sort(A,A+N);
    int sum = 0;
    for(int i=0;i<N;i++) sum += A[i];
    if(sum%K) return false;
    if(A[N-1] > sum/K) return false;
    for(int i=1;i<K;i++){
        if(!isSubset(0,A,N,vis,0,sum/K)){
            return false;
        }
    }
    return true;
}
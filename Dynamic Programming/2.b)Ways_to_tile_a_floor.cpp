//PROBLEM LINK
https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

#define m 1000000007
class Solution {
  public:
    long long numberOfWays(long long N) {
        if(N == 1){
            return 1;
        }
        long long  a = 1, b = 1, c;
        
        for(int i=2;i<=N;i++){
            c = (a + b)%m;
            a = b;
            b = c;
        }
        return b;
    }
};
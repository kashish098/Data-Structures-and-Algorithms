//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

// 1) Find if a string is subsequence of other string
//     https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        if(m == 0 || n == 0) return 0;
        vector<vector<short>> dp(m+1, vector<short>(n+1));

        int i,j;
        for(i=0;i<=m;i++){
            for(j=0;j<=n;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];  
    }
    
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        return longestCommonSubsequence(s, t) == s.length();
    }
};


// 2) Find the shortest common supersequence 
//     https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1


int lcs(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    if(m == 0 || n == 0) return 0;
    vector<vector<int>> dp(m+1, vector<int>(n+1));

    int i,j;
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(text1[i-1] == text2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];  
}

int shortestCommonSupersequence(char* X, char* Y, int m, int n) {
    string s1(X);
    string s2(Y);
    return m + n - lcs(s1, s2);
}


// 3) Print LCS(Longest common subsequence)
//     https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1

class Solution{
	public:

        void mergeset(set<string> &s1, set<string> &s2){
            set_union(s1.begin(), s1.end(),s2.begin(), s2.end(), inserter(s1, s1.begin()));
        }

        void addset(set<string> &s1, set<string> &s2, string c){
            if(s2.size() == 0){
                s1.insert(c);
            }
            else{
                for(auto str:s2){
                    s1.insert(str + c);
                }    
            }
        }
		vector<string> all_longest_common_subsequences(string s, string t){
            int m = s.length(), n = t.length();
            if(m == 0 || n == 0) return vector<string>();
            vector<vector<set<string>>> dp(m+1, vector<set<string>>(n+1, set<string>()));
            int i,j;
            for(i=0;i<=m;i++){
                for(j=0;j<=n;j++){
                    if(i == 0 || j == 0){
                        
                    }
                    else if(s[i-1] == t[j-1]){
                        addset(dp[i][j], dp[i-1][j-1], s.substr(i-1,1));
                    }
                    else{
                        int size1, size2;
                        if(dp[i-1][j].size() == 0){
                            size1 = 0;
                        }
                        else{
                            size1 = (*dp[i-1][j].begin()).size();
                        }
                        
                        if(dp[i][j-1].size() == 0){
                            size2 = 0;
                        }
                        else{
                            size2 = (*dp[i][j-1].begin()).size();
                        }
                        
                        int temp = max(size1, size2);
                        if(size1 == temp){
                            mergeset(dp[i][j], dp[i-1][j]);
                        }

                        if(size2 == temp){
                            mergeset(dp[i][j], dp[i][j-1]);
                        }
                    }
                }
            }
            
            vector<string> res;
            for(auto s:dp[m][n]){
                res.push_back(s);
            }
            return res;
		}
};

// 4) Print SCS(Shortest Common supersequence)
//     https://leetcode.com/problems/shortest-common-supersequence/

class Solution {
public:
    vector<vector<int> > lcs(string& x, string& y, int m, int n){
        vector<vector<int> > dp(m+1, vector<int>(n+1));
        int i, j;
        for(i=0;i<=m;i++)
            for(j=0;j<=n;j++)
            {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(x[i-1] == y[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        return dp;
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        string res;
        int m = str1.length(), n = str2.length();
        vector<vector<int> > dp = lcs(str1, str2, m, n);
        int i = m, j = n;
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                res.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i][j-1] > dp[i-1][j]){
                    res.push_back(str2[j-1]);
                    j--;
                }
                else{
                    res.push_back(str1[i-1]);
                    i--;
                }
            }
        }

        if(i == 0){
            while(j){
                res.push_back(str2[j-1]);
                j--;
            }
        }
        else{
            while(i){
                res.push_back(str1[i-1]);
                i--;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


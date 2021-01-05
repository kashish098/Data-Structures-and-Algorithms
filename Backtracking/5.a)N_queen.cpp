#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int n, vector<int> &queenArrangement){
    int i,j,temp;

    //Checks if it is row safe
    for(int r:queenArrangement){
        if(r == row) return false;
    }

    //Check if it upper diagonal safe
    temp = row-1;
    for(i=queenArrangement.size()-1;i>=0;i--){
        if(temp <= 0) break;
        if(temp == queenArrangement[i]) return false;
        temp--;
    }

    //Check if it is lower diagonal safe
    temp = row+1;
    for(i=queenArrangement.size()-1;i>=0;i--){
        if(temp > n) break;
        if(temp == queenArrangement[i]) return false;
        temp++;
    }

    return true;
}

void nqueen(int col, int n, vector<int> &queenArrangement, vector<vector<int> > &possibleQueenArrangements){
    //IT IS 1-BASED INDEXING, SO WE USED col > n, INSTEAD OF col == n
    if(col > n){
        possibleQueenArrangements.push_back(queenArrangement);
        return;
    }
    int row;
    for(row = 1;row <= n;row++){
        if(isSafe(row,col,n,queenArrangement)){
            queenArrangement.push_back(row);
            nqueen(col+1,n,queenArrangement,possibleQueenArrangements);
            queenArrangement.pop_back();
        }
    }
}

void print(vector<vector<int> > &possibleQueenArrangements){
    if(possibleQueenArrangements.size() == 0){
        cout<<"-1"<<endl;
        return;
    }
    for(auto arrangement: possibleQueenArrangements){
        cout<<"[";
        for(auto row : arrangement){
            cout<<row<<" ";
        }
        cout<<"] ";
    }
    cout<<endl;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> queenArrangement;
        vector<vector<int> > possibleQueenArrangements;
        nqueen(1,n,queenArrangement,possibleQueenArrangements);
        print(possibleQueenArrangements);
    }
    return 0; 
}
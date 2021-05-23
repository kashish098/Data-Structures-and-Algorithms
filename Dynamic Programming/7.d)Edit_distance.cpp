//PROBLEM LINK
//https://practice.geeksforgeeks.org/problems/edit-distance3702/1

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE
int editDistance(string str1, string str2){
      int len1 = str1.length(), len2 = str2.length();
      int dpEditDistance[len1+1][len2+1], i, j;
      for(i=0;i<=len1;i++){
          for(j=0;j<=len2;j++){
              if(i == 0)
                  dpEditDistance[i][j] = j;
              else if(j == 0)
                   dpEditDistance[i][j] = i;
              else if(str1[i-1] == str2[j-1])
                   dpEditDistance[i][j] = dpEditDistance[i-1][j-1];
              else
                   dpEditDistance[i][j] = 1+ min(min(dpEditDistance[i][j-1],dpEditDistance[i-1][j]),dpEditDistance[i-1][j-1]);
          }
      }
    return dpEditDistance[len1][len2];
}
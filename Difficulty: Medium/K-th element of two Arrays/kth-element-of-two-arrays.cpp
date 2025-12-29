class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        vector<int> mergerArr ; 
        
        for(int i = 0 ; i < a.size() ; i++) 
        {
            mergerArr.push_back(a[i]);
        }
        
        
        for(int i = 0 ; i < b.size(); i++){
            mergerArr.push_back(b[i]);
        }
        
        sort(mergerArr.begin() , mergerArr.end());
        
        return mergerArr[k-1]; // Because of Zero based Indexing
        
        //TC- O(n+m log(n + m));
        //SC- O(m + n); 
        
    }
};
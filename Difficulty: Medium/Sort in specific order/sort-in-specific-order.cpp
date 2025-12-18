class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        
        priority_queue<int>pqL;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i]%2!=0){
                pqL.push(arr[i]);
            }
        }
        
        priority_queue<int, vector<int>, greater<int>>pqS;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i]%2==0){
                pqS.push(arr[i]);
            }
        }
        
        int i=0;
        while(!pqL.empty()){
            arr[i] = pqL.top();
            pqL.pop();
            i++;
        }
        while(!pqS.empty()){
            arr[i] = pqS.top();
            pqS.pop();
            i++;
        }
        
    }
};
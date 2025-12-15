class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        // removing 2 will remove even sum
        
        // if i will remove 1 it will check 
        // 1 2 3 4 5 6
        // 135   2 46
        // removing 1 will give   246   35 -1 7
        // removing 2 will do leftsum se 1 remove ho jayega rightme judega 
        // removing 3 will do leftsum se 2 remove ho jayega rightme judega 
        
        int es =0;
        int os =0;
        int n = arr.size();
        for(int i=0;i<n;i++){
             if (i%2==0){
                  es+=arr[i];
             }
             else{
                  os+=arr[i];
             }
        }
        
        int ans =0;
        
        for(int i=0;i<n;i++){
             if (i%2==0){
                  es-=arr[i];
                  if (i>0) es+=arr[i-1];
             }
             else{
                 os-=arr[i];
                  if (i>0) os+=arr[i-1];
             }
             
             if (es==os) ans++;
        }
        
        return ans;
    }
};
class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, 
    vector<vector<int>>& queries) {
        int n = arr.size();
        int mx = *max_element(arr.begin(), arr.end());
        vector<bool>exist(mx, false);
        vector<int>left(mx + 5, -1), right(mx + 5, -1);
        vector<int>ans;
        for(int i = 0; i < n; i++)
        {
            int a = arr[i];
            exist[a] = true;
            right[a] = i;
            if(left[a] == -1)
            {
                left[a] = i;
            }
        }
        for(auto &query : queries)
        {
            int l = query[0], r = query[1], x = query[2];
            int lx = left[x], rx = right[x];
            int freq = 0;
            lx = max(lx, l), rx = min(rx, r);
            freq = (1 + rx) - lx;
            if(exist[x] == false || freq < 0)freq = 0;
            ans.push_back(freq);
        }
        return ans;
    }
};
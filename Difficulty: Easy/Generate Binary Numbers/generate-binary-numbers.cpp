class Solution {
    enum {
        zero,
        one
    } num;
    map<int, char> mp = { {zero, '0'}, {one, '1'} };
    string dogenerate(int val){
        string str;
        while( val > 0 ){
            int left = val % 2;
            val = val / 2;
            str = mp[left] + str;
        }
        return str;
    }
  public:
    vector<string> generateBinary(int n) {
        vector<string> res;
        for(int i = 0; i < n; i++){
            string curstr = dogenerate(i + 1);
            res.push_back(curstr);
        }
        return res;
    }
};
class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        
        //sort because the larger cost will be incurred for the least number of segment to cut.
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int min_cost = 0;
        int horizontalSegment = 1;
        int verticalSegment = 1;
        int x_len = m-1;
        int y_len = n-1;
        int i = x_len-1;
        int j = y_len - 1;
        
        //iterate in reverse order and check which cost is larger and incurr that
        while(i>=0 && j>=0){
            if(x[i]>=y[j]){
                min_cost+=(x[i]*horizontalSegment);
                verticalSegment++;
                i--;
            }
            else
            {
                min_cost+=(y[j]*verticalSegment);
                horizontalSegment++;
                j--;
            }
        }
        //check whether n*m cells have been cut or not.
        while(i>=0){
            min_cost+=(x[i]*horizontalSegment);
            verticalSegment++;
            i--;
        }
        while(j>=0){
            min_cost+=(y[j]*verticalSegment);
            horizontalSegment++;
            j--;
        }
        //return the minimum cost.
        return min_cost;
    }
};
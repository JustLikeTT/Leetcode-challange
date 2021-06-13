/**
Runtime: 8 ms, faster than 64.05% of others
Memory Usage: 13.7 MB, less than 52.65% of others
主要還是練習 Dynamic programming，題目給每步階梯所要花費的成本，每一次只能往上踩一步或兩步，求最小成本是多少。
值得注意的是，DP原本需要用到O(N)的空間複雜度，不過因為每次計算只要前兩個階梯的最小成本就好，所以讓變數做 swap 就好，
在不影響時間複雜度的情況下，空間複雜度直接變成O(1)。
*/
int minCostClimbingStairs(vector<int>& cost) {
    int pre_two = cost[0], pre_one = cost[1];
          int result=0;
          for(size_t i=2; i<cost.size(); i++){
              result = cost[i] + min(pre_one, pre_two);
              pre_two = pre_one;
              pre_one = result;
          }

    return min(pre_two, pre_one);
}

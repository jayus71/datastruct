#include<array>
#include<algorithm>
#include "../base.h"

// 找零问题中的备忘录，当下标为amount时，代表金额为amount时所需的最少硬币数量
int memo_change[MAXSIZE];
/**
 * @brief 找零钱问题的暴力解法
 * 
 * @param coins 其中包含硬币的面值（例如共有：1，2，5三种面值）
 * @param amount 需要找零的钱数
 * @param len coins数组的长度
 * @return int 当数量为amount时，需要的最少硬币数量
 */
int Change(int coins[], int amount, int len){
    if(amount == 0)
        return 0;
    if(amount < 0)
        return -1;
    int res = 999;
    for(int i = 0; i < len; i++){
        // 当减去某面值时所需的硬币个数，例如共有：1，2，5三种面值，amount为11，
        // 则subProblems 即为：10，9，6所需的最小硬币数量
        int subProblems = Change(coins,amount - coins[i], len);
        if (subProblems == -1)
            continue;
        // 和当前最小值比较
        res = std::min(res,subProblems+1);
    }
    return (res == 999)? -1: res;
}

/**
 * @brief 带备忘录的递归，将已经计算出来的结果存入memo备忘录中，减少重复计算
 * 
 * @param coins 硬币面值的数组
 * @param amount 待找零金额
 * @param len coins长度
 * @return int 金额为amount时最少所需硬币数量
 */
int Change_Memo(int coins[], int amount, int len){
    for (size_t i = 0; i < MAXSIZE; i++)
    {
        memo_change[i] = -666;
    }
    
    return dp_change_memo(coins,amount,len);
}

/**
 * @brief 找零问题中带备忘录的构造memo的函数
 * 
 * @param coins 硬币面值的数组
 * @param amount 待找零金额
 * @param len coins长度
 * @return int 金额为amount时最少所需硬币数量
 */
int dp_change_memo(int coins[], int amount, int len){
    if(amount == 0)
        return 0;
    if(amount < 0)
        return -1;
    int res = 999;
    // 已经计算过amount的所需硬币数，防止重复计算
    if(memo_change[amount] != -666)
        return memo_change[amount];
    for(int i = 0; i < len; i++){
        int subProblem = dp_change_memo(coins,amount-coins[i],len);
        if(subProblem == -1)
            continue;
        res = std::min(res,subProblem+1);
    }
    memo_change[amount] = (res == 999)? -1: res;
    return memo_change[amount];
}

/**
 * @brief 求数组中最长递增子序列（可以不连续）
 * 使用dp数组：dp[i]的含义是，以nums[i]结尾的最长递增子序列的长度
 * @param nums 待处理数组
 * @param len 数组长度
 * @return int 最长递增子序列长度
 */
int LengthOfLIS(int nums[], int len){
    int dp[MAXSIZE];
    // base case：每个元素的最长递增子序列至少包含自己，即为1
    for(int i = 0; i < len; i++){
        dp[i] = 1;
    }
    // 遍历一边数组，对nums[i]找之前的比nums[i]小的nums[j]
    // 找到最长的递增子序列（nums[j]+1的最大值）
    for(int i = 0; i < len; i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                dp[i] = std::max(dp[i], dp[j]+1);
            }
        }
    }
    int res = -999;
    // 此时dp中存的是以对应元素结尾的最大递增子序列长度
    for(int i = 0; i < len; i++){
        if(res < dp[i])
            res = dp[i];
    }
    return res;
}


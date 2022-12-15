import java.util.Arrays;

/**
 * dp_lcs
 * 计算两个序列的最长公共子序列长度
 */
public class dp_lcs {

    // 备忘录，消除重叠子问题
    int[][] memo;

    /**
     * 找到两个字符串中的最长公共子序列长度
     * @param s1
     * @param s2
     * @return 返回最大长度
     */
    public int longestCommonSubsequence(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        // 备忘录值为 -1 代表未曾计算
        memo = new int[m][n];
        for (int[] row : memo)
            Arrays.fill(row, -1);
        // 计算 s1[0..] 和 s2[0..] 的 lcs 长度
        return dp(s1, 0, s2, 0);
    }

    /**
     * 定义：计算 s1[i..] 和 s2[j..] 的最长公共子序列长度
     * @param s1 待计算字符串1
     * @param i s1从i开始
     * @param s2 待计算字符串2 
     * @param j s2从j开始
     * @return 返回s[i...]和s[j...]的最长公共子序列长度
     */
    public int dp(String s1, int i, String s2, int j) {
        // base case
        if (i == s1.length() || j == s2.length()) {
            return 0;
        }
        // 如果之前计算过，则直接返回备忘录中的答案
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        // 根据 s1[i] 和 s2[j] 的情况做选择
        // 若二者该位置的字符相等，则必然在lcs中
        if (s1.charAt(i) == s2.charAt(j)) {
            // s1[i] 和 s2[j] 必然在 lcs 中
            memo[i][j] = 1 + dp(s1, i + 1, s2, j + 1);
        } else {
            // s1[i] 和 s2[j] 至少有一个不在 lcs 中
            // 返回两种情况的最大值，并记录在memo[i][j]中
            memo[i][j] = Math.max(
                    dp(s1, i + 1, s2, j),
                    dp(s1, i, s2, j + 1));
        }
        // 返回结果
        return memo[i][j];
    }
}
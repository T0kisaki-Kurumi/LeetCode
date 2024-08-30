package 笔试;

import java.util.Scanner;

/**
 * @author robbie
 * @date Created in 2024/08/19
 */

public class 小红卖宝石 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] x = new int[n + 1];
        int[] y = new int[n + 1];
        int[] z = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            x[i] = scanner.nextInt();
            y[i] = scanner.nextInt();
            z[i] = scanner.nextInt();
        }
//        for(int i : x){
//            System.out.print(i + " ");
//        }
//        System.out.println();
//        for(int i : y){
//            System.out.print(i + " ");
//        }
//        System.out.println();
//        for(int i : z){
//            System.out.print(i + " ");
//        }
//        System.out.println();
        int[][] dp = new int[n + 1][m + 1];  // dp[i][j] 第i个事件后，拥有j个宝石时的最大金币数
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = -1;  // -1表示，第i个事件后，不可能有j个宝石
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            // 卖
            for (int j = 0; j <= m - x[i]; j++) {
                if (dp[i - 1][j + x[i]] != -1) {
                    dp[i][j] = dp[i - 1][j + x[i]] + y[i];
                }
            }
            // 获得
            for (int j = 0; j <= m; j++) {
                if (j + z[i] >= m) {
                    dp[i][m] = Math.max(dp[i][m], dp[i - 1][j]);
                } else {
                    dp[i][j + z[i]] = Math.max(dp[i][j+z[i]], dp[i - 1][j]);
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }
        int res = 0;
        for (int j = 0; j <= m; j++) {
            res = Math.max(res, dp[n][j] + j);
        }
        System.out.println(res);
    }
}

/**
 * https://www.dotcpp.com/oj/problem1178.html
 * 题目描述
 * 你的任务呢，是将一个有理数转换成三进制小数。“什么是三进制小数呢？”你一定会问，这很明白，就是以三为基（二进制数以2为基，而十进制数则以10为基）的小数。
 *
 * 输入
 * 有理数的值都是在0与1之间的，每个有理数都由一个分子和一个分母表示，分子与分母之间隔着一个斜杠。有理数的个数不会超过1000个。
 *
 * 输出
 * 输出格式见样本输出，它是以小数点开头的具有10位精度的3进制数。
 *
 *
 * 样例输入
 * 1/3
 * 1/4
 * 1/6
 * 7/8
 * 样例输出
 * .1000000000
 * .0202020202
 * .0111111111
 * .2121212122
 *
 */
#include<iostream>

using namespace std;

int main() {
    int ans[11], ap;
    int a, b;
    char c;
    while (cin >> a >> c >> b) {
        ap = 0;
        // 进制转换：
        while (ap <= 10) {
            // (a/b) * R 顺取整
            ans[ap++] = (a * 3) / b;
            // 保留小数部分(余数/分母)
            a = (a * 3) % b;
        }
        // 3进制精度控制：1舍2入
        if (ans[10] >= 2) {
            ans[9]++;
        }
        // 处理进位
        for (int i = 9; i >= 0; i--) {
            if (i > 0) {
                ans[i - 1] += ans[i] / 3;
            }
            ans[i] %= 3;
        }
        // 输出仅保留小数部分
        cout << ".";
        for (int i = 0; i < 10; i++) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}

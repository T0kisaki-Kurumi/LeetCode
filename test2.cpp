// 提取字符串中的最长合法简单数学表达式，字符串长度最长的，并计算表达式的值。如果没有，则返回0
// 简单数学表达式可能包含以下内容
// 0-9数字，符号 +-*
// 说明：
// 1. 所有数字，计算结果都不超过long
// 2. 如果有多个长度一样的，请返回第一个表达式的结果
// 样例1
// 输入
// "1-2abcd"
// 输出
// -1
// 说明
// 提取表达式为 1-2 = -1
// 样例2
// 输入
// "1-2*3-5*0abcd"
// 输出
// -5
// 说明
// 1-2*3-5*0=-5

#include

#include

#include

using namespace std;

int main()
{

    string line;

    getline(cin, line);

    long long res = 0;

    int maxLen = 0;

    int len = line.length();

    for (int i = 0; i < len; i++)
    {

        if (len - i <= maxLen)
        {

            break;
        }

        for (int j = i; j < len; j++)
        {

            string sub = line.substr(i, j - i + 1);

            smatch match;

            regex pattern("(\\d+)([*+-])(\\d+)");

            if (regex_search(sub, match, pattern) && j + 1 - i > maxLen)
            {

                maxLen = j + 1 - i;

                long long first = stoll(match[1]);

                string op = match[2];

                long long second = stoll(match[3]);

                if (op == "+")
                {

                    res = first + second;
                }
                else if (op == "-")
                {

                    res = first - second;
                }
                else if (op == "*")
                {

                    res = first * second;
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}
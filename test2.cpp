
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
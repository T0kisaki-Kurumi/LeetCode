#include <iostream>
#include <string>
#include <regex>
using namespace std;

void regex_match_test()
{
	/* std::regex_match:
		判断一个正则表达式(参数re)是否匹配整个字符序列str,它主要用于验证文本
		注意:  这个正则表达式必须匹配被分析串的全部，
			   否则返回false;如果整个序列被成功匹配，返回true
	*/
	string s = "cca,tt";
	vector<regex> regs;
	vector<string> patterns = {
		"ccaatt",
		"cca.tt",            // .    匹配除换行符以外的任意字符。
		"cca[abcde]tt",      // []   字符类，匹配方括号中包含的任意字符。
		"cc[^bcde]att",      // [^]  否定字符类。匹配方括号中不包含的任意字符
		"ccaa*tt",           // *    匹配前面的子表达式零次或多次
		"c+a+t+",            // +    匹配前面的子表达式一次或多次
		"cc?aatt?",          // ?    匹配前面的子表达式零次或一次，或指明一个非贪婪限定符。 
		                     //      此处说明一下，出现一次或零次的意思可以理解为?前面的字符可出出现可不出现
							 //      注意它与 * 的区别 
		"ccaat{1,2}",        //{n,m} 花括号，匹配前面字符至少 n 次，但是不超过 m 次。 
		"(ccaatt)",          //(xyz)	字符组，按照确切的顺序匹配字符xyz。
		"(c(h|d|f)aatt)|(ccaatt)",    // |   分支结构，匹配符号之前的字符或后面的字符。
		                              // \   转义符，它可以还原元字符原来的含义，允许你匹配保留字符 [ ] ( ) { } . * + ? ^ $ \ |
	    "^ccaatt", 	 				  // ^   匹配行的开始
		"ccaatt$"   	     	      // $   匹配行的结束
	};
	
	for(int i = 0;i < patterns.size(); i++) 
		regs.push_back(regex(patterns[i]));
	
	for(int i = 0;i < regs.size(); i++)
	{
		if(regex_match(s,regs[i]))
			printf("use regex: %25s to match %10s [Match!]\n",patterns[i].c_str(),s.c_str());
		else
			printf("use regex: %25s to match %10s [Failed!]\n",patterns[i].c_str(),s.c_str());
	}
}

void regex_search_test()
{
	/* std::regex_search:
	类似于regex_match,但它不要求整个字符序列完全匹配
	可以用regex_search来查找输入中的一个子序列，
	注意regex_search匹配成功一个后面的不再匹配 
	*/
	
	string lines[] = {"Roses are #ff0000",
                      "violets are #0000ff",
                      "all of my base are belong to you"};
 
    regex color_regex("#[a-f0-9]{2}""[a-f0-9]{2}""[a-f0-9]{2}");
 
    // 简单匹配
    for (const auto &line : lines) {
        std::cout << line << ": " << std::boolalpha
                  << std::regex_search(line, color_regex) << '\n';
    }   
    std::cout << '\n';
 
    // 展示每个匹配中有标记子表达式的内容
    smatch color_match;
    for (const auto& line : lines) {
        if(regex_search(line, color_match, color_regex)) {
            cout << "matches for '" << line << "'\n";
            cout << "Prefix: '" << color_match.prefix() << "'\n";
            cout << color_match[0] << '\n';
            cout << "Suffix: '" << color_match.suffix() << "\'\n\n";
        }
    }
 
    // 重复搜索（参阅 std::regex_iterator ）
    std::string log(R"(   \
        Speed:	366       \
        Mass:	35        \
        Speed:	378       \
        Mass:	32        \
        Speed:	400       \
		Mass:	30)");
    std::cout<<log<<std::endl;
    regex r(R"(Speed:\t\d*)");
    smatch sm;
    while(regex_search(log, sm, r))
    {
        std::cout << sm.str() << '\n';
        log = sm.suffix();
    }
 
    // C 风格字符串演示
    cmatch cm;
    if(regex_search("this is a test", cm, regex("test"))) 
        cout << "\nFound " << cm[0] << " at position " << cm.prefix().length() << endl;
}

void regex_replace_test()
{
	std::string text = "{{ name }} for brown fox",replace_result;
 	std::regex double_brace("(\\{\\{) (.*) (\\}\\})");
	
	//regex_replace返回值即为替换后的字符串 
	replace_result = regex_replace(text,double_brace,"*");
	cout << replace_result << "\n";
 
 	//构造存有结果的字符串，[$&]即为用[]将匹配成功部分括起来 
 	// $&	Inserts the matched substring.	 
	cout << regex_replace(text, double_brace, "[$&]") << '\n';
	
	// $i则输出double_brace中第i个括号匹配到的值 
	cout << regex_replace(text, double_brace, "$1") << '\n';
	cout << regex_replace(text, double_brace, "[$2]") << '\n';
	cout << regex_replace(text, double_brace, "$3") << '\n';
}

int main ()
{
	// cout << "regex_match examples : " << endl;
	// regex_match_test();
	
	cout << endl << "regex_search examples : " << endl;
	regex_search_test();
	
	// cout << endl << "regex_replace examples : " << endl << endl;
	// regex_replace_test();

    system("pause");
	
	return 0;
}
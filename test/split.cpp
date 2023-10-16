#include <iostream>
#include <vector>
#include <regex>
using namespace std;


void Stringsplit(const string& str, const string& split, vector<string>& res)
{
	regex reg(split);
	sregex_token_iterator pos(str.begin(), str.end(), reg, -1);
	decltype(pos) end;
	for (; pos != end; ++pos){
		res.push_back(pos->str());
	}
}

int main(){
	vector<string> res;
	string s("尹1康1华1s1b");
	Stringsplit(s,"1", res);
	for (auto s : res)
		cout << s;
    system("pause");
}
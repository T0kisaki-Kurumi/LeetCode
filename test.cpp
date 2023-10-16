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
	string s("尹 康 华 s b");
	Stringsplit(s," ", res);
	for (auto s : res)
		cout << s;
    system("pause");
}
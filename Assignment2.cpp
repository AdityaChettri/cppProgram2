/*Author:Aditya Chettri
DOC:17th November2020
Finding all substrings of a given string that contains all characters of other string.
*/
#include<iostream>
#include<string>
#include <iterator>
#include <unordered_set>
using namespace std;
void subString(string str1, string str2,int m, int n)
{
		unordered_multiset<char> super;
    	unordered_multiset<char> sub;
		for (int i = 0; i < m; i++)
			sub.insert(str2[i]);
		for (int i = 0; i < n; i++)
		{
		if (i < m)
			super.insert(str1[i]);
	
		else
		{
			if (super == sub)
			{
				cout << "Substring " << str1.substr(i - m, m) <<
					" present at index " << i - m << '\n';
			}
			auto itr = super.find(str1[i - m]);
			if (itr != super.end())
				super.erase(itr);
			super.insert(str1[i]);
		}
	}

	if (super == sub)
	{
		cout << "Substrig " << str1.substr(n - m, m) <<
			" present at index " << n - m << '\n';
	}
}
int main()
{
	string str1 = "XYYZXZYZXXYZ";
	string str2 = "XYZ";
	int a=str1.length();
	int b=str2.length();
	subString(str1,str2,a,b);

	return 0;
}


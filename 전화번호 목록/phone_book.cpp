#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	// sort phone_book for lexicographic order
	sort(phone_book.begin(), phone_book.end());

	map<string, int> m;

	for (string str : phone_book)
	{
		int n = str.length();
		// check if prefix matching in map
		for (int i = 0; i < n; i++)
		{
			//string substring = str.substr(0, i+1);
			//cout << substring << endl;
			map<string, int>::iterator it = m.find(str.substr(0, i + 1));
			if (it != m.end() && it->second == 1)
			{
				return false;
			}
		}

		// add str into map
		m.insert(make_pair(str, 1));
	}


	return answer;
}

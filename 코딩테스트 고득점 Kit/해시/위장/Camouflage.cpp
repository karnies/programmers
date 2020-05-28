#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;

	// make hash_map and multiply of all (count+1) - 1
	unordered_map<string, int> m;
	for (vector<string> vs : clothes)
	{
		m[vs[1]]++;
	}

	answer = 1;
	for (pair<string, int>p : m)
	{
		answer *= (p.second + 1);
	}
	answer--;
	return answer;
}

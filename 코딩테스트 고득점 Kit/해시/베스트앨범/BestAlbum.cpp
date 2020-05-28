#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

template<template <typename> class P = less >
struct compare_pair_second {
	template<class T1, class T2> 
	bool operator()(const pair<T1, T2>&left, const pair<T1, T2>&right) {
		return P<T2>()(left.second, right.second);
	}
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	int n = plays.size();

	// make hash for sumation of plays and pair(idx, plays)
	unordered_map<string, int> m;
	unordered_map<string, vector<pair<int, int>>> mm;
	for (int i = 0; i < n; i++)
	{
		m[genres[i]] += plays[i];
		mm[genres[i]].emplace_back(make_pair(i, plays[i]));
	}

	// sort hash by value(plays)
	vector<pair<string, int> > vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), compare_pair_second<less>());

	// Sorting vectors with genres as keys to print only two large ones
	while (!vec.empty())
	{
		pair<string, int> p = vec.back();
		vec.pop_back();

		vector<pair<int, int>> v = mm[p.first];
		if (v.size() > 1)
		{
			sort(v.begin(), v.end(), compare_pair_second<greater>());
			for (int i = 0; i < 2; i++)
				answer.emplace_back(v[i].first);
		}
		else
		{
			answer.emplace_back(v[0].first);
		}
	}

	return answer;
}

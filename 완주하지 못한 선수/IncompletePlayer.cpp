#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
	// The requirement in question is "use hash"
    // make hash
    map<string, int> m;
    for(string str:completion)
    {
        map<string, int>::iterator it;
        it = m.find(str);
        if(it != m.end())
            it->second++;
        else
            m.insert(make_pair(str, 1));
    }
    
	// if count is zero? then that player is answer
    for(string str:participant)
    {
        //cout << "check : " << str << endl;
        map<string, int>::iterator it;
        it = m.find(str);
        if(it == m.end())
        {
            answer = str;
            break;
        }
        else
        {
            //cout << "second : " << it->second << endl;
            if(it->second == 0)
            {
                answer = str;
                break;
            }
            else
            {
                it->second--;
            }
        }
    }

    return answer;
}
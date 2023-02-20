#if 0
#define TEST
#endif // 1
#define TEST1

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX_LOOP	(100)
#define MAX_ARR		(MAX_LOOP+1)

#define FOR_INC(i, from, to) for (int (i)=(from); (i)<(to); ++(i))
#define FOR(i, to) FOR_INC((i), 0, (to))
	
static const int WarnIfNot(const int condFlag, const char* condition){
 	if (condFlag == 0) {
        cout << "Warning: [" << condition << "] is violated!\n";
    }
    return condFlag;
}
#define W_IFNOT(cond) WarnIfNot((cond), (#cond))
#define P_IFNOT(cond, var) if (!W_IFNOT(cond)) cout << "= " << var <<endl;

//char loop[MAX_ARR];
string loop;

void Input_Data(void)
{
	getline(cin, loop);
	getline(cin, loop);
}


bool isPair(const char c1, const char c2) {
	return (c1 == '<' && c2 == '>');
}

bool isOpening(const char c) {
	return (c == '<');
}
bool isClosing(const char c) {
	return (c == '>');
}

typedef pair<char, int> ci;

#define TEST1

string rollout(const string& str) {
#ifdef TEST
	cout << str <<endl;
#endif
	auto it = begin(str);
	auto itLast = find_if_not(it, end(str), [](auto& s){return ((s>='0') && (s<='9'));});
	const int numL = distance(it, itLast);
	string strNum = str.substr(0, numL);
	string strAlpha= str.substr(numL, distance(itLast, end(str)));
	const int num = stoi(strNum);
	string result("");
	FOR(i, num) {
		result += strAlpha;
	}
#ifdef TEST
	cout << result <<endl;
#endif

	return result;
}

string compile(string& s) {
#ifdef TEST
	cout << s <<endl;
#endif
	while (find(begin(s), end(s), '>') != end(s)){
		stack<ci> m_S;
		FOR(i, s.length()) {
			const char c = s[i];
			if (isOpening(c)) {
				m_S.push(ci(s[i], i));
				continue;
			}
			if (isClosing(c)) {
				if (!m_S.empty()) {
					if (isPair(m_S.top().first, c)) {
						const int beginIdx = m_S.top().second+1;
						string sub = s.substr(beginIdx, i-beginIdx);
						sub = rollout(sub);
						string prev(s.substr(0, beginIdx-1));
						string post(s.substr(i+1, s.length()-i));
						s = prev + sub;
						s = s + post;
#ifdef TEST
	cout << prev << post <<endl;
	cout << "ongoing: " << s << endl;
#endif
						m_S.pop();
						break;
					}
					else return "Error: not paired";
				}
			}
		}
	}
	return s;
}

int main(void)
{
	// 입력 받는 부분
	Input_Data();

	// 코드를 작성하세요
	string result;
	cout << compile(loop);
	
	return 0;
}

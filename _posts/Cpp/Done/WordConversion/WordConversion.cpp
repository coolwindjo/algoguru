#if 1
#define TEST
#endif // 1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O1") 
#endif 

typedef unordered_set<string> hashstr;

class ProbSolv
{
    string m_strBegin;
    string m_strTarget;
    vstr m_vstrWords;
public:
    ProbSolv()
    {
        string line;
        FOR (i, 10) {
            getline(cin, line);
            if (line.length()>2) {
                break;
            }
        }

        vstr vstrSplits = _SplitString(line, "[]\", ");
        m_strBegin = vstrSplits[0];
        m_strTarget = vstrSplits[1];
        FOR_INC (i, 2, vstrSplits.size()) {
            m_vstrWords.push_back(vstrSplits[i]);
        }
        
        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        cout << solution(m_strBegin, m_strTarget, m_vstrWords);
    } // _Solve()

    int solution(string begin, string target, vector<string> words) {
        int answer = 51;
        
        hashstr hashWords;
        int cnt = 0;
        DFS(answer, hashWords, cnt, begin, target, words);
        if (answer == 51) {
            answer = 0;
        }
        
        return answer;
    }

    int Diff(const string& str1, const string& str2)
    {
        int cnt = 0;
        for (int i=0; i<str1.length(); ++i) {
            if ((str1[i] - str2[i]) != 0) {
                cnt++;
            }
        }
        if (cnt > 1) {
            return -1;
        }
        return cnt;
    }

    void DFS(int& minCntOut, hashstr& hashWords, const int cnt, const string& curWord, const string& target, const vstr& words)
    {
        if (cnt >= minCntOut) {
            return;
        }
        
        if (target.compare(curWord) == 0) {
            minCntOut = cnt;
            return;
        }
        
        for (int i=0; i<words.size(); ++i) {
            const string nextWord = words[i];
            auto it = hashWords.find(nextWord);
            if (it != end(hashWords)) {
                continue;
            }
            if (Diff(curWord, nextWord) <= 0) {
                continue;
            }
            hashWords.emplace(nextWord);
            DFS(minCntOut, hashWords, cnt+1, nextWord, target, words);
            hashWords.erase(nextWord);
        }
    }

#if 0   // 70yy
#define SPLIT_DEBUG
#endif // 1

    vstr _SplitString(string line, const string& delims, const string& separator = "") {
#ifdef SPLIT_DEBUG
        cout << "\n1) line: " << line <<endl;
#endif
        string::iterator newEnd = unique(line.begin(), line.end(), [] (const char &x, const char &y) {
            return x==y and x==' ';
        });
#ifdef SPLIT_DEBUG
        cout << "2) line: " << line <<endl;
#endif

        line.erase(newEnd, line.end());
#ifdef SPLIT_DEBUG
        cout << "3) line: " << line <<endl;
#endif

        while (line[line.length() - 1] == ' ') {
            line.pop_back();
        }
#ifdef SPLIT_DEBUG
        cout << "4) line: " << line <<endl;
#endif

        vstr vstrSplits;

        size_t prev = 0;
        size_t pos;
        while (prev < line.length()) {
            if ((pos = line.find_first_of(delims, prev)) == string::npos) {
                pos = line.length();
            }
            const int wlen = pos - prev;
            if (wlen > 0) {
                size_t sub_prev = 0;
                size_t sub_pos;
                const string sub_str = line.substr(prev, wlen);
                while ((sub_pos = sub_str.find_first_of(separator, sub_prev)) != string::npos) {
                    const int sub_wlen = sub_pos - sub_prev;
                    if (sub_wlen > 0) {
                        vstrSplits.push_back(sub_str.substr(sub_prev, sub_wlen));
                        vstrSplits.push_back(sub_str.substr((sub_prev+sub_wlen), 1));
                    }
                    else {
                        vstrSplits.push_back(sub_str.substr(sub_prev, 1));
                    }
                    sub_prev = sub_pos + 1;
                }
                prev += sub_prev;
                const int rem_wlen = wlen - sub_prev;
                if (rem_wlen > 0) {
                    vstrSplits.push_back(line.substr(prev, rem_wlen));
                }
            }
#ifdef SPLIT_DEBUG
            for(string str : vstrSplits) {
                cout << str << " ";
            }
            cout <<endl;
#endif
            prev = pos + 1;
        }

        return vstrSplits;
    }

};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int numTCs = 0;
    cin >> numTCs;
    FOR (tc, numTCs) {
        cout << "#" << tc+1 <<" ";
        ProbSolv ps;
        cout << endl;
    }
    return 0;
}
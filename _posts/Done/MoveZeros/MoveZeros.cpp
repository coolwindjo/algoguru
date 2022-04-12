#if 0
#define TEST
#endif // 1
#define TEST1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O1")
#endif

class ProbSolv
{
public:
    ProbSolv()
    {
        string line;
        FOR(i, 10){
            std::getline(cin, line);
            if (line.length() > 2) break;
        }
        vstr vstrSplit = _SplitString(line, "=, \n", "[]");
        vi viNums;
        bool startNum = false;
        for (string strNum : vstrSplit) {
            if (strNum == "]") break;
            if (startNum) {
                viNums.push_back(std::stoi(strNum));
            }
            if (strNum == "[") startNum = true;
        }

        _Solve(viNums);
    }
    ~ProbSolv(){}

private:
    void _Solve(vi& viNums){
        moveZeroes(viNums);
        cout << "[";
        for (int num : viNums) {
            cout << num << ", ";
        }
        cout << "]";
    } // _Solve()

    void moveZeroes(vector<int>& nums) {
        FOR(i, nums.size()) {
            const int I = nums[i];
            if (I != 0) continue;
#ifdef TEST
            cout << "I=" << I <<endl;
#endif
            // I is zero
            FOR_INC(j, i+1, nums.size()) {
                const int J = nums[j];
#ifdef TEST
                cout << "J=" << J <<endl;
#endif
                if (J == 0) continue;
                // J is non-zero
                nums[i] = J;
                nums[j] = 0;
#ifdef TEST
                cout << i << "<=>" << j <<endl;
#endif
                break;
            }

        }
    }

#if 0
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
            prev = pos + 1;
        }

        return vstrSplits;
    }

};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int numTCs = 0;
    cin >> numTCs; cin.ignore();
    FOR (tc, numTCs) {
        cout << "#" << tc+1 <<" ";
        ProbSolv ps;
        cout << endl;
    }
    return 0;
}

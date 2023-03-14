#if 1
#define TEST
#endif // 1
#define TEST1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O1")
#endif

class ProbSolv
{
    string num1_;
    string num2_;
public:
    ProbSolv()
    {
        string line;
        FOR(i, 10) {
            getline(cin, line);
            if (line.length() > 2) break;
        }
        vstr vstrInput = _SplitString(line, "\n\t, ", "\"");

        bool isFirst = true;
        bool isOpen = true;
        bool isValid = false;
        for (const auto &s : vstrInput) {
            if (s == "\"") {
                if (isFirst) {
                    if (isOpen) {
                        isOpen = false;
                        isValid = true;
                    }
                    else {
                        isOpen = true;
                        isValid = false;
                        isFirst = false;
                    }
                }
                else {
                    if (isOpen) {
                        isOpen = false;
                        isValid = true;
                    }
                    else {
                        isOpen = true;
                        isValid = false;
                    }

                }
                continue;
            }
            if (isFirst and isValid) num1_ = s;
            else if (isValid) num2_ = s;
        }

        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        cout << addStrings(num1_, num2_);
    } // _Solve()

    string addStrings(string num1, string num2) {
        std::string ans;
        int carry = 0;
        auto it1 = std::rbegin(num1), it2 = std::rbegin(num2);
        for (int i=0; i<10000; ++i) {
            bool inc1 = false;
            bool inc2 = false;
            if (it1 != std::rend(num1)) inc1 = true;
            if (it2 != std::rend(num2)) inc2 = true;

            if (!inc1 and !inc2) break;

            const int n1 = inc1? (*it1) - '0' : 0;
            const int n2 = inc2? (*it2) - '0' : 0;
            int sum = n1 + n2 + carry;
            carry = 0;
            if (sum > 9) {
                carry = 1;
                sum %= 10;
            }

            ans = std::to_string(sum) + ans;

            if (inc1) ++it1;
            if (inc2) ++it2;
        }
        if (carry > 0) ans = std::to_string(carry) + ans;
        return ans;
    }

#if 0
#define SPLIT_DEBUG
#endif // 1

    vstr _SplitString(string line, const string& delims, const string& separator = "") {
#ifdef SPLIT_DEBUG
        line += "       !";
        cout << "\n1) line: " << line <<endl;
        string::iterator newEnd = unique(begin(line), end(line), [](const char& x, const char& y) {
            return x == y and x == ' ';
        });
        cout << "2) line: " << line <<endl;
        line.erase(newEnd, end(line));
        cout << "3) line: " << line <<endl;
#else
        line.erase(unique(begin(line), end(line),
                          [](const char& x, const char& y) { return x == y and x == ' '; }),
                   end(line));
#endif
        while (line[line.length() - 1] == ' ') {
            line.pop_back();
        }

        vstr vstrSplits;
        size_t prev = 0U;
        size_t pos = 0U;
        while (prev < line.length()) {
            if ((pos = line.find_first_of(delims, prev)) == string::npos) {
                pos = line.length();
            }
            const int wlen = pos - prev;
            if (wlen > 0) { // word exists before next delimiter
                size_t sub_prev = 0U;
                size_t sub_pos = 0U;
                const string sub_str = line.substr(prev, wlen);
                while ((sub_pos = sub_str.find_first_of(separator, sub_prev)) != string::npos) {
                    const int sub_wlen = sub_pos - sub_prev;
                    if (sub_wlen > 0) { // word exists before next separator
                        vstrSplits.push_back(sub_str.substr(sub_prev, sub_wlen));
                        vstrSplits.push_back(sub_str.substr((sub_prev + sub_wlen), 1));
                    } else {
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

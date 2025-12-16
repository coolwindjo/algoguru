#if 1
#define TEST
#endif // 1
#define TEST1

#include "../../ProbSolvStart.h"

#if 1
#pragma GCC optimize("O1")
#endif

class ProbSolv
{
    vector<int> nums_;
    int k_;
public:
    ProbSolv()
    {
        string line;
        FOR (i, 10) {
            std::getline(std::cin, line);
            if (line.length() > 2) {
                break;
            }
        }

        vstr vstrInputs = _SplitString(line, "[]k\n,\t ", "=");
        bool firstEq = true;
        bool isNums = false;
        bool isK = false;
        for (const auto &str : vstrInputs) {
            if (str == "=") {
                if (firstEq) {
                    isNums = true;
                    firstEq = false;
                }
                else {
                    isNums = false;
                    isK = true;
                }
                continue;
            }
            if (isNums) {
                nums_.push_back(std::stoi(str));
            }
            else if (isK) {
                k_ = std::stoi(str);
                break;
            }
            else {}
        }

        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        {
            CoolTimer timer("Out of Time");
            cout << boolalpha << OT_containsNearbyDuplicate(nums_, k_) <<endl;
        }
        {
            CoolTimer timer("Answer");
            cout << boolalpha << containsNearbyDuplicate(nums_, k_) <<endl;
        }
    } // _Solve()

    bool containsNearbyDuplicate(const vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i=0; i<nums.size(); ++i) {
            if (++hash[nums[i]] > 1) return true;
            if (i>=k) hash[nums[i-k]] = 0;
        }
        return false;
    }

    bool OT_containsNearbyDuplicate(const vector<int>& nums, int k) {
        for (int i=0; i<nums.size(); ++i) {
            for (int j=i+1; (j<=i+k) && (j<nums.size()); ++j) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }

    vstr _SplitString(string line, const string& delims, const string& separator = "") {
        line.erase(unique(begin(line), end(line),
                          [](const char& x, const char& y) { return x == y and x == ' '; }),
                   end(line));
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

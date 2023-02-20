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
public:
    ProbSolv()
    {
        string line;
        FOR(i, 10) {
            getline(cin, line);
            if (line.length() > 2) {
                break;
            }
        }
        vstr vstrSplit = _SplitString(line, "[]=, \n");
        vi viNums;
        int target = -2;
        for (string num : vstrSplit) {
            if (target == -1) {
                target = stoi(num);
                break;
            }
            if (isalpha(num[0])) {
                target = -1;
                continue;
            }
            viNums.push_back(stoi(num));
        }
        _Solve(viNums, target);
    }
    ~ProbSolv(){}

private:
    void _Solve(vi& viNums, const int target){
        vi viAns = searchRange(viNums, target);
        cout << "[";
        for (int ans : viAns) {
            cout << ans;
            cout << ", ";
        }
        cout << "]";

    } // _Solve()

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        const int MAX_L = log2(nums.size())+3;

        int hi=nums.size()-1;
        int lo=0;
        int min = -1;
        for (int i=0; hi>=lo && i<MAX_L; ++i) {
            // if (!W_IFNOT(hi > -1)) break;
            // if (!W_IFNOT(lo > -1)) break;
            updateHiLoForMin(nums, target, (lo+hi)>>1, hi, lo, min);
        }

        nums.push_back(INF);
        hi=nums.size()-1;
        lo=max(0, min);
        int max = -1;
        for (int i=0; hi>=lo && i<MAX_L; ++i) {
            // if (!W_IFNOT(hi >= 0)) break;
            // if (!W_IFNOT(lo >= 0)) break;
            updateHiLoForMax(nums, target, (lo+hi)>>1, hi, lo, max);
        }

        vi viAns;
        viAns.push_back(min);
        viAns.push_back(max);

        return viAns;
    }

    void updateHiLoForMin(const vi& nums, const int target, const int mid, int &hi, int &lo, int &min) {
        // if (!W_IFNOT(mid <= hi)) return;
        // if (!W_IFNOT(mid >= lo)) return;
        if (nums[mid] == target) {
            min = hi = mid;
        }
        else if (nums[mid] > target) {
            if (hi == mid) hi = mid-1;
            else hi = mid;
        }
        else {
            if (lo == mid) lo = mid+1;
            else lo = mid;
        }
    }

    void updateHiLoForMax(const vi& nums, const int target, const int mid, int &hi, int &lo, int &max) {
        // if (!W_IFNOT(mid <= hi)) return;
        // if (!W_IFNOT(mid >= lo)) return;
        if (nums[mid] == target) {
            max = lo = mid;
        }
        else if (nums[mid] < target) {
            if (lo == mid) lo = mid+1;
            else lo = mid;
        }
        else {
            if (hi == mid) hi = mid-1;
            else hi = mid;
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

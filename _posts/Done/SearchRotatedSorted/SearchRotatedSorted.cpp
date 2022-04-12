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
            std::getline(cin, line);
            if (line.length() > 2) break;
        }
        vstr vstrSplit = _SplitString(line, ", \n", "=[]");
        vi viNums;
        int target = -1;
        bool startNum = false;
        bool targetIsComing = false;
        bool nextIsTarget = false;
        for (string strNum : vstrSplit) {
            if (startNum) {
                if (strNum == "]") {
                    startNum = false;
                    targetIsComing = true;
                    continue;
                }
                viNums.push_back(std::stoi(strNum));
            }

            if (nextIsTarget) {
                target = std::stoi(strNum);
            }

            if (targetIsComing) {
                if (strNum == "=") nextIsTarget = true;
            }

            if (strNum == "[") startNum = true;
        }

        _Solve(viNums, target);
    }
    ~ProbSolv(){}

private:
    void _Solve(vi& viNums, int target){
        cout << search(viNums, target);
    } // _Solve()

    int search(vector<int>& nums, int target) {
        const int MAX_L = log2(nums.size()) + 3;
        int hi=nums.size()-1;
        int lo=0;
        // /*/
        int ans=-1;
        for (int i=0; hi>=lo && i<MAX_L; ++i) {
            const int mid = (hi+lo) >> 1;
            if (nums[mid] == target) {
                ans = mid;
                break;
            }

            if (nums[mid] >= nums[lo]) {
                if (nums[mid] > target && target >= nums[lo]) {
                    hi = mid-1;
                }
                else {
                    lo = mid+1;
                }

            }
            else {
                if (nums[hi] >= target && target > nums[mid]) {
                    lo = mid+1;
                }
                else {
                    hi = mid-1;
                }
            }
        }
        /*/
        bool beforePivot =  (nums[lo]>target) ? false : true;
        if (nums[hi] < nums[lo]) {
            for (int i=0; hi>lo && i<MAX_L; ++i) {
                const int mid = (hi+lo) >> 1;

                if (nums[mid] > nums[mid+1]) {
                    if (beforePivot) hi = mid;
                    else lo = mid+1;
                    break;
                }
                else if (nums[mid] >= nums[lo]) {
                    lo = mid+1;
                }
                else {
                    hi = mid-1;
                }
            }
            if (beforePivot) lo = 0;
            else hi = nums.size()-1;
        }

        int ans = -1;
        for (int i=0; hi>=lo && i<MAX_L; ++i) {
            const int mid = (hi+lo) >> 1;
            if (nums[mid] == target) {
                ans = mid;
                break;
            }
            else if (nums[mid] > target) {
                //if (hi == mid)
                    hi = mid-1;
                //else hi = mid;  // nums[mid] == target 이 따로 존재할 경우 필요없음
            }
            else {
                //if (lo == mid)
                    lo = mid+1;
                //else lo = mid;  // nums[mid] == target 이 따로 존재할 경우 필요없음
            }
        }
        //*/

        return ans;
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

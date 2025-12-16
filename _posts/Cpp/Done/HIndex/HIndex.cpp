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
    vi citations;
public:
    ProbSolv()
    {
        string line;
        FOR (i, 10) {
            getline(cin, line);
            if (line.length() > 2) {
                break;
            }
        }
        vstr vstr_input = split_string_(line, "[], \n");
        for (const string& s : vstr_input) {
            citations.push_back(stoi(s));
        }

        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        cout << hIndex(citations);
    } // _Solve()

    int hIndex(vector<int>& citations) {
        int max_cit = 0;
        for (const int& cit : citations) {
            if (cit > max_cit) max_cit = cit;
        }
        vi bins = create_bins(citations, max_cit+1);
        int h_idx = 0;
        int cnt = 0;
        FOR_DEC(cit, 0, bins.size()) {
            cnt += bins[cit];
            if (cit <= cnt) {
                h_idx = cit;
                break;
            }
        }
        return h_idx;
    }
    vi create_bins(const vi& data, int bin_size) {
        vi bins(bin_size, 0);
        for (const int& d : data) {
            if (d < bin_size) bins[d]++;
        }
        return bins;
    }

    int hIndex_sort(vector<int>& citations) {
        sort (begin(citations), end(citations), std::greater<>());
        int h = 0;
        int cnt = 1;
        for (const int& c: citations) {
            if (c >= cnt) h = cnt;
            else break;
            cnt++;
        }
        return h;
    }

#if 0
#define SPLIT_DEBUG
#endif // 1

    vstr split_string_(string line, const string& delims, const string& separator = "") {
#ifdef SPLIT_DEBUG
        line += "       !";
        cout << "\n1) line: " << line <<endl;
        string::iterator newEnd = unique(begin(line), end(line), [](const char& x, const char& y) {
            return x == y and x == ' ';
        });
        cout << "2) line: " << line <<endl;
        line.erase(newEnd-1, end(line));
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

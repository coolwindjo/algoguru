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
    vvi m_vviGraph;
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

        vstr vstrSplits = _SplitString(line, ",= \n", "[]");
        stack<string> S;
        FOR_INC (i, 2, vstrSplits.size()) {
            if (vstrSplits[i] == "[") {
                S.push("[");
                continue;
            }

            if (!S.empty()) {
                if (vstrSplits[i] == "]") {
                    vi viNextNodes;
                    while (S.top() != "[") {
                        const string top = S.top(); S.pop();
                        viNextNodes.push_back(stoi(top));
                    }
                    m_vviGraph.push_back(viNextNodes);
                    while(!S.empty()) S.pop();
                    continue;
                }
                S.push(vstrSplits[i]);
            }
        }

        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        vvi vviAns = allPathsSourceTarget(m_vviGraph);
        cout << "[";
        for (vi viPath : vviAns) {
            cout << "[";
            for (int node : viPath) {
                cout << node << ",";
            }
            cout << "], ";
        }
        cout << "]";
    } // _Solve()

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vvi vviAns;
        DFS(vviAns, vi(), 0, graph);
        return vviAns;
    }
    
    void DFS(vvi& vviResult, vi viPath, const int cur, vvi& vviGraph) {
        if (vviGraph.size() == 0) return;
        if ((cur < 0) || (cur >= vviGraph.size())) return;

        viPath.push_back(cur);
        if (cur == vviGraph.size()-1) {
            vviResult.push_back(viPath);
        }
        
        for (int next : vviGraph[cur]) {
            DFS(vviResult, viPath, next, vviGraph);
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

#if 1
#define TEST
#endif // 1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O1") 
#endif 

typedef vector<TreeNode*> vTN;
class ProbSolv
{
    vTN m_vTN;
    unordered_map<int, vTN> hashN;
public:
    ProbSolv()
    {
        _Solve();
    }
    ~ProbSolv(){
        for (int i=0; i<m_vTN.size(); ++i) {
            if (nullptr == m_vTN[i]) {
                delete m_vTN[i];
                m_vTN[i] = nullptr;
            }
        }
    }

private:
    void _Solve(){
        int n = 0;
        cin >> n;
        vTN vTN_ans = allPossibleFBT(n);
        cout <<endl;
        for (auto ans : vTN_ans) {
            cout << "[";
            PrintBST(ans, n);
            cout << "],";
        }
    } // _Solve()

    vector<TreeNode*> allPossibleFBT(int n) {
        m_vTN = BST(n);
        return m_vTN;
    }
    
    vector<TreeNode*> BST(int n) {
        if (n <= 0) return {};
        if (n == 1) return {new TreeNode(0)};
        
        const auto it = hashN.find(n);
        if (it != end(hashN)) {
            return it->second;
        }
        
        // n >= 3
        vTN vTNs;
        for (int i=1; i<(n-1); i+=2) {          // 3    5   5   7   7   7
            vTN vTN_left = BST(i);              // 1    1   3   1   3   5
            vTN vTN_right = BST((n-1)-i);       // 1    3   1   5   3   1
            for (auto l : vTN_left) {
                for (auto r : vTN_right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    vTNs.push_back(root);
                }
            }
        }
        hashN.insert(make_pair(n, vTNs));
        return vTNs;
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
    cin >> numTCs; cin.ignore();
    FOR (tc, numTCs) {
        cout << "#" << tc+1 <<" ";
        ProbSolv ps;
        cout << endl;
    }
    return 0;
}
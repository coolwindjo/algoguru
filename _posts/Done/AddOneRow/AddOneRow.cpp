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
    TreeNode* m_root;
    int m_val;
    int m_depth;
    int m_cnt;
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

        vstr vstrSplits = _SplitString(line, "[, \n", "]");
        typedef enum {
            eInit = 0,
            eValue,
            eDepth
        } Enum_e;
        Enum_e eVal = eInit;

        m_cnt = 0;
        vstr vstrTree;
        for (auto str : vstrSplits) {
            if (eValue == eVal) {
                m_val = stoi(str);
                eVal = eDepth;
            }
            else if (eDepth == eVal) {
                m_depth = stoi(str);
                eVal = eInit;
                break;
            }
            else {
                if ("]" == str) {
                    eVal = eValue;
                }
                else {
                    vstrTree.push_back(str);
                    m_cnt++;
                }
            }

        }

        m_root = BFSBuildBST(vstrTree);
        
        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        TreeNode* pstAns = addOneRow(m_root, m_val, m_depth);
        PrintBST(pstAns, m_cnt+2);
    } // _Solve()

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (1 == depth) {
            TreeNode* node = new TreeNode(val, root, nullptr);
            root = node;
        }
        else {
            DFS(root, val, depth-1);
        }
        return root;
    }
    
    void DFS(TreeNode* cur, const int val, const int depth) {
        if (nullptr == cur) return;
        if (1 == depth) {
            TreeNode* node = new TreeNode(val, cur->left, nullptr);
            cur->left = node;
            node = new TreeNode(val, nullptr, cur->right);
            cur->right= node;
        }
        
        if (nullptr != cur->left) DFS(cur->left, val, depth-1);
        if (nullptr != cur->right) DFS(cur->right, val, depth-1);
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

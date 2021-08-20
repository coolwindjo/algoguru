#if 1
#define TEST
#endif // 1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O1") 
#endif 

class ProbSolv
{
    TreeNode* m_root1;
    TreeNode* m_root2;
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

        vstr vstrSplits = _SplitString(line, "[], \n", "=");
        vstr vstrTree1;
        vstr vstrTree2;
        vstr* pvstrTree = nullptr;
        bool isNode = false;
        for (auto str : vstrSplits) {
            if (("=" == str) && (nullptr == pvstrTree)) {
                pvstrTree = &vstrTree1;
                isNode = true;
                continue;
            }

            if (nullptr != pvstrTree) {
                if ("root2" == str) {
                    isNode = false;
                }
                if (isNode) {
                    pvstrTree->push_back(str);
                }
                if ("=" == str) {
                    pvstrTree = &vstrTree2;
                    isNode = true;
                }
            }
        }

        m_root1 = BFSBuildBST(vstrTree1);
        m_root2 = BFSBuildBST(vstrTree2);
        
        _Solve();
    }
    ~ProbSolv(){
        DFSDelete(&m_root1);
        DFSDelete(&m_root2);
    }

private:
    void _Solve(){
        TreeNode* ans = mergeTrees(m_root1, m_root2);
        PrintBST(ans, 6);
    } // _Solve()

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if ((nullptr == root1) && (nullptr == root2)) return nullptr;
        
        if (nullptr == root1) {
            return root2;
        }
        if (nullptr == root2) {
            return root1;
        }
        
        TreeNode* newRoot = new TreeNode(root1->val + root2->val,
                                         mergeTrees(root1->left, root2->left),
                                         mergeTrees(root1->right, root2->right));
        return newRoot;
    }

    TreeNode* mergeTrees_no_more_new(TreeNode* root1, TreeNode* root2) {
        TreeNode* ans = PickNoneNull(root1, root2);
        if (nullptr == ans) return nullptr;
        
        PreorderMerge(ans, root1, root2);
        
        return ans;
    }
    
    TreeNode* PickNoneNull(TreeNode* root1, TreeNode* root2) {
        if ((nullptr == root1) && (nullptr == root2)) return nullptr;
        
        if (nullptr == root1) {
            return root2;
        }
        else if (nullptr == root2) {
            return root1;
        }
        else {
            return root1;
        }
    }
    
    void PreorderMerge(TreeNode* ans, TreeNode* root1, TreeNode* root2) {
        if (nullptr == ans) return;
        if ((nullptr == root1) || (nullptr == root2)) return;
        
        // Visit Root
        ans->val = root1->val + root2->val; 

        // Visit left 
        if (nullptr != ans->left) {
            PreorderMerge(ans->left, root1->left, root2->left);
        }
        else {
            ans->left = PickNoneNull(root1->left, root2->left);
        }

        // Visit right 
        if (nullptr != ans->right) {
            PreorderMerge(ans->right, root1->right, root2->right);
        }
        else {
            ans->right = PickNoneNull(root1->right, root2->right);
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
    cin >> numTCs; cin.ignore();
    FOR (tc, numTCs) {
        cout << "#" << tc+1 <<" ";
        ProbSolv ps;
        cout << endl;
    }
    return 0;
}
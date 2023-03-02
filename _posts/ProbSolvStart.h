#include <bits/stdc++.h>
using namespace std;

class CoolTimer {
public:
    explicit CoolTimer() : fn_name_len_(0) {}
    explicit CoolTimer(const char* str)
        : fn_name_len_(0) {
        On(str);
    }
    virtual ~CoolTimer() {
        if (IsOn()) Off();
    }

    void On(const char* str) {
        // Get the name of the function.
        fn_name_len_ = strlen(str) + 1;
        memcpy(fn_name_, str, sizeof(char)*fn_name_len_);

        // Start.
        _QueryPerformanceCounter(&begin_);
    }

    void Off() {
        // End.
        _QueryPerformanceCounter(&end_);

        // Calculate the time.
        long seconds = end_.tv_sec - begin_.tv_sec;
        long nanoseconds = end_.tv_nsec - begin_.tv_nsec;
        double elapsed = seconds*1e3 + nanoseconds*1e-6;

        // Print the message.
        ostringstream os;
        os << fn_name_ << "() takes [" << elapsed << "] ms.\n";
        cout << os.str();
        begin_= end_;
    }

    bool IsOn() { return (end_.tv_nsec != begin_.tv_nsec); }

private:
    /* These functions are written to match the win32
    signatures and behavior as closely as possible.
    */
    bool _QueryPerformanceFrequency(timespec* frequency) {
        /* Sanity check. */
        assert(frequency != nullptr);
        /* gettimeofday reports to microsecond accuracy. */
        clock_getres(CLOCK_REALTIME, frequency);
        return true;
    }

    bool _QueryPerformanceCounter(timespec* performance_count) {
        /* Sanity check. */
        assert(performance_count != nullptr);
        /* Grab the current time. */
        clock_gettime(CLOCK_REALTIME, performance_count);
        return true;
    }

    timespec begin_;
    timespec end_;
    char fn_name_[256];
    size_t fn_name_len_;
};

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* BFSBuildBST(const vector<string> vstrVal) {
    const int n = vstrVal.size();
    if (n == 0) return nullptr;
    int cnt = 0;
    if ("null" == vstrVal[cnt]) {
        return nullptr;
    }
    queue<TreeNode*> qTN;
    TreeNode* root = new TreeNode(stoi(vstrVal[cnt++]));
    qTN.emplace(root);
    while ((!qTN.empty() && (cnt < n))) {
        TreeNode* tn = qTN.front(); qTN.pop();
        if (nullptr == tn) continue;
        string strVal = vstrVal[cnt++];
        if ("null" != strVal) {
            tn->left = new TreeNode(stoi(strVal));
        }
        qTN.emplace(tn->left);
        if (cnt == n) break;

        strVal = vstrVal[cnt++];
        if ("null" != strVal) {
            tn->right = new TreeNode(stoi(strVal));
        }
        qTN.emplace(tn->right);
        if (cnt == n) break;
    }

    return root;
}

void BFSPrint(TreeNode* root, int& cnt) {
    if (nullptr == root) return;
    if (cnt == 0) return;

    queue<TreeNode*> qTN;
    qTN.emplace(root);
    while ((!qTN.empty()) && (cnt)) {
        TreeNode* tn = qTN.front(); qTN.pop();
        if (nullptr == tn) {
            cout << "null, ";
        }
        else {
            cout << tn->val << ", ";
            cnt--;
            qTN.emplace(tn->left);
            qTN.emplace(tn->right);
        }
    }
}

void PrintBST(TreeNode* root, int cnt) {
    cout << "[";
    BFSPrint(root, cnt);
    cout << "], ";
}

void DFSDelete(TreeNode** pRoot) {
    if (nullptr == *pRoot) return;

    if (nullptr != (*pRoot)->left) {
        DFSDelete(&(*pRoot)->left);
    }
    if (nullptr != (*pRoot)->right) {
        DFSDelete(&(*pRoot)->right);
    }

    delete *pRoot;
    *pRoot = nullptr;
}

#define FOR_INC(i, from, to) for(int (i)=(from); (i)<(to); ++(i))
#define FOR_DEC(i, from, to) for(int (i)=(to)-1; (i)>=(from); --(i))
#define FOR(i, to) FOR_INC((i), 0, (to))
#define OOR(x, min, max) (((x) < (min) || (x) > (max)))

static const int WarnIfNot(const int condFlag, const char* condition){
 	if (condFlag == 0) {
        cout << "Warning: [" << condition << "] is violated!\n";
    }
    return condFlag;
}
#define W_IFNOT(cond) WarnIfNot((cond), (#cond))
#define P_IFNOT(cond, var) if (!W_IFNOT(cond)) cout << "= " << var <<endl;

typedef long long ll;
constexpr int INF = 987654321;  // INF < 1e9 < 2e30 < INT_MAX

typedef vector<string> vstr;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

#if 0
// 57yy
#if 1
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

// 16yy
constexpr char TO_CHAR[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int c2d(char c){
	if (c <= '9') return c - '0';
	return c - 'A' + 10;
}

typedef enum {
	eR=0, eD,
    eL, eU,
    eDIR_LEN
} Dir_e;
constexpr int DIR[eDIR_LEN][2] = {
    {0,1}, {1,0},
    {0,-1}, {-1,0}
};
constexpr int N_DIR[eDIR_LEN] = {eL, eU, eR, eD};

// 40yy  15dd
        int numLines = 0;
        cin >> numLines; cin.ignore();

        vstr lines;
        FOR(i, numLines){
            string line;
            std::getline(std::cin, line);
            if(line.length() == 0){
                i--;
                continue;
            }
            lines.push_back(line);
        }

        int rows = 0;
        int columns = 0;
        cin >> rows;
        cin >> columns;

        vvi grid;
        FOR(i, rows){
            vi rowG;
            FOR(j, columns){
                int val;
                cin >> val;
                rowG.push_back(val);
            }
            grid.push_back(rowG);
        }
#ifdef TEST
        cout <<endl;
        FOR(r, rows){
            FOR(c, columns){
                cout << grid[r][c] << " ";
            }
            cout <<endl;
        }
#endif

// 11yy
    template <typename T>
    pair<T, bool> getNthElem(set<T>& searchSet, int n) {
        pair<T, bool> result;
        if (searchSet.size() > n) {
            result.first = *(next(begin(searchSet), n));
            result.second = true;
        }
        else {
            result.second = false;
        }
        return result;
    }

#endif // 0

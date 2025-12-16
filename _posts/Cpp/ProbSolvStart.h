#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <cassert>
#include <ctime>

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
typedef vector<vstr> vvstr;
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

// Binning
vector<int> create_bins(const vector<int>& data, int bin_size) {
    vector<int> bins(bin_size, 0);
    for (const int& d : data) {
        if (d < bin_size) bins[d]++;
    }
    return bins;
}


// Two pointers: one input, opposite ends
int fn(vector<int>& arr) {
    int left = 0;
    int right = int(arr.size()) - 1;
    int ans = 0;

    while (left < right) {
        // do some logic here with left and right
        if (CONDITION) {
            left++;
        } else {
            right--;
        }
    }

    return ans;
}

// Two pointers: two inputs, exhaust both
int fn(vector<int>& arr1, vector<int>& arr2) {
    int i = 0, j = 0, ans = 0;

    while (i < arr1.size() && j < arr2.size()) {
        // do some logic here
        if (CONDITION) {
            i++;
        } else {
            j++;
        }
    }

    while (i < arr1.size()) {
        // do logic
        i++;
    }

    while (j < arr2.size()) {
        // do logic
        j++;
    }

    return ans;
}

// Sliding window
int fn(vector<int>& arr) {
    int left = 0, ans = 0, curr = 0;

    for (int right = 0; right < arr.size(); right++) {
        // do logic here to add arr[right] to curr

        while (WINDOW_CONDITION_BROKEN) {
            // remove arr[left] from curr
            left++;
        }

        // update ans
    }

    return ans;
}

// Build a prefix sum
vector<int> fn(vector<int>& arr) {
    vector<int> prefix(arr.size());
    prefix[0] = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    return prefix;
}

// Efficient string building
string fn(vector<char>& arr) {
    return string(arr.begin(), arr.end())
}

// Linked list: fast and slow pointer
int fn(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    int ans = 0;

    while (fast != nullptr && fast->next != nullptr) {
        // do logic
        slow = slow->next;
        fast = fast->next->next;
    }

    return ans;
}

// Reversing a linked list
ListNode* fn(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

// Find number of subarrays that fit an exact criteria
int fn(vector<int>& arr, int k) {
    unordered_map<int, int> counts;
    counts[0] = 1;
    int ans = 0, curr = 0;

    for (int num: arr) {
        // do logic to change curr
        ans += counts[curr - k];
        counts[curr]++;
    }

    return ans;
}

// Monotonic increasing stack
int fn(vector<int>& arr) {
    stack<integer> stack;
    int ans = 0;

    for (int num: arr) {
        // for monotonic decreasing, just flip the > to <
        while (!stack.empty() && stack.top() > num) {
            // do logic
            stack.pop();
        }

        stack.push(num);
    }
}

// Binary tree: DFS (recursive)
int dfs(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int ans = 0;
    // do logic
    dfs(root.left);
    dfs(root.right);
    return ans;
}

// Binary tree: DFS (iterative)
int dfs(TreeNode* root) {
    stack<TreeNode*> stack;
    stack.push(root);
    int ans = 0;

    while (!stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();
        // do logic
        if (node->left != nullptr) {
            stack.push(node->left);
        }
        if (node->right != nullptr) {
            stack.push(node->right);
        }
    }

    return ans;
}

// Binary tree: BFS
int fn(TreeNode* root) {
    queue<TreeNode*> queue;
    queue.push(root);
    int ans = 0;

    while (!queue.empty()) {
        int currentLength = queue.size();
        // do logic for current level

        for (int i = 0; i < currentLength; i++) {
            TreeNode* node = queue.front();
            queue.pop();
            // do logic
            if (node->left != nullptr) {
                queue.push(node->left);
            }
            if (node->right != nullptr) {
                queue.push(node->right);
            }
        }
    }

    return ans;
}

// Graph: DFS (recursive)
// For the graph templates, assume the nodes are numbered from 0 to n - 1 and the graph is given as an adjacency list. Depending on the problem, you may need to convert the input into an equivalent adjacency list before using the templates.

unordered_set<int> seen;

int fn(vector<vector<int>>& graph) {
    seen.insert(START_NODE);
    return dfs(START_NODE, graph);
}

int dfs(int node, vector<vector<int>>& graph) {
    int ans = 0;
    // do some logic
    for (int neighbor: graph[node]) {
        if (seen.find(neighbor) == seen.end()) {
            seen.insert(neighbor);
            ans += dfs(neighbor, graph);
        }
    }

    return ans;
}

// Graph: DFS (iterative)
int fn(vector<vector<int>>& graph) {
    stack<int> stack;
    unordered_set<int> seen;
    stack.push(START_NODE);
    seen.insert(START_NODE);
    int ans = 0;

    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();
        // do some logic
        for (int neighbor: graph[node]) {
            if (seen.find(neighbor) == seen.end()) {
                seen.insert(neighbor);
                stack.push(neighbor);
            }
        }
    }
}

// Graph: BFS
int fn(vector<vector<int>>& graph) {
    queue<int> queue;
    unordered_set<int> seen;
    queue.push(START_NODE);
    seen.insert(START_NODE);
    int ans = 0;

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        // do some logic
        for (int neighbor: graph[node]) {
            if (seen.find(neighbor) == seen.end()) {
                seen.insert(neighbor);
                queue.push(neighbor);
            }
        }
    }
}

// Find top k elements with heap
vector<int> fn(vector<int>& arr, int k) {
    priority_queue<int, CRITERIA> heap;
    for (int num: arr) {
        heap.push(num);
        if (heap.size() > k) {
            heap.pop();
        }
    }

    vector<int> ans;
    while (heap.size() > 0) {
        ans.push_back(heap.top());
        heap.pop();
    }

    return ans;
}

// Binary search
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = int(arr.size()) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            // do something;
            return mid;
        }
        if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    // left is the insertion point
    return left;
}

// Binary search: duplicate elements, left-most insertion point
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

// Binary search: duplicate elements, right-most insertion point
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

// Binary search: for greedy problems
// If looking for a minimum:
int fn(vector<int>& arr) {
    int left = MINIMUM_POSSIBLE_ANSWER;
    int right = MAXIMUM_POSSIBLE_ANSWER;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

bool check(int x) {
    // this function is implemented depending on the problem
    return BOOLEAN;
}

// If looking for a maximum:
int fn(vector<int>& arr) {
    int left = MINIMUM_POSSIBLE_ANSWER;
    int right = MAXIMUM_POSSIBLE_ANSWER;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}

bool check(int x) {
    // this function is implemented depending on the problem
    return BOOLEAN;
}

// Backtracking
int backtrack(STATE curr, OTHER_ARGUMENTS...) {
    if (BASE_CASE) {
        // modify the answer
        return 0;
    }

    int ans = 0;
    for (ITERATE_OVER_INPUT) {
        // modify the current state
        ans += backtrack(curr, OTHER_ARGUMENTS...)
        // undo the modification of the current state
    }

    return ans;
}

// Dynamic programming: top-down memoization
unordered_map<STATE, int> memo;

int fn(vector<int>& arr) {
    return dp(STATE_FOR_WHOLE_INPUT, arr);
}

int dp(STATE, vector<int>& arr) {
    if (BASE_CASE) {
        return 0;
    }

    if (memo.find(STATE) != memo.end()) {
        return memo[STATE];
    }

    int ans = RECURRENCE_RELATION(STATE);
    memo[STATE] = ans;
    return ans;
}

// Build a trie
// note: using a class is only necessary if you want to store data at each node.
// otherwise, you can implement a trie using only hash maps.
struct TrieNode {
    int data;
    unordered_map<char, TrieNode*> children;
    TrieNode() : data(0), children(unordered_map<char, TrieNode*>()) {}
};

TrieNode* buildTrie(vector<string> words) {
    TrieNode* root = new TrieNode();
    for (string word: words) {
        TrieNode* curr = root;
        for (char c: word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        // at this point, you have a full word at curr
        // you can perform more logic here to give curr an attribute if you want
    }

    return root;
}

// Dijkstra's algorithm
vector<int> distances(n, INT_MAX);
distances[source] = 0;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
heap.push({0, source});

while (!heap.empty()) {
    int currDist = heap.top().first;
    int node = heap.top().second;
    heap.pop();
    
    if (currDist > distances[node]) {
        continue;
    }
    
    for (pair<int, int> edge: graph[node]) {
        int nei = edge.first;
        int weight = edge.second;
        int dist = currDist + weight;
        
        if (dist < distances[nei]) {
            distances[nei] = dist;
            heap.push({dist, nei});
        }
    }
}



#endif // 0

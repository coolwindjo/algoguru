#if 1
#define TEST
#endif // 1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O1") 
#endif 

class ProbSolv
{
    ListNode* m_head;
    int m_left;
    int m_right;
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
        auto it = find(begin(vstrSplits), end(vstrSplits), "=");
        it++;
        auto itLast = find(it, end(vstrSplits), "left");
        ListNode h;
        ListNode* prev = &h;
        for (; it != itLast; it++) {
            ListNode* pLN = new ListNode(stoi(*it));
            prev->next = pLN;
            prev = prev->next;
        }
        m_head = h.next;
        
        auto itLeft = find(it, end(vstrSplits), "=");
        itLeft++;
        m_left = stoi(*itLeft);
        auto itRight = find(itLeft, end(vstrSplits), "=");
        itRight++;
        m_right = stoi(*itRight);
        
        _Solve();
    }
    ~ProbSolv(){
        if (nullptr != m_head) {
            ListNode* curr = m_head;
            ListNode* prev = nullptr;
            vector<ListNode*> vLN;
            while (curr) {
                vLN.push_back(curr);
                prev = curr;
                curr = curr->next;
            }
            for (auto toDel : vLN) {
                delete toDel;
            }
            m_head = nullptr;
        }
    }

private:
    void _Solve(){
        ListNode* ans = reverseBetween(m_head, m_left, m_right);
        ListNode* pos = ans;
        cout << "[";
        while (pos) {
            cout << pos->val << ", ";
            pos = pos->next;
        }
        cout << "]";
    } // _Solve()

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (nullptr == head) return nullptr;
        if (nullptr == head->next) return head;
        
        ListNode* itLeftPrev = nullptr;
        ListNode* itLeft = findNode(head, left, &itLeftPrev);
        if (nullptr == itLeft) return nullptr;
        
        ListNode* itRight = findNode(head, right, nullptr);
        if (nullptr == itRight) return nullptr;
        
        ListNode* itNewLeft = reverse(itLeft, itRight);
        W_IFNOT(itRight->val == itNewLeft->val);
        if (nullptr != itLeftPrev) {
            itLeftPrev->next = itNewLeft;
        }
        else {
            head = itNewLeft;
        }
        return head;
    }
    
    ListNode* findNode(ListNode* begin, int pos, ListNode** ppPrev) {
        if (nullptr == begin) return nullptr;
        ListNode* curr = begin;
        ListNode* prev = nullptr;
        while(curr) {
            if (--pos == 0) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        if (nullptr != ppPrev) {
            *ppPrev = prev;
        }
        return curr;
    }
    
    ListNode* reverse(ListNode* head, ListNode* tail) {
        if (head == tail) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != tail) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if (nullptr != curr) {
            head->next = curr->next;
            curr->next = prev;
            return curr;
        }
        return prev;
    }
    
// 70yy
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
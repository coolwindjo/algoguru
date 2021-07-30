#if 1
#define TEST
#endif // 1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O2") 
#endif 

class ProbSolv
{
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode* m_pstToDel;
    ListNode m_stL1;
    ListNode m_stL2;
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
        vstr vstrSplits = _SplitString(line, "[],= \n");

        ListNode* pstL1End = &m_stL1;
        ListNode* pstL2End = &m_stL2;
        int isFirst = 2;
        for (string str : vstrSplits) {
            if (str[0] == 'l') {
                isFirst--;
                continue;
            }
            ListNode* pstNode = new ListNode(stoi(str), nullptr);
            if (isFirst) {
                pstL1End->next = pstNode;
                pstL1End = pstNode;
            }
            else {
                pstL2End->next = pstNode;
                pstL2End = pstNode;
            }
        }
        
        _Solve();
    }
    ~ProbSolv(){
        ListNode* pstNode=m_pstToDel;
        while (pstNode != nullptr) {
            ListNode* pstDel = pstNode;
            pstNode = pstNode->next;
            delete pstDel;
        }
    }

private:
    void _Solve(){
        ListNode* pstAns = mergeTwoLists(m_stL1.next, m_stL2.next);
        m_pstToDel = pstAns;
        cout << "[";
        while (pstAns != nullptr) {
            cout << pstAns->val << ",";
            pstAns = pstAns->next;
        }
        cout << "]";
    } // _Solve()

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode stHead;
        ListNode* pstCur = &stHead;
        while ((l1!=nullptr) && (l2!=nullptr)) {
            if (l1->val < l2->val) {
                pstCur->next = l1;
                l1=l1->next;
            }
            else {
                pstCur->next = l2;
                l2=l2->next;
            }
            pstCur = pstCur->next;
        }
        while (l1!=nullptr) {
            pstCur->next = l1;
            l1=l1->next;
            pstCur = pstCur->next;
        }
        while (l2!=nullptr) {
            pstCur->next = l2;
            l2=l2->next;
            pstCur = pstCur->next;
        }
        return stHead.next;
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
    cin >> numTCs;
    FOR (tc, numTCs) {
        cout << "#" << tc+1 <<" ";
        ProbSolv ps;
        cout << endl;
    }
    return 0;
}
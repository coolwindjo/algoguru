#if 1
#define TEST
#endif // 1
#define TEST1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O1") 
#endif 

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class ProbSolv
{
    vector<Employee*> m_vstEmployees;
    int m_ID;
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

        vstr vstrSplits = _SplitString(line, ", \n", "[]=");

        vstr vstrEmployees;
        bool expectOpen = false;
        typedef enum {
            eInit = 0,
            eID,
            eImportance,
            eSubordinates
        } Emp_e;
        Emp_e eVal;

        Employee* pEmp = nullptr;
        for (auto str : vstrSplits) {
            switch (eVal) {
            case eID:
                if ("[" != str) {
                    pEmp = new Employee();
                    pEmp->id = stoi(str);
                    m_vstEmployees.push_back(pEmp);
                    eVal = eImportance;
                    pEmp = nullptr;
                }
                break;
            case eImportance:
                m_vstEmployees.back()->importance = stoi(str);
                eVal = eSubordinates;
                break;
            case eSubordinates:
                if (true == expectOpen) {
                    if ("]" == str) {
                        eVal = eInit;
                        continue;
                    }
                    m_vstEmployees.back()->subordinates.push_back(stoi(str));
                }
                expectOpen = true;
                continue;
                break;
            default:
                break;
            }

            if ("=" == str) {
                expectOpen = true;
            }
            else if (true == expectOpen) {
                if ("[" == str) {
                    eVal = eID;
                    expectOpen = false;
                }
                else if (("]" == str) || ("id" == str)) {
                    // Do nothing
                }
                else {
                    m_ID = stoi(str);
                }
            }

        }

        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        cout << getImportance(m_vstEmployees, m_ID);
    } // _Solve()

    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> hashE;
        for (Employee* pEmp : employees) {
            hashE.emplace(make_pair(pEmp->id, pEmp));
        }
        
        return DFS(id, hashE);
    }
    
    int DFS(const int id, const unordered_map<int, Employee*>& hashE) {
        if (hashE.empty()) return 0;
        
        auto it = hashE.find(id);
        if (it == end(hashE))  return 0;
        
        int sumImp = 0;
        for (int subId : it->second->subordinates) {
            sumImp += DFS(subId, hashE);
        }
        return it->second->importance + sumImp;
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

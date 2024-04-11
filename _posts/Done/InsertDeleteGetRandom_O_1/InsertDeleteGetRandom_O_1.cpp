#if 1
#define TEST
#endif // 1
#define TEST1

#include "../../ProbSolvStart.h"

#if 0
#pragma GCC optimize("O1") 
#endif

class RandomizedSet {
    std::unordered_set<int>* pHash;

    std::unordered_map<int, int>* pDic;
    std::vector<int>* pV;

public:
    RandomizedSet() {
        pHash = new std::unordered_set<int>();

        pDic = new std::unordered_map<int, int>();
        pV = new std::vector<int>();
    }

    bool insert_dicvec(int val) {
        auto itD = pDic->find(val);
        if (itD != end(*pDic)) return false;
        pV->push_back(val);
        (*pDic)[val] = pV->size() - 1;
        return true;
    }

    bool insert_hash(int val) {
        auto it = pHash->find(val);
        if (it != end(*pHash)) return false;
        pHash->emplace(val);
        return true;
    }

    bool remove_dicvec(int val) {
        auto itD = pDic->find(val);
        if (itD == end(*pDic)) return false;
        (*pV)[itD->second] = pV->back();
        (*pDic)[pV->back()] = itD->second;
        pV->pop_back();
        pDic->erase(val);
        return true;
    }

    bool remove_hash(int val) {
        auto it = pHash->find(val);
        if (it == end(*pHash)) return false;
        pHash->erase(val);
        return true;
    }

    int getRandom_dicvec() {
        if (pV->size() == 0) return -1;
        return (*pV)[rand() % pV->size()];
    }

    int getRandom_hash() {
        if (pHash->size() == 0) return -1;
        int r = std::rand() / ((RAND_MAX + 1u) / pHash->size());
        auto it = begin(*pHash);
        for (; it != end(*pHash); ++it) {
            if (r-- == 0) break;
        }
        return *it;
    }
};


class ProbSolv {
public:
    ProbSolv()
    {
        _Solve();
    }
    ~ProbSolv(){}

private:
    void _Solve(){
        /**
         * Your RandomizedSet object will be instantiated and called as such:
         */
        RandomizedSet* obj = new RandomizedSet();
        bool param_1 = obj->insert_dicvec(0);
        bool param_2 = obj->remove_dicvec(0);
        int param_3 = obj->getRandom_dicvec();
    } // _Solve()
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int numTCs = 0;
    // cin >> numTCs; cin.ignore();
    // FOR (tc, numTCs) {
        // cout << "#" << tc+1 <<" ";
        ProbSolv ps;
        cout << endl;
    // }
    return 0;
}

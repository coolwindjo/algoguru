---
title: 690. Employee Importance
layout: post
tags:
- cpp
- dfs
- std-unordered-map

---

<https://leetcode.com/problems/employee-importance/>{:target="_blank"}

### Source

```cpp

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

```

### GitHub

- [EmployeeImportance](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/EmployeeImportance>){:target="_blank"}

![EmployeeImportance]({{ "/assets/img/posting/employee_importance.png" | relative_url }})

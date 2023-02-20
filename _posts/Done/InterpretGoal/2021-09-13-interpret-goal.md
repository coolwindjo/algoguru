---
title: Goal Parser Interpretation
layout: post
tags:
- cpp
- easy
- string-manipulation
- std-unordered-map
- string-replace
- string-find

---

<https://leetcode.com/problems/goal-parser-interpretation/>{:target="_blank"}

### Source

```cpp

    string interpret(string command) {
        unordered_map<string, string> lut {
            {"()", "o"},
            {"(al)", "al"}
        };
        for (auto it=begin(lut); it!=end(lut); ++it) {
            auto itC = command.find(it->first);
            while (itC != std::string::npos) {
                command.replace(itC, it->first.length(), it->second);
                itC = command.find(it->first);
            }
        }
        return command;
    }

```

### GitHub

- [InterpretGoal](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/InterpretGoal>){:target="_blank"}

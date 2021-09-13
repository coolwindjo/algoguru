---
title: Goal Parser Interpretation
layout: post
tags:
- cpp
- implementation
- string-manipulation
- std-unordered-map

---

<https://leetcode.com/problems/goal-parser-interpretation/>{:target="_blank"}

### Source

```cpp

    string interpret(string command) {
        unordered_map<string, string> lut {
			{"G", "G"},
			{"()", "o"},
			{"(al)", "al"}
		};
		string ans = "";
		string tmp = "";
		for (auto c : command) {
			tmp += c;
			auto it = lut.find(tmp);
			if (it != end(lut)) {
				ans += lut[tmp];
				tmp = "";
			}
		}
		return ans;
    }

```

### GitHub

- [InterpretGoal](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/InterpretGoal>){:target="_blank"}

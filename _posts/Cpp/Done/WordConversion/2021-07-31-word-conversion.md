---
title: Word Conversion
layout: post
tags:
- cpp
- dfs-with-backtracking
- string-manipulation
- std-unordered-set

---

<https://programmers.co.kr/learn/courses/30/lessons/43163>{:target="_blank"}

### Source

```cpp

    int solution(string begin, string target, vector<string> words) {
        int answer = 51;

        hashstr hashWords;
        int cnt = 0;
        DFS(answer, hashWords, cnt, begin, target, words);
        if (answer == 51) {
            answer = 0;
        }

        return answer;
    }

    int Diff(const string& str1, const string& str2)
    {
        int cnt = 0;
        for (int i=0; i<str1.length(); ++i) {
            if ((str1[i] - str2[i]) != 0) {
                cnt++;
            }
        }
        if (cnt > 1) {
            return -1;
        }
        return cnt;
    }

    void DFS(int& minCntOut, hashstr& hashWords, const int cnt, const string& curWord, const string& target, const vstr& words)
    {
        if (cnt >= minCntOut) {
            // Stop if the count number is bigger than minimum count
            return;
        }

        if (target.compare(curWord) == 0) {
            // We found the target string then, stop and store the minimum count
            minCntOut = cnt;
            return;
        }

        for (int i=0; i<words.size(); ++i) {
            const string nextWord = words[i];
            auto it = hashWords.find(nextWord);
            if (it != end(hashWords)) {
                // The word has been visited.
                continue;
            }
            if (Diff(curWord, nextWord) <= 0) {
                // The word is not valid.
                continue;
            }

            // Store the valid word in the hash.
            hashWords.emplace(nextWord);

            // Go to next level
            DFS(minCntOut, hashWords, cnt+1, nextWord, target, words);

            // Back tracking
            hashWords.erase(nextWord);
        }
    }

```

### GitHub

- [WordConversion](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/WordConversion>){:target="_blank"}

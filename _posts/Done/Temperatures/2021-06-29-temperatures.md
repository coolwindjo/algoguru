---
title: Temperatures
layout: post
tags:
- cpp
- implementation

---

<https://www.codingame.com/ide/puzzle/temperatures>{:target="_blank"}

### Source

```cpp

int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    int ans = 0;
    int clsst2zero = 5527;
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();

        // Code!
        int abt = t;
        if (t < 0) abt *= -1;
        if ((abt < clsst2zero) || (abt == clsst2zero && ans < 0)) {
            clsst2zero = abt;
            ans = t;
        }

    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << ans << endl;
}

```

### GitHub

- [Temperatures](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/Temperatures>){:target="_blank"}

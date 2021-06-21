---
title: Circle List Order
layout: post
tags:
- cpp
- list
- STL
- advance
---

<http://codepro.lge.com/apply/exam/ZXhfaUhjUkhfMTQ5NTQ5NjY4ODY3NQ==/quiz/cV9XWmVFZV8xNTU0Nzg1OTIzNDE0>

### Source

{% highlight cpp %}
int curN = N;
int curS = S-1;
const int constM = M-1;

li numL;
FOR(i, curN){
    numL.push_back(i+1);
}

li::iterator it = numL.begin();

FOR(i, N){
    int chosen = (curS+constM)%curN;
    
    advance(it, chosen);
    cout << *it << " ";
    numL.erase(it);
    it = numL.begin();
    
    curS = chosen;
    curN = numL.size();
}
{% endhighlight %}

### GitHub

- [CircleListOrder](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/CircleListOrder>){:target="_blank"}CircleListOrder

![CircleListOrder]({{ "/assets/img/posting/circlelist_order.png" | relative_url }})

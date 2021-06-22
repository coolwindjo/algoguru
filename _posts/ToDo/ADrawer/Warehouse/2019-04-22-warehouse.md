---
title: Warehouse
layout: post
tags:
- cpp
- floyd-warshall
---

<http://codepro.lge.com/apply/exam/ZXhfaUhjUkhfMTQ5NTQ5NjY4ODY3NQ==/quiz/cV9RRUxqRl8xNTU0Nzg1OTIzMzg0>

### Source

{% highlight cpp %}
// Init
FOR(i, N){
    FOR(j, N){
        if (i == j)
            arDist[i][j] = 0;
        else
            arDist[i][j] = INF;
    }
}
FOR(i, M){
    arDist[A[i]-1][B[i]-1] = D[i];
    arDist[B[i]-1][A[i]-1] = D[i];
}

// Update with Floyd
FOR(k, N){
    FOR(i, N){
        if (arDist[i][k] == INF) continue;
        FOR(j, N){
            arDist[i][j] = min(arDist[i][j], arDist[i][k]+arDist[k][j]);
        }
    }
}

// Find min worst
int minWorst = INF;
FOR(k, N){
    int worst = 0;
    FOR(i, N){
        if (k==i) continue;
        int& dist = arDist[k][i];
        W_IFNOT(dist > 0);
        if (dist == INF) continue;
        W_IFNOT(dist < INF);
        if (dist > worst)
            worst = dist;
    }
    if (worst==0) continue;
    if (worst < minWorst)
        minWorst = worst;
}
ans = minWorst;
{% endhighlight %}

### GitHub

- [Warehouse](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/Warehouse>){:target="_blank"}

![Warehouse]({{ "/assets/img/posting/warehouse.png" | relative_url }})

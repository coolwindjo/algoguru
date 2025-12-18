---
title: Mario game
layout: post
tags:
- cpp
- simple-implementation
---

<http://codepro.lge.com/apply/exam/ZXhfaUhjUkhfMTQ5NTQ5NjY4ODY3NQ==/quiz/cV9oUmVJa18xNTQ5ODUxNTIxMDEy>{:target="_blank"}

### Source

{% highlight cpp %}
const int FindMaxH(const int N, const int (&P)[MAX_N])
{
	int h = 0;
	int ud = 1;
	for (int i=0; i<N; i++){
		if(ud == 1){
			if(P[i] > P[i+1]){
				// go down
				h += P[i];
				ud = -1;
			}
		}
		else{
			if(P[i] < P[i+1]){
				// go up
				h -= P[i];
				ud = 1;
			}
		}
	}

	return h;
}
{% endhighlight %}

### GitHub

- [MarioGame](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Cpp/Done/MarioGame>){:target="_blank"}

![MarioGame]({{ "/assets/img/posting/mario.png" | relative_url }})

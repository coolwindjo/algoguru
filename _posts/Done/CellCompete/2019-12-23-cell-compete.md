---
title: Cell Compete
layout: post
tags:
- cpp
- implementation
---

<AMZ Prob>

### Source

{% highlight cpp %}

    vector<int> cellCompete(int* states, int days){
        
         FOR(i, NUM_HOUSES){
            m_dualStates[0][i] = states[i];
        }

        FOR(d, days){
            const int i = d%2;
            const int ni = (d+1)%2;
            FOR(h, NUM_HOUSES){
                if(h == 0){
                    if(m_dualStates[i][h+1] == 0){
                        m_dualStates[ni][h] = 0;
                    }
                    else{
                        m_dualStates[ni][h] = 1;
                    }
                }
                else if(h == (NUM_HOUSES-1)){
                    if(m_dualStates[i][h-1] == 0){
                        m_dualStates[ni][h] = 0;
                    }
                    else{
                        m_dualStates[ni][h] = 1;
                    }
                }
                else{
                    if(m_dualStates[i][h-1] == m_dualStates[i][h+1]){
                        m_dualStates[ni][h] = 0;
                    }
                    else{
                        m_dualStates[ni][h] = 1;
                    }
                }
            }
        }
        const int resIdx = days%2;
        return m_dualStates[resIdx];
    }
};


{% endhighlight %}

### GitHub

- [CellCompete](<https://github.com/coolwindjo/algoguru/tree/master/_posts/Done/CellCompete>){:target="_blank"}

![CellCompete]({{ "/assets/img/posting/cell_compete.png" | relative_url }})

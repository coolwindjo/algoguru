---
layout: post
title: Technical Whiteboard Interviews - Tricks for Getting Unstuck
color: MediumVioletRed
tags: [interview, cheetsheet]
author: coolwindjo
excerpt_separator: <!--more-->
---

 <!--more-->

# Tricks for Getting Unstuck

---

Getting stuck during a coding interview is rough.

If you weren’t in an interview, you might take a break or ask Google for help. But the clock is ticking, and you don’t have Google.

You just have an empty whiteboard, a smelly marker, and an interviewer who’s looking at you expectantly. And all you can think about is how stuck you are.

You need a lifeline for these moments—like a little box that says “In Case of Emergency, Break Glass.”

_Inside_ that glass box? A list of tricks for getting unstuck. Here’s that list of tricks.

## When you’re stuck on getting started

**1) Write a sample input on the whiteboard and turn it into the correct output "by hand."** Notice the _process_ you use. Look for patterns, and think about how to implement your process in code.

Trying to reverse a string? Write “hello” on the board. Reverse it “by hand”—draw arrows from each character’s current position to its desired position.

![An array containing the string "hello." Arrows are drawn to show the swapping of the first letter with the last letter, the second letter with the second to last letter, and the middle letter with itself.](https://www.interviewcake.com/images/svgs/unstuck__hello_string.svg?bust=173)

Notice the pattern: it looks like we’re _swapping_ pairs of characters, starting from the outside and moving in. Now we’re halfway to an algorithm.

**2) Solve a simpler version of the problem.** Remove or simplify one of the requirements of the problem. Once you have a solution, see if you can adapt that approach for the original question.

Trying to find the k-largest element in a set? Walk through finding the _largest_ element, then the _second largest_, then the _third largest_. Generalizing from there to find the k-largest isn’t so bad.

**3) Start with an inefficient solution.** Even if it feels _stupidly inefficient_, it’s often helpful to start with _something_ that’ll return the right answer. From there, you just have to [optimize](https://leetcode.com/explore/interview/card/coding-interview-strategy/207/chapter-2-the-heat-of-battle/1248/#unstuck-optimization) your solution. Explain to your interviewer that this is only your first idea, and that you suspect there are faster solutions.

Suppose you were given two lists of sorted numbers and asked to find the median of both lists combined. It’s messy, but you could simply:

1. Concatenate the arrays together into a new array.
2. Sort the new array.
3. Return the value at the middle index.

Notice that you could’ve _also_ arrived at this algorithm by using trick (2): Solve a simpler version of the problem. “How would I find the median of _one_ sorted list of numbers? Just grab the item at the middle index. Now, can I adapt that approach for getting the median of _two_ sorted lists?”

## When you’re stuck on finding optimizations

**1) Look for repeat work.** If your current solution goes through the same data multiple times, you’re doing unnecessary repeat work. See if you can save time by looking through the data just once.

Say that inside one of your loops, there’s a brute-force operation to find an element in an array. You’re repeatedly looking through items that you don’t have to. Instead, you could convert the array to a lookup table to dramatically improve your runtime.

**2) Look for hints in the specifics of the problem.** Is the input array sorted? Is the [binary tree](https://leetcode.com/explore/learn/card/data-structure-tree/) balanced? Details like this can carry huge hints about the solution. If it didn’t matter, your interviewer wouldn’t have brought it up. It’s a strong sign that the best solution to the problem exploits it.

Suppose you’re asked to find the first occurrence of a number in a sorted array. The fact that the array is _sorted_ is a strong hint—take advantage of that fact by using a [binary search](https://leetcode.com/explore/learn/card/binary-search/).

Sometimes interviewers leave the question deliberately vague because they want you to _ask questions_ to unearth these important tidbits of context. So ask some questions at the beginning of the problem.

**3) Throw some data structures at the problem.** Can you save time by using the fast lookups of a [hash table](https://leetcode.com/explore/learn/card/hash-table/)? Can you express the relationships between data points as a [graph](https://leetcode.com/problemset/all/?topicSlugs=graph)? Look at the requirements of the problem and ask yourself if there’s a data structure that has those properties.

**4) Establish bounds on space and runtime.** Think _out loud_ about the parameters of the problem. Try to get a sense for how fast your algorithm _could possibly_ be:

- “I have to at least look at all the items, so I can’t do better than O(n) time”.
- “The brute force approach is to test all possibilities, which is  
    O(n2) time. So the question is whether or not I can beat that time.”
- “The answer will contain n2n​2​​ items, so I must at least spend that amount of time.”

## When All Else Fails

**1) Make it clear where you are.** State what you know, what you’re trying to do, and highlight the gap between the two. The clearer you are in expressing _exactly_ where you’re stuck, the easier it is for your interviewer to help you.

**2) Pay attention to your interviewer.** If she asks a question about something you just said, there’s probably a hint buried in there. Don’t worry about losing your train of thought—drop what you’re doing and dig into her question.

## Relax. You’re _supposed_ to get stuck.

Interviewers choose hard problems on purpose. They want to see how you poke at a problem you don’t immediately know how to solve.

Seriously. If you _don’t_ get stuck and just breeze through the problem, your interviewer’s evaluation might just say “Didn’t get a good read on candidate’s problem-solving process—maybe she’d already seen this interview question before?”

On the other hand, if you _do_ get stuck, use one of these tricks to get unstuck, and communicate clearly with your interviewer throughout..._that’s_ how you get an evaluation like, “Great problem-solving skills. Hire.”
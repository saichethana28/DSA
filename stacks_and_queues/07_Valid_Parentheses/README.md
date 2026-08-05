# 20. Valid Parentheses

## Problem Statement

Given a string `s` containing only the characters:

- `'('`, `')'`
- `'{'`, `'}'`
- `'['`, `']'`

Determine whether the given string is **valid**.

A string is valid if:

- Every opening bracket has a corresponding closing bracket.
- Brackets are closed in the correct order.
- Every closing bracket matches the most recent unmatched opening bracket.

### Example 1

**Input**
```
s = "()"
```

**Output**
```
true
```

### Example 2

**Input**
```
s = "()[]{}"
```

**Output**
```
true
```

### Example 3

**Input**
```
s = "(]"
```

**Output**
```
false
```

### Example 4

**Input**
```
s = "([])"
```

**Output**
```
true
```

### Example 5

**Input**
```
s = "([)]"
```

**Output**
```
false
```

---

# Brute Force Approach

## Approach

Repeatedly scan the string and remove adjacent valid bracket pairs:

- `"()"`
- `"[]"`
- `"{}"`

Continue removing until no more pairs can be removed.

If the string becomes empty, it is valid; otherwise, it is invalid.

## Code

```cpp
class Solution {
public:
    bool isValid(string s) {

        while (true) {

            string temp = s;

            size_t pos;

            if ((pos = s.find("()")) != string::npos)
                s.erase(pos, 2);
            else if ((pos = s.find("{}")) != string::npos)
                s.erase(pos, 2);
            else if ((pos = s.find("[]")) != string::npos)
                s.erase(pos, 2);

            if (temp == s)
                break;
        }

        return s.empty();
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(N²)`
- **Space Complexity:** `O(1)` (Ignoring string modification cost)

---

# Optimal Approach

## Key Observation

Whenever we encounter an opening bracket, we don't yet know which closing bracket will match it.

The **most recently opened bracket must be closed first**, which follows the **LIFO (Last In, First Out)** principle.

This is exactly what a **Stack** provides.

### Example

```
([{}])
```

Traverse the string:

```
(

Stack

(
```

```
[

Stack

(
[
```

```
{

Stack

(
[
{
```

Now `}` arrives.

Top is `{`

Match found.

Pop.

```
(

Stack

(
[
```

Now `]`

Top is `[`

Match found.

Pop.

```
(

Stack

(
```

Now `)`

Top is `(`

Match found.

Pop.

```
Stack becomes empty
```

Hence the string is valid.

If at any point:

- Stack is empty when a closing bracket appears.
- Top bracket doesn't match.
- Stack is not empty after traversal.

The string is invalid.

## Approach

- Traverse every character.
- If it is an opening bracket, push it onto the stack.
- Otherwise:
  - If the stack is empty, return `false`.
  - Check whether the top opening bracket matches the current closing bracket.
  - If not, return `false`.
  - Otherwise, pop the opening bracket.
- At the end, the stack must be empty.

## Code

```cpp
class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char c : s){

            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }
            else{

                if(st.empty()) return false;

                if(c == ')' && st.top() != '(')
                    return false;

                if(c == ']' && st.top() != '[')
                    return false;

                if(c == '}' && st.top() != '{')
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(N)`

---

# Interview Notes

- This is one of the most common applications of a **Stack**.
- The problem follows the **LIFO** principle because the latest opening bracket must be matched first.
- Always check whether the stack is empty before accessing `top()`.
- At the end of traversal, the stack must be empty for the string to be valid.
- Similar stack-based matching problems include:
  - Remove Adjacent Duplicates
  - Decode String
  - Remove K Digits
  - Expression Evaluation

---

# What I Learned ⭐

- Stack is the ideal data structure for matching nested symbols.
- Every opening bracket is pushed, and every matching closing bracket pops it.
- An unmatched closing bracket or leftover opening brackets indicate an invalid expression.
- Whenever a problem requires matching the **most recent unmatched element**, a **Stack** is usually the right choice.
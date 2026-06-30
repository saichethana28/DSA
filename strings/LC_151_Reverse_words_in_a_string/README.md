# LC 151 - Reverse Words in a String

## Problem

Reverse the order of words in a string.

* Ignore leading/trailing spaces.
* Multiple spaces between words should become a single space.

---

## Approach 1 - Store Words (My First Solution)

### Thought Process

* Traverse the string from left to right.
* Build each word.
* Store every word in a `vector<string>`.
* Traverse the vector from back to front and build the answer.

### Complexity

* **Time:** `O(n)`
* **Space:** `O(n)` (vector + answer string)

### Drawback

Uses an extra vector to store all words.

---

## Key Observation 💡

I don't actually need to store every word.

If I traverse the string **from the end**, I naturally encounter the words in reverse order.

So I can directly append each word to the answer.

---

## Approach 2 - Two Pointers (Better)

### Idea

* Start `right` from the end of the string.
* Skip all spaces.
* `right` now points to the last character of a word.
* Move `left` left until a space (or `-1`).
* Append the word `s[left+1...right]`.
* Move `right = left` and repeat.

---

## Edge Cases Handled

### 1. Trailing Spaces

```text
"hello   "
```

Skip spaces first, then process `"hello"`.

---

### 2. Multiple Spaces

```text
"a   good   example"
```

Skip all consecutive spaces before finding the next word.

---

### 3. Leading Spaces

```text
"   hello"
```

After processing `"hello"`, `right` becomes `-1`.

Stop the loop.

---

### 4. Last Extra Space

Every appended word adds one space.

Remove the final space using:

```cpp
ans.pop_back();
```

---

## Complexity

* **Time:** `O(n)`
* **Space:** `O(n)` (only the answer string)

---

## What I Learned ⭐

* Before processing a word from the end, always **skip spaces**.
* Define pointer roles clearly:

  * `right` → last character of the current word.
  * `left` → space before the current word (or `-1`).
* Think about **what each pointer represents**, not just where it points.
* Handling edge cases (leading, trailing, and multiple spaces) becomes easy once the pointer roles are clear.

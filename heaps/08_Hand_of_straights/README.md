# Hand of Straights

## Problem Statement

Given a hand of cards, divide all cards into groups of size `groupSize` such that every group contains consecutive values.

Return `true` if possible, otherwise `false`.

### Examples

```text
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true

Groups: [1,2,3], [2,3,4], [6,7,8]
```

```text
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
```

## Observations

- `hand.size()` must be divisible by `groupSize`.
- The **smallest unused card must start the next group**.
- Each group needs `start, start+1, start+2, ...`.
- Frequencies are needed because duplicate values can exist across different groups.
- Once a card's frequency becomes `0`, remove it from consideration.

## Brute Force

- Find the smallest unused card.
- Search for the next `groupSize - 1` consecutive cards.
- Remove them and repeat.
- Repeated searching/removing can make it `O(N²)`.
- No code needed for this approach.

### Complexity

- **Time:** `O(N²)`
- **Space:** `O(1)` extra space

## Better Approach

- Store frequencies using an ordered `map`.
- Traverse the map to find the smallest unused card.
- Build a group by selecting consecutive cards.
- Repeatedly traversing the map makes the worst-case time `O(N²)`.

```cpp
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0)
            return false;

        map<int,int> freq;

        for(int x : hand)
            freq[x]++;

        for(int i = 0; i < n / groupSize; i++) {
            map<int,int> mp;
            int last;

            for(auto it : freq) {
                if(it.second != 0 && mp.find(it.first) == mp.end()) {

                    if(mp.size() != 0 && it.first != last + 1)
                        continue;

                    mp[it.first]++;
                    last = it.first;

                    freq[it.first]--;

                    if(freq[it.first] == 0)
                        freq.erase(it.first);
                }

                if(mp.size() == groupSize)
                    break;
            }
        }

        return freq.empty();
    }
};
```

### Complexity

- Building frequency map: `O(N log N)`
- Repeated map traversal: `O(N² / groupSize)` worst case
- **Total:** `O(N log N) + O(N² / groupSize)`
- **Worst case:** `O(N²)`
- **Space:** `O(N) + O(groupSize)` → `O(N)`

## Optimal Approach

- Use an ordered `map<int,int>` for frequencies.
- `freq.begin()` always gives the smallest unused card.
- Start a group from it and require `start, start+1, ...`.
- Decrease each frequency and erase values when their frequency becomes `0`.
- This avoids repeatedly scanning the entire map.

```cpp
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0)
            return false;

        map<int,int> freq;

        for(int x : hand)
            freq[x]++;

        while(!freq.empty()) {
            int start = freq.begin()->first;

            for(int j = 0; j < groupSize; j++) {
                int x = start + j;

                if(freq.find(x) == freq.end())
                    return false;

                freq[x]--;

                if(freq[x] == 0)
                    freq.erase(x);
            }
        }

        return true;
    }
};
```

### Complexity

- Building map: `O(N log N)`
- Processing all `N` cards: `O(N log N)`
- **Total:** `O(N log N) + O(N log N)`
- **Simplified:** `O(2N log N)` → `O(N log N)`
- **Space:** `O(N)`

## Heap Approach

- Use a **min heap** to always get the smallest available card.
- Use a frequency map to track remaining cards.
- When a card's frequency becomes `0`, leave it in the heap temporarily.
- Use **lazy deletion**: remove invalid cards only when they reach the top.
- This has the same asymptotic complexity as the map solution.

```cpp
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0)
            return false;

        unordered_map<int,int> freq;

        for(int x : hand)
            freq[x]++;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto it : freq)
            pq.push(it.first);

        while(!freq.empty()) {

            // Lazy deletion
            while(!pq.empty() && freq.find(pq.top()) == freq.end())
                pq.pop();

            int start = pq.top();

            for(int j = 0; j < groupSize; j++) {
                int x = start + j;

                if(freq.find(x) == freq.end())
                    return false;

                freq[x]--;

                if(freq[x] == 0)
                    freq.erase(x);
            }
        }

        return true;
    }
};
```

### Complexity

- Building frequency map: `O(N)`
- Building heap with at most `N` distinct values: `O(N log N)`
- Each card is processed once and heap cleanup is amortized: `O(N log N)`
- **Total:** `O(N log N)`
- **Space:** `O(N)`

## Key Takeaways

- **Pattern:** Greedy + Frequency Map.
- The **smallest unused card must start a group**.
- `map.begin()` gives the smallest unused value directly.
- Heap deletion uses **lazy deletion** because arbitrary heap deletion is expensive.
- Standard optimal solution: **Ordered Map + Greedy → `O(N log N)`**.
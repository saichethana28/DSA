# Online Stock Span

## Problem Statement

Design a class that calculates the **stock span** for each day's stock price.

The stock span of a day is the maximum number of consecutive days ending on that day for which the stock price was less than or equal to today's price.

For each new `price`, return its span.

### Example

Input:

```text
prices = [100, 80, 60, 70, 60, 75, 85]
```

Output:

```text
[1, 1, 1, 2, 1, 4, 6]
```

Explanation:

- `100` → span = `1`
- `80` → span = `1`
- `60` → span = `1`
- `70` → span = `2`
- `60` → span = `1`
- `75` → span = `4`
- `85` → span = `6`

---

## Brute Force Approach

### Idea

For every new stock price, traverse backwards through all previous prices.

Keep counting while:

```text
previous price <= current price
```

As soon as we find a previous price greater than the current price, stop.

### Algorithm

1. Store every incoming stock price in a vector.
2. For every new price:
   - Add it to the vector.
   - Start from the current index and move backwards.
   - Count consecutive prices that are less than or equal to the current price.
   - Stop when a greater price is found.
3. Return the count.

### Brute Force Code

```cpp
class StockSpanner {
public:
    vector<int> prices;

    StockSpanner() {}

    int next(int price) {
        prices.push_back(price);

        int span = 0;

        for(int i = prices.size() - 1; i >= 0; i--) {
            if(prices[i] <= price) {
                span++;
            }
            else {
                break;
            }
        }

        return span;
    }
};
```

### Brute Force Complexity

- **Time Complexity:** `O(N^2)` in the worst case.
- **Space Complexity:** `O(N)` for storing the prices.

The worst case occurs when the prices are increasing:

```text
[1, 2, 3, 4, 5, 6]
```

For every new price, we may need to scan almost the entire previous array.

---

# Optimized Approach — Monotonic Stack

## Key Observation

For every price, we need to find the **Previous Greater Element**.

Instead of checking every previous price, maintain a **monotonic decreasing stack**.

Store:

```text
{index, price}
```

The stack contains only prices that can potentially become the previous greater element for future prices.

---

## Algorithm

1. Maintain an index `idx`, initially `-1`.
2. For every incoming `price`:
   - Increment `idx`.
   - Remove all prices from the stack that are less than or equal to the current price.
   - If the stack becomes empty:
     - There is no previous greater price.
     - Span = `idx - (-1)`.
   - Otherwise:
     - The top of the stack is the nearest previous greater price.
     - Span = `idx - st.top().first`.
   - Push `{idx, price}` into the stack.
3. Return the span.

---

## Why Do We Pop Smaller or Equal Prices?

Suppose the stack contains:

```text
100
80
60
```

and the current price is:

```text
70
```

Since:

```text
60 <= 70
```

`60` cannot be the previous greater element for `70`.

So we remove it.

The stack maintains prices in decreasing order.

```text
100
80
70
```

This allows us to quickly find the nearest previous greater price.

---

## Optimized Code

```cpp
class StockSpanner {
public:
    int idx;
    stack<pair<int, int>> st;

    StockSpanner() {
        idx = -1;
    }

    int next(int price) {
        idx = idx + 1;

        int ans = 0;

        // Remove previous prices that are
        // smaller than or equal to the current price
        while(!st.empty() && st.top().second <= price) {
            st.pop();
        }

        // No previous greater element
        if(st.empty()) {
            ans = idx - (-1);
        }
        else {
            // Nearest previous greater element
            ans = idx - st.top().first;
        }

        // Store {index, price}
        st.push({idx, price});

        return ans;
    }
};
```

---

## Dry Run

Consider:

```text
prices = [100, 80, 60, 70, 60, 75, 85]
```

### Price = 100

Stack is empty.

```text
span = 0 - (-1) = 1
```

Stack:

```text
[(0,100)]
```

---

### Price = 80

`100 > 80`, so nothing is removed.

```text
span = 1 - 0 = 1
```

Stack:

```text
[(0,100), (1,80)]
```

---

### Price = 60

`80 > 60`.

```text
span = 2 - 1 = 1
```

Stack:

```text
[(0,100), (1,80), (2,60)]
```

---

### Price = 70

`60 <= 70`, so remove `60`.

Now:

```text
80 > 70
```

Therefore:

```text
span = 3 - 1 = 2
```

Stack:

```text
[(0,100), (1,80), (3,70)]
```

---

### Price = 60

`70 > 60`.

```text
span = 4 - 3 = 1
```

---

### Price = 75

Remove:

```text
60 <= 75
70 <= 75
```

Now:

```text
80 > 75
```

Therefore:

```text
span = 5 - 1 = 4
```

---

### Price = 85

Remove:

```text
75 <= 85
80 <= 85
```

Now:

```text
100 > 85
```

Therefore:

```text
span = 6 - 0 = 6
```

Final answer:

```text
[1, 1, 1, 2, 1, 4, 6]
```

---

## Complexity Analysis

### Brute Force

- **Time Complexity:** `O(N^2)` worst case
- **Space Complexity:** `O(N)`

### Optimized Monotonic Stack

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(N)`

Although there is a `while` loop, every element is pushed into the stack once and popped at most once.

Therefore, the total work is `O(N)`.

---

## Key Takeaways

- Stock Span is essentially a **Previous Greater Element** problem.
- Use a **monotonic decreasing stack** for the optimized solution.
- Store `{index, price}` instead of only the price.
- Pop while:

```cpp
st.top().second <= price
```

- If the stack is empty, the span extends to the beginning.
- Otherwise, the stack top gives the nearest previous greater element.
- Span can be calculated as:

```text
current index - previous greater index
```

- Brute force repeatedly scans previous elements.
- Monotonic stack avoids repeated work.
- Optimized complexity is **O(N) time and O(N) space**.
- This pattern is closely related to **Daily Temperatures**, **Next Greater Element**, and other monotonic-stack problems.
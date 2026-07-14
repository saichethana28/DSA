# LC 8 - String to Integer (atoi)

## Problem

Implement the `myAtoi(string s)` function, which converts a string to a **32-bit signed integer**.

The conversion follows these rules:

1. Ignore leading whitespaces.
2. Determine the sign (`+` or `-`).
3. Read consecutive digits.
4. Stop when a non-digit character is encountered.
5. Clamp the value to the range:

```
[-2^31, 2^31 - 1]
```

if overflow occurs.

---

# Brute Force Approach

## Idea

Simulate the conversion exactly as described in the problem statement.

### Algorithm

1. Skip leading whitespaces.
2. Determine the sign.
3. Traverse the digits one by one.
4. Convert each digit using

```cpp
digit = s[i] - '0';
```

5. Update the number

```cpp
num = num * 10 + digit;
```

6. Stop when a non-digit appears.
7. Before updating the number, check for overflow.

---

## Code

```cpp
class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.size();
        int sign = 1;
        int num = 0;

        while (i < n && s[i] == ' ')
            i++;

        if (i >= n)
            return 0;

        if (s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }

        while (i < n && s[i] >= '0' && s[i] <= '9') {

            int digit = s[i] - '0';

            if (num > INT_MAX / 10 ||
               (num == INT_MAX / 10 &&
                digit > (sign == 1 ? 7 : 8))) {

                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return sign * num;
    }
};
```

---

## Complexity

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(1)`

---

# Better Approach (Recursive)

## Idea

Instead of using a loop to process digits, recursively process one character at a time.

The preprocessing remains the same:

- Skip spaces.
- Determine the sign.

The recursive function only processes consecutive digits.

### Recursive Flow

```
solve(i)

↓

Base Case

↓

Process current digit

↓

Update number

↓

Recursive call

↓

solve(i+1)
```

---

## Code

```cpp
class Solution {
public:

    long long num = 0;

    void solve(int i, int n, string &s, int sign) {

        if (i == n)
            return;

        if (s[i] < '0' || s[i] > '9')
            return;

        int digit = s[i] - '0';

        if (num > INT_MAX / 10 ||
           (num == INT_MAX / 10 &&
            digit > (sign == 1 ? 7 : 8))) {

            num = (sign == 1)
                    ? INT_MAX
                    : -(long long)INT_MIN;
            return;
        }

        num = num * 10 + digit;

        solve(i + 1, n, s, sign);
    }

    int myAtoi(string s) {

        int i = 0;
        int n = s.size();
        int sign = 1;

        while (i < n && s[i] == ' ')
            i++;

        if (i < n) {

            if (s[i] == '-') {
                sign = -1;
                i++;
            }
            else if (s[i] == '+') {
                i++;
            }
        }

        solve(i, n, s, sign);

        return (int)(sign * num);
    }
};
```

---

## Complexity

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(N)` (Recursion Stack)

---

# Interview Discussion

### Which solution should be preferred?

The **iterative solution** is preferred in interviews because:

- Uses constant extra space.
- Easier to debug.
- Simpler implementation.
- Matches how `atoi()` is implemented in practice.

The recursive solution is mainly a recursion exercise and demonstrates how an iterative process can be converted into recursion.

If asked in an interview:

> **Implement atoi()**

I would first present the iterative solution.

If the interviewer asks for a recursive implementation, I would then explain the recursive approach.

---

# What I Learned ⭐

- Convert characters to digits using:

```cpp
digit = s[i] - '0';
```

- Always check for overflow **before** performing:

```cpp
num = num * 10 + digit;
```

- For overflow:

```cpp
num > INT_MAX / 10
```

or

```cpp
num == INT_MAX / 10 &&
digit > (sign == 1 ? 7 : 8)
```

- Iterative and recursive solutions have the same time complexity, but recursion uses additional stack space.

- Not every recursive solution is better than the iterative one. Choosing the right approach depends on the problem and interview expectations.
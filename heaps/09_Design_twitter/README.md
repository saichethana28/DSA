# Design Twitter

## Problem Statement

Design a simplified Twitter that supports:

- Posting tweets
- Following/unfollowing users
- Getting the **10 most recent tweets** from the user and people they follow

Tweets must be returned from **newest to oldest**.

### Examples

```text
postTweet(1, 5)
getNewsFeed(1)

Output: [5]
```

```text
follow(1, 2)
postTweet(2, 6)
getNewsFeed(1)

Output: [6,5]
```

## Observations

- Tweet ID does **not** determine the posting order, so we need a timestamp.
- Store tweets of each user in a vector as `{timestamp, tweetId}`.
- The latest tweet of a user is at the **back** of their vector.
- A news feed contains tweets from the user + followed users.
- We only need the **10 most recent** tweets.
- The optimal solution is a **K-way merge using a max heap**.

## Brute Force

- Collect all tweets from the user and everyone they follow.
- Sort all collected tweets by timestamp.
- Return the latest 10 tweets.
- This processes and sorts every relevant tweet.

### Complexity

Let `T` = total relevant tweets.

- **Time:** `O(T log T)`
- **Space:** `O(T)`

## Better Approach — Heap of Size 10

- Collect all tweets from relevant users.
- Use a **min heap of size 10**.
- The smallest timestamp is the oldest tweet.
- When heap size becomes greater than 10, remove the oldest tweet.
- Reverse the remaining tweets to get newest → oldest.

```cpp
class Twitter {
public:
    int time;
    unordered_map<int, vector<int>> following;
    unordered_map<int, vector<pair<int,int>>> userTweets;

    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> users = following[userId];
        users.push_back(userId);

        // Min heap: {timestamp, tweetId}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        for(int user : users) {
            for(auto tweet : userTweets[user]) {
                pq.push(tweet);

                if(pq.size() > 10)
                    pq.pop();
            }
        }

        vector<int> feed;

        while(!pq.empty()) {
            feed.push_back(pq.top().second);
            pq.pop();
        }

        reverse(feed.begin(), feed.end());

        return feed;
    }

    void follow(int followerId, int followeeId) {
        auto &v = following[followerId];

        if(find(v.begin(), v.end(), followeeId) == v.end())
            v.push_back(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        auto &v = following[followerId];

        v.erase(remove(v.begin(), v.end(), followeeId), v.end());
    }
};
```

### Complexity

Let `T` = total relevant tweets.

- Heap size is at most `10`.
- Each tweet performs heap operations costing `O(log 10)`.

```text
TC = O(T log 10)
   = O(T)
```

- **Space:** `O(10)` → `O(1)` extra space for the heap.

## Optimal Approach — K-Way Merge + Max Heap

- Each user's tweets are already sorted by timestamp.
- Put only the **latest tweet of each relevant user** into a max heap.
- The heap gives the globally newest tweet.
- After taking a tweet, add the **previous tweet from the same user**.
- Stop after collecting 10 tweets.

```cpp
class Twitter {
public:
    int time;

    unordered_map<int, vector<int>> following;
    unordered_map<int, vector<pair<int,int>>> userTweets;

    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> users = following[userId];
        users.push_back(userId);

        // {timestamp, tweetId, userId, index}
        priority_queue<vector<int>> pq;

        // Add latest tweet of every relevant user
        for(int user : users) {
            int n = userTweets[user].size();

            if(n == 0)
                continue;

            int idx = n - 1;

            pq.push({
                userTweets[user][idx].first,
                userTweets[user][idx].second,
                user,
                idx
            });
        }

        vector<int> feed;

        while(!pq.empty() && feed.size() < 10) {
            auto top = pq.top();
            pq.pop();

            int user = top[2];
            int idx = top[3];

            feed.push_back(top[1]);

            // Add previous tweet of the same user
            if(idx > 0) {
                idx--;

                pq.push({
                    userTweets[user][idx].first,
                    userTweets[user][idx].second,
                    user,
                    idx
                });
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        auto &v = following[followerId];

        if(find(v.begin(), v.end(), followeeId) == v.end())
            v.push_back(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        auto &v = following[followerId];

        v.erase(remove(v.begin(), v.end(), followeeId), v.end());
    }
};
```

### Complexity

Let:

- `F` = number of relevant users
- `K = 10`

Initial heap:

```text
O(F)
```

At most 10 tweets are extracted, with heap operations costing `O(log F)`:

```text
O(K log F)
```

Therefore:

```text
TC = O(F + K log F)
   = O(F + 10 log F)
```

Since `K = 10` is constant:

```text
TC = O(F + log F)
```

- **Space:** `O(F)` for the heap.

## Key Takeaways

- **Pattern:** K-Way Merge + Heap.
- Each user's tweets form a sorted sequence.
- Start with the **latest tweet from every relevant user**.
- Use a **max heap** to get the newest tweet globally.
- After taking a tweet, push the **previous tweet from that same user**.
- This is essentially **Merge K Sorted Lists in reverse order**.
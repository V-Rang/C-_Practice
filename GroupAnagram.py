from collections import defaultdict
ans = defaultdict(list)
strs = ["eat","tea","tan","ate","nat","bat"]
for s in strs:
    counter = [0]*26
    for j in s:
        counter[ord(j) - ord('a')] += 1
    ans[tuple(counter)].append(s)
print(ans.values())
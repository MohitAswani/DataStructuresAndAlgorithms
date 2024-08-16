# Rabin-Karp Algorithm

In the Rabin-Karp algorithm, instead of comparing the characters directly, we calculate the hash value of every window of the text. If it matches the hash value of the pattern, we compare the pattern with that window.

## Rolling Hash

Instead of manually calculating the hash value for each window, we use a window sliding technique for calculating hash values. This is known as a rolling hash.

t(i+1) = t(i) + txt[i+m] - txt[i]

### Spurious Hit

A spurious hit occurs when the window has the same characters as the pattern but not in the same order. We encounter spurious hits when we use a basic hash function. To avoid such issues, we use a better hash function.

Instead of just adding the ASCII values, we find the weighted sum of the characters. Hence, the formula for the rolling hash becomes:

t(i+1) = d * (t(i) - txt[i] * d^(m-1)) + txt[i+m]

where:
- \( m \) is the length of the pattern

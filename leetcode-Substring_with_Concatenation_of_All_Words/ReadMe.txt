You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

dozerg:
http://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm

heleifz:
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // length of L[i]
        int len = L[0].size();
        int N = L.size();

        // 31 ^ (len - 1) % 997
        size_t power = exponential(len - 1);

        // compute hash sum for L, and hashset for input string O(L.size() * len)
        vector<size_t> hashes;
        hashes.push_back(stringHash(S.substr(0, len)));
        size_t hashSum = 0;
        unordered_set<size_t> strSet;
        for_each(L.begin(), L.end(), [&](const string& s) {
            int hs = stringHash(s);
            strSet.insert(hs);
            hashSum += hs;
        });

        // compute hash for each position (using Rabin-Karp), O(n)
        for (int i = 1; i + len <= S.size(); ++i)
        {
            size_t newHash =  31 * 
                (hashes.back() + 997 - power * S[i - 1] % 997) + S[i + len - 1];
            hashes.push_back(newHash % 997);
        }

        // if substring S[i..i+len) is not in L, set hashes[i] to 0, O(n)
        for (int i = 0; i < hashes.size(); ++i)
        {
            if (!strSet.count(hashes[i]))
            {
                hashes[i] = 0;
            }
        }

        // O(n * L.size())
        vector<int> result;
        for (int i = 0; i + (N - 1) * len <= hashes.size(); ++i)
        {
            size_t h = 0;
            for (int j = 0; j < N; ++j)
            {
                h += hashes[i + j * len];
            }
            if (h == hashSum)
            {
                result.push_back(i); 
            }
        }
        return result;
    }

    size_t stringHash(const string& s)
    {
        size_t h = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            h = (s[i] +  31 * h) % 997;
        }
        return h;
    }

    size_t exponential(unsigned int M)
    {
        unsigned int n = 1;
        for (unsigned int i = 0; i < M; ++i)
        {
            n = (31 * n) % 997;
        }
        return n;
    }
};
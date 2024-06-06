class Solution {
public:
    bool find(string s, string t) {
        int a = 256;
        int b = 100007;
        int a2 = 256;
        int b2 = 100021;
        int pow = 1;
        int pow2 = 1;
        for (int i = 1; i < t.length(); ++i) {
            pow = (pow * a) % b;
            pow2 = (pow2 * a2) % b2;
        }
        int hash_s = 0;
        int hash_t = 0;
        int hash2_s = 0;
        int hash2_t = 0;
        for (int i = 0; i < t.length(); ++i) {
            hash_s = (hash_s * a + s[i]) % b;
            hash_t = (hash_t * a + t[i]) % b;
            hash2_s = (hash2_s * a2 + s[i]) % b2;
            hash2_t = (hash2_t * a2 + t[i]) % b2;
        }

        for (int i = 0; i <= s.length() - t.length(); ++i) {
            if (hash_s == hash_t && hash2_s == hash2_t && t == s.substr(i, t.length())) {
                return true;
            }
            if (i + t.length() == s.length()) {
                break;
            }
            hash_s = (((hash_s + b) - ((s[i] * pow) % b)) * a) % b;
            hash_s += s[i + t.length()];
            hash_s %= b;

            hash2_s = (((hash2_s + b2) - ((s[i] * pow2) % b2)) * a2) % b2;
            hash2_s += s[i + t.length()];
            hash2_s %= b2;
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        int repeat_ct = 1;
        string s = a;
        while (b.length() > s.length()) {
            s += a;
            ++repeat_ct;
        }
        if (find(s, b)) {
            return repeat_ct;
        }
        s += a;
        ++repeat_ct;
        if (find(s, b)) {
            return repeat_ct;
        }
        return -1;
    }
};
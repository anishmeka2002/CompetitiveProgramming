class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) {
            return -1;
        }
        int a = 256;
        int b = 100007;
        int a2 = 1024;
        int b2 = 100021;
        int pow = 1;
        int pow2 = 1;
        for (int i = 1; i < needle.length(); ++i) {
            pow = (pow * a) % b;
            pow2 = (pow2 * a2) % b2;
        }
        int hash_s = 0;
        int hash_t = 0;
        int hash2_s = 0;
        int hash2_t = 0;
        for (int i = 0; i < needle.length(); ++i) {
            hash_s = (hash_s * a + haystack[i]) % b;
            hash_t = (hash_t * a + needle[i]) % b;
            hash2_s = (hash2_s * a2 + haystack[i]) % b2;
            hash2_t = (hash2_t * a2 + needle[i]) % b2;
        }

        for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
            if (hash_s == hash_t && hash2_s == hash2_t && needle == haystack.substr(i, needle.length())) {
                return i;
            }
            if (i + haystack.length() == needle.length()) {
                break;
            }
            hash_s = (((hash_s + b) - (pow * haystack[i]) % b) * a) % b;
            hash_s += haystack[i + needle.length()];
            hash_s %= b;

            hash2_s = (((hash2_s + b2) - (pow2 * haystack[i]) % b2) * a2) % b2;
            hash2_s += haystack[i + needle.length()];
            hash2_s %= b;
        }
        return -1;
    }
};
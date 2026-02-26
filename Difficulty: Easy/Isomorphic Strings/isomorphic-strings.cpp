class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {
        // If the two strings have different lengths, they're not isomorphic
        if (s1.length() != s2.length()) return false; // check lengths

        unordered_map<char, char> mapS1toS2; // store mapping from s1 -> s2
        unordered_map<char, char> mapS2toS1; // store mapping from s2 -> s1

        for (int i = 0; i < s1.length(); i++) { // iterate both strings
            char c1 = s1[i]; // get the character from s1 at i
            char c2 = s2[i]; // get character from s2 at i

            // If s1's char is already mapped, check it matches s2's char
            if (mapS1toS2.find(c1) != mapS1toS2.end()) { // if c1 has mapping
                if (mapS1toS2[c1] != c2) // and it's not consistent, fail
                    return false;
            } else { // if not mapped yet, set mapping
                mapS1toS2[c1] = c2;
            }

            // If s2's char is already mapped, check it matches s1's char
            if (mapS2toS1.find(c2) != mapS2toS1.end()) { // if c2 is mapped
                if (mapS2toS1[c2] != c1) // if mapping doesn't match, fail
                    return false;
            } else { // otherwise, set mapping from c2 to c1
                mapS2toS1[c2] = c1;
            }
        }

        // If we got through all characters without a conflict,
        // the strings are isomorphic
        return true;
    }
};

vector<int> findAnagrams(string s, string p) {
    // Result vector to store starting indices of anagrams in `s`
    vector<int> result;
    int sLen = s.length(), pLen = p.length();
    
    // If `s` is shorter than `p`, it's impossible to find an anagram
    if (sLen < pLen) return result;
    
    // 1. **Create Frequency Counters**
    // Two frequency count arrays:
    // - `pCount` stores the frequency of each character in `p`
    // - `windowCount` keeps track of character frequencies in the current window of `s`
    vector<int> pCount(26, 0);
    vector<int> windowCount(26, 0);
    
    // 2. **Initialize the Frequency Counter for `p`**
    // We populate `pCount` with the character frequencies of `p`
    for (char c : p) {
        pCount[c - 'a']++;
    }
    
    // 3. **Slide Over `s` Using a Sliding Window**
    // Iterate over each character in `s`, maintaining a window of size `pLen`
    for (int i = 0; i < sLen; i++) {
        // Add the current character to `windowCount`
        windowCount[s[i] - 'a']++;
        
        // 4. **Maintain Window Size**
        // If the window exceeds `pLen`, remove the leftmost character
        if (i >= pLen) {
            windowCount[s[i - pLen] - 'a']--;
        }
        
        // 5. **Check for Anagram**
        // If `windowCount` matches `pCount`, it means an anagram has been found
        if (i >= pLen - 1 && windowCount == pCount) {
            // Store the start index of the anagram
            result.push_back(i - pLen + 1);
        }
    }
    
    // Return all found starting indices
    return result;
}

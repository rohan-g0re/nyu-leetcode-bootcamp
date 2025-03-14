

string reverseWords(string s) {
    // 1. **Use stringstream to Split Words**
    // `stringstream` allows easy tokenization of words by whitespace.
    stringstream ss(s);
    
    // Vector to store extracted words
    vector<string> words;
    
    // Temporary string variable to hold each word
    string word;
    
    // Extract words from the input string `s` using `>>` which automatically
    // removes extra spaces and stores words separately.
    while (ss >> word) {
        words.push_back(word);
    }
    
    // 2. **Reverse the Order of Words**
    // Since we need to reverse word positions, we simply reverse the vector.
    reverse(words.begin(), words.end());
    
    // 3. **Join the Words into a Single String**
    // We iterate through the reversed vector and concatenate words with single spaces.
    string result = "";
    
    for (int i = 0; i < words.size(); i++) {
        // Add a space before appending words (except for the first word)
        if (i > 0) result += " ";
        
        // Append the word to the result string
        result += words[i];
    }
    
    // Return the final reversed string
    return result;
}

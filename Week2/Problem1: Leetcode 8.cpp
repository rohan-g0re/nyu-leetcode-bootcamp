
int myAtoi(string s) {
    // Initialize an index variable `i` to traverse the string.
    int i = 0;
    // Get the length of the input string.
    int n = s.length();
    
    // 1. Skipping Leading Whitespace
    // The loop continues moving `i` forward as long as the current character is a space (' ').
    // This ensures that we ignore any leading whitespaces before processing the number.
    while (i < n && s[i] == ' ') {
        i++;
    }
    
    // 2. Handling Sign (Positive or Negative)
    // The variable `sign` determines whether the final result should be positive or negative.
    // Default assumption is positive (`sign = 1`).
    int sign = 1;
    // If a sign character (`+` or `-`) is found, update the `sign` variable accordingly.
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;  // Move to the next character after processing the sign.
    }
    
    // 3. Converting the Number from Characters to an Integer
    // Initialize `result` to store the numerical value extracted from the string.
    int result = 0;
    while (i < n && s[i] >= '0' && s[i] <= '9') {  // Check if the character is a digit.
        int digit = s[i] - '0';  // Convert character to integer value.

        // 4. Handling Overflow Cases
        // Before adding `digit` to `result`, check if multiplying by 10 and adding `digit`
        // would cause an integer overflow.
        // INT_MAX = 2147483647, INT_MIN = -2147483648
        // We check the condition:
        // - If `result` is already greater than `INT_MAX / 10`, then multiplying it by 10 would cause an overflow.
        // - If `result` is equal to `INT_MAX / 10` and the next digit is greater than `7` (last digit of INT_MAX),
        //   then adding it would exceed INT_MAX.
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
            // If overflow occurs, return INT_MAX if `sign` is positive, otherwise return INT_MIN.
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        // Update `result` by shifting digits left (multiplying by 10) and adding the new digit.
        result = result * 10 + digit;
        i++;  // Move to the next character.
    }
    
    // 5. Returning the Final Result
    // Multiply `result` by `sign` to apply the correct sign (positive or negative).
    return sign * result;
}

# 2381. Shifting Letters II using Prefix Sum Approach
- ### Intuition
    The problem requires us to shift the letters in a string according to a set of range-based shift operations. Each operation specifies a range of indices in the string and a direction (right or left) for shifting the letters within that range.

    We need an efficient way to handle these range-based shifts. Directly updating the string for each operation would be slow. Instead, we can leverage the **prefix sum technique**, where we record the "increment" and "decrement" operations at the start and just past the end of each range, respectively. After processing all operations, we can accumulate these changes to determine the final shift for each character.

- ### Approach
    1. **Prefix Sum Array**: 
        - Create an array (`overall_Shifts`) to track the cumulative shifts for each character in the string. This array will help us efficiently handle range-based shifts.
        - For each shift operation `(l, r, d)`:
            - If `d == 1` (right shift), increment the shift at index `l` and decrement the shift at `r + 1`.
            - If `d == 0` (left shift), decrement the shift at index `l` and increment the shift at `r + 1`.
    2. **Applying Shifts**:
        - After all shift operations are processed, traverse the string and apply the cumulative shifts using the `overall_Shifts` array.
        - For each character in the string, accumulate the shifts and use modulo arithmetic to apply the circular shift in the alphabet. Convert each character based on the accumulated shifts.
    3. **Final Output**:
        - Construct the resulting string by applying the cumulative shifts to each character.

- ### Code Implementation
    - **Python Solution**
        ```python3 []
        class Solution:
            def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
                # Helper function to shift a character by a certain number of positions in the alphabet
                def shift_Char(current_Char: str, total_Shifts: int) -> str:
                    # Convert the character to its 0-based index (0 for 'a', 1 for 'b', ..., 25 for 'z')
                    current_Pos = ord(current_Char) - ord('a')
                    # Apply the total shifts, using modulo 26 to handle circular shifts (wrap around the alphabet)
                    new_Pos = (current_Pos + total_Shifts) % 26
                    # Convert back to the character and return it
                    return chr(ord('a') + new_Pos)

                # Get the length of the string
                n = len(s)
                
                # Array to store the cumulative shifts for each character in the string
                overall_Shifts = [0] * n
                
                # Process each shift operation in the shifts list
                for l, r, d in shifts:
                    if d == 1:  # Right shift operation
                        # Increment shift at the start index l
                        overall_Shifts[l] += 1
                        # Decrement shift at index r+1 (i.e., after the range)
                        if r + 1 < n: 
                            overall_Shifts[r + 1] -= 1
                    else:  # Left shift operation
                        # Decrement shift at the start index l
                        overall_Shifts[l] -= 1
                        # Increment shift at index r+1 (i.e., after the range)
                        if r + 1 < n:
                            overall_Shifts[r + 1] += 1
                
                # Initialize variable to accumulate the total shifts as we traverse the string
                total_Shifts = 0
                # String to store the final shifted characters
                result = ''

                # Traverse through the string, applying the cumulative shifts to each character
                for i in range(n):
                    # Update the total shifts by adding the shift at the current position
                    total_Shifts += overall_Shifts[i]
                    # Apply the shift to the current character and append to the result string
                    result += shift_Char(s[i], total_Shifts)
                
                # Return the final result string with all shifts applied
                return result
        ```
    - **C++ Solution**
        ```cpp []
        private:
            // Helper function to shift a character by a certain number of positions in the alphabet
            char shift_Char(char current_Char, int total_Shifts) {
                // Convert the character to a 0-based index (0 for 'a', 1 for 'b', ..., 25 for 'z')
                int current_Pos = current_Char - 'a';
                // Apply the total shifts, using modulo 26 to handle circular shifts (wrap around the alphabet)
                int new_Pos = (current_Pos + total_Shifts) % 26;
                // Ensure the position is always within the bounds of the alphabet (handle negative shifts)
                if (new_Pos < 0) new_Pos += 26;
                // Convert back to the character and return it
                return char('a' + new_Pos);
            }

        public:
            string shiftingLetters(string s, vector<vector<int>> shifts) {
                // Array to store the cumulative shifts for each character in the string
                vector<int> overall_Shifts(s.length(), 0);

                // Process each shift operation in the shifts vector
                for(const vector<int>& shift: shifts) {
                    int l = shift[0], r = shift[1], d = shift[2];
                    
                    // If d == 1, perform a right shift operation
                    if(d == 1) {
                        // Increment shift at the start index l
                        ++overall_Shifts[l];
                        // Decrement shift at index r+1 (i.e., after the range)
                        if(r+1 < s.length()) --overall_Shifts[r+1];
                    }
                    else {
                        // If d == 0, perform a left shift operation
                        // Decrement shift at the start index l
                        --overall_Shifts[l];
                        // Increment shift at index r+1 (i.e., after the range)
                        if(r+1 < s.length()) ++overall_Shifts[r+1];
                    }
                }

                // Variable to accumulate the total shift for each character as we traverse the string
                int total_Shifts = 0;
                // Result string to store the shifted characters
                string result = "";
                
                // Traverse the string, applying the cumulative shifts to each character
                for(int i = 0; i < s.length(); ++i) {
                    // Update the total shifts by adding the shift at the current position
                    total_Shifts += overall_Shifts[i];
                    // Append the shifted character to the result string
                    result += shift_Char(s[i], total_Shifts);
                }

                // Return the final result string with all shifts applied
                return result;
            }
        };
        ```

- ### Time Complexity
    - **Processing the shift operations**: For each shift operation `(l, r, d)`, we only perform constant-time operations (incrementing and decrementing the `overall_Shifts` array). This gives us a time complexity of $O(m)$, where $m$ is the number of shift operations.
    - **Applying the shifts**: We traverse the string of length $n$ and accumulate the shifts. This takes $O(n)$ time.
    
    - Thus, the overall time complexity is **$O(n + m)$**, where $n$ is the length of the string and $m$ is the number of shift operations.

- ### Space Complexity
    - The space complexity is dominated by the `overall_Shifts` array, which stores the cumulative shifts for each character in the string. The size of this array is $n$, where $n$ is the length of the string.

    - Thus, the overall space complexity is **$O(n)$**.

- ### Full Solution: 
    - [**Shifting Letters II**](https://github.com/madiv9820/05_01_2025--2381_Shifting_Letters_II)
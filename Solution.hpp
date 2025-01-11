#include <string>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

class Solution {
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
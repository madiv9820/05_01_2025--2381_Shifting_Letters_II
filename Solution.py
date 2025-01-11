from typing import List

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
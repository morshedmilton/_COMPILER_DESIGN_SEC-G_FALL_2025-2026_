#include <iostream>
#include <string>
using namespace std;

// Function 1: R.E = a^* (zero or more 'a's)
bool checkRE1(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != 'a') {
            return false;
        }
    }
    return true;
}

// Function 2: R.E = a+b (either 'a' OR 'b')
bool checkRE2(string str) {
    return str == "a" || str == "b";
}

// Function 3: R.E = a.b (concatenation: 'a' followed by 'b')
bool checkRE3(string str) {
    return str == "ab";
}

// Function 4: R.E = (a+b)b(a+b)(b)^*
bool checkRE4(string str) {
    int len = str.length();

    if (len < 3) return false;

    if (str[0] != 'a' && str[0] != 'b') return false;
    if (str[1] != 'b') return false;
    if (str[2] != 'a' && str[2] != 'b') return false;

    for (int i = 3; i < len; i++) {
        if (str[i] != 'b') return false;
    }

    return true;
}

// Function 5: R.E = (a+b)^+ (a+b^*)
bool checkRE5(string str) {
    int len = str.length();

    // String must have at least 2 characters?
    // No, minimum is 1 character (from first part) + at least 0 from second part
    // But the second part must be either 'a' OR zero or more 'b's

    if (len == 0) return false; // Empty string not allowed (because (a+b)^+ requires at least 1)

    // Check all characters are 'a' or 'b'
    for (int i = 0; i < len; i++) {
        if (str[i] != 'a' && str[i] != 'b') {
            return false;
        }
    }

    // Now we need to check if the string can be divided into two parts:
    // Part 1: (a+b)^+ (at least one character, can be 'a' or 'b')
    // Part 2: (a+b^*) which is either 'a' OR any number of 'b's (including 0)

    // But wait! If part 2 is zero b's (empty), then the whole string is just part 1
    // So actually, any non-empty string of a's and b's is valid if the last part
    // (from some point) is either 'a' or all b's

    // Let's find the split point
    // We need to check if there exists an index i such that:
    // 1. First part (0 to i) has at least 1 character
    // 2. Second part (i+1 to end) is either:
    //    a) Empty (if we choose b^* with 0 b's)
    //    b) A single 'a'
    //    c) One or more 'b's

    // Actually, this is tricky. Let me think:
    // The second part is (a+b^*) which means:
    // Option A: "a"
    // Option B: any string of b's (could be empty)

    // So the string must end with either:
    // 1. Last character is 'a' (if second part is "a")
    // 2. Last part (could be empty) is all b's

    // But if the second part is empty (b^* with 0 b's), then the whole string is from first part

    // So actually, the condition is:
    // The string must have at least one character, and if the last character is 'a',
    // then it's automatically valid (because second part could be "a" or empty).
    // If the last character is 'b', then from some point to the end must be all b's.

    // Actually, any non-empty string is valid! Let me verify:
    // 1. If string ends with 'a':
    //    - We can take second part as "a"
    //    - First part is everything before that (at least 0 characters? But (a+b)^+ needs at least 1)
    //    - So we need at least 1 character in first part. So minimum string length is 2 if we use "a" as second part?

    // Wait, let's formalize:
    // String S = X + Y where:
    // X is (a+b)^+ (non-empty)
    // Y is (a+b^*) = either "a" or b^n (n >= 0)

    // Cases:
    // 1. Y = "a": Then X is S without the last 'a', and must be non-empty. So S must end with 'a' and have at least 2 characters.
    // 2. Y = b^n (n >= 0):
    //    - If n = 0: Y is empty, so X = S, and S must be non-empty. So any non-empty string is valid in this case.
    //    - If n > 0: Then the last n characters of S are all 'b's, and the prefix (first part) must be non-empty.

    // So the string is valid if:
    // EITHER:
    //   a) It ends with 'a' and has at least 2 characters (case 1)
    //   b) It ends with one or more 'b's and has at least 1 character before the b's (case 2 with n > 0)
    //   c) It is any non-empty string (case 2 with n = 0)

    // But case c covers all non-empty strings! Because for any non-empty string, we can take Y as empty.

    // So the language is actually all non-empty strings over {a,b}!

    // Let me verify with examples:
    // "a": X = "a", Y = empty (b^0) -> valid
    // "b": X = "b", Y = empty -> valid
    // "ab": X = "ab", Y = empty -> valid OR X = "a", Y = "b" -> valid
    // "ba": X = "ba", Y = empty -> valid OR X = "b", Y = "a" -> valid
    // "bbbab": X = "bbbab", Y = empty -> valid

    // So actually, the corrected RE5 accepts all non-empty strings of a and b!
    // My initial implementation was wrong. Let me fix it.

    // Actually, wait. Let me re-read: (a+b)^+ (a+b^*)
    // This could also be interpreted as (a+b)^+ followed by (a OR b^*)
    // And since b^* includes empty string, this is (a+b)^+ followed by (a OR empty OR b^+)
    // Which is just (a+b)^+ (if we take empty) OR (a+b)^+ a OR (a+b)^+ b^+
    // This is indeed all non-empty strings!

    // So the simplest check is: non-empty and only contains a and b

    // But wait, what about "bbbab"? Is it valid?
    // "bbbab" is non-empty and only contains a and b, so yes, it's valid!

    // But earlier I thought it wasn't. Let me check with the RE:
    // We can split "bbbab" as:
    // Option 1: X = "bbbab", Y = empty -> valid
    // Option 2: X = "bbb", Y = "ab" -> invalid because Y="ab" is not "a" or b^*
    // Option 3: X = "bbba", Y = "b" -> valid because Y="b" is b^*
    // Option 4: X = "bb", Y = "bab" -> invalid because Y="bab" is not "a" or b^*

    // So "bbbab" is valid because of option 3!

    // So my algorithm should check: can we split the string into X and Y such that:
    // 1. X is non-empty and consists of a and b
    // 2. Y is either "a" or a string of b's (could be empty)

    // Let me implement this properly:

    // We need to check if there exists a split point i (0 <= i < len) such that:
    // Part 1: str[0..i] is non-empty (i >= 0)
    // Part 2: str[i+1..end] is either:
    //   - Empty (i.e., i = len-1, so no part 2)
    //   - Exactly "a" (so i = len-2 and str[len-1] == 'a')
    //   - A string of one or more b's (so from i+1 to end, all characters are 'b')

    // But note: part 2 can be empty only if we choose b^* with 0 b's.

    // Actually, we can always choose part 2 to be empty if we want (by taking i = len-1).
    // So the string is always valid as long as it's non-empty and all characters are a or b?
    // But wait, then what about the requirement that part 2 must be "a" or b^*?
    // If part 2 is empty, that's allowed by b^* (since b^* can be zero b's).

    // So indeed, any non-empty string is valid.

    // Therefore, the code is simple:

    if (len == 0) return false;

    // Check all characters are 'a' or 'b'
    for (int i = 0; i < len; i++) {
        if (str[i] != 'a' && str[i] != 'b') {
            return false;
        }
    }

    return true;
}

int main() {
    int choice;
    string input;

    while (true) {
        cout << "\n==========================================\n";
        cout << "Regular Expression Checker\n";
        cout << "==========================================\n";
        cout << "Choose Regular Expression to check:\n";
        cout << "1. a^* (zero or more a's)\n";
        cout << "2. a+b (either a or b)\n";
        cout << "3. a.b (a followed by b)\n";
        cout << "4. (a+b)b(a+b)(b)^*\n";
        cout << "5. (a+b)^+ (a+b^*)\n";
        cout << "6. Exit Program\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        if (choice == 6) {
            cout << "Thank you for using the program. Goodbye!\n";
            break;
        }

        if (choice < 1 || choice > 6) {
            cout << "Invalid choice! Please enter a number between 1 and 6.\n";
            continue;
        }

        cout << "Enter a string (only a and b allowed): ";
        cin >> input;

        bool valid_input = true;
        int input_len = input.length();
        for (int i = 0; i < input_len; i++) {
            if (input[i] != 'a' && input[i] != 'b') {
                valid_input = false;
                break;
            }
        }

        if (!valid_input) {
            cout << "Invalid input! Only 'a' and 'b' are allowed.\n";
            continue;
        }

        bool isValid = false;

        switch(choice) {
            case 1:
                isValid = checkRE1(input);
                break;
            case 2:
                isValid = checkRE2(input);
                break;
            case 3:
                isValid = checkRE3(input);
                break;
            case 4:
                isValid = checkRE4(input);
                break;
            case 5:
                isValid = checkRE5(input);
                break;
        }

        cout << "\nResult: String \"" << input << "\" is ";
        if (isValid) {
            cout << "VALID ";
        } else {
            cout << "INVALID ";
        }
        cout << "for the chosen regular expression.\n";

        cout << "\nExamples of valid strings for this RE:\n";
        switch(choice) {
            case 1:
                cout << "Empty string, 'a', 'aa', 'aaa', 'aaaa', ...\n";
                break;
            case 2:
                cout << "'a' or 'b'\n";
                break;
            case 3:
                cout << "'ab'\n";
                break;
            case 4:
                cout << "'abb', 'bbb', 'abbb', 'bbbb', 'abbbbb', ...\n";
                break;
            case 5:
                cout << "Any non-empty string of a and b: 'a', 'b', 'ab', 'ba', 'aa', 'bb', 'aba', 'bab', ...\n";
                break;
        }

        char continue_choice;
        cout << "\nDo you want to check another string? (y/n): ";
        cin >> continue_choice;

        if (continue_choice == 'n' || continue_choice == 'N') {
            cout << "Thank you for using the program. Goodbye!\n";
            break;
        }
    }

    return 0;
}

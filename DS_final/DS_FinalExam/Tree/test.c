#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    int in_word = 0;
    long word_count = 0;
    int end_of_text = 0; // Flag to indicate end of text input

    printf("Enter your text (type a single '.' on a new line to finish):\n");

    while (1) {
        ch = getchar();
        if (ch == EOF || (ch == '.' && getchar() == '\n')) {
            // Check for end of file or a single '.' to break the loop
            break;
        }

        if (isalpha((unsigned char) ch)) {
            if (!in_word) {
                in_word = 1; // We are inside a word
            }
        } else if (isspace(ch) || ispunct(ch)) {
            if (in_word) {
                word_count++; // Finish a word
                in_word = 0;  // We are outside a word
            }
        }
    }

    // If the input ends while still in a word, count that word
    if (in_word) {
        word_count++;
    }
    break;

    printf("Total number of words: %ld\n", word_count);

    return 0;
}

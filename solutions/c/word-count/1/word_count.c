#include "word_count.h"


int count_words(const char *sentence, word_count_word_t *words)
{
    int uniqueWords = 0;

    char buffer[MAX_WORD_LENGTH + 1];
    int buf_idx = 0;

    for (const char *p = sentence; ; ++p)
    {
        char c = *p;

        if (isalnum(c) || c == '\'') {
            if (buf_idx < MAX_WORD_LENGTH) {
                buffer[buf_idx++] = tolower(c);
            } else {
                return EXCESSIVE_LENGTH_WORD;
            }
        }
        else
        {
            if (buf_idx > 0) {
                buffer[buf_idx] = '\0';

                // trim leading apostrophes
                int start = 0;
                while (buffer[start] == '\'') start++;

                // trim trailing apostrophes
                int end = strlen(buffer) - 1;
                while (end >= start && buffer[end] == '\'') end--;

                // extract cleaned word
                if (start <= end) {
                    char clean[MAX_WORD_LENGTH + 1];
                    int j = 0;

                    for (int i = start; i <= end; i++) {
                        clean[j++] = buffer[i];
                    }
                    clean[j] = '\0';

                    // search existing words
                    int found = 0;
                    for (int i = 0; i < uniqueWords; i++) {
                        if (strcmp(words[i].text, clean) == 0) {
                            words[i].count++;
                            found = 1;
                            break;
                        }
                    }

                    // insert new word
                    if (!found) {
                        if (uniqueWords >= MAX_WORDS) {
                            return EXCESSIVE_NUMBER_OF_WORDS;
                        }
                        strcpy(words[uniqueWords].text, clean);
                        words[uniqueWords].count = 1;
                        uniqueWords++;
                    }
                }

                buf_idx = 0;
            }
        }

        if (c == '\0') break;
    }

    return uniqueWords;
}
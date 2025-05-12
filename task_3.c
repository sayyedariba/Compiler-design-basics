#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[32][10] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"
};

int isKeyword(char *word) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(keywords[i], word) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '=' || ch == '<' || ch == '>' || ch == '%' || ch == '!');
}

int main() {
    FILE *fp;
    char ch, buffer[100];
    int i = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch)) {
            buffer[i++] = ch;
        } else if (ch == ' ' || ch == '\n' || ch == '\t') {
            if (i != 0) {
                buffer[i] = '\0';
                i = 0;
                if (isKeyword(buffer))
                    printf("[Keyword] %s\n", buffer);
                else
                    printf("[Identifier] %s\n", buffer);
            }
        } else if (isOperator(ch)) {
            printf("[Operator] %c\n", ch);
        }
    }

    fclose(fp);
    return 0;
}

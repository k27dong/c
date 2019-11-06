void escape (char s[], char t[]);

void escape (char s[], char t[]) {
    int i, c, j;
    for (i = 0, j = 0; (c = t[i]) != '\0'; ++i) {
        switch (c) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
        }
        s[i] = c;
    }
    s[j] = '\0';
}
#define FILE_MANAGEMENT

/* Lê um arquivo */
void read_file(char filePath[]);

/* Reescreve um arquivo */
void rewrite_file(char filePath[], char input[]);

/* Adiciona a um arquivo */
void append_to_file(char filePath[], char input[]);

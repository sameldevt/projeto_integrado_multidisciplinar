/*

#include<stdio.h>
#include <string.h>

int rank_theme(char theme_path[101]) {
    int length;
    
    FILE * file = fopen(theme_path, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        length++;
    }

    for (int i = 0; i < length; i++) {

    }
}

int calculate_feedback_average(char theme_path[101]) {
    char line[256];
    int rate_sum;
    int i;

    FILE* file = fopen(theme_path, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {        
        // Tokenize the line
        char token[2] = strtok(line, ',');

        // Store the token in a variable
        char feedback[2];  // Adjust the size based on your needs
        strcpy(feedback, token);  // Copy the token into the variable

        int int_feedback = (int)feedback;

        rate_sum += int_feedback;
        i++;
    }

    return rate_sum / i;
}

int calculate_feedback_average(char file_path[101]) {
    int average;
    FILE *feedback = fopen(file_path, "r");

    if (feedback == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        int rate_sum;
        char line;
        char line[256];

        // Tokenize the line
        token = strtok(line, ',');

        // Store the token in a variable
        char feedback[2];  // Adjust the size based on your needs
        strcpy(feedback, token);  // Copy the token into the variable

        int int_feedback = (int)feedback;

        rate_sum += int_feedback;
        i++;
    }

    return rate_sum / i;
}

int order_by_rate() {
    int t1r = calculate_feedback_average();
    int t2r = calculate_feedback_average();
    int t3r = calculate_feedback_average();
    int t4r = calculate_feedback_average();

    int theme_avg_arr[5] = { t1r, t2r, t3r, t4r };

    int higher = 0;

    for (int i = 0; i < 5; i++) {
        if (theme_avg_arr[i] > theme_avg_arr[higher]) {
            int aux = theme_avg_arr[i];
            theme_avg_arr[i] = theme_avg_arr[higher];
            theme_avg_arr[higher] = aux;

            higher = i;
        }
    }

    char result[10];
    for (int i = 0; i < 5; i++) {
        result[i] = strcon(result[i], theme_avg_arr[i]);
    }

    rewrite_file(menu_theme_list, result);
}

*/
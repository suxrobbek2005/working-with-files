#include <stdio.h>
#include <stdlib.h>

int main() {

    // Dastur davomida ishlatiladigan o'zgaruvchilar yaratib olindi

    FILE *input_file, *passedFile, *failedFile;
    char name[50];
    int score;

    // kirish faylini yaratib oldik

    input_file = fopen("students.txt", "r");
    if (input_file == NULL) {
        return 1;
    }
    
    // O'quvchilarni o'tganlar fayli yaratib olindi

    passedFile = fopen("passed.txt", "w");
    if (passedFile == NULL) {
        fclose(input_file);
        return 1;
    }
    
    // O'quvchilarni o'tmaganlar fayli yaratib olindi

    failedFile = fopen("failed.txt", "w");
    if (failedFile == NULL) {
        fclose(input_file);
        fclose(passedFile);
        return 1;
    }

    // Fayldan O'quvchilarni o'tgan yoki o'tmaganlikgini ajratib olish sharti quyildi

    while (fscanf(input_file, "%s %d", name, &score) == 2) {
        if (score >= 60) {
            fprintf(passedFile, "%s %d\n", name, score);
        } else {
            fprintf(failedFile, "%s %d\n", name, score);
        }
    }

    // Fayllarni yopish
    
    fclose(input_file);
    fclose(passedFile);
    fclose(failedFile);
    
    // Terminalga chiqadi 

    printf("O'quvchilar saralanib bulindi!\n");
    return 0;
}

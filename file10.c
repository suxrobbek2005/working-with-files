#include <stdio.h>

int main() {
    FILE *enter_fayl, *close_fayl;
    int sonlar[10], i;

    // Kirish faylini ochish
    enter_fayl = fopen("input.txt", "r");
    if (enter_fayl == NULL) {
        return 1;
    }

    // Kirish faylidan sonlarni o'qish
    for (i = 0; i < 10; i++) {
        if (fscanf(enter_fayl, "%d", &sonlar[i]) != 1) {
            fclose(enter_fayl);
            return 1;
        }
    }

    // Chiqish faylini ochish
    
    close_fayl = fopen("output.txt", "w");
    if (close_fayl == NULL) {
        return 1;
    }

    // Dastlabki va oxirgi sonlarni yozish
    // Birinchi son
    fprintf(close_fayl, "%d\n", sonlar[0]); 
     // Oxirgi son
    fprintf(close_fayl, "%d\n", sonlar[9]);
    
    // Ochilgan fayllarimiz yopildi
    fclose(close_fayl);
    fclose(enter_fayl);

    // Termenalga chiqadi dasturimiz to'ri shlayotganini bildiradi

    printf("Dastlabki va oxirgi sonlar output.txt fayliga yozildi.\n");

    return 0;
}

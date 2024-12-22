#include <stdio.h>

int main() {

    // Dastur davomida ishlatiladigan o'zgaruvchilar yaratib ildik
    FILE *kirishFayl1, *kirishFayl2, *chiqishFayl;
    char satr[1024];

    // Kirish faylini ochib olish
    kirishFayl1 = fopen("fayl1.txt", "r");
    if (kirishFayl1 == NULL) {
        return 1;
    }
    // kirish2 faylini ochib olish
    kirishFayl2 = fopen("fayl2.txt", "r");
    if (kirishFayl2 == NULL) {
        fclose(kirishFayl1);
        return 1;
    }
    // Chiqish faylini ochib olish
    chiqishFayl = fopen("output.txt", "w");
    if (chiqishFayl == NULL) {
        fclose(kirishFayl1);
        fclose(kirishFayl2);
        return 1;
    }

    // Fayl1 ma'lumotlarini o'qish va yozish
    while (fgets(satr, sizeof(satr), kirishFayl1) != NULL) {
        fputs(satr, chiqishFayl);
    }

    // Fayl2 ma'lumotlarini o'qish va yozish
    while (fgets(satr, sizeof(satr), kirishFayl2) != NULL) {
        fputs(satr, chiqishFayl);
    }

    // Fayllarni yopish
    fclose(kirishFayl1);
    fclose(kirishFayl2);
    fclose(chiqishFayl);
    
    // Dasturdagi ammalarni ochib olish 
    printf("Fayllar birlashtirilib output.txt fayliga yozildi.\n");

    return 0;
}

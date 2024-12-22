#include <stdio.h>

int main() {
    FILE *enter_fayl, *close_fayl;
    int farq;
    char belgi;

    // Fayllarni ochish
    enter_fayl = fopen("input.txt", "r");
    if (enter_fayl == NULL) {
        printf("input.txt faylini ochishda xatolik yuz berdi!\n");
        return 1;
    }

    close_fayl = fopen("output.txt", "w");
    if (close_fayl == NULL) {
        printf("output.txt faylini yaratishda xatolik yuz berdi!\n");
        fclose(enter_fayl);
        return 1;
    }

    // ASCII kodlarini o'qish va belgilarga aylantirish
    while (fscanf(enter_fayl, "%d", &farq) != EOF) {
        belgi = (char)farq; // ASCII kodni belgiga aylantirish
        fprintf(close_fayl, "%c", belgi); // Belgini faylga yozish
    }

    // Fayllarni yopish
    fclose(enter_fayl);
    fclose(close_fayl);

    printf("Matn output.txt fayliga yozildi.\n");

    return 0;
}

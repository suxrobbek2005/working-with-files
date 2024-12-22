#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *uz_word, *eng_word, *combined_fayl;
    char uzbekSoz[256], inglizSoz[256];

    // Uzbek fayli ochib olndi 
    uz_word = fopen("uzbek.txt", "r");
    if (uz_word == NULL) {
        return 1;
    }
    
    // Eng_word fayli ham ochib olndi 
    eng_word = fopen("ingliz.txt", "r");
    if (eng_word == NULL) {
        fclose(uz_word);
        return 1;
    }
    
    // Comibned fayli ham ochib olnid
    combined_fayl = fopen("birlashtirilgan.txt", "w");
    if (combined_fayl == NULL) {
        fclose(uz_word);
        fclose(eng_word);
        return 1;
    }

    // Fayllarni o'qish va birlashtirish
    while (fgets(uz_word, sizeof(uz_word), uz_word) != NULL && 
           fgets(eng_word, sizeof(eng_word), eng_word) != NULL) {
        // Yangi qator belgisini olib tashlash
        uz_word[strcspn(uz_word, "\n")] = '\0';
        eng_word[strcspn(eng_word, "\n")] = '\0';

        // Birlashtirilgan formatda yozish
        fprintf(combined_fayl, "%s - %s\n", eng_word, uz_word);
    }

    // Fayllarni yopish
    fclose(uz_word);
    fclose(eng_word);
    fclose(combined_fayl);

    printf("So'zlar birlashtirilib birlashtirilgan.txt fayliga yozildi.\n");

    return 0;
}

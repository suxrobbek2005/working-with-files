#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE *enterFayl, *juftFayl, *toqFayl;
    int son;

    // Kirish faylini ochish 
    enterFayl = fopen("sonlar.txt", "r"); 
    // Faylarni ochishda to'gri bo'lsa ishlaydi
    if (enterFayl == NULL) {
        return 1;
    }

    // Juft fayl ochib olndi 
    juftFayl = fopen("juft.txt", "w");
    if (juftFayl == NULL) {
        fclose(enterFayl);
        return 1;
    }
    // Toq fayl ochib olndi 
    toqFayl = fopen("toq.txt", "w");
    if (toqFayl == NULL) {
        fclose(enterFayl);
        fclose(juftFayl);
        return 1;
    }

    // Sonlarni o'qish va mos fayllarga yozish
    while (fscanf(enterFayl, "%d", &son) != EOF) {
        if (son % 2 == 0) {
            fprintf(juftFayl, "%d ", son);
        } else {
            fprintf(toqFayl, "%d ", son);
        }
    }

    // Fayllarni yopish
    fclose(enterFayl);
    fclose(juftFayl);
    fclose(toqFayl);

    printf("Juft sonlar juft.txt fayliga, toq sonlar toq.txt fayliga yozildi.\n");

    return 0;
}

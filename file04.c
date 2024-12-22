#include <stdio.h>

int main() {

    // Dastur davomida kerakli o'zgaruvchilarni yaratib oldik
    FILE *fayl;
    int sonlar[5];
    int i, yigindi = 0;

    // Foydalanuvchidan 5 ta sonni kiritishni so'rash
    printf("5 ta son kiriting:\n");
    for (i = 0; i < 5; i++) {
        printf("%d-son: ", i + 1);
        // Sonlarni kiritb olamiz
        scanf("%d", &sonlar[i]);
        // Kiritilgan sonlarni yig'indisini hisoblab boradi
        yigindi += sonlar[i];
    }

    // Faylni ochish
    fayl = fopen("new.txt", "w");
    if (fayl == NULL) {
        // Agarda faylda xatolik yuz bersa dastur ishlamaydi
        return 1;
    }

    // Sonlarni va yig'indini faylga yozish
    fprintf(fayl, "%d", sonlar[0]);
    // bestha son kiritishimiz uchun loopimizni 5ta aylantitirin 
    for (i = 1; i < 5; i++) {
        fprintf(fayl, " + %d", sonlar[i]);
    }
    fprintf(fayl, " = %d\n", yigindi);

    // Faylni yopish
    fclose(fayl);

    printf("Sonlar va ularning yig'indisi new.txt fayliga yozildi.\n");

    return 0;
}

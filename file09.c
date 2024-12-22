#include <stdio.h>

int main() {
    FILE *enter_fayl, *close_fayl;
    char belgi;
    int plus = 0, minus = 0, kopaytirish = 0, bolish = 0, qoldiq = 0;

    // Fayllarni ochish
    enter_fayl = fopen("input.txt", "r");
    if (enter_fayl == NULL) {
        return 1;
    }

    // Chiqish faylini kiritib oldik

    close_fayl = fopen("output.txt", "w");
    if (close_fayl == NULL) {
        fclose(enter_fayl);
        return 1;
    }

    // Kirish faylidagi ifodani o'qish va amallarni hisoblash

    while ((belgi = fgetc(enter_fayl)) != EOF) {

        // Xar bir gilgini dasturga tanitib oldik

        if (belgi == '+') {
            plus++;
        } else if (belgi == '-') {
            minus++;
        } else if (belgi == '*') {
            kopaytirish++;
        } else if (belgi == '/') {
            bolish++;
        } else if (belgi == '%') {
            qoldiq++;
        }
    }

    // Hisoblangan natijalarni output.txt fayliga yozish
    fprintf(close_fayl, " '+' ishlatilgan: %d marta\n", plus);
    fprintf(close_fayl, " '-' ishlatilgan: %d marta\n", minus);
    fprintf(close_fayl, " '*' ishlatilgan: %d marta\n", kopaytirish);
    fprintf(close_fayl, " '/' ishlatilgan: %d marta\n", bolish);
    fprintf(close_fayl, " '%%' ishlatilgan: %d marta\n", qoldiq);

    // Fayllarni yopish
    fclose(enter_fayl);
    fclose(close_fayl);

    // Terminalaga chiqadi

    printf("Amallar qancha ishtirok etishi output.txt fayliga yozildi! \n");

    return 0;
}

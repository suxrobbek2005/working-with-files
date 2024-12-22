#include <stdio.h>
#include <stdlib.h>

int main() {

    // Dasturga kerakli bulgan barcha uzgaruvchilarni yaratib olidk
    FILE *enter_file, *close_file;
    char satr[256];
    int qatorRaqami, joriyQator = 1;

    // Foydalanuvchidan qator raqamini so'rash
    printf("O'chiriladigan qator raqamini kiriting: ");
    // Kiritgan qator raqami buyicha matnlarni o'qiydi
    scanf("%d", &qatorRaqami); 

    // Fayllarni ochish
    enter_file = fopen("input.txt", "r");
    if (enter_file == NULL) {
        printf("intput.txt\n");
        return 1;
    }
     // Dasturdagi 2-faylni ham ochib oldik
    close_file = fopen("output.txt", "w");
    if (close_file == NULL) {
        printf("output.txt\n");
        fclose(enter_file);
        return 1;
    }

    // Fayldagi qatorlarni o'qish va nusxalash
    while (fgets(satr, sizeof(satr), enter_file)) {
        if (joriyQator != qatorRaqami) {
            fputs(satr, close_file);
        }
        joriyQator++;  
    }

    // Fayllarni yopish
    fclose(enter_file);
    fclose(close_file);

    printf("Tanlangan qator tashlab ketildi va natija output.txt fayliga yozildi.\n");

    return 0;
}

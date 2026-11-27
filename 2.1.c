#include <stdio.h>
#include <stdlib.h>

void taoTep(const char *filename) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Khong the tao tep!\n");
        return;
    }
    fprintf(f, "12 -7 5 -4 0 19 -22 8 3\n");
    fclose(f);
    printf("1. Da tao tep '%s' thanh cong.\n\n", filename);
}

void docVaInNoiDung(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Khong the mo tep de doc!\n");
        return;
    }
    printf("2. Noi dung cua tep '%s':\n", filename);
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        putchar(ch);
    }
    fclose(f);
    printf("\n");
}

void phanLoaiSo(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Khong the mo tep de phan loai!\n");
        return;
    }

    int numbers[100];
    int count = 0;
    int num;

    while (fscanf(f, "%d", &num) == 1) {
        numbers[count++] = num;
    }
    fclose(f);

    printf("3. Ket qua phan loai cac so trong tep:\n");

    printf("- So nguyen duong: ");
    for (int i = 0; i < count; i++) {
        if (numbers[i] > 0) {
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");

    printf("- So nguyen am: ");
    for (int i = 0; i < count; i++) {
        if (numbers[i] < 0) {
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");

    printf("- So chan: ");
    for (int i = 0; i < count; i++) {
        if (numbers[i] % 2 == 0) {
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");

    printf("- So le: ");
    for (int i = 0; i < count; i++) {
        if (numbers[i] % 2 != 0) {
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");
}

int main() {
    const char *filename = "data.txt";

    taoTep(filename);
    docVaInNoiDung(filename);
    phanLoaiSo(filename);

    return 0;
}

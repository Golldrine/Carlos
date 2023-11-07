#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Jogador {
    char nome[31];
    char posicao;
    int forca;
};

int main() {
    setlocale(LC_ALL, "C");
    char nomeTime1[31];
    char nomeTime2[31];
    struct Jogador time1[11];
    struct Jogador time2[11];
    int forcaTime1 = 0;
    int forcaTime2 = 0;

    fgets(nomeTime1, sizeof(nomeTime1), stdin);
    nomeTime1[strcspn(nomeTime1, "\n")] = '\0';

    for (int i = 0; i < 11; i++) {
        scanf("%30[^;]; %c; %d", time1[i].nome, &time1[i].posicao, &time1[i].forca);
        getchar();

        if (time1[i].posicao == 'G') {
            forcaTime1 += 8 * time1[i].forca;
        } else if (time1[i].posicao == 'L') {
            forcaTime1 += 10 * time1[i].forca;
        } else if (time1[i].posicao == 'Z') {
            forcaTime1 += 5 * time1[i].forca;
        } else if (time1[i].posicao == 'V') {
            forcaTime1 += 8 * time1[i].forca;
        } else if (time1[i].posicao == 'M') {
            forcaTime1 += 11 * time1[i].forca;
        } else if (time1[i].posicao == 'A') {
            forcaTime1 += 12 * time1[i].forca;
        }
    }

    fgets(nomeTime2, sizeof(nomeTime2), stdin);
    nomeTime2[strcspn(nomeTime2, "\n")] = '\0';

    for (int i = 0; i < 11; i++) {
        scanf("%30[^;]; %c; %d", time2[i].nome, &time2[i].posicao, &time2[i].forca);
        getchar();

        if (time2[i].posicao == 'G') {
            forcaTime2 += 8 * time2[i].forca;
        } else if (time2[i].posicao == 'L') {
            forcaTime2 += 10 * time2[i].forca;
        } else if (time2[i].posicao == 'Z') {
            forcaTime2 += 5 * time2[i].forca;
        } else if (time2[i].posicao == 'V') {
            forcaTime2 += 8 * time2[i].forca;
        } else if (time2[i].posicao == 'M') {
            forcaTime2 += 11 * time2[i].forca;
        } else if (time2[i].posicao == 'A') {
            forcaTime2 += 12 * time2[i].forca;
        }
    }

    double forcaPonderadaTime1 = (double)forcaTime1 / 100;
    double forcaPonderadaTime2 = (double)forcaTime2 / 100;

    printf("%s: %.2lf de forca\n", nomeTime1, forcaPonderadaTime1);
    printf("%s: %.2lf de forca\n", nomeTime2, forcaPonderadaTime2);

    if (forcaPonderadaTime1 > forcaPonderadaTime2) {
        printf("%s eh mais forte\n", nomeTime1);
    } else if (forcaPonderadaTime2 > forcaPonderadaTime1) {
        printf("%s eh mais forte\n", nomeTime2);
    } else {
        printf("Os times tem a mesma força\n");
    }

    return 0;
}
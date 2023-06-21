#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[20];
  int hearts;
  int nivel;
} Personagem;

void mostrarPoder(const char *nomePersonagem) {
  if (strcmp(nomePersonagem, "Mago") == 0) {
    printf("Poder: Gelo Frio\n");
  } else if (strcmp(nomePersonagem, "Cavaleiro") == 0) {
    printf("Poder: Espada doida \n");
  }
}

int obterNivel() {
  char input[20];
  int nivel;

  while (1) {
    printf("Digite o nível: ");
    scanf("%s", input);

    int i = 0;
    while (input[i] != '\0') {
      if (!isdigit(input[i])) {
        printf("Digite um caracter numérico.\n");
        break;
      }
      i++;
    }

    if (input[i] == '\0') {
      nivel = atoi(input);
      break;
    }
  }

  return nivel;
}

int main() {
  Personagem personagens[2];

  for (int i = 0; i < 2; i++) {
    if (i == 0) {
      printf("Qual é o nome do Cavaleiro? Digite: ");
    } else {
      printf("Qual é o nome do Mago? Digite: ");
    }
    scanf("%s", personagens[i].nome);

    printf("Digite a quantidade de hearts que seu personagem tem: ");
    scanf("%d", &personagens[i].hearts);

    personagens[i].nivel = obterNivel();

    printf("\n");
  }

  printf("Cavaleiro\n");
  printf("Nome: %s\n", personagens[0].nome);
  printf("Poder: ");
  mostrarPoder(personagens[0].nome);
  printf("Hearts: %d\n", personagens[0].hearts);
  printf("Nível: %d\n", personagens[0].nivel);
  printf("\n");

  printf("Mago\n");
  printf("Nome: %s\n", personagens[1].nome);
  printf("Poder: ");
  mostrarPoder(personagens[1].nome);
  printf("Hearts: %d\n", personagens[1].hearts);
  printf("Nível: %d\n", personagens[1].nivel);
  printf("\n");

  if (personagens[0].nivel > personagens[1].nivel) {
    printf("O Cavaleiro é mais forte, hihi!\n");
  } else if (personagens[1].nivel > personagens[0].nivel) {
    printf("O Mago é mais forte, cuidado ein?!\n");
  } else {
    printf("O Cavaleiro e o Mago têm a mesma força, qualquer um ta bom!\n");
  }

  return 0;
}

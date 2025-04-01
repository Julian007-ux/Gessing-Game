#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{	
	int	i;
	int	trying_num;
	int	secret_num;
	int	user_num;
	int	upper;
	int	lower;
	int	win;
	int	level;
	double	points;
	double	loose_pointes;


	srand(time(0)); //Retorna a data actual e define uma nova semente para a função rand();
	points = 1000;
	i = 0;
	loose_pointes = 0;
	secret_num = rand() % 100; //Retorna um número aleatório no intervalo de 0 - 99;
	printf("Informe a dificuldade: \n");
	printf("(1)-Fácil (2)-Médio (3)-Difícil: ");
	scanf("%d", &level);
	switch(level){
		case 1:
			trying_num = 20;
			break;
		case 2:
			trying_num = 15;
			break;
		case 3:
			trying_num = 6;
			break;
		default:
			printf("\n");
			printf("Valor inválido\n");
			break;
	}
	while(i != trying_num){
		i++;
		
		system("clear");
		printf("\n\n");
		printf("       P /_\\ P	\n");
		printf("     /_\\_|_|_/_\\	\n");
		printf("  n_n | ||. .|| | n_n		Bem-vindo ao	\n");
		printf("  |_|_|nnnn nnnn|_|_|		Jogo de Adivinhação! \n");
		printf("   |\" \" | |_| |\" \" |					\n");
		printf(" |_____| ' _ ' |_____|					\n");
		printf("       \\__|_|__/						\n");
		printf("\n\n");
		printf("Tentativa %d de %d\n", i, trying_num);
		printf("Qual é o teu palpite?: ");
		scanf("%d", &user_num);
		
		if(user_num < 0){
			system("clear");
			printf("Números negativos não são permitidos!, prima ENTER para continuar\n");
			getchar();
			i--;
			continue;
		}

		upper = user_num > secret_num;
		lower = user_num < secret_num;
		win = user_num == secret_num;
		

		if(win){
			system("clear");
			printf("              OOOOOOOOOOO               \n");
			printf("          OOOOOOOOOOOOOOOOOOO           \n");
			printf("       OOOOOO  OOOOOOOOO  OOOOOO        \n");
			printf("     OOOOOO      OOOOO      OOOOOO      \n");
			printf("    OOOOOOOO  #   OOOOO   #  OOOOOOOO   \n");
			printf("  OOOOOOOOOO     OOOOOOO     OOOOOOOOOO \n");
			printf(" OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
			printf(" OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
			printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
			printf("  OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
			printf("   OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
			printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO      \n");
			printf("     OOOOOO    OOOOOOOOO   OOOOOO       \n");
			printf("      OOOOOO              OOOOOO        \n");
			printf("          OOOOOOOOOOOOOOOOO  			\n");
			printf("Parabéns você Ganhou!!!	\n");
			break;
		}else{
			system("clear");
			if(upper){
				printf("Errou, tente um número menor\n");
			} else if(lower){
				printf("Errou, tente um número maior\n");
			}
			loose_pointes += abs(user_num - secret_num) / 2.0; // calcula o número de pontos perdidos, converte para float e retorna uma número positivo;

			printf("          \\|/ ____ \\|/          \n");
			printf("           @~/ ,. \\~@            \n");
			printf("          /_( \\__/ )_\\          \n");
			printf("             \\__U_/              \n");
			printf("Aguarde 5 segundos...\n");
			printf("Pontos perdidos: %.2f\n", loose_pointes);
			system("sleep 5");
		}
	}
	points -= loose_pointes;
	if(!win)
		printf("O número secreto é: %d\n", secret_num);
	if(win)
		printf("Você teve %.2f pontos\n", points);
	printf("Fim do Jogo!!!\n");
}

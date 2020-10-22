#include <stdio.h>
#include <string.h>
#include <assert.h>

/**
 * @brief CALCULE DE PUISSANCE
 * 
 * @param number 
 * @param puissance 
 * @return int 
 */
int puissance(int number, int puissance)
{
	int result = number;
	if (puissance > 0)
	{
		int i = 1;
		while (i != puissance)
		{
			result *= number;
			i++;
		}
	}
	else
	{
		result = 1;
	}
	return result;
}

/**
 * @brief La fonction getSize retourne la taille d'une chaine de caractere
 * 
 * @param val 
 * @return int 
 */
int getSize(char *val) {
	int size = 0;
	while (val[size] != '\0') {
		size++;
	}
	return size;
}

char* strrev(char *str) {
	char *p1, *p2;

	if (!str || !*str)
		return str;
	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	return str;
}

/**
 * @brief CONVERSION BINAIRE VERS DECIMALE
 * 
 * @param val 
 * @return int 
 */
int bintodec(char *val)
{
	int result = 0;
	int taille = strlen(val) - 1;
	int j = 0;
	for (int i = taille; i > -1; i--)
	{
		if (val[i] == '1')
		{
			result += puissance(2, j);
		}
		j++;
	}
	return result;
}

/**
 * @brief CONVERSION HEXADECIMALE VERS DECIMALE
 * 
 * @param val 
 * @return int 
 */
int hexatodec(char *val)
{
	char hexa[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	int result = 0;
	int i = strlen(val) - 1;
	int j = 0;
	int k = 0;

	while (i != -1)
	{
		for (j = 0; j <= 15; j++)
		{
			if (hexa[j] == val[i])
			{
				result += (j * (puissance(16, k)));
				k++;
			}
		}
		i--;
	}
	return result;
}

/**
 * @brief CONVERSION DECIMALE VERS HEXADECIMALE
 * 
 * @param val 
 * @return char* 
 */
char *dectohexa(unsigned int val)
{
	int reste;
	int j = 0;
	char hexa[100];

	while (val != 0)
	{
		reste = val % 16;
		if (reste < 10)
		{
			hexa[j] = 48 + reste;
		}
		else
		{
			hexa[j] = 55 + reste;
		}
		val /= 16;
		j++;
	}
	char *finish = hexa;
	return finish;
}

/**
 * @brief CONVERSION DECIMALE VERS BINAIRE AVEC SOUSTRACTION
 * 
 * @param val 
 * @return char* 
 */
char *dectobin_v1(unsigned int val)
{
	char result[8];
	for (int i = 0; i < sizeof(result); i++) {
		result[i] = '0';
	}
	while (val > 0) {
		double k = 0;
		while (val > puissance(2, k)) {
			k++;
		}
		if (val - puissance(2, k) != 0) {
			val = val - puissance(2, k - 1);
			result[(int) k - 1] = '1';
		} else {
			val = val - puissance(2, k);
			result[(int) k] = '1';
		}
	}
	char *finish = strrev(result);
	return finish;
}

/**
 * @brief CONVERSION DECIMALE VERS BINAIRE AVEC DIVISION
 * 
 * @param val 
 * @return char* 
 */
char *dectobin_v2(unsigned int val)
{
	char result[100];
	int i = 0;
	while (val != 0)
	{
		if (val % 2 == 0)
		{
			result[i] = '0';
		}
		else
		{
			result[i] = '1';
		}
		val /= 2;
		i++;
	}
	
	char *finish = strrev(result);
	return finish;
}

/**
 * @brief CONVERSION DECIMALE VERS BINAIRE AVEC DECALAGE DE BIT
 * 
 * @param val 
 * @return char* 
 */
char *dectobin_v3(unsigned int val)
{
	char result[100];
	int i = 0;
	while (val != 0)
	{
		if (val % 2 == 0)
		{
			result[i] = '0';
		}
		else
		{
			result[i] = '1';
		}
		val >>= 1;
		i++;
	}
	char *finish = strrev(result);
	return finish;
}

/**
 * @brief CONVERSION DECIMALE VERS HEXADECIMALE AVEC DECALAGE DE BIT
 * 
 * @param val 
 * @return char* 
 */
char *dectohexa_v2(unsigned int val)
{
	int reste;
	int i = 0;
	char hexa[100];

	while (val != 0)
	{
		reste = val % 16;
		if (reste < 10)
		{
			hexa[i] = 48 + reste;
		}
		else
		{
			hexa[i] = 55 + reste;
		}
		val >>= 4;
		i++;
	}
	char *finish = strrev(hexa);
	return finish;
}

int main()
{
	// #####BINNAIRE VERS DECIMALE#####
	//printf("Résultat %d", bintodec("1110"));
	//assert(bintodec("1110") == 14);

	// #####HEXADECIMALE VERS DECIMALE#####
	//printf("Résultat %d", hexatodec("AE3"));
	//assert(hexatodec("AE3") == 2787);

	// #####DECIMALE VERS HEXADECIMALE#####
	//printf("Résultat %s", dectohexa(12));
	//assert(strcmp("C", dectohexa(12)) == 0);

	// #####DECIMALE VERS BINAIRE AVEC SOUSTRACTION#####
	//printf("Résultat %s", dectobin_v1(14));
	//assert(strcmp("00001110", dectobin_v1(14)) == 0);

	// #####DECIMALE VERS BINAIRE AVEC DIVISION#####
	//printf("Résultat %s", dectobin_v2(14));
	//assert(strcmp("1110", dectobin_v2(14)) == 0);

	// #####DECIMALE VERS BINAIRE AVEC DECALAGE ET OPERATEUR BIT A BIT
	//printf("Résultat %s", dectobin_v3(14));
	//assert(strcmp("1110", dectobin_v3(14)) == 0);

	//#####DECIMALE VERS HEXA AVEC DECALAGE ET OPERATEUR BIT A BIT
	//printf("Résultat %s", dectohexa_v2(2787));
	//assert(strcmp("AE3", dectohexa_v2(2787)) == 0);
}
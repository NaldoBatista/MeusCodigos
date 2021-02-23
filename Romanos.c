# include <stdio.h>
# include <string.h>

int algarismoInt(char c) {
	int num;
	switch(c) {
		case 'I':
			num = 1;
			break;
		case 'V':
			num = 5;
			break;
		case 'X':
			num = 10;
			break;
		case 'L':
			num = 50;
			break;
		case 'C':
			num = 100;
			break;
		case 'D':
			num = 500;
			break;
		case 'M':
			num = 1000;
			break;
	}
	return num;
}


int converteRomano(char str[]) {
	int conta = 0;
	for(int i=0; i< strlen(str); i++) {
		if(algarismoInt(str[i]) >= algarismoInt(str[i+1])) {
			conta += algarismoInt(str[i]);
		}
		else if(algarismoInt(str[i]) < algarismoInt(str[i+1])) {
			conta += algarismoInt(str[i+1]) - algarismoInt(str[i]);
			i++;
		}
		else {
			conta += algarismoInt(str[i]);
		}
	}
	printf("O numero romano %s no sistema decimal e: %d", str, conta);
	return conta;
}

int main() {
	
	char numeroRomano[10];
	scanf("%s", numeroRomano);
	
	converteRomano(numeroRomano);
}

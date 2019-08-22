#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int auxEmail(char);
#pragma clang diagnostic ignored "-Wtautological-constant-out-of-range-compare"
int valDec(char* c){
	int len = strlen(c) - 1, count = 0;
	for (len = strlen(c) - 1; len >= 0; --len) {
		if (((c[len] >= '0' && c[len] <='9') == 0) && (c[len] != ',' && c[len] != '.')) {
			return 0;
		} else if (c[len] == ',' || c[len] == '.') {
			c[len] = '.';
			++count;
		} if (count > 1) {
				return 0;
			}
	}
		if ((len == 0) && count == 0) {
			return 0;
		}
	return 1;
}

int valDecInt(char* c) {
	int len = (strlen(c) - 1);
	for (len = strlen(c) - 1; len >= 0; --len) {
		if (((c[len] >= '0' && c[len] <= '9') == 0)) {
			return 0;
		}
	}
	return 1;
}

int valDecPf(char* c) {
	int len = strlen(c) - 1, count = 0;
	for (len = strlen(c) - 1; len >= 0; --len) {
		if (((c[len] >= '0' && c[len] <='9') == 0) && (c[len] != ',' && c[len] != '.')) {
			return 0;
		} else if (c[len] == ',' || c[len] == '.') {
			c[len] = '.';
			++count;
			if (count > 1) {
				return 0;
			}
		}
	}
		if ((len == 0) && count == 0) {
			return 0;
		}
	return 1;
}


int valISN(char *c) {
	int len = strlen(c) -1;
	int valid = 0;
	int peso = 1;
	int i,j,alt = 1;
	if(len != 7 && len != 9 && len != 12) {
		return 0;
	}
	for(j = len;j >= 0;--j) {
		if(((c[j] >= '0' && c[j] <='9') || c[j] == 'x' || c[j] == 'X') == 0) {
			return 0;
		}
	}

	if(len == 7) {
		for(i = 0,j = 8;i < len;++i,--j) {
			printf("\nvalid = %d * %d",(c[i]-48),j);
			valid += ( (c[i]-48) * j);
		}
		valid = valid%11;
		if(valid != 0){
			valid = 11 - valid;
		}
		printf("valid = %d",valid);
	} else if(len == 9) {
		for(i = 0;i < len;++i,++j) {
			valid += ( (c[i]-48) *j);
		}
		valid = valid%11;
	} else if(len == 12) {
		for(i = 0;i < len;++i) { 
			if(alt%2 == 0) {
				peso = 2;
				alt = 3;
			} else {
					peso = 1;
					alt = 1;
			}
			valid += ( (c[i]-48) * alt);
			alt += peso;
		}
		valid = ((valid%10)-10)*-1;
	}	
	int out = 0;
	if((c[strlen(c)-1]-48) >= 0 && (c[strlen(c)-1]-48) <= 9) {
		out = (c[strlen(c)-1]-48);
	} else if ((c[strlen(c)-1]) == 'x' || (c[strlen(c)-1]) == 'X') {
		out = 10;
	}
	if(valid == out) {
		return 1;
	} else {
		return 0;
	}
} 


int valCPF(char *c) {
	int len = strlen(c);
	if(len < 11) {
		return 0;
	}
	
	int j, i = 0,d1 = 0,d2 = 0;
	for(j = len-1;j >= 2;--j) {
		if((c[i] >= '0' && c[i] <= '9') == 0){
			return 0;
		}
		d1 += (c[i]-48)*j;
		d2 += ((c[i]-48)*(j+1));
		++i;
	}
	d1 = (d1%11) < 2 ? 0 : 11-(d1%11);
	d2 += (c[9]-48)*2;
	d2 = 11-(d2%11);
	if(d1 != (c[9]-48) && d2 != (c[10]-48)) {
		return 0;
	} else {
		return 1;
	}
}

int valCEP(char* c) {
	int len = strlen(c) - 1;
	if(len != 8){
		return 0;
	}
	for (len = strlen(c) - 1; len >= 0; --len) {
		if (((c[len] >= '0' && c[len] <= '9') || c[len] != '-') == 0) {
			return 0;
		}
	}
	return 1;
}

int valRua(char *c) {
	int len = strlen(c) -1, count1 = 0, count2 = 0;
	for (len = strlen(c) - 1;len >= 0;--len) {
		if(c[len] == 32) {
			++count1;
		} if ((c[len] >= 65 && c[len] <= 90) || (c[len] >= 97 && c[len] <= 122)) {
			++count2;
		}
	}
	if(count1 == 0 || count2 == 0) {
		return 0;
	}
	return 1;
}

int valAlpha(char* c) {
	for (int len = (strlen(c) - 1); len >= 0; --len) {
		if ( ((c[len] != 32) || (c[len] >= 65 && c[len] <= 90) || (c[len] >= 97 && c[len] <= 122) || (c[len] >= 128 && c[len] <= 163) ) == 0) {
			return 0;
		}
	}
	return 1;
}

int valName(char* c) {
	int count = 0;
	for (int len = (strlen(c) - 1); len >= 0; --len) {
		if (( (c[len] != 32) || (c[len] >= 65 && c[len] <= 90) || (c[len] >= 97 && c[len] <= 122) || (c[len] >= 128 && c[len] <= 163) || (c[len] == 32)) == 0) {
			return 0;
		} if (c[len] == 32) {
			++count;
		}
	}
	if(count == 0) {
		return 0;
	}
	return 1;
}

int valAlphaNum(char* c) {
	for (int len = (strlen(c) - 1); len >= 0; --len) {
		if (c[len] >= '0' && c[len] <= '9') {
			continue;
		} else	if (c[len] >= 65 && c[len] <= 90) {
			continue;
		} else	if  ((c[len] >= 97 && c[len] <= 122) || (c[len] >= 128 && c[len] <= 163)) {
				continue;
		} else {
			return 0;
		}
	}
	return 1;
}


int valEmail(char* c) {
	int local = 0;
	int temp = 0;
	for(int i = 0;i <= strlen(c) - 1;++i) {
		if(c[i] == 64) {
			local = i - 1;
			break;
		} else if(c[i] == ' ') {
			return 0;
		}
	}
	if(local > 64) {
		return 0;
	}
	int domain = local + 2;
	if(domain < 3) {
		return 0;
	}
	for(int i = strlen(c);i <= domain;--i) {
		++temp;
		}
	if (temp > 63) {
		return 0;
	}
	for(int i = local; i >= 0; --i) {
		if ((c[i] >= '0' && c[i] <= '9') == 0) {
			if ((c[i] >= 65 && c[i] <= 90) == 0) {
				if ((c[i] >= 97 && c[i] <= 122) == 0) {
					if (c[i] != '.'  && c[i] != '!' && c[i] != '#' && c[i] != '$' && c[i] != '%' && c[i] != '&' && c[i] != 39 && c[i] != '*' && c[i] != '+' && c[i] != '-' && c[i] != '/' && c[i] != '=' && c[i] != '?' && c[i] != '^' && c[i] != '_' && c[i] != '`' && c[i] != '{' && c[i] != '|' && c[i] != '}' && c[i] != 126 && c[i] != 32) {
						return 0;
					}
				}
			}
		}
	}
	if(auxEmail(c[temp]) == 0) {
		return 0;
	}
	for(int i = domain; i >= 0; --i) {
		if ((c[i] >= '0' && c[i] <= '9') == 0) {
			if ((c[i] >= 65 && c[i] <= 90) == 0) {
				if ((c[i] >= 97 && c[i] <= 122) == 0) {
					if ( (c[i] != '.'  && c[i] != '!' && c[i] != '#' && c[i] != '$' && c[i] != '%' && c[i] != '&' && c[i] != 39 && c[i] != '*' && c[i] != '+' && c[i] != '-' && c[i] != '/' && c[i] != '=' && c[i] != '?' && c[i] != '^' && c[i] != '_' && c[i] != '`' && c[i] != '{' && c[i] != '|' && c[i] != '}' && c[i] != 126 ) == 0) {
						return 0;
					}
				}
			}
		}
	}
	return 1;
}


int auxEmail(char c) {
	if ((c >= '0' && c <= '9') == 0) {
		if ((c >= 65 && c <= 90) == 0) {
			if ((c >= 97 && c <= 122) == 0) {
				return 0;
			}
		}
	}
	return 1;
}

int valKeyA(char* c) {
	int countAlphaU = 0;
	int countAlphaD = 0;
	int countNum = 0;
	int countSymbol = 0;
	if(strlen(c) < 8 ){
		return 0;
	}
	for (int len = strlen(c); len >= 0; --len) {
		if (c[len] >= '0' && c[len] <= '9') {
			++countNum;
		} else if (c[len] >= 'a' && c[len] <='z') {
			++countAlphaD;
		} else if (c[len] >= 'A' && c[len] <='Z') {
				++countAlphaU;
		} else if ( (c[len] >= 33 && c[len] <= 63) || (c[len] >= 123 && c[len] <= 153) ){
			++countSymbol;
		}
	}
	if (countAlphaU == 0 || countAlphaD == 0 || countNum == 0|| countSymbol == 0) {
		return 0;
	}
	return 1;
}

int validaData(char* c) {
    short i;
    if(c[2] != '/' || c[5] != '/' || (c[1] == '0' && c[0] == '0')) {
		return 0;
	}
    for(i = 9; i >= 0 ; --i) {
		if( ((c[i] >= '0' && c[i] <= '9') || (c[i] == '/')) == 0) {
			return 0;
		}
	}

	char year[4] ="";
	//Tamanho de 'c' e posição dos caracteres: |d?|d¹|/²|m³|m?|/?|y?|y?|y?|y?|
											//  0  1  2  3  4  5  6  7  8  9
	//Dia: c[0],c[1];
	//mes = c[3],c[4];
	//ano = c[6],c[7],c[8],c[9];
	strcat(year,&c[6]);

	if ((c[3] < '1' && c[4] >= '1') ^ (c[3] == '1' && c[4] <= '2')) {
		if (((c[0] <= '3' && c[1] <= '9') ^ (c[0] == '3' && c[1] <= '1')) && ((c[3] == '0' && c[4] == '1') || (c[3] == '0' && c[4] == '3') || (c[3] == '0' && c[4] == '5') || (c[3] == '0' && c[4] == '7') || (c[3] == '0' && c[4] == '8') || (c[3] == '1' && c[4] == '0') || (c[3] == '1' && c[4] == '2'))) {
		} else if (((c[0] <= '3' && c[1] <= '9') ^ (c[0] == '3' && c[1] <= '1')) && ((c[3] == '0' && c[4] == '4') || (c[3] == '0' && c[4] == '6') || (c[3] == '0' && c[4] == '9') || (c[3] == '1' && c[4] == '1'))) {
			return 1;
		} else if ((c[0] <= '2' && c[1] <= '8') && (c[3] == '0' && c[4] == '2')) {
			return 1;
		} else if (((c[0] == '2' && c[1] == '9') && (c[3] == '0' && c[4] == '2')) && (atoi(year) % 400 == 0 || ((atoi(year) % 4 == 0 && atoi(year)) % 100 != 0))) {
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;    
    }
    return 1;
}
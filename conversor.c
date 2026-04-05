#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int bin_to_dec(char numero[100], char resultado_pointer[100])
{
    int digito = 1, digito_resultado = 0, quantia_digitos = 1, expoente = 0, indice = 0, caractere = 0, i = 0;
    unsigned long long int resultado_int = 0;

    while(numero[quantia_digitos] != '\0') quantia_digitos += 1;

    while(expoente != quantia_digitos)
    {
        digito = numero[quantia_digitos - (expoente + 1)];

        if(digito >= 48 && digito <= 49) digito -= 48;
        else return 0;

        resultado_int += digito * pow(2, expoente);

        expoente += 1;
    }

    expoente = 0, quantia_digitos = 0;
    
    quantia_digitos = floor(log10(resultado_int) + 1);

    while (expoente != (quantia_digitos))
    {
        resultado_pointer[expoente] = 'X';

        expoente += 1;
    }

    expoente = 0;

    while(expoente != quantia_digitos)
    {
        digito_resultado = resultado_int %10;
        digito_resultado += 48; 

        resultado_pointer[quantia_digitos - (expoente+1)] = digito_resultado;

        expoente += 1;
        resultado_int /= 10;
    }
    return 1;
}

int oct_to_dec(char numero[100], char resultado_pointer[100])
{
    int digito = 1, digito_resultado = 0, quantia_digitos = 1, expoente = 0, indice = 0, caractere = 0, i = 0;
    unsigned long long int resultado_int = 0;

    while(numero[quantia_digitos] != '\0') quantia_digitos += 1;

    while(expoente != quantia_digitos)
    {
        digito = numero[quantia_digitos - (expoente + 1)];

        if(digito >= 48 && digito <= 56) digito -= 48;
        else return 0;

        resultado_int += digito * pow(8, expoente);

        expoente += 1;
    }

    expoente = 0, quantia_digitos = 0;
    
    quantia_digitos = floor(log10(resultado_int) + 1);

    while (expoente != (quantia_digitos))
    {
        resultado_pointer[expoente] = 'X';

        expoente += 1;
    }

    expoente = 0;

    while(expoente != quantia_digitos)
    {
        digito_resultado = resultado_int %10;
        digito_resultado += 48; 

        resultado_pointer[quantia_digitos - (expoente+1)] = digito_resultado;

        expoente += 1;
        resultado_int /= 10;
    }
    return 1;
}

int hex_to_dec(char numero[100], char resultado_pointer[100])
{
    int digito = 1, digito_resultado = 0, quantia_digitos = 1, expoente = 0, indice = 0, caractere = 0, i = 0;
    unsigned long long int resultado_int = 0;

    while(numero[quantia_digitos] != '\0') quantia_digitos += 1;

    while(expoente != quantia_digitos)
    {
        digito = numero[quantia_digitos - (expoente + 1)];

        if(digito >= 97 && digito <= 102) digito -= 87; 
        else if(digito >= 48 && digito <= 58) digito -= 48;
        else return 0;

        resultado_int += digito * pow(16, expoente);

        expoente += 1;
    }

    expoente = 0, quantia_digitos = 0;
    
    quantia_digitos = floor(log10(resultado_int) + 1);

    while (expoente != (quantia_digitos))
    {
        resultado_pointer[expoente] = 'X';

        expoente += 1;
    }

    expoente = 0;

    while(expoente != quantia_digitos)
    {
        digito_resultado = resultado_int %10;
        digito_resultado += 48; 

        resultado_pointer[quantia_digitos - (expoente + 1)] = digito_resultado;

        expoente += 1;
        resultado_int /= 10;
    }
    return 1;
}

void dec_to_bin(char resultado_pointer[100], char resultado_final[100])
{
    unsigned long long int numero_int = 0, resultado_int = 0;
    int quantia_digitos = 1, expoente = 0, digito = 0, digito_resultado = 0;

    while(resultado_pointer[quantia_digitos] != '\0') quantia_digitos += 1;

    while (expoente != quantia_digitos)
    {
        digito = resultado_pointer[quantia_digitos - (expoente + 1)];

        if(digito >= 48 && digito <= 58) digito -= 48;

        numero_int += digito * pow(10, expoente);

        expoente += 1;
    }

    expoente = 0;

    while (numero_int != 0)
    {
        resultado_int += numero_int %2 * pow(10, expoente);

        expoente += 1;
        numero_int /= 2;
    }
    printf("\nresultado: %llu\n\n\n", resultado_int);
}

void dec_to_oct(char resultado_pointer[100], char resultado_final[100])
{
    unsigned long long int numero_int = 0, resultado_int = 0;
    int quantia_digitos = 1, expoente = 0, digito = 0, digito_resultado = 0;

    while(resultado_pointer[quantia_digitos] != '\0') quantia_digitos += 1;

    while (expoente != quantia_digitos)
    {
        digito = resultado_pointer[quantia_digitos - (expoente + 1)];

        if(digito >= 48 && digito <= 58) digito -= 48;

        numero_int += digito * pow(10, expoente);

        expoente += 1;
    }

    expoente = 0;

    while (numero_int != 0)
    {
        resultado_int += numero_int %8 * pow(10, expoente);

        expoente += 1;
        numero_int /= 8;
    }
    printf("\nresultado: %llu\n\n\n", resultado_int);
}

void dec_to_hex(char resultado_pointer[100], char resultado_final[100], char resultado_final_inverso[100])
{
    
    unsigned long long int numero_int = 0, resultado_int = 0;
    int quantia_digitos = 1, expoente = 0, digito = 0, digito_resultado = 0, digito_final = 0;

    while (resultado_pointer[quantia_digitos] != '\0') quantia_digitos += 1;

    while (expoente != quantia_digitos)
    {
        digito = resultado_pointer[quantia_digitos - (expoente + 1)];

        if (digito >= 48 && digito <= 58) digito -= 48;

        numero_int += digito * pow(10, expoente);

        expoente += 1;
    }

    expoente = 0;

    while (numero_int != 0)
    {
        resultado_int = numero_int %16;

        if (resultado_int >= 10) resultado_final[expoente] = (resultado_int + 87);
        else resultado_final[expoente] = (resultado_int + 48);

        expoente += 1;
        numero_int /= 16;
    }

    expoente = 0, quantia_digitos = 0;

    while (resultado_final[quantia_digitos] != '\0') quantia_digitos += 1;

    while (expoente != (quantia_digitos))
    {
        resultado_final_inverso[expoente] = resultado_final[quantia_digitos - (expoente + 1)];

        expoente += 1;
    }

    printf("\nresultado: %s\n\n\n", resultado_final_inverso);
}

int case_dec(char numero[100], char resultado_pointer[100])
{
    int quantia_digitos = 0, expoente = 0, digito = 0;

    while (numero[quantia_digitos] != '\0') quantia_digitos += 1;

    while (expoente != quantia_digitos)
    {
        digito = numero[quantia_digitos - (expoente + 1)];

        if (digito >= 48 && digito <= 58) digito -= 48;
        else return 0;

        expoente += 1;
    }

    expoente = 0;

    while (expoente != (quantia_digitos))
    {
        resultado_pointer[expoente] = numero[expoente];

        expoente += 1;
    }
}






int main()
{
    printf("\n\n||=============================||\n");
    printf("||==========conversor==========||\n");
    printf("||===========de=base===========||\n");
    printf("||=============================||\n");

    char numero[100] = {0}, resultado_pointer[100] = {0}, resultado_final[100] = {0}, resultado_final_inverso[100] = {0};
    int base_de_entrada = 0, base_de_saida = 0;
    unsigned long long int resultado_int = 0;

    printf("\n\nqual base vai digitar? [ 2 | 8 | 10 | 16 ] ");
    scanf("%d", &base_de_entrada);
    printf("base selecionada: %d", base_de_entrada);

    printf("\n\npara qual base vai converter? [ 2 | 8 | 10 | 16 ] ");
    scanf("%d", &base_de_saida);
    printf("base selecionada: %d", base_de_saida);

    printf("\n\nqual numero? ");
    scanf("%s", &numero);
    printf("numero escollhido: %s\n", numero);

    switch(base_de_entrada)
    {
        case 2:
        {
            if(!bin_to_dec(numero, resultado_pointer))
            {
                printf("\n||=======numero=invalido=======||\n\n\n");
                printf("digite qualquer tecla para finalizar o progama... ");
                scanf("%s");
                return -1;
            }
            switch(base_de_saida)
            {
                case 8:
                {
                    dec_to_oct(resultado_pointer, resultado_final);
                    break;
                }

                case 10:
                {
                    printf("\nresultado: %s\n\n\n", resultado_pointer);
                    break;
                }

                case 16:
                {
                    dec_to_hex(resultado_pointer, resultado_final, resultado_final_inverso);
                    break;
                }
            }
            break;
        }

        case 8:
        {
            if(!oct_to_dec(numero, resultado_pointer))
            {
                printf("\n||=======numero=invalido=======||\n\n\n");
                printf("digite qualquer tecla para finalizar o progama... ");
                scanf("%s");
                return -1;
            }
            switch(base_de_saida)
            {
                case 2:
                {
                    dec_to_bin(resultado_pointer, resultado_final);
                    break;
                }

                case 10:
                {
                    printf("\nresultado: %s\n\n\n", resultado_pointer);
                    break;
                }

                case 16:
                {
                    dec_to_hex(resultado_pointer, resultado_final, resultado_final_inverso);
                    break;
                }
            }
            break;
        }

        case 10:
        {
            if(!case_dec(numero, resultado_pointer))
            {
                printf("\n||=======numero=invalido=======||\n\n\n");
                printf("digite qualquer tecla para finalizar o progama... ");
                scanf("%s");
                return -1;
            }
            switch(base_de_saida)
            {
                case 8:
                {
                    dec_to_oct(resultado_pointer, resultado_final);
                    break;
                }

                case 2:
                {
                    dec_to_bin(resultado_pointer, resultado_final);
                    break;
                }

                case 16:
                {
                    dec_to_hex(resultado_pointer, resultado_final, resultado_final_inverso);
                    break;
                }
            }
            break;
        }

        case 16:
        {
            if(!hex_to_dec(numero, resultado_pointer))
            {
                printf("\n||=======numero=invalido=======||\n\n\n");
                printf("digite qualquer tecla para finalizar o progama... ");
                scanf("%s");
                return -1;
            }
            else hex_to_dec(numero, resultado_pointer);

            switch(base_de_saida)
            {
                case 8:
                {
                    dec_to_oct(resultado_pointer, resultado_final);
                    break;
                }

                case 10:
                {
                    printf("\nresultado: %s\n\n\n", resultado_pointer);
                    break;
                }

                case 2:
                {
                    dec_to_bin(resultado_pointer, resultado_final);
                    break;
                }
            }
            break;
        }
        break;
    }
    printf("digite qualquer tecla para finalizar o progama... ");
    scanf("%s");
    return 1;
}
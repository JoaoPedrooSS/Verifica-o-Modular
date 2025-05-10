#include <stdio.h>
#include <stdlib.h>

// Funcao para verificar se um número e primo
int eh_primo(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

// Funcao para calcular o MDC usando o algoritmo de Euclides
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Funcao para calcular o inverso modular usando o algoritmo estendido de Euclides
int inverso_modular(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    
    if (m == 1) return 0;
    
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    
    if (x1 < 0) x1 += m0;
    
    return x1;
}

// Funcao para calcular a funcao totiente de Euler
int euler(int n) {
    int resultado = n;
    
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            resultado -= resultado / p;
        }
    }
    
    if (n > 1) {
        resultado -= resultado / n;
    }
    
    return resultado;
}

// Funcao para calcular a^b mod m
int exp_mod(int base, int exp, int mod) {
    int resultado = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            resultado = (resultado * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    
    return resultado;
}

int main() {
    int H, G, n, x, n1;
    
    printf("=== Programa de Verificacao Modular ===\n");
    printf("Aluno: Joao pedro Silva Sousa - 222006258\n");
    printf("Digite os valores de entrada:\n");
    printf("H: "); scanf("%d", &H);
    printf("G: "); scanf("%d", &G);
    printf("n: "); scanf("%d", &n);
    printf("x (expoente): "); scanf("%d", &x);
    printf("n1 (modulo final): "); scanf("%d", &n1);
    
    printf("\n=== ETAPA 1: Verificar se G e n sao coprimos ===\n");
    int gcd_gn = mdc(G, n);
    if (gcd_gn != 1) {
        printf("G (%d) e n (%d) nao sao coprimos (MDC = %d). Divisao modular nao e possivel.\n", G, n, gcd_gn);
        return 1;
    }
    printf("G (%d) e n (%d) sao coprimos (MDC = 1). Divisao modular e possivel.\n", G, n);
    
    printf("\n=== ETAPA 2: Calcular o inverso de G em Zn ===\n");
    int inv_G = inverso_modular(G, n);
    printf("O inverso de G (%d) em Z%d e: %d\n", G, n, inv_G);
    
    printf("\n=== ETAPA 3: Calcular a = H * G^(-1) mod n ===\n");
    int a = (H * inv_G) % n;
    printf("a = %d\n", a);
    
    printf("\n=== ETAPA 4: Verificar se a e n1 sao coprimos ===\n");
    int gcd_an1 = mdc(a, n1);
    if (gcd_an1 != 1) {
        printf("a (%d) e n1 (%d) nao sao coprimos (MDC = %d).\n", a, n1, gcd_an1);
        return 0;
    } else {
        printf("a (%d) e n1 (%d) sao coprimos (MDC = 1).\n", a, n1);
    }
    
    printf("\n=== ETAPA 5: Verificar se n1 e primo ===\n");
    int primo = eh_primo(n1);
    if (primo) {
        printf("n1 (%d) e primo.\n", n1);
    } else {
        printf("n1 (%d) nao e primo.\n", n1);
    }
    
    printf("\n=== ETAPA 6/7: Ajustar o expoente ===\n");
    int novo_x;
    if (primo) {
        novo_x = n1 - 1;
        printf("Aplicando Pequeno Teorema de Fermat: x = %d - 1, x = %d\n", n1, novo_x);
    } else {
        int phi = euler(n1);
        novo_x = phi;
        printf("Aplicando Teorema de Euler: x = f(n1) = %d\n", novo_x);
    }
    
    printf("\n=== ETAPA 8: Decompor o expoente x ===\n");
    int q, r, x1;
    q = novo_x;
    r = ((x % novo_x) + novo_x) % novo_x;
    x1 = x / novo_x;

    printf("x = x1*q + r => %d = %d*%d + %d\n", x, x1, q, r);
    
    printf("\n=== ETAPA 9/10: Calcular os valores intermediarios ===\n");
    int a_x1 = exp_mod(a, x1, n1);
    printf("a^x1 mod n1 = %d^%d mod %d = %d\n", a, x1, n1, a_x1);
    
    int a_x1_q = exp_mod(a_x1, q, n1);
    printf("(a^x1)^q mod n1 = %d^%d mod %d = %d\n", a_x1, q, n1, a_x1_q);
    
    int a_r = exp_mod(a, r, n1);
    printf("a^r mod n1 = %d^%d mod %d = %d\n", a, r, n1, a_r);
    
    printf("\n=== ETAPA 11: Combinar os resultados ===\n");
    int resultado = (a_x1_q * a_r) % n1;
    printf("Resultado final: ((%d) * (%d)) mod %d = %d\n", a_x1_q, a_r, n1, resultado);
    
    printf("\n=== RESULTADO FINAL ===\n");
    printf("%d^%d mod %d === %d\n", a, x, n1, resultado);
    
    return 0;
}
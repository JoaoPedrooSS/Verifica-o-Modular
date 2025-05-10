# Verificação Modular — Matemática Discreta II (UnB Gama)

Este projeto implementa um verificador modular em linguagem C, desenvolvido como parte da Avaliação P1 da disciplina **Matemática Discreta II** (T03) da Universidade de Brasília — FGA.

Nome: João Pedro Silva Sousa
matrícula: 222006258

O programa realiza operações modulares envolvendo:

- Cálculo de inverso modular
- Verificação de coprimalidade
- Primalidade
- Aplicação do Teorema de Fermat e Teorema de Euler
- Exponenciação modular eficiente
- Etapas detalhadas e explicativas para acompanhamento matemático

---

## 🧮 Entradas do programa

O programa solicita os seguintes valores:

- `H`: numerador da divisão modular
- `G`: denominador da divisão modular
- `n`: módulo para o cálculo da divisão H ⊘ G em Zₙ
- `x`: expoente
- `n1`: módulo final da exponenciação

O objetivo é calcular:  
a = H * G⁻¹ mod n <br>
Resultado final: a^x mod n1


---

## ▶️ Como compilar e executar

### ✅ Requisitos
- Compilador C (como `gcc`)
- Terminal Linux, WSL ou similar
- Ou use um compilador online (ex: [https://onecompiler.com/c](https://onecompiler.com/c))

### 🔧 Compilação

No terminal, execute:

```bash
gcc q9.c -o q9

./q9



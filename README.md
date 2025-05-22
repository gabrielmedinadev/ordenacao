
# Sistema de Ordenação e Processamento de Dados de Alunos

## Descrição

Este programa em C realiza a leitura de dados de alunos a partir de um arquivo CSV, permitindo diversas ordenações sobre os dados conforme critérios selecionados pelo usuário. Após a ordenação, os dados são salvos automaticamente em um novo arquivo CSV (`saida.csv`).

O programa foi desenvolvido com foco em simplicidade e clareza, utilizando algoritmos de ordenação básicos e manipulação de arquivos.

---

## Funcionalidades

- ✅ Leitura de arquivo CSV contendo dados de alunos.
- ✅ Ordenação dos alunos por:
  1. Nome
  2. Semestre
  3. Semestre, turma, período, disciplina e nome
  4. Disciplina e média (ordem decrescente da média)
  5. Período, semestre, turma, disciplina e nome
- ✅ Gravação dos dados ordenados em um novo arquivo CSV (`saida.csv`).
- ✅ Menu interativo para seleção da ordenação desejada.

---

## Estrutura dos Dados

Cada registro de aluno contém os seguintes campos:

- `semestre` — número inteiro
- `turma` — caractere único
- `periodo` — caractere único
- `nome` — texto (até 99 caracteres)
- `disciplina` — texto (até 49 caracteres)
- `media` — número decimal (float)

Formato esperado no arquivo CSV de entrada (`entrada.csv`):

```
semestre,turma,periodo,nome,disciplina,media
```

Exemplo de linha válida:

```
3,A,M,Carlos Silva,Matemática,7.5
```

---

## Exemplo de Arquivo `entrada.csv`

```csv
1,A,M,João Silva,Matemática,7.5
2,B,T,Ana Lima,Física,8.0
1,A,M,Marcos Souza,História,6.7
3,C,N,Camila Alves,Química,9.1
2,B,T,Beatriz Santos,Física,7.3
```

⚠️ O arquivo **não deve conter cabeçalho**.  
Cada linha representa um aluno com os campos separados por vírgula, na seguinte ordem:  
`semestre,turma,periodo,nome,disciplina,media`.

---

## Como Compilar

Utilize um compilador C, como `gcc`:

```bash
gcc programa.c -o programa
```

---

## Como Executar

1. Certifique-se de que existe um arquivo chamado `entrada.csv` no mesmo diretório do programa, contendo os dados no formato correto.
2. Execute o programa:

```bash
./programa
```

3. Escolha no menu a opção de ordenação desejada.
4. O arquivo `saida.csv` será gerado automaticamente com os dados ordenados.

---

## Menu de Opções

Ao executar o programa, será exibido o seguinte menu:

```
1. Ordenar por nome
2. Ordenar por semestre
3. Ordenar por semestre, turma, período, disciplina e nome
4. Ordenar por disciplina e média final (decrescente)
5. Ordenar por período, semestre, turma, disciplina e nome
0. Sair
```

Após cada ordenação, o programa salvará os dados em `saida.csv`.

---

## Dependências

- Compilador C compatível com C99 ou superior.
- Sistema de arquivos para leitura e gravação de CSV.

---

## Arquivos

- `programa.c` — Código-fonte do programa.
- `entrada.csv` — Arquivo de entrada com dados dos alunos (deve ser criado pelo usuário).
- `saida.csv` — Arquivo gerado automaticamente com os dados ordenados.

---

## Observações

- O programa suporta até **1000 alunos**.
- A ordenação é feita com **Bubble Sort** — suficiente para pequenas e médias quantidades de dados.
- A opção "Ordenar por período, semestre, turma, disciplina e nome" utiliza a mesma função de ordenação completa (`ordenar_completo`).
- O programa sobrescreve `saida.csv` a cada ordenação realizada.

---

## Melhorias Futuras

- Substituir o Bubble Sort por algoritmos mais eficientes (como QuickSort ou MergeSort).
- Parametrizar os nomes dos arquivos de entrada e saída via linha de comando.
- Implementar validação de dados ao ler o CSV.
- Melhorar o tratamento de erros e mensagens de feedback.

---

## Autor

Desenvolvido como exercício de manipulação de arquivos e algoritmos de ordenação em C.

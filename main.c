#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void SelectionSort(long int a[], int n){
    int i, j, min, aux,t=0;
    unsigned long long int comp = 0, troca = 0;
    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(a[j] < a[min]){
                min = j;
                t=1;
            }
            comp++;
        }
        if(t==1){
            troca++;
        }
        t=0;
        aux = a[min];
        a[min] = a[i];
        a[i] = aux;
    }
    printf("\n\nComparacoes:\n( %ld )\n", comp);
    printf("Trocas:\n( %ld )\n", troca);
}

void bubbleSort(long int v[], int n){
    int i, j, x;
    unsigned long long int contTrocas = 0, comparacao = 0;
    for (i=0; i<n-1; i++){
		for (j=0; j<n-1-i; j++){
            comparacao++;
            if (v[j] > v[j+1]){
                contTrocas++;
                x = v[j];
                v[j] = v[j+1];
                v[j+1] = x;
		    }
		    comparacao++;
        }
        if(contTrocas == 0){
            break;
        }
	}
	printf("\n\nComparacoes:\n( %ld )\n", comparacao);
    printf("Trocas:\n( %ld )\n", contTrocas);
}

void insertionSort(long int v[], int n){
    int i, j, valorAtual;
    unsigned long long int contTrocas = 0, comparacao = 0;
    for(i=1; i<n; i++){
        valorAtual = v[i];
        j = i - 1;
        comparacao++;
        while((j >= 0) && (valorAtual < v[j])){
            contTrocas++;
            v[j+1] = v[j];
            j--;
            comparacao++;
        }
        v[j+1] = valorAtual;
    }
    printf("\n\nComparacoes:\n( %ld )\n", comparacao);
    printf("Trocas:\n( %ld )\n", contTrocas);
}

int mergetrocas = 0;
int mergecomparacoes = 0;

void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio + 1, comAux = 0, tam = fim - comeco + 1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while (com1 <= meio && com2 <= fim) {
        mergecomparacoes++;
        if (vetor[com1] <= vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
            mergecomparacoes++;
            mergetrocas++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
            mergetrocas++;
        }
        comAux++;
    }

    while (com1 <= meio) {
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
        mergecomparacoes++;
        mergetrocas++;
    }

    while (com2 <= fim) {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
        mergecomparacoes++;
        mergetrocas++;
    }

    for (comAux = 0; comAux < tam; comAux++) {
        mergetrocas++;
        vetor[comeco + comAux] = vetAux[comAux];
    }

    free(vetAux);
}

void MergeSort(int vetor[], int comeco, int fim) {
    if (comeco < fim) {
        int meio = (fim + comeco) / 2;

        mergecomparacoes++;

        MergeSort(vetor, comeco, meio);
        MergeSort(vetor, meio + 1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

int quicktrocas = 0;
int quickcomparacoes = 0;

int particao(int v[], int esq, int dir) {
    int pivo, i, j, aux;

    pivo = v[esq];
    i = esq;
    j = dir;

    while(i < j) {
        quickcomparacoes++;
        while((v[i] <= pivo) && (i <= dir)) {
            quickcomparacoes++;
            i++;
        }
        while(v[j] > pivo) {
            quickcomparacoes++;
            j--;
        }
        if(i < j) {
            quickcomparacoes++;
            quicktrocas++;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    quicktrocas++;
    v[esq] = v[j];
    v[j] = pivo;
    return j;
}

void QuickSort(int v[], int esq, int dir) {
    int pivo;

    if (dir > esq) {
        quickcomparacoes++;
        pivo = particao(v, esq, dir);
        QuickSort(v, esq, pivo-1);
        QuickSort(v, pivo+1, dir);
    }

}

void shellSort(int *v, int n) {
    int i, j, valor;
    int h = 1;
    long int comparacoes = 0, trocas = 0;

    while (h < n) {
        h = 3 * h + 1;
    }

    while (h > 1) {
        h /= 3;
        for (i = h; i < n; i++) {
            valor = v[i];
            j = i;
            comparacoes++;
            while (j >= h && valor < v[j - h]) {
                v[j] = v[j - h];
                j = j - h;
                trocas++;
                comparacoes++;
            }
            v[j] = valor;
        }
    }

    printf("\nComparacoes:( %ld )\n", comparacoes);
    printf("Trocas:( %ld )\n", trocas);
}

long int comparacoesHeap = 0;
long int trocasHeap = 0;

void  refazHeap(int esq, int dir, int v[]){
    int i = esq;
    int j, aux;
    j = (i+1) * 2 - 1;
    aux = v[i];
    while (j <= dir){
        comparacoesHeap++;
        if (j < dir){
            comparacoesHeap++;
            if (v[j] < v[j+1])
            j++;
        }
        comparacoesHeap++;
        if (aux >= v[j])
            break;
        v[i] = v[j];
        i = j;
        j = i * 2 + 1;
        trocasHeap++;
    }
    v[i] = aux;
}

void constroiHeap(int v[], int n){
    int esq;
    esq = n / 2;
    while (esq > 0){
        esq--;
        refazHeap(esq, n, v);
    }
}

void heapSort(int v[], int n) {
    int esq, dir;
    int x;

    constroiHeap(v, n - 1);
    esq = 0;
    dir = n - 1;

    while (dir > 0) {
        x = v[0];
        v[0] = v[dir];
        v[dir] = x;
        dir--;
        refazHeap(esq, dir, v);
        trocasHeap++;
    }
}

void aleatorio(int v[], int n, int max){
    int i;
    for(i=0; i<n; i++){
        v[i] = rand()%max;
    }
}

void copiarVetor(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

void imprimir(int v[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("[%d] ", v[i]);
    }
}
int main()
{
    setlocale(LC_ALL, "portuguese");

    srand(time(NULL));

    int t1000 = 1000,i;
    int max = t1000 * 5;
    int *vetor1k = (int) malloc(sizeof(int) * t1000);
    aleatorio(vetor1k, t1000, max);


    int *vetorBubble1k = (int) malloc(sizeof(int) *t1000);
    int *vetorInsertion1k = (int) malloc(sizeof(int) *t1000);
    int *vetorSelection1k = (int) malloc(sizeof(int) *t1000);

    int *vetorMergeSort1k = (int) malloc(sizeof(int) *t1000);
    int *vetorQuickSort1k = (int) malloc(sizeof(int) *t1000);
    int *vetorShellSort1k = (int) malloc(sizeof(int) *t1000);
    int *vetorHeapSort1k = (int) malloc(sizeof(int) *t1000);

    copiarVetor(vetor1k, vetorBubble1k, t1000);
    copiarVetor(vetor1k, vetorInsertion1k, t1000);
    copiarVetor(vetor1k, vetorSelection1k, t1000);


    copiarVetor(vetor1k, vetorMergeSort1k, t1000);
    copiarVetor(vetor1k, vetorQuickSort1k, t1000);
    copiarVetor(vetor1k, vetorShellSort1k, t1000);
    copiarVetor(vetor1k, vetorHeapSort1k, t1000);

    printf("***Vetores de 1000***");

    printf("\nBubbleSort: ");
    bubbleSort(vetorBubble1k, t1000);

    printf("\nInsertionSort: ");
    insertionSort(vetorInsertion1k, t1000);

    printf("\nSelectionSort: ");
    SelectionSort(vetorSelection1k, t1000);

    printf("\nMergeSort:");
    mergecomparacoes = 0;
    mergetrocas = 0;
    MergeSort(vetorMergeSort1k, 0, t1000-1);
    printf("\nComparacoes: %ld", mergecomparacoes);
    printf("\nTrocas: %ld\n", mergetrocas);

    printf("\nQuickSort:");
    quickcomparacoes = 0;
    quicktrocas = 0;
    QuickSort(vetorQuickSort1k, 0, t1000-1);
    printf("\nComparacoes: %d", quickcomparacoes);
    printf("\nTrocas: %d\n", quicktrocas);

    printf("\nShellSort:");
    shellSort(vetorShellSort1k, t1000);

    printf("\nHeapSort:");
    comparacoesHeap = 0;
    trocasHeap = 0;
    heapSort(vetorHeapSort1k, t1000);
    printf("\nComparacoes: %ld", comparacoesHeap);
    printf("\nTrocas: %ld \n", trocasHeap);

    printf("\n***Vetores de 10000***\n");
    int t10000 = 10000;
    max = t10000 * 5;
    int *vetor10k = (int) malloc(sizeof(int) * t10000);
    aleatorio(vetor10k, t10000, max);

    int *vetorBubble10k = (int) malloc(sizeof(int) * t10000);
    int *vetorInsertion10k = (int) malloc(sizeof(int) * t10000);
    int *vetorSelection10k = (int) malloc(sizeof(int) * t10000);

    int *vetorMergeSort10k = (int) malloc(sizeof(int) *t10000);
    int *vetorQuickSort10k = (int) malloc(sizeof(int) *t10000);
    int *vetorShellSort10k = (int) malloc(sizeof(int) *t10000);
    int *vetorHeapSort10k = (int) malloc(sizeof(int) *t10000);

    copiarVetor(vetor10k, vetorBubble10k, t10000);
    copiarVetor(vetor10k, vetorInsertion10k, t10000);
    copiarVetor(vetor10k, vetorSelection10k, t10000);


    copiarVetor(vetor10k, vetorMergeSort10k, t10000);
    copiarVetor(vetor10k, vetorQuickSort10k, t10000);
    copiarVetor(vetor10k, vetorShellSort10k, t10000);
    copiarVetor(vetor10k, vetorHeapSort10k, t10000);


    printf("\nBubbleSort: ");
    bubbleSort(vetorBubble10k, t10000);

    printf("\nInsertionSort: ");
    insertionSort(vetorInsertion10k, t10000);

    printf("\nSelectionSort: ");
    SelectionSort(vetorSelection10k, t10000);

    printf("\nMergeSort:");
    mergecomparacoes = 0;
    mergetrocas = 0;
    MergeSort(vetorMergeSort10k, 0, t10000-1);
    printf("\nComparacoes: %ld", mergecomparacoes);
    printf("\nTrocas: %ld\n", mergetrocas);

    printf("\nQuickSort:");
    quickcomparacoes = 0;
    quicktrocas = 0;
    QuickSort(vetorQuickSort10k, 0, t10000-1);
    printf("\nComparacoes: %d", quickcomparacoes);
    printf("\nTrocas: %d\n", quicktrocas);

    printf("\nShellSort:");
    shellSort(vetorShellSort10k, t10000);

    printf("\nHeapSort:");
    comparacoesHeap = 0;
    trocasHeap = 0;
    heapSort(vetorHeapSort10k, t10000);
    printf("\nComparacoes: %ld", comparacoesHeap);
    printf("\nTrocas: %ld\n", trocasHeap);

    printf("\n***Vetores de 100000***\n");
    int t100000 = 100000;
    max = t100000 * 5;
    int *vetor100k = (int) malloc(sizeof(int) * t100000);
    aleatorio(vetor100k, t100000, max);

    int *vetorBubble100k = (int) malloc(sizeof(int) * t100000);
    int *vetorInsertion100k = (int) malloc(sizeof(int) * t100000);
    int *vetorSelection100k = (int) malloc(sizeof(int) * t100000);

    int *vetorMergeSort100k = (int) malloc(sizeof(int) *t100000);
    int *vetorQuickSort100k = (int) malloc(sizeof(int) *t100000);
    int *vetorShellSort100k = (int) malloc(sizeof(int) *t100000);
    int *vetorHeapSort100k = (int) malloc(sizeof(int) *t100000);

    copiarVetor(vetor100k, vetorBubble100k, t100000);
    copiarVetor(vetor100k, vetorInsertion100k, t100000);
    copiarVetor(vetor100k, vetorSelection100k, t100000);

    copiarVetor(vetor100k, vetorMergeSort100k, t100000);
    copiarVetor(vetor100k, vetorQuickSort100k, t100000);
    copiarVetor(vetor100k, vetorShellSort100k, t100000);
    copiarVetor(vetor100k, vetorHeapSort100k, t100000);

    printf("\nBubbleSort: ");
    bubbleSort(vetorBubble100k, t100000);

    printf("\nInsertionSort: ");
    insertionSort(vetorInsertion100k, t100000);

    printf("\nSelectionSort: ");
    SelectionSort(vetorSelection100k, t100000);

    printf("\nMergeSort:");
    mergecomparacoes = 0;
    mergetrocas = 0;
    MergeSort(vetorMergeSort100k, 0, t100000-1);
    printf("\nComparacoes: %ld", mergecomparacoes);
    printf("\nTrocas: %ld\n", mergetrocas);

    printf("\nQuickSort:");
    quickcomparacoes = 0;
    quicktrocas = 0;
    QuickSort(vetorQuickSort100k, 0, t100000-1);
    printf("\nComparacoes: %d", quickcomparacoes);
    printf("\nTrocas: %d\n", quicktrocas);


    printf("\nShellSort:");
    shellSort(vetorShellSort100k, t100000);

    printf("\nHeapSort:");
    comparacoesHeap = 0;
    trocasHeap = 0;
    heapSort(vetorHeapSort100k, t100000);
    printf("\nComparacoes: %ld", comparacoesHeap);
    printf("\nTrocas: %ld", trocasHeap);

    return 0;
}

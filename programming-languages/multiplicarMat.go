package main

import (
    "fmt"
    "math/rand"
    "sync"	
    "time"
)

// Define os tamanhos das matrizes para os testes
const sizeSmall = 5
const sizeLarge = 2000


// Função para gerar uma matriz aleatória de tamanho n x n
func generateMatrix(n int) [][]int {
    // Cria uma matriz bidimensional
    matrix := make([][]int, n)
    for i := range matrix {
        matrix[i] = make([]int, n)
        // Preenche a matriz com números aleatórios de 0 a 9
        for j := range matrix[i] {
            matrix[i][j] = rand.Intn(10)
        }
    }
    return matrix
}

// Função para multiplicação de matrizes de forma sequencial
func multiplyMatricesSequential(a, b [][]int) [][]int {
    n := len(a)
    result := make([][]int, n)
    for i := range result {
        result[i] = make([]int, n)
        for j := range result[i] {
            sum := 0
            // Calcula o produto das matrizes
            for k := 0; k < n; k++ {
                sum += a[i][k] * b[k][j]
            }
            result[i][j] = sum
        }
    }
    return result
}

// Função para multiplicação de matrizes de forma paralela
func multiplyMatricesParallel(a, b [][]int) [][]int {
    n := len(a)
    result := make([][]int, n)
    for i := range result {
        result[i] = make([]int, n)
    }

    var wg sync.WaitGroup
    // Inicia uma goroutine para cada linha da matriz de resultado
    for i := 0; i < n; i++ {
        wg.Add(1)
        go func(i int) {
            defer wg.Done()
            for j := 0; j < n; j++ {
                sum := 0
                // Calcula o produto das matrizes
                for k := 0; k < n; k++ {
                    sum += a[i][k] * b[k][j]
                }
                result[i][j] = sum
            }
        }(i)
    }
    // Espera todas as goroutines terminarem
    wg.Wait()
    return result
}

func main() {
    // Semente para geração de números aleatórios
    rand.Seed(time.Now().UnixNano())

    // Teste com matrizes pequenas (5x5)
    fmt.Println("Teste com matrizes pequenas (5x5)")
    aSmall := generateMatrix(sizeSmall)
    bSmall := generateMatrix(sizeSmall)

    // Multiplicação sequencial
    start := time.Now()
    multiplyMatricesSequential(aSmall, bSmall)
    elapsed := time.Since(start)
    fmt.Printf("Tempo sequencial: %s\n", elapsed)

    // Multiplicação paralela
    start = time.Now()
    multiplyMatricesParallel(aSmall, bSmall)
    elapsed = time.Since(start)
    fmt.Printf("Tempo paralelo: %s\n", elapsed)

    // Teste com matrizes grandes (20000x20000)
    fmt.Println("Teste com matrizes grandes (2000x2000)")
    aLarge := generateMatrix(sizeLarge)
    bLarge := generateMatrix(sizeLarge)

    // Multiplicação sequencial
    start = time.Now()
    multiplyMatricesSequential(aLarge, bLarge)
    elapsed = time.Since(start)
    fmt.Printf("Tempo sequencial: %s\n", elapsed)

    // Multiplicação paralela
    start = time.Now()
    multiplyMatricesParallel(aLarge, bLarge)
    elapsed = time.Since(start)
    fmt.Printf("Tempo paralelo: %s\n", elapsed)
}

#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>

#include "Shellsort.h"
#include "HeapSort.h"
#include "Trie.h"




// алгоритм подсчета времени сортировки массива по шеллу
long long algoritmforShellsort(std::vector<int>& source, int iterations) {
    long long total = 0;
    for (int i = 0; i < iterations; ++i) {
        std::vector<int> working(source);
        auto start = std::chrono::high_resolution_clock::now();
        Shellsort(working);
        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }
    return total;
}   


// алгоритм подсчета времени сортировки массива по пирамиде
long long algoritmforHeapsort(std::vector<int>& source, int iterations) {
    long long total = 0;
    for (int i = 0; i < iterations; ++i) {
        std::vector<int> working(source);
        auto start = std::chrono::high_resolution_clock::now();
        HeapSort(working);
        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }
    return total;
}  


// алгоритм подсчета времени ПОИСКА по Бору
long long algoritmforTriefind(std::vector<int>& source, int iterations) {
    long long total = 0;
    Trie trie(source);

    for (int i = 0; i < source.size(); ++i) {
        auto start = std::chrono::high_resolution_clock::now();

        for (int x : source) {
            trie.search(source[i]);
        }

        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }
    return total;
}  



int main() {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // колво элементов
    int N1 = 1600 * 2;
    int N2 = 2800 * 2;
    int N3 = 8800 * 2;
    srand(time(0));


    // 3 рандомных массива
    std::vector<int> sourceArrayN_1(N1);
    for (int i = 0; i < N1; ++i) {
        sourceArrayN_1[i] = rand() % 100000; 
    } 

    std::vector<int> sourceArrayN_2(N2);
    for (int i = 0; i < N2; ++i) {
        sourceArrayN_2[i] = rand() % 100000; 
    } 

    std::vector<int> sourceArrayN_3(N3);
    for (int i = 0; i < N3; ++i) {
        sourceArrayN_3[i] = rand() % 100000; 
    } 


    // подсчет Шелла
    double totaltime_Shell_N2 = algoritmforShellsort(sourceArrayN_2, 10) / 1'000'000.0;
    double totaltime_Shell_N3 = algoritmforShellsort(sourceArrayN_3, 10) / 1'000'000.0;
    double totaltime_Shell_N1 = algoritmforShellsort(sourceArrayN_1, 10) / 1'000'000.0;


    

    // Вывод Шелла 
    std::cout << "                      Результаты сортировки" << "\n";
    for (int i = 0; i < 55; ++i) { std::cout << "-";}
    std::cout << '\n';
    std::cout << "| Метод сортировки | " << "метод Шелла                     |" << std::endl;
    for (int i = 0; i < 55; ++i) { std::cout << "-";}
    std::cout << '\n';
    std::cout << "| Количество элементов, N | " << N1 << " | " << N2 << " | " << N3 << " |" << std::endl;
    for (int i = 0; i < 55; ++i) { std::cout << "-";}
    std::cout << '\n';
    std::cout << "| Время сортировки, t с | " << totaltime_Shell_N1 << " | " << totaltime_Shell_N2 << " | " << totaltime_Shell_N3 << " |" << std::endl;
    for (int i = 0; i < 55; ++i) { std::cout << "-";}
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    // подсчет пирамиды
    double totaltime_Heap_N1 = algoritmforHeapsort(sourceArrayN_1, 10) / 1'000'000.0;
    double totaltime_Heap_N2 = algoritmforHeapsort(sourceArrayN_2, 10) / 1'000'000.0;
    double totaltime_Heap_N3 = algoritmforHeapsort(sourceArrayN_3, 10) / 1'000'000.0;


        // Вывод пирамиды 
    std::cout << "                      Результаты сортировки" << "\n";
    for (int i = 0; i < 55; ++i) { std::cout << "-";}
    std::cout << '\n';
    std::cout << "| Метод сортировки | " << "метод Пирамиды                     |" << std::endl;
    for (int i = 0; i < 55; ++i) { std::cout << "-";}
    std::cout << '\n';
    std::cout << "| Количество элементов, N | " << N1 << " | " << N2 << " | " << N3 << " |" << std::endl;
    for (int i = 0; i < 55; ++i) { std::cout << "-";}
    std::cout << '\n';
    std::cout << "| Время сортировки, t с | " << totaltime_Heap_N1 << " | " << totaltime_Heap_N2 << " | " << totaltime_Heap_N3 << " |" << std::endl;
    for (int i = 0; i < 55; ++i) { std::cout << "-";}
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;





        // подсчет Бора
    double totaltime_Bora_N1 = algoritmforTriefind(sourceArrayN_1, 1) / 1'000'000.0;
    double totaltime_Bora_N2 = algoritmforTriefind(sourceArrayN_2, 1) / 1'000'000.0;
    double totaltime_Bora_N3 = algoritmforTriefind(sourceArrayN_3, 1) / 1'000'000.0;


        // Вывод Бора 
    std::cout << "                      Результаты поиска" << "\n";
    for (int i = 0; i < 55; ++i) { std::cout << "-";}
    std::cout << '\n';
    std::cout << "| Метод сортировки | " << "метод Бора                     |" << std::endl;
    for (int i = 0; i < 55; ++i) { std::cout << "-";}
    std::cout << '\n';
    std::cout << "| Количество элементов, N | " << N1 << " | " << N2 << " | " << N3 << " |" << std::endl;
    for (int i = 0; i < 55; ++i) { std::cout << "-";}
    std::cout << '\n';
    std::cout << "| Время сортировки, t с | " << totaltime_Bora_N1 << " | " << totaltime_Bora_N2 << " | " << totaltime_Bora_N3 << " |" << std::endl;

    for (int i = 0; i < 55; ++i) { std::cout << "-";}
}
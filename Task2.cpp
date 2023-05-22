#include <iostream>

// Структура, що описує багаж пасажира
struct Baggage {
    int numberOfItems;
    float totalWeight;
};

// Функція для введення даних про багаж пасажира
void inputBaggageInfo(Baggage& baggage) {
    std::cout << "Введіть кількість речей у багажі: ";
    std::cin >> baggage.numberOfItems;
    std::cout << "Введіть загальну вагу багажу: ";
    std::cin >> baggage.totalWeight;
}

// Функція для порівняння двох багажів за кількістю речей
bool compareByNumberOfItems(const Baggage& baggage1, const Baggage& baggage2) {
    return baggage1.numberOfItems > baggage2.numberOfItems;
}

// Функція для порівняння двох багажів за вагою
bool compareByWeight(const Baggage& baggage1, const Baggage& baggage2) {
    return baggage1.totalWeight > baggage2.totalWeight;
}

int main() {
    int N;
    std::cout << "Введіть кількість пасажирів: ";
    std::cin >> N;

    Baggage* passengers = new Baggage[N];

    // Введення даних про багаж кожного пасажира
    for (int i = 0; i < N; i++) {
        std::cout << "Дані про пасажира #" << i + 1 << ":" << std::endl;
        inputBaggageInfo(passengers[i]);
    }

    // Пошук пасажира з найбільшим багажем за кількістю речей
    int maxItemsIndex = 0;
    for (int i = 1; i < N; i++) {
        if (compareByNumberOfItems(passengers[i], passengers[maxItemsIndex])) {
            maxItemsIndex = i;
        }
    }

    // Пошук пасажира з найбільшим багажем за вагою
    int maxWeightIndex = 0;
    for (int i = 1; i < N; i++) {
        if (compareByWeight(passengers[i], passengers[maxWeightIndex])) {
            maxWeightIndex = i;
        }
    }

    std::cout << "Пасажир з найбільшим багажем за кількістю речей: #" << maxItemsIndex + 1 << std::endl;
    std::cout << "Пасажир з найбільшим багажем за вагою: #" << maxWeightIndex + 1 << std::endl;

    delete[] passengers;
    return 0;
}

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

    int maxItemsIndex = 0; // Індекс пасажира з найбільшим багажем за кількістю речей
    int maxWeightIndex = 0; // Індекс пасажира з найбільшим багажем за вагою

    // Пошук пасажира з найбільшим багажем за кількістю речей і за вагою
    for (int i = 1; i < N; i++) {
        if (passengers[i].numberOfItems > passengers[maxItemsIndex].numberOfItems) {
            maxItemsIndex = i;
        }

        if (passengers[i].totalWeight > passengers[maxWeightIndex].totalWeight) {
            maxWeightIndex = i;
        }
    }

    if (maxItemsIndex == maxWeightIndex) {
        std::cout << "Пасажир з найбільшим багажем за кількістю речей і вагою: #" << maxItemsIndex + 1 << std::endl;
    } else {
        std::cout << "Пасажира з найбільшим багажем водночас і за кількістю речей і за вагою немає." << std::endl;
    }

    delete[] passengers;
    return 0;
}

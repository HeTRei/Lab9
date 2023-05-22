#include <iostream>

const int MAX_SIZE = 100;

struct ABIT {
    std::string NAME;
    std::string GENDER;
    std::string SPEC;
    int EXAM[3];
};

void inputABIT(ABIT& abit) {
    std::cout << "Введіть прізвище та ініціали вступника: ";
    std::getline(std::cin >> std::ws, abit.NAME);
    std::cout << "Введіть гендер: ";
    std::getline(std::cin >> std::ws, abit.GENDER);
    std::cout << "Введіть спеціальність: ";
    std::getline(std::cin >> std::ws, abit.SPEC);
    std::cout << "Введіть результати екзаменів (три результати через пробіл): ";
    for (int i = 0; i < 3; i++) {
        std::cin >> abit.EXAM[i];
    }
}

void printSpecializationsBelowPassing(ABIT abits[], int size, int passingScore) {
    bool found = false;
    std::cout << "Абітурієнти, що не набрали прохідний бал (" << passingScore << "):\n";
    for (int i = 0; i < size; i++) {
        int totalScore = (abits[i].EXAM[0] + abits[i].EXAM[1] + abits[i].EXAM[2]) / 3;
        if (totalScore < passingScore) {
            std::cout << abits[i].NAME << " - " << abits[i].SPEC << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Всі абітурієнти набрали прохідний бал.\n";
    }
}

int main() {
    int N;
    std::cout << "Увага! Весь текст повинен бути введений латиницею.\nВведіть кількість абітурієнтів: ";
    std::cin >> N;

    ABIT abiturients[MAX_SIZE];

    for (int i = 0; i < N; i++) {
        std::cout << "Введіть деталі абітурієнта " << i + 1 << ":\n";
        inputABIT(abiturients[i]);
    }

    int passingScore;
    std::cout << "Введіть прохідний бал: ";
    std::cin >> passingScore;

    printSpecializationsBelowPassing(abiturients, N, passingScore);

    return 0;
}

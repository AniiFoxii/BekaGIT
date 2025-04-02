#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>    
#include <ctime>      
#include <fstream>     

int getRandomIndex(int size) {
    return std::rand() % size;
}
std::string generateStory(const std::vector<std::string>& heroes, const std::vector<std::string>& places, const std::vector<std::string>& actions, const std::vector<std::string>& details) {
    int heroIndex = getRandomIndex(heroes.size());
    int placeIndex = getRandomIndex(places.size());
    int actionIndex = getRandomIndex(actions.size());
    int detailIndex = getRandomIndex(details.size());

    return heroes[heroIndex] + " " + places[placeIndex] + ", " + actions[actionIndex] + " " + details[detailIndex] + ".";
}

void saveStory(const std::string& story) {
    std::ofstream outFile("stories.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << story << "\n";
        outFile.close();
        std::cout << "История сохранена в файл stories.txt" << std::endl;
    } else {
        std::cout << "Ошибка открытия файла для записи!" << std::endl;
    }
}
bool askPlayAgain() {
    char choice;
    std::cout << "\nХотите сгенерировать новую историю? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<std::string> heroes = {"отважный воин", "легендарный убийца", "чародей", "отважный мореплаватель", "храбрый расхититель гробниц"};
    std::vector<std::string> places = {"в Импрерии Красного Солнца", "на руинах забытого города", "в диких джунглях", "на просторах континента", "у подножия величественных горных хребтов"};
    std::vector<std::string> actions = {"помог избавится от проклятого дракона", "в усыпальнице королей древности отыскал сокровища", "одержал победу в турнире сильнейших всего континета", "развивал свою вотчину по памяти из другого мира", "раскрыл древнюю тайну династии Слейн"};
    std::vector<std::string> details = {"с магическим реликтом мечя", "на летающем грифоне", "под звуки волшебной сонаты битв", "с удивительной силой", "в сопровождении магического фамильяра"};

    std::cout << "Добро пожаловать в игру \"Генератор историй\"!" << std::endl;

    do {
        std::string story = generateStory(heroes, places, actions, details);
        std::cout << "\nСгенерированная история:\n" << story << std::endl;

        char saveChoice;
        std::cout << "\nСохранить историю в файл (stories.txt)? (y/n): ";
        std::cin >> saveChoice;
        if (saveChoice == 'y' || saveChoice == 'Y') {
            saveStory(story);
        }

    } while (askPlayAgain());

    std::cout << "Спасибо за игру! До свидания." << std::endl;

    return 0;
}

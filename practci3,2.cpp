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
    std::vector<std::string> heroes = {"смелый рыцарь", "хитрый вор", "волшебник", "отважный пират", "дерзкий исследователь"};
    std::vector<std::string> places = {"в далёком королевстве", "на заброшенной фабрике", "в густом лесу", "на просторах космоса", "у подножия гор"};
    std::vector<std::string> actions = {"победил дракона", "обнаружил сокровища", "выиграл битву", "устроил бал", "раскрыл древнюю тайну"};
    std::vector<std::string> details = {"с волшебным мечом", "на летающем ковре", "под звуки волшебной музыки", "с удивительной силой", "в сопровождении магического существа"};

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

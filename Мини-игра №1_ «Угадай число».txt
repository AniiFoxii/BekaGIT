#include <iostream>
#include <cstdlib>  // Для функции rand() и srand()
#include <ctime>    // Для получения времени для seed генератора
#include <limits>   // Для обработки ошибок ввода

int main() {
    std::cout << "Добро пожаловать в игру 'Угадай число'!\n";

    // Инициализация генератора случайных чисел
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Используем текущее время как seed
    int secretNumber = std::rand() % 100 + 1;  // Загаданное число в диапазоне от 1 до 100

    // Основной игровой цикл
    do {
        int guess = 0;   // Переменная для хранения предположения игрока
        int attempts = 0; // Счётчик попыток

        std::cout << "Я загадал число от 1 до 100. Попробуй угадать его!\n";

        // Игровой цикл: продолжаем, пока пользователь не угадает число
        while (true) {
            std::cout << "Введите ваше предположение: ";
            std::cin >> guess;

            // Проверка корректности ввода
            if (std::cin.fail()) {
                std::cin.clear();  // Очищаем ошибку ввода
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Игнорируем неверный ввод
                std::cout << "Пожалуйста, введите корректное число.\n";
                continue;
            }

            attempts++;  // Увеличиваем количество попыток

            // Сравниваем введённое число с загаданным
            if (guess < secretNumber) {
                std::cout << "Загаданное число больше.\n";
            } else if (guess > secretNumber) {
                std::cout << "Загаданное число меньше.\n";
            } else {
                // Если угадали
                std::cout << "Поздравляем! Вы угадали число " << secretNumber << " за " << attempts << " попыток.\n";
                break;  // Выход из цикла, игра окончена
            }
        }

        // Предложение сыграть снова
        char playAgain;
        std::cout << "Хотите сыграть ещё раз? (y/n): ";
        std::cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') {
            break;  // Выход из основного цикла, если пользователь не хочет играть снова
        } else {
            // Генерируем новое случайное число для следующей игры
            secretNumber = std::rand() % 100 + 1;
        }

    } while (true);  // Повторяем игру, если пользователь хочет

    std::cout << "Спасибо за игру! До свидания!\n";
    return 0;
}

#include <iostream>
#include <cstring>

int fermi(std::string guess_number, std::string usr_number, int number_of_digit){
    int count = 0;
    for(int i = 0; i < number_of_digit; i++) {
        if (guess_number[i] == usr_number[i]) {
            count++;
        }
    }
    return count;
}

int pico(std::string guess_number, std::string usr_number, int number_of_digits){
    int count = 0;

    for(int i = 0; i < number_of_digits; i++){
        for(int k = 0; k < number_of_digits; k++){

            if(usr_number[k] == guess_number[i]){
                count++;
                usr_number[k] = '-';
                guess_number[i] = '+';
                k = number_of_digits;
        }
    }
    }
    return count;
}

bool input_usr(std::string input, int number_of_digit){
    //std::cout << atoi(input);

    if(atoi(input) < pow(10, number_of_digit - 1)) return false ;
    return true;
} //проверка на правильность ввода

int main() {
    std::string guess_number = "545";
    std::string user_number = "";
    int number_of_digit;
    int fermi_number;
    int pico_number;
    std::cout << "Какое количество цифр желаете отгадывать? ";
    std::cin >> number_of_digit;
    std::cout << "Хорошо, пора начинать. Я загадал число. Удачи!" << std::endl;

    for(int i = 1; i < 21; i++){
        std::cout << "Попытка №" << i << "  ";
        std::cin >> user_number;
        if(!input_usr(user_number,number_of_digit)){
            std::cout << "Неправильный ввод, попробуйте заново.";
            i = i - 1;
            continue;
        }else{
            fermi_number = fermi(guess_number, user_number, number_of_digit);
            pico_number = pico(guess_number, user_number,number_of_digit);
            std::cout << "В цель = " << fermi_number << "\n";
            std::cout << "Рядом = " << pico_number - fermi_number << "\n";
        }
        std::cout << "input = " << user_number << "\n";

    }
    //std::cout << "Попытка №" << "\n"; //добавить номер попытки
    //std::cin >> user_number;
    fermi_number = fermi(guess_number, user_number, number_of_digit);
    pico_number = pico(guess_number, user_number,number_of_digit);
   // std::cout << "Совпадений FERME = " << fermi_number << "\n";
    //std::cout << "Совпадений ПИКО = " << pico_number - fermi_number << "\n";
    //pico( guess_number, user_number,arr_size);
    //std::cout << input_usr(guess_number,number_of_digit) << "\n";
    //std::cout << std::atoi(guess_number) << "\n" << pow(10, 5);

    return 0;
}

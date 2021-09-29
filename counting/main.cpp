#include <iostream>
#include <fstream>
#include <map>
#define FOOD 1
#define HOME 2
#define PHARM 3
#define CAFE 4
#define PHONE 5
#define TRANSPORT 6
#define CLOTHES 7
#define GIFTS 8
#define OTHER 9

double ConvertStrToDouble(std::string str) {
    return std::stod(str);
}

void CountInCategory(double &cat) {
    std::string exp;
    std::cout << "Enter expenses for this category." << std::endl;
    std::cin >> exp;
    if (exp == ".") {

    }
    cat += ConvertStrToDouble(exp);
}

/*int ConvertStrToInt(std::string str) {
    return std::stoi(str);
}*/

int main(int argc, char *argv[]) {
    std::string date = argv[1];

    struct Categories {
        double food;
        double home;
        double pharm;
        double cafe;
        double phone;
        double transport;
        double clothes;
        double gifts;
        double other;
    };
    Categories cat{};

    std::map<std::string, int> in;
    in["food"] = FOOD;
    in["home"] = HOME;
    in["pharmacy"] = PHARM;
    in["cafe"] = CAFE;
    in["phone"] = PHONE;
    in["transport"] = TRANSPORT;
    in["clothes"] = CLOTHES;
    in["gifts"] = GIFTS;
    in["other"] = OTHER;

    std::cout << "Enter necessary category:\n"
                 "● food\n"
                 "● home\n"
                 "● pharmacy\n"
                 "● cafe\n"
                 "● phone\n"
                 "● transport\n"
                 "● clothes\n"
                 "● gifts\n"
                 "● other\n" << std::endl;

    std::string input;
    std::cin >> input;

    switch (in[input]) {
        case FOOD:      CountInCategory(cat.food); break;
        case HOME:      CountInCategory(cat.home); break;
        case PHARM:     CountInCategory(cat.pharm); break;
        case CAFE:      CountInCategory(cat.cafe); break;
        case PHONE:     CountInCategory(cat.phone); break;
        case TRANSPORT: CountInCategory(cat.transport); break;
        case CLOTHES:   CountInCategory(cat.clothes); break;
        case GIFTS:     CountInCategory(cat.gifts); break;
        case OTHER:     CountInCategory(cat.other); break;

        default:        std::cerr << "Wrong name of category." << std::endl;
                        return -1;
    }


    std::map<std::string, Categories> map;
    map[date] = cat;



    std::fstream file;
    file.open("expenses.txt", std::fstream::app);
    if (file.is_open()) {
        //file.seekg(30, std::ios_base::end);


        file.close();
    } else {
        std::cerr << "file open error" << std::endl;
    }


    return 0;
}

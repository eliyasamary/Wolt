#include "Application.h"
#define MENU_SIZE 5
#define RESTAURANT_SIZE 3

int main() 
{
    Address liors_address(15, "Ramla");
    Client wolt_client("Lior", "0542288625", liors_address);

    Dish taizu_dishes[MENU_SIZE];
    taizu_dishes[0].setName("Sushi Roll");
    taizu_dishes[0].setDishType(MainCourse);
    taizu_dishes[0].setValue(20);
    taizu_dishes[1].setName("Saviche");
    taizu_dishes[1].setDishType(Appetizer);
    taizu_dishes[1].setValue(10);
    taizu_dishes[2].setName("Cheese Cake");
    taizu_dishes[2].setDishType(Dessert);
    taizu_dishes[2].setValue(12);
    taizu_dishes[3].setName("Ribeye Steak");
    taizu_dishes[3].setDishType(MainCourse);
    taizu_dishes[3].setValue(30);
    taizu_dishes[4].setName("Penne Rose");
    taizu_dishes[4].setDishType(MainCourse);
    taizu_dishes[4].setValue(20);

    Dish kisu_dishes[MENU_SIZE];
    kisu_dishes[0].setName("Hamburger");
    kisu_dishes[0].setDishType(MainCourse);
    kisu_dishes[0].setValue(20);
    kisu_dishes[1].setName("Root Salad");
    kisu_dishes[1].setDishType(Appetizer);
    kisu_dishes[1].setValue(10);
    kisu_dishes[2].setName("Chocolate Cake");
    kisu_dishes[2].setDishType(Dessert);
    kisu_dishes[2].setValue(12);
    kisu_dishes[3].setName("Siriloin Steak");
    kisu_dishes[3].setDishType(MainCourse);
    kisu_dishes[3].setValue(30);
    kisu_dishes[4].setName("Fettuchini Pomdoro");
    kisu_dishes[4].setDishType(MainCourse);
    kisu_dishes[4].setValue(20);

    Dish a_dishes[MENU_SIZE];
    a_dishes[0].setName("Salmon Fillet");
    a_dishes[0].setDishType(MainCourse);
    a_dishes[0].setValue(20);
    a_dishes[1].setName("Green Salad");
    a_dishes[1].setDishType(Appetizer);
    a_dishes[1].setValue(10);
    a_dishes[2].setName("Apple Pie");
    a_dishes[2].setDishType(Dessert);
    a_dishes[2].setValue(12);
    a_dishes[3].setName("Tenderloin Steak");
    a_dishes[3].setDishType(MainCourse);
    a_dishes[3].setValue(30);
    a_dishes[4].setName("Vegtebale Eggroll");
    a_dishes[4].setDishType(Appetizer);
    a_dishes[4].setValue(20);

    Menu taizu_menu(taizu_dishes, MENU_SIZE);
    Menu kisu_menu(kisu_dishes, MENU_SIZE);
    Menu a_menu(a_dishes, MENU_SIZE);

    Restaurant restaurants_array[RESTAURANT_SIZE];
    Address taizu_address(20, "Tel Aviv"), kisu_address(13, "Ramla"), a_address(10, "Modiin");
    restaurants_array[0].setName("Taizu");
    restaurants_array[0].setAddress(taizu_address);
    restaurants_array[0].setMenu(taizu_menu);

    restaurants_array[1].setName("Kisu");
    restaurants_array[1].setAddress(kisu_address);
    restaurants_array[1].setMenu(kisu_menu);

    restaurants_array[2].setName("A");
    restaurants_array[2].setAddress(a_address);
    restaurants_array[2].setMenu(a_menu);

    Application wolt(&wolt_client, restaurants_array, RESTAURANT_SIZE);
    int choose = 0;
    while (true)
    {
        std::cout << "\n-----------MENU:-----------\n"
            << "\t1-Exit\n"
            << "\t2-Check Order\n"
            << "\t3-Order\n>";
        std::cin >> choose;
        switch (choose)
        {
        case 1:
            return 0;
            break;
        case 2:
            wolt.CheckOrder();
            break;
        case 3:
            wolt.makeOrder();
            break;
        default:
            std::cout << "Please try again\n";
            break;
        }
    }
    return 0;
}
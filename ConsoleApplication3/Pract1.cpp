#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace chrono;


int fill_mas(int mas[], const int size, int mas_unsorted[]) {
    cout << "Выбрана команда: 1\n";
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        mas[i] = rand() % 199 - 99;
        mas_unsorted[i] = mas[i];
    }

    cout << "Массив успешно создан\n\n";
    return(0);
}

int print_mas(int mas[], const int size, bool flag) {
    cout << "Выбрана команда: 9\n";
    if (flag) {
        cout << "Массив:\n";
        for (int i = 0; i < size; i++) {
            cout << mas[i] << " ";
        }
        cout << "\n\n";
    }
    else {
        cout << "Массив не создан\n";
    }
    return(0);
}

int sort_mas(int mas[], const int size, bool flag) {
    cout << "Выбрана команда: 2\n";

    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;

    start = steady_clock::now();

    if (flag) {
        int temp;
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1; j++) {
                if (mas[j] > mas[j + 1]) {
                    temp = mas[j];
                    mas[j] = mas[j + 1];
                    mas[j + 1] = temp;
                }
            }
        }

        end = steady_clock::now();
        result = duration_cast<nanoseconds>(end - start);

        cout << "Массив отсортирован\n";
        cout << "Время сортировки(в наносекундах): " << result.count() << "\n";
    }
    else {
        cout << "Массив не создан\n";
    }
    return(0);
}

int find_max_min(int mas[], const int size, bool flag, int mas_unsorted[]) {
    cout << "Выбрана команда: 3\n";
    if (flag) {

        int temp;
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1; j++) {
                if (mas[j] > mas[j + 1]) {
                    temp = mas[j];
                    mas[j] = mas[j + 1];
                    mas[j + 1] = temp;
                }
            }
        }

        int max = mas[0], min = mas[0];

        time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
        nanoseconds result;

        start = steady_clock::now();

        for (int i = 0; i < size; i++) {
            if (mas[i] > max) {
                max = mas[i];
            }
        }
        for (int i = 0; i < size; i++) {
            if (mas[i] < min) {
                min = mas[i];
            }
        }

        end = steady_clock::now();
        result = duration_cast<nanoseconds>(end - start);

        cout << "Максимальное значение: " << max << "\n";
        cout << "Минимальное значение: " << min << "\n";
        cout << "Время поиска в отсортированном массиве(в наносекундах): " << result.count() << "\n\n";

        int max_ = mas_unsorted[0], min_ = mas_unsorted[0];

        start = steady_clock::now();

        for (int i = 0; i < size; i++) {
            if (mas_unsorted[i] > max_) {
                max_ = mas_unsorted[i];
            }
        }
        for (int i = 0; i < size; i++) {
            if (mas_unsorted[i] < min_) {
                min_ = mas_unsorted[i];
            }
        }

        end = steady_clock::now();
        result = duration_cast<nanoseconds>(end - start);

        cout << "Максимальное значение: " << max_ << "\n";
        cout << "Минимальное значение: " << min_ << "\n";
        cout << "Время поиска в неотсортированном массиве(в наносекундах): " << result.count() << "\n";

    }
    else {
        cout << "Массив не создан\n";
    }
    return(0);
}

int middle_max_min(int mas[], const int size, bool flag, int mas_unsorted[]) {
    cout << "Выбрана команда: 4\n\n";
    if (flag) {

        int temp;
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1; j++) {
                if (mas[j] > mas[j + 1]) {
                    temp = mas[j];
                    mas[j] = mas[j + 1];
                    mas[j + 1] = temp;
                }
            }
        }

        time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
        nanoseconds result;

        start = steady_clock::now();

        int max = mas[0], min = mas[0];
        for (int i = 0; i < size; i++) {
            if (mas[i] > max) {
                max = mas[i];
            }
        }
        for (int i = 0; i < size; i++) {
            if (mas[i] < min) {
                min = mas[i];
            }
        }

        end = steady_clock::now();
        result = duration_cast<nanoseconds>(end - start);

        int middle = (max + min) / 2;
        int count = 0;
        cout << "Среднее значение: " << middle << "\n";
        cout << "Индексы элементов, равные среднему значению: ";
        for (int i = 0; i < size; i++) {
            if (mas[i] == middle) {
                cout << i << " ";
                count += 1;
            }
        }
        cout << "\nКоличество: " << count << "\n";
        cout << "Время поиска в отсортированном массиве(в наносекундах): " << result.count() << "\n\n";

        start = steady_clock::now();

        int max_ = mas_unsorted[0], min_ = mas_unsorted[0];
        for (int i = 0; i < size; i++) {
            if (mas_unsorted[i] > max_) {
                max_ = mas_unsorted[i];
            }
        }
        for (int i = 0; i < size; i++) {
            if (mas_unsorted[i] < min_) {
                min_ = mas_unsorted[i];
            }
        }

        end = steady_clock::now();
        result = duration_cast<nanoseconds>(end - start);

        int middle_ = (max_ + min_) / 2;
        int count_ = 0;
        cout << "Среднее значение: " << middle_ << "\n";
        cout << "Индексы элементов, равные среднему значению: ";
        for (int i = 0; i < size; i++) {
            if (mas[i] == middle_) {
                cout << i << " ";
                count_ += 1;
            }
        }
        cout << "\nКоличество: " << count_ << "\n";
        cout << "Время поиска в неотсортированном массиве(в наносекундах): " << result.count() << "\n";

    }
    else {
        cout << "Массив не создан\n";
    }
    return(0);
}

int less_than_a(int mas[], const int size, bool flag, bool flag_sort) {
    cout << "Выбрана команда: 5\n";
    if (flag) {
        if (flag_sort) {
            cout << "Введите число: ";
            int a, count = 0;

            while (!(cin >> a)) {
                cout << "Ошибка ввода. Неправильный тип данных.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            for (int i = 0; i < size; i++) {
                if (mas[i] < a) {
                    count += 1;
                }
            }
            cout << "\nКоличество элементов, меньших, чем а: " << count << "\n";
        }
        else {
            cout << "Массив не отсортирован\n";
        }
    }
    else {
        cout << "Массив не создан\n";
    }
    return(0);
}

int more_than_b(int mas[], const int size, bool flag, bool flag_sort) {
    cout << "Выбрана команда: 6\n";
    if (flag) {
        if (flag_sort) {
            int b, count = 0;
            cout << "Введите число: ";

            while (!(cin >> b)) {
                cout << "Ошибка ввода. Неправильный тип данных.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            for (int i = 0; i < size; i++) {
                if (mas[i] > b) {
                    count += 1;
                }
            }
            cout << "\nКоличество элементов, больших, чем b: " << count << "\n";
        }
        else {
            cout << "Массив не отсортирован\n";
        }
    }
    else {
        cout << "Массив не создан\n";
    }
    return(0);
}

int binary_Search(int mas[], const int size, bool flag, bool flag_sort, int start, int end, int value) {
    if (flag) {
        if (flag_sort) {
            if (end >= start) {
                int mid = start + (end - start) / 2;

                if (mas[mid] == value) {
                    return mid;
                }

                if (mas[mid] > value) {
                    return binary_Search(mas, size, flag, flag_sort, start, mid - 1, value);
                }

                return binary_Search(mas, size, flag, flag_sort, mid + 1, end, value);
            }
        }
        else {
            cout << "Массив не отсортирован\n";
        }
    }
    else {
        cout << "Массив не создан\n";
    }
    return(-1);
}

int transpose(int mas[], const int size, bool flag) {
    cout << "Выбрана команда: 8\n";
    if (flag) {
        int elem1, elem2;
        cout << "Введите индексы: ";
        cin >> elem1 >> elem2;
        int temp;

        time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
        nanoseconds results;

        start = steady_clock::now();

        temp = mas[elem1 - 1];
        mas[elem1 - 1] = mas[elem2 - 1];
        mas[elem2 - 1] = mas[elem1 - 1];
        cout << "Элементы переставлены\n";

        end = steady_clock::now();
        results = duration_cast<nanoseconds>(end - start);

        cout << "Время перестановки(в наносекундах): " << results.count() << endl;
    }
    else {
        cout << "Массив не создан\n";
    }
    return(0);
}

int main()
{
    setlocale(LC_ALL, "RU");
    bool flag = false, flag_sort = false;
    int num = 1;
    const int size = 100;
    int mas[size] = {};
    int mas_unsorted[size] = {};
    while (num != 0) {
        cout << "Введите команду: \n"
            "[1]Заполнить массив\n"
            "[2]Сортировка массива\n"
            "[3]Вывод максимального и минимального значений\n"
            "[4]Вывод среднего результата максимального и минимального значений\n"
            "[5]Вывод количества элементов массива, меньших, чем число a\n"
            "[6]Вывод количества элементов массива, больших, чем число b\n"
            "[7]Бинарный поиск\n"
            "[8]Поменять местами элементы массива\n"
            "[9]Вывести массив\n"
            "[0]Выход из программы\n";
        cout << "Команда: ";

        while (!(cin >> num)) {
            cout << "Ошибка ввода. Неправильный тип данных.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (num) {

        case(1):
            system("cls");
            fill_mas(mas, size, mas_unsorted);
            flag = true;
            system("pause");
            break;

        case(2):
            system("cls");
            sort_mas(mas, size, flag);
            flag_sort = true;
            system("pause");
            break;

        case(3):
            system("cls");
            find_max_min(mas, size, flag, mas_unsorted);
            system("pause");
            break;

        case(4):
            system("cls");
            middle_max_min(mas, size, flag, mas_unsorted);
            system("pause");
            break;

        case(5):
            system("cls");
            less_than_a(mas, size, flag, flag_sort);
            system("pause");
            break;

        case(6):
            system("cls");
            more_than_b(mas, size, flag, flag_sort);
            system("pause");
            break;

        case(7):
            system("cls");
            int value;
            cout << "Выбрана команда: 7\nВведите число: ";

            while (!(cin >> value)) {
                cout << "Ошибка ввода. Неправильный тип данных.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            if (num == 7) {
                time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
                nanoseconds results;

                start = steady_clock::now();

                int result = binary_Search(mas, size, flag, flag_sort, 0, size - 1, value);


                if (result == -1) {
                    cout << "Элемент не найден" << endl;
                }
                else {
                    cout << "Элемент находится в позиции " << result + 1 << endl;

                    end = steady_clock::now();
                    results = duration_cast<nanoseconds>(end - start);

                    cout << "Время бинарного поиска(в наносекундах): " << results.count() << endl;

                    start = steady_clock::now();

                    for (int i = 0; i < size; i++) {
                        if (mas[i] == value) {
                            cout << "Элемент находится в позиции " << i + 1 << endl;
                            break;
                        }
                    }

                    end = steady_clock::now();
                    results = duration_cast<nanoseconds>(end - start);
                    cout << "Время обычного перебора(в наносекундах): " << results.count() << endl;
                }
            }
            system("pause");
            break;

        case(8):
            system("cls");
            transpose(mas, size, flag);
            flag_sort = false;
            system("pause");
            break;

        case(9):
            system("cls");
            print_mas(mas, size, flag);
            system("pause");
            break;

        }
        system("cls");
    }
    return(0);
}
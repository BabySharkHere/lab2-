/*Дополнительные методы для класса «Строка-идентификатор»: перевод всех символов строки 
(кроме цифр) в нижний регистр, переопределение операции проверки на равенство «==».
Производный от «Строки» класс «Шестнадцатеричная строка».
Строки данного класса могут содержать только символы шестнадцатеричных цифр (как в 
верхнем, так и в нижнем регистре) и символы «-» и «+», задающие знак числа, которые могут находиться только в первой позиции числа, при отсутствии знака число считается положительным. 
Если в составе инициализирующей строки будут встречены любые символы, отличные от допустимых, «Шестнадцатеричная строка» принимает нулевое значение. Содержимое данных строк 
рассматривается как шестнадцатеричное число. 
Обязательные методы: определение, можно ли представить данное число в формате long, перегрузка операций сложения «+» и проверки на меньше «<» двух шестнадцатеричных чисел.*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <locale>


using namespace std;

void cleaning() {
    cin.clear();
    while (cin.get() != '\n');
}
//---------------------------------------------------------------------------
//----------------------------------------------------------------------------

class line {
    friend class line16; friend class lineIdent;
protected:
    int n;  //кол-во строк, которое вбил пользователь
    int* z;  // массив 16-ой строки
    int i;
    int x;  //син типов операндов
    string* AS;  //массив строк, которые вбил пользователь
    string* newArrayS; //массив строка-идентификатор
    int j;  //поля
    int k;  //поля
    string strE;    //переменная для строк
    string strS;    //переменная для строк
    int plus1;  //переменная для 16-тиричной строки
    int plus2;  //переменная для 16-тиричной строки
    string str;
    locale loc;
    char c;
    int pos;
    int r;
    int flag;
    int t;
    int rithm;
public:

    line() {
        n = 0;
        z = 0;
        i = 0;
        x = 0;
        AS = 0;
        newArrayS = 0;
        j = 0;
        k = 0;
        strE = '0';
        strS = '0';
        plus1 = 0;
        plus2 = 0;
        str = '0';
        pos = 0;
        cout << "Конструктор по-умолчанию активирован" << endl;
    }
    
    void getter() {
        cout << "Введите кол-во строк: " << endl;
        while (!(cin >> n) || cin.get() != '\n' && n < 0) {
            cout << "Ошибка! Введите целое число" << endl;
            cleaning();
        }
        AS = new string[n];
        z = new int[n];
        newArrayS = new string[n];
        system("CLS");

        t = 0;
        rithm = 0;
        r = 0;
        flag = 0;
        cout << "Заполните операдны: " << endl;
        for (i = 0; i < n; i++) {
            //cin >> AS[i];
            while (!(cin >> AS[i]) || cin.get() != '\n') {
                cout << "Ошибка!!! Попробуйте другое число" << endl;
                cleaning();
            }

            cout << "Выберите тип операнда:" << endl;
            cout << "1.Строка" << endl;
            cout << "2.Строка-идентификатор" << endl;
            cout << "3.16-ая строка" << endl;

            while (!(cin >> x) || cin.get() != '\n' && (x < 0 || x>3)) {
                cout << "Ошибка!!! Попробуйте другое число" << endl;
                cleaning();
            }


            if (x == 2) {
                //int t = 0;
                newArrayS[t] = AS[i];
                t++;
                rithm++;
                cout << "Добавлена строка-идентификатор" << endl;
            }
            

            if (x == 3) {
                pos = 0;
                str = AS[i];
                for (string::size_type i = 0; i < str.length(); i++)
                {
                    c = str[i];
                    if ((c < '0' || c >'9') && (c < 'a' || c > 'f') && (c < 'A' || c > 'F') && (c != '-') && (c != '+')) {

                        str.clear();
                        str = '0';
                        //AS[i].clear();
                        //AS[i] = '0';
                        cout << "Строка обнулена" << endl;
                        //z[r] = stoi(AS[i], 0, 16);
                        z[r] = 0;
                        //r++;
                        //flag++;

                    }
                }
                
                if (z[r] == 0) {
                    r++;
                    flag++;
                    AS[i].clear();
                    AS[i] = "0";
                    cout << "Добавлен элемент 0" << endl;
                }
                else {

                    pos = str.find('-');
                    if (pos == -1) {
                        z[r] = stoi(str, 0, 16);
                        cout << "Добавил положительный элемент" << endl;
                        r++;
                        flag++;
                    }
                    else if (pos > 1) {
                        str.clear();
                        //str = '0';
                        AS[i].clear();
                        AS[i] = '0';
                        cout << "Строка обнулена" << endl;
                        //z[r] = stoi(str, 0, 16);
                        z[r] = 0;
                        r++;
                        flag++;

                    }
                    else {
                        str.erase(0, 1);
                        z[r] = stoi(str, 0, 16);
                        z[r] = z[r] * -1;
                        cout << "Добавил отрицательный элемент" << endl;
                        r++;
                        flag++;
                    }
                }
            }
        }
    }

        void pushLine16() {
        for (i = 0; i < flag; i++) {
            if (z[i] > 0) {
                cout << "z[" << i << "]: " << dec << z[i] << endl;
            }
            else {
                z[i] = z[i] * -1;
                cout << "z[" << i << "]: " << "-" << dec << z[i] << endl;
                z[i] = z[i] * -1;
            }
        }
    }

    void push() {
        for (i = 0; i < n; i++) {
            cout << "AS[" << i << "]: " << AS[i] << endl;
        }
    }

    void choise() {

       /* cout << "Выберите 2 операнда: " << endl;
        push();
        while (!(cin >> j) || cin.get() != '\n' && (j < 0 || j > n-1)) {
            cout << "Ошибка! Введите другой id операнда" << endl;
            cleaning();
        }
        strE = newArrayS[j];
        plus1 = z[j];

        cout << "Первый операнд равен: " << AS[j] << endl;

        while (!(cin >> k || cin.get() != '\n' && (k != j) && (k < 0 || k > n-1))) {
            cout << "Ошибка! Введите другой id операнда" << endl;
            cleaning();
        }
        strS = newArrayS[k];
        plus2 = z[k];

        cout << "Второй операнд равен: " << AS[k] << endl;*/
        cout << "Выберите тип операнда, с которым вы хотите работать" << endl;
        cout << "1. Строка-идентификатор" << endl;
        cout << "2. 16-тиричная строка" << endl;
        cin >> x;

        switch (x) {
        case 1: {
            cout << "Выбран тип операнда - 'Строка-идентификатор'" << endl;
            for (int i = 0; i < rithm; i++) {
                cout << "newArrayS[" << i << "] " << newArrayS[i] << endl;
            }
            cout << "Выход из этого пункта меню '1001'" << endl;

                cout << "Выберите 2 операнда" << endl;
                
                cin >> j;
                if (j == 1001)
                {
                    cout << "Выход из меню" << endl;
                    break;
                }
                cout << "Первый операнд равен: " << newArrayS[j] << endl;
                strE = newArrayS[j];

                cin >> k;
                if (k == 1001)
                {
                    cout << "Выход из меню" << endl;
                    break;
                }

                cout << "Второй операнд равен: " << newArrayS[k] << endl;
                strS = newArrayS[k];

                system("Pause");
                system("CLS");
                break;
        }
        case 2: {
            cout << "Выбран тип операнда - '16-тиричная строка'" << endl;
            for (int i = 0; i < flag; i++) {
                if (z[i] < 0) {
                    z[i] = z[i] * -1;
                    cout << "z[" << i << "] -" << hex << z[i] << endl;
                    z[i] = z[i] * -1;
                }
                else {
                    cout << "z[" << i << "] " << hex << z[i] << endl;
                }
            }

            cout << "Выход из этого пункта меню '1001'" << endl;

                cout << "Выберите 2 операнда" << endl;

                cin >> j;
                if (j == 1001)
                {
                    cout << "Выход из меню" << endl;
                    break;
                }
                if (z[j] < 0) {
                    z[j] = z[j] * -1;
                    cout << "Первый операнд равен: -" << hex << z[j] << endl;
                    z[j] = z[j] * -1;
                    plus1 = z[j];
                }
                else {
                    cout << "Первый операнд равен: " << hex << z[j] << endl;
                    plus1 = z[j];
                }

                cin >> k;
                if (k == 1001)
                {
                    cout << "Выход из меню" << endl;
                    break;
                }
                if (z[k] < 0) {
                    z[k] = z[k] * -1;
                    cout << "Второй операнд равен: -" << hex << z[k] << endl;
                    z[k] = z[k] * -1;
                    plus2 = z[k];
                }
                else {
                    cout << "Второй операнд равен: " << hex << z[k] << endl;
                    plus2 = z[k];
                }
            

            system("Pause");
            system("CLS");
            break;
        }
        }
    }

       ~line() {
           cout << "Вызван деструктор" << endl;
           delete[] AS;
           delete[] z;
           delete[] newArrayS;
       }
};

//--------------------------------------------------------------------
//--------------------------------------------------------------------
class line16 : public line {
protected:
    int* z;
    int j;
    int k;
public:

    line16& operator= (const line& a)
    {
        z = a.z;
        j = a.j;
        k = a.k;
        plus1 = a.plus1;
        plus2 = a.plus2;
        cout << "Констркутор копирования активирован" << endl;
        return *this;
    }

    friend int  operator + (const line16& rc1, const line16& rc2)
    {
        if (rc1.plus1 + rc2.plus2 < 0) {
            cout << "-";
            return ((rc1.plus1 + rc2.plus2) * -1);
        }
        else
            return (rc1.plus1 + rc2.plus2);
    }

    /*void plus() {

        int sum = 0;
        int b = z[j];
        int a = z[k];


        sum = b + a;
        if (sum < 0) {
            sum = sum * -1;
            cout << "Сумма двух операндов в 16-ом формате равна: " << "-" << hex << sum << endl;
        }
        else cout << "Сумма двух операндов в 16-ом формате равна: " << hex << sum << endl;
    }*/

    /*void test16() {
        cout << "Вы выбрали пункт '16-тиричная строка' " << endl;
        cout << "1. Сложить два операнда" << endl;
        cout << "2. Найти наименьший операнд" << endl;
        cout << "3. Узнать, возмонжно ли представить в long" << endl;
        cin >> check;
        switch (check) {
        case 1: {
            plus();    
            system("Pause");
            system("CLS");
            break;
        }
        case 2: {
            less();
        }
        case 3: {
            longoper();
        }
        }
    }*/

    void plus() {
        line16 b;
        line16 x;
        cout << hex << b + x << endl;
    }

    void less() {

        int min;

        if (z[j] < z[k]) {
            min = z[j];
        }
        else min = z[k];

        if (min < 0) {
            min = min * -1;
            cout << "Минимальный операнд равен: " << "-" << hex << min << endl;
        }
        else
            cout << "Минимальный операнд равен: " << hex << min << endl;


    }

    void longoper() {
        int p;
        int o;
        int y;

        p = sizeof(long);
        o = sizeof(z[j]);
        y = sizeof(z[k]);


        if (o <= p && y <= p)
            cout << "Оба операнда можно представить в формате long" << endl;
        else if (o <= p)
            cout << "Первый операнд можно представить в формате long" << endl;
        else if (y <= p)
            cout << "Второй операнд можно представить в формате long" << endl;
        else
            cout << "Ни первый ни второй операнд нельзя представить в формате long" << endl;
    }
};
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
class lineIdent : public line {

protected:
    string* newArrayS; //массив строка-идентификатор
    int j;  //поля
    int k;  //поля
    string strE;
    string strS;
public:

    lineIdent& operator= (const line& a)
    {
        newArrayS = a.newArrayS;
        j = a.j;
        k = a.k;
        strE = a.strE;
        strS = a.strS;
        cout << "Конструктор копирования активирован" << endl;
        return *this;
    };

    friend bool operator == (const lineIdent& str1, const  lineIdent& str2)
    {


        return str1.strE == str2.strS;

    }

    void changeCase()   // перевод в нижний регистр
    {

        string str;
        str = newArrayS[j];

        locale loc;
        char c;

        cout << "Преобразованный первый операнд: " << endl;

        for (string::size_type i = 0; i < str.length(); ++i)
        {
            c = str[i];
            if (isupper(c, loc)) c = tolower(c, loc);
            cout << c;
        }
        cout << endl;

        str = newArrayS[k];

        cout << "Преобразованный второй операнд: " << endl;

        for (string::size_type i = 0; i < str.length(); ++i)
        {
            c = str[i];
            if (isupper(c, loc)) c = tolower(c, loc);
            cout << c;
        }
        cout << endl;
    }

};

void testmenu() {
    cout << "1. Строка" << endl;
    cout << "2. Строка-идентификатор" << endl;
    cout << "3. 16-ричная строка" << endl;
    cout << "4. Выбор операндов" << endl;
    cout << "0. Выход" << endl;
}

void testMenuString() {
    cout << "Вы выбрали пункт меню 'Строка'" << endl;
    cout << "1. Вывести строки на экран" << endl;
}

void testMenuStringIdent() {
    cout << "Вы выбрали пункт 'Строка - индентификатор'" << endl;
    cout << "1. Сравнить операнды" << endl;
    cout << "2. Перевести все буквы верхнего регистра в нижний" << endl;
}

void testMenuString16() {
    cout << "Вы выбрали пункт меню '16-ричная строка'" << endl;
    cout << "1. Сумма операндов" << endl;
    cout << "2. Меньший операнд" << endl;
    cout << "3. long - оператор" << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    int change;
    int changeCase;
    int ChangeCase;
    line a;
    line16 b;
    lineIdent d;
    lineIdent c;

    do{
        cout << "1. Заполнить операнды" << endl;
        while (!(cin >> change) || cin.get() != '\n' && (change < 0 || change > 1)) {
            cout << "Ошибка! Введёный пункт меню отсутствует!" << endl;
            cleaning();
        }
        if (change == 1) {
            a.getter();
            system("Pause");
            system("CLS");
        }
    } while (change != 1);

        do {
            cout << "1. Выбрать операнды" << endl;
            cout << "2. Перейти к тест-меню" << endl;
            while (!(cin >> change) || cin.get() != '\n' && (change < 0 || change > 2)) {
                cout << "Ошибка! Введёный пункт меню отсутствует!" << endl;
                cleaning();
            }
            switch (change) {
            case 1: {
                a.choise();
                //system("Pause");
                system("CLS");
                break;
            }
            }
        } while (change != 2);

        do {
            testmenu();
            while (!(cin >> change) || cin.get() != '\n' && (change < 0 || change > 4)) {
                cout << "Ошибка! Введёный пункт меню отсутствует!" << endl;
                cleaning();
            }
            switch (change) {
            case 1: {
                system("CLS");
                testMenuString();
                while (!(cin >> ChangeCase) || cin.get() != '\n' && (ChangeCase < 0 || ChangeCase > 1)) {
                    cout << "Ошибка! Введёный пункт меню отсутствует!" << endl;
                    cleaning();
                }
                switch (ChangeCase) {
                case 1: {
                    a.push();
                    system("Pause");
                    system("CLS");
                    break;
                }
                }
                break;
            }
            case 2: {
                system("CLS");
                testMenuStringIdent();
                while (!(cin >> ChangeCase) || cin.get() != '\n' && (ChangeCase < 0 || ChangeCase > 2)) {
                    cout << "Ошибка! Введёный пункт меню отсутствует!" << endl;
                    cleaning();
                }
                switch (ChangeCase) {
                case 1: {
                    c = a;
                    d = a;
                    if (c == d)
                        cout << "Строки равны" << endl;
                    else
                        cout << "Строки не равны" << endl;
                    system("Pause");
                    system("CLS");
                    break;
                }
                case 2: {
                    c = a;
                    c.changeCase();
                    system("Pause");
                    system("CLS");
                    break;
                }
                }
                break;
            }

            case 3: {
                system("CLS");
                testMenuString16();
                while (!(cin >> ChangeCase) || cin.get() != '\n' && (ChangeCase < 0 || ChangeCase > 3)) {
                    cout << "Ошибка! Введёный пункт меню отсутствует!" << endl;
                    cleaning();
                }
                switch (ChangeCase) {
                case 1: {
                    b = a;
                    line16 x = b;
                    cout << hex << b + x << endl;
                    system("Pause");
                    system("CLS");
                    break;
                }
                case 2: {
                    b = a;
                    b.less();
                    system("Pause");
                    system("CLS");
                    break;
                }
                case 3: {
                    b = a;
                    b.longoper();
                    system("Pause");
                    system("CLS");
                    break;
                }
                }
                break;
            }
            case 4: {
                a.choise();
                //system("Pause");
                system("CLS");
                break;
            }
            case 0: {
                line* ptr = new line();
                ptr->~line();
                exit(0);
            }
            }
        } while (true);


              /*case 2: {
                  a.push();
                  system("Pause");
                  system("CLS");
                  break;
              }
              case 3: {
                  a.pushLine16();
                  system("Pause");
                  system("CLS");
                  break;
              }
              case 4: {
                  a.choise();
                  system("Pause");
                  system("CLS");
                  break;
              }
              case 5: {


                  b = a;
                  line16 x = b;
                  cout << hex << b + x << endl;
                  system("Pause");
                  system("CLS");
                  break;
              }
              case 6: {
                  b = a;
                  b.less();
                  system("Pause");
                  system("CLS");
                  break;
              }
              case 7: {
                  b = a;
                  b.longoper();
                  system("Pause");
                  system("CLS");
                  break;
              }
              case 8: {
                  c = a;
                  d = a;
                  if (c == d)
                      cout << "Строки равны" << endl;
                  else
                      cout << "Строки не равны" << endl;
                  system("Pause");
                  system("CLS");
                  break;
              }
              case 9: {
                  c = a;
                  c.changeCase();
                  system("Pause");
                  system("CLS");
                  break;
              }
              case 0: {
                  line* ptr = new line();
                  ptr->~line();
                  exit(0);
              }
              }*/
        }

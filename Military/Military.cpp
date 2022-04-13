#include <iostream>
using namespace std;

const int N = 41;

string statesList[] = { "Адыгея", "Башкортостан", "Бурятия", "Алтай", "Дагестан", "Ингушетия", "Кабардино-Балкария", "Калмыкия", "Карачаево-Черкесия", "Карелия", 
"Коми", "Марий-Эл", "Мордовия", "Якутия", "Сев.Осетия", "Татарстан", "Тыва", "Удмуртия", "Хакассия", "Чечня",
"Чувашия", "Алтай", "Краснодар", "Красноярск", "Приморье", "Ставрополь", "Хабаровск", "Приамурье", "Архангельск", "Астрахань",
"Белгород", "Брянск", "Владимир", "Волгоград", "Вологда", "Воронеж", "Иваново", "Иркутск", "Калининград", "Калуга",
"Камчатка", "Кемерово", "Киров", "Кострома", "Курган", "Курск", "Ленинград", "Липецк", "Магадан", "Москва"};

bool attempts[N];
bool hide = true;

struct coord {
    int x;
    int y;
};

coord coordsList[] = { {7, 20}, {23, 19}, {58, 20}, {43, 23}, {11, 23},
    {10, 21}, {8, 21}, {12, 20}, {8, 20}, {18, 11},
    {27, 14}, {20, 16}, {16, 17}, {60, 12}, {9, 21},
    {20, 17}, {47, 22}, {23, 17}, {45, 22}, {10, 22},
    {18, 17}, {43, 23}, {7, 20}, {46, 14}, {77, 21},
    {10, 20}, {72, 17}, {68, 19}, {22, 12}, {13, 21},
    {10, 16}, {11, 15}, {16, 16}, {14, 19}, {18, 14},
    {12, 18}, {17, 15}, {52, 20}, {7, 11}, {12, 15},
    {79, 10} };
int g;

void E() {
    cout << endl;
}

void Island(int x, int y) {
    for (int i = 0; i++ < x;) cout << " ";
    for (int i = 0; i++ < y;) cout << "#";
}

void Space(int x) {
    for (int i = 0; i++ < x;) cout << " ";
}

void Bullet(int x) {
    if (hide) return;
    if (attempts[x - 1]) cout << "   "; else
        if (x < 10) cout << " " << x << ".";
        else cout << x << ".";
    cout << " " << statesList[x - 1];
}

void IslandO(int x, int y) {
    for (int i = 0; i++ < x;) cout << " ";
    for (int i = 0; i++ < y;) cout << ":";
}

void Dot(int x) {
    for (int i = 0; i++ < x;) cout << " ";
    cout << "#";
}

void DotO(int x) {
    for (int i = 0; i++ < x;) cout << " ";
    cout << ":";
}

void Archipelag(int count, int* x) {
    for (int i = 0; i < count; i += 2)
        Island(x[i], x[i + 1]);
}

int tonum(string s) {
    string s1 = s + "f";
    return (s1[0] - 48) * 10 + s1[1] - 48;
}

string toName(int a) {
    if (a > 0 && a < 85) return statesList[a - 1];
}

string Compare(int reg) {
    float wgt = coordsList[g - 1].x - coordsList[reg - 1].x;
    float hgt = coordsList[g - 1].y - coordsList[reg - 1].y;
    float tg = hgt / wgt;
    if (wgt >= 0 && hgt < 0) {
        if (tg < -0.42 && tg > -2.46) return "северо-восточнее";
        if (tg > -0.42) return "восточнее";
        if (tg < -2.46) return "севернее";
    }
    if (wgt < 0 && hgt < 0) {
        if (tg > 0.42 && tg < 2.46) return "северо-западнее";
        if (tg < 0.42) return "западнее";
        if (tg > 2.46) return "севернее";
    }
    if (wgt >= 0 && hgt >= 0) {
        if (tg > 0.42 && tg < 2.46) return "юго-восточнее";
        if (tg < 0.42) return "восточнее";
        if (tg > 2.46) return "южнее";
    }
    if (wgt < 0 && hgt >= 0) {
        if (tg < -0.42 && tg > -2.46) return "юго-западнее";
        if (tg > -0.42) return "западнее";
        if (tg < -2.46) return "южнее";
    }
    return "рядом";
}

int State(string s) {
    string s1 = s + "f";
    if (s1[0] >= 49 && s1[0] <= 57 && s1[1] >= 48 && s1[1] <= 57) {
        return tonum(s1);
    }
    if (s1[0] >= 49 && s1[0] <= 57) {
        return tonum("0" + s);
    }
    for (int i = 0; i < N; i++)
        if (s == statesList[i]) return i + 1;
    return -1;
}

void Draw(int region) {
    string str;
    int st;
    system("cls");

    //1
    if (region == 80) DotO(76); else Dot(76);
    Space(8); Bullet(1); Space(13); Bullet(25);
    E();

    //2
    if (region == 80) DotO(69); else Dot(69);
    if (region == 80) IslandO(4, 4); else Island(4, 4);
    Space(7); Bullet(2); Space(7); Bullet(26);
    E();

    //3
    if (region == 80) IslandO(70, 4); else Island(70, 4);
    Space(11); Bullet(3); Space(12); Bullet(27);
    E();

    //4
    if (region == 80) IslandO(69, 4); else Island(69, 4);
    Space(12); Bullet(4); Space(14); Bullet(28);
    E();

    //5
    if (region == 80) IslandO(68, 10); else Island(68, 10);
    Space(7); Bullet(5); Space(11); Bullet(29);
    E();

    //6
    if (region == 24) DotO(44); else Dot(44);
    if (region == 14) DotO(14); else Dot(14);
    if (region == 14) DotO(5); else Dot(5);
    if (region == 80) IslandO(1, 10); else Island(1, 10);
    if (region == 41) IslandO(0, 1); else Island(0, 1);
    Space(7); Bullet(6); Space(10); Bullet(30);
    E();

    //7
    if (region == 24) DotO(44); else Dot(44);
    if (region == 24) DotO(1); else Dot(1);
    if (region == 14) IslandO(9, 2); else Island(9, 2);
    if (region == 14) DotO(1); else Dot(1);
    if (region == 14) IslandO(2, 7); else Island(2, 7);
    if (region == 80) IslandO(0, 4); else Island(0, 4);
    if (region == 41) IslandO(0, 5); else Island(0, 5);
    Space(7); Bullet(7); Space(1); Bullet(31);
    E();

    //8
    if (region == 51) IslandO(21, 2); else Island(21, 2);
    if (region == 29) IslandO(11, 4); else Island(11, 4);
    if (region == 24) IslandO(8, 4); else Island(8, 4);
    if (region == 14) IslandO(10, 11); else Island(10, 11);
    if (region == 49) IslandO(0, 4); else Island(0, 4);
    if (region == 41) DotO(1); else Dot(1);
    Space(8); Bullet(8); Space(11); Bullet(32);
    E();

    //9
    if (region == 51) IslandO(19, 4); else Island(19, 4);
    if (region == 29) IslandO(8, 2); else Island(8, 2);
    if (region == 24) IslandO(11, 6); else Island(11, 6);
    if (region == 14) IslandO(4, 2); else Island(4, 2);
    if (region == 14) IslandO(3, 11); else Island(3, 11);
    if (region == 49) IslandO(0, 4); else Island(0, 4);
    if (region == 41) DotO(3); else Dot(3);
    Space(7); Bullet(9); Space(1); Bullet(33);
    E();
    
    //10
    if (region == 10) IslandO(17, 3); else Island(17, 3);
    if (region == 51) IslandO(1, 3); else Island(1, 3);
    if (region == 29) IslandO(6, 1); else Island(6, 1);
    if (region == 24) IslandO(11, 7); else Island(11, 7);
    if (region == 24) DotO(1); Dot(1);
    if (region == 14) IslandO(0, 19); else Island(0, 19);
    if (region == 49) IslandO(0, 4); else Island(0, 4);
    if (region == 41) IslandO(3, 4); else Island(3, 4);
    Space(4); Bullet(10); Space(12); Bullet(34);
    E();

    //11
    if (region == 39) DotO(6); else Dot(6);
    Island(7, 1); 
    if (region == 10) IslandO(0, 5); else Island(0, 5);
    if (region == 29) IslandO(0, 1); else Island(0, 1);
    if (region == 29) IslandO(1, 3); else Island(1, 3);
    Dot(6); Island(3, 2); 
    if (region == 24) DotO(2); else Dot(2);
    if (region == 24) IslandO(1, 11); else Island(1, 11);
    if (region == 14) IslandO(0, 17); else Island(0, 17);
    Island(0, 6);
    if (region == 41) IslandO(3, 4); else Island(3, 4);
    Space(3); Bullet(11); Space(15); Bullet(35);
    E();

    //12
    Island(10, 6); 
    if (region == 10) IslandO(0, 3); else  Island(0, 3);
    if (region == 29) IslandO(0, 6); else  Island(0, 6);
    Island(0, 9);
    Dot(1); 
    Island(1, 3);
    if (region == 24) IslandO(0, 11); else Island(0, 11);
    if (region == 14) IslandO(0, 19); else Island(0, 19);
    if (region == 27) IslandO(0, 2); else Island(0, 2);
    if (region == 41) IslandO(8, 3); else Island(8, 3);
    Space(2); Bullet(12); Space(11); Bullet(36);
    E();

    //13
    Island(11, 4); 
    if (region == 35) IslandO(0, 3); else Island(0, 3);
    if (region == 29) IslandO(0, 5); else Island(0, 5);
    if (region == 11) IslandO(0, 11); else Island(0, 11);
    Island(0, 2);
    Island(1, 3);
    if (region == 24) IslandO(0, 11); else Island(0, 11);
    if (region == 14) IslandO(0, 17); else Island(0, 17);
    if (region == 27) IslandO(0, 3); else Island(0, 3);
    Space(14); Bullet(13); Space(11); Bullet(37);
    E();

    //14
    Island(10, 7);
    if (region == 35) IslandO(0, 4); else Island(0, 4);
    Island(0, 1);
    if (region == 29) IslandO(0, 2); else Island(0, 2);
    if (region == 11) IslandO(0, 6); else Island(0, 6);
    Island(0, 10);
    if (region == 24) IslandO(0, 11); else Island(0, 11);
    if (region == 14) IslandO(0, 18); else Island(0, 18);
    if (region == 27) IslandO(0, 1); else Island(0, 1);
    Space(15); Bullet(14); Space(13); Bullet(38);
    E();

    //15
    if (region == 32) IslandO(9, 2); else Island(9, 2);
    if (region == 40) IslandO(0, 2); else Island(0, 2);
    Island(0, 2);
    if (region == 33) IslandO(0, 1); else Island(0, 1);
    if (region == 37) IslandO(0, 2); else Island(0, 2);
    Island(0, 4);
    if (region == 11) IslandO(0, 6); else Island(0, 6);
    Island(0, 12);
    if (region == 24) IslandO(0, 11); else Island(0, 11);
    if (region == 14) IslandO(0, 16); else Island(0, 16);
    if (region == 27) IslandO(0, 3); else Island(0, 3);
    Space(15); Bullet(15); Space(9); Bullet(39);
    E();

    //16
    if (region == 31) IslandO(9, 1); else Island(9, 1);
    Island(0, 5);
    if (region == 33) IslandO(0, 1); else Island(0, 1);
    Island(0, 2);
    if (region == 12) IslandO(0, 3); else  Island(0, 3);
    Island(0, 20);
    if (region == 24) IslandO(0, 10); else Island(0, 10);
    if (region == 38) IslandO(0, 3); else Island(0, 3);
    if (region == 14) IslandO(0, 14); else Island(0, 14);
    if (region == 27) IslandO(0, 2); else Island(0, 2);
    Space(15); Bullet(16); Space(10); Bullet(40);
    E();

    //17
    if (region == 31) IslandO(10, 1); else Island(10, 1);
    if (region == 36) IslandO(0, 1); else Island(0, 1);
    Island(0, 2);
    Island(0, 1);
    if (region == 13) IslandO(0, 2); else Island(0, 2);
    if (region == 21) DotO(0); else Dot(0);
    if (region == 16) IslandO(0, 3); else Island(0, 3);
    Dot(0);
    if (region == 18) DotO(0); else Dot(0);
    Island(0, 17);
    if (region == 24) IslandO(0, 11); else Island(0, 11);
    if (region == 38) IslandO(0, 4); else Island(0, 4);
    if (region == 14) IslandO(0, 2); else Island(0, 2);
    if (region == 38) IslandO(0, 3); else Island(0, 3);
    if (region == 14) IslandO(0, 8); else Island(0, 8);
    if (region == 27) IslandO(0, 8); else Island(0, 8);
    
    Dot(1); 
    Space(7); Bullet(17); Space(15); Bullet(41);
    E();

    //18
    if (region == 36) IslandO(10, 2); else Island(10, 2);
    //Island(0, 1);
    if (region == 34) DotO(0); else Dot(0);
    Island(0, 7);
    if (region == 16) DotO(0); else Dot(0);
    if (region == 2) { 
        IslandO(0, 4); 
        Island(0, 1);
    }
    else Island(0, 5); 
    Island(0, 14);
    if (region == 24) IslandO(0, 11); else Island(0, 11);
    if (region == 38) IslandO(0, 4); else Island(0, 4);
    if (region == 14) DotO(0); else Dot(0);
    Island(0, 3);
    if (region == 3) {
        DotO(0);
        Island(0, 1);
    }
    else Island(0, 2); 
    Island(0, 1); 
    if (region == 28) IslandO(0, 10); else Island(0, 10);
    if (region == 27) IslandO(0, 4); else Island(0, 4);
    Dot(1); 
    Space(7); Bullet(18);
    E();

    //19
    Dot(4); Dot(3); 
    if (region == 34) IslandO(1, 5); else Island(1, 5);
    Island(0, 6);
    if (region == 2) {
        IslandO(0, 3);
        Island(0, 12);
    } else Island(1, 14); 
    Island(0, 7);
    if (region == 24) IslandO(0, 7); else Island(0, 7);
    if (region == 38) IslandO(0, 6); else Island(0, 6);
    if (region == 3) {
        IslandO(0, 4);
        Island(0, 1);
    }
    else Island(0, 5); 
    Island(0, 3); 
    if (region == 28) IslandO(0, 8); else Island(0, 8);
    if (region == 27) IslandO(0, 6); else Island(0, 6);
    Dot(2);
    Space(4); Bullet(19);
    E();

    //20
    if (region == 1 || region == 23) DotO(6); else Dot(6);
    if (region == 9 || region == 23) DotO(0); else Dot(0);
    if (region == 26) IslandO(0, 2); else Island(0, 2);
    Island(0, 1);
    if (region == 8) IslandO(0, 2); else Island(0, 2);
    if (region == 30) DotO(0); else Dot(0);
    Dot(1); Island(2, 4); 
    if (region == 2) DotO(0); else Dot(0);
    Island(0, 20);
    if (region == 24) IslandO(0, 6); else Island(0, 6);
    if (region == 38) IslandO(0, 7); else Island(0, 7);
    if (region == 3) {
        IslandO(0, 4);
        Island(0, 4);
    }
    else Island(0, 8);
    if (region == 28) IslandO(3, 9); else Island(3, 9);
    if (region == 27) IslandO(0, 1); else Island(0, 1);
    Space(8); Bullet(20);
    E();

    //21
    if (region == 7) DotO(7); else Dot(7);
    if (region == 15 || region == 26) DotO(0); else Dot(0);
    if (region == 6 || region == 26) DotO(0); else Dot(0);
    Island(0, 1);
    if (region == 8) DotO(0); else Dot(0);
    if (region == 30) IslandO(0, 2); else Island(0, 2);
    Dot(9); 
    Island(11, 8);
    if (region == 24) IslandO(0, 5); else Island(0, 5);
    if (region == 38) IslandO(0, 8); else Island(0, 8);
    if (region == 3) {
        IslandO(0, 4);
        Island(0, 4);
    }
    else Island(0, 8);
    if (region == 25) IslandO(11, 3); else Island(11, 3);
    Space(7); Bullet(21);
    E();

    //22
    if (region == 20) DotO(9); else Dot(9);
    if (region == 5) IslandO(0, 1); else Island(0, 1);
    Island(25, 5); 
    if (region == 4) {
        IslandO(0, 2);
        Island(0, 1);
    }
    else Island(0, 3);
    if (region == 19 || region == 24) DotO(0); else Dot(0);
    if (region == 17) IslandO(0, 4); else Island(0, 4);
    if (region == 38) IslandO(1, 5); else Island(1, 5);
    if (region == 3) {
        IslandO(0, 2);
        Island(0, 3);
    }
    else Island(0, 5);
    if (region == 25) IslandO(15, 2); else Island(15, 2);
    Space(8); Bullet(22);
    E();

    //23
    if (region == 5) IslandO(9, 2); else Island(9, 2);
    Island(28, 1); 
    if (region == 4) IslandO(0, 4); else Island(0, 4);
    if (region == 17) DotO(0); else Dot(0);
    if (region == 17) IslandO(1, 3); else  Island(1, 3);
    if (region == 3) DotO(7); else Dot(7);
    Space(28); Bullet(23);
    E();
    Dot(51); 
    Space(33); Bullet(24);
    E();
    if (region == -1) {
        cout << "Неизвестный регион\n\n\n";
    } else
    if (region != 0) { 
        cout << "Ваш регион: " << toName(region); 
        if (region == g) {
            cout << "\nПОЗДРАВЛЯЕМ,\nвы угадали!\nВы будете служить ";
            if (region == 33) cout << "во "; else
                if (region == 41) cout << "на "; else cout << "в ";
            switch (region) {
            case 11:
            case 25:
            case 28:
                cout << statesList[region - 1];
                break;
            case 1:
            case 4:
            case 17:
            case 20:
            case 26:
            case 35:
            case 37:
            case 40:
            case 41:
            case 42:
            case 44:
            case 50:
                cout << statesList[region - 1].substr(0, statesList[region - 1].length() - 1) + "е";
                break;
            case 3:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 13:
            case 14:
            case 15:
            case 18:
            case 19:
            case 21:
            case 30:
                cout << statesList[region - 1].substr(0, statesList[region - 1].length() - 1) + "и";
                break;
            case 2:
            case 5:
            case 12:
            case 16:
            case 23:
            case 24:
            case 27:
            case 29:
            case 31:
            case 32:
            case 33:
            case 34:
            case 36:
            case 38:
            case 39:
            case 43:
            case 45:
            case 46:
            case 47:
            case 48:
            case 49:
                cout << statesList[region - 1] + "е";
                break;
            }
            
            cout << ".\n\nВозьмите повестку и проследуйте в военкомат\n\n\n\n\n";
            return;
        }
        else {
            cout << "\nХорошая догадка, но командир думает иначе. Вы будете служить " << Compare(region);
        }
    }
    cout << endl;
    cout << "\nГде вы будете служить? > ";
    cin >> str;
    st = State(str);
    if (st == 22) st = 4;
    attempts[st - 1] = true;
    if (str == "/show") {
        hide = false;
        Draw(0);
    } else if (str == "/hide") {
        hide = true;
        Draw(0);
    } else
    Draw(st);
    return;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    srand(time(0));
    g = (rand() % N) + 1;
    if (g == 22) g = 4;
    for (int i = 0; i < N; i++) attempts[i] = false;
    Draw(0);
    system("pause");
}

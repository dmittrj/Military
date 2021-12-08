#include <iostream>
using namespace std;

string statesList[] = { "Адыгея", "Башкортостан", "Бурятия", "Алтай", "Дагестан", "Ингушетия", "Кабардино-Балкария", "Калмыкия", "Карачаево-Черкесия", "Карелия", 
"Коми", "Марий-Эл", "Мордовия", "Якутия", "Сев.Осетия", "Татарстан", "Тыва", "Удмуртия"};

struct coord {
    int x;
    int y;
};

coord coordsList[] = { {7, 20}, {23, 19}, {58, 20}, {43, 23}, {11, 23}, 
    {10, 21}, {8, 21}, {12, 20}, {8, 20}, {18, 11}, 
    {27, 14}, {20, 16}, {16, 17}, {60, 12}, {9, 21},
    {20, 17}, {47, 22}, {23, 17} };
int g;

void E() {
    cout << endl;
}

void Island(int x, int y) {
    for (int i = 0; i++ < x;) cout << " ";
    for (int i = 0; i++ < y;) cout << "#";
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
    int wgt = coordsList[g - 1].x - coordsList[reg - 1].x;
    int hgt = coordsList[g - 1].y - coordsList[reg - 1].y;
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
    for (int i = 0; i < 14; i++)
        if (s == statesList[i]) return i + 1;
    return -1;
}

void Draw(int region) {
    string str;
    int st;
    system("cls");
    Dot(76); E();
    Dot(69); Island(4, 4); E();
    Island(70, 4); E();
    Island(69, 4); E();
    Island(68, 10); E();

    //6
    Dot(44); 
    if (region == 14) DotO(14); else Dot(14);
    if (region == 14) DotO(5); else Dot(5);
    Island(1, 11); E();

    //7
    Dot(44); 
    Dot(1); 
    if (region == 14) IslandO(9, 2); else Island(9, 2);
    if (region == 14) DotO(1); else Dot(1);
    if (region == 14) IslandO(2, 7); else Island(2, 7);
    Island(0, 9);
    
    E();

    //8
    Island(21, 2); Island(11, 4); Island(8, 4); 
    if (region == 14) IslandO(10, 11); else Island(10, 11);
    Island(0, 4);
    Dot(1); E();

    //9
    Island(19, 4); Island(8, 2); Island(11, 6); 
    if (region == 14) IslandO(4, 2); else Island(4, 2);
    if (region == 14) IslandO(3, 11); else Island(3, 11);
    Island(0, 4);
    Dot(3); E();
    
    //10
    if (region == 10) IslandO(17, 3); else Island(17, 3);
    Island(1, 3); 
    Dot(6); Island(11, 7); 
    Island(1, 1); 
    if (region == 14) IslandO(0, 19); else Island(0, 19);
    Island(0, 4);
    Island(3, 4); E();

    //11
    Dot(6); 
    Island(7, 1); 
    if (region == 10) IslandO(0, 5); else Island(0, 5);
    Island(0, 1);
    Island(1, 3); Dot(6); Island(3, 2); Dot(2); 
    Island(1, 11); 
    if (region == 14) IslandO(0, 17); else Island(0, 17);
    Island(0, 6);
    Island(3, 4); E();

    //12
    Island(10, 6); 
    if (region == 10) IslandO(0, 3); else  Island(0, 3);
    Island(0, 15);
    Dot(1); 
    Island(1, 14); 
    if (region == 14) IslandO(0, 19); else Island(0, 19);
    Island(0, 2);
    Island(8, 3); E();

    //13
    Island(11, 12); 
    if (region == 11) IslandO(0, 11); else Island(0, 11);
    Island(0, 2);
    Island(1, 14); 
    if (region == 14) IslandO(0, 17); else Island(0, 17);
    Island(0, 3);
    E();

    //14
    Island(10, 14);
    if (region == 11) IslandO(0, 6); else Island(0, 6);
    Island(0, 21);
    if (region == 14) IslandO(0, 18); else Island(0, 18);
    Island(0, 1);
    E();

    //15
    Island(9, 13); 
    if (region == 11) IslandO(0, 6); else Island(0, 6);
    Island(0, 23);
    if (region == 14) IslandO(0, 16); else Island(0, 16);
    Island(0, 3);
    E();

    //16
    Island(9, 9); 
    if (region == 12) IslandO(0, 3); else  Island(0, 3);
    Island(0, 33);
    if (region == 14) IslandO(0, 14); else Island(0, 14);
    Island(0, 2);
    E();

    //17
    Island(10, 5); 
    if (region == 13) IslandO(0, 2); else Island(0, 2);
    Dot(0);
    if (region == 16) IslandO(0, 3); else Island(0, 3);
    Dot(0);
    if (region == 18) DotO(0); else Dot(0);
    Island(0, 32);
    if (region == 14) IslandO(0, 2); else Island(0, 2);
    Island(0, 3);
    if (region == 14) IslandO(0, 8); else Island(0, 8);
    Island(0, 8);
    
    Dot(1); E();

    //18
    Island(10, 10); 
    if (region == 16) DotO(0); else Dot(0);
    if (region == 2) { 
        IslandO(0, 4); 
        Island(0, 10);
    }
    else Island(0, 5); 
    Island(0, 29);
    if (region == 14) DotO(0); else Dot(0);
    Island(0, 3);
    if (region == 3) {
        DotO(0);
        Island(0, 10);
    }
    else Island(0, 11); 
    Island(0, 6); 
    Dot(1); E();

    //19
    Dot(4); Dot(3); 
    Island(1, 11);
    if (region == 2) {
        IslandO(0, 3);
        Island(0, 26);
    } else Island(1, 34); 
    if (region == 3) {
        IslandO(0, 4);
        Island(0, 18);
    }
    else Island(0, 22); Dot(2); E();

    //20
    if (region == 1) DotO(6); else Dot(6);
    if (region == 9) DotO(0); else Dot(0);
    Island(0, 3); 
    if (region == 8) IslandO(0, 2); else Island(0, 2);
    Dot(0);
    Dot(1); Island(2, 4); 
    if (region == 2) DotO(0); else Dot(0);
    Island(0, 33);
    if (region == 3) {
        IslandO(0, 4);
        Island(0, 4);
    }
    else Island(0, 8);
    Island(3, 10); E();

    //21
    if (region == 7) DotO(7); else Dot(7);
    if (region == 15) DotO(0); else Dot(0);
    if (region == 6) DotO(0); else Dot(0);
    Island(0, 1);
    if (region == 8) DotO(0); else Dot(0);
    Island(0, 2);
    Dot(9); 
    Island(11, 21); 
    if (region == 3) {
        IslandO(0, 4);
        Island(0, 4);
    }
    else Island(0, 8);
    Island(11, 3); E();

    //22
    Island(9, 1); 
    if (region == 5) IslandO(0, 1); else Island(0, 1);
    Island(25, 5); 
    if (region == 4) {
        IslandO(0, 2);
        Island(0, 1);
    }
    else Island(0, 3);
    Dot(0);
    if (region == 17) IslandO(0, 4); else Island(0, 4);
    Island(1, 5); 
    if (region == 3) {
        IslandO(0, 2);
        Island(0, 3);
    }
    else Island(0, 5);
    Island(15, 2); E();

    //23
    if (region == 5) IslandO(9, 2); else Island(9, 2);
    Island(28, 1); 
    if (region == 4) IslandO(0, 4); else Island(0, 4);
    if (region == 17) DotO(0); else Dot(0);
    if (region == 17) IslandO(1, 3); else  Island(1, 3);
    if (region == 3) DotO(7); else Dot(7);
    E();
    Dot(51); E();
    if (region != 0) { 
        cout << "Ваш регион: " << toName(region); 
        if (region == g) {
            cout << "\nПОЗДРАВЛЯЕМ,\nвы угадали!\nВы будете служить ";
            cout << "в ";
            cout << statesList[region - 1];
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
    Draw(st);
    return;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    srand(time(0));
    g = (rand() % 17) + 1;
    Draw(0);
}

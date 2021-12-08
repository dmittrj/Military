#include <iostream>
using namespace std;

string statesList[] = { "Адыгея", "Башкортостан", "Бурятия", "Алтай", "Дагестан", "Ингушетия", "Кабардино-Балкария", "Калмыкия", "Карачаево-Черкесия", "Карелия", 
"Коми", "Марий-Эл", "Мордовия", "Якутия"};

struct coord {
    int x;
    int y;
};

coord coordsList[] = { {7, 20}, {23, 19}, {58, 20}, {43, 23}, {11, 23}, 
    {10, 21}, {8, 21}, {12, 20}, {8, 20}, {18, 11} };
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
    if (wgt > 0 && hgt > 0) {
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
    Dot(44); Dot(14); Dot(5); Island(1, 11); E();
    Dot(44); Dot(1); Island(9, 2); Dot(1); Island(2, 16); E();
    Island(21, 2); Island(11, 4); Island(8, 4); Island(10, 15); Dot(1); E();
    Island(19, 4); Island(8, 2); Island(11, 6); Island(4, 2); Island(3, 15); Dot(3); E();
    
    //10
    if (region == 10) IslandO(17, 3); else Island(17, 3);
    Island(1, 3); 
    Dot(6); Island(11, 7); Island(1, 24); Island(3, 4); E();

    //11
    Dot(6); 
    Island(7, 1); 
    if (region == 10) IslandO(0, 5); else Island(0, 5);
    Island(0, 1);
    Island(1, 3); Dot(6); Island(3, 2); Dot(2); Island(1, 34); Island(3, 4); E();

    //12
    Island(10, 6); 
    if (region == 10) IslandO(0, 3); else  Island(0, 3);
    Island(0, 15);
    Dot(1); Island(1, 35); Island(8, 3); E();
    Island(11, 25); Island(1, 34); E();
    Island(10, 60); E();
    for (int i = 0; i++ < 2;) { Island(9, 61); E(); }
    Island(10, 66); Dot(1); E();
    //18
    Island(10, 11); 
    if (region == 2) { 
        IslandO(0, 4); 
        Island(0, 43);
    }
    else Island(0, 38); 
    if (region == 3) {
        DotO(0);
        Island(0, 16);
    }
    else Island(0, 17); Dot(1); E();

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
        Island(0, 6);
    }
    else Island(0, 8);
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
    Island(0, 1);
    Island(1, 3); 
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
    g = (rand() % 10) + 1;
    Draw(0);
}

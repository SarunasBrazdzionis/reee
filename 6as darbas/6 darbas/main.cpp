#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <array>
#include <fstream>
using namespace std;

struct knyga
{
    string Pavadinimas = "";
    string Autorius = "";
    int puslapiuSkaicius =0;
    int leidybosMetai = 0;
};

void teigiamas(int *x);

///3
int seniausiaiIsleistaKnyga(knyga *passBook, int sz);
int daugiausiaiPuslapiu(knyga *passBook, int sz);
void arTiePatysAutoriai(knyga *passBook, int sz);
int main()
{
    ///rand default set
        srand (time(NULL));
    int uzduotiesID = 0;
    int useless = 0;

    while(uzduotiesID != -1)
    {
        system("CLS");
        cout << "kuri uzduotis(1-3): ";
        cin >> uzduotiesID;
        switch(uzduotiesID)
        {
            default:
                cout << "Parinktas neteisingas variantas, programa baigia darba" << endl;
                uzduotiesID = -1;

            break;

            case 1: {                                             /// 1-oji uzduotis O_o
                int internalID = 0;
                while(internalID == 0)
                {
                    system("cls");
                    cout << "1. uzduotis" << endl;
                    cout << "a: sukurkite 2 sveikojo tipo kintamuosius" << endl;
                    cout << "b: sukurkite rodykle, kuri saugotu 1-ojo kintamojo adresa" << endl;
                    cout << "c: naudodami sukurta rodykle, priskirti pirmaji kintamaji = 99" << endl;
                    cout << "d: atspauzdinti pirmaji kintamaji dvejais budais" << endl;
                    cout << "e: nustatykite pirmaja rodykle antrajam kintamajam ir jam priskirti reiksme -300" << endl;
                    cout << "f: sukurti laikina sveiko tipo kintamaji ir antraja rodykle" << endl;
                    cout << "g: naudodamiesi laikinuoju kintamuoju, apkeiskite pirmojo ir antrojo kintamojo reiksmes" << endl;
                    cout << "h: sukurti void tipo funkcija iskvietus sveikojo tipo rodykle ir joje turi buti nustatytas ar kintamasis teigiamas, isveda rezultata, jei kintamasis neigiamas, jam priskirti 0 reiksme." << endl;
                    cout << "i: naudojant antraja rodykle, isspauzdinti 1 ir 2 kintamuosius" << endl;
                    cout << endl << endl;
                    ///a
                        int kintamasis1, kintamasis2;
                        cout << "a: kintamasis1: " << kintamasis1 << "  kintamasis2: " << kintamasis2 << endl;
                    ///b
                        int* rodiklis1 = &kintamasis1;
                        cout << "b: " << rodiklis1 << endl;
                    ///c
                        *rodiklis1 = 99;
                        cout << "c: kintamasis1: " << kintamasis1 << endl;
                    ///d
                        cout << "d: rodykle " << *rodiklis1 << " kintamasis1 " << kintamasis1 << endl;
                    ///e
                        rodiklis1 = &kintamasis2;
                        *rodiklis1 = -300;
                        cout << "e: " << rodiklis1 << " " << *rodiklis1 << endl;
                    ///f
                        int temp;
                        int *rodiklis2;
                        cout << "f: temp: " << temp << "  rodiklis: " << rodiklis2 << endl;
                    ///g
                        rodiklis1 = &kintamasis1;
                        rodiklis2 = &kintamasis2;
                        temp = *rodiklis1;
                        *rodiklis1 = *rodiklis2;
                        *rodiklis2 = temp;
                        cout << "g: kintamasis1: " << kintamasis1 << " kintamasis2: " << kintamasis2 << endl;
                    ///h
                        cout << "h: " << endl;
                        teigiamas(&kintamasis1);
                        teigiamas(&kintamasis2);
                        cout << kintamasis1 << " " << kintamasis2 << endl;
                    ///i
                        cout << "i: ";
                        rodiklis2 = &kintamasis1;
                        cout << *rodiklis2 << " ";
                        rodiklis2 = &kintamasis2;
                        cout << *rodiklis2 << endl;
                    cin >> internalID;

                    delete rodiklis1;
                    delete rodiklis2;
                }

            }break;

            case 2: {
                int loop = 0;
                while (loop == 0){
                    system("CLS");
                    cout << "2. uzduotis" << endl;
                    cout << "masyvo dydis: ";
                    int arraySize;
                    cin >> arraySize;
                    ///A
                        cout << "dinaminio masyvo sukurimas: " << endl;
                        int* array = new int[arraySize];
                        cout << &array << endl;
                    ///B
                        cout << "dinaminio masyvo spauzdinimas: " << endl;
                        for(int i = 0; i < arraySize; i++)
                        {

                            array[i] = rand() % 10+1;
                            cout << array[i] << " ";
                        }
                        cout << endl;
                    ///C
                        int suma = 0;
                        cout << " c: " << endl;
                        for(int i = 0; i < arraySize; i+= 2)
                        {
                            cout << suma << " + " << array[i] << " = ";
                            suma += (array[i]);
                            cout << suma <<endl;
                        }
                    ///D
                        for(int i = 0; i < arraySize; i++)
                        {
                            for(int x = 0; x < arraySize; x++)
                            {
                                if(array[i] <= array[x])
                                {
                                    if(i!=x)
                                    {
                                        int tmp = array[i];
                                        array[i] = array[x];
                                        array[x] = tmp;
                                    }
                                }
                            }
                        }
                        for(int i = 0; i < arraySize; i++)
                            cout << array[i] << " ";

                    ///baigta
                    delete[] array;
                    cin >> loop;
                }



            }break;

            case 3:{
                int testi = 0;
                while(testi == 0)
                {
                    cout << "3. uzduotis" << endl;
                    int sizeOfStruct = 0;
                    ///randa dydi
                        string temp1;
                        string temp2;
                        int temp3;
                        int temp4;

                        ifstream temp("./knygos/knygos.txt");
                        while(temp >> temp1 && temp >>temp2 && temp >> temp3 && temp >> temp4)
                        {
                            sizeOfStruct++;
                        }
                        temp.close();
                        cout << "aprasyta knygu: " <<sizeOfStruct << endl;

                    ///
                        knyga *knygos = new knyga[sizeOfStruct];
                        ifstream duomenys("./knygos/knygos.txt");
                        cout << "knygos "<< endl;
                        for(int i = 0; i < sizeOfStruct; i++)
                        {
                            duomenys >>knygos[i].Pavadinimas
                                     >>knygos[i].Autorius
                                     >>knygos[i].puslapiuSkaicius
                                     >>knygos[i].leidybosMetai;
                            cout << i+1 << "-a knyga" << endl;
                            cout << "Pavadinimas " << knygos[i].Pavadinimas << endl;
                            cout << "Autorius " << knygos[i].Autorius << endl;
                            cout << "pslSkaicius " << knygos[i].puslapiuSkaicius << endl;
                            cout << "isleidimo metai " <<knygos[i].leidybosMetai << endl << endl << endl;
                        }
                    ///A
                        int seniausiaInt = 0;
                        cout << seniausiaiIsleistaKnyga(knygos, sizeOfStruct)+1 << "-oji knyga yra parasyra anksciausiai: " << knygos[seniausiaiIsleistaKnyga(knygos, sizeOfStruct)].leidybosMetai << " metais";
                        cout << endl;
                    ///B
                        int didziausia = 0;
                        cout << daugiausiaiPuslapiu(knygos, sizeOfStruct)+1 << "-oji knyga turi daugiausiai puslapiu: " << knygos[daugiausiaiPuslapiu(knygos, sizeOfStruct)].puslapiuSkaicius << " - puslapiai" << endl;
                    ///C
                        arTiePatysAutoriai(knygos, sizeOfStruct);


                    delete[] knygos;
                    cin >> testi;
                }

            }break;

            case 4:
                {
                    ofstream knyguDuom("./knygos/knygos.txt");
                    cout << "kiek knygu norite aprasyti(note knygos bus perrasytos)" << endl;
                    int kiekis;
                    cin >> kiekis;
                    for(int i = 0; i < kiekis; i++)
                    {
                        string KnygosPav= "";
                        string Autorius = "";
                        int puslapiai= 0;
                        int leidybosMetai = 0;

                        cout << "knygosPav: ";
                        cin >> KnygosPav;

                        cout << "Autorius: ";
                        cin >> Autorius;

                        cout << "puslapiai: ";
                        cin >> puslapiai;

                        cout << "leidybosMetai ";
                        cin >> leidybosMetai;


                        knyguDuom << KnygosPav << " ";
                        knyguDuom << Autorius << " ";
                        knyguDuom << puslapiai << " ";
                        knyguDuom << leidybosMetai << endl;

                    }
                    knyguDuom.close();
                }break;
        }

    }

    return 0;
}

void teigiamas(int *x)
{
    if(*x >0)
        cout << "Teigiamas: " << *x << endl;
    else
    {
        cout << "Neigiamas: " << *x << endl;
        *x =0;
    }
}

///3

int seniausiaiIsleistaKnyga(knyga *passBook, int sz)
{
    int integer = 0;
    for(int i = 0; i < sz; i++)
    {
        if(i!=integer)
        {
            if(passBook[i].leidybosMetai < passBook[integer].leidybosMetai)
                integer = i;
        }
    }
    return integer;
}

int daugiausiaiPuslapiu(knyga *passBook, int sz)
{
    int integer = 0;
    for(int i = 0; i < sz; i++)
    {
        if(i!=integer)
        {
            if(passBook[i].puslapiuSkaicius > passBook[integer].puslapiuSkaicius)
                integer = i;
        }
    }
    return integer;
}

void arTiePatysAutoriai(knyga *passBook, int sz)
{
    bool **autoriai = new bool*[sz];
    ///array -false
    for(int i = 0; i < sz; i++)
    {
        autoriai[i] = new bool[sz];
        for(int x = 0; x < sz; x++)
        {
            autoriai[i][x] = false;
        }
    }

    for(int i = 0; i < sz; i++)
    {
        for(int x = 0; x < sz; x++)
        {
            if(i!=x)
            {
                if(passBook[i].Autorius == passBook[x].Autorius)
                {
                    autoriai[i][x] = true;
                }
            }
        }
    }
    bool reee[sz];
    for(int i = 0; i < sz; i++)
    {
        reee[i] = false;

    }
    for(int i = 0; i < sz; i++)
    {
        for(int x = 0; x < sz; x++)
        {
            if(autoriai[i][x])
            {
                reee[i] = true;
            }
        }
    }
    bool reeee = false;

    for(int i = 0; i < sz; i++)
    {
        if(reee[i])
            reeee = true;
    }

    if(reeee)
    {
        cout << "autoriai kurie parase 2+ knygas: ";
        for(int i = 0; i < sz; i++)
        {
            if(reee[i])
            {
                cout << passBook[i].Autorius << " Parase knygas: " << endl;
                for(int x = 0; x < sz; x++)
                {
                    if(passBook[i].Autorius == passBook[x].Autorius)
                        cout << passBook[x].Pavadinimas << endl;
                }
                cout << endl;
            }
        }
    }else
    {
        cout << "nei vienas autorius neparase 2+ knygu" << endl;
    }

    for(int i = 0; i < sz; i++)
        delete[] autoriai[i];

    delete[] autoriai;



}

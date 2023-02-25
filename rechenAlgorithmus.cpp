#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>
#include "strtk.hpp"

enum Rechenoperatoren
{
    toThePowerOF,
    wurzel,
    modulo,
    geteilt,
    mal,
    plus,
    minus,
};

std::vector<double> vRechnung;

std::string sOperator = "^w%/*+-";

std::string rechnen()
{
    double zahl1 = 0;
    double zahl2 = 0;
    double zwischenErgebnis = 0;

    while (vRechnung.size() > 1)
    {
        for (int iOperator = toThePowerOF; iOperator <= minus; iOperator ++)
        {
            for (int vRechnungStelle = 1; vRechnungStelle < vRechnung.size(); vRechnungStelle += 2)
            {
                if ((int)vRechnung[vRechnungStelle] == iOperator)
                {
                    zahl1 = vRechnung[vRechnungStelle - 1];
                    zahl2 = vRechnung[vRechnungStelle +1];

                    if (iOperator == plus)
                    {
                        zwischenErgebnis = zahl1+zahl2;
                    }

                    else if (iOperator == minus)
                    {
                        zwischenErgebnis = zahl1-zahl2;
                    }

                    else if (iOperator == mal)
                    {
                        zwischenErgebnis = zahl1*zahl2;
                    }

                    else if (iOperator == geteilt)
                    {
                        if (zahl2 == 0) return("Nan");
                        zwischenErgebnis = zahl1/zahl2;
                    }
                    else if (iOperator == toThePowerOF)
                    {
                        //for (int i = 0; i < zahl2; i++) zwischenErgebnis = zahl1 * zahl1;
                        zwischenErgebnis = (pow(zahl1, zahl2));
                        std::string temp = std::to_string(zwischenErgebnis);
                        if (temp.find_first_not_of("0123456789,") != std::string::npos) return ("NaN");
                    }
                    else if (iOperator == wurzel)
                    {
                        zwischenErgebnis = std::sqrt(zahl2);
                    }
                    else if (iOperator == modulo)
                    {
                        zwischenErgebnis = zahl1/zahl2;
                        zwischenErgebnis = zahl1 - (int)zwischenErgebnis * zahl2;
                    }
                    vRechnung.erase(vRechnung.begin() + vRechnungStelle, vRechnung.begin() + vRechnungStelle + 2);
                    vRechnung[vRechnungStelle - 1] = zwischenErgebnis;
                    vRechnungStelle -= 2;
                    if (vRechnung.size() == 1) break;
                }
            }
        }
    }
    if (vRechnung[0] < 0) return "[" + strtk::type_to_string<double>(vRechnung[0]) + "]";
    return strtk::type_to_string<double>(vRechnung[0]);
}


void rechnungZuVektor(std::string teilrechnung)
{
    int zahlOperatorEnde;
    int iOperator = 0;
    vRechnung.clear();
    while (teilrechnung.find_first_of("^w%/*+-") != std::string::npos) //Wenn sich keine Rechenoperatoren mehr in der Rechnung befinden,wird die while-Schleife verlassen
    {
        if (teilrechnung[0] == '[')
        {
            zahlOperatorEnde = teilrechnung.find_first_of("]") + 1;
            vRechnung.push_back(std::stod(teilrechnung.substr(1, zahlOperatorEnde - 2)));
            teilrechnung.erase(0, zahlOperatorEnde);
        }
        if (teilrechnung.empty()) break;
        zahlOperatorEnde = teilrechnung.find_first_of("^w%/*+-"); //Hier wird das erste Vorkommen eines Rechenzeichens gesucht
        iOperator = sOperator.find(teilrechnung[zahlOperatorEnde]); //Hier wird dem int iOperator die Position des vorkommens des gefundenen Rechenzeichens in sOperator zugewiesen.

        //Dann werden Zahl und Rechenzeichen getrennt in einen Vektor gepusht

        //if (zahlOperatorEnde == 0) //Wenn das erste Zeichen ein Rechenzeichen ist, wird die stelle im Vektor davor mit einer 0 aufgefüllt. Aber nur, wenn noch nichts drinsteht
        //{
        //    vRechnung.push_back(0);
        //    vRechnung.push_back(iOperator);
        //}
        //else //Wenn das erste Zeichen kein Rechenzeichen ist, wird alles, was sich davor befindet als double in den Vektor gepusht und danach das Rechenzeichen
        //{
        if ((vRechnung.empty() || vRechnung.size() % 2 == 0) && zahlOperatorEnde == 0) vRechnung.push_back(0);
        if (zahlOperatorEnde != 0) vRechnung.push_back(std::stod(teilrechnung.substr(0, zahlOperatorEnde)));
        vRechnung.push_back(iOperator);
        //}
        teilrechnung.erase(0, zahlOperatorEnde + 1);
    }
    if (!teilrechnung.empty()) vRechnung.push_back(std::stod(teilrechnung)); // Wenn es keine Rechenzeichen mehr gibt, wird der gesamte Rest als double in den Vektor gepusht
}

std::string rechenAlgorithmus(std::string rechnung)
{
    int rechenende = 0;
    int rechenanfang = 0;
    int klammern = 0;
    int insertAnfang = 0;
    //int vorzeichenZahlEnde = 0;
    if (rechnung.find_last_of("^w%/*+-") == rechnung.length() - 1) rechnung.pop_back();

    if(rechnung[0] == '-')
    {
        rechnung.erase(0, 1);
        rechnung.insert(insertAnfang, "([-1]*");
        if(rechnung[6] == 'w' && rechnung[7] == '(')
        {
            rechnung.insert(rechnung.substr(8).find_first_of(')') + 8, ")");
        }
        else if (rechnung.substr(6).find_first_of("^%/*+-)") == std::string::npos) rechnung.insert(rechnung.size(), ")");

        else rechnung.insert(rechnung.substr(6).find_first_of("^%/*+-)") + 6, ")");
    }

    for (int i = 0; i < rechnung.length(); i++) // - Vorzeichen sollen durch ([-1]*AUSDRUCK) ersetzt werden
    {
        if (rechnung.substr(i, rechnung.length() - i).find("(-") != std::string::npos)
        {
            bool wurzelklammer = false;
            insertAnfang = rechnung.substr(i).find("(-") + 1 + i;
            rechnung.erase(insertAnfang, 1);
            rechnung.insert(insertAnfang, "([-1]*");
            if(rechnung[insertAnfang + 6] == 'w' && rechnung[insertAnfang + 7] == '(')
            {
                    rechnung.insert(rechnung.substr(insertAnfang + 8).find_first_of(')') + insertAnfang + 8, ")");
            }
            else rechnung.insert(rechnung.substr(insertAnfang + 6).find_first_of("^%/*+-)") + insertAnfang + 6, ")");
        }
    }

    while (rechnung[0] != '[' && rechnung.find_first_of("^w%/*+-") != std::string::npos || rechnung[0] == '[' && rechnung.substr(2, rechnung.size() -2).find_first_of("^w%/*+-") != std::string::npos) //Die while-Schleife wird verlassen sobals sich keine Rechenoperatoren mehr in dem String rechnung befinden.
    {
        if (rechnung.find("(") != std::string::npos)
        {
            rechenende = rechnung.find_first_of(")") - 1; //Hier wird das Vorkommen der ersten geschlossen Klammer gesucht und dem Wert rechenende zugewiesen. Das wird gemacht, um die innerste Rechenaufgabe zu finden.
            rechenanfang = rechnung.substr(0, rechenende).find_last_of("(") + 1; // rechenanfang, also der anfang der innersten Rechnung ist die letzte geöffnete Klammer vor der geschlossenen,die davor gefunden wurde.
            klammern = 1;
        }
        else
        {
            rechenende = rechnung.size() -1; //Andernfalls wird einfach alles zur rechnung deklariert
            rechenanfang = 0;
            klammern = 0;
        }
        rechnungZuVektor(rechnung.substr(rechenanfang, rechenende - rechenanfang + 1)); //Hier wird die funktion rechnungZuVektor mit der eben ermittelten Gleichung aufgerufen
        rechnung.erase(rechenanfang - klammern, rechenende - rechenanfang + 1 + 2 * klammern);
        rechnung.insert(rechenanfang - klammern, rechnen());
    }
    if (rechnung[0] == '[')
    {
        rechnung.erase(rechnung.begin(), rechnung.begin() + 1);
        rechnung.pop_back();
    }
    rechnung.pop_back();
    if (rechnung.substr(rechnung.find(",")).length() == 15)
    {
        //if (rechnung.size() > 3 && int(rechnung[rechnung.size() - 1])  >= 53 && rechnung[rechnung.size() - 2] < 57) rechnung[rechnung.size() - 2] += 1;
        //rechnung.pop_back();
        if (int(rechnung[rechnung.size() - 1] == 57))
        {
            while (int(rechnung[rechnung.size() - 1] == 57) && rechnung[rechnung.size() - 2] != ',')
            {
                rechnung.pop_back();
            }
            rechnung[rechnung.size() - 1] += 1;
        }

        if (rechnung[rechnung.size() - 1] == ',') //','
        {
            rechnung.pop_back();
            for (int i = rechnung.size() - 1; i > 0; i--)
            {
                if (int(rechnung[i]) < 57)
                {
                    rechnung[0] += 1;
                    break;
                }
            }
        }

        for (int i = rechnung.length() - 1; i >= 0; i--)
        {
            if (rechnung[i] == '0') rechnung.pop_back();

            else if (rechnung[i] == ',')
            {
                rechnung.pop_back();
                break;
            }

            else break;
        }
    }
    return rechnung; //.substr(rechenanfang, rechenende + 1 - rechenanfang);
}

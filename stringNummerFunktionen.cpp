#include <iostream>

std::string Runden(std::string rechnung)
{
    if (rechnung.find(",") != std::string::npos && rechnung.substr(rechnung.find(",") + 1).length() >= 16) rechnung.pop_back();

    if (int(rechnung[rechnung.size() - 1] == 57))
    {
        while (int(rechnung[rechnung.size() - 1]) == 57)
        {
            rechnung.pop_back();
        }
        if (rechnung[rechnung.size() - 1] != ',') rechnung[rechnung.size() - 1] += 1;
    }

    if (rechnung[rechnung.size() - 1] == ',') //','
    {
        rechnung.pop_back();
        for (int i = rechnung.size() - 1; i >= 0; i--)
        {
            if (int(rechnung[i]) < 57)
            {
                rechnung[i] += 1;
                break;
            }

            if (int(rechnung[i]) == 57)
            {
                rechnung[i] = '0';
            }

            if (i == 0 && int(rechnung[i]) == 48) rechnung.insert(0, "1");
        }
    }

    return rechnung;
}

std::string KlammernLöschen(std::string rechnung)
{
    while (rechnung[0] == '(')
    {
        rechnung.erase(rechnung.begin(), rechnung.begin() + 1);
        rechnung.pop_back();
    }


    if (rechnung[0] == '[')
    {
        rechnung.erase(rechnung.begin(), rechnung.begin() + 1);
        rechnung.pop_back();
    }
    return rechnung;
}

std::string NullenLöschen(std::string rechnung)
{
    while (rechnung[0] == '0' && rechnung[1] != ',' && rechnung.size() > 1)
    {
        rechnung.erase(rechnung.begin(), rechnung.begin() + 1);
    }

    if (rechnung.find(",") != std::string::npos)
    {
        while (rechnung[rechnung.size() - 1] == '0')
        {
            rechnung.pop_back();
        }
        if (rechnung[rechnung.size() - 1] == ',') rechnung.pop_back();
    }
    return rechnung;
}

std::string PunkteFormatierung(std::string rechnung)
{
    int minusVorhanden = 0;
    int punkteInsertAnfang = rechnung.find(",");
    if (punkteInsertAnfang == std::string::npos) punkteInsertAnfang = rechnung.length();
    if (rechnung[0] == '-') minusVorhanden = 1;

    for (int i = rechnung.substr(0 , punkteInsertAnfang).length() -3; i > minusVorhanden; i -= 3)
    {
        rechnung.insert(i, ".");
    }
    return rechnung;
}

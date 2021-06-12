// Copyright 2021 DBarinov
#include "textgen.h"

void TextGenerator::CreateTable(std::string text)
{
    int i = 0, pos = 0, count = -1;
    while (text[i] != '\0')
    {
        if (pos == 0 && text[i] != ' ' && text[i] != '\r' && text[i] != '\n')
        {
            pos = 1;
            count++;
            words.push_back("");
            words[count] = words[count] + text[i];
        }
        else if (pos == 1 && (text[i] == ' ' || text[i] == '\r' || text[i] == '\n'))
        {
            pos = 0;
        }
        else if (pos == 1 && text[i] != ' ' && text[i] != '\r' && text[i] != '\n')
        {
            words[count] = words[count] + text[i];
        }
        i++;
    }
    for (int i = 0; i < words.size() - NPREF + 1; i++)
    {
        prefix prf;
        for (int j = 0; j < NPREF; j++)
            prf.push_back(words[i + j]);
        if (i + NPREF < words.size())
            postab[prf].push_back(words[i + NPREF]);
        else postab[prf].push_back("END_OF_FILE");
    }
}
std::string TextGenerator::newText()
{
    prefix str;
    for (int i = 0; i < NPREF; i++)
        str.push_back(words[i]);
    std::string result = "";
    int count = 1;
    while (result.size() < MAXGEN)
    {
        if (result.size() == 0)
        {
            for (int i = 0; i < NPREF; i++)
                result = result + str[i] + ' ';
        }
        int ran_;
        if (postab[str].size() == 1 && postab[str][0] == "END_OF_FILE")
            break;
        if (postab[str].size() == 0)
            break;
        ran_ = rand() % postab[str].size();
        if (postab[str][postab[str].size() - 1] == "END_OF_FILE")
            ran_ = rand() % (postab[str].size() - 1);
        result = result + postab[str][ran_] + ' ';
        if (count * 100 - result.size() < 0 || count * 100 - result.size() > 100)
        {
            count++;
            result = result + '\n';
        }
        std::string tmp = postab[str][ran_];
        for (int i = 0; i < NPREF - 1; i++) str[i] = str[i + 1];
        str[NPREF - 1] = tmp;
    }
    return result;
}
std::string TextGenerator::fileInput(std::string filename) {
    std::string world;
    std::string text = "";
    std::ifstream OriginText(filename);
    if (OriginText.is_open())
    {
        while (!OriginText.eof())
        {
            OriginText >> world;
            text = text + world + ' ';
        }
    }
    OriginText.close();
    return text;
}
void TextGenerator::fileOutput(std::string output) {
    std::ofstream out;
    out.open("output.txt");
    if (out.is_open())
    {
        out << output;
    }
    out.close();
}
TextGenerator::TextGenerator(std::map<prefix, std::vector<std::string> > val,
    std::vector<std::string> word)
{
    postab = val;
    words = word;
}
TextGenerator::TextGenerator() {
    this->words;
    this->postab;
}

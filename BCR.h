#ifndef BCR_H
#define BCR_H
#include <string>
#include <vector>
#include <fstream>

struct Prod{
    int cena;
    std::string nazwa;
};

class BCR
{
    public:
        BCR(std::string name="default.txt");
        virtual ~BCR();
        void setFile(std::string name);
        void dumpFile();
        void dumpPriceList();

    protected:

    private:
        std::string name;
        std::vector<std::string> line;
        void clear();
        void readFile();
        std::vector<Prod> produkt;
        void decode();
};

#endif // BCR_H

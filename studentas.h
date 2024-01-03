#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include <string>
#include <vector>

class Studentas {
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> tarpiniai_rezultatai;
    int egzamino_rezultatas;

public:
    // Konstruktorius
    Studentas(std::string v, std::string p, std::vector<int> tr, int er)
        : vardas(v), pavarde(p), tarpiniai_rezultatai(tr), egzamino_rezultatas(er) {}

    // Get metodai
    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
    int getEgzaminoRezultatas() const { return egzamino_rezultatas; }
    std::vector<int>& getTarpiniaiRezultatai() { return tarpiniai_rezultatai; }
    Studentas() {}
    // Kitos funkcijos
    double skaiciuotiGalutiniBala(const std::string& tipas) const;
    void setEgzaminoRezultatas(int rez) {this->egzamino_rezultatas= rez;}
    void padalintiStudentusIFailus(const std::vector<Studentas>& studentai, const std::string& failasVargsiukai, const std::string& failasLyderiai);
    double skaiciuotiGalutiniBala(const Studentas& studentas, const char tipas[]);
};

void dalinimoBudas1(std::vector<Studentas>&, std::vector<Studentas>&, std::vector<Studentas>&, const std::string&);
void dalinimoBudas2(std::vector<Studentas>&, std::vector<Studentas>&, const std::string&);
void ivestiDuomenisRanka(std::vector<Studentas>& studentai);
void skaitytiDuomenisIsFailo(std::vector<Studentas>& studentai, const std::string& failoPavadinimas);
void generuotiDuomenis(std::vector<Studentas>& studentai);
void generuotiFailus();
void padalintiStudentusIFailus(const std::vector<Studentas>& studentai, const std::string& failasVargsiukai, const std::string& failasLyderiai);
double skaiciuotiGalutiniBala(const Studentas& studentas, const std::string& tipas);

#endif

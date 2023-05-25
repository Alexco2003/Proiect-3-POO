#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include <typeinfo>
#include <limits>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <type_traits>
#include <random>
#include <windows.h>
#include <stdio.h>
#include <algorithm>
#include <cctype>

using namespace std;

int cnt255=0;

void clearScreen()
{
    system("CLS");
}

void pauza(int secunde)
{
    this_thread::sleep_for(chrono::seconds(secunde));
}

void displayMeniuPrincipal()
{
    cout<<"---Catalog Online---" << endl;
    cout << "\n1-Meniu Utilizator";
    cout << "\n2-Meniu Admin";
    cout << "\n3-Stop";
    cout << endl;

}
void displayMeniuAdmin()
{

    cout << "---Meniu Admin---" << endl << endl;
    cout << "Introduceti Parola: ";
}

void displaySubMeniuAdmin()
{

    cout << "---Meniu Admin---" << endl << endl;
    cout << "1-Adauga Student" << endl;
    cout << "2-Adauga Student International" << endl;
    cout << "3-Adauga Catalog" << endl;
    cout << "4-Adauga Catalog International" << endl;
    cout << "5-Vezi Lista de Studenti" << endl;
    cout << "6-Vezi Lista de Studenti Internationali" << endl;
    cout << "7-Vezi Lista de Cataloage" << endl;
    cout << "8-Vezi Lista de Cataloage Internationale" << endl;
    cout << "9-Sterge Student" << endl;
    cout << "10-Sterge Student International" << endl;
    cout << "11-Sterge Catalog" << endl;
    cout << "12-Sterge Catalog International" << endl;
    cout << "13-Adauga Nota Student" << endl;
    cout << "14-Sterge Nota Student" << endl;
    cout << "15-Adauga Materie Student (Completeaza lista de materii la care este olimpic Studentul)" << endl;
    cout << "16-Schimba Profesor Catalog" << endl;
    cout << "17-Schimba Profesor Catalog International" << endl;
    cout << "18-Schimba Curs Catalog" << endl;
    cout << "19-Schimba Curs Catalog International" << endl;
    cout << "20-Vezi Fondurile Institutiei de Invatamant" << endl;
    cout << "21-IMPORT Studenti" << endl;
    cout << "22-IMPORT Studenti Internationali" << endl;
    cout << "23-EXPORT Cataloage" << endl;
    cout << "24-EXPORT Cataloage Internationale" << endl;
    cout << "25-Inapoi" << endl;

}
void displayMeniuUtilizator()
{

    cout << "---Meniu Utilizator---" << endl << endl;
    cout << "1-Vezi Toate Notele" << endl;
    cout << "2-Vezi Toate Notele Maxime si Minime" << endl;
    cout<< "3-Depune o reclamatie" << endl;
    cout << "4-Inapoi" << endl;
}

void writeReclamatie(const string& reclamatie)
{
    ofstream logFile("reclamatii.txt", ios::app);
    if (logFile.is_open())
    {
        logFile << reclamatie << endl<<endl;
        logFile.close();
        cnt255++;
    }
    else
    {
        cout <<endl<< "A intervenit o eroare." << endl;
    }
}


template <typename T>
T getMaxValue(const list<T>& values)
{
    return *max_element(values.begin(), values.end());
}

template <>
char getMaxValue<char>(const list<char>& values)
{
    char minChar = 'F';
    for (const char& ch : values)
    {
        if (ch < minChar && ch >= 'A')
        {
            minChar = ch;
        }
    }

    return minChar;

}

template <typename T>
T getMinValue(const list<T>& values)
{
    return *min_element(values.begin(), values.end());
}

template <>
char getMinValue<char>(const list<char>& values)
{
    char maxChar = 'A';
    for (const char& ch : values)
    {
        if (ch > maxChar && ch <= 'F')
        {
            maxChar = ch;
        }
    }

    return maxChar;
}



class Persoana
{
protected:
    string nume;
public:
    Persoana();
    Persoana(string nume);
    Persoana(const Persoana& obj);
    Persoana& operator=(const Persoana& obj);
    friend istream& operator>>(istream& in, Persoana& obj);
    friend ostream& operator<<(ostream& out, const Persoana& obj);

    string getNume() const
    {
        return this->nume;
    };
    void settNume(string nume)
    {
        this->nume=nume;
    };

    virtual int taxa() const = 0;

    virtual ~Persoana() {};

};

Persoana::Persoana()
{
    this->nume="Anonim";
}
Persoana::Persoana(string nume)
{
    this->nume=nume;
}
Persoana::Persoana(const Persoana& obj)
{
    this->nume=obj.nume;
}
Persoana& Persoana::operator=(const Persoana& obj)
{
    if (this!=&obj)
        this->nume=obj.nume;

    return *this;
}
istream& operator>>(istream& in, Persoana&obj)
{
    cout<<"Nume: ";
    cin.ignore(10000, '\n');
    getline(in, obj.nume);
    return in;
}
ostream& operator<<(ostream& out, const Persoana& obj)
{
    out<<"Nume: " << obj.nume << endl;
    return out;
}



class Student:public Persoana
{
protected:
    const int id;
    static int contorId;
    int anulNasterii;
    set <string> materii;

public:
    Student();
    Student(string nume, int anulNasterii, set<string> materii);
    Student(const Student& obj);
    Student& operator=(const Student& obj);
    friend istream& operator>>(istream& in, Student& obj);
    friend ostream& operator<<(ostream& out, const Student& obj);

    const int getId()
    {
        return this->id;
    };
    int getAnulNasterii()
    {
        return this->anulNasterii;
    };
    set<string> getMaterii()
    {
        return this->materii;
    };

    void settAnulNasterii(int anulNasterii)
    {
        this->anulNasterii=anulNasterii;
    };
    void settMaterii(set<string> materii)
    {
        this->materii=materii;
    };

    void addMaterie(const string& materie)
    {
        this->materii.insert(materie);
    }


    int taxa()const
    {
        return 2500;
    }

    virtual ~Student() {};


};

int Student::contorId=0;

Student::Student():Persoana(),id(contorId++)
{
    this->anulNasterii=0;
    this->materii=set<string>();

}
Student::Student(string nume, int anulNasterii, set<string> materii):Persoana(nume),id(contorId++)
{
    this->anulNasterii=anulNasterii;
    this->materii=materii;
}

Student::Student(const Student& obj):Persoana(obj),id(contorId++)
{
    this->materii=obj.materii;
    this->anulNasterii=obj.anulNasterii;
}

Student& Student::operator=(const Student& obj)
{
    if (this!=&obj)
    {
        Persoana::operator=(obj);
        this->materii=obj.materii;
        this->anulNasterii=obj.anulNasterii;
    }
    return *this;
}

istream& operator>>(istream& in, Student& obj)
{
    in >> (Persoana&)obj;
    cout << "Anul Nasterii: ";

    while (true)
    {
        try
        {
            string input;
            in >> input; // Citeste inputul de la utilizator in variabila input de tip string
            stringstream ss(input); // Creaza un stringstream folosind inputul citit

            ss >> obj.anulNasterii; // Extrage valoarea intreaga din stringstream si o atribuie obj.anulNasterii

            if (ss.fail())
            {
                throw invalid_argument("Input invalid. Te rog introdu un numar valid.");
            }

            char remainingChar;
            if (ss >> remainingChar)
            {
                throw invalid_argument("Input invalid. Au fost gasite caractere suplimentare.");
            }

            break; // Inputul este valid
        }
        catch (const invalid_argument& e)
        {
            cout << e.what() << " Incearca din nou: ";
            in.clear(); // Reseteaza starea de eroare
            in.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
        }
    }



    return in;
}



ostream& operator <<(ostream& out, const Student& obj)
{
    out<<"ID: " << obj.id << endl;
    out<<(Persoana&)obj;
    out << "Anul Nasterii: " << obj.anulNasterii << endl;
    if (!obj.materii.empty())
    {
        out << "Materii la care studentul este olimpic: ";
        for (auto it = obj.materii.begin(); it != obj.materii.end(); ++it)
        {
            out << *it;
            if (next(it) != obj.materii.end())
            {
                out << ", ";
            }
            else
            {
                out << endl;
            }
        }

    }
    return out;
}

class StudentInternational:public Student
{
private:
    string origine;

public:
    StudentInternational();
    StudentInternational(string nume, int anulNasterii, set<string> materii, string origine );
    StudentInternational(const StudentInternational& obj);
    StudentInternational& operator=(const StudentInternational& obj);
    friend istream& operator>>(istream& in, StudentInternational& obj);
    friend ostream& operator<<(ostream& out, const StudentInternational& obj);

    string getOrigine()
    {
        return this->origine;
    };
    void settOrigine(string origine)
    {
        this->origine=origine;
    };

    int taxa()const
    {
        return 12500;
    }

    virtual ~StudentInternational() {};


};

StudentInternational::StudentInternational():Student()
{
    this->origine="Necunoscuta";

}
StudentInternational::StudentInternational(string nume, int anulNasterii, set<string> materii, string origine):Student(nume, anulNasterii, materii)
{
    this->origine=origine;
}

StudentInternational::StudentInternational(const StudentInternational& obj):Student(obj)
{
    this->origine=obj.origine;
}

StudentInternational& StudentInternational::operator=(const StudentInternational& obj)
{
    if (this!=&obj)
    {
        Student::operator=(obj);
        this->origine=origine;
    }
    return *this;
}

istream& operator >>(istream& in, StudentInternational& obj )
{
    in>>(Student&)obj;
    cout << "Origine: ";
    in.ignore();
    getline(in, obj.origine);
    return in;
}

ostream& operator <<(ostream& out, const StudentInternational& obj)
{
    out<<(Student&)obj;
    out << "Origine: " << obj.origine << endl;
    return out;
}

///Template Class
template <class gradeType=int>
class CatalogOnline
{
private:
    string numeProfesor;
    string materie;
    map<int, list<gradeType>> catalog;

public:

    CatalogOnline()
    {
        this->numeProfesor="-";
        this->materie="-";
        this->catalog=map<int, list<gradeType>>();
    };
    CatalogOnline(string numeProfesor, string materie, map<int, list<gradeType>> catalog)
    {
        this->numeProfesor=numeProfesor;
        this->materie=materie;
        this->catalog=catalog;
    };
    CatalogOnline(const CatalogOnline& obj)
    {
        this->numeProfesor=obj.numeProfesor;
        this->materie=obj.materie;
        this->catalog=obj.catalog;
    };
    CatalogOnline& operator=(const CatalogOnline& obj)
    {
        if (this!=&obj)
        {
            this->numeProfesor=obj.numeProfesor;
            this->materie=obj.materie;
            this->catalog=obj.catalog;
        }
        return *this;
    };

    friend istream& operator>>(istream& in, CatalogOnline& obj)
    {
        cout<<"Nume Profesor: ";
        cin.ignore(10000, '\n');
        getline(in,obj.numeProfesor);
        cout<<"Materie: ";
        getline(in,obj.materie);

        return in;
    };


    friend ostream& operator<<(ostream& out, const CatalogOnline& obj)
    {
        out << "+---------------------------------------------------+" << endl;

        // Check if gradeType is char (English design)
        if (is_same<gradeType, char>::value)
        {
            out << "|                   Online Catalog                  |" << endl;
            out << "+---------------------------------------------------+" << endl;
            out << "| Professor: " << setw(44) << left << obj.numeProfesor << endl;
            out << "| Course:    " << setw(44) << left << obj.materie << endl;
            out << "+---------------------------------------------------+" << endl;
            if (obj.catalog.empty())
            {
                out << "|                  Empty Catalog                    |" << endl;
            }
            else
            {
                out << "| ID        | Grades                                |" << endl;
                out << "+---------------------------------------------------+" << endl;

                for (const auto& entry : obj.catalog)
                {
                    out << "| " << setw(10) << left << entry.first << "| ";

                    // Calculate the number of empty spaces for alignment
                    int numSpaces = 10 * (10 - entry.second.size());

                    for (const auto& grade : entry.second)
                    {
                        // Set text color based on grade
                        if (grade == 'A')
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Green color
                        }
                        else if (grade >= 'B' && grade <= 'E')
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Yellow color
                        }
                        else
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Red color
                        }

                        out << grade << " ";
                    }

                    // Right-align the grades column
                    out << setw(numSpaces) << right << " " << endl;

                    // Reset text color to default
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
            }
        }
        // Check if gradeType is int (Romanian design)
        else if (is_same<gradeType, int>::value)
        {
            out << "|                   Catalog Online                  |" << endl;
            out << "+---------------------------------------------------+" << endl;
            out << "| Profesor: " << setw(44) << left << obj.numeProfesor << endl;
            out << "| Curs:     " << setw(44) << left << obj.materie << endl;
            out << "+---------------------------------------------------+" << endl;
            if (obj.catalog.empty())
            {
                out << "|                  Catalog Gol                      |" << endl;
            }
            else
            {
                out << "| ID        | Note                                  |" << endl;
                out << "+---------------------------------------------------+" << endl;

                for (const auto& entry : obj.catalog)
                {
                    out << "| " << setw(10) << left << entry.first << "| ";

                    // Calculate the number of empty spaces for alignment
                    int numSpaces = 10 * (10 - entry.second.size());

                    for (const auto& grade : entry.second)
                    {
                        // Set text color based on grade
                        if (grade == 10 || grade == 9)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Green color
                        }
                        else if (grade >= 5 && grade <= 8)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Yellow color
                        }
                        else if (grade < 5)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Red color
                        }
                        else
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Default color (white)
                        }

                        out << grade << " ";
                    }

                    // Right-align the grades column
                    out << setw(numSpaces) << right << " " << endl;

                    // Reset text color to default
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
            }
        }

        out << "+---------------------------------------------------+" << endl << endl << endl;

        return out;
    };

    string getNumeProfesor()
    {
        return this->numeProfesor;
    };
    string getMaterie()
    {
        return this->materie;
    };
    map<int, list<gradeType>> getCatalog()
    {
        return this->catalog;
    };

    void settNumeProfesor(string numeProfesor)
    {
        this->numeProfesor=numeProfesor;
    };
    void settMaterie(string materie)
    {
        this->materie=materie;
    };
    void settCatalog(map<int, list<gradeType>> catalog)
    {
        this->catalog=catalog;
    };

    void addGrade(int ID, gradeType grade)
    {
        this->catalog[ID].push_back(grade);
    }

    void removeGrade(int ID, gradeType grade)
    {
        auto& grades = this->catalog[ID];
        auto it = find(grades.begin(), grades.end(), grade);
        if (it != grades.end())
        {
            grades.erase(it);
        }
    }

    void eraseStudent(int ID)
    {
        this->catalog.erase(ID);
    }

    /// Template method 1
    template <typename T=gradeType>
    T getMaxValue(const list<T>& values)
    {

        return ::getMaxValue(values);
    };

    /// Template method 2
    template <typename T=gradeType>
    T getMinValue(const list<T>& values)
    {

        return ::getMinValue(values);
    };

    ///Export in file
    void exportToFile(const string& filename) const
    {
        ofstream file(filename, ios::app); // Open the file in append mode to preserve existing content
        if (!file.is_open())
        {
            cerr << endl<<"A intervenit o eroare." << endl;
            return;
        }

        cnt255++;
        file << "+---------------------------------------------------+" << endl;

        // Check if gradeType is char (International design)
        if (is_same<gradeType, char>::value)
        {
            file << "|                   Online Catalog                  |" << endl;
            file << "+---------------------------------------------------+" << endl;
            file << "| Professor: " << setw(44) << left << numeProfesor << endl;
            file << "| Course:    " << setw(44) << left << materie << endl;
            file << "+---------------------------------------------------+" << endl;
            if (catalog.empty())
            {
                file << "|                  Empty Catalog                    |" << endl;
            }
            else
            {
                file << "| ID        | Grades                                |" << endl;
                file << "+---------------------------------------------------+" << endl;

                for (const auto& entry : catalog)
                {
                    file << "| " << setw(10) << left << entry.first << "| ";

                    // Calculate the number of empty spaces for alignment
                    int numSpaces = 10 * (10 - entry.second.size());

                    for (const auto& grade : entry.second)
                    {
                        // Set text color based on grade
                        file << grade << " ";
                    }

                    // Right-align the grades column
                    file << setw(numSpaces) << right << " " << endl;
                }
            }
        }
        // Check if gradeType is int (Romanian design)
        else if (is_same<gradeType, int>::value)
        {
            file << "|                   Catalog Online                  |" << endl;
            file << "+---------------------------------------------------+" << endl;
            file << "| Profesor: " << setw(44) << left << numeProfesor << endl;
            file << "| Curs:     " << setw(44) << left << materie << endl;
            file << "+---------------------------------------------------+" << endl;
            if (catalog.empty())
            {
                file << "|                  Catalog Gol                      |" << endl;
            }
            else
            {
                file << "| ID        | Note                                  |" << endl;
                file << "+---------------------------------------------------+" << endl;

                for (const auto& entry : catalog)
                {
                    file << "| " << setw(10) << left << entry.first << "| ";

                    // Calculate the number of empty spaces for alignment
                    int numSpaces = 10 * (10 - entry.second.size());

                    for (const auto& grade : entry.second)
                    {
                        // Set text color based on grade
                        file << grade << " ";
                    }

                    // Right-align the grades column
                    file << setw(numSpaces) << right << " " << endl;
                }
            }
        }

        file << "+---------------------------------------------------+" << endl<<endl<<endl;

        file.close();
    };



    ~CatalogOnline() {};

};

int cnt256=0;
vector <Persoana*> persoane;
vector<CatalogOnline<int>*> cataloage1;
vector<CatalogOnline<char>*> cataloage2;

// Trim leading and trailing whitespace from a string
string trim(const string& str)
{
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    if (start == string::npos || end == string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

///Import from file
void importStudents(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr <<endl<< "A intervenit o eroare." << endl;
        return;
    }

    cnt256++;
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string nume;
        int anulNasterii;
        set<string> materii;

        getline(ss, nume, ',');
        ss >> anulNasterii;

        // Read the subjects
        string subjects;
        getline(ss, subjects, '{');
        getline(ss, subjects, '}');

        stringstream ssSubjects(subjects);
        string subject;
        while (getline(ssSubjects, subject, ','))
        {
            materii.insert(trim(subject));
        }

        // Create and add the Student object to the persoane vector
        persoane.push_back(new Student(nume, anulNasterii, materii));
    }

    file.close();
}

void importStudentInternationals(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr <<endl<< "A intervenit o eroare." << endl;
        return;
    }

    cnt256++;
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string nume;
        int anulNasterii;
        set<string> materii;
        string origine;

        getline(ss, nume, ',');
        ss >> anulNasterii;

        // Read the subjects
        string subjects;
        getline(ss, subjects, '{');
        getline(ss, subjects, '}');

        stringstream ssSubjects(subjects);
        string subject;
        while (getline(ssSubjects, subject, ','))
        {
            materii.insert(trim(subject));
        }

        // Read the country
        getline(ss, origine);
        origine = trim(origine); // Trim leading and trailing whitespace

        // Remove the leading comma if present
        if (!origine.empty() && origine[0] == ',')
        {
            origine = origine.substr(1);
        }
        // Trim leading and trailing whitespace from the origine string
        origine = trim(origine);
        // Create and add the StudentInternational object to the persoane vector
        persoane.push_back(new StudentInternational(nume, anulNasterii, materii, origine));
    }

    file.close();
}


class Meniu
{
private:
    static Meniu *obj;
    Meniu()=default;
    Meniu(const Meniu&)=delete;
    static int nrOfInstances;
public:
    static Meniu* getInstance()
    {
        nrOfInstances++;
        if(!obj)
            obj=new Meniu();


        return obj;
    }

    void MyApp()
    {
        while (true)
        {
            int comanda;
            try
            {

                displayMeniuPrincipal();
                cin >> comanda;
                if (cin.fail())
                {
                    throw invalid_argument("Input invalid. Te rog introdu o comanda valida.");
                }

            }
            catch (const invalid_argument& e)
            {
                cout << "Eroare: " << e.what() << endl;
                cin.clear(); // Clear the error state of cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining characters in the input buffer
            }


            switch (comanda)
            {
            case 1:
            {
                clearScreen();
                while (true)
                {
                    int comanda2;
                    try
                    {
                        displayMeniuUtilizator();
                        cin >> comanda2;
                        if (cin.fail())
                        {
                            throw invalid_argument("Input invalid. Te rog introdu o comanda valida.");
                        }

                    }
                    catch (const invalid_argument& e)
                    {
                        cout << "Eroare: " << e.what() << endl << endl;
                        cin.clear(); // Clear the error state of cin
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining characters in the input buffer
                    }

                    switch (comanda2)
                    {
                    case 1:
                    {
                        clearScreen();

                        try
                        {
                            bool foundStudent = false;
                            for (const auto& persoana : persoane)
                            {
                                if (typeid(*persoana) == typeid(Student))
                                {
                                    foundStudent = true;
                                    cout << dynamic_cast<Student&>(*persoana) << endl;
                                }
                                if (typeid(*persoana) == typeid(StudentInternational))
                                {
                                    foundStudent = true;
                                    cout << dynamic_cast<StudentInternational&>(*persoana) << endl;
                                }
                            }

                            if (!foundStudent)
                            {
                                throw runtime_error("Nu exista studenti.");

                            }
                        }
                        catch (const exception& e)
                        {
                            cout << "Eroare: " << e.what() << endl<<endl;
                            pauza(3);
                            clearScreen();
                            break;
                        }

                        cout<<"Introduceti ID-ul studentului caruia doriti sa ii vedeti notele: ";
                        int ID;

                        while (true)
                        {
                            try
                            {
                                string input;
                                cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                ss >> ID; // Extrage valoarea intreaga din stringstream si o atribuie variabilei ID

                                if (ss.fail())
                                {
                                    throw invalid_argument("ID invalid. Te rog introdu un ID valid.");
                                }

                                char remainingChar;
                                if (ss >> remainingChar)
                                {
                                    throw invalid_argument("ID invalid. Au fost gasite caractere suplimentare.");
                                }

                                break; // Inputul este valid
                            }
                            catch (const invalid_argument& e)
                            {
                                cout << e.what() << " Incearca din nou: ";
                                cin.clear(); // Reseteaza starea de eroare
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                            }
                        }

                        try
                        {
                            bool foundStudent = false;
                            for (auto it = persoane.begin(); it != persoane.end(); )
                            {
                                if (typeid(*(*it)) == typeid(Student) && dynamic_cast<Student&>(*(*it)).getId() == ID)
                                {
                                    foundStudent = true;

                                }


                                if (typeid(*(*it)) == typeid(StudentInternational) && dynamic_cast<StudentInternational&>(*(*it)).getId() == ID)
                                {
                                    foundStudent = true;

                                }

                                ++it;

                            }


                            if (!foundStudent)
                            {
                                throw runtime_error("Nu exista studentul cu ID-ul respectiv.");

                            }
                        }
                        catch (const exception& e)
                        {
                            cout <<endl<< "Eroare: " << e.what() << endl<<endl;
                            pauza(3);
                            clearScreen();
                            break;
                        }

                        cout<<endl;

                        for (const auto& catalog : cataloage1)
                        {
                            if(catalog->getCatalog().find(ID)!=catalog->getCatalog().end())
                            {
                                cout<< catalog->getMaterie() << ": ";
                                for (const auto& grade : catalog->getCatalog()[ID])
                                    cout<<grade<<" ";
                            }
                            cout<<endl;
                        }

                        cout<<endl;

                        for (const auto& catalog : cataloage2)
                        {
                            if(catalog->getCatalog().find(ID)!=catalog->getCatalog().end())
                            {
                                cout<< catalog->getMaterie() << ": ";
                                for (const auto& grade : catalog->getCatalog()[ID])
                                    cout<<grade<<" ";
                            }
                            cout<<endl;
                        }

                        cout<<endl;




                        cout << "Apasa 'enter' pentru a reveni la meniu." << endl;
                        cin.ignore();
                        while (cin.get() != '\n');

                        clearScreen();
                        break;
                    }
                    case 2:
                    {
                        clearScreen();

                        try
                        {
                            bool foundStudent = false;
                            for (const auto& persoana : persoane)
                            {
                                if (typeid(*persoana) == typeid(Student))
                                {
                                    foundStudent = true;
                                    cout << dynamic_cast<Student&>(*persoana) << endl;
                                }
                                if (typeid(*persoana) == typeid(StudentInternational))
                                {
                                    foundStudent = true;
                                    cout << dynamic_cast<StudentInternational&>(*persoana) << endl;
                                }
                            }

                            if (!foundStudent)
                            {
                                throw runtime_error("Nu exista studenti.");

                            }
                        }
                        catch (const exception& e)
                        {
                            cout << "Eroare: " << e.what() << endl<<endl;
                            pauza(3);
                            clearScreen();
                            break;
                        }

                        cout<<"Introduceti ID-ul studentului caruia doriti sa ii vedeti notele maxime si minime: ";
                        int ID;

                        while (true)
                        {
                            try
                            {
                                string input;
                                cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                ss >> ID; // Extrage valoarea intreaga din stringstream si o atribuie variabilei ID

                                if (ss.fail())
                                {
                                    throw invalid_argument("ID invalid. Te rog introdu un ID valid.");
                                }

                                char remainingChar;
                                if (ss >> remainingChar)
                                {
                                    throw invalid_argument("ID invalid. Au fost gasite caractere suplimentare.");
                                }

                                break; // Inputul este valid
                            }
                            catch (const invalid_argument& e)
                            {
                                cout << e.what() << " Incearca din nou: ";
                                cin.clear(); // Reseteaza starea de eroare
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                            }
                        }

                        try
                        {
                            bool foundStudent = false;
                            for (auto it = persoane.begin(); it != persoane.end(); )
                            {
                                if (typeid(*(*it)) == typeid(Student) && dynamic_cast<Student&>(*(*it)).getId() == ID)
                                {
                                    foundStudent = true;

                                }


                                if (typeid(*(*it)) == typeid(StudentInternational) && dynamic_cast<StudentInternational&>(*(*it)).getId() == ID)
                                {
                                    foundStudent = true;

                                }

                                ++it;

                            }


                            if (!foundStudent)
                            {
                                throw runtime_error("Nu exista studentul cu ID-ul respectiv.");

                            }
                        }
                        catch (const exception& e)
                        {
                            cout <<endl<< "Eroare: " << e.what() << endl<<endl;
                            pauza(3);
                            clearScreen();
                            break;
                        }

                        cout<<endl;

                        for (const auto& catalog : cataloage1)
                        {
                            if(catalog->getCatalog().find(ID)!=catalog->getCatalog().end())
                            {
                                cout<< catalog->getMaterie() << ": ";
                                if(catalog->getCatalog()[ID].empty())
                                {

                                    cout<<"Nota Maxima -> "<<"---"<<", ";
                                    cout<<"Nota Minima -> "<<"---"<<endl;
                                }
                                else
                                {
                                    cout<<"Nota Maxima -> "<<catalog->getMaxValue(catalog->getCatalog()[ID])<<", ";
                                    cout<<"Nota Minima -> "<<catalog->getMinValue(catalog->getCatalog()[ID])<<endl;
                                }

                            }
                            cout<<endl;
                        }

                        cout<<endl;
                        for (const auto& catalog : cataloage2)
                        {
                            if(catalog->getCatalog().find(ID)!=catalog->getCatalog().end())
                            {
                                cout<< catalog->getMaterie() << ": ";
                                if(catalog->getCatalog()[ID].empty())
                                {
                                    cout<<"Nota Maxima -> "<<"---"<<", ";
                                    cout<<"Nota Minima -> "<<"---"<<endl;
                                }
                                else
                                {
                                    cout<<"Nota Maxima -> "<<catalog->getMaxValue(catalog->getCatalog()[ID])<<", ";
                                    cout<<"Nota Minima -> "<<catalog->getMinValue(catalog->getCatalog()[ID])<<endl;
                                }


                            }
                            cout<<endl;
                        }


                        cout<<endl;




                        cout << "Apasa 'enter' pentru a reveni la meniu." << endl;
                        cin.ignore();
                        while (cin.get() != '\n');

                        clearScreen();
                        break;
                    }
                    case 3:
                    {
                        clearScreen();

                        cout<<"Introduceti reclamatia dumneavoastra: ";
                        cin.ignore();
                        string reclamatie;
                        getline(cin, reclamatie);

                        cnt255=0;
                        writeReclamatie(reclamatie);

                        for(int i=0; i<=3; i++)
                        {
                            clearScreen();
                            cout << "\rSe proceseaza.";
                            this_thread::sleep_for(chrono::milliseconds(500));
                            cout << "\rSe proceseaza..";
                            this_thread::sleep_for(chrono::milliseconds(500));
                            cout << "\rSe proceseaza...";
                            this_thread::sleep_for(chrono::milliseconds(500));
                        }

                        clearScreen();
                        if(cnt255!=0)
                            cout<<endl<<"EXPORT realizat cu succes."<<endl;
                        else
                            cout<<endl<<"A intervenit o eroare." << endl;
                        pauza(3);
                        clearScreen();
                        break;



                    }

                    case 4:
                    {
                        clearScreen();


                        clearScreen();
                        break;

                    }


                    default:
                    {
                        clearScreen();
                        cout << "Comanda invalida. Folositi o comanda valida." << endl<<endl;
                        break;
                    }

                    }


                    if (comanda2==4)
                        break;
                }
                break;

            }





            case 2:
            {
                clearScreen();
                displayMeniuAdmin();
                string parola;
                char c;
                while ((c = getch()) != '\r')   // se citesc caractere pana se apasa enter
                {
                    if (c == '\b' && !parola.empty())   // ca sa mearga backspace
                    {
                        parola.pop_back();
                        cout << "\b \b"; // sa stearga si '*' din consola cand apesi backspace
                    }
                    else if (c != '\b')     // sa ignore backspace, sa nu il ia ca si caracter
                    {
                        parola += c;
                        cout << "*";
                    }
                }
                cout << endl;
                if (parola == "1234")
                {
                    clearScreen();
                    while (true)
                    {
                        int comanda3;
                        try
                        {
                            displaySubMeniuAdmin();
                            cin >> comanda3;
                            if (cin.fail())
                            {
                                throw invalid_argument("Input invalid. Te rog introdu o comanda valida.");
                            }

                        }
                        catch (const invalid_argument& e)
                        {
                            cout << "Eroare: " << e.what() << endl << endl;
                            cin.clear(); // Clear the error state of cin
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining characters in the input buffer
                        }

                        switch (comanda3)
                        {


                        case 1:
                        {
                            clearScreen();

                            Student *A= new Student();
                            cin>>*A;
                            persoane.push_back(A);

                            clearScreen();
                            break;
                        }
                        case 2:
                        {
                            clearScreen();
                            StudentInternational *A= new StudentInternational();
                            cin>>*A;
                            persoane.push_back(A);
                            clearScreen();
                            break;
                        }
                        case 3:
                        {
                            clearScreen();

                            CatalogOnline<> *A = new CatalogOnline<>();
                            cin >> *A;
                            cataloage1.push_back(A);

                            clearScreen();
                            break;
                        }

                        case 4:
                        {
                            clearScreen();

                            CatalogOnline<char> *A = new CatalogOnline<char>();
                            cin >> *A;
                            cataloage2.push_back(A);

                            clearScreen();
                            break;

                        }
                        case 5:
                        {
                            clearScreen();


                            try
                            {
                                bool foundStudent = false;
                                for (const auto& persoana : persoane)
                                {
                                    if (typeid(*persoana) == typeid(Student))
                                    {
                                        foundStudent = true;
                                        cout << dynamic_cast<Student&>(*persoana) << endl;
                                    }
                                }

                                if (!foundStudent)
                                {
                                    throw runtime_error("Nu exista studenti.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }

                            cout << "Apasa 'enter' pentru a reveni la meniu." << endl;
                            cin.ignore();
                            while (cin.get() != '\n');

                            clearScreen();
                            break;
                        }

                        case 6:
                        {

                            clearScreen();


                            try
                            {
                                bool foundStudent = false;
                                for (const auto& persoana : persoane)
                                {
                                    if (typeid(*persoana) == typeid(StudentInternational))
                                    {
                                        foundStudent = true;
                                        cout << dynamic_cast<StudentInternational&>(*persoana) << endl;
                                    }
                                }

                                if (!foundStudent)
                                {
                                    throw runtime_error("Nu exista studenti internationali.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }

                            cout << "Apasa 'enter' pentru a reveni la meniu." << endl;
                            cin.ignore();
                            while (cin.get() != '\n');

                            clearScreen();
                            break;
                        }

                        case 7:
                        {
                            clearScreen();

                            try
                            {
                                bool foundCatalog = false;
                                for (const auto& catalog : cataloage1)
                                {
                                    cout<<*catalog<<endl;
                                    foundCatalog=true;
                                }



                                if (!foundCatalog)
                                {
                                    throw runtime_error("Nu exista cataloage.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }

                            cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                            cin.ignore();
                            while(cin.get() != '\n');



                            clearScreen();
                            break;

                        }
                        case 8:
                        {
                            clearScreen();

                            try
                            {
                                bool foundCatalog = false;
                                for (const auto& catalog : cataloage2)
                                {
                                    cout<<*catalog<<endl;
                                    foundCatalog=true;
                                }



                                if (!foundCatalog)
                                {
                                    throw runtime_error("Nu exista cataloage internationale.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }

                            cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                            cin.ignore();
                            while(cin.get() != '\n');



                            clearScreen();
                            break;

                        }
                        case 9:
                        {

                            clearScreen();

                            try
                            {
                                bool foundStudent = false;
                                for (const auto& persoana : persoane)
                                {
                                    if (typeid(*persoana) == typeid(Student))
                                    {
                                        foundStudent = true;
                                        cout << dynamic_cast<Student&>(*persoana) << endl;
                                    }
                                }

                                if (!foundStudent)
                                {
                                    throw runtime_error("Nu exista studenti.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }

                            cout<<"Introduceti ID-ul studentului pe care doriti sa-l eliminati: ";
                            int ID;

                            while (true)
                            {
                                try
                                {
                                    string input;
                                    cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                    stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                    ss >> ID; // Extrage valoarea intreaga din stringstream si o atribuie variabilei ID

                                    if (ss.fail())
                                    {
                                        throw invalid_argument("ID invalid. Te rog introdu un ID valid.");
                                    }

                                    char remainingChar;
                                    if (ss >> remainingChar)
                                    {
                                        throw invalid_argument("ID invalid. Au fost gasite caractere suplimentare.");
                                    }

                                    break; // Inputul este valid
                                }
                                catch (const invalid_argument& e)
                                {
                                    cout << e.what() << " Incearca din nou: ";
                                    cin.clear(); // Reseteaza starea de eroare
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                }
                            }

                            try
                            {
                                bool foundStudent = false;
                                for (auto it = persoane.begin(); it != persoane.end(); )
                                {
                                    if (typeid(*(*it)) == typeid(Student) && dynamic_cast<Student&>(*(*it)).getId() == ID)
                                    {
                                        foundStudent = true;
                                        it = persoane.erase(it);
                                    }
                                    else
                                    {
                                        ++it;
                                    }
                                }


                                if (!foundStudent)
                                {
                                    throw runtime_error("Nu exista studentul cu ID-ul respectiv.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout <<endl<< "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }


                            for (auto& catalog : cataloage1)
                            {
                                catalog->eraseStudent(ID);
                            }


                            for (auto& catalog : cataloage2)
                            {
                                catalog->eraseStudent(ID);
                            }

                            cout<<endl<<"Studentul a fost sters cu succes." <<endl;



                            pauza(4);
                            clearScreen();
                            break;

                        }



                        case 10:
                        {

                            clearScreen();

                            try
                            {
                                bool foundStudent = false;
                                for (const auto& persoana : persoane)
                                {
                                    if (typeid(*persoana) == typeid(StudentInternational))
                                    {
                                        foundStudent = true;
                                        cout << dynamic_cast<StudentInternational&>(*persoana) << endl;
                                    }
                                }

                                if (!foundStudent)
                                {
                                    throw runtime_error("Nu exista studenti internationali.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }

                            cout<<"Introduceti ID-ul studentului international pe care doriti sa-l eliminati: ";
                            int ID;

                            while (true)
                            {
                                try
                                {
                                    string input;
                                    cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                    stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                    ss >> ID; // Extrage valoarea intreaga din stringstream si o atribuie variabilei ID

                                    if (ss.fail())
                                    {
                                        throw invalid_argument("ID invalid. Te rog introdu un ID valid.");
                                    }

                                    char remainingChar;
                                    if (ss >> remainingChar)
                                    {
                                        throw invalid_argument("ID invalid. Au fost gasite caractere suplimentare.");
                                    }

                                    break; // Inputul este valid
                                }
                                catch (const invalid_argument& e)
                                {
                                    cout << e.what() << " Incearca din nou: ";
                                    cin.clear(); // Reseteaza starea de eroare
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                }
                            }

                            try
                            {
                                bool foundStudent = false;
                                for (auto it = persoane.begin(); it != persoane.end(); )
                                {
                                    if (typeid(*(*it)) == typeid(StudentInternational) && dynamic_cast<StudentInternational&>(*(*it)).getId() == ID)
                                    {
                                        foundStudent = true;
                                        it = persoane.erase(it);
                                    }
                                    else
                                    {
                                        ++it;
                                    }
                                }


                                if (!foundStudent)
                                {
                                    throw runtime_error("Nu exista studentul international cu ID-ul respectiv.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout <<endl<< "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }


                            for (auto& catalog : cataloage1)
                            {
                                catalog->eraseStudent(ID);
                            }


                            for (auto& catalog : cataloage2)
                            {
                                catalog->eraseStudent(ID);
                            }

                            cout<<endl<<"Studentul international a fost sters cu succes." <<endl;



                            pauza(4);
                            clearScreen();
                            break;

                        }

                        case 11:
                        {
                            clearScreen();

                            try
                            {
                                bool foundCatalog = false;
                                int i=0;
                                for (const auto& catalog : cataloage1)
                                {
                                    cout<<i<<". " << endl << *catalog<<endl;
                                    foundCatalog=true;
                                    i++;
                                }



                                if (!foundCatalog)
                                {
                                    throw runtime_error("Nu exista cataloage.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }
                            cout<<"Introduceti Index-ul catalogului pe care doriti sa-l eliminati: ";
                            int Index;

                            while (true)
                            {
                                try
                                {
                                    string input;
                                    cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                    stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                    ss >> Index; // Extrage valoarea intreaga din stringstream si o atribuie variabilei Index

                                    if (ss.fail())
                                    {
                                        throw invalid_argument("Index invalid. Te rog introdu un Index valid.");
                                    }

                                    char remainingChar;
                                    if (ss >> remainingChar)
                                    {
                                        throw invalid_argument("Index invalid. Au fost gasite caractere suplimentare.");
                                    }

                                    break; // Inputul este valid
                                }
                                catch (const invalid_argument& e)
                                {
                                    cout << e.what() << " Incearca din nou: ";
                                    cin.clear(); // Reseteaza starea de eroare
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                }
                            }
                            try
                            {
                                if (Index >= 0 && Index < cataloage1.size())
                                {
                                    cataloage1.erase(cataloage1.begin() + Index);
                                }
                                else
                                {
                                    throw out_of_range("Index invalid. Index-ul introdus nu exista.");
                                }
                            }
                            catch (const out_of_range& e)
                            {
                                cout <<endl<< "Eroare: " << e.what() << endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }





                            cout<<endl<<"Catalogul a fost sters cu succes." <<endl;



                            pauza(4);
                            clearScreen();
                            break;
                        }

                        case 12:
                        {
                            clearScreen();

                            try
                            {
                                bool foundCatalog = false;
                                int i=0;
                                for (const auto& catalog : cataloage2)
                                {
                                    cout<<i<<". " << endl << *catalog<<endl;
                                    foundCatalog=true;
                                    i++;
                                }



                                if (!foundCatalog)
                                {
                                    throw runtime_error("Nu exista cataloage internationale.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }
                            cout<<"Introduceti Index-ul catalogului international pe care doriti sa-l eliminati: ";
                            int Index;

                            while (true)
                            {
                                try
                                {
                                    string input;
                                    cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                    stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                    ss >> Index; // Extrage valoarea intreaga din stringstream si o atribuie variabilei Index

                                    if (ss.fail())
                                    {
                                        throw invalid_argument("Index invalid. Te rog introdu un Index valid.");
                                    }

                                    char remainingChar;
                                    if (ss >> remainingChar)
                                    {
                                        throw invalid_argument("Index invalid. Au fost gasite caractere suplimentare.");
                                    }

                                    break; // Inputul este valid
                                }
                                catch (const invalid_argument& e)
                                {
                                    cout << e.what() << " Incearca din nou: ";
                                    cin.clear(); // Reseteaza starea de eroare
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                }
                            }
                            try
                            {
                                if (Index >= 0 && Index < cataloage1.size())
                                {
                                    cataloage1.erase(cataloage1.begin() + Index);
                                }
                                else
                                {
                                    throw out_of_range("Index invalid. Index-ul introdus nu exista.");
                                }
                            }
                            catch (const out_of_range& e)
                            {
                                cout <<endl<< "Eroare: " << e.what() << endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }





                            cout<<endl<<"Catalogul international a fost sters cu succes." <<endl;



                            pauza(4);
                            clearScreen();
                            break;
                        }

                        case 13:
                        {

                            clearScreen();

                            try
                            {
                                bool foundStudent = false;
                                for (const auto& persoana : persoane)
                                {
                                    if (typeid(*persoana) == typeid(Student))
                                    {
                                        foundStudent = true;
                                        cout << dynamic_cast<Student&>(*persoana) << endl;
                                    }
                                    if (typeid(*persoana) == typeid(StudentInternational))
                                    {
                                        foundStudent = true;
                                        cout << dynamic_cast<StudentInternational&>(*persoana) << endl;
                                    }
                                }

                                if (!foundStudent)
                                {
                                    throw runtime_error("Nu exista studenti.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }

                            cout<<"Introduceti ID-ul studentului caruia doriti sa ii adaugati o nota: ";
                            int ID;

                            while (true)
                            {
                                try
                                {
                                    string input;
                                    cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                    stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                    ss >> ID; // Extrage valoarea intreaga din stringstream si o atribuie variabilei ID

                                    if (ss.fail())
                                    {
                                        throw invalid_argument("ID invalid. Te rog introdu un ID valid.");
                                    }

                                    char remainingChar;
                                    if (ss >> remainingChar)
                                    {
                                        throw invalid_argument("ID invalid. Au fost gasite caractere suplimentare.");
                                    }

                                    break; // Inputul este valid
                                }
                                catch (const invalid_argument& e)
                                {
                                    cout << e.what() << " Incearca din nou: ";
                                    cin.clear(); // Reseteaza starea de eroare
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                }
                            }

                            try
                            {
                                bool foundStudent = false;
                                for (auto it = persoane.begin(); it != persoane.end(); )
                                {
                                    if (typeid(*(*it)) == typeid(Student) && dynamic_cast<Student&>(*(*it)).getId() == ID)
                                    {
                                        foundStudent = true;

                                    }


                                    if (typeid(*(*it)) == typeid(StudentInternational) && dynamic_cast<StudentInternational&>(*(*it)).getId() == ID)
                                    {
                                        foundStudent = true;

                                    }

                                    ++it;

                                }


                                if (!foundStudent)
                                {
                                    throw runtime_error("Nu exista studentul cu ID-ul respectiv.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout <<endl<< "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }


                            cout<<"Introduceti '1' pentru a selecta cataloagele sau '2' pentru a selecta cataloagele internationale: ";
                            int nr;

                            do
                            {
                                try
                                {
                                    string input;
                                    cin >> input;
                                    stringstream ss(input);

                                    ss >> nr;

                                    if (ss.fail())
                                    {
                                        throw invalid_argument("Input invalid. Te rog introdu un numar valid.");
                                    }

                                    char remainingChar;
                                    if (ss >> remainingChar)
                                    {
                                        throw invalid_argument("Input invalid. Au fost gasite caractere suplimentare.");
                                    }

                                    if (nr != 1 && nr != 2)
                                    {
                                        throw invalid_argument("Input invalid. Te rog introdu 1 sau 2.");
                                    }

                                    break; // Inputul este valid
                                }
                                catch (const invalid_argument& e)
                                {
                                    cout << e.what() << " Incearca din nou: ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                            }
                            while (true);

                            if(nr==1)
                            {
                                cout<<endl;
                                try
                                {
                                    bool foundCatalog = false;
                                    int i=0;
                                    for (const auto& catalog : cataloage1)
                                    {
                                        cout<<i<<". " << endl << *catalog<<endl;
                                        foundCatalog=true;
                                        i++;
                                    }



                                    if (!foundCatalog)
                                    {
                                        throw runtime_error("Nu exista cataloage.");

                                    }
                                }
                                catch (const exception& e)
                                {
                                    cout << "Eroare: " << e.what() << endl<<endl;
                                    pauza(3);
                                    clearScreen();
                                    break;
                                }
                                cout<<"Introduceti Index-ul catalogului unde doriti sa adaugati nota: ";
                                int Index;

                                while (true)
                                {
                                    try
                                    {
                                        string input;
                                        cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                        stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                        ss >> Index; // Extrage valoarea intreaga din stringstream si o atribuie variabilei Index

                                        if (ss.fail())
                                        {
                                            throw invalid_argument("Index invalid. Te rog introdu un Index valid.");
                                        }

                                        char remainingChar;
                                        if (ss >> remainingChar)
                                        {
                                            throw invalid_argument("Index invalid. Au fost gasite caractere suplimentare.");
                                        }

                                        break; // Inputul este valid
                                    }
                                    catch (const invalid_argument& e)
                                    {
                                        cout << e.what() << " Incearca din nou: ";
                                        cin.clear(); // Reseteaza starea de eroare
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                    }
                                }
                                try
                                {
                                    if (Index >= 0 && Index < cataloage1.size())
                                    {

                                    }
                                    else
                                    {
                                        throw out_of_range("Index invalid. Index-ul introdus nu exista.");
                                    }
                                }
                                catch (const out_of_range& e)
                                {
                                    cout <<endl<< "Eroare: " << e.what() << endl;
                                    pauza(3);
                                    clearScreen();
                                    break;
                                }

                                cout<<"Introduceti nota: ";
                                int nota;

                                do
                                {
                                    try
                                    {
                                        string input;
                                        cin >> input;
                                        stringstream ss(input);

                                        ss >> nota;

                                        if (ss.fail())
                                        {
                                            throw invalid_argument("Input invalid. Te rog introdu o nota valida.");
                                        }

                                        char remainingChar;
                                        if (ss >> remainingChar)
                                        {
                                            throw invalid_argument("Input invalid. Au fost gasite caractere suplimentare.");
                                        }

                                        if (nota <1 || nota >10)
                                        {
                                            throw invalid_argument("Input invalid. Te rog introdu un numar de la 1 la 10.");
                                        }

                                        break; // Inputul este valid
                                    }
                                    catch (const invalid_argument& e)
                                    {
                                        cout << e.what() << " Incearca din nou: ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    }
                                }
                                while (true);

                                cataloage1[Index]->addGrade(ID,nota);

                                cout<<endl<<"Nota adaugata cu succes."<<endl;
                                pauza(4);
                                clearScreen();
                                break;


                            }


                            if(nr==2)
                            {
                                cout<<endl;
                                try
                                {
                                    bool foundCatalog = false;
                                    int i=0;
                                    for (const auto& catalog : cataloage2)
                                    {
                                        cout<<i<<". " << endl << *catalog<<endl;
                                        foundCatalog=true;
                                        i++;
                                    }



                                    if (!foundCatalog)
                                    {
                                        throw runtime_error("Nu exista cataloage internationale.");

                                    }
                                }
                                catch (const exception& e)
                                {
                                    cout << "Eroare: " << e.what() << endl<<endl;
                                    pauza(3);
                                    clearScreen();
                                    break;
                                }
                                cout<<"Introduceti Index-ul catalogului international unde doriti sa adaugati nota: ";
                                int Index;

                                while (true)
                                {
                                    try
                                    {
                                        string input;
                                        cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                        stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                        ss >> Index; // Extrage valoarea intreaga din stringstream si o atribuie variabilei Index

                                        if (ss.fail())
                                        {
                                            throw invalid_argument("Index invalid. Te rog introdu un Index valid.");
                                        }

                                        char remainingChar;
                                        if (ss >> remainingChar)
                                        {
                                            throw invalid_argument("Index invalid. Au fost gasite caractere suplimentare.");
                                        }

                                        break; // Inputul este valid
                                    }
                                    catch (const invalid_argument& e)
                                    {
                                        cout << e.what() << " Incearca din nou: ";
                                        cin.clear(); // Reseteaza starea de eroare
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                    }
                                }
                                try
                                {
                                    if (Index >= 0 && Index < cataloage2.size())
                                    {

                                    }
                                    else
                                    {
                                        throw out_of_range("Index invalid. Index-ul introdus nu exista.");
                                    }
                                }
                                catch (const out_of_range& e)
                                {
                                    cout <<endl<< "Eroare: " << e.what() << endl;
                                    pauza(3);
                                    clearScreen();
                                    break;
                                }

                                cout<<"Introduceti nota: ";
                                char nota;

                                do
                                {
                                    try
                                    {
                                        string input;
                                        cin >> input;
                                        stringstream ss(input);

                                        ss >> nota;

                                        if (ss.fail())
                                        {
                                            throw invalid_argument("Input invalid. Te rog introdu o nota valida.");
                                        }

                                        char remainingChar;
                                        if (ss >> remainingChar)
                                        {
                                            throw invalid_argument("Input invalid. Au fost gasite caractere suplimentare.");
                                        }

                                        // Convert the input to uppercase for comparison
                                        nota = toupper(nota);

                                        if (nota != 'A' && nota != 'B' && nota != 'C' && nota != 'D' && nota != 'E' && nota != 'F')
                                        {
                                            throw invalid_argument("Input invalid. Te rog introdu o nota valida (A, B, C, D, E sau F).");
                                        }

                                        break; // Inputul este valid
                                    }
                                    catch (const invalid_argument& e)
                                    {
                                        cout << e.what() << " Incearca din nou: ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    }
                                }
                                while (true);


                                cataloage2[Index]->addGrade(ID,nota);

                                cout<<endl<<"Nota adaugata cu succes."<<endl;
                                pauza(4);
                                clearScreen();
                                break;


                            }


                        }
                        case 14:
                        {

                            clearScreen();

                            try
                            {
                                bool foundStudent = false;
                                for (const auto& persoana : persoane)
                                {
                                    if (typeid(*persoana) == typeid(Student))
                                    {
                                        foundStudent = true;
                                        cout << dynamic_cast<Student&>(*persoana) << endl;
                                    }
                                    if (typeid(*persoana) == typeid(StudentInternational))
                                    {
                                        foundStudent = true;
                                        cout << dynamic_cast<StudentInternational&>(*persoana) << endl;
                                    }
                                }

                                if (!foundStudent)
                                {
                                    throw runtime_error("Nu exista studenti.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }

                            cout<<"Introduceti ID-ul studentului caruia doriti sa ii eliminati o nota: ";
                            int ID;

                            while (true)
                            {
                                try
                                {
                                    string input;
                                    cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                    stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                    ss >> ID; // Extrage valoarea intreaga din stringstream si o atribuie variabilei ID

                                    if (ss.fail())
                                    {
                                        throw invalid_argument("ID invalid. Te rog introdu un ID valid.");
                                    }

                                    char remainingChar;
                                    if (ss >> remainingChar)
                                    {
                                        throw invalid_argument("ID invalid. Au fost gasite caractere suplimentare.");
                                    }

                                    break; // Inputul este valid
                                }
                                catch (const invalid_argument& e)
                                {
                                    cout << e.what() << " Incearca din nou: ";
                                    cin.clear(); // Reseteaza starea de eroare
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                }
                            }

                            try
                            {
                                bool foundStudent = false;
                                for (auto it = persoane.begin(); it != persoane.end(); )
                                {
                                    if (typeid(*(*it)) == typeid(Student) && dynamic_cast<Student&>(*(*it)).getId() == ID)
                                    {
                                        foundStudent = true;

                                    }


                                    if (typeid(*(*it)) == typeid(StudentInternational) && dynamic_cast<StudentInternational&>(*(*it)).getId() == ID)
                                    {
                                        foundStudent = true;

                                    }

                                    ++it;

                                }


                                if (!foundStudent)
                                {
                                    throw runtime_error("Nu exista studentul cu ID-ul respectiv.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout <<endl<< "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }


                            cout<<"Introduceti '1' pentru a selecta cataloagele sau '2' pentru a selecta cataloagele internationale: ";
                            int nr;

                            do
                            {
                                try
                                {
                                    string input;
                                    cin >> input;
                                    stringstream ss(input);

                                    ss >> nr;

                                    if (ss.fail())
                                    {
                                        throw invalid_argument("Input invalid. Te rog introdu un numar valid.");
                                    }

                                    char remainingChar;
                                    if (ss >> remainingChar)
                                    {
                                        throw invalid_argument("Input invalid. Au fost gasite caractere suplimentare.");
                                    }

                                    if (nr != 1 && nr != 2)
                                    {
                                        throw invalid_argument("Input invalid. Te rog introdu 1 sau 2.");
                                    }

                                    break; // Inputul este valid
                                }
                                catch (const invalid_argument& e)
                                {
                                    cout << e.what() << " Incearca din nou: ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                            }
                            while (true);

                            if(nr==1)
                            {
                                cout<<endl;
                                try
                                {
                                    bool foundCatalog = false;
                                    int i=0;
                                    for (const auto& catalog : cataloage1)
                                    {
                                        cout<<i<<". " << endl << *catalog<<endl;
                                        foundCatalog=true;
                                        i++;
                                    }



                                    if (!foundCatalog)
                                    {
                                        throw runtime_error("Nu exista cataloage.");

                                    }
                                }
                                catch (const exception& e)
                                {
                                    cout << "Eroare: " << e.what() << endl<<endl;
                                    pauza(3);
                                    clearScreen();
                                    break;
                                }
                                cout<<"Introduceti Index-ul catalogului unde doriti sa eliminati nota: ";
                                int Index;

                                while (true)
                                {
                                    try
                                    {
                                        string input;
                                        cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                        stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                        ss >> Index; // Extrage valoarea intreaga din stringstream si o atribuie variabilei Index

                                        if (ss.fail())
                                        {
                                            throw invalid_argument("Index invalid. Te rog introdu un Index valid.");
                                        }

                                        char remainingChar;
                                        if (ss >> remainingChar)
                                        {
                                            throw invalid_argument("Index invalid. Au fost gasite caractere suplimentare.");
                                        }

                                        break; // Inputul este valid
                                    }
                                    catch (const invalid_argument& e)
                                    {
                                        cout << e.what() << " Incearca din nou: ";
                                        cin.clear(); // Reseteaza starea de eroare
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                    }
                                }
                                try
                                {
                                    if (Index >= 0 && Index < cataloage1.size())
                                    {

                                    }
                                    else
                                    {
                                        throw out_of_range("Index invalid. Index-ul introdus nu exista.");
                                    }
                                }
                                catch (const out_of_range& e)
                                {
                                    cout <<endl<< "Eroare: " << e.what() << endl;
                                    pauza(3);
                                    clearScreen();
                                    break;
                                }

                                cout<<"Introduceti nota pe care doriti sa o eliminati: ";
                                int nota;

                                do
                                {
                                    try
                                    {
                                        string input;
                                        cin >> input;
                                        stringstream ss(input);

                                        ss >> nota;

                                        if (ss.fail())
                                        {
                                            throw invalid_argument("Input invalid. Te rog introdu o nota valida.");
                                        }

                                        char remainingChar;
                                        if (ss >> remainingChar)
                                        {
                                            throw invalid_argument("Input invalid. Au fost gasite caractere suplimentare.");
                                        }

                                        if (nota <1 || nota >10)
                                        {
                                            throw invalid_argument("Input invalid. Te rog introdu un numar de la 1 la 10.");
                                        }

                                        break; // Inputul este valid
                                    }
                                    catch (const invalid_argument& e)
                                    {
                                        cout << e.what() << " Incearca din nou: ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    }
                                }
                                while (true);

                                cataloage1[Index]->removeGrade(ID,nota);

                                cout<<endl<<"Nota eliminata cu succes."<<endl;
                                pauza(4);
                                clearScreen();
                                break;


                            }


                            if(nr==2)
                            {
                                cout<<endl;
                                try
                                {
                                    bool foundCatalog = false;
                                    int i=0;
                                    for (const auto& catalog : cataloage2)
                                    {
                                        cout<<i<<". " << endl << *catalog<<endl;
                                        foundCatalog=true;
                                        i++;
                                    }



                                    if (!foundCatalog)
                                    {
                                        throw runtime_error("Nu exista cataloage internationale.");

                                    }
                                }
                                catch (const exception& e)
                                {
                                    cout << "Eroare: " << e.what() << endl<<endl;
                                    pauza(3);
                                    clearScreen();
                                    break;
                                }
                                cout<<"Introduceti Index-ul catalogului international unde doriti sa eliminati nota: ";
                                int Index;

                                while (true)
                                {
                                    try
                                    {
                                        string input;
                                        cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                        stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                        ss >> Index; // Extrage valoarea intreaga din stringstream si o atribuie variabilei Index

                                        if (ss.fail())
                                        {
                                            throw invalid_argument("Index invalid. Te rog introdu un Index valid.");
                                        }

                                        char remainingChar;
                                        if (ss >> remainingChar)
                                        {
                                            throw invalid_argument("Index invalid. Au fost gasite caractere suplimentare.");
                                        }

                                        break; // Inputul este valid
                                    }
                                    catch (const invalid_argument& e)
                                    {
                                        cout << e.what() << " Incearca din nou: ";
                                        cin.clear(); // Reseteaza starea de eroare
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                    }
                                }
                                try
                                {
                                    if (Index >= 0 && Index < cataloage2.size())
                                    {

                                    }
                                    else
                                    {
                                        throw out_of_range("Index invalid. Index-ul introdus nu exista.");
                                    }
                                }
                                catch (const out_of_range& e)
                                {
                                    cout <<endl<< "Eroare: " << e.what() << endl;
                                    pauza(3);
                                    clearScreen();
                                    break;
                                }

                                cout<<"Introduceti nota pe care doriti sa o eliminati: ";
                                char nota;

                                do
                                {
                                    try
                                    {
                                        string input;
                                        cin >> input;
                                        stringstream ss(input);

                                        ss >> nota;

                                        if (ss.fail())
                                        {
                                            throw invalid_argument("Input invalid. Te rog introdu o nota valida.");
                                        }

                                        char remainingChar;
                                        if (ss >> remainingChar)
                                        {
                                            throw invalid_argument("Input invalid. Au fost gasite caractere suplimentare.");
                                        }

                                        // Convert the input to uppercase for comparison
                                        nota = toupper(nota);

                                        if (nota != 'A' && nota != 'B' && nota != 'C' && nota != 'D' && nota != 'E' && nota != 'F')
                                        {
                                            throw invalid_argument("Input invalid. Te rog introdu o nota valida (A, B, C, D, E sau F).");
                                        }

                                        break; // Inputul este valid
                                    }
                                    catch (const invalid_argument& e)
                                    {
                                        cout << e.what() << " Incearca din nou: ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    }
                                }
                                while (true);


                                cataloage2[Index]->removeGrade(ID,nota);

                                cout<<endl<<"Nota eliminata cu succes."<<endl;
                                pauza(4);
                                clearScreen();
                                break;


                            }


                        }
                        case 15:
                        {
                            clearScreen();
                            try
                            {
                                bool foundStudent = false;
                                for (const auto& persoana : persoane)
                                {
                                    if (typeid(*persoana) == typeid(Student))
                                    {
                                        foundStudent = true;
                                        cout << dynamic_cast<Student&>(*persoana) << endl;
                                    }
                                    if (typeid(*persoana) == typeid(StudentInternational))
                                    {
                                        foundStudent = true;
                                        cout << dynamic_cast<StudentInternational&>(*persoana) << endl;
                                    }
                                }

                                if (!foundStudent)
                                {
                                    throw runtime_error("Nu exista studenti.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }

                            cout<<"Introduceti ID-ul studentului caruia doriti sa ii adaugati o materie la care este olimpic: ";
                            int ID;

                            while (true)
                            {
                                try
                                {
                                    string input;
                                    cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                    stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                    ss >> ID; // Extrage valoarea intreaga din stringstream si o atribuie variabilei ID

                                    if (ss.fail())
                                    {
                                        throw invalid_argument("ID invalid. Te rog introdu un ID valid.");
                                    }

                                    char remainingChar;
                                    if (ss >> remainingChar)
                                    {
                                        throw invalid_argument("ID invalid. Au fost gasite caractere suplimentare.");
                                    }

                                    break; // Inputul este valid
                                }
                                catch (const invalid_argument& e)
                                {
                                    cout << e.what() << " Incearca din nou: ";
                                    cin.clear(); // Reseteaza starea de eroare
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                }
                            }

                            try
                            {
                                bool foundStudent = false;
                                for (auto it = persoane.begin(); it != persoane.end(); )
                                {
                                    if (typeid(*(*it)) == typeid(Student) && dynamic_cast<Student&>(*(*it)).getId() == ID)
                                    {
                                        foundStudent = true;

                                    }


                                    if (typeid(*(*it)) == typeid(StudentInternational) && dynamic_cast<StudentInternational&>(*(*it)).getId() == ID)
                                    {
                                        foundStudent = true;

                                    }

                                    ++it;

                                }


                                if (!foundStudent)
                                {
                                    throw runtime_error("Nu exista studentul cu ID-ul respectiv.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout <<endl<< "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }

                            cout<<"Introduceti materia: ";
                            cin.ignore();
                            string materie;
                            getline(cin, materie);
                            for (auto it = persoane.begin(); it != persoane.end(); )
                            {
                                if (typeid(*(*it)) == typeid(Student) && dynamic_cast<Student&>(*(*it)).getId() == ID)
                                {
                                    dynamic_cast<Student&>(*(*it)).addMaterie(materie);

                                }


                                if (typeid(*(*it)) == typeid(StudentInternational) && dynamic_cast<StudentInternational&>(*(*it)).getId() == ID)
                                {

                                    dynamic_cast<StudentInternational&>(*(*it)).addMaterie(materie);
                                }

                                ++it;

                            }




                            cout<<endl<<"Materie adaugata cu succes."<<endl;
                            pauza(3);



                            clearScreen();
                            break;

                        }
                        case 16:
                        {
                            clearScreen();
                            try
                            {
                                bool foundCatalog = false;
                                int i=0;
                                for (const auto& catalog : cataloage1)
                                {
                                    cout<<i<<". " << endl << *catalog<<endl;
                                    foundCatalog=true;
                                    i++;
                                }



                                if (!foundCatalog)
                                {
                                    throw runtime_error("Nu exista cataloage.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }
                            cout<<"Introduceti Index-ul catalogului caruia doriti sa ii schimbati profesorul: ";
                            int Index;

                            while (true)
                            {
                                try
                                {
                                    string input;
                                    cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                    stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                    ss >> Index; // Extrage valoarea intreaga din stringstream si o atribuie variabilei Index

                                    if (ss.fail())
                                    {
                                        throw invalid_argument("Index invalid. Te rog introdu un Index valid.");
                                    }

                                    char remainingChar;
                                    if (ss >> remainingChar)
                                    {
                                        throw invalid_argument("Index invalid. Au fost gasite caractere suplimentare.");
                                    }

                                    break; // Inputul este valid
                                }
                                catch (const invalid_argument& e)
                                {
                                    cout << e.what() << " Incearca din nou: ";
                                    cin.clear(); // Reseteaza starea de eroare
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                }
                            }
                            try
                            {
                                if (Index >= 0 && Index < cataloage1.size())
                                {

                                }
                                else
                                {
                                    throw out_of_range("Index invalid. Index-ul introdus nu exista.");
                                }
                            }
                            catch (const out_of_range& e)
                            {
                                cout <<endl<< "Eroare: " << e.what() << endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }
                            cout<<"Introduceti numele noului profesor: ";
                            cin.ignore();
                            string profesor;
                            getline(cin, profesor);
                            cataloage1[Index]->settNumeProfesor(profesor);

                            cout<<endl<<"Profesor schimbat cu succes.";
                            pauza(3);



                            clearScreen();
                            break;


                        }
                        case 17:
                        {
                            clearScreen();
                            try
                            {
                                bool foundCatalog = false;
                                int i=0;
                                for (const auto& catalog : cataloage2)
                                {
                                    cout<<i<<". " << endl << *catalog<<endl;
                                    foundCatalog=true;
                                    i++;
                                }



                                if (!foundCatalog)
                                {
                                    throw runtime_error("Nu exista cataloage internationale.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }
                            cout<<"Introduceti Index-ul catalogului international caruia doriti sa ii schimbati profesorul: ";
                            int Index;

                            while (true)
                            {
                                try
                                {
                                    string input;
                                    cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                    stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                    ss >> Index; // Extrage valoarea intreaga din stringstream si o atribuie variabilei Index

                                    if (ss.fail())
                                    {
                                        throw invalid_argument("Index invalid. Te rog introdu un Index valid.");
                                    }

                                    char remainingChar;
                                    if (ss >> remainingChar)
                                    {
                                        throw invalid_argument("Index invalid. Au fost gasite caractere suplimentare.");
                                    }

                                    break; // Inputul este valid
                                }
                                catch (const invalid_argument& e)
                                {
                                    cout << e.what() << " Incearca din nou: ";
                                    cin.clear(); // Reseteaza starea de eroare
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                }
                            }
                            try
                            {
                                if (Index >= 0 && Index < cataloage1.size())
                                {

                                }
                                else
                                {
                                    throw out_of_range("Index invalid. Index-ul introdus nu exista.");
                                }
                            }
                            catch (const out_of_range& e)
                            {
                                cout <<endl<< "Eroare: " << e.what() << endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }
                            cout<<"Introduceti numele noului profesor: ";
                            cin.ignore();
                            string profesor;
                            getline(cin, profesor);
                            cataloage2[Index]->settNumeProfesor(profesor);

                            cout<<endl<<"Profesor schimbat cu succes.";
                            pauza(3);



                            clearScreen();
                            break;


                        }
                        case 18:
                        {
                            clearScreen();
                            try
                            {
                                bool foundCatalog = false;
                                int i=0;
                                for (const auto& catalog : cataloage1)
                                {
                                    cout<<i<<". " << endl << *catalog<<endl;
                                    foundCatalog=true;
                                    i++;
                                }



                                if (!foundCatalog)
                                {
                                    throw runtime_error("Nu exista cataloage.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }
                            cout<<"Introduceti Index-ul catalogului caruia doriti sa ii schimbati materia: ";
                            int Index;

                            while (true)
                            {
                                try
                                {
                                    string input;
                                    cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                    stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                    ss >> Index; // Extrage valoarea intreaga din stringstream si o atribuie variabilei Index

                                    if (ss.fail())
                                    {
                                        throw invalid_argument("Index invalid. Te rog introdu un Index valid.");
                                    }

                                    char remainingChar;
                                    if (ss >> remainingChar)
                                    {
                                        throw invalid_argument("Index invalid. Au fost gasite caractere suplimentare.");
                                    }

                                    break; // Inputul este valid
                                }
                                catch (const invalid_argument& e)
                                {
                                    cout << e.what() << " Incearca din nou: ";
                                    cin.clear(); // Reseteaza starea de eroare
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                }
                            }
                            try
                            {
                                if (Index >= 0 && Index < cataloage1.size())
                                {

                                }
                                else
                                {
                                    throw out_of_range("Index invalid. Index-ul introdus nu exista.");
                                }
                            }
                            catch (const out_of_range& e)
                            {
                                cout <<endl<< "Eroare: " << e.what() << endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }
                            cout<<"Introduceti numele noii materii: ";
                            cin.ignore();
                            string materie;
                            getline(cin, materie);
                            cataloage1[Index]->settMaterie(materie);

                            cout<<endl<<"Materie schimbata cu succes.";
                            pauza(3);



                            clearScreen();
                            break;


                        }
                        case 19:
                        {
                            clearScreen();
                            try
                            {
                                bool foundCatalog = false;
                                int i=0;
                                for (const auto& catalog : cataloage2)
                                {
                                    cout<<i<<". " << endl << *catalog<<endl;
                                    foundCatalog=true;
                                    i++;
                                }



                                if (!foundCatalog)
                                {
                                    throw runtime_error("Nu exista cataloage internationale.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }
                            cout<<"Introduceti Index-ul catalogului international caruia doriti sa ii schimbati materia: ";
                            int Index;

                            while (true)
                            {
                                try
                                {
                                    string input;
                                    cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                    stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                    ss >> Index; // Extrage valoarea intreaga din stringstream si o atribuie variabilei Index

                                    if (ss.fail())
                                    {
                                        throw invalid_argument("Index invalid. Te rog introdu un Index valid.");
                                    }

                                    char remainingChar;
                                    if (ss >> remainingChar)
                                    {
                                        throw invalid_argument("Index invalid. Au fost gasite caractere suplimentare.");
                                    }

                                    break; // Inputul este valid
                                }
                                catch (const invalid_argument& e)
                                {
                                    cout << e.what() << " Incearca din nou: ";
                                    cin.clear(); // Reseteaza starea de eroare
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                }
                            }
                            try
                            {
                                if (Index >= 0 && Index < cataloage1.size())
                                {

                                }
                                else
                                {
                                    throw out_of_range("Index invalid. Index-ul introdus nu exista.");
                                }
                            }
                            catch (const out_of_range& e)
                            {
                                cout <<endl<< "Eroare: " << e.what() << endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }
                            cout<<"Introduceti numele noii materii: ";
                            cin.ignore();
                            string materie;
                            getline(cin, materie);
                            cataloage2[Index]->settMaterie(materie);

                            cout<<endl<<"Materie schimbata cu succes.";
                            pauza(3);



                            clearScreen();
                            break;


                        }
                        case 20:
                        {
                            clearScreen();
                            int S1=0;
                            int S2=0;

                            for (int i=0; i<persoane.size(); i++)
                            {
                                if(typeid(*persoane[i])==typeid(Student))
                                    S1=S1+persoane[i]->taxa();
                                if(typeid(*persoane[i])==typeid(StudentInternational))
                                    S2=S2+persoane[i]->taxa();



                            }

                            cout<<"---Fondurile Institutiei de Invatamant---"<<endl<<endl;
                            cout<< "Taxele de la studenti : " << S1 << " lei." << endl;
                            cout<< "Taxele de la studenti internationali: " << S2<<" lei." << endl;
                            cout<<"Total: " << S1+S2 << " lei." << endl <<endl;
                            cout << "Apasa 'enter' pentru a reveni la meniu." << endl;
                            cin.ignore();
                            while (cin.get() != '\n');

                            clearScreen();
                            break;

                        }
                        case 21:
                        {
                            clearScreen();
                            cout<<"Fisierul trebuie sa aiba urmatorul format pe fiecare linie: Nume, AnulNasterii, {Materie1, Materie2...}"<<endl;
                            cout<<"Exemplu de fisier formatat corect: " <<endl<<endl;
                            cout<<"Albert, 1998, {English, History}"<<endl<<"Emma Watson, 2002, {Biology, Computer Science}"<<endl<<endl;
                            cout<<"Orice fisier formatat gresit va duce la coruptia datelor."<<endl<<endl;

                            cnt256=0;
                            string fileName;
                            cout<<"Introduceti numele fisierului: ";
                            cin.ignore();
                            getline(cin, fileName);
                            importStudents(fileName);

                            if(cnt256!=0)
                                cout<<endl<<"IMPORT realizat cu succes.";
                            pauza(3);
                            clearScreen();
                            break;

                        }
                        case 22:
                        {
                            clearScreen();
                            cout<<"Fisierul trebuie sa aiba urmatorul format pe fiecare linie: Nume, AnulNasterii, {Materie1, Materie2...}, Tara"<<endl;
                            cout<<"Exemplu de fisier formatat corect: " <<endl<<endl;
                            cout<<"Sophia Lee, 2001, {English, History}, Europe"<<endl<<"Muhammad Ali, 2003, {Biology, Computer Science}, Asia"<<endl<<endl;
                            cout<<"Orice fisier formatat gresit va duce la coruptia datelor."<<endl<<endl;


                            cnt256=0;
                            string fileName;
                            cout<<"Introduceti numele fisierului: ";
                            cin.ignore();
                            getline(cin, fileName);
                            importStudentInternationals(fileName);

                            if(cnt256!=0)
                                cout<<endl<<"IMPORT realizat cu succes.";
                            pauza(3);
                            clearScreen();
                            break;

                        }
                        case 23:
                        {
                            clearScreen();

                            try
                            {
                                bool foundCatalog = false;
                                int i=0;
                                for (const auto& catalog : cataloage1)
                                {
                                    cout<<i<<". " << endl << *catalog<<endl;
                                    foundCatalog=true;
                                    i++;
                                }



                                if (!foundCatalog)
                                {
                                    throw runtime_error("Nu exista cataloage.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }
                            cout<<"Introduceti Index-ul catalogului pe care doriti sa il exportati: ";
                            int Index;

                            while (true)
                            {
                                try
                                {
                                    string input;
                                    cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                    stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                    ss >> Index; // Extrage valoarea intreaga din stringstream si o atribuie variabilei Index

                                    if (ss.fail())
                                    {
                                        throw invalid_argument("Index invalid. Te rog introdu un Index valid.");
                                    }

                                    char remainingChar;
                                    if (ss >> remainingChar)
                                    {
                                        throw invalid_argument("Index invalid. Au fost gasite caractere suplimentare.");
                                    }

                                    break; // Inputul este valid
                                }
                                catch (const invalid_argument& e)
                                {
                                    cout << e.what() << " Incearca din nou: ";
                                    cin.clear(); // Reseteaza starea de eroare
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                }
                            }
                            try
                            {
                                if (Index >= 0 && Index < cataloage1.size())
                                {

                                }
                                else
                                {
                                    throw out_of_range("Index invalid. Index-ul introdus nu exista.");
                                }
                            }
                            catch (const out_of_range& e)
                            {
                                cout <<endl<< "Eroare: " << e.what() << endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }


                            cnt255=0;
                            cataloage1[Index]->exportToFile("catalog.txt");
                            if(cnt255!=0)
                                cout<<endl<<"EXPORT realizat cu succes."<<endl;
                            pauza(3);
                            clearScreen();
                            break;

                        }
                        case 24:
                        {
                            clearScreen();

                            try
                            {
                                bool foundCatalog = false;
                                int i=0;
                                for (const auto& catalog : cataloage2)
                                {
                                    cout<<i<<". " << endl << *catalog<<endl;
                                    foundCatalog=true;
                                    i++;
                                }



                                if (!foundCatalog)
                                {
                                    throw runtime_error("Nu exista cataloage internationale.");

                                }
                            }
                            catch (const exception& e)
                            {
                                cout << "Eroare: " << e.what() << endl<<endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }
                            cout<<"Introduceti Index-ul catalogului international pe care doriti sa il exportati: ";
                            int Index;

                            while (true)
                            {
                                try
                                {
                                    string input;
                                    cin >> input; // Citeste inputul de la utilizator in variabila input de tip string
                                    stringstream ss(input); // Creaza un stringstream folosind inputul citit

                                    ss >> Index; // Extrage valoarea intreaga din stringstream si o atribuie variabilei Index

                                    if (ss.fail())
                                    {
                                        throw invalid_argument("Index invalid. Te rog introdu un Index valid.");
                                    }

                                    char remainingChar;
                                    if (ss >> remainingChar)
                                    {
                                        throw invalid_argument("Index invalid. Au fost gasite caractere suplimentare.");
                                    }

                                    break; // Inputul este valid
                                }
                                catch (const invalid_argument& e)
                                {
                                    cout << e.what() << " Incearca din nou: ";
                                    cin.clear(); // Reseteaza starea de eroare
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracterele ramase in bufferul de intrare
                                }
                            }
                            try
                            {
                                if (Index >= 0 && Index < cataloage1.size())
                                {

                                }
                                else
                                {
                                    throw out_of_range("Index invalid. Index-ul introdus nu exista.");
                                }
                            }
                            catch (const out_of_range& e)
                            {
                                cout <<endl<< "Eroare: " << e.what() << endl;
                                pauza(3);
                                clearScreen();
                                break;
                            }

                            cnt255=0;
                            cataloage2[Index]->exportToFile("catalog.txt");
                            if(cnt255!=0)
                                cout<<endl<<"EXPORT realizat cu succes."<<endl;
                            pauza(3);
                            clearScreen();
                            break;

                        }
                        case 25:
                        {
                            clearScreen();


                            clearScreen();
                            break;

                        }


                        default:
                        {
                            clearScreen();
                            cout << "Comanda invalida. Folositi o comanda valida." << endl<<endl;
                            break;
                        }

                        }


                        if (comanda3==25)
                            break;
                    }


                }
                else
                {
                    cout<<endl;
                    cout << "Acces restrictionat. Parola incorecta." << endl;
                    pauza(3);
                    clearScreen();
                }
                break;
            }
            case 3:
            {

                break;
            }
            default:
            {
                clearScreen();
                cout << "Comanda invalida. Folositi o comanda valida." << endl<<endl;
                break;
            }
            }
            if(comanda==3)
            {
                clearScreen();
                break;

            }
        }
        cout<<"La revedere!" << endl;
    }

    void BazaDeDate()
    {
        persoane.push_back(new Student("Codarcea Alexandru", 2003, {"Matematica", "Informatica"}));
        persoane.push_back(new Student("Ionescu Maria", 2002, {"Romana", "Biologie"}));
        persoane.push_back(new Student("Popescu Ion", 2004, {"Istorie", "Geografie"}));
        persoane.push_back(new Student("Dumitrescu Ana", 2003, {"Fizica", "Chimie"}));
        persoane.push_back(new Student("Radulescu Andrei", 2001, {"Limba Engleza", "Economie"}));
        persoane.push_back(new Student("Popa Ioana", 2003, {"Biologie", "Fizica"}));
        persoane.push_back(new Student("Georgescu Andrei", 2002, {"Matematica", "Informatica"}));
        persoane.push_back(new Student("Popescu Ana", 2004, {"Chimie", "Fizica"}));
        persoane.push_back(new Student("Ionescu Ion", 2001, {"Istorie", "Geografie"}));
        persoane.push_back(new Student("Mihai Ioana", 2003, {"Biologie", "Romana"}));
        persoane.push_back(new Student("Stanescu Vasile", 2002, {"Matematica", "Fizica"}));
        persoane.push_back(new Student("Constantin Maria", 2004, {"Limba Engleza", "Informatica"}));
        persoane.push_back(new Student("Stancu Andrei", 2001, {"Geografie", "Istorie"}));
        persoane.push_back(new Student("Dinu Alina", 2003, {"Biologie", "Chimie"}));
        persoane.push_back(new Student("Matei Stefan", 2002, {"Romana", "Matematica"}));
        persoane.push_back(new Student("Popovici Ana", 2004, {"Informatica", "Fizica"}));
        persoane.push_back(new Student("Dumitru Ion", 2001, {"Istorie", "Limba Engleza"}));
        persoane.push_back(new Student("Munteanu Ioana", 2003, {"Biologie", "Geografie"}));
        persoane.push_back(new Student("Radu Andrei", 2002, {"Matematica", "Romana"}));
        persoane.push_back(new Student("Diaconu Maria", 2004, {"Chimie", "Fizica"}));
        persoane.push_back(new Student("Iordache Ionut", 2001, {"Istorie", "Informatica"}));
        persoane.push_back(new Student("Popa Andreea", 2003, {"Biologie", "Limba Engleza"}));
        persoane.push_back(new Student("Dumitrache Andrei", 2002, {"Fizica", "Geografie"}));
        persoane.push_back(new Student("Constantinescu Ana", 2004, {"Matematica", "Chimie"}));
        persoane.push_back(new Student("Stoica Maria", 2001, {"Romana", "Informatica"}));

        persoane.push_back(new StudentInternational("Stefanos Jamal", 2003, {"Maths", "Biology"}, "United States"));
        persoane.push_back(new StudentInternational("Johnson Emily", 2002, {"English", "History"}, "United Kingdom"));
        persoane.push_back(new StudentInternational("Smith Daniel", 2004, {"Chemistry", "Physics"}, "Canada"));
        persoane.push_back(new StudentInternational("Anderson Sophia", 2003, {"Economics", "Business"}, "Australia"));
        persoane.push_back(new StudentInternational("Brown Olivia", 2001, {"Computer Science", "Maths"}, "Germany"));
        persoane.push_back(new StudentInternational("Davis Ethan", 2003, {"Biology", "Chemistry"}, "France"));
        persoane.push_back(new StudentInternational("Wilson Ava", 2002, {"Physics", "English"}, "Spain"));
        persoane.push_back(new StudentInternational("Taylor Benjamin", 2004, {"History", "Geography"}, "Italy"));
        persoane.push_back(new StudentInternational("Miller Mia", 2001, {"Maths", "Chemistry"}, "Japan"));
        persoane.push_back(new StudentInternational("Moore Jackson", 2003, {"English", "Literature"}, "Brazil"));
        persoane.push_back(new StudentInternational("Robinson Lily", 2002, {"Physics", "Biology"}, "Mexico"));
        persoane.push_back(new StudentInternational("Clark William", 2004, {"History", "Politics"}, "South Korea"));
        persoane.push_back(new StudentInternational("Lee Grace", 2001, {"Chemistry", "Maths"}, "China"));
        persoane.push_back(new StudentInternational("Hall Oliver", 2003, {"English", "Psychology"}, "India"));
        persoane.push_back(new StudentInternational("Turner Abigail", 2002, {"Biology", "Chemistry"}, "Sweden"));
        persoane.push_back(new StudentInternational("Parker Samuel", 2004, {"Physics", "Computer Science"}, "Netherlands"));
        persoane.push_back(new StudentInternational("Green Emily", 2001, {"History", "Geography"}, "New Zealand"));
        persoane.push_back(new StudentInternational("Harris Ava", 2003, {"Maths", "Chemistry"}, "Switzerland"));
        persoane.push_back(new StudentInternational("Baker Ethan", 2002, {"English", "Literature"}, "Norway"));
        persoane.push_back(new StudentInternational("Bell Lily", 2004, {"Physics", "Biology"}, "Russia"));

        cataloage1.push_back(new CatalogOnline<int>("Zidu George", "Matematica",
        {
            {0, {8, 9, 7, 6}},
            {1, {10, 9}},
            {7, {6, 4, 8, 10, 9}},
            {23, {9, 8, 7, 10}},
            {3, {8, 7, 3, 6, 10}},
            {2, {9, 8, 6}},
            {5, {7, 6, 8, 10}}
        }));

        cataloage1.push_back(new CatalogOnline<int>("Corina Barlan", "Romana",
        {
            {4, {9, 10, 9, 8}},
            {12, {8, 9, 7, 10}},
            {14, {10, 8, 9}},
            {19, {7, 9, 8}},
            {22, {9, 8, 2, 10}},
            {24, {8, 7, 9}}
        }));

        cataloage1.push_back(new CatalogOnline<int>("Manuela Stefanescu", "Fizica",
        {
            {11, {9, 8, 9, 7}},
            {13, {8, 9, 7}},
            {15, {10, 8, 9, 1}},
            {16, {7, 9, 8}},
            {17, {9, 8, 7}},
            {20, {8, 7, 9}},
            {21, {9, 2, 9}}
        }));

        cataloage1.push_back(new CatalogOnline<int>("Eduard Szmeteanca", "Informatica",
        {
            {0, {10, 1}},
            {3, {9, 8, 7, 10}},
            {6, {8, 7, 9}},
            {8, {9, 10, 9}},
            {9, {8, 9, 7}},
            {18, {10, 8, 9}},
            {23, {7, 3, 8}}
        }));

        cataloage1.push_back(new CatalogOnline<int>("Popescu Ion", "Biologie",
        {
            {1, {8, 7, 9}},
            {5, {2, 10}},
            {7, {8, 9, 7, 10}},
            {10, {10, 8, 9}},
            {13, {7, 3, 8}},
            {16, {9, 8, 7}},
            {22, {8, 7, 9, 10}}
        }));

        cataloage1.push_back(new CatalogOnline<int>("Viorica Alexandra", "Chimie",
        {
            {2, {9, 8}},
            {4, {8, 7, 9}},
            {11, {9, 10, 9}},
            {15, {8, 9, 7, 10}},
            {19, {10, 8, 9}},
            {20, {7, 9, 8}},
            {24, {9, 8, 7}}
        }));

        cataloage1.push_back(new CatalogOnline<int>("Chirita Valentina", "Geografie",
        {
            {1, {7, 9, 8}},
            {3, {9, 8, 7}},
            {5, {10, 9, 8}},
            {9, {8, 7, 9}},
            {12, {9, 10, 9}},
            {17, {4, 9, 7}},
            {21, {7, 9, 8}}
        }));

        cataloage1.push_back(new CatalogOnline<int>());


        cataloage2.push_back(new CatalogOnline<char>("James Thompson", "History",
        {
            {25, {'B', 'A', 'C'}},
            {26, {'D', 'F'}},
            {30, {'C', 'D', 'A', 'F'}},
            {35, {'B', 'C', 'D'}},
            {40, {'A', 'B', 'C', 'D'}},
            {42, {'A', 'C', 'F'}},
            {44, {'B', 'F'}}
        }));

        cataloage2.push_back(new CatalogOnline<char>("Emily Davis", "English",
        {
            {28, {'A', 'B', 'A', 'C'}},
            {31, {'C', 'D', 'E', 'F'}},
            {33, {'B', 'C', 'F'}},
            {36, {'A', 'C', 'D'}},
            {38, {'A', 'B', 'D', 'F'}},
            {41, {'A', 'B', 'C', 'E'}},
            {43, {'B', 'E', 'F'}}
        }));

        cataloage2.push_back(new CatalogOnline<char>("Samuel Turner", "Economics",
        {
            {25, {'A', 'B', 'C', 'D'}},
            {27, {'C', 'D', 'F'}},
            {29, {'B', 'D', 'E'}},
            {32, {'C', 'E', 'F'}},
            {34, {'A', 'C', 'D'}},
            {37, {'B', 'C', 'D', 'E'}},
            {39, {'A', 'C', 'F'}}
        }));

        cataloage2.push_back(new CatalogOnline<char>("Victoria Adams", "Art",
        {
            {26, {'B', 'C', 'E'}},
            {28, {'A', 'C', 'D', 'F'}},
            {30, {'B', 'C', 'D', 'E'}},
            {33, {'A', 'C', 'F'}},
            {35, {'C', 'D', 'E'}},
            {38, {'A', 'B', 'D'}},
            {42, {'B', 'E', 'F'}}
        }));

        cataloage2.push_back(new CatalogOnline<char>("Jonathan Mitchell", "Mathematics",
        {
            {27, {'A', 'B', 'C', 'E'}},
            {29, {'C', 'D', 'F'}},
            {31, {'B', 'C', 'D'}},
            {34, {'A', 'B', 'C', 'F'}},
            {36, {'B', 'D', 'E'}},
            {39, {'A', 'C', 'D'}},
            {43, {'B', 'C', 'E'}}
        }));

        cataloage2.push_back(new CatalogOnline<char>("Olivia Roberts", "French",
        {
            {25, {'A', 'C', 'D'}},
            {28, {'B', 'C', 'D', 'E'}},
            {30, {'C', 'E', 'F'}},
            {32, {'B', 'C', 'D'}},
            {35, {'A', 'C', 'D', 'F'}},
            {37, {'B', 'D', 'E'}},
            {40, {'A', 'B', 'C'}}
        }));

        cataloage2.push_back(new CatalogOnline<char>("Benjamin Wilson", "Computer Science",
        {
            {26, {'B', 'C', 'D', 'E'}},
            {29, {'A', 'C', 'D'}},
            {31, {'C', 'E', 'F'}},
            {33, {'A', 'B', 'C', 'F'}},
            {36, {'B', 'D', 'E'}},
            {38, {'C', 'D', 'F'}},
            {41, {'A', 'B', 'C'}}
        }));

        cataloage2.push_back(new CatalogOnline<char>());
    }

    ~Meniu()
    {
        nrOfInstances--;
        if(nrOfInstances==0)
            if(obj)
                delete obj;

    }

};

Meniu* Meniu::obj=0;
int Meniu::nrOfInstances=0;

int main()
{
    try
    {
        Meniu* meniu = Meniu::getInstance();
        meniu->BazaDeDate();
        meniu->MyApp();
    }
    catch(...)
    {
        cout<<endl<<"A intervenit o eroare. Va rugam reporniti aplicatia."<<endl;
    }

    return 0;

}

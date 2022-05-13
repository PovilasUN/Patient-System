#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

class Patient
{
private:
    string Name;
    string Surname;
    string ID;
    string Gender;
    string Age;
    string Time;
    string Symptoms;
public:
    Patient(string name, string surname, string id, string gender, string age, string time, string symptoms)
    {
        Name = name;
        Surname = surname;
        ID = id;
        Gender = gender;
        Age = age;
        Time = time;
        Symptoms = symptoms;
    }
    string GetName()
    {
        return Name;
    }
    string GetSurname()
    {
        return Surname;
    }
    string GetID()
    {
        return ID;
    }
    string GetGender()
    {
        return Gender;
    }
    string GetAge()
    {
        return Age;
    }
    string GetTime()
    {
        return Time;
    }
    string GetSymptoms()
    {
        return Symptoms;
    }
};

class System
{
public:
    void DisplaySchedule(queue<Patient> Schedule)
    {
        while (!Schedule.empty()) {
            cout << Schedule.front().GetName() << " | " << Schedule.front().GetSurname() << " | " << Schedule.front().GetID() << " | " << Schedule.front().GetGender() << " | " << Schedule.front().GetAge() << " | " << Schedule.front().GetTime() << " | " << Schedule.front().GetSymptoms() << endl;
            Schedule.pop();
        }
    }
    void UnexpectedPatient(queue<Patient> &Schedule)
    {
        string name;
        string surname;
        string id;
        string gender;
        string age;
        string time;
        string symptoms;
        cout << "Insert Patients Name: ";
        cin >> name;
        cout << "Insert Patients Surname: ";
        cin >> surname;
        cout << "Insert Patients ID: ";
        cin >> id;
        cout << "Insert Patients Gender: ";
        cin >> gender;
        cout << "Insert Patients Age: ";
        cin >> age;
        cout << "Insert Patients visit Time: "; 
        cin >> time;
        cout << "Insert Patients Symptoms: ";
        cin >> symptoms;
        Patient patient(name, surname, id, gender, age, time, symptoms);
        Schedule.push(patient);
    }
    void AddDiagnosis(queue<Patient> &Schedule)
    {
        string diagnosis;
        ofstream outFile;
        outFile.open("dataDiagnosis.csv",ios::app);
        cout << "Insert Patients Diagnosis: ";
        cin >> diagnosis;
        outFile << Schedule.front().GetName() << ";" << Schedule.front().GetSurname() << ";" << Schedule.front().GetID() << ";" << Schedule.front().GetGender() << ";" << Schedule.front().GetAge() << ";" << Schedule.front().GetTime() << ";" << Schedule.front().GetSymptoms() << ";" << diagnosis << endl;
        Schedule.pop();
    }
    void SearchForPatientName(queue<Patient> Schedule)
    {
        string NAME;
        string SURNAME;
        cout << "Insert Name/Surname: ";
        cin >> NAME;
        cin >> SURNAME;
        while (!Schedule.empty())
        {
            if (Schedule.front().GetName() == NAME && Schedule.front().GetSurname() == SURNAME)
            {
                cout << "Patient was found!\n";
                cout << Schedule.front().GetName() << " | " << Schedule.front().GetSurname() << " | " << Schedule.front().GetID() << " | " << Schedule.front().GetGender() << " | " << Schedule.front().GetAge() << " | " << Schedule.front().GetTime() << " | " << Schedule.front().GetSymptoms() << endl;
                break;
            }
            Schedule.pop();
            if (Schedule.size() == 0)
                cout << "No Patient was found!\n";
        }
    }
    void SearchForPatientID(queue<Patient> Schedule)
    {
        string identity;
        cout << "Insert ID: ";
        cin >> identity;
        while (!Schedule.empty())
        {
            if (Schedule.front().GetID() == identity)
            {
                cout << "Patient was found!\n";
                cout << Schedule.front().GetName() << " | " << Schedule.front().GetSurname() << " | " << Schedule.front().GetID() << " | " << Schedule.front().GetGender() << " | " << Schedule.front().GetAge() << " | " << Schedule.front().GetTime() << " | " << Schedule.front().GetSymptoms() << endl;
                break;
            }
            Schedule.pop();
            if (Schedule.size() == 0)
                cout << "No Patient was found!\n";
        }
    }
    void SearchForPatientTime(queue<Patient> Schedule)
    {
        string t;
        cout << "Insert Time: ";
        cin >> t;
        while (!Schedule.empty())
        {
            if (Schedule.front().GetTime() == t)
            {
                cout << "Patient was found!\n";
                cout << Schedule.front().GetName() << " | " << Schedule.front().GetSurname() << " | " << Schedule.front().GetID() << " | " << Schedule.front().GetGender() << " | " << Schedule.front().GetAge() << " | " << Schedule.front().GetTime() << " | " << Schedule.front().GetSymptoms() << endl;
                break;
            }
            Schedule.pop();
            if (Schedule.size() == 0)
                cout << "No Patient was found!\n";
        }
    }
};

queue<Patient> fRead()
{
    queue<Patient> Schedule;
    string name;
    string surname;
    string id;
    string gender;
    string age;
    string time;
    string symptoms;

    ifstream inFile;
    string tdate;

    while (!inFile.is_open())
    {
        cout << "Please enter todays date (YYYY-MM-DD).csv: ";
        cin >> tdate;
        inFile.open(tdate.c_str());
        if (inFile.is_open())
            cout << "File has been opened!" << endl;
        else
        {
            cout << "No file has been opened!" << endl;
            Sleep(2500);
            system("cls");
        }
    }

    while (true)
    {
        getline(inFile, name, ';');
        getline(inFile, surname, ';');
        getline(inFile, id, ';');
        getline(inFile, gender, ';');
        getline(inFile, age, ';');
        getline(inFile, time, ';');
        getline(inFile, symptoms);
        if (inFile.eof())
            break;
        Patient patient(name, surname, id, gender, age, time, symptoms);
        Schedule.push(patient);
    }
    inFile.close();
    Sleep(2500);
    system("cls");
    return Schedule;
}

int main()
{
    int input = 1;
    queue<Patient> Schedule = fRead();
    System functions;
    while (input != 0)
    {
        if (Schedule.size() == 0)
        {
            cout << "\nPatient Schedule System (PSS)\n";
            cout << "\nMENU\n";
            cout << "\nCurrent Patient: The Schedule is empty!\n" << endl;
            cout << "\t1.Display the whole Schedule\n";
            cout << "\t2.Insert an Unexpected Patient to the Schedule\n";
            cout << "\t3.Clear the Schedule\n";
            cout << "\t4.Insert Diagnosis\n";
            cout << "\t5.Search for Patient using NAME and SURNAME\n";
            cout << "\t6.Search for Patient using ID\n";
            cout << "\t7.Search for Patient using Time\n";
            cout << "\t0.End program\n";
            cin >> input;
            switch (input)
            {
            case 1:
                cout << "The Schedule is empty!\n";
                system("pause");
                system("cls");
                break;
            case 2:
                functions.UnexpectedPatient(Schedule);
                cout << "Patient has been inserted into the schedule!\n";
                Sleep(2500);
                system("cls");
                break;
            case 3:
                cout << "The Schedule is empty!\n";
                system("pause");
                system("cls");
                break;
            case 4:
                cout << "The Schedule is empty, no one to diagnose!\n";
                Sleep(2500);
                system("cls");
                break;
            case 5:
                cout << "The Schedule is empty!\n";
                Sleep(2500);
                system("cls");
                break;
            case 6:
                cout << "The Schedule is empty!\n";
                Sleep(2500);
                system("cls");
                break;
            case 7:
                cout << "The Schedule is empty!\n";
                Sleep(2500);
                system("cls");
                break;
            case 0:
                cout << "Schedule is clear!\n";
                cout << "Shutting down!\n";
                break;
            default:
                cout << "ERROR! Please choose a valid command.\n";
                Sleep(2500);
                system("cls");
                break;
            }
        }
        else
        {
            cout << "\nPatient Schedule System (PSS)\n";
            cout << "\nMENU\n";
            cout << "\nCurrent Patient: " << Schedule.front().GetName() << " | " << Schedule.front().GetSurname() << " | " << Schedule.front().GetID() << " | " << Schedule.front().GetGender() << " | " << Schedule.front().GetAge() << " | " << Schedule.front().GetTime() << " | " << Schedule.front().GetSymptoms() << "\n" << endl;
            cout << "\t1.Display the whole Schedule\n";
            cout << "\t2.Insert an Unexpected Patient to the Schedule\n";
            cout << "\t3.Clear the Schedule\n";
            cout << "\t4.Insert Diagnosis\n";
            cout << "\t5.Search for Patient using NAME and SURNAME\n";
            cout << "\t6.Search for Patient using ID\n";
            cout << "\t7.Search for Patient using Time\n";
            cout << "\t0.End program\n";
            cin >> input;
            switch (input)
            {
            case 1:
                 functions.DisplaySchedule(Schedule);
                 system("pause");
                 system("cls");
                 break;
            case 2:
                functions.UnexpectedPatient(Schedule);
                cout << "Patient has been inserted into the schedule!\n";
                Sleep(2500);
                system("cls");
                break;
            case 3:
                while (!Schedule.empty())
                {
                   Schedule.pop();
                }
                cout << "Schedule has been cleared!\n";
                Sleep(2500);
                system("cls");
                break;
            case 4:
                functions.AddDiagnosis(Schedule);
                cout << "Patient was diagnosed!\n";
                Sleep(2500);
                system("cls");
                break;
            case 5:
                functions.SearchForPatientName(Schedule);
                system("pause");
                system("cls");
                break;
            case 6:
                functions.SearchForPatientID(Schedule);
                system("pause");
                system("cls");
                break;
            case 7:
                functions.SearchForPatientTime(Schedule);
                system("pause");
                system("cls");
                break;
            case 0:
                while (!Schedule.empty())
                {
                   Schedule.pop();
                }
                cout << "Schedule has been cleared!\n";
                cout << "Shutting down!\n";
                break;
            default:
                cout << "ERROR! Please choose a valid command.\n";
                Sleep(2500);
                system("cls");
                break;
            }
        }
    }
    return 0;
}
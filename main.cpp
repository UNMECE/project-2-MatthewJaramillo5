#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

// After compiling the code, run "./student_app"
// This should create the student_app.dat file
// Finlly run "cat student_info.dat" in the terminal to print the student_app text

using namespace std;

string to_string(int value) {
    stringstream ss;
    ss << value;
    return ss.str();
}


enum Semester { SPRING, SUMMER, FALL };
enum Level { UNDERGRADUATE, GRADUATE };
enum ArtEmphasis { ART_STUDIO, ART_HISTORY, ART_EDUCATION };
enum PhysicsConcentration { BIOPHYSICS, EARTH_AND_PLANETARY_SCIENCES };

string semesterToString(Semester s) {
    switch (s) {
        case SPRING: return "Spring";
        case SUMMER: return "Summer";
        case FALL:   return "Fall";
        default:     return "Unknown";
    }
}

string levelToString(Level l) {
    return l == UNDERGRADUATE ? "Undergraduate" : "Graduate";
}

string emphasisToString(ArtEmphasis e) {
    switch (e) {
        case ART_STUDIO: return "Art Studio";
        case ART_HISTORY: return "Art History";
        case ART_EDUCATION: return "Art Education";
        default: return "Unknown";
    }
}

string concentrationToString(PhysicsConcentration c) {
    switch (c) {
        case BIOPHYSICS: return "Biophysics";
        case EARTH_AND_PLANETARY_SCIENCES: return "Earth and Planetary Sciences";
        default: return "Unknown";
    }
}

class Student {
protected:
    string first_name;
    string last_name;
    double gpa;
    int grad_year;
    Semester grad_semester;
    int enrolled_year;
    Semester enrolled_semester;
    Level level;

public:
    Student() {
        first_name = "John";
        last_name = "Doe";
        gpa = 0.0;
        grad_year = 2025;
        grad_semester = SPRING;
        enrolled_year = 2021;
        enrolled_semester = FALL;
        level = UNDERGRADUATE;
    }

    virtual ~Student() {}

    void setName(const string& first, const string& last) {
        first_name = first;
        last_name = last;
    }

    void setGPA(double value) { gpa = value; }

    void setGraduation(int year, Semester sem) {
        grad_year = year;
        grad_semester = sem;
    }

    void setEnrollment(int year, Semester sem) {
        enrolled_year = year;
        enrolled_semester = sem;
    }

    void setLevel(Level lvl) { level = lvl; }

    virtual void writeToFile(ofstream& out) const {
        out << first_name << " " << last_name
            << ", GPA: " << gpa
            << ", Level: " << levelToString(level)
            << ", Enrolled: " << enrolled_year << " " << semesterToString(enrolled_semester)
            << ", Graduation: " << grad_year << " " << semesterToString(grad_semester);
    }
};

class Art_Student : public Student {
private:
    ArtEmphasis emphasis;

public:
    Art_Student() {
        emphasis = ART_STUDIO;
    }

    void setEmphasis(ArtEmphasis emp) {
        emphasis = emp;
    }

    void writeToFile(ofstream& out) const {
        Student::writeToFile(out);
        out << ", Emphasis: " << emphasisToString(emphasis) << "\n";
    }
};

class Physics_Student : public Student {
private:
    PhysicsConcentration concentration;

public:
    Physics_Student() {
        concentration = BIOPHYSICS;
    }

    void setConcentration(PhysicsConcentration conc) {
        concentration = conc;
    }

    void writeToFile(ofstream& out) const {
        Student::writeToFile(out);
        out << ", Concentration: " << concentrationToString(concentration) << "\n";
    }
};

int main() {
    vector<Art_Student*> art_students;
    vector<Physics_Student*> physics_students;

int i;
for (int i = 0; i < 5; ++i) {
        Art_Student* student = new Art_Student();
        student->setName("ArtFirst" + to_string(i), "ArtLast" + to_string(i));
        student->setGPA(3.0 + i * 0.2);
        student->setLevel(UNDERGRADUATE);
        student->setEnrollment(2021, FALL);
        student->setGraduation(2025, SPRING);
        student->setEmphasis((ArtEmphasis)(i % 3));
        art_students.push_back(student);
    }

for (int i = 0; i < 5; ++i) {
        Physics_Student* student = new Physics_Student();
        student->setName("PhysicsFirst" + to_string(i), "PhysicsLast" + to_string(i));
        student->setGPA(3.5 + i * 0.1);
        student->setLevel(GRADUATE);
        student->setEnrollment(2022, SPRING);
        student->setGraduation(2026, FALL);
        student->setConcentration((PhysicsConcentration)(i % 2));
        physics_students.push_back(student);
    }

    ofstream outfile("student_info.dat");
    if (!outfile) {
        cerr << "Error opening file for writing.\n";
        return 1;
    }

    outfile << "Art Students:\n";
    for (int i = 0; i < art_students.size(); ++i) {
        art_students[i]->writeToFile(outfile);
    }

    outfile << "\nPhysics Students:\n";
    for (int i = 0; i < physics_students.size(); ++i) {
        physics_students[i]->writeToFile(outfile);
    }

    outfile.close();

for (int i = 0; i < art_students.size(); ++i) delete art_students[i];
    for (int i = 0; i < physics_students.size(); ++i) delete physics_students[i];

    return 0;
}

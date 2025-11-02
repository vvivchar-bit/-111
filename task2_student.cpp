#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name, group;
    vector<int> marks;

    double avg() const {
        double sum = 0;
        for (size_t i = 0; i < marks.size(); ++i)
            sum += marks[i];
        return sum / marks.size();
    }

    bool only4or5() const {
        for (size_t i = 0; i < marks.size(); ++i)
            if (marks[i] < 4) return false;
        return true;
    }
};

bool cmp(const Student &a, const Student &b) {
    return a.avg() < b.avg();
}

Student makeStudent(const string& name, const string& group,
                    int m1, int m2, int m3, int m4, int m5) {
    Student s;
    s.name = name;
    s.group = group;
    s.marks.resize(5);
    s.marks[0] = m1; s.marks[1] = m2; s.marks[2] = m3; s.marks[3] = m4; s.marks[4] = m5;
    return s;
}

int main() {
    vector<Student> v;

    Student s1 = makeStudent("Ivanov I. I.", "ALK-43", 4,5,4,5,4);
    Student s2 = makeStudent("Petrenko P. P.", "ALK-42", 5,4,5,5,5);
    Student s3 = makeStudent("Sydorenko S. S.", "ALK-41", 4,4,4,4,4);
    Student s4 = makeStudent("Melnyk M. M.", "ALK-43", 5,5,5,5,5);

    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    v.push_back(s4);

    sort(v.begin(), v.end(), cmp);

    cout << "Sorting by average grade:\n";
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i].name << "  " << v[i].group << "  avg=" << v[i].avg() << "\n";

    cout << "\nStudents with only 4 or 5 marks:\n";
    for (size_t i = 0; i < v.size(); ++i)
        if (v[i].only4or5())
            cout << v[i].name << "  " << v[i].group << "\n";

    return 0;
}

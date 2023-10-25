#include "DiskCla"

double Disk::getPrice() {
    if (percentageGrade >= 90.0) {
        return 'A';
    } else if (percentageGrade >= 80.0) {
        return 'B';
    } else if (percentageGrade >= 70.0) {
        return 'C';
    } else if (percentageGrade >= 60.0) {
        return 'D';
    } else {
        return 'F';
    }
}
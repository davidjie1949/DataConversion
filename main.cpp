#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

double width {1280.};
double height {960.};

double central_x(int& x1, int& x2) {
    return (x1 + x2) / (2*width);
}

double central_y(int& y1, int& y2) {
    return (y1 + y2) / (2*height);
}

double absoulte_width(int& x1, int& x2) {
    return (x2 - x1) / width;
}

double absoulate_height(int& y1, int& y2) {
    return (y2 - y1) / height;
}

int main(int argc, char *argv[]){
    if(argc != 2){
        cout << "Please select the file" << endl;
        return 1;
    }

//int main(){
    ifstream input(argv[1]);
    //ifstream input("frameAnnotationsBULB.csv");
    ofstream myfile("abstraction.txt");
    if(input){
        string line;
        while (getline(input, line)){
            cout << line << endl;
            vector <char> list_vector;
            for (unsigned i = 36; i < 57; i++){
                if (line.at(i) == 48 ||
                    line.at(i) == 49 ||
                    line.at(i) == 50 ||
                    line.at(i) == 51 ||
                    line.at(i) == 52 ||
                    line.at(i) == 53 ||
                    line.at(i) == 54 ||
                    line.at(i) == 55 ||
                    line.at(i) == 56 ||
                    line.at(i) == 57 ||
                    line.at(i) == 103 ){
                        list_vector.push_back(line[i]);
                        cout << line[i] - 48;
                } else if (line.at(i) == 59) {
                    list_vector.push_back(' ');
                    cout << " ";
                }
            }

            for (auto i = list_vector.begin(); i != list_vector.end(); ++i){
            myfile << *i;
            }
            myfile << "\n";
            cout << endl;
        }
    }
    myfile.close();

    ifstream myinput("abstraction.txt");
//    ofstream myoutput("postprocess.txt");
//    if(myinput){
//        string line;
//        while (getline(myinput, line)){
//            stringstream geek(line);
//            char temp;
//            int a,x1, y1, x2, y2;
//            geek >> temp >> x1 >> y1 >> x2 >> y2;
//            if (temp == 'g')
//                a = 0;
//
//            myoutput << a << ' ' << setprecision(15) << central_x(x1, x2) << ' ' << central_y(y1, y2) << ' ' << absoulte_width(x1, x2) << ' ' << absoulate_height(y1, y2) << endl;
//            cout << a << ' ' << setprecision(15) << central_x(x1, x2) << ' ' << central_y(y1, y2) << ' ' << absoulte_width(x1, x2) << ' ' << absoulate_height(y1, y2) << endl;
//        }
//    }
//    myoutput.close();

    if (myinput) {
        string line;
        int filecount {0};
        while (getline(myinput,line)){
            string filename = "File_" + to_string(filecount) + ".txt";
            ofstream index_output(filename);
            stringstream geek(line);
            char temp;
            int a,x1, y1, x2, y2;
            geek >> temp >> x1 >> y1 >> x2 >> y2;
            if (temp == 'g')
                a = 0;

            index_output << a << ' ' << setprecision(15) << central_x(x1, x2) << ' ' << central_y(y1, y2) << ' ' << absoulte_width(x1, x2) << ' ' << absoulate_height(y1, y2) << endl;
            cout << a << ' ' << setprecision(15) << central_x(x1, x2) << ' ' << central_y(y1, y2) << ' ' << absoulte_width(x1, x2) << ' ' << absoulate_height(y1, y2) << endl;
            filecount++;
            index_output.close();
        }
    }

    return 0;
}

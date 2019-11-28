#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

double width {1280.};
double height {960.};

int nthSubstr(int n, const string& s, const string& p){
    string::size_type i = s.find(p);// Find the first occurrence

    int j;
    for (j = 1; j < n && i != string::npos; ++j)
        i = s.find(p, i+1);// Find the next occurrence

    if (j == n)
        return(static_cast<int>(i));
    else
        return(-1);
}

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

void writefile (string& filename, string& readline){
    string semicolon {";"};
    ifstream infile(filename);
    if (infile){
        string temp3;
        for (int i = nthSubstr(2, readline, semicolon) + 1; i < nthSubstr(6, readline, semicolon); ++i){
            temp3 += readline[i];
        }
        stringstream geek(temp3);
        char xx;
        int x1, y1, x2, y2;
        geek >> x1 >> xx >> y1 >> xx >> x2  >> xx >> y2;
        fstream infile(filename,ios::app);
        infile << 0 << ' ' << central_x(x1, x2) << ' ' << central_y(y1, y2) << ' ' << absoulte_width(x1, x2) << ' ' << absoulate_height(y1, y2) << endl;
    }
}

string readfilename(string& readline){
    string temp2, slash {"/"}, point {"."};
    for (int i = nthSubstr(1, readline, slash) + 1; i < nthSubstr(1, readline, point); ++i){
        temp2 += readline[i];
    }
    return temp2 + ".txt";

}

//"nightTraining/nightClip1--00000.png;go;656;300;667;313;nightTraining/nightClip1/clip1.mp4;0;nightTraining/nightClip1/clip1.mp4;0"
int main(int argc, char *argv[]){
    if(argc != 2){
        cout << "Please select the file" << endl;
        return 1;
    }
//int main(){
//ifstream input("frameAnnotationsBULB.csv");
    ifstream input(argv[1]);
    if(input){
        string readline, filename;
        while (getline(input, readline)){
            string filename_1 = readfilename(readline);

            if(filename_1 == filename){
                writefile(filename,readline);
            }else{
                filename = filename_1;
                ofstream myfile(filename);
                writefile(filename,readline);
            }
        }
    }
    return 0;
}



//    ifstream myinput("abstraction.txt");
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

//    if (myinput) {
//        string line;
//        int filecount {0};
//        while (getline(myinput,line)){
//            string filename = "File_" + to_string(filecount) + ".txt";
//            ofstream index_output(filename);
//            stringstream geek(line);
//            char temp;
//            int a,x1, y1, x2, y2;
//            geek >> temp >> x1 >> y1 >> x2 >> y2;
//            if (temp == 'g')
//                a = 0;
//
//            index_output << a << ' ' << setprecision(15) << central_x(x1, x2) << ' ' << central_y(y1, y2) << ' ' << absoulte_width(x1, x2) << ' ' << absoulate_height(y1, y2) << endl;
//            cout << a << ' ' << setprecision(15) << central_x(x1, x2) << ' ' << central_y(y1, y2) << ' ' << absoulte_width(x1, x2) << ' ' << absoulate_height(y1, y2) << endl;
//            filecount++;
//            index_output.close();
//        }
//    }

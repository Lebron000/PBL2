#include "suatchieu.h"

// Suatchieu::Suatchieu(string stt, string MaMovie, string Begin)
// {
//     this->Stt = stt;
//     this->maphim = MaMovie;
//     this->TimeBegin = Begin;
// } 

// Suatchieu::~Suatchieu()
// {
// }

// void Suatchieu::setTimeBegin()
// {
//     cout << "Thoi gian bat dau: ";
//     string begin;
//     cin >> begin;
//     this->TimeBegin = begin;
// }

// void Suatchieu::setstt()
// {
//     cout << "Stt suat chieu:";
//     string stt;
//     cin >> stt;
//     this->Stt = stt;
// }

string **Suatchieu::inseat()
{
    char a = 'A';
    string **S = new string *[12];
    for (int i = 0; i < 12; i++)
    {
        S[i] = new string[12];
        for (int j = 0; j < 12; j++)
        {
            stringstream ss;
            int index = j;
            index++;
            ss << '1' << a << index;
            S[i][j] = ss.str();
        }
        a += 1;
    }

    return S;
}

// bool Suatchieu::Checkmaphim(const std::string &filename, const std::string &prefix)
// {
//     ifstream file(filename);
//     if (!file.is_open())
//     {
//         cout << "Không thể mở tệp " << filename << endl;
//         return false;
//     }

//     string line;
//     while (getline(file, line))
//     {
//         if (line.compare(0, prefix.size(), prefix) == 0)
//         {
//             file.close();
//             return true;
//         }
//     }

//     file.close();
//     return false;
// }

void Insuatchieuvaotrongfile(string &filename, string &line)
{
    // Đọc toàn bộ nội dung từ tệp vào một chuỗi.
    ifstream inFile(filename);
    string NoidungFile;
    if (inFile)
    {
        string line;
        while (getline(inFile, line))
        {
            NoidungFile += line + "\n";
        }
        inFile.close(); // đọc hết nội dung file rồi đóng file để tránh các bản ghi sau ghi đè lên các bản ghi trước
    }
    else
    {
        inFile.close();
        cout << "Khong co tep thong tin!" << endl;
        return;
    }
    string **S = Suatchieu::inseat();
    // kiểm tra phim đó đã có suất chiếu nào chưa

    string TimMaphim = line.substr(0, 3); // trích ra 3 kí tự đầu của chuối line  để kiểm tra 3 kí tự đầu tiên mỗi hàng
    size_t foundPosition = NoidungFile.find(TimMaphim);
    if (foundPosition != string::npos)
    { // string::npos là 1 tín hiệu có nghĩa là không tìm thấy -> != string::npos tức là đã tìm thấy chuỗi cần tìm

        // nếu có rồi thì thêm suất chiếu mới vào ngay bên dưới các suất chiếu mới của phim đó trong file txt
        size_t nextLinePosition = NoidungFile.find("\n", foundPosition);
        size_t seatPosition = NoidungFile.find("\n", nextLinePosition);
        if (nextLinePosition != string::npos)
        {
            string newline = "";
            for (int i = 0; i < 12; i++)
            {
                for (int j = 0; j < 12; j++)
                {
                    newline += S[i][j] + " ";
                }
                newline += "\n";
            }

            // Thêm hàng mới xuống phía dưới của hàng trùng đó.
            NoidungFile.insert(seatPosition, "\n" + line); // chỗ này biến bị ngược :/ éo biết vì sao nữa (code đã chạy đúng thì đừng có sửa)
            NoidungFile.insert(nextLinePosition, "\n" + newline);
        }
    }
    else
    {
        // nếu chưa có suất chiếu nào thì thêm vào cuối file .txt
        NoidungFile += "\n" + line;
        NoidungFile += "\n";
        string **S = Suatchieu::inseat();
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                NoidungFile += S[i][j] + " ";
            }
            NoidungFile += "\n";
        }
        NoidungFile += "\n";
    }

    // Ghi lại toàn bộ nội dung của chuỗi vào tệp văn bản.
    ofstream outFile(filename);
    outFile << NoidungFile;
    outFile.close();
}

void Suatchieu::insuatchieucuaphim()
{
    ifstream inFile("suatchieu.txt");
    if (!inFile)
    {
        cout << "Không thể mở tệp." << endl;
        return;
    }
    string line;
    string maphim;
    cout << "Nhap ma phim can tim suat chieu: ";
    cin >> maphim;
    while (getline(inFile, line))
    {
        if (line.find(maphim) == 0)
        {
            cout << line << endl;
        }
    }
    inFile.close();
}

void Suatchieu::printMovieShow(string maphim)
{
    ifstream inFile("suatchieu.txt");
    if (!inFile)
    {
        cout << "File Not Found!!!";
    }

    int lent = maphim.length() + 19;
    int len = maphim.length();
    std::cout << "\t\t\to" << std::string(lent, '=') << "o" << std::endl;
    std::cout << "\t\t\t" << std::string(5, ' ') << "MOVIE ID: " << maphim << std::endl;
    std::cout << "\t\t\to" << std::string(lent, '-') << "o" << std::endl;
    std::cout << "\t\t\t" << std::string(5, ' ') << "ST" << std::string(len, ' ') << "|" << std::string(len, ' ') << "Time" << std::endl;
    std::cout << "\t\t\to" << std::string(lent, '-') << "o" << std::endl;

    string line;
    while (getline(inFile, line))
    {
        size_t pos = line.find(";");
        if (pos != std::string::npos)
        {
            std::string currentMaphim = line.substr(0, pos);
            if (currentMaphim == maphim)
            {
                std::string st = line.substr(pos + 1, 3);
                std::string timee = line.substr(pos + 5);
                if (timee.length() == 4)
                    timee += ' ';
                int spaceLen = len - st.length();
                std::cout << "\t\t\to " << std::string(len, ' ') << st << std::string(spaceLen, ' ') << "  |   " << timee << std::string(len, ' ') << " o" << std::endl;
            }
        }
    }
    std::cout << "\t\t\to" << std::string(lent, '-') << "o" << std::endl;
    inFile.close();
}

// void Suatchieu::themsuatchieu()
// {
//     string filephim = "Movie_information.txt"; // file thông tin các phim đã tồn tại
//     string filesuatchieu = "suatchieu.txt";    // file thông tin các suất chiếu của các phim
//     cout << "Nhap ma phim: ";                  // nhập mã phim cần thêm suất chiếu mới
//     string maphim;
//     cin >> maphim;
//     Suatchieu New;
//     if (Suatchieu::Checkmaphim(filephim, maphim) == true)
//     { // hàm kiểm tra phim muốn thêm suất chiếu có tồn tại trong danh sách movie_information hay không
//         cout << "Cac suat chieu da co cua phim " << maphim << endl;
//         New.printMovieShow(maphim);
//         cout << "Vui long nhap thong tin suat chieu cua ma phim " << maphim << endl;
//         New.setstt();
//         New.setTimeBegin();
//         string Thongtinsuatchieu = maphim + ";" + New.Stt + ";" + New.TimeBegin;
//         Insuatchieuvaotrongfile(filesuatchieu, Thongtinsuatchieu); // thêm thông tin vô file suatchieu.txt
//     }
//     else
//         cout << "Chua co phim do trong danh sach phim"; // nếu phim chưa tồn tại trong file movie_information thì hiện ra thông báo
// }

void Suatchieu::inthongtinsuatchieu(string maphim, string Sothutu)
{
    ifstream inFile("suatchieu.txt");

    if (!inFile.is_open())
    {
        cout << "File not Found!" << std::endl;
        return;
    }

    // Mã suất chiếu bạn muốn tìm

    system("cls");
    string line;
    bool foundTarget = false;

    while (getline(inFile, line))
    {
        if (line.find(maphim) != std::string::npos && line.find(Sothutu) != std::string::npos)
        {
            foundTarget = true;
            string Codephim, sttt, timee;
            std::cout << "\t\t\to" << std::string(maphim.length()+15, '-') << "o" << std::endl;
            size_t pos1 = line.find(';');
            if (pos1 != std::string::npos)
            {
                Codephim = line.substr(0, pos1);

                size_t pos2 = line.find(';', pos1 + 1);
                if (pos2 != std::string::npos)
                {
                    sttt = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    timee = line.substr(pos2 + 1);
                    cout << "\t\t\t  " << Codephim << " | " << sttt << " | " << timee << endl;
                }
            }
            std::cout << "\t\t\to" << std::string(maphim.length()+15, '-') << "o" << std::endl;
        }
        else if (foundTarget && line.empty())
        {
            break;
        }
    }

    inFile.close();

    if (!foundTarget)
    {
        std::cout << "Không tìm thấy mã suất chiếu: " << maphim << " và số thứ tự: " << Sothutu << endl;
    }

    return;
}

// void Suatchieu::printseat(string suatchieu, string seat){
//     ifstream inFile("suatchieu.txt");
//     if(!inFile){
//         cerr<<"Error opening file";
//         exit(-1);
//     }
//     string file;
//     string line;
//     if(inFile.is_open()) {
//         while(getline(inFile, line)) {
//             file += line + "\n";
//             if(line.find(suatchieu) != string::npos){
//                 file += seat + ";" ;
//                 break;
//         }
//     }
//     while(getline(inFile, line)) {
//         file += line + '\n';
//     }
//     inFile.close();
// }
//     ofstream outFile("suatchieu.txt");
//     if(outFile.is_open()) {
//         outFile << file;
//         outFile.close();
//     } else cerr << "Khong tim thay file"; 

// }


// void Suatchieu::readseat(string suatchieu){
//     ifstream inFile("suatchieu.txt");
//     if(!inFile){
//         cerr<<"Error opening file";
//         exit(-1);
//     }
//     string line;
//     string target;
//     bool istarget = false;
//     while(getline(inFile, line)) {
//         if(istarget == true) {
//             istringstream linestream(line);
//             string field;
//             while(getline(linestream, field, ';')) {
//                 cout << field << " ";
//             }
//             cout << endl;
//             istarget = false;
//         } else if (line.find(suatchieu) != string::npos) {
//             istarget = true;
//         }   
//     }
//     inFile.close();
// }
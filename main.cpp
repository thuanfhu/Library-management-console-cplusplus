#include <bits/stdc++.h>
#include "console.cpp"
#include <Windows.h>
#include "ThuVien.cpp"
#include "DocGia.cpp"
#include "Sach.cpp"
#include "PhieuMuon.cpp"
using namespace std;

QuanLyThuVien library;

// Access app first time => Draw frame
vector<bool> firstRun(20, true);


// UI for App
void exitLib(){
	char ask;
	int choice[] = {4,7};
	int counter = 1;
    char key;
    gotoxy(40, 12);
    TextColor(3);
    cout << "Ban co chac chan muon thoat TD Bookstore?";
    for(int i=0;;){
    	gotoxy(57,14);
        TextColor(choice[0]);
        cout<<"YES";
	
        gotoxy(57,16);
        TextColor(choice[1]);
        cout<<"NO";
        
        key = _getch();
        
        if(key == 72 && (counter >=2 && counter <= 5))
        {
            PlaySound(TEXT("Sound/go.wav"), NULL, SND_FILENAME | SND_ASYNC);
            counter--;
        }
        if(key == 80 && (counter >=1 && counter <= 4))
        {
            PlaySound(TEXT("Sound/go.wav"), NULL, SND_FILENAME | SND_ASYNC);
            counter++;
        }
        if(key == '\r')
        {
            if(counter == 1)
            {
                PlaySound(TEXT("Sound/move.wav"), NULL, SND_FILENAME | SND_ASYNC);
            	clrscr();
                for(int i=0; i<15; i++){
                	gotoxy(46, i);
                	TextColor(i);
                	cout << "Cam on da su dung!";
                	if(i==14){
                		break;
					}
					Sleep(70);
					clrscr();
				}
                exit(0);
            }
            if(counter == 2)
            {
                PlaySound(TEXT("Sound/move.wav"), NULL, SND_FILENAME | SND_ASYNC);
            	clrscr();
            	return;
            }
		}
		choice[0] = 7;
        choice[1] = 7;
        if(counter == 1)
        {
            choice[0] = 4;
        }
        if(counter == 2)
        {
            choice[1] = 4;
        }
	}
}
void tenLib() {
	for(int i=1; i<15; i++){
		TextColor(i);
		gotoxy(28, 5);
		cout << " ____  ____    ____   __    __  __ _  ____  ____  __  ____  ____ " << endl; gotoxy(28, 6);
		cout << "(_  _)(    \\  (  _ \\ /  \\  /  \\(  / )/ ___)(_  _)/  \\(  _ \\(  __)" << endl; gotoxy(28, 7);
		cout << "  )(   ) D (   ) _ ((  O )(  O ))  ( \\___ \\  )( (  O ))   / ) _) " << endl; gotoxy(28, 8);
		cout << " (__) (____/  (____/ \\__/  \\__/(__\\_)(____/ (__) \\__/(__\\_)(____)" << endl;
    	Sleep(50);
	}
	TextColor(10);	
	gotoxy(28, 5);
    cout << " ____  ____    ____   __    __  __ _  ____  ____  __  ____  ____ " << endl; gotoxy(28, 6);
	cout << "(_  _)(    \\  (  _ \\ /  \\  /  \\(  / )/ ___)(_  _)/  \\(  _ \\(  __)" << endl; gotoxy(28, 7);
	cout << "  )(   ) D (   ) _ ((  O )(  O ))  ( \\___ \\  )( (  O ))   / ) _) " << endl; gotoxy(28, 8);
	cout << " (__) (____/  (____/ \\__/  \\__/(__\\_)(____/ (__) \\__/(__\\_)(____)" << endl;
}
void loading(){
	TextColor(10);
	char a = 219;
	gotoxy(49, 24);
	cout << "Loading..."<< endl;
	gotoxy(49,26);
	for(int r =1; r<=20; r++)
	{
		for(int q=0; q <= 100000000; q++);
		cout << a;
		Sleep(45);
	}
}
void demNguoc(){
    PlaySound(TEXT("Sound/count.wav"), NULL, SND_FILENAME | SND_ASYNC);
	gotoxy(100, 26);
	TextColor(10);
	cout << "3";
	Sleep(1000);
	for(int i = 100; i< 96 ; i++){
		gotoxy(i, 26);
		cout << char(32);
		Sleep(1);
	}
	gotoxy(100, 26);
	TextColor(14);
	cout << "2";
	Sleep(1000);
	for(int i = 100; i< 96 ; i++){
		gotoxy(i, 26);
		cout << char(32);
		Sleep(1);
	}
	gotoxy(100, 26);
	TextColor(4);
	cout << "1";
	Sleep(1000);
	for(int i = 100; i< 96 ; i++){
		gotoxy(i, 26);
		cout << char(32);
		Sleep(1);
	}
}	
void exitESC(){
	while (true) {
        if (_kbhit()) { 
            char ch = _getch(); 
            if (ch == 27) {
            	return;
            }
        }
    }
}
void khungMenu(){
    //Hai duong trang 
 	for(int i = 46; i<73; i++){
 		TextColor(3);
 		gotoxy(i, 13);
 		cout << char(196);
 		Sleep(1);
	 }
	 for(int i = 46; i<73; i++){
	 	TextColor(3);
 		gotoxy(i, 21);
 		cout << char(196);
 		Sleep(1);
	 }
}
void aboutMe(string madeBy, string mssv, string lop, string tenTruong){
	//Hai duong trang 
    for(int i = 41; i<80; i++){
 	TextColor(1);
 	gotoxy(i, 10);
 	cout << char(196);
 	Sleep(1);
	}
    for(int i = 41; i<80; i++){
        TextColor(4);
        gotoxy(i, 21);
        cout << char(196);
        Sleep(1);
    }
    // Noi dung 
	for(int i=1; i<15; i++){
	 	TextColor(i);
	 	gotoxy(46, 12);
	 	cout << "Made by: " << madeBy;
	 	Sleep(4);
	 }
	 for(int i=1; i<15; i++){
	 	TextColor(i);
	 	gotoxy(46, 14);
	 	cout << "MSSV: " << mssv;
	 	Sleep(4);
	 }
	 gotoxy(46, 16);	 
	 cout << "Class: " << lop;
	 for(int i=1; i<15; i++){
	 	TextColor(i);
	 	gotoxy(46, 16);
	 	cout << "Class: " << lop;
	 	Sleep(4);
	 }
	 for(int i=1; i<15; i++){
	 	TextColor(i);
	 	gotoxy(46, 18);
	 	cout << tenTruong;
	 	Sleep(4);
	 }
}
void help(){
	if(firstRun[15]){
        //Khung rules
        gotoxy(0, 0);
        TextColor(11);
        cout << char(201);
        for(int i=1; i<59; i++){
            gotoxy(i, 0);
            cout << char(205);
            Sleep(1);
        }
        gotoxy(59,0);
        cout << char(187);
        for(int i = 1 ; i < 29; i++){
            gotoxy(59, i);
            cout << char(186);
            Sleep(1);
        }
        gotoxy(59, 29); cout << char(188);
        for(int i = 58; i >= 1; i--){
            gotoxy(i, 29);
            cout << char(205);
            Sleep(1);
        }
        gotoxy(0, 29); cout << char(200);
        for(int i = 28; i >= 1; i--){
            gotoxy(0, i);
            cout << char(186);
            Sleep(1);
        }
        //Noi dung luat choi
        gotoxy(13, 2);
        for(int i=1; i<15; i++){
            TextColor(i);
            gotoxy(13, 2);
            cout << "  ____  _   _ _     _____ ____  " ; gotoxy(13, 3);
            cout << " |  _ \\| | | | |   | ____/ ___| " ; gotoxy(13, 4);
            cout << " | |_) | | | | |   |  _| \\___ \\ " ; gotoxy(13, 5);
            cout << " |  _ <| |_| | |___| |___ ___) |" ; gotoxy(13, 6);
            cout << " |_| \\_\\\\___/|_____|_____|____/ ";
            Sleep(30);
        }
        PlaySound(TEXT("Sound/tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
        TextColor(12);
        gotoxy(13, 2);
        cout << "  ____  _   _ _     _____ ____  " ; gotoxy(13, 3);
        cout << " |  _ \\| | | | |   | ____/ ___| " ; gotoxy(13, 4);
        cout << " | |_) | | | | |   |  _| \\___ \\ " ; gotoxy(13, 5);
        cout << " |  _ <| |_| | |___| |___ ___) |" ; gotoxy(13, 6);
        cout << " |_| \\_\\\\___/|_____|_____|____/ ";	
        TextColor(14);
        gotoxy(6, 8); cout << "+ Members chi duoc muon toi da 3 cuon sach";
        gotoxy(6, 10); cout << "+ Thoi han tu ngay muon den ngay tra la 3 thang";
        gotoxy(6, 12); cout << "+ So dien thoai members chi toi da 10 chu so";
        gotoxy(6, 14); cout << "+ Phieu muon se xoa neu xoa members khoi thu vien";
        gotoxy(6, 16); cout << "+ Chi co the search thong tin member neu co member";
        gotoxy(6, 17); cout << "  trong co so du lieu cua thu vien";
        gotoxy(6, 19); cout << "+ Ma doc gia, ma phieu muon, ma sach duoc thu vien";
        gotoxy(6, 20); cout << "  khoi tao tu dong sau khi nhap xong thong tin";
        gotoxy(6, 22); cout << "+ Neu member muon sach vuot qua thoi han 3 thang se";
        gotoxy(6, 23); cout << "  bi thu vien khoa the tu dong";
        gotoxy(6, 25); cout << "+ Neu mat, hong sach thi phai den tien cho thu vien";
        gotoxy(6, 27); cout << "+ Neu can ho tro, hay lien he hotline: 0886332809";

        // Khung dieu khien WADS
        gotoxy(61, 0);
        TextColor(10);
        cout << char(201);
        for(int i=62; i<119; i++){
            gotoxy(i, 0);
            cout << char(205);
            Sleep(1);
        }
        gotoxy(119,0);
        cout << char(187);
        for(int i = 1 ; i < 14; i++){
            gotoxy(119, i);
            cout << char(186);
            Sleep(1);
        }
        gotoxy(119, 14); cout << char(188);
        for(int i = 118; i >= 61; i--){
            gotoxy(i, 14);
            cout << char(205);
            Sleep(1);
        }
        gotoxy(61, 14); cout << char(200);
        for(int i = 13; i >= 1; i--){
            gotoxy(61, i);
            cout << char(186);
            Sleep(1);
        }
        //Noi dung khung Adjust PvP Mode
        for(int i=1; i<15; i++){
            TextColor(i);
            gotoxy(82, 3);
            cout << "Reader Management Mode";
            Sleep(10);
        }
        PlaySound(TEXT("Sound/tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
        TextColor(12);
        gotoxy(82, 3);
        cout << "Reader Management Mode";
        TextColor(14);
        gotoxy(78, 5); cout << "A: Them members vao thu vien";
        gotoxy(78, 7); cout << "S: Tim kiem thong tin members";
        gotoxy(78, 9); cout << "B: Tao phieu muon sach thu vien";
        gotoxy(78, 11); cout << "D: Xoa members khoi thu vien";	
        //Khung phim tat
        gotoxy(61, 15);
        TextColor(13);
        cout << char(201);
        for(int i=62; i<119; i++){
            gotoxy(i, 15);
            cout << char(205);
            Sleep(1);
        }
        gotoxy(119,15);
        cout << char(187);
        for(int i = 16 ; i < 29; i++){
            gotoxy(119, i);
            cout << char(186);
            Sleep(1);
        }
        gotoxy(119, 29); cout << char(188);
        for(int i = 118; i >= 61; i--){
            gotoxy(i, 29);
            cout << char(205);
            Sleep(1);
        }
        gotoxy(61, 29); cout << char(200);
        for(int i = 28; i >= 16; i--){
            gotoxy(61, i);
            cout << char(186);
            Sleep(1);
        }
        //Noi dung o phim tat
        for(int i=1; i<15; i++){
            TextColor(i);
            gotoxy(82, 18);
            cout << "Book Management Mode";
            Sleep(10);
        }
        PlaySound(TEXT("Sound/tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
        TextColor(12);
        gotoxy(82, 18);
        cout << "Book Management Mode";
        TextColor(14);
        gotoxy(78, 20); cout << "R: Tra sach cho thu vien";
        gotoxy(78, 22); cout << "E: Tro lai giao dien chinh";
        gotoxy(78, 24); cout << "A: Them sach vao thu vien";
        gotoxy(78, 26); cout << "D: Xoa sach khoi thu vien";
    }
    firstRun[15] = false;
}


// Draw frame
void veKhungThem(int color1, int color2, string title, string name1, string name2, string name3, string name4, string name5){
    // Them sach vao thu vien
    TextColor(color1);
    gotoxy(90, 1); cout << title;
    gotoxy(82, 2); cout << char(218);
    for(int i = 83; i < 119; i++){
        gotoxy(i, 2);
        cout << char(196);
        if(firstRun[0]) Sleep(1);
    }
    gotoxy(119, 2); cout << char(191);

    for(int i = 3; i < 12; i++){
        gotoxy(82, i);
        cout << char(179);
        if(firstRun[0]) Sleep(1);
    }
    gotoxy(82, 12); cout << char(192);

    for(int i = 83; i < 119; i++){
        gotoxy(i, 12);
        cout << char(196);
        if(firstRun[0]) Sleep(1);
    }
    gotoxy(119, 12); cout << char(217);

    for(int i = 11; i >= 3; i--){
        gotoxy(119, i); 
        cout << char(179);
        if(firstRun[0]) Sleep(1);
    }

    // Ve duong ngang them sach 
    gotoxy(82, 4); cout << char(195);
    gotoxy(119, 4); cout << char(180);
    for(int i = 83; i < 119; i++){
        gotoxy(i, 4);
        cout << char(196);
        if(firstRun[0]) Sleep(1);
    }

    gotoxy(82, 6); cout << char(195);
    gotoxy(119, 6); cout << char(180);
    for(int i = 83; i < 119; i++){
        gotoxy(i, 6);
        cout << char(196);
        if(firstRun[0]) Sleep(1);
    }

    gotoxy(82, 8); cout << char(195);
    gotoxy(119, 8); cout << char(180);
    for(int i = 83; i < 119; i++){
        gotoxy(i, 8);
        cout << char(196);
        if(firstRun[0]) Sleep(1);
    }

    gotoxy(82, 10); cout << char(195);
    gotoxy(119, 10); cout << char(180);
    for(int i = 83; i < 119; i++){
        gotoxy(i, 10);
        cout << char(196);
        if(firstRun[0]) Sleep(1);
    }

    // Ve duong doc them sach
    gotoxy(92, 2); cout << char(194);
    gotoxy(92, 12); cout << char(193);
    for(int i = 3; i < 12; i++){
        if(i == 4 || i == 6 || i == 8 || i == 10){
            gotoxy(92, i);
            cout << char(197);
        }
        else {
            gotoxy(92, i);
            cout << char(179);
        }
        if(firstRun[0]) Sleep(1);
    }

    // Dien thong tin sach
    TextColor(color2);
    gotoxy(83, 3); cout << name1;
    gotoxy(83, 5); cout << name2;
    gotoxy(83, 7); cout << name3;
    gotoxy(83, 9); cout << name4;
    gotoxy(83, 11); cout << name5;
    firstRun[0] = false;
}
void veKhungXoa(int color1, int color2, string title, string name1, string name2){
    // Xoa sach khoi thu vien
    TextColor(color1);
    gotoxy(90, 14); cout << title;
    // Ve khung
    gotoxy(82, 15); cout << char(218);
    for(int i = 83; i < 119; i++){
        gotoxy(i, 15);
        cout << char(196);
        if(firstRun[2]) Sleep(1);
    }    
    gotoxy(119, 15); cout << char(191);

    for(int i = 16; i < 19; i++){
        gotoxy(82, i);
        cout << char(179);
        if(firstRun[2]) Sleep(1);
    }
    gotoxy(82, 19); cout << char(192);

    for(int i = 83; i < 119; i++){
        gotoxy(i, 19);
        cout << char(196);
        if(firstRun[2]) Sleep(1);
    }
    gotoxy(119, 19); cout << char(217);

    for(int i = 18; i >= 16; i--){
        gotoxy(119, i); 
        cout << char(179);
        if(firstRun[2]) Sleep(1);   
    }

    // Ve duong ngang
    for(int i = 82; i <= 119; i++){
        gotoxy(i, 17);
        if(i == 119) cout << char(180);
        else if(i == 82) cout << char(195);
        else cout << char(196);
        if(firstRun[2]) Sleep(1);
    }

    // Ve duong doc
    gotoxy(92, 15); cout << char(194);
    gotoxy(92, 19); cout << char(193);
    for(int i = 16; i < 19; i++){
        gotoxy(92, i);
        if(i == 17) cout << char(197);
        else cout << char(179);
        if(firstRun[2]) Sleep(1);
    }

    TextColor(color2);
    gotoxy(83, 16); cout << name1;
    gotoxy(83, 18); cout << name2;
    firstRun[2] = false;
}
void veKhungStatus(int color, string title){
    // Thanh trang thai
    TextColor(color);
    gotoxy(93, 21); cout << title;
    gotoxy(82, 22); cout << char(218);
    // Ve khung
    gotoxy(82, 22); cout << char(218);
    for(int i = 83; i < 119; i++){
        gotoxy(i, 22);
        cout << char(196);
        if(firstRun[1]) Sleep(1);
    }    
    gotoxy(119, 22); cout << char(191);

    for(int i = 23; i < 29; i++){
        gotoxy(82, i);
        cout << char(179);
        if(firstRun[1]) Sleep(1);
    }
    gotoxy(82, 29); cout << char(192);

    for(int i = 83; i < 119; i++){
        gotoxy(i, 29);
        cout << char(196);
        if(firstRun[1]) Sleep(1);
    }
    gotoxy(119, 29); cout << char(217);

    for(int i = 28; i >= 23; i--){
        gotoxy(119, i); 
        cout << char(179);
        if(firstRun[1]) Sleep(1);   
    }
    firstRun[1] = false;
}
void veKhungInfoReader(){
    TextColor(3);
    gotoxy(30, 1);
    cout << "BANG THONG TIN MEMBERS";
    // Ve khung xung quanh
    gotoxy(0, 2); cout << char(201);
    for(int i = 1; i < 80; i++) {
        gotoxy(i, 2);
        cout << char(205);
        if(firstRun[3]) Sleep(1);
    }
    gotoxy(80, 2); cout << char(187);
    for(int i = 3; i < 29; i++){
        gotoxy(0 , i);
        cout << char(186);
        if(firstRun[3]) Sleep(1);
    }
    gotoxy(0, 29); cout << char(200);
    for(int i = 1; i < 80; i++) {
        gotoxy(i, 29);
        cout << char(205);
        if(firstRun[3]) Sleep(1);
    }
    gotoxy(80, 29); cout << char(188);
    for(int i = 3; i < 29; i++) {
        gotoxy(80, i);
        cout << char(186);
        if(firstRun[3]) Sleep(1);
    }

    // Ve duong doc
    gotoxy(9, 2); cout << char(203);
    gotoxy(9, 29); cout << char(202);
    for(int i = 3; i < 29; i++){
        gotoxy(9, i);
        cout << char(186);
        if(firstRun[3]) Sleep(1);
    }   
    gotoxy(27, 2); cout << char(203);
    gotoxy(27, 29); cout << char(202);
    for(int i = 3; i < 29; i++){
        gotoxy(27, i);
        cout << char(186);
        if(firstRun[3]) Sleep(1);
    }   
    gotoxy(35, 2); cout << char(203);
    gotoxy(35, 29); cout << char(202);
    for(int i = 3; i < 29; i++){
        gotoxy(35, i);
        cout << char(186);
        if(firstRun[3]) Sleep(1);
    }   
    gotoxy(51, 2); cout << char(203);
    gotoxy(51, 29); cout << char(202);
    for(int i = 3; i < 29; i++){
        gotoxy(51, i);
        cout << char(186);
        if(firstRun[3]) Sleep(1);
    }   
    gotoxy(62, 2); cout << char(203);
    gotoxy(62, 29); cout << char(202);
    for(int i = 3; i < 29; i++){
        gotoxy(62, i);  
        cout << char(186);
        if(firstRun[3]) Sleep(1);
    }   
    gotoxy(73, 2); cout << char(203);
    gotoxy(73, 29); cout << char(202);
    for(int i = 3; i < 29; i++){
        gotoxy(73, i);  
        cout << char(186);
        if(firstRun[3]) Sleep(1);
    }   
    
    // Ve duong ngang
    gotoxy(0, 4); cout << char(204);
    for(int i = 1; i < 80; i++) {
        if(i == 9) {
            gotoxy(i, 4); 
            cout << char(206);
        }
        else if(i == 27){
            gotoxy(i, 4); 
            cout << char(206);
        }
        else if(i == 35){
            gotoxy(i, 4); 
            cout << char(206);
        }
        else if(i == 51){
            gotoxy(i, 4); 
            cout << char(206);
        }
        else if(i == 62){
            gotoxy(i, 4); 
            cout << char(206);
        }
        else if(i == 73){
            gotoxy(i, 4); 
            cout << char(206);
        } 
        else {
            gotoxy(i, 4);
            cout << char(205);
        }
        if(firstRun[3]) Sleep(1);
    }
    gotoxy(80, 4); cout << char(185);

    TextColor(12);
    gotoxy(2, 3); cout << "Ma DG";
    gotoxy(16, 3); cout << "Ho DG";
    gotoxy(28, 3); cout << "Ten DG";
    gotoxy(41, 3); cout << "So DT";
    gotoxy(53, 3); cout << "Gioi Tinh";
    gotoxy(65, 3); cout << "TS Muon";
    gotoxy(74, 3); cout << "Status";
    firstRun[3] = false;
}
void veKhungSoLuongDocGia(){
    // Ve khung vuong
    TextColor(3); 
    for(int i = 41; i <= 78; i++){
        gotoxy(i, 4);
        if(i == 41) cout << char(201);
        else if(i == 78) cout << char(187);
        else cout << char(205); 
        if(firstRun[4]) Sleep(1); 
    }
    for(int i = 5; i <= 8; i++){
        gotoxy(41, i);
        if(i == 8) cout << char(200);
        else cout << char(186); 
        if(firstRun[4]) Sleep(1);
    }
    for(int i = 42; i <= 78; i++){
        gotoxy(i, 8);
        if(i == 78) cout << char(188);
        else cout << char(205); 
        if(firstRun[4]) Sleep(1);
    }
    for(int i = 5; i <= 7; i++){
        gotoxy(78, i); 
        cout << char(186); 
        if(firstRun[4]) Sleep(1);
    }
    // Ve duong ngang
    gotoxy(41, 6); cout << char(204);
    gotoxy(78, 6); cout << char(185);
    for(int i = 42; i < 78; i++){
        gotoxy(i, 6); cout << char(205); 
        if(firstRun[4]) Sleep(1);
    }
    // Dien thong tin
    TextColor(14);
    gotoxy(51, 3); cout << "THANH TRANG THAI";
    firstRun[4] = false;
}
void veKhungThemDocGia(){
    TextColor(3);
    // Ve khung vuong
    for(int i = 38; i <= 81; i++){
        gotoxy(i, 14);
        if(i == 38) cout << char(218);
        else if(i == 81) cout << char(191);
        else cout << char(196);
        if(firstRun[5]) Sleep(1);
    }
    for(int i = 15; i <= 22; i++){
        gotoxy(38, i);
        if(i == 22) cout << char(192);
        else cout << char(179);
        if(firstRun[5]) Sleep(1);
    }
    for(int i = 39; i <= 81; i++){
        gotoxy(i, 22);
        if(i == 81) cout << char(217);
        else cout << char(196);
        if(firstRun[5]) Sleep(1);
    }
    for(int i = 15; i <= 21; i++){
        gotoxy(81, i);
        cout << char(179);
        if(firstRun[5]) Sleep(1);
    }
    // Ve duong doc
    for(int i = 14; i <= 22; i++){
        gotoxy(49, i);
        if(i == 14) cout << char(194);
        else if(i == 22) cout << char(193);
        else cout << char(179);
        if(firstRun[5]) Sleep(1);
    }
    // Ve duong ngang
    for(int i = 16; i < 21; i += 2){
        for(int j = 38; j <= 81; j++){
            gotoxy(j, i);
            if(j == 38) cout << char(195);
            else if(j == 81) cout << char(180);
            else if(j == 49) cout << char(197);
            else cout << char(196);
            if(firstRun[5]) Sleep(1);
        }
    }
    // Dien thong tin
    TextColor(14);
    gotoxy(50, 13); cout << "PHIEU DANG KI DOC GIA";
    gotoxy(39, 15); cout << "HO DG";
    gotoxy(39, 17); cout << "TEN DG";
    gotoxy(39, 19); cout << "SO DT";
    gotoxy(39, 21); cout << "GIOI TINH";
    firstRun[5] = false;
}
void veKhungInfoBook(int color1, int color2, string title, string name1, string name2, string name3, string name4, string name5, string name6){
    TextColor(color1);
    gotoxy(30, 1);
    cout << title;
    // Ve khung xung quanh
    gotoxy(0, 2); cout << char(201);
    for(int i = 1; i < 80; i++) {
        gotoxy(i, 2);
        cout << char(205);
        if(firstRun[6]) Sleep(1);
    }
    gotoxy(80, 2); cout << char(187);
    for(int i = 3; i < 29; i++){
        gotoxy(0 , i);
        cout << char(186);
        if(firstRun[6]) Sleep(1);
    }
    gotoxy(0, 29); cout << char(200);
    for(int i = 1; i < 80; i++) {
        gotoxy(i, 29);
        cout << char(205);
        if(firstRun[6]) Sleep(1);
    }
    gotoxy(80, 29); cout << char(188);
    for(int i = 3; i < 29; i++) {
        gotoxy(80, i);
        cout << char(186);
        if(firstRun[6]) Sleep(1);
    }
    // Ve duong doc
    gotoxy(9, 2); cout << char(203);
    gotoxy(9, 29); cout << char(202);
    for(int i = 3; i < 29; i++){
        gotoxy(9, i);
        cout << char(186);
        if(firstRun[6]) Sleep(1);
    }   

    gotoxy(38, 2); cout << char(203);
    gotoxy(38, 29); cout << char(202);
    for(int i = 3; i < 29; i++){
        gotoxy(38, i);
        cout << char(186);
        if(firstRun[6]) Sleep(1);
    }   
    
    gotoxy(45, 2); cout << char(203);
    gotoxy(45, 29); cout << char(202);
    for(int i = 3; i < 29; i++){
        gotoxy(45, i);
        cout << char(186);
        if(firstRun[6]) Sleep(1);
    }   

    gotoxy(62, 2); cout << char(203);
    gotoxy(62, 29); cout << char(202);
    for(int i = 3; i < 29; i++){
        gotoxy(62, i);  
        cout << char(186);
        if(firstRun[6]) Sleep(1);
    }   

    gotoxy(73, 2); cout << char(203);
    gotoxy(73, 29); cout << char(202);
    for(int i = 3; i < 29; i++){
        gotoxy(73, i);  
        cout << char(186);
        if(firstRun[6]) Sleep(1);
    }   
    
    // Ve duong ngang
    gotoxy(0, 4); cout << char(204);
    for(int i = 1; i < 80; i++) {
        gotoxy(i, 4);
        if(i == 9) {
            cout << char(206);
        }
        else if(i == 38){
            cout << char(206);
        }
        else if(i == 45){
            cout << char(206);
        }
        else if(i == 62){
            cout << char(206);
        }
        else if(i == 73){
            cout << char(206);
        } 
        else {
            cout << char(205);
        }
        if(firstRun[6]) Sleep(1);
    }
    gotoxy(80, 4); cout << char(185);   

    TextColor(color2);
    gotoxy(1, 3); cout << name1;
    gotoxy(20, 3); cout << name2;
    gotoxy(40, 3); cout << name3;
    gotoxy(49, 3); cout << name4;
    gotoxy(64, 3); cout << name5;
    gotoxy(76, 3); cout << name6;
    firstRun[6] = false;
}
void veKhungStatusBorrow(){
    TextColor(7);
    // Ve khung vuong
    for(int i = 74; i <= 108; i++){
        gotoxy(i, 1);
        if(i == 74) cout << char(201);
        else if(i == 108) cout << char(187);
        else cout << char(205);
        if(firstRun[7]) Sleep(1);
    }  
    for(int i = 2; i < 8; i++){
        gotoxy(108, i);
        if(i == 7) cout << char(188);
        else cout << char(186);
        if(firstRun[7]) Sleep(1);
    } 
    for(int i = 107; i >= 74; i--){
        gotoxy(i, 7);
        if(i == 74) cout << char(200);
        else cout << char(205);
        if(firstRun[7]) Sleep(1);
    }
    for(int i = 6; i >= 2; i--){
        gotoxy(74, i);
        cout << char(186);
        if(firstRun[7]) Sleep(1);
    }
    // Dien thong tin
    TextColor(11);
    gotoxy(83, 0); cout << "THANH TRANG THAI";
    firstRun[7] = false;
}
void veKhungReturnBook(){
    TextColor(7);
    // Ve khung vuong
    for(int i = 11; i <= 50; i++){
        gotoxy(i, 1);
        if(i == 11) cout << char(201);
        else if(i == 50) cout << char(187);
        else cout << char(205);
        if(firstRun[8]) Sleep(1);
    }
    for(int i = 2; i <= 7; i++){
        gotoxy(50, i);
        if(i == 7) cout << char(188);
        else cout << char(186);
        if(firstRun[8]) Sleep(1);
    }
    for(int i = 49; i >= 11; i--){
        gotoxy(i, 7);
        if(i == 11) cout << char(200);
        else cout << char(205);
        if(firstRun[8]) Sleep(1);
    }
    for(int i = 6; i >= 2; i--){
        gotoxy(11, i); cout << char(186);
        if(firstRun[8]) Sleep(1);
    }
    // Ve duong ngang
    gotoxy(11, 3); cout << char(204);
    gotoxy(50, 3); cout << char(185);
    for(int i = 12; i < 50; i++){
        gotoxy(i, 3); cout << char(205);
        if(firstRun[8]) Sleep(1);
    }
    gotoxy(11, 5); cout << char(204);
    gotoxy(50, 5); cout << char(185);
    for(int i = 12; i < 50; i++){
        gotoxy(i, 5); cout << char(205);
        if(firstRun[8]) Sleep(1);
    }
    // Ve duong doc
    gotoxy(20, 1); cout << char(203);
    gotoxy(20, 7); cout << char(202);
    for(int i = 2; i < 7; i++){
        gotoxy(20, i); 
        if(i == 3 || i == 5) cout << char(206);
        else cout << char(186);
        if(firstRun[8]) Sleep(1);
    }
    // Dien thong tin
    TextColor(11);
    gotoxy(23, 0); cout << "TRA SACH THU VIEN";  
    gotoxy(12, 2); cout << "MA PM";
    gotoxy(12, 4); cout << "MA SACH";
    gotoxy(12, 6); cout << "TEN SACH";
    firstRun[8] = false;
}
void veKhungInfoBorrow(){
    TextColor(7);
    // Ve khung vuong
    for(int i = 11; i <= 108; i++){
        gotoxy(i, 10);
        if(i == 11) cout << char(201);
        else if(i == 108) cout << char(187);
        else cout << char(205);
        if(firstRun[9]) Sleep(1);
    }
    for(int i = 11; i <= 29; i++){
        gotoxy(108, i);
        if(i == 29) cout << char(188);
        else cout << char(186);
        if(firstRun[9]) Sleep(1);
    }
    for(int i = 107; i >= 11; i--){
        gotoxy(i, 29);
        if(i == 11) cout << char(200);
        else cout << char(205);
        if(firstRun[9]) Sleep(1);
    }
    for(int i = 28; i >= 11; i--){
        gotoxy(11, i); cout << char(186);
        if(firstRun[9]) Sleep(1);
    }
    // Ve duong doc
    gotoxy(19, 10); cout << char(203);
    gotoxy(19, 29); cout << char(202);
    for(int i = 11; i < 29; i++){
        gotoxy(19, i); cout << char(186);
        if(firstRun[9]) Sleep(1);
    }
    gotoxy(50, 10); cout << char(203);
    gotoxy(50, 29); cout << char(202);
    for(int i = 11; i < 29; i++){
        gotoxy(50, i); cout << char(186);
        if(firstRun[9]) Sleep(1);
    }
    gotoxy(58, 10); cout << char(203);
    gotoxy(58, 29); cout << char(202);
    for(int i = 11; i < 29; i++){
        gotoxy(58, i); cout << char(186);
        if(firstRun[9]) Sleep(1);
    }
    gotoxy(85, 10); cout << char(203);
    gotoxy(85, 29); cout << char(202);
    for(int i = 11; i < 29; i++){
        gotoxy(85, i); cout << char(186);
        if(firstRun[9]) Sleep(1);
    }
    gotoxy(97, 10); cout << char(203);
    gotoxy(97, 29); cout << char(202);  
    for(int i = 11; i < 29; i++){
        gotoxy(97, i); cout << char(186);
        if(firstRun[9]) Sleep(1);
    }
    // Ve duong ngang
    gotoxy(11, 12); cout << char(204);
    gotoxy(108, 12); cout << char(185);
    for(int i = 12; i < 108; i++){
        gotoxy(i, 12);
        if(i == 19 || i == 50 || i == 58 || i == 85 || i == 97) cout << char(206);
        else cout << char(205);
        if(firstRun[9]) Sleep(1);
    }
    // Dien thong tin
    TextColor(11);
    gotoxy(49, 9); cout << "BANG THONG TIN MUON SACH";
    gotoxy(13, 11); cout << "MA PM";
    gotoxy(29, 11); cout << "TEN SACH MUON";
    gotoxy(52, 11); cout << "MA DG";
    gotoxy(70, 11); cout << "TEN DG";
    gotoxy(87, 11); cout << "NGAY MUON";
    gotoxy(99, 11); cout << "NGAY TRA";
    firstRun[9] = false;
}
void veKhungSearchByMaDG(){
    TextColor(10);
    // Ve khung vuong
    for(int i = 45; i <= 75; i++){
        gotoxy(i, 4);
        if(i == 45) cout << char(218);
        else if(i == 75) cout << char(191);
        else cout << char(196);
        if(firstRun[10]) Sleep(1);
    }
    for(int i = 5; i <= 10; i++){
        gotoxy(45, i);
        if(i == 10) cout << char(192);
        else cout << char(179);
        if(firstRun[10]) Sleep(1);
    }
    for(int i = 45; i <= 75; i++){
        gotoxy(i, 10);
        if(i == 45) cout << char(192);
        else if(i == 75) cout << char(191);
        else cout << char(196);
        if(firstRun[10]) Sleep(1);
    }
    for(int i = 5; i <= 10; i++){
        gotoxy(75, i);
        if(i == 10) cout << char(217);
        else cout << char(179);
        if(firstRun[10]) Sleep(1);
    }    
    // Ve duong ngang
    for(int i = 45; i <= 75; i++){
        gotoxy(i, 6);
        if(i == 45) cout << char(195);
        else if(i == 75) cout << char(180);
        else cout << char(196);
        if(firstRun[10]) Sleep(1);
    }
    for(int i = 45; i <= 75; i++){
        gotoxy(i, 8);
        if(i == 45) cout << char(195);
        else if(i == 75) cout << char(180);
        else cout << char(196);
        if(firstRun[10]) Sleep(1);
    }
    // Dien thong tin
    TextColor(14);
    gotoxy(47, 5); cout << "NHAP MA DOC GIA CAN TRA CUU";
    firstRun[10] = false;
}
void veKhungSearchInfoDG(){
    TextColor(10);
    // Ve khung vuong
    for(int i = 4; i < 118; i++){
        gotoxy(i, 16);
        if(i == 4) cout << char(201);
        else if(i == 117) cout << char(187);
        else cout << char(205);
        // if(firstRun[11]) Sleep(1);
    }
    for(int i = 17; i < 23; i++){
        gotoxy(4, i);
        if(i == 22) cout << char(200);
        else cout << char(186);
        // if(firstRun[11]) Sleep(1);
    }
    for(int i = 5; i < 118; i++){
        gotoxy(i, 22);
        if(i == 117) cout << char(188);
        else cout << char(205);
        // if(firstRun[11]) Sleep(1);
    }
    for(int i = 17; i < 22; i++){
        gotoxy(117, i); cout << char(186);
    }

    // Ve duong doc
    for(int i = 16; i < 23; i++){
        gotoxy(31, i);
        if(i == 16) cout << char(203);
        else if(i == 22) cout << char(202);
        else cout << char(186);
        // if(firstRun[11]) Sleep(1);
    }
    for(int i = 16; i < 23; i++){
        gotoxy(37, i);
        if(i == 16) cout << char(203);
        else if(i == 22) cout << char(202);
        else cout << char(186);
        // if(firstRun[11]) Sleep(1);
    }
    for(int i = 16; i < 23; i++){
        gotoxy(50, i);
        if(i == 16) cout << char(203);
        else if(i == 22) cout << char(202);
        else cout << char(186);
        // if(firstRun[11]) Sleep(1);
    }
    for(int i = 16; i < 23; i++){
        gotoxy(58, i);
        if(i == 16) cout << char(203);
        else if(i == 22) cout << char(202);
        else cout << char(186);
        // if(firstRun[11]) Sleep(1);
    }
    for(int i = 16; i < 23; i++){
        gotoxy(89, i);
        if(i == 16) cout << char(203);
        else if(i == 22) cout << char(202);
        else cout << char(186);
        // if(firstRun[11]) Sleep(1);
    }
    for(int i = 16; i < 23; i++){
        gotoxy(103, i);
        if(i == 16) cout << char(203);
        else if(i == 22) cout << char(202);
        else cout << char(186);
        // if(firstRun[11]) Sleep(1);
    }

    // Ve duong ngang
    for(int i = 4; i < 118; i++){
        gotoxy(i, 18);
        if(i == 4) cout << char(204);
        else if(i == 117) cout << char(185);
        else if(i == 31 || i == 37 || i == 50 || i == 58 || i == 89 || i == 103) cout << char(206);
        else cout << char(205);
        // if(firstRun[11]) Sleep(1);
    }

    // Dien thong tin 
    TextColor(14);
    gotoxy(52, 15); cout << "THONG TIN DOC GIA";
    gotoxy(10, 17); cout << "HO VA TEN DOC GIA";
    gotoxy(32, 17); cout << "GTINH";
    gotoxy(42, 17); cout << "SO DT";
    gotoxy(51, 17); cout << "MA SACH";
    gotoxy(67, 17); cout << "TEN SACH MUON";
    gotoxy(92, 17); cout << "NGAY MUON";
    gotoxy(107, 17); cout << "NGAY TRA";
    // firstRun[11] = false;
}


// Clear UI
void clearInfoBookUI(){
    // Clear bang thong tin Sach
    for(int i = 5; i < 29; i++){
        for(int j = 1; j < 80; j++){
            gotoxy(j, i);
            if(j == 9 || j == 38 || j == 45 || j == 62 || j == 73) continue;
            else cout << char(32);
        }
    }
}
void clearStatusBar(){
    // Clear Status bar
    for(int i = 83; i < 119; i++){
        gotoxy(i, 25); cout << char(32);
        Sleep(10);
    }
}
void clearAddUI(){
    // Clear bang them sach
    for(int i = 3; i < 12; i += 2){
        for(int j = 93; j < 119; j++){
            gotoxy(j, i); cout << char(32);
        }
    }
}
void clearRemoveUI(){
    // Clear bang xoa sach
    for(int i = 93; i < 119; i++){
        gotoxy(i, 16); cout << char(32);
        gotoxy(i, 18); cout << char(32);
        Sleep(1);
    }
}
void clearInfoMemberUI(){
    // Clear bang thong tin DG
    for(int i = 5; i < 29; i++){
        for(int j = 1; j < 80; j++){
            gotoxy(j, i);
            if(j == 9 || j == 27 || j == 35 || j == 51 || j == 62 || j == 73) continue;
            else cout << char(32);
        }
    }
}
void clearStatusBarBorrow(){
    for(int i = 75; i < 108; i++){
        gotoxy(i, 4); cout << char(32);
        Sleep(10);
    }
}
void clearReturnBook(){
    for(int i = 2; i <= 6; i += 2){
        for(int j = 21; j < 50; j++){
            gotoxy(j, i);
            cout << char(32);
            Sleep(1);
        }
    }
}   
void clearInfoBorrowUI(){
    for(int i = 13; i < 29; i++){
        for(int j = 12; j < 108; j++){
            gotoxy(j, i);
            if(j == 19 || j == 50 || j == 58 || j == 85 || j == 97) continue;
            else cout << char(32);
        }
    }
}
void clearDemNguocBorrow(){
    for(int i = 75; i < 108; i++){
        gotoxy(i, 5); cout << char(32);
    }
}
void clearReturnInputByLine(int line){
    for(int i = 21; i < 50; i++){
        gotoxy(i, line); cout << char(32); Sleep(1);
    }
}
void clearSearchInputByLine(int line){
    for(int i = 46; i < 75; i++){
        gotoxy(i, line); cout << char(32);
        Sleep(1);
    }
}
void clearSearchDG(){
    for(int i = 15; i <= 22; i++){
        for(int j = 4; j < 118; j++){
            gotoxy(j, i); cout << char(32);
        }
    }
}
void clearSLMemberInputByLine(int line){
    for(int i = 42; i <= 77; i++){
        gotoxy(i, line); cout << char(32);
        Sleep(1);
    }
}
void clearAddMemberInput(){
    for(int i = 15; i <= 21; i += 2){
        for(int j = 50; j <= 80; j++){
            gotoxy(j, i); cout << char(32);
        }
    }
}
void clearAllPhieuDangKiMember(){
    for(int i = 13; i <= 22; i++){
        for(int j = 38; j <= 81; j++){
            gotoxy(j, i); cout << char(32);
        }
    }
}
void clearContentAboutMe(){
    for(int i = 12; i <= 18; i+=2){
        for(int j = 40; j <= 80; j++){
            gotoxy(j, i); cout << char(32);
        }
    }
}


// Operation for Reader Management with remove and borrow mode
void addMemberMode(){ 
    int num; 
    while(true){
        gotoxy(46, 5); cout << "So luong doc gia can them:";
        gotoxy(73, 5); cin >> num;  cin.ignore();
        if(num <= 0){
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC);
            clearSLMemberInputByLine(7); TextColor(4);
            gotoxy(47, 7); cout << "Invalid number of readers"; Sleep(2000); clearSLMemberInputByLine(7);
            gotoxy(51, 7); cout << "Please try again!"; Sleep(2000); clearSLMemberInputByLine(7); 
            clearSLMemberInputByLine(5); TextColor(14); gotoxy(46, 5);
            continue;
        }   
        else break;
    } 
    clearSLMemberInputByLine(7); veKhungThemDocGia(); 
    for(int i = 0; i < num; i++){
        gotoxy(46, 7); cout << "Nhap thong tin doc gia thu " << i + 1;
        DocGia dg; dg.nhapInfo_DG(); library.themDocGia(dg); clearAddMemberInput();
    }
}
void removeDGMode(){
    string maDGCanXoa;
    gotoxy(93, 16); cin.ignore(); getline(cin, maDGCanXoa);
    string tenDGCanXoa = library.traCuuTenDG(maDGCanXoa); gotoxy(93, 18);
    if(tenDGCanXoa == ""){
        PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        TextColor(4);
        cout << "Invalid Member ID"; Sleep(2000); clearRemoveUI(); TextColor(7);
    }
    else {
        cout << tenDGCanXoa; Sleep(2000);
        library.xoaDocGia(maDGCanXoa); clearInfoMemberUI(); 
        library.hienThiFullDocGia();
    }
    clearRemoveUI();
}
void returnMode(){
    string maPM, maSachReturn; cin.ignore();
    while(true){
        gotoxy(21, 2); getline(cin, maPM);
        bool checkPM = library.checkErrorReturnBook("MA PM", maPM);
        if(!checkPM){
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC);
            clearReturnInputByLine(2); TextColor(4);
            gotoxy(21, 2); cout << "Invalid Borrow ID"; Sleep(2000); clearReturnInputByLine(2);
            gotoxy(21, 2); cout << "Please try again!"; Sleep(2000); clearReturnInputByLine(2); TextColor(11);         
            continue;
        }
        else break;
    }

    while(true){
        gotoxy(21, 4); getline(cin, maSachReturn);
        bool checkMaSach = library.checkErrorReturnBook("MA SACH", maSachReturn);
        if(!checkMaSach){
            clearReturnInputByLine(4);
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC); TextColor(4);
            gotoxy(21, 4); cout << "Invalid Book ID"; Sleep(2000); clearReturnInputByLine(4);
            gotoxy(21, 4); cout << "Please try again!"; Sleep(2000); clearReturnInputByLine(4); TextColor(11);            
            continue;
        }
        else break;
    }

    string tenSachReturn = library.traCuuTenSach(maSachReturn); gotoxy(21, 6); cout << tenSachReturn;
    // Giam tong sach muon doc gia va tang so luong sach trong thu vien
    string maDG = library.maPMto(maPM, "MA DG"), maSach = library.maPMto(maPM, "MA SACH");
    library.tangGiamTSMuonDG(maDG, "GIAM"); library.tangGiamSLSachThuVien(maSach, "TANG");
    // Xoa phieu muon
    library.xoaPhieuMuon(maPM); Sleep(2000); clearInfoBorrowUI(); library.hienThiFullPhieuMuon(); clearReturnBook();
}
void searchInfoDGMode(){
    string maDGCanSearch; cin.ignore();
    while(true){
        gotoxy(57, 7); getline(cin, maDGCanSearch);
        bool check = library.checkErrorSearchInfoDG("MA DG", maDGCanSearch);
        if(!check){
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC);
            clearSearchInputByLine(7); TextColor(4);
            gotoxy(51, 7); cout << "Reader ID Not Found"; Sleep(2000); clearSearchInputByLine(7);
            gotoxy(52, 7); cout << "Please try again!"; Sleep(2000); clearSearchInputByLine(7); 
            TextColor(14);
            continue;
        }
        else break;
    }
    // Tim thay ID doc gia trong thu vien
    veKhungSearchInfoDG(); library.hienThiInfoDGByID(maDGCanSearch); exitESC(); clearSearchDG(); clearSearchInputByLine(7);
}


// Operation for Book Management with remove and add mode
void addBookMode(){
    Sach sach;
    sach.nhapInfo_Sach(); library.themSach(sach);
    library.hienThiFullSach(); clearAddUI();
}
void removeBookMode(){
    string maSachCanXoa;
    gotoxy(93, 16); cin.ignore(); getline(cin, maSachCanXoa);
    string tenSachCanXoa = library.traCuuTenSach(maSachCanXoa); gotoxy(93, 18);
    if(tenSachCanXoa == ""){
        PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC); TextColor(4);
        cout << "Invalid Book ID"; Sleep(2000); TextColor(7);
    }
    else {
        cout << tenSachCanXoa; Sleep(2000);
        library.xoaSach(maSachCanXoa); clearInfoBookUI(); 
        library.hienThiFullSach();
    }
    clearRemoveUI();
}
void borrowMode(){  
    PhieuMuon borrow; borrow.nhapInfo_PhieuMuon(); 
    string nameBook = library.traCuuTenSach(borrow.getMaSach()); borrow.tenSach = nameBook;
    string nameDG = library.traCuuTenDG(borrow.getMaDG()); borrow.tenDocGia = nameDG;
    gotoxy(93, 11); cout << nameBook;
    library.taoPhieuMuon(borrow); Sleep(2000); 
    // Tang tong sach muon doc gia va giam so luong sach trong thu vien
    library.tangGiamTSMuonDG(borrow.getMaDG(), "TANG"); 
    library.tangGiamSLSachThuVien(borrow.getMaSach(), "GIAM"); 
    clearInfoMemberUI(); library.hienThiFullDocGia(); clearAddUI();
}   
void logicStatusBar(int status){ 
    while(status == 1){
        gotoxy(86, 25); cout << "Press A/D to add/delete book: ";
        char press; gotoxy(116, 25); cin >> press; clearStatusBar();
        if(press == 'A' || press == 'a'){
            gotoxy(89, 25); cout << "Activate book adding mode";
            addBookMode(); clearStatusBar(); 
            continue;
        }
        else if(press == 'D' || press == 'd'){
            gotoxy(88, 25); cout << "Activate book deletion mode";
            removeBookMode(); clearStatusBar();
            continue;
        }
        else if(press == 'E' || press == 'e') {
            gotoxy(84, 25); cout << "The application will exit later..."; demNguoc();
            return;
        }
        else {
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC); TextColor(4);
            gotoxy(91, 25); cout << "Invalid input syntax"; Sleep(2000); clearStatusBar();
            gotoxy(89, 25); cout << "Please re-enter correctly!"; Sleep(2000); clearStatusBar(); TextColor(7);
            continue;
        }
    } 
    while(status == 2){
        gotoxy(84, 25); cout << "Press B/D to borrow/delete user: ";
        char press; gotoxy(117, 25); cin >> press; clearStatusBar();
        if(press == 'B' || press == 'b'){
            gotoxy(87, 25); cout << "Activate book borrowing mode";
            borrowMode(); clearStatusBar(); 
            continue;
        }
        else if(press == 'D' || press == 'd'){
            gotoxy(88, 25); cout << "Activate member deletion mode";
            removeDGMode(); clearStatusBar();
            continue;
        }
        else if(press == 'E' || press == 'e') {
            gotoxy(84, 25); cout << "The application will exit later..."; demNguoc();
            return;
        }
        else {
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC); TextColor(4);
            gotoxy(91, 25); cout << "Invalid input syntax"; Sleep(2000); clearStatusBar();
            gotoxy(89, 25); cout << "Please re-enter correctly!"; Sleep(2000); clearStatusBar(); TextColor(7);
            continue;
        }
    }
    while(status == 3){
        gotoxy(79, 4); cout << "Press R to return book:";
        char press; gotoxy(103, 4); cin >> press; clearStatusBarBorrow();
        if(press == 'R' || press == 'r'){
            gotoxy(77, 4); cout << "Activate book returning mode";
            returnMode(); clearStatusBarBorrow(); 
            continue;
        }
        else if(press == 'E' || press == 'e') {
            gotoxy(75, 4); cout << "The application will exit later.."; 
            // Dem nguoc cho return mode
            PlaySound(TEXT("Sound/count.wav"), NULL, SND_FILENAME | SND_ASYNC);
            gotoxy(90, 5); TextColor(10);
            cout << "3"; Sleep(1000); clearDemNguocBorrow();
            gotoxy(90, 5); TextColor(14);
            cout << "2"; Sleep(1000); clearDemNguocBorrow();
            gotoxy(90, 5); TextColor(4);
            cout << "1"; Sleep(1000); clearDemNguocBorrow();
            return;
        }
        else {
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC); TextColor(4);
            gotoxy(81, 4); cout << "Invalid input syntax"; Sleep(2000); clearStatusBarBorrow();
            gotoxy(79, 4); cout << "Please re-enter correctly!"; Sleep(2000); clearStatusBarBorrow();
            TextColor(11);
            continue;
        }
    }
    while(status == 4){
        gotoxy(47, 9); cout << "Press S to search member:";
        char press; gotoxy(73, 9); cin >> press; clearSearchInputByLine(9);
        if(press == 'S' || press == 's'){
            gotoxy(47, 9); cout << "Activate member search mode";
            searchInfoDGMode(); clearSearchInputByLine(9); 
            continue;
        }
        else if(press == 'E' || press == 'e') {
            gotoxy(48, 9); cout << "Exit search member mode..."; Sleep(2000); clearSearchInputByLine(9);
            return;
        }
        else {
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC); TextColor(4);
            gotoxy(50, 9); cout << "Invalid input syntax"; Sleep(2000); clearSearchInputByLine(9);
            gotoxy(47, 9); cout << "Please re-enter correctly!"; Sleep(2000); clearSearchInputByLine(9); TextColor(14);
            continue;
        }
    }
    while(status == 5){
        TextColor(14);
        gotoxy(48, 7); cout << "Press A to add readers:";
        char press; gotoxy(72, 7); cin >> press; clearSLMemberInputByLine(7);
        if(press == 'A' || press == 'a'){
            gotoxy(47, 7); cout << "Activate member add mode";
            addMemberMode(); clearAllPhieuDangKiMember();
            clearSLMemberInputByLine(5); clearSLMemberInputByLine(7); 
            continue;
        }
        else if(press == 'E' || press == 'e') {
            gotoxy(49, 7); cout << "Exit add member mode..."; Sleep(2000); clearSLMemberInputByLine(7);
            return;
        }
        else {
            PlaySound(TEXT("Sound/error.wav"), NULL, SND_FILENAME | SND_ASYNC); TextColor(4);
            gotoxy(49, 7); cout << "Invalid input syntax"; Sleep(2000); clearSLMemberInputByLine(7);
            gotoxy(48, 7); cout << "Please re-enter correctly!"; Sleep(2000); clearSLMemberInputByLine(7); TextColor(14);
            continue;
        }
    }
}


// Menu for Book and Reader Management
void readerMode(){
    khungMenu();
	char ask;
	int choice[] = {4, 7, 7, 7};
	int counter = 1;
    char key;
    gotoxy(48, 11);
    TextColor(10);
    cout << "Reader Management Mode";
    for(int i=0;;){
    	gotoxy(51,14);
        TextColor(choice[0]);
        cout<<"Dang ki doc gia";

        gotoxy(49,16);
        TextColor(choice[1]);
        cout<<"Tim thong tin doc gia";

        gotoxy(46,18);
        TextColor(choice[2]);
        cout<<"Hien thi danh sach doc gia";

        gotoxy(54,20);
        TextColor(choice[3]);
        cout<<"Exit mode";

        key = _getch();    
        if(key == 72 && (counter >=2 && counter <= 4)) {
            PlaySound(TEXT("Sound/go.wav"), NULL, SND_FILENAME | SND_ASYNC);
            counter--;
        }
        if(key == 80 && (counter >=1 && counter <= 3)) {
            PlaySound(TEXT("Sound/go.wav"), NULL, SND_FILENAME | SND_ASYNC);
            counter++;
        }
        
        if(key == '\r')
        {
            if(counter == 1)
            {
                PlaySound(TEXT("Sound/move.wav"), NULL, SND_FILENAME | SND_ASYNC);
            	clrscr();
                veKhungSoLuongDocGia();
                logicStatusBar(5);
                return;
            }
            if(counter == 2)
            {
                PlaySound(TEXT("Sound/move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                clrscr();
                veKhungSearchByMaDG();
                logicStatusBar(4);
            	return; 
            }
            if(counter == 3)
            {
                PlaySound(TEXT("Sound/move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                clrscr(); 
                veKhungInfoReader(); 
                veKhungThem(10, 12, "TAO PHIEU MUON SACH", "MA DG", "NGAY MUON", "NGAY TRA", "MA SACH", "TEN SACH"); 
                veKhungXoa(14, 12, "XOA DG KHOI THU VIEN", "MA DG", "TEN DG"); 
                veKhungStatus(4, "THANH TRANG THAI"); 
                library.hienThiFullDocGia();
                logicStatusBar(2);
                return;	
            }
            if(counter == 4) return; 
		}
		choice[0] = 7;
        choice[1] = 7;
        choice[2] = 7;
        choice[3] = 7;
        if(counter == 1)
        {
            choice[0] = 4;
        }
        if(counter == 2)
        {
            choice[1] = 4;
        }
        if(counter == 3)
        {
            choice[2] = 4;
        }
        if(counter == 4)
        {
            choice[3] = 4;
        }
	}
}
void bookMode(){
    khungMenu();
	char ask;
	int choice[] = {4, 7, 7};
	int counter = 1;
    char key;
    gotoxy(49, 11);
    TextColor(10);
    cout << "Book Management Mode";
    for(int i=0;;){
        gotoxy(49,14);
        TextColor(choice[0]);
        cout<< "Thong tin phieu muon";

        gotoxy(48,17);
        TextColor(choice[1]);
        cout<<"Hien thi thong tin sach";

        gotoxy(54,20);
        TextColor(choice[2]);
        cout<<"Exit mode";

        key = _getch();    
        if(key == 72 && (counter >=2 && counter <= 3)) {
            PlaySound(TEXT("Sound/go.wav"), NULL, SND_FILENAME | SND_ASYNC);
            counter--;
        }
        if(key == 80 && (counter >=1 && counter <= 2)) {
            PlaySound(TEXT("Sound/go.wav"), NULL, SND_FILENAME | SND_ASYNC);
            counter++;
        }
        
        if(key == '\r')
        {
            if(counter == 1)
            {
                PlaySound(TEXT("Sound/move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                clrscr(); 
                veKhungReturnBook(); veKhungStatusBorrow(); veKhungInfoBorrow();
                library.hienThiFullPhieuMuon();
                logicStatusBar(3);
				return;     
            }
            if (counter == 2)
            {
                PlaySound(TEXT("Sound/move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                clrscr(); 
                veKhungInfoBook(12, 11, "BANG THONG TIN BOOKS", "Ma Sach", "Ten Sach", "NXB", "Ten Tac Gia", "So trang", "SL"); 
                veKhungThem(14, 11, "THEM SACH VAO THU VIEN", "TEN SACH", "TEN TG", "NAM XB", "SO TRANG", "SO LUONG"); 
                veKhungXoa(10, 11, "XOA SACH KHOI THU VIEN", "MA SACH", "TEN SACH"); 
                veKhungStatus(1, "THANH TRANG THAI"); 
                library.hienThiFullSach();
                logicStatusBar(1);
                return;
            }

            if(counter == 3)
            {    	
                PlaySound(TEXT("Sound/move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                return;
            }
		}
		choice[0] = 7;
        choice[1] = 7;
        choice[2] = 7;
        if(counter == 1)
        {
            choice[0] = 4;
        }
        if(counter == 2)
        {
            choice[1] = 4;
        }
        if(counter == 3)
        {
            choice[2] = 4;
        }
	}
}


int main(){	
    // Test Data 
    // 1. Sach
    Sach sach1("Atomic Habits", "James Clear", 2018, 388, 7); library.themSach(sach1);
    Sach sach2("Nha Gia Kim", "Paulo Coelho", 1988, 225, 102); library.themSach(sach2);
    Sach sach3("7 Thoi Quen De Thanh Dat", "Stephen Covey", 1989, 288, 2); library.themSach(sach3);
    Sach sach4("Tu Tot Den Vi Dai", "Jim Collins", 2001, 484, 14); library.themSach(sach4);
    Sach sach5("Dac Nhan Tam", "Dale Carnegie", 1936, 291, 32); library.themSach(sach5);
    Sach sach6("Khong Gia Dinh", "Hector Malot", 1878, 635, 98); library.themSach(sach6);

    // 2. Doc Gia
    DocGia dg1("Quach Phu", "Thuan", "Nam", "0886332809"); library.themDocGia(dg1); 
    DocGia dg2("Tran Anh", "Thu", "Nu", "0886332809"); library.themDocGia(dg2); 
    DocGia dg3("Doan Vinh", "Khang", "Nam", "0939316440"); library.themDocGia(dg3);
    DocGia dg4("Tran Trong", "Tri", "Nam", "0939316440"); library.themDocGia(dg4);
    DocGia dg5("Tran Nguyen Minh", "Quan", "Nam", "0939316440"); library.themDocGia(dg5);
    DocGia dg6("Le Pham Thanh", "Duy", "Nam", "0939316440"); library.themDocGia(dg6);
    
    // App
	hideCursor();
	tenLib();
    khungMenu();
	int Set[] = {4, 7, 7, 7, 7};
	int counter = 1;
	char key;
	for(int i=0;;) {	
        gotoxy(50,15);
        TextColor(Set[0]);
        cout<<"Reader Management";
     
        gotoxy(50,16);
        TextColor(Set[1]);
        cout<<"Book Management";

        gotoxy(50,17);
        TextColor(Set[2]);
        cout<<"Help";

        gotoxy(50,18);
        TextColor(Set[3]);
        cout<<"About me";

        gotoxy(50,19);
        TextColor(Set[4]);
        cout<<"Exit";

        key = _getch();

        if(key == 72 && (counter >=2 && counter <= 5)) {
            PlaySound(TEXT("Sound/go.wav"), NULL, SND_FILENAME | SND_ASYNC);
            counter--;
        } 
        if(key == 80 && (counter >=1 && counter <= 4)) {
            PlaySound(TEXT("Sound/go.wav"), NULL, SND_FILENAME | SND_ASYNC);
            counter++;
        }  
        if(key == '\r')
        {
            if(counter == 1)
            {          
                PlaySound(TEXT("Sound/move.wav"), NULL, SND_FILENAME | SND_ASYNC);	
				loading();			
				clrscr();
                readerMode();
                clrscr();
				khungMenu();
				tenLib();
				continue;
            }
            if(counter == 2)
            {
                PlaySound(TEXT("Sound/move.wav"), NULL, SND_FILENAME | SND_ASYNC);
            	loading();			
				clrscr();
                bookMode();
                clrscr();
				khungMenu();
				tenLib();
				continue;
            }
            if(counter == 3)
            {
                PlaySound(TEXT("Sound/move.wav"), NULL, SND_FILENAME | SND_ASYNC);
            	clrscr(); help();
                exitESC(); clrscr(); khungMenu(); tenLib();
                continue;
            }
            if(counter == 4)
            {
                PlaySound(TEXT("Sound/move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                clrscr();
                aboutMe("Tran Trong Tri", "22H1120140", "CN22CLCE", "University Of Transport HCM City"); Sleep(1000); clearContentAboutMe();
                aboutMe("Le Pham Thanh Duy", "22H1120123", "CN22CLCE", "University Of Transport HCM City"); Sleep(1000); clearContentAboutMe();
                aboutMe("Quach Phu Thuan", "2251120446", "CN22CLCE", "University Of Transport HCM City");
				exitESC();
				clrscr();
				khungMenu();				
				tenLib();
				continue; 
            }
            if(counter == 5)
            {
                PlaySound(TEXT("Sound/move.wav"), NULL, SND_FILENAME | SND_ASYNC);
                clrscr();
            	exitLib();
            	khungMenu();
				tenLib();
				continue;
            }
        }
        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        Set[3] = 7;
        Set[4] = 7;

        if(counter == 1)
        {
            Set[0] = 4;
        }
        if(counter == 2)
        {
            Set[1] = 4;
        }
        if(counter == 3)
        {
            Set[2] = 4;
        }
        if(counter == 4)
        {
            Set[3] = 4;
        }
        if(counter == 5)
        {
            Set[4] = 4;
        }
    }
}

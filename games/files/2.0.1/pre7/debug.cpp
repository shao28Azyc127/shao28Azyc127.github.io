#include <iostream>
#include <Windows.h>
using namespace std;
enum Scale{
    Rest=0,
    C8=108,B7=107,A7s=106,A7=105,G7s=104,G7=103,
    F7s=102,F7=101,E7=100,D7s=99,D7=98,C7s=97,
    C7=96,B6=95,A6s=94,A6=93,G6s=92,G6=91,F6s=90,
    F6=89,E6=88,D6s=87,D6=86,C6s=85,C6=84,B5=83,
    A5s=82,A5=81,G5s=80,G5=79,F5s=78,F5=77,E5=76,
    D5s=75,D5=74,C5s=73,C5=72,B4=71,A4s=70,A4=69,
    G4s=68,G4=67,F4s=66,F4=65,E4=64,D4s=63,D4=62,
    C4s=61,C4=60,B3=59,A3s=58,A3=57,G3s=56,G3=55,
    F3s=54,F3=53,E3=52,D3s=51,D3=50,C3s=49,C3=48,
    B2=47,A2s=46,A2=45,G2s=44,G2=43,F2s=42,F2=41,
    E2=40,D2s=39,D2=38,C2s=37,C2=36,B1=35,A1s=34,
    A1=33,G1s=32,G1=31,F1s=30,F1=29,E1=28,D1s=27,
    D1=26,C1s=25,C1=24,B0=23,A0s=22,A0=21
};
enum Voice{
    X1=C2,X2=D2,X3=E2,X4=F2,X5=G2,X6=A2,X7=B2,
    L1=C3,L2=D3,L3=E3,L4=F3,L5=G3,L6=A3,L7=B3,
    M1=C4,M2=D4,M3=E4,M4=F4,M5=G4,M6=A4,M7=B4,
    H1=C5,H2=D5,H3=E5,H4=F5,H5=G5,H6=A5,H7=B5,
    LOW_SPEED=500,MIDDLE_SPEED=400,HIGH_SPEED=300,_=0XFF
};
void RICKROLLing(){
    HMIDIOUT handle;
    midiOutOpen(&handle,0,0,0,CALLBACK_NULL);
    midiOutShortMsg(handle,34<<8|0xC0);
    int volume=0x7f;int voice=0x0;int sleep=1000;
    int RR[]={
H1,H2,0,500,M5,1000,H2,1000,H3,125,
H5,H4,H3,H1,1000,H1,1000,H2,0,500,M5,1000,H2,H1,
109,M5,M5,M6,H1,M6,H1,1000,
H1,H2,0,500,M5,1000,H2,1000,H3,125,
H5,H4,H3,H1,1000,H1,1000,H2,0,500,M5,1000,H2,H1,
//Ç°×à 

300,
L6,L7,M1,M1,M2,L7,L6,L5,
//We're no strangers to love
L6,L6,L7,M1,L6,L5,M5,M5,M2,
//You know the rules and so do I (do I)
L6,L6,L7,M1,L6,M1,M2,L7,L6,L6,L5,
//A full commitment's what I'm thinking of
L6,L6,L7,M1,L6,L5,M2,M2,M2,M3,M2,
//You wouldn't get this from any other guy

//4-START
M1,M2,M3,M1,M2,M2,M2,M3,M2,L5,
//I just wanna tell you how I'm feeling
L6,L7,M1,L6,M2,M3,M2,
//Gotta make you understand
//4-END

//1-START
L5,L6,M1,L6,M3,M3,M2,
//Never gonna give you up
L5,L6,M1,L6,M2,M2,M1,L7,L6,
//Never gonna let you down
L5,L6,M1,L6,M1,M2,L7,L6,L5,L5,M2,M1,
//Never gonna run around and desert you
L5,L6,M1,L6,M3,M3,M2,
//Never gonna make you cry
L5,L6,M1,L6,M5,L7,M1,L7,L6,
//Never gonna say goodbye
L5,L6,M1,L6,M1,M2,L7,L6,L5,L5,M2,M1,
//Never gonna tell a lie and hurt you
//1-END

//3-START
M1,M1,L6,M1,M2,L7,L6,L7,L6,L5,
//We've known each other for so long
L6,L6,L7,M1,L6,L5,M5,M5,M2,M3,M2,M1,
//Your heart's been aching, but you're too shy to say it (say it)
M1,M1,L6,M1,L6,M1,M2,L7,L6,L7,L6,L5,
//Inside, we both know what's been going on (going on)
L6,L6,L7,M1,L6,L5,M2,M3,M3,M2,
//We know the game and we're gonna play it
//3-END

M1,M2,M3,M1,M2,M2,M2,M3,M2,L5,
//And if you ask me how I'm feeling
L5,L6,L7,M1,L6,M2,M3,M2,
//Don't tell me you're too blind to see

//1-START
L5,L6,M1,L6,M3,M3,M2,
//Never gonna give you up
L5,L6,M1,L6,M2,M2,M1,L7,L6,
//Never gonna let you down
L5,L6,M1,L6,M1,M2,L7,L6,L5,L5,M2,M1,
//Never gonna run around and desert you
L5,L6,M1,L6,M3,M3,M2,
//Never gonna make you cry
L5,L6,M1,L6,M5,L7,M1,L7,L6,
//Never gonna say goodbye
L5,L6,M1,L6,M1,M2,L7,L6,L5,L5,M2,M1,
//Never gonna tell a lie and hurt you
//1-END

//1-START
L5,L6,M1,L6,M3,M3,M2,
//Never gonna give you up
L5,L6,M1,L6,M2,M2,M1,L7,L6,
//Never gonna let you down
L5,L6,M1,L6,M1,M2,L7,L6,L5,L5,M2,M1,
//Never gonna run around and desert you
L5,L6,M1,L6,M3,M3,M2,
//Never gonna make you cry
L5,L6,M1,L6,M5,L7,M1,L7,L6,
//Never gonna say goodbye
L5,L6,M1,L6,M1,M2,L7,L6,L5,L5,M2,M1,
//Never gonna tell a lie and hurt you
//1-END

H1,H1,M7,
//(Ooh, give you up)
H1,H1,M7,
//(Ooh, give you up)
M5,M6,H1,M6,H3,M5,M6,H1,M6,H3,H1,H1,M7,
//(Ooh) Never gonna give, never gonna give (give you up)
M5,M6,H1,M6,H3,M5,M6,H1,M6,H3,H1,H1,M7,
//(Ooh) Never gonna give, never gonna give (give you up)

//3-START
M1,M1,L6,M1,M2,L7,L6,L7,L6,L5,
//We've known each other for so long
L6,L6,L7,M1,L6,L5,M5,M5,M2,M3,M2,M1,
//Your heart's been aching, but you're too shy to say it (say it)
M1,M1,L6,M1,L6,M1,M2,L7,L6,L7,L6,L5,
//Inside, we both know what's been going on (going on)
L6,L6,L7,M1,L6,L5,M2,M3,M3,M2,
//We know the game and we're gonna play it
//3-END

M1,M2,M3,M1,M2,M2,M2,M3,M2,L5,
//And if you ask me how I'm feeling
L5,L6,L7,M1,L6,M2,M3,M2,
//Don't tell me you're too blind to see

//1-START
L5,L6,M1,L6,M3,M3,M2,
//Never gonna give you up
L5,L6,M1,L6,M2,M2,M1,L7,L6,
//Never gonna let you down
L5,L6,M1,L6,M1,M2,L7,L6,L5,L5,M2,M1,
//Never gonna run around and desert you
L5,L6,M1,L6,M3,M3,M2,
//Never gonna make you cry
L5,L6,M1,L6,M5,L7,M1,L7,L6,
//Never gonna say goodbye
L5,L6,M1,L6,M1,M2,L7,L6,L5,L5,M2,M1,
//Never gonna tell a lie and hurt you
//1-END

//1-START
L5,L6,M1,L6,M3,M3,M2,
//Never gonna give you up
L5,L6,M1,L6,M2,M2,M1,L7,L6,
//Never gonna let you down
L5,L6,M1,L6,M1,M2,L7,L6,L5,L5,M2,M1,
//Never gonna run around and desert you
L5,L6,M1,L6,M3,M3,M2,
//Never gonna make you cry
L5,L6,M1,L6,M5,L7,M1,L7,L6,
//Never gonna say goodbye
L5,L6,M1,L6,M1,M2,L7,L6,L5,L5,M2,M1,
//Never gonna tell a lie and hurt you
//1-END

//1-START
L5,L6,M1,L6,M3,M3,M2,
//Never gonna give you up
L5,L6,M1,L6,M2,M2,M1,L7,L6,
//Never gonna let you down
L5,L6,M1,L6,M1,M2,L7,L6,L5,L5,M2,M1,
//Never gonna run around and desert you
L5,L6,M1,L6,M3,M3,M2,
//Never gonna make you cry
L5,L6,M1,L6,M5,L7,M1,L7,L6,
//Never gonna say goodbye
L5,L6,M1,L6,M1,M2,L7,L6,L5,L5,M2,M1,
//Never gonna tell a lie and hurt you
//1-END

    };
    for(auto i:RR){
        if(i>108){sleep=i;continue;}
        if(i==0){sleep=175;continue;}
        if(i==700){Sleep(175);continue;}
        if(i==_){Sleep(500);continue;}
        if(i>10000){volume+=(i-10000);}
        voice=(volume<<16)+((i)<<8)+0x90;
        midiOutShortMsg(handle,voice);
        Sleep(sleep);
    }
    midiOutClose(handle);
}

int main(){
	RICKROLLing();
}

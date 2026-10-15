#include<conio.h>
#include<dos.h>

#define NOTE_B1 62
#define NOTE_Gb2 92
#define NOTE_B2 123
#define NOTE_Bb1 59
#define NOTE_F2 87
#define NOTE_Bb2 117
#define NOTE_Eb2 78
#define NOTE_Eb3 156
#define NOTE_Db2 70
#define NOTE_Ab2 104
#define NOTE_Db3 139

void main()
{
    int eighth = 214;
    int sixteenth = 107;
    int i;
    int loopCount;

    int melody1[] = {
	NOTE_B1, NOTE_B2, NOTE_B1, NOTE_B2,
	NOTE_Bb1, NOTE_Bb2, NOTE_Bb1, NOTE_Bb2,
	NOTE_Eb2, NOTE_Eb3, NOTE_Eb2, NOTE_Eb3,
	NOTE_Db2, NOTE_Db3, NOTE_Db2, NOTE_Db3
    };

    int durations1[] = {
	eighth, eighth, eighth, eighth,
	eighth, eighth, eighth, eighth,
	eighth, eighth, eighth, eighth,
	eighth, eighth, eighth, eighth
    };
    int melody2[] = {NOTE_B1, NOTE_Gb2, NOTE_B2, NOTE_B1, NOTE_B2, NOTE_Bb1, NOTE_F2, NOTE_Bb2, NOTE_Bb1, NOTE_Bb2, NOTE_Eb2, NOTE_Bb2, NOTE_Eb3, NOTE_Eb2, NOTE_Eb3, NOTE_Db2, NOTE_Ab2, NOTE_Db3, NOTE_Db2, NOTE_Db3};
    int durations2[] = {eighth, sixteenth, sixteenth, eighth, eighth, eighth, sixteenth, sixteenth, eighth, eighth, eighth, sixteenth, sixteenth, eighth, eighth, eighth, sixteenth, sixteenth, eighth, eighth};

    clrscr();

    // --- 1-Second Audio Sync Pop ---
    // Snaps perfectly with your Percussion, Melody, and Arp files
    sound(1000); delay(100); nosound();
    delay(1000);

    // Loops the entire 8-beat bassline 2 times to match the rest of the song
    for (loopCount = 0; loopCount < 2; loopCount++)
    {
	for (i = 0; i < 16; i++)
	{
	    sound(melody1[i]);
	    // Subtract the 10ms gap so each eighth note stays exactly 214ms total
	    delay(durations1[i] - 10);
	    nosound();
	    delay(10);
	}
    }
    for (loopCount = 0; loopCount < 2; loopCount++)
    {
    for (i = 0; i < 20; i++)
    {
    sound(melody2[i]);
    delay(durations2[i] - 10);
    nosound();
    delay(10);
    }
    }
    getch();
}

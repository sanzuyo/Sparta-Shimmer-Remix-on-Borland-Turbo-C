#include<conio.h>
#include<dos.h>

#define NOTE_Gb5 740
#define NOTE_F5 698
#define NOTE_Eb5 622
#define NOTE_Db5 554
#define NOTE_Ab4 415
#define NOTE_A4 440
#define NOTE_Bb4 466
#define NOTE_Eb4 311
#define NOTE_Gb4 370
#define NOTE_B4  494
#define NOTE_Db4 277

void main()
{
    int half = 856;
    int dottedquarter = 642;
    int quarter = 428;
    int eighth = 214;
    int sixteenth = 107;
    int i, loopCount;

    // ==========================================
    // SECTION 1: ORIGINAL MELODY DATA (13 Notes)
    // ==========================================
    int melody1[] = {NOTE_Gb5, NOTE_F5, NOTE_Eb5, NOTE_Db5, NOTE_Ab4, NOTE_A4, NOTE_Bb4, NOTE_Eb4, NOTE_Gb4, NOTE_Ab4, NOTE_Bb4, NOTE_Ab4, NOTE_Gb4};
    int durations1[] = {quarter, eighth, eighth, quarter, eighth, eighth, quarter, eighth, eighth, eighth, eighth, eighth, eighth};

    // ==========================================
    // SECTION 2: NEW EXTENDED MELODY DATA (26 Notes)
    // ==========================================
    int melody2[] = {
	NOTE_Eb4, NOTE_Gb4, NOTE_Ab4, NOTE_Bb4, NOTE_Ab4, NOTE_Gb4,
	NOTE_Eb4, NOTE_Gb4, NOTE_Ab4, NOTE_Bb4, NOTE_Ab4, NOTE_Gb4,
	NOTE_Bb4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_Bb4, NOTE_Ab4,
	NOTE_Gb4, NOTE_Eb4, NOTE_Db4, NOTE_Eb4, NOTE_Gb4, NOTE_Bb4,
	NOTE_Ab4, NOTE_Gb4
    };

    int durations2[] = {
	dottedquarter, eighth, eighth, eighth, eighth, eighth,
	dottedquarter, eighth, eighth, eighth, eighth, eighth,
	eighth, eighth, quarter, quarter, quarter, quarter,
	quarter, eighth, eighth, eighth, eighth, eighth,
	eighth, half
    };

    clrscr();

    // --- 1-Second Audio Sync Pop ---
    sound(1000); delay(100); nosound();
    delay(1000);

    // ==========================================
    // PLAYBACK BLOCK 1: ORIGINAL THEME (Loops 2 Times)
    // ==========================================
    for (loopCount = 0; loopCount < 2; loopCount++)
    {
	for (i = 0; i < 13; i++)
	{
	 //STACCATO
	 if ((i == 0 && melody1[i] == NOTE_Gb5) || (i == 3 && melody1[i] == NOTE_Db5) || (i == 6 && melody1[i]))
	 {
	 sound(melody1[i]);
	 delay(214);
	 nosound();
	 delay(224);
	 }
	 else
	 {
	 sound(melody1[i]);
	 delay(durations1[i] - 10);
	 nosound();
	 delay(10);
	 }
	 }
	 }

    // ==========================================
    // PLAYBACK BLOCK 2: NEW EXTENDED PITCH VARIATION
    // ==========================================
    for (i = 0; i < 26; i++)
    {
	sound(melody2[i]);
	// STACCATO 2
	if ((i == 12 && melody2[i] == NOTE_Bb4) || (i == 13 && melody2[i] == NOTE_B4))
	{
	delay(47);
	nosound();
	delay(60);
	}
	else if (i == 14 && melody2[i] == NOTE_B4)
	{
	delay(107);
	nosound();
	delay(112);
	}
	else
	{
	delay(durations2[i] - 10);
	nosound();
	delay(10);
	}
	}
	getch();
	}

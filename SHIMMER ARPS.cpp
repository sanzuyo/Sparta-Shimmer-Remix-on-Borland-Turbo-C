#include<dos.h>
#include<conio.h>

void main()
{
    int i;
    int loopCount;
    clrscr();

    // --- 1-Second Audio Sync Pop ---
    // Matches the exact placement in your melody and percussion scripts
    sound(1000); delay(100); nosound();
    delay(1000);

    // Loops the entire 8-beat progression 2 times to match the song arrangement
    for (loopCount = 0; loopCount < 2; loopCount++)
    {
        // --- CHORD 1: Bmajor7 (2 Beats / 856ms) ---
        // 14 cycles * 4 notes * 15ms = 840ms. Buffer = 16ms to hit 856ms.
        for(i = 0; i < 14; i++) {
            sound(494); delay(15); // B4
            sound(622); delay(15); // D#5
            sound(740); delay(15); // F#5
            sound(932); delay(15); // A#5
        }
        delay(16); 

        // --- CHORD 2: Bbminor7 (2 Beats / 856ms) ---
        for(i = 0; i < 14; i++) {
            sound(466); delay(15); // Bb4
            sound(554); delay(15); // Db5
            sound(698); delay(15); // F5
            sound(831); delay(15); // Ab5
        }
        delay(16);

        // --- CHORD 3: Ebminor7 (2 Beats / 856ms) ---
        for(i = 0; i < 14; i++) {
            sound(622); delay(15); // Eb5
            sound(740); delay(15); // Gb5
            sound(932); delay(15); // Bb5
            sound(1109); delay(15); // Db6
        }
        delay(16);

        // --- CHORD 4: Db7 (2 Beats / 856ms) ---
        // Cleanly updated comments to match your beautiful 4-note dominant 7th layout
        for(i = 0; i < 14; i++) {
            sound(554); delay(15); // Db5
            sound(698); delay(15); // F5
            sound(831); delay(15); // Ab5
            sound(988); delay(15); // B5
        }
        delay(16); 
    }

    nosound(); // Turn off the PC speaker cleanly at the end of the song
    getch();
}

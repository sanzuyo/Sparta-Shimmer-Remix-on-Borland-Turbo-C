#include<dos.h>
#include<conio.h>
#include<stdlib.h> 

void playKick() {
    int freq;
    for (freq = 150; freq > 40; freq -= 8) { sound(freq); delay(3); }
    nosound();
}

void playSnare() {
    int i;
    for (i = 0; i < 40; i++) { sound(200 + rand() % 600); delay(2); }
    nosound();
}

void playFastSnare() {
    int i;
    for (i = 0; i < 15; i++) { sound(200 + rand() % 600); delay(2); }
    nosound();
}

void playCymbal() {
    int i;
    for (i = 0; i < 20; i++) { sound(3000 + rand() % 4000); delay(2); }
    nosound();
}

void main()
{
    int i;
    int quarter = 428;
    int eighth = 214;
    int sixteenth = 107; 
    
    clrscr();
    
    // Sync Pop
    sound(1000); delay(100); nosound();
    delay(1000);

    // Loop the 8-beat pattern 2 times to match the melody track
    for (i = 0; i < 2; i++)
    {
        // --- MEASURE 1 (Beats 1 - 4) ---
        playKick(); delay(quarter - 42);   // Beat 1
        playCymbal(); delay(quarter - 40); // Beat 2
        playSnare(); delay(quarter - 80);  // Beat 3
        playCymbal(); delay(quarter - 40); // Beat 4

        // --- MEASURE 2 (Beats 5 - 8) ---
        playKick(); delay(quarter - 42);   // Beat 5
        playCymbal(); delay(eighth - 40);  // Beat 6 (Part A)
        playCymbal(); delay(eighth - 40);  // Beat 6 (Part B)
        playSnare(); delay(quarter - 80);  // Beat 7
        
        // Beat 8: The 4-Hit Sixteenth Note Drum Roll!
        playFastSnare(); delay(sixteenth - 30);
        playFastSnare(); delay(sixteenth - 30);
        playFastSnare(); delay(sixteenth - 30);
        playFastSnare(); delay(sixteenth - 30);
    }
    getch();
}

# Blackjack

Gra Blackjack (kasynowa odmiana gry w oczko) napisana w języku C++ przy wykorzystaniu bibliotek SFML.

Gra posiada graficzny interfejs, efekty dżwiękowe (wysuwania, odwracania kart itp.) oraz klimatyczny podkład muzyczny.

Klawiszologia:
- H - Hit (dobranie karty)
- S - Stand (zakończenie dobierania kart i przekazanie tury krupierowi)
- Spacja - Restart gry
- Escape - Wyjście z gry
- K - Zmiana koloru rewersu kart

W grze występują dwa "Easter Eggi" ukryte pod dwoma skrótami klawiszowymi:
- E - Wyświetla saldo gracza po wszystkich dotychczasowych rozgrywkach (przenosi się między uruchomieniami gry)
- C - Zastępuje kartę Króla kartą ze znanym programistą gier komputerowych

Punktacja kart w blackjacku:
- Karty od dwójki do dziesiątki mają wartość równą numerowi karty.
- Walet, Dama i Król mają wartość równą 10 punktów.
- As ma wartość równą 1 lub 11, w zależności co jest lepsze dla dobierającego.

Opis gry:

Blackjack jest kasynową wersją gry w oczko. Zadaniem gracza jest uzyskać jak najbliżej (ale nie więcej niż) 21 punktów. Jeżeli gracz uzyskał więcej punktów niż krupier, jednoczesnie nie przekraczając 21 punktów lub krupier przekroczył 21 punktów, gracz wygyrwa zakład. Najwyższym układem kart jest tzw. Blackjack, czyli As i 10 lub figura, za który gracz dostaje 150% zakładu.

W grze używa się jednej talii złożonej z 52 kart.

-----------------------------------------------------------------------------------------------

Blackjack written in C++ using SFML libraries.

Game includes graphical interface, sound effects and music.

Key mapping:
- H - Hit
- S - Stand
- Space - Restart
- Escape - Exit the game
- K - Change color of card back

There are two "Easter Eggs" hidden in the game under two key shortcuts:
- E - Shows player's account balance based on all previous rounds (including other sessions)

Points in blackjack:
- Cards from 2 to 10 have the same value as the number on the card.
- Jack, Queen and King have the value of 10.
- Ace value depends on what suits the player best, 1 or 11.

Game description:

Player's objective in Blackjack is to get as many points as possible but not more than 21. If the player has more points then dealer and not more than 21 or dealer has more than 21 points, player wins the bet. If the player gets Ace and 10 (or Jack, Queen, King), he got "Blackjack" and gets 150% winning bet.

The game uses one card deck consisting of 52 cards.

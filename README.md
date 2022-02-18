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

Blackjack jest kasynową wersją gry w oczko. Zadaniem gracza jest uzyskać jak najbliżej (ale nie więcej niż) 21 punktów. Najwyższym układem kart jest tzw. Blackjack, czyli As i 10 lub figura, za który gracz dostaje 150% zakładu .

W grze używa się jednej talii złożonej z 52 kart.

W Blackjacka gra się przeciwko krupierowi. Gracz stawia zakład na stole używając żetonów. Następnie gracz i krupier dostają po dwie karty. Obydwie karty gracza są odkryte, natomiast tylko jedna karta krupiera jest pokazana graczowi. Gracz teraz może podjąć decyzje o swoim następnym ruchu i zadecydować czy dobiera karty dalej czy też kończy swoją turę.

Jeżeli gracz po dobraniu kart ma więcej niż 21 punktów, przegrywa zakład i krupier zabiera jego żetony. Jeżeli natomiast gracz ma 21 punktów lub mniej, krupier odkrywa swoją zakrytą kartę i w zależności od liczby jego punktów może dobrać więcej kart. Krupier musi grać według następujących przepisów: wziąć kartę, jeżeli ma 16 punktów lub mniej i nie brać więcej kart, gdy ma 17 punktów lub więcej (niezależnie, ile punktów ma gracz). Wygrywa ten, który ma sumę punktów bliższą lub równą 21. W przypadku remisu punktowego, postawiona stawka wraca do gracza.

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

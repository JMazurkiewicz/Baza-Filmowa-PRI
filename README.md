# Movie-DB #

## Compilation with CMake ##

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Project requirements (in Polish) ##

### PRI 3 ###

Napisz bazę danych przechowująca bazę filmów, aktorów i studiów nagraniowych. Baza powinna umożliwiać:

* dodawanie i usuwanie filmów, aktorów i studiów nagraniowych
* sortowanie filmów, aktorów i studiów nagraniowych wg różnych kryteriów
* wypis danych o filmie: studio nagraniowe realizujące film, lista aktorów
* wypis danych o studiu nagraniowym: nazwa, adres siedziby, kontakt, lista wyprodukowanych filmów, lista aktorów z którymi dane studio nagraniowe współpracuje wg filmu
* wypis danych o aktorze: imie i nazwisko, lista filmów w których uczestniczył aktor
* aktorzy mogą występować w kilku filmach
* film może mieć kilka aktorów i jedno studio nagraniowe
* jedno studio nagraniowe realizuje kilka filmów

Należy wykorzystać dynamiczną alokacje pamięci (zadbać o jej odpowiednie zwalnianie i brak wycieków pamięci). Wykorzystane struktury (lista, drzewo) jak i sortowanie należy zaimplementować samodzielnie. Program powinien być zabezpieczony przed próbami wpisania nieprawidłowych danych wejściowych. Proszę również zadbać o przyjazny użytkownikowi interfejs - losowy Kowalski powinien umieć obsłużyć ten program i mieć dostęp do instrukcji. Kod ma być czytelny i podzielony na pliki `.h` i `.c`. Należy zadbać o odpowiedni podział kodu na funkcje.

### PRI 4 ###

Wymagania:

* zapis bazy do plików
* odczyt bazy z ostatnio utworzonych plików (przywrócenie z kopii zapasowej w przypadku wyłączenia programu) - należy dać użytkownikowi wybór między najnowszym i nieco starszym zapisem na podstawie timestamp
* przy odczycie bazy z plików wyświetlenie daty ostatniej modyfikacji pliku zapasowego
* usuwanie plików zapasowych

Powinno się również zadbać o obsługę błędów plików, sytuacji kiedy plik bedzie uszkodzony i zapis bedzie niekompletny (sprawdzanie poprawności zapisu i odczytu).

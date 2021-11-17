# studentu-sarasas

V0.1 RELEASE

Buvo sukurta klasė Student su tokiais duomenimis:

* Studento vardas, pavardė;
* Namų darbų ir egzamino rezultatai;
* Galutinis pažymys;

Klasės metodai:

* Konstruktorius;
* Priskyrimo-kopijavimo operatorius;
* Kopijavimo konstruktorius;
* Destruktorius;
* Išvesties metodas;
* Įvesties metodas;
* Galutinio pažymio skaičiavimo metodas(pagal medianą arba vidurkį);

Paleidus programą, ji paprašo vartotojo pasirinkti, ar norėtų skaityti duomenis iš failo, ar įvesti pačiam.(1-skaityti iš failo duomenis, 2- įvesti pačiam). Jei vartotojas pasirenka 1- programa nuskaito iš failo studentų duomenis, suskaičiuoja vidurkį ir išveda duomenis lentelės pavidalu. Jei vartotojas įrašo skaičių 2-tuomet programa rašo, kiek studentų vartotojas norėtų sukurti? Tarkime, 2. Tuomet programa paprašo įvesti studento vardą, pavardę. Toliau programa leidžia rinktis ar pažymių vidurkį norėtų skaičiuoti su vidurkiu ar su mediana. Jei pasirenka 1-skaičiuoja pagal vidurkį.Jei 2-pagal medianą. Kai pasirenki medianą arba vidurkį ,programa klausia, ar nori pažymius įrašyti pats, ar atsitiktinai sugeneruoti pačiai programai. Jei pasirenk 1-programa pati sugeneruoja už tave, tik dar prieš tai paklausia kiek pažymių nori sugeneruoti. Ir tada išveda rezultatą. Jei pasirenki įrašyti pažymius pačiam, tada programa prašo įvesti pažymius tol, kol įrašysi -1. Paskui įvedi testo rezultatą ir galiausiai prograa išsspaudina surūšiuotus pagal pavardes studentus.

Failai programoje yra išskaidyti į antarštinį failą, kuriame aprašyta yra klasė, funkcijos.

Taip pat panaudotos išimčių valdymas(pvz. tikrinant ar failas, iš kurio norime duomenis nuskaityti išvis egzistuoja)

V0.2 RELEASE

Programa sugeneravo 5 studentų sąrašų failus, juos užpildė  1000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų su studento vardu, pavarde ir galutiniu pažymiu. Vėliau duomenis nuskaitė pagal galutinį pažymį padalino į dvi grupes ir įrašė į du failus(Kieti.txt ir Minksti.txt). Galutinis < 5 -Minkštus ir galutinis > 5 -kietus.
Tuomet buvo atlikta spartos analizė pagal prieš tai išvardintus žingsnius.
Analizės rezultatai: 

* Failu sukurimas  uztruko : 120102954 microseconds

* Duomenu nuskaitymas i faila uztruko : 118630916 microseconds

* Studentu surusiavimas ir isvedimas i faila uztruko : 287886323 microseconds

ISVADOS: 

Daugiausiai uztruko studentu surusiavimas ir isvedimas i faila. Maziausiai uztruko duomenu nuskaitymas i faila.

Toliau buvo atliktas konteinerių testavimas. deque, vector, list.

Analizes rezultatai:

LIST:

* Failu nuskaitymas naudojant list uztruko: 114328490 microseconds.
* Studentu surusiavimas ir isvedimas uztruko : 270841857 microseconds

DEQUE:

* Failu nuskaitymas  uztruko : 130250733 microseconds
* Studentu surusiavimas ir isvedimas uztruko : 281718212 microseconds

VECTOR:

* Duomenu nuskaitymas i faila uztruko : 118630916 microseconds
* Studentu surusiavimas ir isvedimas i faila uztruko : 287886323 microseconds

Pagal mano analize, list'as veikia greiciausiai su dideliais duomenu kiekiais.

   
NAUDOJIMOSI INSTRUKCIJA

Norint pasinaudoti programa, reiktų atsisiųsti į kompą norimos versijos releas'ą, išsiarchyvuoti ir susikurti naują projektą. Kadangi failus nežinau kodėl iš pat pradžių kėliau rankiniu būdu ir po vieną, o ne visą projektą, tai todėl programos paleidimas bus šiek tiek sunkesnis. Kai susikūrėte naują projektą, reiktų prie header files įkelti student.h failą bei Student.txt failą. O prie Source files ištrinti naujo projekto main failą ir įkelti Student.cpp bei students data.cpp. Ir paleidus, turėtų veikti.

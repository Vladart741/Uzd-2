#1.0v patobulinta

Patobulinus 1.0v gaunami stai tokie rezultatai:

| Pirma Strategija be alg |      10      |     100      |    1000    |   10000    |  100000  |
|-------------------------| ------------ | ------------ | ---------- |----------- |----------|
|         Vector          | 0.000159209s | 0.00215506 s | 0.017743 s | 0.183133 s | 1.79775 s|
|          List           | 0.000114568s | 0.000986863 s|0.00660029 s| 0.0809856 s|0.742438 s|
|         Deque           | 0.00013116s  | 0.000722567 s|0.00697323 s| 0.0724377 s| 0.72009 s|

| Pirma Strategija su alg |      10      |     100      |    1000    |   10000    |  100000  |
|-------------------------| ------------ | ------------ | ---------- |----------- |----------|
|         Vector          | 0.000166716 s| 0.0014641 s  | 0.015868 s | 0.14747 s  | 1.41291 s|
|          List           | 0.000121284 s| 0.000788937 s|0.00680059 s| 0.0763334 s|0.707516 s|
|         Deque           | 0.000101136 s| 0.000470123 s|0.00360415 s| 0.0414609 s|0.374867 s|

---------------------------------------------------------------------------------------------

| Antra Strategija be alg |      10      |     100      |    1000    |   10000    |  100000  |
|-------------------------| ------------ | ------------ | ---------- |----------- |----------|
|         Vector          | 0.000157629 s|  0.00532701 s| 0.413043 s |     n      |     n    |
|          List           | 4.1481e-05 s | 0.000468543 s|0.00455466 s|     n      |     n    |
|         Deque           | 7.2296e-05 s | 0.000719407 s|0.0150977 s |     n      |     n    |

| Antra Strategija su alg |      10      |     100      |    1000    |   10000    |  100000  |
|-------------------------| ------------ | ------------ | ---------- |----------- |----------|
|         Vector          | 6.084e-05 s  | 0.00058311 s |0.00638222 s| 0.0739444 s|0.869877 s|
|          List           | 4.2271e-05 s | 0.000363851 s|0.00296415 s| 0.0431115 s|0.344498 s|
|         Deque           | 7.5062e-05 s | 0.000495012 s|0.0046795 s | 0.0484725 s|0.38851 s |

# Vertinimo pastabos

1. Be algoritmų panaudojimo (v0.5) vector turėjo veikti gerokai lėčiau, negu su algoritmais.
2. Kažkodėl List veikia lėčiausiai, nors turėtų būti atvirsčiai. Čia matyt todėl, kad abi strategijos realizuotos tik su algoritmais.
3. Programa "užlūšta" jeigu įvedamas ne skaičius iš [1,5] intervalo.(Pataisyta)
4. Header GUARD faile 'Struktura.h' yra neteisingas.(Pataisyta)
5. Truksta v0.5 releaso.(Pataisyta)



# 0.4v
0,4v pakeisti keli headeriai, pridėtas failų generatorius pagal vartotojo poreikius (galima nustatyti norima failo dydį, t.y. 10, 100, 1000 ir t.t. random studentų). Įvykdyti matavimai parodė, kad generuojant ir apdorojant duomenis programa atliko tai per:

|            |      10      |     100      |    1000    |   10000   |  100000  |
|------------| ------------ | ------------ | ---------- |-----------|----------|
| Vector     | 0,0150969 s  | 0,0150969 s  | 0,439631 s | 3,71195 s | 37,2324 s|

# 0.5v
Išmatuota programos veikimo sparta naudojant visus konteinerius (vector, list, deque). Gautus rezultatus galite matyti žemiau pateiktoje lentelėje.

|            |      10      |     100      |    1000    |   10000   |  100000  |
|------------| ------------ | ------------ | ---------- |-----------|----------|
| Vector     | 0,00363615 s | 0,02630068 s | 0,245246 s | 2,49357 s | 26,8591 s|
| List       | 0,00580464 s | 0,0346837 s  | 0,274511 s | 2,80558 s |  29,65 s |
| Deque      | 0,00459575 s | 0,0382132 s  | 0,333447 s | 3,58463 s | 36,1639 s|

Pagal gautus duomenis matome, kad greičiausiai duonenis apdoroja vector tipo konteineris nepriklausomai nuo duomenu apimties.

# 1.0v
Gauti rezultatai naudojant pirma strategija:

|            |      10      |     100      |    1000    |   10000   |  100000  |
|------------| ------------ | ------------ | ---------- |-----------|----------|
| Vector     | 0.0064869 s  | 0.0365281 s  | 0.288937 s | 3.20637 s | 31.3955 s|
| List       | 0.00911129 s | 0.0487083 s  | 0.361323 s | 3.6171 s  | 33.9164 s|
| Deque      | 0.00552414 s | 0.0490911 s  | 0.479989 s | 4.48342 s | 42.9406 s|

# 1.0v pirmos strategijos patobulinimas ir antros integravimas į programą
Buvo patobulinta pirma strategija, dabar gauti rezultatai atrodo štai taip:

|            |      10      |     100      |    1000    |   10000   |  100000  |
|------------| ------------ | ------------ | ---------- |-----------|----------|
| Vector     | 0.00480197 s | 0.0266891 s  | 0.222386 s | 2.21173 s | 21.6464 s|
| List       | 0.00496078 s | 0.0322164 s  | 0.281032 s | 3.02114 s | 28.2685 s|
| Deque      | 0.00564305 s | 0.0439454 s  | 0.294255 s | 2.74744 s | 26.9514 s|

Taip pat patobulinime pradėta naudoti algoritmus, tokius kaip std::copy_if, std::remove_if

Buvo pridėta ir antra strategija. Jos rezultatus galite matyti lentelėje žemiau.

|            |      10      |     100      |    1000    |   10000    |  100000  |
|------------| ------------ | ------------ | ---------- |----------- |----------|
| Vector     | 0.00822715 s | 0.0351304 s  | 0.229233 s | 2.2712 s   | 22.2557 s|
| List       | 0.00793362 s | 0.0405649 s  | 0.353475 s | 3.43421 s  | 32.8801 s|
| Deque      | 0.00562764 s | 0.0373258 s  | 0.323843 s | 3.26589 s  | 33.6631 s|

P.S. Strategija 2 veikia ne iki galo tiksliai, nes spausdinant rezultatus puse failo spausdinama gerai, kita pusė kažkaip "pasislenka". Buvo bandyta naudoti algoritmą std::remove_copy_if, bet kažkaip prastai pavyko šį algoritmą "priversti" veikti :) .

# NAUDOJIMOSI INSTRUKCIJA

Paleidus programą, ji leidžia vartotojui pasirinkti vieną iš pateiktų punktų:
1. Galimybę sugeneruoti naują failą su vartotojo nustatytu dydžiu bei pavadinimu.
2. Galimybę nuskaityti egzistuojanti failą ir atspausdinti suskaičiuotus rezultatus į duomenų failą "Rezultatai.txt"
3. Apjungia dvi prieš tai buvusias funkcijas į vieną. T.y. generuoja, nuskaito, atspausdina.
4. Galimybę nuskaityti ir apdoroti failą pagal pirmą strategiją.
	4.1. Leidžia nuskaityti esamą failą.
	4.5. Nuskaito 5 failus (10,100,1000,10000,100000 studentų sk.) ir atspausdina į rezultatų failą kiek programa užtruko laiko apdorojant kiekvieną failą.
5. Galimybę nuskaityti ir apdoroti failą pagal antrą strategiją.
	5.1. Leidžia nuskaityti esamą failą.
	5.5. Nuskaito 5 failus (10,100,1000,10000,100000 studentų sk.) ir atspausdina į rezultatų failą kiek programa užtruko laiko apdorojant kiekvieną failą.
Punktai 3, 4 ir penktas atliekami su visais konteineriais (vector,list ir deque).

Norėdami aktyvuoti kažkurį iš šių funkcijų, reikia įvesti atitinkamą skaičių, kuris yra pateiktas prie komandos (Pvz.:(1) jei norite sugeneruoti nauja faila. (Reikės įvesti 1)) ir nuspausti ENTER.
Įvedę netinkamą numerį, programa paprašys įvesti tinkamą.
Jei prašoma įvesti EGZISTUOJANČIO failo pavadinimą, BŪTINA rašyti pavadinimą su galūne .txt (Pvz.: "Duomenys.txt", o ne "Duomenys"). Priešingu atveju bus išmesta klaida "Failas nerastas" ir būsite gražinti į pagrindinį meniu.

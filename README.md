# 0.5v
Išmatuota programos veikimo sparta naudojant visus konteinerius (vector, list, deque). Gautus rezultatus galite matyti žemiau pateiktoje lentelėje.

|            |      10      |     100      |    1000    |   10000   |  100000  |
|------------| ------------ | ------------ | ---------- |-----------|----------|
| Vector     | 0,00363615 s | 0,02630068 s | 0,245246 s | 2,49357 s | 26,8591 s|
| List       | 0,00580464 s | 0,0346837 s  | 0,274511 s | 2,80558 s |  29,65 s |
| Deque      | 0,00459575 s | 0,0382132 s  | 0,333447 s | 3,58463 s | 36,1639 s|

Pagal gautus duomenis matome, kad greičiausiai duonenis apdoroja vector tipo konteineris nepriklausomai nuo duomenu apimties.

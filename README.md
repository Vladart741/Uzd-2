# 1.0v
Gauti rezultatai naudojant pirma strategija:

|            |      10      |     100      |    1000    |   10000   |  100000  |
|------------| ------------ | ------------ | ---------- |-----------|----------|
| Vector     | 0.0064869 s  | 0.0365281 s  | 0.288937 s | 3.20637 s | 31.3955 s|
| List       | 0.00911129 s | 0.0487083 s  | 0.361323 s | 3.6171 s  | 33.9164 s|
| Deque      | 0.00552414 s | 0.0490911 s  | 0.479989 s | 4.48342 s | 42.9406 s|

# 0.5v
Išmatuota programos veikimo sparta naudojant visus konteinerius (vector, list, deque). Gautus rezultatus galite matyti žemiau pateiktoje lentelėje.

|            |      10      |     100      |    1000    |   10000   |  100000  |
|------------| ------------ | ------------ | ---------- |-----------|----------|
| Vector     | 0,00363615 s | 0,02630068 s | 0,245246 s | 2,49357 s | 26,8591 s|
| List       | 0,00580464 s | 0,0346837 s  | 0,274511 s | 2,80558 s |  29,65 s |
| Deque      | 0,00459575 s | 0,0382132 s  | 0,333447 s | 3,58463 s | 36,1639 s|

Pagal gautus duomenis matome, kad greičiausiai duonenis apdoroja vector tipo konteineris nepriklausomai nuo duomenu apimties.

# 0.4v
0,4v pakeisti keli headeriai, pridėtas failų generatorius pagal vartotojo poreikius (galima nustatyti norima failo dydį, t.y. 10, 100, 1000 ir t.t. random studentų). Įvykdyti matavimai parodė, kad generuojant ir apdorojant duomenis programa atliko tai per:

|            |      10      |     100      |    1000    |   10000   |  100000  |
|------------| ------------ | ------------ | ---------- |-----------|----------|
| Vector     | 0,0150969 s  | 0,0150969 s  | 0,439631 s | 3,71195 s | 37,2324 s|

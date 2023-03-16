## 1. Poznámka

Tato šifra je inspirována šifrou RC4 vytvořena kryptografem  
Ronaldem Rivestem. Její účel není aby byla kryptograficky bezpečná,  
ale aby poukázala na možný vývoj základních šifer a v tomto případě  
především šifry proudové, více v části **Odkazy**.  

## 2. Použití

SC.exe [args]

args:

	d - decrypt

## 3. Popis

### 3.1 Šifrování

Je tu několik proměnných na které je třeba dávat pozor,  
těmi jsou proměnné **k[]**, **ks[]**, **t** a **p**.  

**k[]** je datového typu *unsigned char* s velikostí 256 do níž se  
vloží hodnoty rundovního klíče (viz 2.1-1).  
**ks[]** má rozdílnou velikost a to je 8000. Slouží k uchování hodnot  
vygenerovaných 2.1-2. **t** a **p** jsou typu *string*. V nich je  
uložen text k šifrování a heslo.  

Uživatel je dotázán o zadání textu, který chce zašifrovat a klíče,  
který chce použít.  
Hodnoty jsou uloženy do řetězců **t**(plain***t***ext) a  
**p**(***p***assphrase).  

#### 3.1-1 Příprava rundovního klíče - KSA

Pole "k[]" se naplní veškerými možnými hodnotami datového typu  
*unsigned char*, těmi jsou čísla 0-255.  
Na to je využit cyklus *for*.  

Vytvořená proměnná **j** je inicializována hodnotou 0.  

Je vytvořen další cyklus *for*, který se zopakuje přesně 256x.  
V cyklu se nastaví hodnota proměnné **j** na součet proměnné **j** a  
číselné hodnotě znaku z řetězce **p** na indexu hodnoty  
aktuální iterace(*i*) modulo délka proměnné **p**.  
Prohodí se hodnoty proměnné **k[]** na indexu *i* s  
proměnnou **k[]** na indexu proměnné **j** za použití  
funkce ***swap()***. Hodnota proměnné **k[]** na indexu *i* se nastaví na  
hodnotu výstupu funkce ***lfsr()***, prvním argument této funkce je  
proměnná **j**, druhým argumentem je řetězec **p** na indexu hodnoty  
*i* modulo délka proměnné **p**.  

#### 3.1-2 Pseudo-náhodný generovací algoritmus - PRGA

Je vytvořena proměnná **i** s datovým typem *int* je  
inicializována hodnotou 0.  

Uvnitř nekonečného cyklu je podmínka jestli je hodnota řetězce **t** na  
indexu **i** rovna hodnotě *null*, pokud je splněna, program vystoupí z  
cyklu. Proměnná **j** se nataví na součet proměnné **j** a hodnoty  
pole **k[]** na indexu **i** modulo 256. Prohodí se hodnoty pole  
**k[]** na indexu **i** s hodnotou pole **k[]** na indexu proměnné **j** za  
použití funkce ***swap()***. Do pole **ks[]** na indexu **i** se nastaví  
hodnota pole **k[]** na indexu součtu hodnot polí **k[]** na indexu **i** a  
**k[]** na indexu **j** modulo 256. V cyklu se nakonec **i**  
zvětší o 1. Cyklus se opakuje do doby dokud se nesplní podmínka (viz řádek 50 popisu šifry)  

#### 3.1-3 Výpis zašifrovaného textu uživateli

Je vytvořen cyklus *for*. Počet cyklů je určen délkou řetězce **t**.
Je vyvolána funkce ***ttc()*** kde první parametr je řetězec **t** na indexu *i* a druhý je pole **ks[]**.

### 3.2 Dešifrování

... // ukladani hesla a hex ciphertextu popis

#### 3.2-1 Příprava rundovního klíče - KSA

Stejné jako 3.1-1

#### 3.2-2 Pseudo-náhodný generovací algoritmus - PRGA

Stejné jako 3.1-2

#### 3.1-3 Výpis zašifrovaného textu uživateli

Je vytvořen cyklus *for*. Počet cyklů je určen délkou řetězce **c**.
Je vyvolána funkce ***ctt()*** kde první parametr je řetězec **c** na indexu *i*, druhý je řetězec **c** na indexu **i**+1 a třetí je pole **kc[]** na indexu **i**/2.

## 4. Funkce

### 4.1 lfsr - Linear Feedback Shift Register

LFSR slouží k vytvoření pseudonáhodného čísla a v kódu je použit za účelem snížení předvídatelnosti vygenerovaného rundovního klíče.

#### 4.1-1 Princip LFSR

Vyberou se místa v jednom/více bitů/bajtů v našem připadě jednoho bajtu (8 bitů), těmto místům se říká anglicky ***"taps"***. Na tyto ***"taps"*** následně použijeme binární operátor XOR (v kódu ***^***) a výstup připojíme na začátek (8. bit zprava) ale před připojením posuneme celý bit doprava o 1 pozici nebo opačně, posuneme bit o 1 pozici doleva a výstup připojíme doleva (1. bit zprava).

Příklad:

Taps: 8, 6, 5, 3
\______
/| || |
 11000101 - Vstup
01100010  - 1. iterace
10110001  - 2. iterace
...
11000101  - x. iterace

Po určitém počtu iterací se výstupní hodnota vrátí do původního stavu.
Podrobnější informace v části **Odkazy**.

#### 4.1-2 Popis kódu

...

### 4.2 ttc - Text To Ciphertext

...

### 4.3 ctt - Ciphertext To Text


...

## Odkazy

https://cs.wikipedia.org/wiki/Proudov%C3%A1_%C5%A1ifra
https://cs.wikipedia.org/wiki/RC4
https://en.wikipedia.org/wiki/Linear-feedback_shift_register
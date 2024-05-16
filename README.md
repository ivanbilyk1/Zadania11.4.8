# Zadania11.4.8
Tento kód implementuje vytváranie, manipuláciu a mazanie spájaného zoznamu. V prepojenom zozname má každý prvok (uzol) hodnotu a odkaz na ďalší uzol v zozname.

Funkcionalita
Vytvorenie prázdneho zoznamu: Funkcia lowl_create_empty vytvorí nový prázdny zoznam a vráti naň ukazovateľ.

Vytvorenie zoznamu s náhodnými hodnotami: Funkcia lowl_create_random vytvorí nový zoznam danej veľkosti s náhodnými hodnotami a vráti naň ukazovateľ.

Lineárna interpolácia: Funkcia lowl_interpolate_linear vykoná lineárnu interpoláciu medzi každou dvojicou susedných položiek zoznamu. Výsledkom je aktualizovaný zoznam s novými položkami, ktoré sú aritmetickým priemerom susedných hodnôt.

Vloženie položky na koniec zoznamu: Funkcia lowl_insert_right vloží na koniec zoznamu novú položku so zadanou hodnotou.

Vytlačenie zoznamu: Funkcia lowl_print vypíše hodnoty všetkých položiek zoznamu na obrazovku.

Uvoľnenie pamäte: Funkcia lowl_destroi uvoľní pamäť, ktorá bola alokovaná pre zoznam a všetky jeho položky.

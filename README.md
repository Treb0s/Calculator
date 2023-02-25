# Tachenrechner mit Grafischer Oberfläche

## Das Grundprinzip der Eingabe
Bei der Eingabe wird mithilfe des/der vorher gedrückten Knöpfe festgelegt, welche Eingaben als nächstes überhaupt angenommen und angezeigt werden (Bugs sind noch vorhanden). Die Rechnung zur anzeige ist in einem QString (Datentyp vom QT-Framework) gespeichert, während die Eigentliche Rechnung in einem Normalen String gespeichert wird. Dieser String wird dann an die Rechenfunktion weitergegeben, die als Ergebnis auch wieder einen String zurückgibt.

## Wie der Rechenalgorithmus funktioniert
Zunächst werden die '-' Vorzeichen gesondert behandelt, da sie ja keine Rechenoperatoren sondern teil der Zahl sind. Danach wird dann nach der Innersten Klammer gesucht und der Ausdruck dann ausgerechnet. Das passiert, bis keine Klammern mehr vorhanden sind. Wenn keine Klammern mehr vorhanden sind, wird der ganze Rest ausgerechnet.

## Tiefergreifende Erklärung der inneren Vorgänge
Die Ausdrücke, die berechnet werden sollen, werden an eine Funktion weitergegeben, die den String nach Zahlen und Operatoren getrennt in einen 'double' Vektor schiebt.
Eine Andere Funktion berechnet dann die Ergebnisse nach der festgelegten Rechenreihenfolge und ersetzt im Vektor den Ausdruck durch das Ergebnis. Besteht der Vektor nur noch aus einem Element, wird der Rechenausdruck im String mit der Kompletten Aufgabe durch das Zwischenergebnis ersetzt.
Das passiert auch wieder so lange, bis nur noch eine Zahl übrig ist, die dann zurückgegeben wird und als Endergebnis angezeigt wird.

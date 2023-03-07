# Tach calculator with graphical user interface

## The basic principle of input
During input, the button(s) pressed beforehand are used to determine which inputs are accepted and displayed next in the first place. The calculation for display is stored in a QString (data type from the QT framework), while the actual calculation is stored in a normal string. This string is then passed on to the calculation function, which also returns a string as the result.

## How the calculation algorithm works
First, the '-' signs signs are treated separately, as they are not arithmetic operators but part of the number. Then the innermost bracket is searched for and the expression is calculated. This happens until there are no more brackets. If there are no more brackets, the whole remainder is calculated.

## Deeper explanation of the inner processes
The expressions to be calculated are passed to a function, which pushes the string into a 'double' vector separated by numbers and operators.
Another function then calculates the results according to the defined calculation sequence and replaces the expression with the result in the vector. If the vector consists of only one element, the calculation expression in the string with the complete task is replaced by the intermediate result.
This happens again until only one number is left, which is then returned and displayed as the final result.

Translated with www.DeepL.com/Translator (free version)

# Tachenrechner mit Grafischer Oberfläche

## Das Grundprinzip der Eingabe
Bei der Eingabe wird mithilfe des/der vorher gedrückten Knopfes/Knöpfe festgelegt, welche Eingaben als nächstes überhaupt angenommen und angezeigt werden. Die Rechnung zur Anzeige ist in einem QString (Datentyp vom QT-Framework) gespeichert, während die eigentliche Rechnung in einem normalen String gespeichert wird. Dieser String wird dann an die Rechenfunktion weitergegeben, die als Ergebnis auch wieder einen String zurückgibt.

## Wie der Rechenalgorithmus funktioniert
Zunächst werden die '-' Vorzeichen gesondert behandelt, da sie ja keine Rechenoperatoren, sondern Teil der Zahl sind. Danach wird dann nach der innersten Klammer gesucht und der Ausdruck ausgerechnet. Das passiert, bis keine Klammern mehr vorhanden sind. Wenn keine Klammern mehr vorhanden sind, wird der ganze Rest ausgerechnet.

## Tiefergreifende Erklärung der inneren Vorgänge
Die Ausdrücke, die berechnet werden sollen, werden an eine Funktion weitergegeben, die den String nach Zahlen und Operatoren getrennt in einen 'double' Vektor schiebt.
Eine Andere Funktion berechnet dann die Ergebnisse nach der festgelegten Rechenreihenfolge und ersetzt im Vektor den Ausdruck durch das Ergebnis. Besteht der Vektor nur noch aus einem Element, wird der Rechenausdruck im String mit der Kompletten Aufgabe durch das Zwischenergebnis ersetzt.
Das passiert auch wieder so lange, bis nur noch eine Zahl übrig ist, die dann zurückgegeben wird und als Endergebnis angezeigt wird.

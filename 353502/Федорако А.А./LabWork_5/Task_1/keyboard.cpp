#include "keyboard.h"

Keyboard::Keyboard()
{

}

QVector<QString> Keyboard::getEnglishKeyboard(bool isShift, bool isCaps)
{
    if(isShift && isCaps)
        return  {"~", "!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+", "BACKSPACE","TAB", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "{", "}", "|", "CAPS LOCK", "a", "s", "d", "f", "g", "h", "j", "k", "l",  ":", "'", "ENTER", "SHIFT", "z", "x", "c", "v", "b", "n", "m", "<", ">", "?", "SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
    else if(isShift) {
        return  {"~", "!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+", "BACKSPACE","TAB", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{", "}", "|", "CAPS LOCK", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "'", "ENTER", "SHIFT", "Z", "X", "C", "V", "B", "N", "M", "<", ">", "?", "SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
    }
    else if(isCaps) {
        return  {"`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "BACKSPACE","TAB", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "\\", "CAPS LOCK", "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "\"", "ENTER", "SHIFT", "Z", "X", "C", "V", "B", "N", "M", ",", ".", "/", "SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
    }
    return  {"`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "BACKSPACE","TAB", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "\\", "CAPS LOCK", "a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "\"", "ENTER", "SHIFT", "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", "SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
}


QVector<QString> Keyboard::getFranchKeyboard(bool isShift, bool isCaps)
{
    if(isShift && isCaps)
        return  {"`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "°", "+", "BACKSPACE","TAB", "a", "z", "e", "r", "t", "y", "u", "i", "o", "p", "¨", "£", "*", "CAPS LOCK", "a", "s", "d", "f", "g", "h", "j", "k", "l",  ":", "'", "ENTER", "SHIFT", "z", "x", "c", "v", "b", "n", "?", ".", "/", "§", "rSHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
    else if(isShift) {
        return  {"`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "°", "+", "BACKSPACE","TAB", "A", "Z", "E", "R", "T","Y","U","I","O","P", "¨", "£", "*", "CAPS LOCK", "Q","S","D","F","G","H","J","K","L","M","Ù", "ENTER", "SHIFT","W","X","C","V","B","N", "?", ".", "/", "§", "SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
    }
    else if(isCaps) {
        return  {"²", "&&", "é", "\"", "'", "(", "-", "è", "_", "ç", "à", ")","=", "BACKSPACE", "TAB", "A", "Z", "E", "R", "T","Y","U","I","O","P", "^","$","*", "CAPS LOCK", "Q","S","D","F","G","H","J","K","L","M","Ù","ENTER", "SHIFT", "W","X","C","V","B","N",",",";",":","!","SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
    }
    return  {"²", "&&", "é", "\"", "'", "(", "-", "è", "_", "ç", "à", ")","=", "BACKSPACE","TAB", "a", "z", "e", "r", "t", "y", "u", "i", "o", "p", "^", "$", "*", "CAPS LOCK", "q", "s", "d", "f", "g", "h", "j", "k", "l", "m", "ù", "ENTER", "SHIFT", "w", "x", "c", "v", "b", "n", ",", ";", ":", "!", "SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
}


QVector<QString> Keyboard::getGermanKeyboard(bool isShift, bool isCaps)
{
    if(isShift && isCaps)
        return  {"°", "!", "\"", "§", "$", "%", "&", "/", "(", ")", "=", "?", "'", "BACKSPACE","TAB", "q", "w", "e", "r", "t", "z", "u", "i", "o", "p", "ü", "+", "#", "CAPS LOCK", "a", "s", "d", "f", "g", "h", "j", "k", "l", "ö", "ä", "ENTER", "SHIFT", "y", "x", "c", "v", "b", "n", "m", ";", ":", "_", "SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
    else if(isShift) {
        return  {"°", "!", "\"", "§", "$", "%", "&", "/", "(", ")", "=", "?", "'", "BACKSPACE","TAB", "Q", "W", "E", "R", "T","Z","U","I","O","P", "Ü","*","'", "CAPS LOCK", "A","S","D","F","G","H","J","K","L","Ö","Ä","ENTER", "SHIFT", "Y","X","C","V","B","N","M",";",":","_","SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
    }
    else if(isCaps) {
        return  {"^", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "ß","´", "BACKSPACE", "TAB", "Q", "W", "E", "R", "T","Z","U","I","O","P", "Ü","+","#", "CAPS LOCK", "A","S","D","F","G","H","J","K","L","Ö","Ä","ENTER", "SHIFT", "Y","X","C","V","B","N","M",",",".","-","SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
    }
    return  {"^", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "ß","´", "BACKSPACE", "TAB", "q", "w", "e", "r", "t", "z", "u", "i", "o", "p", "ü", "+", "#", "CAPS LOCK", "a", "s", "d", "f", "g", "h", "j", "k", "l", "ö", "ä", "ENTER", "SHIFT", "y", "x", "c", "v", "b", "n", "m", ",", ".", "-", "SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
}

QVector<QString> Keyboard::getRussianKeyboard(bool isShift, bool isCaps)
{
    if(isShift && isCaps)
        return  {"ё", "!", "\"", "№", ";", "%", ":", "?", "*", "(", ")", "_", "+", "BACKSPACE","TAB", "й", "ц", "у", "к", "е", "н", "г", "ш", "щ", "з", "х", "ъ", "/", "CAPS LOCK", "ф", "ы", "в", "а", "п", "р", "о", "л", "д", "ж", "э", "ENTER", "SHIFT", "я", "ч", "с", "м", "и", "т", "ь", "б", "ю", ",", "SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
    else if(isShift) {
        return  {"Ё", "!", "\"", "№", ";", "%", ":", "?", "*", "(", ")", "_", "+", "BACKSPACE","TAB",  "Й", "Ц", "У", "К", "Е", "Н", "Г", "Ш", "Щ", "З", "Х", "Ъ", "/", "CAPS LOCK", "Ф", "Ы", "В", "А", "П", "Р", "О", "Л", "Д", "Ж", "Э", "ENTER", "SHIFT", "Я", "Ч", "С", "М", "И", "Т", "Ь", "Б", "Ю", ",", "SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
    }
    else if(isCaps) {
        return  {"Ё", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "BACKSPACE","TAB", "Й", "Ц", "У", "К", "Е", "Н", "Г", "Ш", "Щ", "З", "Х", "Ъ", "\\", "CAPS LOCK", "Ф", "Ы", "В", "А", "П", "Р", "О", "Л", "Д", "Ж", "Э", "ENTER", "SHIFT", "Я", "Ч", "С", "М", "И", "Т", "Ь", "Б", "Ю", ".", "SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
    }
    return  {"ё", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "BACKSPACE","TAB", "й", "ц", "у", "к", "е", "н", "г", "ш", "щ", "з", "х", "ъ", "\\", "CAPS LOCK", "ф", "ы", "в", "а", "п", "р", "о", "л", "д", "ж", "э", "ENTER", "SHIFT", "я", "ч", "с", "м", "и", "т", "ь", "б", "ю", ".", "SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
}

QVector<QString> Keyboard::getHebrewKeyboard(bool isShift, bool isCaps)
{
    if(isShift && isCaps)
        return {"~","!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+","BACKSPACE","TAB", "/", "'", "ק", "ר", "א", "ט", "ו", "ן", "ם", "פ", "}","{","|", "CAPS LOCK", "ש", "ד", "ג", "כ", "ע", "י", "ח", "ל", "ך", "ף", "\"", "ENTER", "SHIFT", "ז", "ס", "ב", "ה", "נ", "מ", "צ", "ת", "ץ", "?",  "SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
    else if(isShift) {
        return {"~","!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+","BACKSPACE","TAB", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "}", "{", "|", "CAPS LOCK","A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"","ENTER",  "SHIFT", "Z", "X", "C", "V", "B", "N", "M", ">", "<", "?",  "SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
    }
    else if(isCaps) {
        return {";","1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "BACKSPACE","TAB", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "]", "[", "\\", "CAPS LOCK","A", "S", "D", "F", "G", "H", "J", "K", "L", ":", ",", "ENTER", "SHIFT", "Z", "X", "C", "V", "B", "N", "M", ">", "<", ".", "SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
    }
    return {";","1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "BACKSPACE","TAB", "/", "'", "ק", "ר", "א", "ט", "ו", "ן", "ם", "פ","]", "[", "\\","CAPS LOCK" ,"ש", "ד", "ג", "כ", "ע", "י", "ח", "ל", "ך", "ף", ",", "ENTER", "SHIFT", "ז", "ס", "ב", "ה", "נ", "מ", "צ", "ת", "ץ","-", "SHIFT", "CTRL", "FN", "⊞", "ALT", "SPACE", "ALT FN", "CTRL", "←", "↑","↓","→"};
}

﻿https://github.com/okovtun/PD_212_WIN.git
https://www.youtube.com/playlist?list=PLeqyOOqxeiIMqz9yEX2G4Jjeqy2NBTsZV

Qt:
https://drive.google.com/drive/folders/1nJUXS1MzBZzO6m9dcGMua-_poyvrlTMp?usp=sharing

TODO:
1. Должны работать все кнопки в плейере;		DONE
2. При выходе из плейера плейлист должен сохраняться, а при запуске плейера, загружаться;	DONE
3. В плейлисте должна подсвечиваться активная композиция;	DONE
4. При двойном щелчке по композиции в плейлисте должно начинаться ее воспроизведение;	DONE
5. Добавить возможность зацикливать плейлист, и включать режим перемешивания;			DONE
6. Добавить кнопку 'CLR', которая очищает плейлист;							DONE
7. Добавить кнопку 'DEL', которая удаляет выбранные композиции из плейлиста;	DONE
8. Запретить разворачивать окно плейера на весь экран;
9. Загрузить плейлист в формате *.CUE;
10. Добавить темы с использованием QML;
11. Добавить эквалайзер;

DONE:
При воспроизведении слайдер 'Progress' должен двигаться, при этом label 'Progress' 
должен отображать текущее время воспроизведения, а label 'Duration' - длительность композиции;

DONE:
1. При открытии окна 'Font', в выпадающем списке уже должен быть выьран текущий шрифт,	DONE
   а в счетчике 'размер шрифта' должен быть размет текущего шрифта;
2. При следующем запуске программы, шрифт и размер шрифта должны сохраняться;
	https://stackoverflow.com/questions/457671/c-sharp-how-do-i-save-runtime-font-settings
3. При следующем запуске программы, цвет текста и фона так же дожны сохраняться;
	https://stackoverflow.com/questions/22437558/load-and-save-color-value
4. Установить QtCreator!!!
	MVC - Model View Controller

DONE:
Добавить в часы кастомные шрифты;

DONE:
1. Добавить кнопку "Hide controls", при нажатии на которую элементы управления прячутся, и на экране отображается только время;	DONE
2. Добавить кнопку "Close", которая закрывает программу;			DONE
3. Часы должн всегда открываться в правом верхнем углу экрана;		DONE
4. Когда элементы управления скрываются, в системном трее должен ноявляться значек;	DONE
5. У значка в системнос трее должно быть контекстное меню:			DONE
	Show date;
	---------------
	Show controls;
	Hide control;
	---------------
	Close;

DONE:
Добавить темы "square_gree" и "round_green", переключение между темами должно происходить через контекстное меню.

DONE:
1. Сделать иконку для калькулятора;
2. Сделать иконки для кнопок;

DONE:
Организовать вычисления;

DONE:
В Solution 'WinAPI' добавить проект 'Calc', и в нем реализовать калькулятор, 
выполняющий простейшие операции над дробными числами: +, -, *, /;

DONE:
1. В проект 'ListBox' добавить кнопки 'Добавить' и 'Удалить'.
	- Кнопка 'Добавить' открывает диалоговое окно с текстовым полем, в которое можно вписать название пункта, 
	  при нажатии кнопки 'Отмена', диалоговое окно просто закрывается, а при нажатии кнопки 'OK', в ListBox
	  родительского окна доьавляется написанный элемент;
	- Кнопка 'Удалить', просто удаляет элемент из 'ListBox'. Можно спросить у пользователя, 
	  действительно ли он хочет удалить этот пункт.

2. Скачать еще две иконки в формате !!!!!*.ICO!!!!!, и загрузить их БЕЗ использования файла ресурсов;
   Загрузить анимированный указатель мыши:
	http://www.rw-designer.com/cursor-set/starcraft-original	DONE
   TOREAD: ExtractIcon(...);

3. Окно должно занимать ровно 3/4 экрана, и его размер при запуске должен адаптироваться под размер экрана;	DONE
	https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getsystemmetrics

4. В строке заголовка окна должен отображаться размер окна и его положение на экране.
   При изменении как размер а окна так и его положения, все данные должны отображаться 
   в заголовке окна в реальном времени.

DONE:
В Solution 'WinAPI' добавить проект 'ListBox', и с 'ListBox' 
произвести все те же действия, что и с 'ComboBox';

DONE:
1. В текстовом поле 'Login' должно отбражаться приглашение: "Введите имя пользователя".
   Как только это текстовое поле получает фокус, приглашение сбрасывается, и если пользователь ввел имя,
   то это имя там и сохраняется, но, если при утрате фокуса поле осталось пустым, 
   то в нем снова отображается приглашение "Введите имя пользователя".
   https://learn.microsoft.com/en-us/windows/win32/controls/edit-controls
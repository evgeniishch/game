
### Игра-стратегия в рамках курса "Технологии программирования" ФИВТ МФТИ

#### Персонажи
Все персонажи суть объекты базового класса Character. Когда игрок выбирает персонажа (вводит имя), 
происходит запрос к некторому хранилищу (в идеале БД, но пока это класс Data, имитирующий её функционал), из которого извлекается инфромация о персонаже, 
после чего создается объект класса Character со свойствами выбранного персонажа, который добавляется в коллекцию 
персонажей игрока. Такой подход выбран для того, чтобы в игру можно было добавлять сколь угодно много новых персонажей,
а также для того, чтобы максимально отделить логическую часть игры от наполнения (информации о персонажах, предметах, правилах их взаимодействия и тд).

Все персонажи доступны для всех игроков.

#### Множества персонажей
За один ход игрок может выставить на поле одного нового персонажа. Однако, в случае необходимости, он может сформировать отряд и выставить сразу нескольких.
В этом случае игрок помимо стоимости персонажей должен уплатить пошлину, зависящую от свойств персонажей, которых он хочет выставить (например, пошлина для отряда
из двух "слабых" персонажей будет совсем незначительной, а пошлина для отряда из мага, друида и дракона будет достаточно большой). 
Игрок также может сформировать отряд, но не выставлять его на поле. В таком случае все члены отряда будут в единицу времени получать опыт пропорционально способностям и колчиеству. Количество опыта, который персонажи в отряде могут получить таким способом, ограничено. 
Персонаж, которого игрок перевел в отряд, удаляется из обычной коллекции персонажей. 
Если игрок захочет, обратно, извлечь персонажа из отряда, этот персонаж теряет набранный в отряде опыт.


#### Игровой процесс
В игре могут участвовать сколь угодно много игроков. 
В начале игры каждому игроку предоставляется возможность выбрать игровых персонажей с соответсвующими им
базовыми наборами способностей на 1000 единиц золота. Игроки выбирают персонажей по очереди.

Когда игроки выбрали персонажей, начинается игра. Игроки делают ходы по очереди. На каждом ходу игрок может составить отряд, выставить персонажа/отряд на поле и/или совершить какое-либо действие с каким-либо своим персонажем. 


#### Об использовании паттернов
По моему мнению, логика игры должна быть отделена от ее "наполнения". Под наполнением я подразумеваю все конкретные игровые данные, т.е. имена персонажей, их характеристики, свойства... В рамках этого проекта я старался максимально разделить логику игры и ее начинку, чтобы обеспечить наилучшую масштабируемость в дальнейшем. Так, структурные паттерны, изученные на семинарах, прочтиворечат данной концепции. Как было сказано на одной из лекций: использование паттернов - это антипаттерн, если они используются, значит в проекте недостаточен уровень абстракции.  

#### Сборка
Для того, чтобы запустить программу, выполните следующие действия: 

1. Скачайте репозиторий 
2. Перейдите в загруженную папку командой *cd*  
3. Создайте папку build-dir и перейдите в неё
3. Используйте команду cmake /путь_к_скачанному_репозиторию
4. Используйте команду make
5. Запустите программу 

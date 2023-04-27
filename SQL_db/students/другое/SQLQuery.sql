--- ЗАДАНИЕ 1 ---
------------- Запрос а ----------------
SELECT Clients.name AS 'Имя клиента', Clients.surname AS 'Фамилия клиента', Clients.book, Workers.surname AS 'Фамилия работника', PhoneNumbers.phone 
FROM Clients 
 INNER JOIN Workers ON Clients.worker_id = Workers.id
 INNER JOIN PhoneNumbers ON Workers.id = PhoneNumbers.worker_id
WHERE Clients.id between 1 AND 6
      AND Workers.id between 1 AND 6
ORDER BY 
        1 ASC
		;
------------- Запрос б ----------------
SELECT Clients.name AS 'Имя клиента', Cnigi.release AS 'Дата публикации книги', Cnigi.price AS 'Цена книги' 
FROM Clients 
 INNER JOIN Cnigi ON Clients.book_id = Cnigi.id
WHERE Clients.name LIKE 'A%' OR Clients.name LIKE 'T%'
      AND Cnigi.release between '2000-01-01' and '2014-01-01' 
	  AND Clients.surname !='%va' 
ORDER BY 
        3 ASC
		;
------------- Запрос в ----------------
SELECT Clients.name AS 'Имя клиента', Clients.book AS 'Наименование книги', Cnigi.price AS 'Цена книги' 
FROM Clients 
 INNER JOIN Cnigi ON Clients.book_id = Cnigi.id
WHERE Clients.name LIKE 'A%' 
      AND Clients.name LIKE '%a'
	  OR Cnigi.price < 10000
ORDER BY 
        3 ASC
		;

--- ЗАДАНИЕ 2 ---
--- Выведем среднюю цену книгу, используя при этом преобразование переменной
SELECT 'Средняя цена книги = '+ CAST(AVG(price) AS CHAR(4)) + 'р.'
FROM Cnigi; 
-- Переформатируем дату
SELECT book AS 'Книга' , price AS 'Цена' ,
       CONVERT(varchar, release, 104) AS 'Дата публикации книги'
  FROM Cnigi
  ORDER BY release;
-- Посчитаем количество лет между выпуском первой книги и последней в библиотеке
SELECT DATEDIFF(yy, (SELECT MIN(release) 
 FROM Cnigi
 ), 
 (SELECT MAX(release) 
 FROM Cnigi
 )
 );
-- Посчитаем количество работников, чей id меньше 7
SELECT COUNT(name)
FROM Workers
WHERE id<7;
-- Посчитаем всех работников, чьё имя начинается на A
SELECT SUM(id)
FROM Workers
WHERE name LIKE 'A%';
-- Session 1
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;

SELECT CURRENT_TIMESTAMP;

-- Session 2
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;

SELECT CURRENT_TIMESTAMP;

-- Session 1
SHOW TRANSACTION ISOLATION LEVEL;

-- Session 2
SHOW TRANSACTION ISOLATION LEVEL;

-- Session 1
SELECT CURRENT_TIMESTAMP;

SELECT rating FROM pizzeria WHERE name = 'Pizza Hut';

-- Session 2
SELECT CURRENT_TIMESTAMP;

SELECT rating FROM pizzeria WHERE name = 'Pizza Hut';

-- Session 1

UPDATE pizzeria SET rating = 4.0 WHERE name = 'Pizza Hut';

-- Session 2

UPDATE pizzeria SET rating = 3.6 WHERE name = 'Pizza Hut';

-- Session 1
SELECT CURRENT_TIMESTAMP;

COMMIT;

-- Session 2
SELECT CURRENT_TIMESTAMP;

COMMIT;

-- Session 1
SELECT CURRENT_TIMESTAMP;

SELECT rating FROM pizzeria WHERE name = 'Pizza Hut';

-- Session 2
SELECT CURRENT_TIMESTAMP;

SELECT rating FROM pizzeria WHERE name = 'Pizza Hut';
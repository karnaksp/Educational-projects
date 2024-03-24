-- Session #1
SELECT CURRENT_TIMESTAMP;

BEGIN;

SELECT * FROM pizzeria WHERE name = 'Pizza Hut';

SELECT CURRENT_TIMESTAMP;

UPDATE pizzeria SET rating = 5 WHERE name = 'Pizza Hut';

SELECT * FROM pizzeria WHERE name = 'Pizza Hut';

SELECT CURRENT_TIMESTAMP;

-- Session #2
SELECT CURRENT_TIMESTAMP;

SELECT * FROM pizzeria WHERE name = 'Pizza Hut';

-- Session #1
SELECT CURRENT_TIMESTAMP;

COMMIT;

-- Session #2
SELECT CURRENT_TIMESTAMP;

SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
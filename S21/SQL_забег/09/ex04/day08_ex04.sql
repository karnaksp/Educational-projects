-- Session 1
SELECT CURRENT_TIMESTAMP;

BEGIN TRANSACTION ISOLATION LEVEL SERIALIZABLE;

-- Session 2
SELECT CURRENT_TIMESTAMP;

BEGIN TRANSACTION ISOLATION LEVEL SERIALIZABLE;

-- Session 1
SHOW TRANSACTION ISOLATION LEVEL;

-- Session 2
SHOW TRANSACTION ISOLATION LEVEL;

-- Session 1
SELECT CURRENT_TIMESTAMP;

SELECT rating FROM pizzeria WHERE name = 'Pizza Hut';

-- Session 2
SELECT CURRENT_TIMESTAMP;

UPDATE pizzeria SET rating = 3.0 WHERE name = 'Pizza Hut';

COMMIT;

-- Session 1
SELECT CURRENT_TIMESTAMP;

SELECT rating FROM pizzeria WHERE name = 'Pizza Hut';

COMMIT;

SELECT rating FROM pizzeria WHERE name = 'Pizza Hut';

SELECT CURRENT_TIMESTAMP;

-- Session 2;
SELECT CURRENT_TIMESTAMP;

SELECT rating FROM pizzeria WHERE name = 'Pizza Hut';
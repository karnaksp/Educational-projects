SELECT NAME
FROM pizzeria
WHERE id NOT IN (
        SELECT
            DISTINCT pizzeria_id
        FROM person_visits
    );

SELECT NAME
FROM pizzeria p
WHERE NOT EXISTS (
        SELECT 1
        FROM person_visits pv
        WHERE
            pv.pizzeria_id = p.id
    );
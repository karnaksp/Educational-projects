SELECT pizzeria.name, rating
FROM pizzeria
WHERE id NOT IN (
        SELECT
            DISTINCT pizzeria_id
        FROM person_visits
    );
SELECT pizzeria.name
FROM menu
    FULL JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
    INNER JOIN (
        SELECT *
        FROM person_visits
        WHERE
            visit_date = '2022-01-08'
    ) AS person_or ON pizzeria.id = person_or.pizzeria_id
    INNER JOIN (
        SELECT *
        FROM person
        WHERE
            NAME = 'Dmitriy'
    ) AS pers ON pers.id = person_or.person_id
WHERE price < 800;
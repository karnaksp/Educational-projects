WITH andrey_visit AS (
        SELECT
            pz.name AS pizzeria_name
        FROM person AS p
            JOIN person_visits AS pv ON p.id = pv.person_id
            JOIN pizzeria AS pz ON pz.id = pv.pizzeria_id
        WHERE
            p.name = 'Andrey'
    ),
    andrey_order AS (
        SELECT
            pz.name AS pizzeria_name
        FROM person AS p
            JOIN person_order AS po ON p.id = po.person_id
            JOIN menu AS m ON po.menu_id = m.id
            JOIN pizzeria AS pz ON m.pizzeria_id = pz.id
        WHERE
            p.name = 'Andrey'
    )
SELECT pizzeria_name
FROM andrey_visit
EXCEPT
SELECT pizzeria_name
FROM andrey_order;
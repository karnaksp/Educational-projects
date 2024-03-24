SELECT
    pizza_name,
    pizzeria.name AS pizzeria_name
FROM menu
    FULL JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
    INNER JOIN person_order ON menu.id = person_order.menu_id
    INNER JOIN (
        SELECT *
        FROM person
        WHERE
            NAME IN ('Denis', 'Anna')
    ) AS pers ON pers.id = person_order.person_id
ORDER BY 1, 2;
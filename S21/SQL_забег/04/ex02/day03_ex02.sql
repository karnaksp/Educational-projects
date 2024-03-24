SELECT
    m.pizza_name,
    m.price,
    p.name AS pizzeria_name
FROM menu m
    INNER JOIN pizzeria p ON p.id = m.pizzeria_id
WHERE NOT EXISTS (
        SELECT 1
        FROM person_order po
        WHERE
            po.menu_id = m.id
    )
ORDER BY
    m.pizza_name,
    m.price;
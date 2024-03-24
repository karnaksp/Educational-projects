WITH pizzeria_1 AS (
        SELECT
            pz.id AS id,
            pz.name,
            m.pizza_name,
            m.price
        FROM menu AS m
            JOIN pizzeria AS pz ON pz.id = m.pizzeria_id
    ), pizzeria_2 AS (
        SELECT
            pz.id AS id,
            pz.name,
            pizza_name,
            m.price
        FROM menu AS m
            JOIN pizzeria AS pz ON m.pizzeria_id = pz.id
    )
SELECT
    pizzeria_1.pizza_name,
    pizzeria_1.name AS pizzeria_name_1,
    pizzeria_2.name AS pizzeria_name_2,
    pizzeria_1.price
FROM pizzeria_1, pizzeria_2
WHERE
    pizzeria_1.name != pizzeria_2.name
    AND pizzeria_1.pizza_name = pizzeria_2.pizza_name
    AND pizzeria_1.id > pizzeria_2.id
    AND pizzeria_1.price = pizzeria_2.price
ORDER BY
    pizzeria_1.pizza_name;
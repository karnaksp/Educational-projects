SELECT *
FROM (
        SELECT person.name
        FROM person
        ORDER BY
            person.name
    ) AS first_
UNION ALL
SELECT *
FROM (
        SELECT
            menu.pizza_name
        FROM menu
        ORDER BY
            menu.pizza_name
    ) AS second_;
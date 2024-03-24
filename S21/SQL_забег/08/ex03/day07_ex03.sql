SELECT name, SUM(total_count) AS total_count
FROM (
        SELECT pizzeria.name, COUNT(pizzeria.name) AS total_count
        FROM person_visits
            INNER JOIN pizzeria ON person_visits.pizzeria_id = pizzeria.id
        GROUP BY
            pizzeria.name
        UNION ALL
        SELECT pizzeria.name, COUNT(pizzeria.name) AS total_count
        FROM
            person_order
            INNER JOIN menu ON person_order.menu_id = menu.id
            INNER JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
        GROUP BY
            pizzeria.name
    ) AS tmp
GROUP BY
    name
ORDER BY total_count DESC, name ASC;
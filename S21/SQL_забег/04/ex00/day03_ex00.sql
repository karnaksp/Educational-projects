SELECT
    m.pizza_name,
    m.price,
    p.name AS pizzeria_name,
    pv.visit_date
FROM menu m
    JOIN pizzeria p ON m.pizzeria_id = p.id
    JOIN person_visits pv ON p.id = pv.pizzeria_id
    JOIN person ps ON pv.person_id = ps.id
WHERE
    ps.name = 'Kate'
    AND m.price BETWEEN 800 AND 1000
ORDER BY
    m.pizza_name,
    m.price,
    p.name;
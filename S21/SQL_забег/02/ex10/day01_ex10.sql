-- Active: 1704644311037@@127.0.0.1@5432@pizza
SELECT
    person.name AS person_name,
    menu.pizza_name,
    pizzeria.name AS pizzeria_name
FROM person_order
    JOIN person ON person.id = person_order.person_id
    JOIN menu ON menu.id = person_order.menu_id
    JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
ORDER BY
    person_name ASC,
    menu.pizza_name ASC,
    pizzeria_name ASC;
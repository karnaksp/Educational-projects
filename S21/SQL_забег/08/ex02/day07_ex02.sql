(SELECT name, 
COUNT(*) AS count, 
'visit' AS action_type
FROM pizzeria
INNER JOIN person_visits ON person_visits.pizzeria_id = pizzeria.id
GROUP BY name
ORDER BY count DESC
LIMIT 3)
UNION
(SELECT name, 
COUNT (*) AS count,
'order' AS action_type
FROM pizzeria
INNER JOIN menu ON pizzeria.id = menu.pizzeria_id
INNER JOIN person_order ON menu.id = person_order.menu_id
GROUP BY name
ORDER BY count DESC
LIMIT 3)
ORDER BY action_type, count DESC;

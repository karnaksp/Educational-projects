SELECT
    COALESCE(p.name, '-') AS person_name,
    pv.visit_date,
    COALESCE(PI.name, '-') AS pizzeria_name
FROM person p
    FULL JOIN (
        SELECT *
        FROM person_visits
        WHERE
            visit_date BETWEEN '2022-01-01' AND '2022-01-03'
    ) AS pv ON pv.person_id = p.id
    FULL JOIN pizzeria PI ON PI.id = pv.pizzeria_id
ORDER BY 1, 2, 3;
SELECT DISTINCT *
FROM (
        SELECT
            order_date AS action_date,
            NAME
        FROM person_order
            INNER JOIN person_visits ON person_order.person_id = person_visits.person_id
            JOIN person ON person_order.person_id = person.id
        WHERE
            visit_date = order_date
    ) AS first_
ORDER BY
    action_date ASC,
    NAME DESC;
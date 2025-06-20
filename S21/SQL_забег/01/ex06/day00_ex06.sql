SELECT
    (
        SELECT
            name
        FROM
            person
        WHERE
            person.id = person_order.person_id
    ) AS person_name,
    CASE
        WHEN (
            SELECT
                name
            FROM
                person
            WHERE
                person.id = person_order.person_id
        ) = 'Denis' THEN TRUE
        ELSE false
    END AS check_name
FROM
    person_order
WHERE
    menu_id IN (13, 14, 18)
    AND order_date = '2022-01-07';